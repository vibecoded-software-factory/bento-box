#pragma once

#include <qlist.h>
#include <qobject.h>
#include <qproperty.h>
#include <qqmlintegration.h>
#include <qstring.h>
#include <qtmetamacros.h>
#include <qtypes.h>

#include "../../core/retainable.hpp"

// macOS stub for Quickshell.Services.Polkit, mirroring upstream's surface
// (src/services/polkit/{qml,flow,identity}.hpp) name for name. macOS has no
// polkit daemon - privilege prompts are system-owned dialogs - so the agent
// can never register: isRegistered/isActive stay false, flow stays null,
// and no AuthFlow/Identity instance is ever created. The full surface
// exists so DMS's PolkitAgent{} instance and its AuthFlow bindings load
// and attach unchanged.
namespace qs::mac::polkit {

class AuthFlow;

///! Represents a user or group that can be used to authenticate.
/// Never instantiated on macOS (no polkit); see @@PolkitAgent.
class Identity: public QObject {
	Q_OBJECT;
	Q_DISABLE_COPY_MOVE(Identity);

	// clang-format off
	/// The Id of the identity. If the identity is a user, this is the user's uid. See @@isGroup.
	Q_PROPERTY(quint32 id READ id CONSTANT);
	/// The name of the user or group.
	Q_PROPERTY(QString string READ name CONSTANT);
	/// The full name of the user or group, if available. Otherwise the same as @@name.
	Q_PROPERTY(QString displayName READ displayName CONSTANT);
	/// Indicates if this identity is a group or a user.
	Q_PROPERTY(bool isGroup READ isGroup CONSTANT);
	QML_UNCREATABLE("Identities cannot be created directly.");
	// clang-format on

public:
	explicit Identity(QObject* parent = nullptr): QObject(parent) {}
	~Identity() override = default;

	[[nodiscard]] static quint32 id() { return 0; }
	[[nodiscard]] static QString name() { return {}; }
	[[nodiscard]] static QString displayName() { return {}; }
	[[nodiscard]] static bool isGroup() { return false; }
};

///! An ongoing polkit authentication flow.
/// Never instantiated on macOS (no polkit); @@PolkitAgent.flow is always
/// null. The type and its full surface exist so upstream configs load.
class AuthFlow
    : public QObject
    , public Retainable {
	Q_OBJECT;
	QML_ELEMENT;
	Q_DISABLE_COPY_MOVE(AuthFlow);
	QML_UNCREATABLE("AuthFlow can only be obtained from PolkitAgent.");

	// clang-format off
	/// The main message to present to the user.
	Q_PROPERTY(QString message READ message CONSTANT);
	/// The icon to present to the user in association with the message.
	Q_PROPERTY(QString iconName READ iconName CONSTANT);
	/// The action ID represents the action that is being authorized.
	Q_PROPERTY(QString actionId READ actionId CONSTANT);
	/// A cookie that identifies this authentication request.
	Q_PROPERTY(QString cookie READ cookie CONSTANT);
	/// The list of identities that may be used to authenticate.
	Q_PROPERTY(QList<qs::mac::polkit::Identity*> identities READ identities CONSTANT);
	/// The identity that will be used to authenticate.
	Q_PROPERTY(qs::mac::polkit::Identity* selectedIdentity READ default WRITE setSelectedIdentity NOTIFY selectedIdentityChanged BINDABLE selectedIdentity);
	/// Indicates that a response from the user is required, typically a password.
	Q_PROPERTY(bool isResponseRequired READ default NOTIFY isResponseRequiredChanged BINDABLE isResponseRequired);
	/// This message is used to prompt the user for required input.
	Q_PROPERTY(QString inputPrompt READ default NOTIFY inputPromptChanged BINDABLE inputPrompt);
	/// Indicates whether the user's response should be visible.
	Q_PROPERTY(bool responseVisible READ default NOTIFY responseVisibleChanged BINDABLE responseVisible);
	/// An additional message to present to the user.
	Q_PROPERTY(QString supplementaryMessage READ default NOTIFY supplementaryMessageChanged BINDABLE supplementaryMessage);
	/// Indicates whether the supplementary message is an error.
	Q_PROPERTY(bool supplementaryIsError READ default NOTIFY supplementaryIsErrorChanged BINDABLE supplementaryIsError);
	/// Has the authentication request been completed.
	Q_PROPERTY(bool isCompleted READ default NOTIFY isCompletedChanged BINDABLE isCompleted);
	/// Indicates whether the authentication request was successful.
	Q_PROPERTY(bool isSuccessful READ default NOTIFY isSuccessfulChanged BINDABLE isSuccessful);
	/// Indicates whether the current authentication request was cancelled.
	Q_PROPERTY(bool isCancelled READ default NOTIFY isCancelledChanged BINDABLE isCancelled);
	/// Indicates whether an authentication attempt has failed at least once during this authentication flow.
	Q_PROPERTY(bool failed READ default NOTIFY failedChanged BINDABLE failed);
	// clang-format on

public:
	explicit AuthFlow(QObject* parent = nullptr): QObject(parent) {}
	~AuthFlow() override = default;

	/// Submit a response to a request that was previously emitted. Typically the password.
	Q_INVOKABLE void submit(const QString& value);
	/// Cancel the ongoing authentication request from the user side.
	Q_INVOKABLE void cancelAuthenticationRequest();

	[[nodiscard]] static QString message() { return {}; }
	[[nodiscard]] static QString iconName() { return {}; }
	[[nodiscard]] static QString actionId() { return {}; }
	[[nodiscard]] static QString cookie() { return {}; }
	[[nodiscard]] static QList<Identity*> identities() { return {}; }

	[[nodiscard]] QBindable<Identity*> selectedIdentity() { return &this->bSelectedIdentity; }
	void setSelectedIdentity(Identity* identity);

	[[nodiscard]] QBindable<bool> isResponseRequired() { return &this->bIsResponseRequired; }
	[[nodiscard]] QBindable<QString> inputPrompt() { return &this->bInputPrompt; }
	[[nodiscard]] QBindable<bool> responseVisible() { return &this->bResponseVisible; }
	[[nodiscard]] QBindable<QString> supplementaryMessage() { return &this->bSupplementaryMessage; }
	[[nodiscard]] QBindable<bool> supplementaryIsError() { return &this->bSupplementaryIsError; }
	[[nodiscard]] QBindable<bool> isCompleted() { return &this->bIsCompleted; }
	[[nodiscard]] QBindable<bool> isSuccessful() { return &this->bIsSuccessful; }
	[[nodiscard]] QBindable<bool> isCancelled() { return &this->bIsCancelled; }
	[[nodiscard]] QBindable<bool> failed() { return &this->bFailed; }

signals:
	/// Emitted whenever an authentication request completes successfully.
	void authenticationSucceeded();
	/// Emitted whenever an authentication request completes unsuccessfully.
	void authenticationFailed();
	/// Emitted when an ongoing authentication request is cancelled by the PolKit daemon.
	void authenticationRequestCancelled();

	void selectedIdentityChanged();
	void isResponseRequiredChanged();
	void inputPromptChanged();
	void responseVisibleChanged();
	void supplementaryMessageChanged();
	void supplementaryIsErrorChanged();
	void isCompletedChanged();
	void isSuccessfulChanged();
	void isCancelledChanged();
	void failedChanged();

private:
	// clang-format off
	Q_OBJECT_BINDABLE_PROPERTY(AuthFlow, Identity*, bSelectedIdentity, &AuthFlow::selectedIdentityChanged);
	Q_OBJECT_BINDABLE_PROPERTY(AuthFlow, bool, bIsResponseRequired, &AuthFlow::isResponseRequiredChanged);
	Q_OBJECT_BINDABLE_PROPERTY(AuthFlow, QString, bInputPrompt, &AuthFlow::inputPromptChanged);
	Q_OBJECT_BINDABLE_PROPERTY(AuthFlow, bool, bResponseVisible, &AuthFlow::responseVisibleChanged);
	Q_OBJECT_BINDABLE_PROPERTY(AuthFlow, QString, bSupplementaryMessage, &AuthFlow::supplementaryMessageChanged);
	Q_OBJECT_BINDABLE_PROPERTY(AuthFlow, bool, bSupplementaryIsError, &AuthFlow::supplementaryIsErrorChanged);
	Q_OBJECT_BINDABLE_PROPERTY(AuthFlow, bool, bIsCompleted, &AuthFlow::isCompletedChanged);
	Q_OBJECT_BINDABLE_PROPERTY(AuthFlow, bool, bIsSuccessful, &AuthFlow::isSuccessfulChanged);
	Q_OBJECT_BINDABLE_PROPERTY(AuthFlow, bool, bIsCancelled, &AuthFlow::isCancelledChanged);
	Q_OBJECT_BINDABLE_PROPERTY(AuthFlow, bool, bFailed, &AuthFlow::failedChanged);
	// clang-format on
};

///! Contains interface to instantiate a PolKit agent listener.
/// On macOS there is no polkit daemon, so the agent never registers:
/// @@isRegistered and @@isActive stay false and @@flow stays null.
class PolkitAgent: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	Q_DISABLE_COPY_MOVE(PolkitAgent);

	// clang-format off
	/// The D-Bus path that this agent listener will use.
	///
	/// If not set, a default of /org/quickshell/Polkit will be used.
	Q_PROPERTY(QString path READ path WRITE setPath);
	/// Indicates whether the agent registered successfully and is in use.
	Q_PROPERTY(bool isRegistered READ default NOTIFY isRegisteredChanged BINDABLE isRegistered);
	/// Indicates an ongoing authentication request.
	Q_PROPERTY(bool isActive READ default NOTIFY isActiveChanged BINDABLE isActive);
	/// The current authentication state if an authentication request is active.
	///
	/// Null when no authentication request is active.
	Q_PROPERTY(qs::mac::polkit::AuthFlow* flow READ default NOTIFY flowChanged BINDABLE flow);
	// clang-format on

public:
	explicit PolkitAgent(QObject* parent = nullptr);
	~PolkitAgent() override = default;

	[[nodiscard]] QString path() const { return this->mPath; }
	void setPath(const QString& path) { this->mPath = path; }

	[[nodiscard]] QBindable<AuthFlow*> flow() { return &this->bFlow; }
	[[nodiscard]] QBindable<bool> isActive() { return &this->bIsActive; }
	[[nodiscard]] QBindable<bool> isRegistered() { return &this->bIsRegistered; }

signals:
	/// Emitted when an application makes a request that requires authentication.
	void authenticationRequestStarted();

	void isRegisteredChanged();
	void isActiveChanged();
	void flowChanged();

private:
	QString mPath = "";

	// clang-format off
	Q_OBJECT_BINDABLE_PROPERTY(PolkitAgent, AuthFlow*, bFlow, &PolkitAgent::flowChanged);
	Q_OBJECT_BINDABLE_PROPERTY(PolkitAgent, bool, bIsActive, &PolkitAgent::isActiveChanged);
	Q_OBJECT_BINDABLE_PROPERTY(PolkitAgent, bool, bIsRegistered, &PolkitAgent::isRegisteredChanged);
	// clang-format on
};

} // namespace qs::mac::polkit
