#pragma once

#include <qjsonobject.h>
#include <qlocalserver.h>
#include <qlocalsocket.h>
#include <qobject.h>
#include <qqmlintegration.h>
#include <qstring.h>
#include <qtmetamacros.h>
#include <qtypes.h>
#include <qvariant.h>
#include <qvector.h>

#include "../../core/doc.hpp"
#include "../../core/model.hpp"
#include "../../core/reload.hpp"
#include "../../core/retainable.hpp"

// The macOS notifications backend.
//
// The Linux service makes the shell the freedesktop notification SERVER, so
// every app's notification is delivered to it. macOS owns notifications in the
// system Notification Center and offers NO public API for a third-party app to
// receive ANOTHER app's notifications (DistributedNotificationCenter,
// NSWorkspace and notification-service extensions all fail for this; the only
// route to others' notifications is scraping the private Notification Center
// SQLite DB, which needs Full Disk Access and breaks every OS release - not
// done here).
//
// What CAN be delivered is every notification that flows through OUR path:
// `notify-send`. DMS raises its own alerts that way (battery, portal errors),
// and any app/script on the box can too. So this NotificationServer listens on
// a local socket (/tmp/dms-notifications.sock); the notify-send shim hands each
// notification to it as one JSON line, and it drives the same
// `Quickshell.Services.Notifications` surface the Linux server does - real
// popups and a real notification center, for everything launched through
// notify-send. Native macOS apps posting straight to the system center are the
// only thing left out, and nothing public can change that.
namespace qs::mac::notifications {

///! The urgency level of a notification.
class NotificationUrgency: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_SINGLETON;

public:
	enum Enum : quint8 {
		Low = 0,
		Normal = 1,
		Critical = 2,
	};
	Q_ENUM(Enum);
	Q_INVOKABLE static QString toString(qs::mac::notifications::NotificationUrgency::Enum value);
};

///! The reason a notification was closed.
class NotificationCloseReason: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_SINGLETON;

public:
	enum Enum : quint8 {
		Expired = 1,
		Dismissed = 2,
		CloseRequested = 3,
	};
	Q_ENUM(Enum);
	Q_INVOKABLE static QString toString(qs::mac::notifications::NotificationCloseReason::Enum value);
};

///! An action that can be taken on a notification.
/// Provided for API compatibility. notify-send is fire-and-forget (the caller
/// has already detached), so there is no channel to deliver ActionInvoked back
/// to it; actions are not populated for socket-delivered notifications rather
/// than shown as buttons that do nothing.
class NotificationAction: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(QString identifier READ identifier CONSTANT);
	Q_PROPERTY(QString text READ text NOTIFY textChanged);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("NotificationActions must be acquired from a Notification");

public:
	explicit NotificationAction(QObject* parent = nullptr): QObject(parent) {}

	[[nodiscard]] QString identifier() const { return {}; }
	[[nodiscard]] QString text() const { return {}; }
	Q_INVOKABLE void invoke() {}

signals:
	void textChanged();
};

class NotificationServer;

///! A notification.
/// The macOS counterpart of the Linux `Notification`, populated from a
/// notify-send delivery over the server socket.
class Notification
    : public QObject
    , public Retainable {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(quint32 id READ id CONSTANT);
	Q_PROPERTY(bool tracked READ isTracked WRITE setTracked NOTIFY trackedChanged);
	Q_PROPERTY(bool lastGeneration READ isLastGeneration CONSTANT);
	Q_PROPERTY(qreal expireTimeout READ expireTimeout NOTIFY expireTimeoutChanged);
	Q_PROPERTY(QString appName READ appName NOTIFY appNameChanged);
	Q_PROPERTY(QString appIcon READ appIcon NOTIFY appIconChanged);
	Q_PROPERTY(QString summary READ summary NOTIFY summaryChanged);
	Q_PROPERTY(QString body READ body NOTIFY bodyChanged);
	Q_PROPERTY(qs::mac::notifications::NotificationUrgency::Enum urgency READ urgency NOTIFY urgencyChanged);
	Q_PROPERTY(QList<qs::mac::notifications::NotificationAction*> actions READ actions NOTIFY actionsChanged);
	Q_PROPERTY(bool hasActionIcons READ hasActionIcons NOTIFY hasActionIconsChanged);
	Q_PROPERTY(bool resident READ resident NOTIFY residentChanged);
	Q_PROPERTY(bool transient READ isTransient NOTIFY transientChanged);
	Q_PROPERTY(QString desktopEntry READ desktopEntry NOTIFY desktopEntryChanged);
	Q_PROPERTY(QString image READ image NOTIFY imageChanged);
	Q_PROPERTY(bool hasInlineReply READ hasInlineReply NOTIFY hasInlineReplyChanged);
	Q_PROPERTY(QString inlineReplyPlaceholder READ inlineReplyPlaceholder NOTIFY inlineReplyPlaceholderChanged);
	Q_PROPERTY(QVariantMap hints READ hints NOTIFY hintsChanged);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("Notifications must be acquired from a NotificationServer");

	friend class NotificationServer;

public:
	explicit Notification(QObject* parent = nullptr): QObject(parent) {}

	[[nodiscard]] quint32 id() const { return this->mId; }
	[[nodiscard]] bool isTracked() const { return this->mTracked; }
	void setTracked(bool tracked);
	[[nodiscard]] bool isLastGeneration() const { return false; }
	[[nodiscard]] qreal expireTimeout() const { return this->mExpireTimeout; }
	[[nodiscard]] QString appName() const { return this->mAppName; }
	[[nodiscard]] QString appIcon() const { return this->mAppIcon; }
	[[nodiscard]] QString summary() const { return this->mSummary; }
	[[nodiscard]] QString body() const { return this->mBody; }
	[[nodiscard]] NotificationUrgency::Enum urgency() const { return this->mUrgency; }
	[[nodiscard]] QList<NotificationAction*> actions() const { return {}; }
	[[nodiscard]] bool hasActionIcons() const { return false; }
	[[nodiscard]] bool resident() const { return false; }
	[[nodiscard]] bool isTransient() const { return this->mTransient; }
	[[nodiscard]] QString desktopEntry() const { return this->mDesktopEntry; }
	[[nodiscard]] QString image() const { return this->mImage; }
	[[nodiscard]] bool hasInlineReply() const { return false; }
	[[nodiscard]] QString inlineReplyPlaceholder() const { return {}; }
	[[nodiscard]] QVariantMap hints() const { return this->mHints; }

	Q_INVOKABLE void expire();
	Q_INVOKABLE void dismiss();
	Q_INVOKABLE void sendInlineReply(const QString& /*replyText*/) {}

signals:
	/// Sent when a notification has been closed.
	///
	/// The notification object will be destroyed as soon as all signal handlers exit.
	void closed(qs::mac::notifications::NotificationCloseReason::Enum reason);

	void trackedChanged();
	void expireTimeoutChanged();
	void appNameChanged();
	void appIconChanged();
	void summaryChanged();
	void bodyChanged();
	void urgencyChanged();
	void actionsChanged();
	void hasActionIconsChanged();
	void residentChanged();
	void transientChanged();
	void desktopEntryChanged();
	void imageChanged();
	void hasInlineReplyChanged();
	void inlineReplyPlaceholderChanged();
	void hintsChanged();

private:
	NotificationServer* mServer = nullptr;
	quint32 mId = 0;
	bool mTracked = false;
	qreal mExpireTimeout = -1.0;
	QString mAppName;
	QString mAppIcon;
	QString mSummary;
	QString mBody;
	NotificationUrgency::Enum mUrgency = NotificationUrgency::Normal;
	bool mTransient = false;
	QString mDesktopEntry;
	QString mImage;
	QVariantMap mHints;
};

///! Notification server.
/// The macOS counterpart of the Linux `NotificationServer`: it listens on a
/// local socket for notify-send deliveries and tracks them, so the shell's
/// popups and notification center light up for everything launched through
/// notify-send.
class NotificationServer: public PostReloadHook {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(bool keepOnReload READ keepOnReload WRITE setKeepOnReload NOTIFY keepOnReloadChanged);
	Q_PROPERTY(bool persistenceSupported READ persistenceSupported WRITE setPersistenceSupported NOTIFY persistenceSupportedChanged);
	Q_PROPERTY(bool bodySupported READ bodySupported WRITE setBodySupported NOTIFY bodySupportedChanged);
	Q_PROPERTY(bool bodyMarkupSupported READ bodyMarkupSupported WRITE setBodyMarkupSupported NOTIFY bodyMarkupSupportedChanged);
	Q_PROPERTY(bool bodyHyperlinksSupported READ bodyHyperlinksSupported WRITE setBodyHyperlinksSupported NOTIFY bodyHyperlinksSupportedChanged);
	Q_PROPERTY(bool bodyImagesSupported READ bodyImagesSupported WRITE setBodyImagesSupported NOTIFY bodyImagesSupportedChanged);
	Q_PROPERTY(bool actionsSupported READ actionsSupported WRITE setActionsSupported NOTIFY actionsSupportedChanged);
	Q_PROPERTY(bool actionIconsSupported READ actionIconsSupported WRITE setActionIconsSupported NOTIFY actionIconsSupportedChanged);
	Q_PROPERTY(bool imageSupported READ imageSupported WRITE setImageSupported NOTIFY imageSupportedChanged);
	Q_PROPERTY(bool inlineReplySupported READ inlineReplySupported WRITE setInlineReplySupported NOTIFY inlineReplySupportedChanged);
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::notifications::Notification>*);
	Q_PROPERTY(UntypedObjectModel* trackedNotifications READ trackedNotifications NOTIFY trackedNotificationsChanged);
	Q_PROPERTY(QVector<QString> extraHints READ extraHints WRITE setExtraHints NOTIFY extraHintsChanged);
	// clang-format on
	QML_NAMED_ELEMENT(NotificationServer);

	friend class Notification;

public:
	explicit NotificationServer(QObject* parent = nullptr);

	// Start listening once the reload settles, mirroring upstream's server
	// which binds its name in the post-reload hook.
	void onPostReload() override;

	[[nodiscard]] bool keepOnReload() const { return this->mKeepOnReload; }
	void setKeepOnReload(bool v) {
		this->set(this->mKeepOnReload, v, &NotificationServer::keepOnReloadChanged);
	}
	[[nodiscard]] bool persistenceSupported() const { return this->mPersistenceSupported; }
	void setPersistenceSupported(bool v) {
		this->set(this->mPersistenceSupported, v, &NotificationServer::persistenceSupportedChanged);
	}
	[[nodiscard]] bool bodySupported() const { return this->mBodySupported; }
	void setBodySupported(bool v) {
		this->set(this->mBodySupported, v, &NotificationServer::bodySupportedChanged);
	}
	[[nodiscard]] bool bodyMarkupSupported() const { return this->mBodyMarkupSupported; }
	void setBodyMarkupSupported(bool v) {
		this->set(this->mBodyMarkupSupported, v, &NotificationServer::bodyMarkupSupportedChanged);
	}
	[[nodiscard]] bool bodyHyperlinksSupported() const { return this->mBodyHyperlinksSupported; }
	void setBodyHyperlinksSupported(bool v) {
		this->set(
		    this->mBodyHyperlinksSupported,
		    v,
		    &NotificationServer::bodyHyperlinksSupportedChanged
		);
	}
	[[nodiscard]] bool bodyImagesSupported() const { return this->mBodyImagesSupported; }
	void setBodyImagesSupported(bool v) {
		this->set(this->mBodyImagesSupported, v, &NotificationServer::bodyImagesSupportedChanged);
	}
	[[nodiscard]] bool actionsSupported() const { return this->mActionsSupported; }
	void setActionsSupported(bool v) {
		this->set(this->mActionsSupported, v, &NotificationServer::actionsSupportedChanged);
	}
	[[nodiscard]] bool actionIconsSupported() const { return this->mActionIconsSupported; }
	void setActionIconsSupported(bool v) {
		this->set(this->mActionIconsSupported, v, &NotificationServer::actionIconsSupportedChanged);
	}
	[[nodiscard]] bool imageSupported() const { return this->mImageSupported; }
	void setImageSupported(bool v) {
		this->set(this->mImageSupported, v, &NotificationServer::imageSupportedChanged);
	}
	[[nodiscard]] bool inlineReplySupported() const { return this->mInlineReplySupported; }
	void setInlineReplySupported(bool v) {
		this->set(this->mInlineReplySupported, v, &NotificationServer::inlineReplySupportedChanged);
	}

	[[nodiscard]] ObjectModel<Notification>* trackedNotifications() { return &this->mTracked; }

	[[nodiscard]] QVector<QString> extraHints() const { return this->mExtraHints; }
	void setExtraHints(const QVector<QString>& hints) {
		this->mExtraHints = hints;
		emit this->extraHintsChanged();
	}

signals:
	// Emitted when a notification arrives. A shell binds `onNotification` and
	// sets `tracked = true` to keep it; an untracked one is dropped.
	void notification(qs::mac::notifications::Notification* notification);

	void keepOnReloadChanged();
	void persistenceSupportedChanged();
	void bodySupportedChanged();
	void bodyMarkupSupportedChanged();
	void bodyHyperlinksSupportedChanged();
	void bodyImagesSupportedChanged();
	void actionsSupportedChanged();
	void actionIconsSupportedChanged();
	void imageSupportedChanged();
	void inlineReplySupportedChanged();
	void trackedNotificationsChanged();
	void extraHintsChanged();

private:
	void set(bool& field, bool value, void (NotificationServer::*signal)()) {
		if (field == value) return;
		field = value;
		emit(this->*signal)();
	}

	// Bind the local socket (idempotent - safe to call again after a reload).
	void startListening();
	void onNewConnection();
	void readFrom(QLocalSocket* socket);
	// Parse one JSON delivery, build (or replace) a Notification and offer it.
	void deliver(const QJsonObject& json);
	// Called by Notification::setTracked to add/remove it from the model.
	void setNotificationTracked(Notification* notification, bool tracked);
	// Called by Notification::dismiss/expire.
	void closeNotification(Notification* notification, NotificationCloseReason::Enum reason);

	QLocalServer* mSocketServer = nullptr;
	quint32 mNextId = 1;

	bool mKeepOnReload = true;
	bool mPersistenceSupported = false;
	bool mBodySupported = true;
	bool mBodyMarkupSupported = false;
	bool mBodyHyperlinksSupported = false;
	bool mBodyImagesSupported = false;
	bool mActionsSupported = false;
	bool mActionIconsSupported = false;
	bool mImageSupported = false;
	bool mInlineReplySupported = false;
	QVector<QString> mExtraHints;
	ObjectModel<Notification> mTracked {this};
};

} // namespace qs::mac::notifications
