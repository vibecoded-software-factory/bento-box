#include "compositor.hpp"

#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

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

	auto fd = ::socket(AF_UNIX, SOCK_STREAM, 0);
	if (fd < 0) return;

	if (::connect(fd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == 0) {
		auto payload = line.toUtf8();
		if (!payload.endsWith('\n')) payload.append('\n');
		// Best-effort: a short write or EPIPE just means the compositor went
		// away mid-send, which is the same as it never being there.
		auto written = ::write(fd, payload.constData(), payload.size());
		Q_UNUSED(written);
	} else {
		qCDebug(logCompositor) << "no compositor listening at" << path;
	}

	::close(fd);
}

} // namespace qs::mac
