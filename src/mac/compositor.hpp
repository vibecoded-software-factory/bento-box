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
//
// Returns true if the line was delivered. A caller that needs the message to
// land (a reservation, not a fire-and-forget) can retry on false: at startup a
// shell maps several panels at once and the compositor, busy adopting them on
// its single thread, refuses connections in bursts until it drains.
bool sendCompositorMessage(const QString& line);

} // namespace qs::mac
