#pragma once

#include <qlogging.h>
#include <qobject.h>
#include <qqmlintegration.h>
#include <qstring.h>
#include <qtmetamacros.h>
#include <qtypes.h>

// macOS stub for Quickshell.Services.Pam, mirroring upstream's surface
// (src/services/pam/qml.hpp + conversation.hpp) name for name. macOS DOES
// ship PAM (/etc/pam.d exists), but the lock/auth path on this platform is
// system-owned (dms-darwin's NativeLock drives the real unlock), so no
// conversation ever runs here: start() honestly refuses and `active` stays
// false. The full surface exists so upstream lock configs load and their
// handlers attach.
namespace qs::mac::pam {

///! The result of an authentication.
/// See @@PamContext.completed(s).
class PamResult: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_SINGLETON;

public:
	enum Enum : quint8 {
		/// Authentication was successful.
		Success = 0,
		/// Authentication failed.
		Failed = 1,
		/// An error occurred while trying to authenticate.
		Error = 2,
		/// The authentication method ran out of tries and should not be used again.
		MaxTries = 3,
	};
	Q_ENUM(Enum);

	Q_INVOKABLE static QString toString(qs::mac::pam::PamResult::Enum value);
};

///! An error that occurred during an authentication.
/// See @@PamContext.error(s).
class PamError: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_SINGLETON;

public:
	enum Enum : quint8 {
		/// Failed to start the pam session.
		StartFailed = 1,
		/// Failed to try to authenticate the user.
		/// This is not the same as the user failing to authenticate.
		TryAuthFailed = 2,
		/// An error occurred inside quickshell's pam interface.
		InternalError = 3,
	};
	Q_ENUM(Enum);

	Q_INVOKABLE static QString toString(qs::mac::pam::PamError::Enum value);
};

///! Connection to pam.
/// Connection to pam. On macOS no conversation ever runs (the lock path is
/// system-owned); the surface matches upstream so configs load unchanged.
class PamContext: public QObject {
	Q_OBJECT;
	// clang-format off
	/// If the pam context is actively performing an authentication.
	///
	/// Setting this value behaves exactly the same as calling @@start() and @@abort().
	Q_PROPERTY(bool active READ isActive WRITE setActive NOTIFY activeChanged);
	/// The pam configuration to use. Defaults to "login".
	Q_PROPERTY(QString config READ config WRITE setConfig NOTIFY configChanged);
	/// The pam configuration directory to use. Defaults to "/etc/pam.d".
	Q_PROPERTY(QString configDirectory READ configDirectory WRITE setConfigDirectory NOTIFY configDirectoryChanged);
	/// The user to authenticate as. If unset the current user will be used.
	Q_PROPERTY(QString user READ user WRITE setUser NOTIFY userChanged);
	/// The last message sent by pam.
	Q_PROPERTY(QString message READ message NOTIFY messageChanged);
	/// If the last message should be shown as an error.
	Q_PROPERTY(bool messageIsError READ messageIsError NOTIFY messageIsErrorChanged);
	/// If pam currently wants a response.
	Q_PROPERTY(bool responseRequired READ isResponseRequired NOTIFY responseRequiredChanged);
	/// If the user's response should be visible. Only valid when @@responseRequired is true.
	Q_PROPERTY(bool responseVisible READ isResponseVisible NOTIFY responseVisibleChanged);
	// clang-format on
	QML_ELEMENT;

public:
	explicit PamContext(QObject* parent = nullptr): QObject(parent) {}

	/// Start an authentication session. Returns if the session was started successfully.
	Q_INVOKABLE bool start();

	/// Abort a running authentication session.
	Q_INVOKABLE void abort() {}

	/// Respond to pam.
	Q_INVOKABLE void respond(const QString& response);

	[[nodiscard]] bool isActive() const { return false; } // NOLINT
	// Upstream's documented equivalence: assigning `active` IS start()/abort().
	void setActive(bool active);

	[[nodiscard]] QString config() const { return this->mConfig; }
	void setConfig(const QString& config);

	[[nodiscard]] QString configDirectory() const { return this->mConfigDirectory; }
	void setConfigDirectory(const QString& configDirectory);

	[[nodiscard]] QString user() const { return this->mUser; }
	void setUser(const QString& user);

	[[nodiscard]] static QString message() { return {}; }
	[[nodiscard]] static bool messageIsError() { return false; }
	[[nodiscard]] static bool isResponseRequired() { return false; }
	[[nodiscard]] static bool isResponseVisible() { return false; }

signals:
	/// Emitted whenever authentication completes.
	void completed(qs::mac::pam::PamResult::Enum result);
	/// Emitted if pam fails to perform authentication normally.
	///
	/// A `completed(PamResult.Error)` will be emitted after this event.
	void error(qs::mac::pam::PamError::Enum error);

	/// Emitted whenever pam sends a new message, after the change signals for
	/// `message`, `messageIsError`, and `responseRequired`. No arguments,
	/// like upstream (qml.hpp:109) - the message travels in the properties.
	void pamMessage();

	void activeChanged();
	void configChanged();
	void configDirectoryChanged();
	void userChanged();
	void messageChanged();
	void messageIsErrorChanged();
	void responseRequiredChanged();
	void responseVisibleChanged();

private:
	// Upstream's defaults (qml.hpp:130-131).
	QString mConfig = "login";
	QString mConfigDirectory = "/etc/pam.d";
	QString mUser;
};

} // namespace qs::mac::pam
