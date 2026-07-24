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
		qCDebug(logNigiri) << "event socket connected to" << socketPath() << "- subscribing";
		// A reconnect inherits the dead connection's half-read line in the
		// reader's buffer; re-attaching the device starts it clean.
		this->mEventReader.setDevice(&this->mEventSocket);
		// Subscribe. nigiri replays the current state right after, so the model
		// is populated before the first live change.
		//
		// DIALECT CONTRACT: this is the legacy bare-word form ("event-stream"),
		// a documented nigiri extension kept for bento (NiriProtocol.swift:9-13)
		// while DMS speaks niri's real JSON on the same socket - nigiri answers
		// each line in the dialect it arrived in. The bare words here and in
		// dispatch()/panel_window.cpp (action reserve-zone) are load-bearing:
		// nigiri must not drop them until bento migrates to the JSON forms.
		this->mEventSocket.write("event-stream\n");
		this->mEventSocket.flush();
	});

	// The compositor can be down at login (start order) or restart at any
	// time; either way the socket lands in UnconnectedState and nothing else
	// would re-open it. Retry forever on a slow heartbeat, the panel side's
	// pattern. On reconnect nigiri replays the full state and applyWindows /
	// applyWorkspaces prune whatever went stale.
	this->mReconnectTimer.setInterval(3000);
	QObject::connect(&this->mReconnectTimer, &QTimer::timeout, this, [this]() {
		if (this->mEventSocket.state() == QLocalSocket::UnconnectedState) {
			this->connectToNigiri();
		}
	});
	this->mReconnectTimer.start();

	this->connectToNigiri();
}

void NigiriIpc::connectToNigiri() {
	this->mEventSocket.connectToServer(socketPath(), QLocalSocket::ReadWrite);
}

void NigiriIpc::onEventSocketState(QLocalSocket::LocalSocketState state) {
	if (state == QLocalSocket::UnconnectedState) {
		qCDebug(logNigiri) << "event socket disconnected from" << socketPath() << "- will retry";
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
	} else if (name == "WindowsChanged") {
		// niri's bulk snapshot: how the event stream seeds a new subscriber -
		// and the only way a RECONNECTING client can drop windows that closed
		// while it was away. Reconcile: upsert what is present, prune the rest.
		this->applyWindows(data.value("windows").toArray());
	} else if (name == "WorkspaceActivated") {
		// niri's event-stream contract (niri-ipc EventStreamState): the
		// workspace with this id becomes active on its output and every other
		// workspace on that output goes inactive; when `focused` is set, focus
		// moves with it. nigiri happens to follow this event with a full
		// WorkspacesChanged snapshot today, but niri upstream does NOT - the
		// flags must be derived from this event alone or they would go stale
		// the day nigiri drops the redundant snapshot.
		auto id = data.value("id").toInt();
		auto focused = data.value("focused").toBool();
		auto* target = this->findWorkspaceById(id, false);
		if (target != nullptr) {
			// Single output today (PORT.md M2): every workspace is a sibling of
			// the target, so exactly one stays active.
			for (auto* object: this->mWorkspaces.values()) {
				auto* ws = qobject_cast<NigiriWorkspace*>(object);
				if (ws == nullptr) continue;
				ws->bindableActive().setValue(ws == target);
				if (focused) ws->bindableFocused().setValue(ws == target);
			}
			if (focused) this->bFocusedWorkspace = target;
		}
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

void NigiriIpc::applyWindows(const QJsonArray& array) {
	// Same in-place reconcile as applyWorkspaces: update keyed by id so QML
	// delegates survive, then prune what the snapshot no longer contains.
	QList<qint32> seen;
	for (auto value: array) {
		auto object = value.toObject();
		auto id = object.value("id").toInt();
		seen.append(id);
		auto* w = this->findWindowById(id, true);
		w->updateFromJson(object);
	}

	const auto current = this->mWindows.values();
	for (auto* object: current) {
		auto* w = qobject_cast<NigiriWindow*>(object);
		if (w != nullptr && !seen.contains(w->bindableId().value())) {
			if (this->bActiveWindow.value() == w) this->bActiveWindow = nullptr;
			this->mWindows.removeObject(w);
			w->deleteLater();
		}
	}

	this->updateActiveWindow();
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
	// Legacy bare-word dialect - see the DIALECT CONTRACT note in the ctor.
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
