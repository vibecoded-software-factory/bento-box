#include "connection.hpp"

#include <qjsonarray.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qloggingcategory.h>
#include <qtenvironmentvariables.h>

#include "workspace.hpp"

namespace qs::nigiri {

namespace {
Q_LOGGING_CATEGORY(logNigiri, "quickshell.nigiri");
}

NigiriIpc* NigiriIpc::instance() {
	static NigiriIpc* instance = new NigiriIpc(); // NOLINT
	return instance;
}

QString NigiriIpc::socketPath() {
	auto fromEnv = qEnvironmentVariable("NIGIRI_SOCKET");
	if (!fromEnv.isEmpty()) return fromEnv;
	return QStringLiteral("/tmp/nigiri-msg.sock");
}

NigiriIpc::NigiriIpc() {
	QObject::connect(
	    &this->mEventSocket,
	    &QLocalSocket::stateChanged,
	    this,
	    &NigiriIpc::onEventSocketState
	);
	QObject::connect(
	    &this->mEventSocket,
	    &QLocalSocket::readyRead,
	    this,
	    &NigiriIpc::onEventSocketReady
	);
	QObject::connect(
	    &this->mEventSocket,
	    &QLocalSocket::errorOccurred,
	    this,
	    [](QLocalSocket::LocalSocketError error) {
		    qCDebug(logNigiri) << "event socket error:" << error;
	    }
	);
	// The `connected` signal fires once the device is actually open for I/O -
	// unlike stateChanged(ConnectedState), which can arrive a beat earlier
	// (measured on macOS: the socket read ConnectedState but isOpen() was still
	// false, and the subscribe write returned -1).
	QObject::connect(&this->mEventSocket, &QLocalSocket::connected, this, [this]() {
		this->mEventReader.setDevice(&this->mEventSocket);
		// Subscribe. nigiri replays the current state right after, so the model
		// is populated before the first live change.
		this->mEventSocket.write("event-stream\n");
		this->mEventSocket.flush();
	});
	this->connectToNigiri();
}

void NigiriIpc::connectToNigiri() {
	this->mEventSocket.connectToServer(socketPath(), QLocalSocket::ReadWrite);
}

void NigiriIpc::onEventSocketState(QLocalSocket::LocalSocketState state) {
	if (state == QLocalSocket::UnconnectedState) {
		qCDebug(logNigiri) << "event socket disconnected from" << socketPath();
	}
}

void NigiriIpc::onEventSocketReady() {
	// One JSON object per line. Transactional: readUntil returns the line only
	// once a full one is buffered, else commit fails and we wait for more.
	while (true) {
		this->mEventReader.startTransaction();
		auto line = this->mEventReader.readUntil('\n');
		if (!this->mEventReader.commitTransaction()) return;
		if (line.isEmpty()) continue;

		auto doc = QJsonDocument::fromJson(line);
		if (!doc.isObject()) continue;
		auto object = doc.object();
		// niri-shaped events are a single {EventName: payload}. The legacy
		// {"event": "..."} lines are ignored - the capitalised events carry the
		// same information in a stable shape.
		if (object.contains("event")) continue;
		if (object.isEmpty()) continue;

		auto name = object.begin().key();
		auto data = object.begin().value().toObject();
		this->handleEvent(name, data);
		emit this->rawEvent(name, data);
	}
}

void NigiriIpc::handleEvent(const QString& name, const QJsonObject& data) {
	if (name == "WorkspacesChanged") {
		this->applyWorkspaces(data.value("workspaces").toArray());
	} else if (name == "WorkspaceActivated") {
		auto* ws = this->findWorkspaceById(data.value("id").toInt(), false);
		if (ws != nullptr) this->bFocusedWorkspace = ws;
	} else if (name == "WindowOpenedOrChanged") {
		auto window = data.value("window").toObject();
		auto* w = this->findWindowById(window.value("id").toInt(), true);
		w->updateFromJson(window);
	} else if (name == "WindowClosed") {
		auto* w = this->findWindowById(data.value("id").toInt(), false);
		if (w != nullptr) {
			if (this->bActiveWindow.value() == w) this->bActiveWindow = nullptr;
			this->mWindows.removeObject(w);
			w->deleteLater();
		}
	} else if (name == "WindowFocusChanged") {
		auto id = data.value("id");
		this->bFocusedWindowId = id.isDouble() ? id.toInt() : 0;
		this->updateActiveWindow();
	}
	// OverviewOpenedOrClosed is carried on rawEvent for now.
}

void NigiriIpc::updateActiveWindow() {
	// The window whose id is focused, or null. Each window's own `active` is a
	// binding off focusedWindowId, so it recomputes itself; this only tracks
	// the pointer for `Nigiri.activeWindow`.
	this->bActiveWindow = this->findWindowById(this->bFocusedWindowId.value(), false);
}

NigiriWindow* NigiriIpc::findWindowById(qint32 id, bool createIfMissing) {
	for (auto* object: this->mWindows.values()) {
		auto* w = qobject_cast<NigiriWindow*>(object);
		if (w != nullptr && w->bindableId().value() == id) return w;
	}
	if (!createIfMissing) return nullptr;
	auto* w = new NigiriWindow(this);
	w->bindableId().setValue(id);
	this->mWindows.insertObject(w);
	return w;
}

void NigiriIpc::applyWorkspaces(const QJsonArray& array) {
	// Update in place, keyed by id, so QML delegates and bindings survive a
	// refresh instead of being torn down and rebuilt. Match Hyprland's
	// findByIdOrCreate + prune pattern.
	QList<qint32> seen;
	NigiriWorkspace* focused = nullptr;
	for (auto value: array) {
		auto object = value.toObject();
		auto id = object.value("id").toInt();
		seen.append(id);
		auto* ws = this->findWorkspaceById(id, true);
		ws->updateFromJson(object);
		if (object.value("is_focused").toBool()) focused = ws;
	}

	// Drop workspaces that no longer exist.
	const auto current = this->mWorkspaces.values();
	for (auto* object: current) {
		auto* ws = qobject_cast<NigiriWorkspace*>(object);
		if (ws != nullptr && !seen.contains(ws->bindableId().value())) {
			if (this->bFocusedWorkspace.value() == ws) this->bFocusedWorkspace = nullptr;
			this->mWorkspaces.removeObject(ws);
			ws->deleteLater();
		}
	}

	this->bFocusedWorkspace = focused;
}

NigiriWorkspace* NigiriIpc::findWorkspaceById(qint32 id, bool createIfMissing) {
	for (auto* object: this->mWorkspaces.values()) {
		auto* ws = qobject_cast<NigiriWorkspace*>(object);
		if (ws != nullptr && ws->bindableId().value() == id) return ws;
	}
	if (!createIfMissing) return nullptr;

	auto* ws = new NigiriWorkspace(this);
	ws->bindableId().setValue(id);
	// Keep the model ordered by strip position so a bar iterating `values`
	// shows them left to right.
	this->mWorkspaces.insertObjectSorted(ws, [](NigiriWorkspace* a, NigiriWorkspace* b) {
		return a->bindableIdx().value() < b->bindableIdx().value();
	});
	return ws;
}

void NigiriIpc::dispatch(const QString& action) {
	// One-shot request/reply, done synchronously with short waits. A command is
	// user-initiated and rare (a click on a bar), and nigiri answers a request
	// socket in well under a millisecond, so the brief block is invisible -
	// and it sidesteps the async connect flakiness the event socket already
	// worked around (nigiri's own `msg` client is blocking for the same reason).
	QLocalSocket socket;
	socket.connectToServer(socketPath(), QLocalSocket::ReadWrite);
	if (!socket.waitForConnected(200)) {
		qCDebug(logNigiri) << "dispatch could not reach nigiri:" << action;
		return;
	}
	socket.write(QStringLiteral("action %1\n").arg(action).toUtf8());
	socket.flush();
	socket.waitForBytesWritten(200);
	// Drain the {"ok":true} reply so nigiri isn't left writing into a closed
	// socket, then close.
	socket.waitForReadyRead(200);
	socket.readAll();
	socket.disconnectFromServer();
}

} // namespace qs::nigiri
