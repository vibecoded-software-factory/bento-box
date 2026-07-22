#include "compositor.hpp"

#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#include <cerrno>
#include <cstring>

#include <qbytearray.h>
#include <qloggingcategory.h>
#include <qstring.h>
#include <qtenvironmentvariables.h>

namespace qs::mac {

namespace {
Q_LOGGING_CATEGORY(logCompositor, "quickshell.mac.compositor");

QByteArray socketPath() {
	auto fromEnv = qEnvironmentVariable("NIGIRI_SOCKET");
	if (!fromEnv.isEmpty()) return fromEnv.toUtf8();
	return QByteArrayLiteral("/tmp/nigiri-msg.sock");
}
} // namespace

void sendCompositorMessage(const QString& line) {
	auto path = socketPath();

	sockaddr_un addr {};
	addr.sun_family = AF_UNIX;
	if (path.size() >= static_cast<int>(sizeof(addr.sun_path))) {
		qCWarning(logCompositor) << "socket path too long:" << path;
		return;
	}
	std::memcpy(addr.sun_path, path.constData(), path.size());
	// macOS (BSD sockets) reads sun_len; connect with the exact address length,
	// not sizeof(sockaddr_un). Passing the full struct size made connect() fail
	// for a short path (the compositor looked "not listening" when it was).
	addr.sun_len = static_cast<unsigned char>(SUN_LEN(&addr));
	auto addrLen = static_cast<socklen_t>(SUN_LEN(&addr));

	// The compositor's accept loop runs on its main thread; while it is busy
	// (a relayout as our panels map) a connect can momentarily get
	// ECONNREFUSED even though it is listening. A raw connect succeeds when it
	// is idle, so retry a few times with a short backoff. A fresh socket per
	// attempt: a fd whose connect() failed cannot be reconnected.
	bool connected = false;
	int lastErrno = 0;
	for (int attempt = 0; attempt < 5 && !connected; attempt++) {
		auto fd = ::socket(AF_UNIX, SOCK_STREAM, 0);
		if (fd < 0) return;
		if (::connect(fd, reinterpret_cast<sockaddr*>(&addr), addrLen) == 0) {
			auto payload = line.toUtf8();
			if (!payload.endsWith('\n')) payload.append('\n');
			// Best-effort: a short write or EPIPE just means the compositor went
			// away mid-send, which is the same as it never being there.
			auto written = ::write(fd, payload.constData(), payload.size());
			Q_UNUSED(written);
			connected = true;
		} else {
			lastErrno = errno;
		}
		::close(fd);
		if (!connected && lastErrno == ECONNREFUSED) usleep(20000); // 20ms
		else if (!connected) break;
	}

	if (!connected) {
		qCDebug(logCompositor) << "no compositor listening at" << path << "-" << std::strerror(lastErrno);
	}
}

} // namespace qs::mac
