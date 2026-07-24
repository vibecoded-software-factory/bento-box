# bento-box — quickshell on macOS

A port of [quickshell](https://git.outfoxxed.me/quickshell/quickshell) to
macOS. Same QML API, AppKit instead of Wayland.

This is a **fork, not a rewrite**. `upstream` is a real remote and the history
is intact, so the ~44k lines of portable Qt keep coming from the source and we
can rebase on it. LGPL-3, inherited.

## Why a port and not a new shell

The goal is to run [DankMaterialShell](https://github.com/AvengeMedia/DankMaterialShell)
on macOS. DMS is 568 QML files written against quickshell's API, so API
compatibility IS the feature: anything that changes the API costs a rewrite of
the shell, and anything that keeps it gets the whole shell for free.

## What has to be replaced, measured rather than guessed

Of quickshell's ~58k lines of C++, ~14k are platform-specific (`src/wayland`
12.2k, `src/x11` 2.1k). The rest is portable Qt, except the Linux service
bindings.

Counted from DMS's own QML — what it actually touches, by weight:

| what it uses | uses | where it comes from | status |
|---|---|---|---|
| `Quickshell` (core singleton) | 750 | `src/core` | portable |
| `WlrLayershell` | 199 | `src/wayland` | **rewrite on AppKit** |
| `Singleton` | 171 | `src/core` | portable |
| `Process` | 121 | `src/io` | portable, needs checking |
| `FileView` | 56 | `src/io` | portable |
| `PanelWindow` | 49 | `src/window` + `src/wayland` | **the heart of the port** |
| `IpcHandler` | 47 | `src/ipc` | portable |
| `Screen` / `LazyLoader` / `DesktopEntries` / `Variants` / `SystemClock` | ~170 | `src/core` | portable (DesktopEntries needed a macOS `.app` scan - see the divergence ledger) |

Plus the services (Mpris, UPower, PipeWire, SystemTray, Notifications,
Bluetooth) and the compositor integration — where nigiri takes Hyprland's
place, since it already speaks niri's IPC.

## The mapping

| Wayland | macOS |
|---|---|
| `wlr-layer-shell` (layer, anchors, exclusive zone) | `NSWindow` level + `NSScreen` frame + Dock/menu-bar insets |
| `wl_output` | `NSScreen`, `NSApplication.didChangeScreenParametersNotification` |
| `xdg-popup` / `popupanchor` | child `NSWindow` positioned against an anchor rect |
| `wlr-screencopy` | ScreenCaptureKit |
| `ext-session-lock` | (no equivalent; macOS owns the lock screen) |
| PipeWire | CoreAudio |
| UPower | IOKit power sources |
| NetworkManager | CoreWLAN / SystemConfiguration |
| BlueZ | IOBluetooth |
| MPRIS (DBus) | MediaRemote / now-playing |
| StatusNotifierItem (tray) | `NSStatusItem` (ours) — the system tray others publish has no macOS analogue |
| Hyprland / i3 IPC | nigiri's socket (niri-shaped) |

## Portable-tree divergence ledger

Everything outside `src/mac/` is supposed to keep coming from upstream
verbatim. The exceptions are listed here, each one either macOS-forced or an
upstream-destined patch - anything not on this list is a bug:

- `src/io/socket.cpp` (`Socket::onSocketError`) - **upstream bug fix, not
  macOS-forced**: a refused dial strands the dead `QLocalSocket` so a
  reconnect-with-backoff dies on its first attempt (identical on Linux).
  bento needs the redial for the nigiri event socket across compositor
  restarts, so the fix lives here until it can be submitted upstream; it
  changes observable behavior on all platforms (`connectionStateChanged`
  now fires on refused attempts, and `connected: true` no longer stays
  targeted after one) and will conflict on rebase until upstream takes it.
- `CMakeLists.txt` / `src/CMakeLists.txt` / `src/core/CMakeLists.txt` /
  `src/widgets/CMakeLists.txt` - build gating for macOS (MAC option, OBJCXX,
  libdrm off, MSL shader variants on APPLE).
- `src/core/debuginfo.cpp` - `gpuInfo()` returns an honest
  "<not implemented on macOS>" (diagnostics only).
- `src/core/logging.cpp` - `__APPLE__` include branch + `memfd_create` shim
  (mkstemp+unlink, same fd-lifetime semantics).
- `src/core/desktopentry.cpp` (+ CoreFoundation link in
  `src/core/CMakeLists.txt`) - **macOS-forced**: the XDG scan finds nothing
  on a stock Mac, so `DesktopEntryScanner::run` first synthesizes one entry
  per `.app` bundle from /Applications, /System/Applications (+Utilities)
  and ~/Applications through the same ParsedDesktopEntryData pipeline:
  id = bundle identifier (matches the compositor's app_id so `byId()`
  resolves toplevels), name = bundle display name, icon = absolute path of
  the bundle's `.icns` (Qt's icns plugin renders it; asset-catalog-only
  apps get an empty icon, not a fake), exec = `open <bundle>`. Scanning
  needs `QDir::Hidden|System`: cryptex app links (Safari) carry the hidden
  attribute. XDG entries still override on id conflict. Verified live:
  89/89 bundles found, byId("com.apple.Safari") -> "Safari" with real icns
  and exec.
- `CMakeLists.txt` (CRASH_HANDLER) - **off by default on APPLE**: the
  reporter relaunches via `/proc/self/exe` (crash/handler.cpp), which does
  not exist on macOS - the signal handler perror()s and `_exit()`s leaving
  the forked coredump child behind. Until the reporter learns
  `_NSGetExecutablePath`, no handler beats a broken one.
- `src/core/logging.cpp` also carries upstream `10b439f` ("prevent double
  initialization of logger") applied verbatim ahead of the next rebase -
  identical content, dissolves on merge - and reorders the two `struct
  flock` designated initializers into Darwin's declaration order (same
  fields, silences -Wreorder-init-list on macOS only).
- Instance "display" note: with neither WAYLAND_DISPLAY nor DISPLAY set,
  every macOS instance records display `"unk"` (launch/command.cpp
  getDisplayConnection, inherited) - correct for a one-session OS, but it
  means `qs list` collapses to a single display bucket and the
  mismatched-display machinery is dead code here.
- `src/core/paths.cpp` - runtime dir from `_CS_DARWIN_USER_TEMP_DIR` when
  `XDG_RUNTIME_DIR` is unset (macOS has no /run/user). Caveat: macOS
  periodically purges files there after ~3 days without access, so a
  long-lived instance's lock/socket/log can be reaped - a failure mode
  /run/user (tmpfs, per-boot) does not have.

## Milestones

- **M0** ✅ — it builds and runs a QML file in a plain window, with live reload.
  Everything Linux-only switched off at the CMake level; nothing rewritten yet.
- **M1** ✅ — `PanelWindow` on AppKit. A cocoa `QsEnginePlugin` (`src/mac/`)
  overlay-registers `PanelWindow` the same way the wayland/x11 plugins do, backed
  by `MacPanelWindow : ProxyWindowBase`: anchors + margins pin the window to a
  screen edge (the exact geometry rule from the X11 backend), `aboveWindows`
  and `focusable` map to the NSWindow level and non-activating style, and one
  Objective-C++ bridge (`bridge.mm`) sets `collectionBehavior` so the panel
  shows on every Space. Per-screen instances come for free from quickshell's
  `Variants`.
  **Exclusive zone** (`exclusiveZone` / `exclusionMode`): macOS has no public
  API to reserve space (a window's `NSScreen.visibleFrame` is read-only), so
  the backend does what a wl_layer surface does with a compositor - it *asks*
  the tiling window manager. `MacPanelWindow` computes its zone with the exact
  wlroots/X11 rule (`compositor.cpp`, `bridge.hpp`) and sends `reserve-zone`
  over the compositor's control socket (`$NIGIRI_SOCKET`); the WM leaves that
  strip free. Best-effort: with no compositor listening the panel simply draws
  without reserved space. This is the first thread of the M3 integration.
  The honest limit stays: only WM-managed windows respect the zone - an app
  zoomed with the green button uses the system `visibleFrame` regardless.
- **M2** ✅ — the portable core works on macOS with no code changes, as the
  usage table predicted. Verified live against a QML config:
  `Quickshell.screens` enumerates the display through Qt's `QScreen` (cocoa QPA,
  NSScreen-backed): "Built-in Retina Display" 1470x956 @ scale 2. `Process`
  ran `uname -srm` → "Darwin 25.5.0 arm64". `FileView` read `/etc/hosts`.
  `IpcHandler` round-tripped end to end over the instance's unix socket (whose
  macOS paths M0 fixed): `qs ipc call m2 ping` → "pong", `add 3 4` → 7.
  Not exercised for lack of hardware: multi-monitor enumeration and hot-plug
  (`screensChanged`) - single display only.
- **M3** 🚧 — the nigiri integration module (`Quickshell.Nigiri`, in `src/mac/nigiri/`),
  the macOS counterpart of `Quickshell.Hyprland`. Structured the same way: a
  backend singleton (`NigiriIpc`) owning a persistent event socket read with the
  shared `StreamReader`, an `ObjectModel<NigiriWorkspace>` updated in place, and
  a QML facade singleton `Nigiri`. Transport is nigiri's niri-shaped JSON line
  protocol on one socket (`event-stream` to subscribe - it replays current state
  first - and `action <line>` to command), not Hyprland's two `NAME>>DATA`
  sockets. **Done:** workspaces (id/idx/name/active/focused) and windows
  (id/title/appId/pid/workspaceId/floating/active), both live; `focusedWorkspace`,
  `activeWindow`, `focusedWindowId`; `NigiriWorkspace.activate()`,
  `NigiriWindow.activate()`, and `Nigiri.dispatch()`. Each object's `active` is a
  binding off the focused id, Hyprland-style, so highlights recompute themselves.
  Verified live end to end: both models populate from the event stream, react to
  external workspace/focus changes, and QML-initiated `activate()`/`dispatch()`
  drive nigiri (a window's `activate()` uses nigiri's new `focus-window-by-id`,
  switching workspace if needed). `WorkspaceActivated` is applied with niri's
  own event-stream semantics (the target workspace becomes active, its
  siblings deactivate, focus moves when `focused` is set) - the flags do NOT
  depend on nigiri's redundant follow-up `WorkspacesChanged` snapshot, which
  niri upstream does not send (verified against a replayed stream carrying
  the lone event). **Dialect contract:** one socket, two dialects. bento
  speaks the legacy bare-word forms (`event-stream` to subscribe, `action
  <line>` to command, `action reserve-zone` from panel_window.cpp) while DMS
  speaks niri's real JSON on the same socket; nigiri parses each line in the
  dialect it arrived in and answers in kind (its NiriProtocol.swift documents
  the bare words as a kept extension for bento). The bare words are
  load-bearing: nigiri must not drop them until bento migrates to the JSON
  forms. **Module status (deliberate fork API):** `Quickshell.Nigiri` has no
  upstream counterpart - it is this fork's compositor-integration module,
  the role Quickshell.Hyprland plays upstream. It deliberately speaks
  niri's vocabulary, not Hyprland's contract (nigiri IS niri-shaped;
  mimicking Hyprland's two-socket surface would fake a compositor that
  doesn't exist). Consumer today: bento itself (MacToplevelManager feeds
  Quickshell.Wayland.ToplevelManager from NigiriIpc); public and kept.
  DMS's niri path also shells out to a `niri` CLI (`validate`,
  `msg -j outputs`, `msg output ...`); on macOS that binary is a shim
  installed by dms-darwin's Glue/install.sh which forwards to nigiri's
  parser/socket honestly. **Next:** monitors, and `msg windows` gaining
  the `id` field (the event stream already carries it; only the one-shot query
  omits it).
  One macOS gotcha found and worked around: `QLocalSocket`'s
  `stateChanged(ConnectedState)` can arrive before the device is open
  (`isOpen()` false, writes return -1); the subscribe must wait for the
  `connected()` signal instead.
- **M4+** — services, one at a time, in the order DMS needs them.
  - **Mpris (now-playing)** ✅ — `Quickshell.Services.Mpris` on macOS
    (`src/mac/mpris/`), same QML surface as the Linux D-Bus service so DMS's
    media widget binds unchanged: singleton `Mpris` with `players` (zero or one,
    since macOS aggregates now-playing to one session), `MprisPlayer` with the
    full metadata/state/capability/position API, and the two enums.
    The data comes from Apple's **MediaRemote** private framework - which since
    macOS 15.4 refuses access to unentitled processes, but Apple's own signed
    binaries (`com.apple.*`) are allowed. The backend spawns the **entitled
    system `/usr/bin/perl`** (`com.apple.perl5`) running a **compiled
    `MediaRemoteAdapter.framework`** (vendored from ungive/mediaremote-adapter,
    BSD-3, built from source by our CMake as Objective-C; see
    `src/mac/mpris/mediaremote-adapter/`). Perl loads the framework with the
    stock `DynaLoader` and calls its exported `adapter_*` entry points; because
    perl is the entitled host, the framework reaches MediaRemote. `... stream`
    is a long-lived `QProcess` emitting now-playing JSON (parsed into the
    player); `... send <n>` is a one-shot for transport commands. It covers
    browser media (Chrome/YouTube), not just Music/Spotify.
    **Seek, loop and shuffle are real controls**, not stubs: the adapter's
    `seek` (absolute elapsed via `MRMediaRemoteSetElapsedTime`, so
    `setPosition` maps directly and `seek(offset)` is position+offset),
    `repeat` (1 off / 2 track / 3 playlist -> `MprisLoopState`) and
    `shuffle` (1 off / 3 tracks) commands; the read side comes from the
    stream's `repeatMode`/`shuffleMode` keys. `canSeek`/`loopSupported`/
    `shuffleSupported` are true. Volume stays honestly unsupported
    (MediaRemote has no per-player volume; it reads 1.0 like upstream's
    unsupported default). `identity` is the app's human name resolved from
    the bundle identifier via NSRunningApplication/NSWorkspace ("Spotify",
    not "com.spotify.client"); the raw id stays in `dbusName`. `Stopped`
    is unreachable by design: MediaRemote sessions deregister instead of
    idling, so the player is removed - the same thing upstream does when an
    MPRIS app quits. The full upstream property surface is present:
    `uniqueId` (per-player track counter), `trackArtists` (deprecated
    alias), `trackAlbumArtist` (always "" - the payload has no album
    artist), `rate` (read from `playbackRate`; writes carry upstream's
    min/max guard with MPRIS's 1.0/1.0 defaults, routed to the adapter's
    `speed`), `fullscreen`/`canSetFullscreen` (false, write refuses with
    upstream's message), `supportedUriSchemes`/`supportedMimeTypes` (empty,
    unadvertised), `openUri()` (targeted NSWorkspace open with the player's
    app), `postTrackChanged` (after-update half of upstream's ordering),
    `length` falling back to `position` until a duration is seen, and
    `metadata` carrying `mpris:length` (microseconds) and `mpris:trackid`
    (MediaRemote's content item identifier) when available.
    NOT yet verified live: the seek/loop/shuffle round-trip, the resolved
    identity and the new property values need a playing app (none was
    active at fix time) - transport commands and metadata were verified
    earlier; the new QML registrations were verified in the generated
    qmltypes.
    Why compiled and not the earlier pure-osascript helper: album artwork.
    `MRNowPlayingRequest` (reachable from JXA) exposes only an artwork
    *identifier*, never the bytes - for ANY app, Music included. The bytes come
    only from `MRMediaRemoteGetNowPlayingInfo(queue, block)`, whose dispatch
    queue + completion block osascript/JXA cannot call. The compiled framework
    can, so it returns `artworkData` (base64); the backend decodes it to a temp
    file per track and exposes a `file://` URL. **Verified live:** Music and
    Chrome both populate identity/title/artist, a live-advancing position (from
    the info timestamp), working play/pause/toggle/next/previous, and real
    album art (the actual cover, not a placeholder).
    Build/runtime note: the framework path is baked in at build time
    (`$<TARGET_BUNDLE_DIR:MediaRemoteAdapter>`) and overridable via
    `$BENTO_MRA_FRAMEWORK`; the perl loader ships embedded as a Qt resource.
    Relocatable packaging (framework inside an app bundle) is a later concern.
    Position is computed from the info's OWN timestamp, not arrival time: a
    browser reports `elapsedTime=0` with a fresh timestamp, so
    `position = elapsed + (now - timestamp)`.
    Two gotchas found integrating the framework: (1) it must compile as
    Objective-C, not Objective-C++ - the perl loader resolves the exported
    `adapter_*_env` entry points by plain C name, and C++ mangles them out of
    reach; (2) transport commands reach mediaremoted asynchronously over XPC, so
    a caller that exits the instant after the call drops the message - the
    compiled adapter's `send` handles the flush, which the earlier ad-hoc
    osascript command mode did not (making a browser look like it refused
    commands when it did not).
  - **Battery (UPower)** ✅ — `Quickshell.Services.UPower` on macOS
    (`src/mac/upower/`), the same QML surface as the Linux D-Bus service
    (singleton `UPower` with `displayDevice`/`devices`/`onBattery`,
    `UPowerDevice` with the full property set, and the `UPowerDeviceState` /
    `UPowerDeviceType` enums) so DMS's battery widget binds unchanged. Backed by
    **IOKit power sources** (no daemon, no entitlement): `IOPSCopyPowerSourcesInfo`
    for the live fields (percentage 0-1, charging state, time-to-empty/full,
    present, on-battery) refreshed on the system's `IOPSNotificationCreateRunLoopSource`
    change callback plus a slow timer, and **AppleSmartBattery** (IORegistry) for
    what power sources omit - energy/capacity in Wh, watt change-rate, health %
    and model. State/`isLaptopBattery`/`healthSupported`/`iconName` are derived
    exactly as the Linux service derives them (`percentage` is a 0-1 fraction,
    matching UPower's `PowerPercentage` transform, not 0-100). The state
    ladder honors UPower's full enum from what IOKit can attest: `IsCharged`
    (or >=99%) is FullyCharged; on AC while neither charging nor charged the
    battery is being held below full (optimized charging) = PendingCharge;
    an empty battery still discharging = Empty; PendingDischarge has no
    macOS signal and stays unreachable (documented in the code).
    **Verified live** against `pmset -g batt`: on battery, 100%, discharging,
    17:45 to empty (= 63900s), −3.44 W, 52.7/53.2 Wh, 90% health - all matching.
    Not exercised for lack of a second state change during the test: live
    charge/discharge transitions rely on the IOKit notification (wired, plus the
    10s timer as a floor).
    **PowerProfiles** ✅ — the same URI also registers `PowerProfiles`,
    `PowerProfile`, `PerformanceDegradationReason` and the `powerProfileHold`
    value type (upstream `powerprofiles.hpp`), backed by `NSProcessInfo`:
    `profile` is `PowerSaver` while Low Power Mode is on and `Balanced`
    otherwise (live via `NSProcessInfoPowerStateDidChangeNotification`);
    `degradationReason` maps the thermal state (`serious`+ = macOS throttling
    = `HighTemperature`, via the thermal-state notification); honest limits:
    the profile **cannot be set** (macOS has no public Low Power Mode setter -
    writes log an error, and the Performance guard is upstream's verbatim),
    `hasPerformanceProfile` is always false, `holds` is always empty (no hold
    mechanism). **Verified live** against `pmset -g`: lowpowermode 0 ↔
    profile Balanced(1), hasPerformanceProfile false, holds 0, both write
    refusals fire; a live Low Power Mode flip was NOT exercised (needs
    System Settings).
  - **Audio (Pipewire)** ✅ — `Quickshell.Services.Pipewire` on macOS
    (`src/mac/pipewire/`), backed by **CoreAudio**. Mirrors the audio slice of
    the Linux service so DMS's volume widgets bind unchanged: the `Pipewire`
    singleton (`nodes`, `defaultAudioSink`/`Source`, `preferredDefaultAudioSink`/
    `Source` for switching the system default, `ready`), `PwNode`
    (id/name/isSink/type/properties/audio), `PwNodeAudio` (volume/muted/channels/
    volumes, all read-write), the `PwNodeType`/`PwAudioChannel` enums, and a
    `PwObjectTracker` that is a no-op (CoreAudio devices are always fully
    available - no binding step). Each CoreAudio device becomes a node per
    direction it carries; volume is the device's master scalar (falling back to
    averaging channels), mute is `kAudioDevicePropertyMute`. Updates arrive on
    CoreAudio property listeners (device list, default in/out, and volume/mute on
    the current defaults), bounced to the main thread. **No link graph** -
    CoreAudio has none, so `links`/`linkGroups` are always empty - but the
    TYPES exist so upstream configs load: `PwLink`/`PwLinkGroup`
    (uncreatable), `PwLinkState` (pw_link_state values -2..4 and
    pw_link_state_as_string strings, verified against pipewire's own
    sources), and a creatable `PwNodeLinkTracker` whose `linkGroups` is
    always empty. `PwAudioChannel` is the FULL SPA enum, value for value
    (verified against spa/param/audio/raw.h) with upstream's toString
    including the 1-based Aux/Custom formatting.
    `preferredDefaultAudioSink`/`Source` NOTIFY through upstream's own
    signal names (`defaultConfiguredAudioSink/SourceChanged`); on macOS
    set-default is imperative and immediate, so configured and actual move
    together - there is no pending-preference state, documented in the
    header. `PwNode.properties` NOTIFYs `propertiesChanged` like upstream.
    **Volume model**: CoreAudio is driven through a single master scalar,
    so `volumes` reads the same value for every channel; on a flat vector
    upstream's proportional redistribution and bento's averaging produce
    identical results, so the per-channel distinction is vacuous here -
    documented as the platform's volume model, not a shortcut.
    **Verified live** against `osascript`/system volume: enumerated speakers +
    two mics with correct types and channel counts; read the default sink at
    78%; set it to 35% from QML and the system volume followed; muted and
    unmuted through the same path - then restored.
  - **Quickshell.Wayland shim** ✅ — `src/mac/wayland/` provides the module
    DMS imports unconditionally. What is REAL: `Toplevel`/`ToplevelManager`
    (compositor-IPC-fed window list; activate/close/fullscreen work),
    `ScreencopyView` (ScreenCaptureKit; needs the Screen Recording grant;
    `live` is a 500ms re-capture cadence rather than a video stream -
    thumbnails, not video - and `captureFrame()` is a no-op while live like
    upstream; `constraintSize` implements upstream's implicit-size formula
    verbatim; `stopped()` fires when the source dies mid-live; a ShellScreen
    source captures the whole display, verified at the display's true
    pixel size),
    `IdleInhibitor` (IOPM display-sleep assertion, held only while enabled
    AND the bound window is set and visible - upstream's surface-lifetime
    contract, verified against `pmset -g assertions`). Same-edge panels STACK
    against each other's exclusive zones with upstream X11's intra-process
    loop verbatim (MacPanelStack + the shrink loop in updateDimensions:
    same layer, same screen, visible panels only, Ignore opts out, hiding a
    panel reflows the ones above it) - no compositor needed for own-process
    panels; other apps' windows still move via nigiri's reserve-zone.
    `WlrLayershell` is a
    REAL creatable window, upstream's shape: a MacPanelWindow subclass
    carrying the layer vocabulary, every PanelWindow is backed by one
    (WaylandPanelInterface, mirroring upstream's), and the attached object
    IS the backing window - the full window surface (anchors, margins,
    exclusiveZone/exclusionMode, color, everything ProxyWindowBase)
    resolves through it, with upstream's layer<->aboveWindows and
    keyboardFocus<->focusable conversions as virtual overrides (real shared
    state, no copies); `namespace` is stored but inert. Deliberate macOS deviations, each in a code comment: the
    Background layer is suppressed and replaced by `Quickshell.Mac.Desktop`
    (macOS owns the desktop), exclusive keyboard focus takes/yields app
    focus (no compositor grab exists), the layer ladder maps to NSWindow
    levels with upstream's fullscreen semantics (Top = status level, below
    fullscreen apps; Overlay = pop-up-menu level + FullScreenAuxiliary, over
    fullscreen apps - levels verified against the window server; the
    over-fullscreen join itself pends a visual check), and the
    exclusive-zone rule follows the X11 backend (the one that also
    computes zones client-side). Honest inert stubs, full upstream surface,
    never functional: `WlSessionLock`/`WlSessionLockSurface` (macOS owns
    the lock screen; dms-darwin's NativeLock does the real unlock),
    `IdleMonitor` (never reports idle), `ShortcutInhibitor` (nothing to
    inhibit), `HyprlandFocusGrab.active` (no grab can begin - reads false).
    `BackgroundEffect` (attached) stores `blurRegion` so bindings hold but
    applies no blur - no ext-background-effect-v1 here, and the native
    NSVisualEffectView analogue is deliberately not wired (zero consumers).
  - **Quickshell.Hyprland stub** ✅ — `src/mac/hyprland/` mirrors upstream's
    FULL module surface (ipc + focus_grab + global_shortcuts + surface
    extensions) as honest inert stubs, so DMS's unconditional import and
    every guarded read resolve while its compositor detection routes to the
    niri path. `Hyprland` singleton: `usingLua` (false forever),
    `requestSocketPath`/`eventSocketPath` (empty, like upstream when
    `$HYPRLAND_INSTANCE_SIGNATURE` is unset), `focusedMonitor`/
    `focusedWorkspace`/`activeToplevel` (null), empty monitors/workspaces/
    toplevels models, `dispatch()` refusing with a warning (upstream's
    cannot-connect behavior), typed `monitorFor()` returning null, no-op
    refresh invokables, and the `rawEvent(HyprlandEvent)` signal (never
    emitted - no event socket exists). `HyprlandWorkspace`/`HyprlandMonitor`/
    `HyprlandToplevel` carry upstream's full property/signal surface with
    upstream's defaults (ids -1, hex address "0" mirroring upstream
    bug-for-bug, null pointers, empty maps/models); `HyprlandToplevel` is
    attachable like upstream but its handles stay null forever (no address
    is ever reported). `HyprlandEvent.parse()` runs upstream's split
    algorithm over the always-empty body. `GlobalShortcut` (PostReloadHook
    like upstream, default appid "quickshell") stores its properties and
    warns on reload that hyprland-global-shortcuts-v1 does not exist here -
    it never registers, never fires. `HyprlandWindow` (attached) stores
    `opacity`/`visibleMask` so bindings hold, forwarded nowhere (no
    hyprland-surface-v1). `HyprlandFocusGrab.active` always reads false -
    upstream's "will not change to true until the grab begins" with no grab
    possible. Upstream splits the URI into private submodules re-exported
    by an umbrella; bento registers everything flat under
    `Quickshell.Hyprland` - identical resolution for QML consumers. The
    real compositor integration is `Quickshell.Nigiri` (M3).
  - **Quickshell.I3 stub** ✅ — `src/mac/i3/` mirrors upstream's full
    i3/Sway IPC surface (src/x11/i3/ipc/*) as honest inert stubs, same
    rationale as the Hyprland stub above. `I3` singleton: `socketPath`
    (empty, like upstream when `$I3SOCK`/`$SWAYSOCK` are unset),
    `focusedWorkspace`/`focusedMonitor` (null), empty monitors/workspaces
    models, `dispatch()` refusing with a warning (upstream's cannot-connect
    behavior), typed `findWorkspaceByName`/`findMonitorByName`/`monitorFor`
    returning null, no-op refresh invokables, `rawEvent(I3Event)` and
    `connected` signals (never emitted - no i3 socket exists).
    `I3Workspace` (id/number -1, `num` deprecated alias, urgent/active/
    focused false, null monitor, `activate()` routing through dispatch) and
    `I3Monitor` (id -1, scale 1 like upstream's default, `focusedWorkspace`
    deprecated alias of `activeWorkspace`) carry upstream's full surface.
    `I3Event.type` reads "unknown" (upstream's default event code) with
    empty `data`. `I3IpcListener` is a PostReloadHook like upstream with
    upstream's `ipcEvent(I3IpcEvent*)` signature - the previously invented
    `ipcEvent(QString,QString)` signature and `start()`/`stop()` invokables
    are gone - and warns on reload that no socket exists.
  - **Quickshell.Mac (fork-native module)** ✅ — invented surface with no
    upstream counterpart, deliberately: `Desktop` (singleton;
    `setWallpaper(path)` -> NSWorkspace.setDesktopImageURL per screen,
    returns false for missing files or colour strings) exists because bento
    suppresses the shell's background wallpaper layer (macOS owns the
    desktop) and something must drive the real wallpaper instead; its
    consumer is the generated `MacWallpaperBridge.qml` glue
    (dms-darwin/Glue/install.sh) - bento stays shell-agnostic, only the
    glue knows where DMS stores the wallpaper path. `MacPanelWindow` is the
    macOS panel backend registered for the window module. This is
    deliberate fork lock-in: anything importing Quickshell.Mac runs only on
    this fork, which is why the glue - not DMS - is the only importer.
  - **Polkit** ✅ (stub) — `Quickshell.Services.Polkit` on macOS
    (`src/mac/polkit/`) is an **API-compatible stub** mirroring upstream
    name for name: `PolkitAgent` (creatable; `path` RW, `isRegistered`/
    `isActive` bindable false, `flow` bindable null,
    `authenticationRequestStarted` + change signals), the full `AuthFlow`
    surface (uncreatable, Retainable, every property/signal/invokable from
    upstream flow.hpp) and `Identity` (uncreatable; id/string/displayName/
    isGroup). macOS has no polkit daemon - privilege prompts are
    system-owned dialogs - so the agent can never register and no flow is
    ever created; construction logs that honestly. The previously invented
    `Polkit.available` singleton (no upstream counterpart, zero consumers)
    is gone. **Verified live**: DMS's `agent?.isActive ?? false` /
    `agent?.flow` bindings now resolve typed values instead of undefined;
    all signal names attach.
  - **Pam** ✅ (stub) — `Quickshell.Services.Pam` on macOS (`src/mac/pam/`)
    is an **API-compatible stub** mirroring upstream name for name:
    `PamContext` (active RW with upstream's start/abort equivalence, config
    defaulting "login", configDirectory defaulting "/etc/pam.d", user,
    message/messageIsError/responseRequired/responseVisible each with its
    own NOTIFY), the `PamResult` and `PamError` singletons with upstream's
    values and toString strings, and the argumentless `pamMessage()`
    signal. macOS does ship PAM, but the lock/auth path here is
    system-owned (dms-darwin's NativeLock does the real unlock), so no
    conversation ever runs: `start()` refuses honestly with upstream's
    failed-start contract - warning, `error(StartFailed)`, then
    `completed(Error)`, returning false - and `active` stays false.
    **Verified live**: defaults, enum values/strings, all signal names, and
    the refusal path (QML dump).
  - **SystemTray** ✅ (stub) — `Quickshell.Services.SystemTray` on macOS
    (`src/mac/systemtray/`) is an **API-compatible stub**: the `SystemTray`
    singleton, `SystemTrayItem` type (with upstream's full NOTIFY topology
    and `ready()` signal; `menu` is typed `QObject*` as the closest honest
    stand-in for the Linux `DBusMenuHandle` - macOS has no dbusmenu - and
    NOTIFYs `hasMenuChanged` like upstream), and `Status`/`Category` enums
    exist so a shell that imports the service binds without error, but
    `items` is **always
    empty**. This is an honest platform limit, not laziness: macOS has **no
    public API to enumerate another app's `NSStatusItem`s**. Confirmed by how
    the leading tools do it - Ice/Bartender scrape the menu bar with **private
    CoreGraphics/SkyLight APIs** and capture each icon with **ScreenCaptureKit**
    (Screen Recording permission), which also makes them unsandboxable. A real
    tray is that whole fragile, private-API subsystem - deferred, and of low
    value here since macOS already shows these items in its own menu bar.
    Verified: the URI imports, `items.length == 0`, the enums resolve, and a
    `Repeater` over the model creates zero delegates.
  - **Bluetooth** ✅ — `Quickshell.Bluetooth` on macOS (`src/mac/bluetooth/`,
    Objective-C++), backed by **IOBluetooth** (classic BR-EDR). Mirrors the
    BlueZ service's surface so DMS binds unchanged: the `Bluetooth` singleton
    (`defaultAdapter`/`adapters`/`devices`), `BluetoothAdapter` (name, `enabled`
    write toggles power, `state` with dedicated `enabledChanged`, `devices`,
    `discovering` runs a real IOBluetoothDeviceInquiry, `adapterId` = the
    hci-style id "hci0" like upstream derives from its DBus path, `dbusPath`
    = the matching synthetic "/org/bluez/hci0"), `BluetoothDevice` (address,
    `name` writable with upstream's alias contract - the alias is
    SESSION-LOCAL, macOS has no public persistent alias store - `deviceName`
    with its own NOTIFY, icon, `state`, `connected` write
    connects/disconnects with dedicated `connectedChanged`,
    `paired`/`bonded` [pairing IS bonding on macOS; bonded carries
    upstream's `bondedChanged`], `adapter` with upstream's NOTIFY, per-device
    `battery` from the IOKit registry where the device reports it) and the
    two state enums. What is REAL beyond that surface: `pair()` via
    IOBluetoothDevicePair (just-works/numeric auto-confirmed like a
    NoInputNoOutput BlueZ agent, keyboard passkeys surfaced via
    notification), `forget()` via the framework's long-stable private
    `remove` (the same call blueutil makes - there is no public unpair), and
    `cancelPair()`. The default host controller gives adapter name/power;
    `[IOBluetoothDevice pairedDevices]` gives the device list, refreshed on
    a 2s poll (IOBluetooth's change callbacks are per-device and awkward; a
    poll is the honest simple choice). connect/disconnect run
    `openConnection`/`closeConnection` off the main thread; power uses
    `IOBluetoothPreferenceSetControllerPowerState`. Honest INERT remainder,
    marked as such in code: `discoverable`/`pairable` and their timeouts
    (macOS owns these in System Settings; timeouts stored so writes
    round-trip), `trusted`/`blocked`/`wakeAllowed` (no IOBluetooth
    analogue).
    **Verified live** against `system_profiler`: adapter enabled with the
    right id, paired devices enumerated with correct names, addresses and
    icons (mouse/keyboard/headphones/generic), bonded==paired, the alias
    round-trip (set -> name shows alias with deviceName untouched, clear ->
    falls back), and hci0/dbusPath/timeout round-trips. The write paths (connect,
    disconnect, power) are wired with standard IOBluetooth calls but were not
    toggled live, to avoid disconnecting the Magic Mouse/Keyboard/Trackpad in
    active use.
  - **Notifications** ✅ (stub) — `Quickshell.Services.Notifications` on macOS
    (`src/mac/notifications/`) is an **API-compatible stub**: `NotificationServer`
    (capability flags honored as storage), `Notification`, `NotificationAction`
    and the `NotificationUrgency`/`NotificationCloseReason` enums exist so a
    shell that imports the service binds without error, but `trackedNotifications`
    is **always empty**. Like SystemTray, this is a hard platform limit: the
    Linux service works by making the shell the freedesktop notification *server*
    so every app's notification is delivered to it; macOS has **no public API for
    a third-party app to receive another app's notifications**
    (DistributedNotificationCenter, NSWorkspace and notification service
    extensions all fail for this - Apple blocks it by design). The only route is
    scraping the private Notification Center SQLite DB, which needs Full Disk
    Access and breaks each OS release - deferred. Verified: the URI imports,
    `NotificationServer` is creatable and its capability flags round-trip,
    `trackedNotifications.length == 0`, and the enums resolve.

Same house rules as nigiri: warning-free build, a check for anything claimed,
and small verifiable milestones.
