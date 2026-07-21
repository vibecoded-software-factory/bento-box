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
  **Deferred, on purpose:** the exclusive zone. wlroots/X11 reserve space so
  maximized windows avoid the panel; macOS exposes no public API for that (only
  the system Dock and menu bar reserve space). The `exclusiveZone` /
  `exclusionMode` properties exist because the interface requires them, but they
  are no-ops on macOS. Revisiting needs private APIs, which the project's
  public-APIs-only rule rules out.
- **M2** — `Quickshell` core singleton against `NSScreen`, plus `Process`,
  `FileView` and `IpcHandler` working on macOS.
- **M3** — the nigiri integration module, in the place `Quickshell.Hyprland`
  occupies for DMS.
- **M4+** — services, one at a time, in the order DMS needs them.

Same house rules as nigiri: warning-free build, a check for anything claimed,
and small verifiable milestones.
