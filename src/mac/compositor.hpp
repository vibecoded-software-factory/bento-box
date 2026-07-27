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

// Bounded wait for the compositor's control socket to appear. Returns as soon
// as it does, so a session that has one pays only the race window.
//
// A shell probes for the compositor ONCE and latches the answer: DMS's
// CompositorService fires a single non-repeating 100ms timer, tests
// `test -S $NIRI_SOCKET`, and on failure applies "unknown" for the life of the
// process - disabling every integration gated on it until the shell is
// restarted by hand. Nothing re-runs that probe.
//
// bento and the compositor are both launchd agents with RunAtLoad, launchd has
// no ordering primitive, and the compositor binds its socket late in its own
// startup (after the Accessibility gate, the config parse and the initial
// window scan) while bento is a Qt app that reaches QML fast. At login that
// race is routinely lost.
//
// Waiting here - before the QML root is loaded, and so before any shell can
// probe - is the only fix on our side of the boundary: the shell is
// third-party and strictly read-only.
//
// Waits ONLY when $NIGIRI_SOCKET is set explicitly. Setting it is the
// declaration that a compositor is expected; a plain macOS session that never
// sets it starts immediately and pays nothing. $BENTO_COMPOSITOR_WAIT_MS
// overrides the cap in milliseconds, and 0 disables the wait entirely.
void awaitCompositorSocket();

} // namespace qs::mac
