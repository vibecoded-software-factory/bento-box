#include "compositor.hpp"
#include <cerrno>
#include <cstring>

#include <qbytearray.h>
#include <qelapsedtimer.h>
#include <qloggingcategory.h>
#include <qstring.h>
#include <qtenvironmentvariables.h>
#include <qthread.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <unistd.h>

namespace qs::mac {

namespace {
Q_LOGGING_CATEGORY(logCompositor, "quickshell.mac.compositor");

QByteArray socketPath() {
	auto fromEnv = qEnvironmentVariable("NIGIRI_SOCKET");
	if (!fromEnv.isEmpty()) return fromEnv.toUtf8();
	return QByteArrayLiteral("/tmp/nigiri-msg.sock");
}

// How long to wait for the compositor before giving up and starting anyway,
// and how often to look. The cap is only ever paid in full when $NIGIRI_SOCKET
// names a compositor that never comes up; a live one ends the wait the moment
// it binds, which is what the poll interval buys.
constexpr int defaultWaitMs = 5000;
constexpr int pollIntervalMs = 25;
} // namespace

bool sendCompositorMessage(const QString& line) {
	auto path = socketPath();

	sockaddr_un addr {};
	addr.sun_family = AF_UNIX;
	if (path.size() >= static_cast<int>(sizeof(addr.sun_path))) {
		qCWarning(logCompositor) << "socket path too long:" << path;
		return false;
	}
	std::memcpy(addr.sun_path, path.constData(), path.size());
	// macOS (BSD sockets) reads sun_len; connect with the exact address length,
	// not sizeof(sockaddr_un). Passing the full struct size made connect() fail
	// for a short path (the compositor looked "not listening" when it was).
	addr.sun_len = static_cast<unsigned char>(SUN_LEN(&addr));
	auto addrLen = static_cast<socklen_t>(SUN_LEN(&addr));

	// ONE attempt, and never a sleep. This runs on the GUI thread: it is reached
	// from MacPanelWindow::updateReservation, which every panel re-runs on a 3s
	// heartbeat, so any wait here is the whole shell freezing. The previous
	// version retried thirty times with a 20ms usleep between them - up to 600ms
	// of frozen UI per panel per heartbeat for as long as the compositor was
	// unreachable, which is precisely when the shell most needs to keep drawing.
	//
	// Nothing is lost by giving up immediately, because the retry already exists
	// one level up and does not block: updateReservation re-sends on a
	// QTimer::singleShot, and the heartbeat re-asserts the live reservation
	// forever after that. The compositor's listen backlog was raised to 128 and
	// its accept loop now drains the queue, which is the actual fix for the burst
	// this used to paper over.
	auto fd = ::socket(AF_UNIX, SOCK_STREAM, 0);
	if (fd < 0) return false;
	bool connected = ::connect(fd, reinterpret_cast<sockaddr*>(&addr), addrLen) == 0;
	int lastErrno = connected ? 0 : errno;
	if (connected) {
		auto payload = line.toUtf8();
		if (!payload.endsWith('\n')) payload.append('\n');
		// Best-effort: a short write or EPIPE just means the compositor went
		// away mid-send, which is the same as it never being there.
		auto written = ::write(fd, payload.constData(), payload.size());
		Q_UNUSED(written);
	}
	::close(fd);

	if (!connected) {
		qCDebug(logCompositor) << "no compositor listening at" << path << "-"
		                       << std::strerror(lastErrno);
	}
	return connected;
}

void awaitCompositorSocket() {
	// The EXPLICIT variable, not socketPath(): its fallback to the well-known
	// path would make every plain macOS session wait for a compositor it was
	// never told to expect. Setting the variable is the declaration.
	auto path = qEnvironmentVariable("NIGIRI_SOCKET");
	if (path.isEmpty()) return;

	auto timeoutMs = defaultWaitMs;
	if (qEnvironmentVariableIsSet("BENTO_COMPOSITOR_WAIT_MS")) {
		auto ok = false;
		auto value = qEnvironmentVariableIntValue("BENTO_COMPOSITOR_WAIT_MS", &ok);
		if (ok) timeoutMs = value;
	}
	if (timeoutMs <= 0) return;

	// stat(), not connect(): the shell's own probe is `test -S`, so matching it
	// is what closes the race. Connecting would also consume a slot in the
	// compositor's accept backlog for nothing.
	auto bytes = path.toUtf8();
	QElapsedTimer timer;
	timer.start();

	for (;;) {
		struct stat info {};
		if (::stat(bytes.constData(), &info) == 0 && S_ISSOCK(info.st_mode)) {
			// Silent in the common case: a compositor that was already up costs
			// one stat() and deserves no line in the log.
			if (timer.elapsed() >= pollIntervalMs) {
				qCInfo(logCompositor) << "compositor socket appeared after" << timer.elapsed() << "ms";
			}
			return;
		}

		if (timer.elapsed() >= timeoutMs) {
			qCWarning(logCompositor) << "no compositor socket at" << path << "after" << timeoutMs
			                         << "ms - starting without one";
			return;
		}

		QThread::msleep(pollIntervalMs);
	}
}

} // namespace qs::mac
