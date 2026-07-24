#include "notifications.hpp"

#include <qbytearray.h>
#include <qhash.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qjsonvalue.h>
#include <qlocalserver.h>
#include <qlocalsocket.h>
#include <qstring.h>
#include <qvariant.h>

namespace qs::mac::notifications {

namespace {
// The notify-send shim connects here and writes one JSON line per
// notification. A fixed path both sides agree on, like the DMS daemon sockets.
const QString SOCKET_PATH = QStringLiteral("/tmp/dms-notifications.sock");
}

QString NotificationUrgency::toString(NotificationUrgency::Enum value) {
	switch (value) {
	case Low: return "Low";
	case Normal: return "Normal";
	case Critical: return "Critical";
	default: return "Invalid notification urgency";
	}
}

QString NotificationCloseReason::toString(NotificationCloseReason::Enum value) {
	switch (value) {
	case Expired: return "Expired";
	case Dismissed: return "Dismissed";
	case CloseRequested: return "CloseRequested";
	default: return "Invalid notification close reason";
	}
}

// ---- Notification ----

void Notification::setTracked(bool tracked) {
	if (this->mTracked == tracked) return;
	this->mTracked = tracked;
	if (this->mServer != nullptr) this->mServer->setNotificationTracked(this, tracked);
	emit this->trackedChanged();
}

void Notification::dismiss() {
	if (this->mServer != nullptr) {
		this->mServer->closeNotification(this, NotificationCloseReason::Dismissed);
	}
}

void Notification::expire() {
	if (this->mServer != nullptr) {
		this->mServer->closeNotification(this, NotificationCloseReason::Expired);
	}
}

// ---- NotificationServer ----

NotificationServer::NotificationServer(QObject* parent): PostReloadHook(parent) {
	this->mSocketServer = new QLocalServer(this);
	QObject::connect(
	    this->mSocketServer,
	    &QLocalServer::newConnection,
	    this,
	    &NotificationServer::onNewConnection
	);
}

void NotificationServer::onPostReload() { this->startListening(); }

void NotificationServer::startListening() {
	if (this->mSocketServer->isListening()) return;
	// Clear a socket file left by a previous run/instance, then bind.
	QLocalServer::removeServer(SOCKET_PATH);
	if (!this->mSocketServer->listen(SOCKET_PATH)) {
		qWarning(
		    "notifications: failed to listen on %s: %s",
		    qUtf8Printable(SOCKET_PATH),
		    qUtf8Printable(this->mSocketServer->errorString())
		);
	}
}

void NotificationServer::onNewConnection() {
	while (auto* socket = this->mSocketServer->nextPendingConnection()) {
		QObject::connect(socket, &QLocalSocket::readyRead, this, [this, socket]() {
			this->readFrom(socket);
		});
		QObject::connect(socket, &QLocalSocket::disconnected, this, [this, socket]() {
			this->readFrom(socket);
			socket->deleteLater();
		});
	}
}

void NotificationServer::readFrom(QLocalSocket* socket) {
	// notify-send sends one JSON object per line and then hangs up; process
	// every complete line as it arrives (a partial tail waits for more).
	auto pending = socket->property("buffer").toByteArray();
	pending += socket->readAll();

	int newline = 0;
	while ((newline = pending.indexOf('\n')) != -1) {
		auto line = pending.left(newline);
		pending.remove(0, newline + 1);
		if (line.trimmed().isEmpty()) continue;
		auto doc = QJsonDocument::fromJson(line);
		if (doc.isObject()) this->deliver(doc.object());
	}
	socket->setProperty("buffer", pending);
}

void NotificationServer::deliver(const QJsonObject& json) {
	auto urgencyOf = [](int value) {
		switch (value) {
		case 0: return NotificationUrgency::Low;
		case 2: return NotificationUrgency::Critical;
		default: return NotificationUrgency::Normal;
		}
	};

	auto replacesId = static_cast<quint32>(json.value("replacesId").toInt(0));

	// Replace-in-place: notify-send -r reuses an id; find the tracked one and
	// update its fields so the shell's existing popup/entry mutates.
	if (replacesId != 0) {
		for (auto* existing: this->mTracked.valueList()) {
			if (existing->mId != replacesId) continue;
			existing->mAppName = json.value("appName").toString();
			existing->mAppIcon = json.value("appIcon").toString();
			existing->mSummary = json.value("summary").toString();
			existing->mBody = json.value("body").toString();
			existing->mUrgency = urgencyOf(json.value("urgency").toInt(1));
			existing->mImage = json.value("image").toString();
			emit existing->appNameChanged();
			emit existing->appIconChanged();
			emit existing->summaryChanged();
			emit existing->bodyChanged();
			emit existing->urgencyChanged();
			emit existing->imageChanged();
			return;
		}
	}

	auto* notif = new Notification(this);
	notif->mServer = this;
	notif->mId = this->mNextId++;
	notif->mAppName = json.value("appName").toString();
	notif->mAppIcon = json.value("appIcon").toString();
	notif->mSummary = json.value("summary").toString();
	notif->mBody = json.value("body").toString();
	notif->mUrgency = urgencyOf(json.value("urgency").toInt(1));
	notif->mExpireTimeout = json.value("expireTimeout").toDouble(-1.0);
	notif->mTransient = json.value("transient").toBool(false);
	notif->mDesktopEntry = json.value("desktopEntry").toString();
	notif->mImage = json.value("image").toString();
	notif->mHints = json.value("hints").toObject().toVariantMap();

	// The shell keeps it by setting tracked = true inside this signal; if it
	// does not, the notification is dropped (upstream semantics).
	emit this->notification(notif);
	if (!notif->isTracked()) notif->deleteLater();
}

void NotificationServer::setNotificationTracked(Notification* notification, bool tracked) {
	if (tracked) {
		if (!this->mTracked.valueList().contains(notification)) {
			this->mTracked.insertObject(notification);
		}
	} else {
		this->mTracked.removeObject(notification);
	}
}

void NotificationServer::closeNotification(
    Notification* notification,
    NotificationCloseReason::Enum reason
) {
	emit notification->closed(reason);
	this->mTracked.removeObject(notification);
	notification->deleteLater();
}

} // namespace qs::mac::notifications
