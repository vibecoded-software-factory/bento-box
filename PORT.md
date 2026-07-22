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
| `Screen` / `LazyLoader` / `DesktopEntries` / `Variants` / `SystemClock` | ~170 | `src/core` | portable |

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
  switching workspace if needed). **Next:** monitors, and `msg windows` gaining
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
    matching UPower's `PowerPercentage` transform, not 0-100).
    **Verified live** against `pmset -g batt`: on battery, 100%, discharging,
    17:45 to empty (= 63900s), −3.44 W, 52.7/53.2 Wh, 90% health - all matching.
    Not exercised for lack of a second state change during the test: live
    charge/discharge transitions rely on the IOKit notification (wired, plus the
    10s timer as a floor).
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
    CoreAudio has none, so `links`/`linkGroups` are always empty.
    **Verified live** against `osascript`/system volume: enumerated speakers +
    two mics with correct types and channel counts; read the default sink at
    78%; set it to 35% from QML and the system volume followed; muted and
    unmuted through the same path - then restored.
  - **SystemTray** ✅ (stub) — `Quickshell.Services.SystemTray` on macOS
    (`src/mac/systemtray/`) is an **API-compatible stub**: the `SystemTray`
    singleton, `SystemTrayItem` type, and `Status`/`Category` enums exist so a
    shell that imports the service binds without error, but `items` is **always
    empty**. This is an honest platform limit, not laziness: macOS has **no
    public API to enumerate another app's `NSStatusItem`s**. Confirmed by how
    the leading tools do it - Ice/Bartender scrape the menu bar with **private
    CoreGraphics/SkyLight APIs** and capture each icon with **ScreenCaptureKit**
    (Screen Recording permission), which also makes them unsandboxable. A real
    tray is that whole fragile, private-API subsystem - deferred, and of low
    value here since macOS already shows these items in its own menu bar.
    Verified: the URI imports, `items.length == 0`, the enums resolve, and a
    `Repeater` over the model creates zero delegates.

Same house rules as nigiri: warning-free build, a check for anything claimed,
and small verifiable milestones.
