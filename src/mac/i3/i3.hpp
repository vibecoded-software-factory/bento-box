#pragma once

#include <qlist.h>
#include <qobject.h>
#include <qqmlintegration.h>
#include <qstring.h>
#include <qtmetamacros.h>
#include <qtypes.h>
#include <qvariant.h>

#include "../../core/doc.hpp"
#include "../../core/model.hpp"
#include "../../core/qmlscreen.hpp"
#include "../../core/reload.hpp"

// macOS stub for Quickshell.I3 (i3/Sway IPC).
//
// Multi-compositor shells (DankMaterialShell) import this module
// unconditionally but only USE it when their compositor detection says the
// session is i3/Sway. On macOS the compositor is nigiri, so DMS drives its
// niri path instead - but the import and every type reference still have to
// resolve for the QML to load. Per AGENTS.md rule 4 every type mirrors
// upstream's full property/signal/invokable surface (src/x11/i3/ipc/*) and is
// honestly inert: models stay empty, pointers stay null, and nothing ever
// fires - there is no i3 socket to talk to. The niri integration proper is
// `Quickshell.Nigiri`.
namespace qs::mac::i3 {

class I3Workspace;
class I3Monitor;

} // namespace qs::mac::i3

Q_DECLARE_OPAQUE_POINTER(qs::mac::i3::I3Workspace*);
Q_DECLARE_OPAQUE_POINTER(qs::mac::i3::I3Monitor*);

namespace qs::mac::i3 {

///! I3/Sway IPC Events
/// Emitted by @@I3.rawEvent(s). On macOS no i3 socket exists, so no event is
/// ever emitted and no instance of this type is ever created.
class I3IpcEvent: public QObject {
	Q_OBJECT;

	Q_PROPERTY(QString type READ type CONSTANT);
	Q_PROPERTY(QString data READ data CONSTANT);

	QML_NAMED_ELEMENT(I3Event);
	QML_UNCREATABLE("I3IpcEvents cannot be created.");

public:
	explicit I3IpcEvent(QObject* parent = nullptr): QObject(parent) {}

	// Upstream: type is eventToString(code) - "unknown" for the default code -
	// and data renders the (here always null) JSON document, which is empty.
	[[nodiscard]] static QString type() { return QStringLiteral("unknown"); }
	[[nodiscard]] static QString data() { return {}; }
};

///! I3/Sway workspaces
/// Inert on macOS: no workspace is ever created (see the module note).
class I3Workspace: public QObject {
	Q_OBJECT;
	// clang-format off
	/// The ID of this workspace, it is unique for i3/Sway launch
	Q_PROPERTY(qint32 id READ id NOTIFY idChanged);
	/// The name of this workspace
	Q_PROPERTY(QString name READ name NOTIFY nameChanged);
	/// The number of this workspace
	Q_PROPERTY(qint32 number READ number NOTIFY numberChanged);
	/// Deprecated: use @@number
	Q_PROPERTY(qint32 num READ number NOTIFY numberChanged);
	/// If a window in this workspace has an urgent notification
	Q_PROPERTY(bool urgent READ urgent NOTIFY urgentChanged);
	/// If this workspace is currently active on its monitor. See also @@focused.
	Q_PROPERTY(bool active READ active NOTIFY activeChanged);
	/// If this workspace is currently active on a monitor and that monitor is currently
	/// focused. See also @@active.
	Q_PROPERTY(bool focused READ focused NOTIFY focusedChanged);
	/// The monitor this workspace is being displayed on
	Q_PROPERTY(qs::mac::i3::I3Monitor* monitor READ monitor NOTIFY monitorChanged);
	/// Last JSON returned for this workspace, as a JavaScript object.
	Q_PROPERTY(QVariantMap lastIpcObject READ lastIpcObject NOTIFY lastIpcObjectChanged);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("I3Workspaces must be retrieved from the I3 object.");

public:
	explicit I3Workspace(QObject* parent = nullptr): QObject(parent) {}

	/// Activate the workspace.
	///
	/// > [!NOTE] This is equivalent to running
	/// > ```qml
	/// > I3.dispatch(`workspace number ${workspace.number}`);
	/// > ```
	Q_INVOKABLE void activate();

	// Upstream defaults: id/number -1 until reported (workspace.hpp:86-88);
	// everything else default-constructed. Nothing is ever reported on macOS.
	[[nodiscard]] static qint32 id() { return -1; }
	[[nodiscard]] static QString name() { return {}; }
	[[nodiscard]] static qint32 number() { return -1; }
	[[nodiscard]] static bool urgent() { return false; }
	[[nodiscard]] static bool active() { return false; }
	[[nodiscard]] static bool focused() { return false; }
	[[nodiscard]] static I3Monitor* monitor() { return nullptr; }
	[[nodiscard]] static QVariantMap lastIpcObject() { return {}; }

signals:
	void idChanged();
	void nameChanged();
	void urgentChanged();
	void activeChanged();
	void focusedChanged();
	void numberChanged();
	void monitorChanged();
	void lastIpcObjectChanged();
};

///! I3/Sway monitors
/// Inert on macOS: no monitor is ever created (see the module note).
class I3Monitor: public QObject {
	Q_OBJECT;
	// clang-format off
	/// The ID of this monitor
	Q_PROPERTY(qint32 id READ id NOTIFY idChanged);
	/// The name of this monitor
	Q_PROPERTY(QString name READ name NOTIFY nameChanged);
	/// Whether this monitor is turned on or not
	Q_PROPERTY(bool power READ power NOTIFY powerChanged);
	/// The currently active workspace on this monitor, May be null.
	Q_PROPERTY(qs::mac::i3::I3Workspace* activeWorkspace READ activeWorkspace NOTIFY activeWorkspaceChanged);
	/// Deprecated: See @@activeWorkspace.
	Q_PROPERTY(qs::mac::i3::I3Workspace* focusedWorkspace READ activeWorkspace NOTIFY activeWorkspaceChanged);
	/// The X coordinate of this monitor inside the monitor layout
	Q_PROPERTY(qint32 x READ x NOTIFY xChanged);
	/// The Y coordinate of this monitor inside the monitor layout
	Q_PROPERTY(qint32 y READ y NOTIFY yChanged);
	/// The width in pixels of this monitor
	Q_PROPERTY(qint32 width READ width NOTIFY widthChanged);
	/// The height in pixels of this monitor
	Q_PROPERTY(qint32 height READ height NOTIFY heightChanged);
	/// The scaling factor of this monitor, 1 means it runs at native resolution
	Q_PROPERTY(qreal scale READ scale NOTIFY scaleChanged);
	/// Whether this monitor is currently in focus
	Q_PROPERTY(bool focused READ focused NOTIFY focusedChanged);
	/// Last JSON returned for this monitor, as a JavaScript object.
	Q_PROPERTY(QVariantMap lastIpcObject READ lastIpcObject NOTIFY lastIpcObjectChanged);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("I3Monitors must be retrieved from the I3IpcController object.");

public:
	explicit I3Monitor(QObject* parent = nullptr): QObject(parent) {}

	// Upstream defaults: id -1, scale 1 (monitor.hpp:91,98); everything else
	// default-constructed. Nothing is ever reported on macOS.
	[[nodiscard]] static qint32 id() { return -1; }
	[[nodiscard]] static QString name() { return {}; }
	[[nodiscard]] static bool power() { return false; }
	[[nodiscard]] static I3Workspace* activeWorkspace() { return nullptr; }
	[[nodiscard]] static qint32 x() { return 0; }
	[[nodiscard]] static qint32 y() { return 0; }
	[[nodiscard]] static qint32 width() { return 0; }
	[[nodiscard]] static qint32 height() { return 0; }
	[[nodiscard]] static qreal scale() { return 1; }
	[[nodiscard]] static bool focused() { return false; }
	[[nodiscard]] static QVariantMap lastIpcObject() { return {}; }

signals:
	void idChanged();
	void nameChanged();
	void powerChanged();
	void activeWorkspaceChanged();
	void xChanged();
	void yChanged();
	void widthChanged();
	void heightChanged();
	void scaleChanged();
	void lastIpcObjectChanged();
	void focusedChanged();
};

///! I3/Sway IPC integration
/// Inert on macOS, where the compositor is nigiri (see the module note).
class I3: public QObject {
	Q_OBJECT;
	// clang-format off
	/// Path to the I3 socket. Empty on macOS, like upstream when $I3SOCK and
	/// $SWAYSOCK are unset.
	Q_PROPERTY(QString socketPath READ socketPath CONSTANT);

	Q_PROPERTY(qs::mac::i3::I3Workspace* focusedWorkspace READ focusedWorkspace NOTIFY focusedWorkspaceChanged);
	Q_PROPERTY(qs::mac::i3::I3Monitor* focusedMonitor READ focusedMonitor NOTIFY focusedMonitorChanged);
	/// All I3 monitors.
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::i3::I3Monitor>*);
	Q_PROPERTY(UntypedObjectModel* monitors READ monitors CONSTANT);
	/// All I3 workspaces.
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::i3::I3Workspace>*);
	Q_PROPERTY(UntypedObjectModel* workspaces READ workspaces CONSTANT);
	// clang-format on
	QML_NAMED_ELEMENT(I3);
	QML_SINGLETON;

public:
	explicit I3(QObject* parent = nullptr): QObject(parent) {}

	/// Execute an [I3/Sway command](https://i3wm.org/docs/userguide.html#list_of_commands)
	Q_INVOKABLE static void dispatch(const QString& request);

	/// Refresh monitor information.
	Q_INVOKABLE static void refreshMonitors() {}

	/// Refresh workspace information.
	Q_INVOKABLE static void refreshWorkspaces() {}

	/// Find an I3Workspace using its name, returns null if the workspace doesn't exist.
	Q_INVOKABLE static I3Workspace* findWorkspaceByName(const QString& name);

	/// Find an I3Monitor using its name, returns null if the monitor doesn't exist.
	Q_INVOKABLE static I3Monitor* findMonitorByName(const QString& name);

	/// Return the i3/Sway monitor associated with `screen`
	Q_INVOKABLE static I3Monitor* monitorFor(QuickshellScreenInfo* screen);

	[[nodiscard]] static QString socketPath() { return {}; }
	[[nodiscard]] static I3Workspace* focusedWorkspace() { return nullptr; }
	[[nodiscard]] static I3Monitor* focusedMonitor() { return nullptr; }
	[[nodiscard]] ObjectModel<I3Monitor>* monitors() { return &this->mMonitors; }
	[[nodiscard]] ObjectModel<I3Workspace>* workspaces() { return &this->mWorkspaces; }

signals:
	/// Never emitted on macOS - no i3 socket exists.
	void rawEvent(qs::mac::i3::I3IpcEvent* event);
	void connected();
	void focusedWorkspaceChanged();
	void focusedMonitorChanged();

private:
	ObjectModel<I3Monitor> mMonitors {this};
	ObjectModel<I3Workspace> mWorkspaces {this};
};

///! I3/Sway IPC event listener
/// #### Example
/// ```qml
/// I3IpcListener {
///   subscriptions: ["input"]
///   onIpcEvent: function (event) {
///     handleInputEvent(event.data)
///   }
/// }
/// ```
///
/// Inert on macOS: there is no i3 socket, so the listener never connects and
/// @@ipcEvent never fires (see the module note).
class I3IpcListener: public PostReloadHook {
	Q_OBJECT;
	// clang-format off
	/// List of [I3/Sway events](https://man.archlinux.org/man/sway-ipc.7.en#EVENTS) to subscribe to.
	Q_PROPERTY(QList<QString> subscriptions READ subscriptions WRITE setSubscriptions NOTIFY subscriptionsChanged);
	// clang-format on
	QML_ELEMENT;

public:
	explicit I3IpcListener(QObject* parent = nullptr): PostReloadHook(parent) {}

	// Upstream connects and subscribes here; there is no i3 socket on macOS,
	// so this warns once and no event ever fires.
	void onPostReload() override;

	[[nodiscard]] QList<QString> subscriptions() const { return this->mSubscriptions; }
	void setSubscriptions(QList<QString> subscriptions);

signals:
	void ipcEvent(qs::mac::i3::I3IpcEvent* event);
	void subscriptionsChanged();

private:
	QList<QString> mSubscriptions;
};

} // namespace qs::mac::i3
