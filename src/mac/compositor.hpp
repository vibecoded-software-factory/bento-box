#pragma once

class QString;

namespace qs::mac {

// Best-effort one-line message to the tiling compositor's control socket.
//
// This is the client side of a compositor integration: on Wayland a layer
// surface declares its exclusive zone through the layer-shell protocol; macOS
// has no such protocol, so a PanelWindow that wants space reserved asks the
// running tiling window manager over its niri-shaped IPC socket instead. The
// socket path comes from $NIGIRI_SOCKET, falling back to the well-known path.
//
// Best-effort by design: if nothing is listening (no compositor running), the
// send silently fails and the panel simply draws without a reserved zone -
// the same graceful degradation as any platform where exclusion is
// unavailable. bento never requires a compositor to be present.
void sendCompositorMessage(const QString& line);

} // namespace qs::mac
