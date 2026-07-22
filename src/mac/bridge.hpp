#pragma once

class QWindow;
class QRect;

namespace qs::mac {

// Reconfigure the NSWindow backing a QWindow as a layer-shell-style panel.
// Implemented in Objective-C++ (bridge.mm) because Qt exposes no flag for the
// two things that matter here:
//   - collectionBehavior: canJoinAllSpaces + stationary, so the panel shows on
//     every Space and does not slide with Space switches, like a wl_layer
//     surface. Qt has no equivalent hint.
//   - window level above the ordinary WindowStaysOnTopHint floating level, so a
//     panel can sit at the status-bar level (over normal windows, under the
//     system menu bar), matching WlrLayer.Top.
//
// `aboveWindows` picks the level (status-bar vs a normal, below-everything
// level). `desktopBackground` marks a shell's wallpaper layer: macOS owns the
// desktop, so instead of covering the user's windows with it we make it
// invisible and click-through (a shell drives the OS wallpaper through
// Quickshell.Mac.Desktop). Called after the native window exists and whenever
// the layer/level inputs change. A no-op (logged once) if the QWindow has no
// native handle yet.
void configurePanelWindow(QWindow* window, bool aboveWindows, bool desktopBackground);

// Re-assert the panel's intended frame on the native NSWindow.
//
// The window server constrains windows at the normal level to the screen's
// visibleFrame, which excludes the top strip reserved for the menu bar (on
// notched displays that strip exists even while the menu bar is set to
// auto-hide). A panel is shown before configurePanelWindow raises it to the
// status-bar level, so a top-anchored bar gets clamped below that strip at
// show time and Qt never re-applies the frame. Status-level windows are NOT
// constrained, so re-setting the frame after the level is configured places
// the panel at the true screen edge. `geometry` is in Qt's global coordinates
// (top-left origin); a no-op when the native handle doesn't exist yet or the
// frame already matches.
void assertPanelFrame(QWindow* window, const QRect& geometry);

// Take app focus for a panel that holds a Wayland-style EXCLUSIVE keyboard
// grab (a launcher, a modal): remember the frontmost app, activate the shell
// app and make the panel's NSWindow key, so typing reaches its QML content.
// macOS has no compositor-side keyboard grab - this is the closest analogue,
// and it is exactly what Spotlight-like panels do. `owner` identifies the
// panel across the grab's lifetime; it must outlive the QWindow, which shells
// destroy on close (the window is often gone by the time focus is returned).
void takeKeyboardForPanel(QWindow* window, void* owner);

// Give app focus back after an exclusive-keyboard panel hides or is torn
// down: reactivate the app remembered by takeKeyboardForPanel. A no-op unless
// `owner` is the panel currently holding the grab, so overlapping modals
// don't fight.
void yieldKeyboardFromPanel(void* owner);

} // namespace qs::mac
