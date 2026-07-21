#pragma once

class QWindow;

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
// level). Called after the native window exists and whenever the layer/level
// inputs change. A no-op (logged once) if the QWindow has no native handle yet.
void configurePanelWindow(QWindow* window, bool aboveWindows);

} // namespace qs::mac
