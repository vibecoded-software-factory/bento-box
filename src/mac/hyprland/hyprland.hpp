#pragma once

#include <qdebug.h>
#include <qlist.h>
#include <qlogging.h>
#include <qobject.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>
#include <qvariant.h>

#include "../../core/doc.hpp"
#include "../../core/model.hpp"
#include "../../core/qmlscreen.hpp"
#include "../../core/region.hpp"
#include "../../core/reload.hpp"
#include "../wayland/toplevel.hpp"

// macOS stub for Quickshell.Hyprland.
//
// Shells that support multiple compositors (DankMaterialShell) import the
// Hyprland module unconditionally but only USE it when their compositor
// detection says the session is Hyprland. On macOS the compositor is nigiri
// (niri-shaped), so DMS drives its niri path instead and this module is never
// exercised - but the import and the type references still have to resolve for
// the QML to load. Per AGENTS.md rule 4 every type mirrors upstream's full
// property/signal/invokable surface (src/wayland/hyprland/*) and is honestly
// inert: models stay empty, pointers stay null, booleans stay false, and
// nothing ever fires - there is no Hyprland to talk to. Upstream splits the
// URI into private submodules (Quickshell.Hyprland._Ipc etc.) re-exported by
// an umbrella module; this stub registers everything flat under
// Quickshell.Hyprland directly, which resolves identically for QML consumers.
// The niri integration proper is `Quickshell.Nigiri`.
namespace qs::mac::hyprland {

class HyprlandWorkspace;
class HyprlandMonitor;
class HyprlandToplevel;

} // namespace qs::mac::hyprland

Q_DECLARE_OPAQUE_POINTER(qs::mac::hyprland::HyprlandWorkspace*);
Q_DECLARE_OPAQUE_POINTER(qs::mac::hyprland::HyprlandMonitor*);
Q_DECLARE_OPAQUE_POINTER(qs::mac::hyprland::HyprlandToplevel*);

namespace qs::mac::hyprland {

///! Live Hyprland IPC event.
/// Live Hyprland IPC event. Holding this object after the
/// signal handler exits is undefined as the event instance
/// is reused.
///
/// Emitted by @@Hyprland.rawEvent(s). On macOS no event socket exists, so no
/// event is ever emitted and no instance of this type is ever created.
class HyprlandIpcEvent: public QObject {
	Q_OBJECT;
	/// The name of the event.
	///
	/// See [Hyprland Wiki: IPC](https://wiki.hyprland.org/IPC/) for a list of events.
	Q_PROPERTY(QString name READ nameStr CONSTANT);
	/// The unparsed data of the event.
	Q_PROPERTY(QString data READ dataStr CONSTANT);
	QML_NAMED_ELEMENT(HyprlandEvent);
	QML_UNCREATABLE("HyprlandIpcEvents cannot be created.");

public:
	explicit HyprlandIpcEvent(QObject* parent = nullptr): QObject(parent) {}

	/// Parse this event with a known number of arguments.
	///
	/// Argument count is required as some events can contain commas
	/// in the last argument, which can be ignored as long as the count is known.
	Q_INVOKABLE [[nodiscard]] QVector<QString> parse(qint32 argumentCount) const;

	[[nodiscard]] QString nameStr() const { return {}; }
	[[nodiscard]] QString dataStr() const { return {}; }
};

///! Hyprland workspace.
/// Inert on macOS: no workspace is ever created (see the module note).
class HyprlandWorkspace: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(qint32 id READ id NOTIFY idChanged);
	Q_PROPERTY(QString name READ name NOTIFY nameChanged);
	/// If this workspace is currently active on its monitor. See also @@focused.
	Q_PROPERTY(bool active READ active NOTIFY activeChanged);
	/// If this workspace is currently active on a monitor and that monitor is currently
	/// focused. See also @@active.
	Q_PROPERTY(bool focused READ focused NOTIFY focusedChanged);
	/// If this workspace has a window that is urgent.
	Q_PROPERTY(bool urgent READ urgent NOTIFY urgentChanged);
	/// If this workspace currently has a fullscreen client.
	Q_PROPERTY(bool hasFullscreen READ hasFullscreen NOTIFY hasFullscreenChanged);
	/// Last json returned for this workspace, as a javascript object.
	Q_PROPERTY(QVariantMap lastIpcObject READ lastIpcObject NOTIFY lastIpcObjectChanged);
	Q_PROPERTY(qs::mac::hyprland::HyprlandMonitor* monitor READ monitor NOTIFY monitorChanged);
	/// List of toplevels on this workspace.
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::hyprland::HyprlandToplevel>*);
	Q_PROPERTY(UntypedObjectModel* toplevels READ toplevels CONSTANT);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("HyprlandWorkspaces must be retrieved from the HyprlandIpc object.");

public:
	explicit HyprlandWorkspace(QObject* parent = nullptr): QObject(parent) {}

	/// Activate the workspace.
	///
	/// > [!NOTE] This is equivalent to running
	/// > ```qml
	/// > HyprlandIpc.dispatch(`workspace ${workspace.name}`);
	/// > ```
	Q_INVOKABLE void activate();

	// Upstream defaults: id -1 until reported (workspace.hpp:100); everything
	// else default-constructed. Nothing is ever reported on macOS.
	[[nodiscard]] static qint32 id() { return -1; }
	[[nodiscard]] static QString name() { return {}; }
	[[nodiscard]] static bool active() { return false; }
	[[nodiscard]] static bool focused() { return false; }
	[[nodiscard]] static bool urgent() { return false; }
	[[nodiscard]] static bool hasFullscreen() { return false; }
	[[nodiscard]] static QVariantMap lastIpcObject() { return {}; }
	[[nodiscard]] static HyprlandMonitor* monitor() { return nullptr; }
	[[nodiscard]] ObjectModel<HyprlandToplevel>* toplevels() { return &this->mToplevels; }

signals:
	void idChanged();
	void nameChanged();
	void activeChanged();
	void focusedChanged();
	void urgentChanged();
	void hasFullscreenChanged();
	void lastIpcObjectChanged();
	void monitorChanged();

private:
	ObjectModel<HyprlandToplevel> mToplevels {this};
};

///! Hyprland monitor.
/// Inert on macOS: no monitor is ever created (see the module note).
class HyprlandMonitor: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(qint32 id READ id NOTIFY idChanged);
	Q_PROPERTY(QString name READ name NOTIFY nameChanged);
	Q_PROPERTY(QString description READ description NOTIFY descriptionChanged);
	Q_PROPERTY(qint32 x READ x NOTIFY xChanged);
	Q_PROPERTY(qint32 y READ y NOTIFY yChanged);
	Q_PROPERTY(qint32 width READ width NOTIFY widthChanged);
	Q_PROPERTY(qint32 height READ height NOTIFY heightChanged);
	Q_PROPERTY(qreal scale READ scale NOTIFY scaleChanged);
	/// Last json returned for this monitor, as a javascript object.
	Q_PROPERTY(QVariantMap lastIpcObject READ lastIpcObject NOTIFY lastIpcObjectChanged);
	/// The currently active workspace on this monitor. May be null.
	Q_PROPERTY(qs::mac::hyprland::HyprlandWorkspace* activeWorkspace READ activeWorkspace NOTIFY activeWorkspaceChanged);
	/// If the monitor is currently focused.
	Q_PROPERTY(bool focused READ focused NOTIFY focusedChanged);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("HyprlandMonitors must be retrieved from the HyprlandIpc object.");

public:
	explicit HyprlandMonitor(QObject* parent = nullptr): QObject(parent) {}

	// Upstream defaults: id -1 until reported (monitor.hpp:89); everything
	// else default-constructed. Nothing is ever reported on macOS.
	[[nodiscard]] static qint32 id() { return -1; }
	[[nodiscard]] static QString name() { return {}; }
	[[nodiscard]] static QString description() { return {}; }
	[[nodiscard]] static qint32 x() { return 0; }
	[[nodiscard]] static qint32 y() { return 0; }
	[[nodiscard]] static qint32 width() { return 0; }
	[[nodiscard]] static qint32 height() { return 0; }
	[[nodiscard]] static qreal scale() { return 0.0; }
	[[nodiscard]] static QVariantMap lastIpcObject() { return {}; }
	[[nodiscard]] static HyprlandWorkspace* activeWorkspace() { return nullptr; }
	[[nodiscard]] static bool focused() { return false; }

signals:
	void idChanged();
	void nameChanged();
	void descriptionChanged();
	void xChanged();
	void yChanged();
	void widthChanged();
	void heightChanged();
	void scaleChanged();
	void lastIpcObjectChanged();
	void activeWorkspaceChanged();
	void focusedChanged();
};

///! Hyprland Toplevel
/// Represents a window as Hyprland exposes it.
/// Can also be used as an attached object of a @@Quickshell.Wayland.Toplevel,
/// to resolve a handle to an Hyprland toplevel.
///
/// Inert on macOS: no Hyprland address is ever reported, so attached
/// instances keep null handles forever (see the module note).
class HyprlandToplevel: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_UNCREATABLE("");
	QML_ATTACHED(HyprlandToplevel);
	// clang-format off
	/// Hexadecimal Hyprland window address. Will be an empty string until
	/// the address is reported.
	Q_PROPERTY(QString address READ addressStr NOTIFY addressChanged);
	/// The toplevel handle, exposing the Hyprland toplevel.
	/// Will be null until the address is reported
	Q_PROPERTY(qs::mac::hyprland::HyprlandToplevel* handle READ hyprlandHandle NOTIFY hyprlandHandleChanged);
	/// The wayland toplevel handle. Will be null until the address is reported
	Q_PROPERTY(qs::mac::wayland::Toplevel* wayland READ waylandHandle NOTIFY waylandHandleChanged);
	/// The title of the toplevel
	Q_PROPERTY(QString title READ title NOTIFY titleChanged);
	/// Whether the toplevel is active or not
	Q_PROPERTY(bool activated READ activated NOTIFY activatedChanged);
	/// Whether the client is urgent or not
	Q_PROPERTY(bool urgent READ urgent NOTIFY urgentChanged);
	/// Last json returned for this toplevel, as a javascript object.
	Q_PROPERTY(QVariantMap lastIpcObject READ lastIpcObject NOTIFY lastIpcObjectChanged);
	/// The current workspace of the toplevel (might be null)
	Q_PROPERTY(qs::mac::hyprland::HyprlandWorkspace* workspace READ workspace NOTIFY workspaceChanged);
	/// The current monitor of the toplevel (might be null)
	Q_PROPERTY(qs::mac::hyprland::HyprlandMonitor* monitor READ monitor NOTIFY monitorChanged);
	// clang-format on

public:
	explicit HyprlandToplevel(QObject* parent = nullptr): QObject(parent) {}

	static HyprlandToplevel* qmlAttachedProperties(QObject* object);

	// Upstream: address 0 until reported, rendered in hex - so "0", not ""
	// (hyprland_toplevel.hpp:64,105 - the doc says empty but the code says
	// "0"; mirrored bug-for-bug). Nothing is ever reported on macOS.
	[[nodiscard]] static QString addressStr() { return QString::number(0, 16); }
	[[nodiscard]] static HyprlandToplevel* hyprlandHandle() { return nullptr; }
	[[nodiscard]] static qs::mac::wayland::Toplevel* waylandHandle() { return nullptr; }
	[[nodiscard]] static QString title() { return {}; }
	[[nodiscard]] static bool activated() { return false; }
	[[nodiscard]] static bool urgent() { return false; }
	[[nodiscard]] static QVariantMap lastIpcObject() { return {}; }
	[[nodiscard]] static HyprlandWorkspace* workspace() { return nullptr; }
	[[nodiscard]] static HyprlandMonitor* monitor() { return nullptr; }

signals:
	void addressChanged();
	QSDOC_HIDE void waylandHandleChanged();
	QSDOC_HIDE void hyprlandHandleChanged();

	void titleChanged();
	void activatedChanged();
	void urgentChanged();
	void workspaceChanged();
	void monitorChanged();
	void lastIpcObjectChanged();
};

///! Hyprland focus grab (for dismissable popups). Inert stub - the shell falls
/// back to other dismissal on macOS.
class HyprlandFocusGrab: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged);
	Q_PROPERTY(QList<QObject*> windows READ windows WRITE setWindows NOTIFY windowsChanged);
	// clang-format on
	QML_ELEMENT;

public:
	explicit HyprlandFocusGrab(QObject* parent = nullptr): QObject(parent) {}
	// Upstream: setting true REQUESTS the grab, but the property "will not
	// change to true until the grab begins, which requires at least one
	// visible window" (focus_grab/qml.hpp:61-68). No grab can ever begin on
	// macOS (no hyprland), so active always reads false and the write is an
	// honest no-op - the old stub stored the write, reporting a grab that
	// never existed.
	[[nodiscard]] static bool active() { return false; }
	void setActive(bool active) {
		if (active) {
			qWarning() << "HyprlandFocusGrab: no grab can begin on macOS; active stays false";
		}
	}
	[[nodiscard]] QList<QObject*> windows() const { return this->mWindows; }
	void setWindows(const QList<QObject*>& windows) {
		this->mWindows = windows;
		emit this->windowsChanged();
	}

signals:
	void activeChanged();
	void windowsChanged();
	void cleared();

private:
	QList<QObject*> mWindows;
};

///! Hyprland global shortcut.
/// Global shortcut implemented with [hyprland_global_shortcuts_v1].
///
/// Inert on macOS: the protocol does not exist here, so the shortcut never
/// registers and never fires (see the module note).
///
/// [hyprland_global_shortcuts_v1]: https://github.com/hyprwm/hyprland-protocols/blob/main/protocols/hyprland-global-shortcuts-v1.xml
class GlobalShortcut: public PostReloadHook {
	Q_OBJECT;
	// clang-format off
	/// If the keybind is currently pressed.
	Q_PROPERTY(bool pressed READ isPressed NOTIFY pressedChanged);
	/// The appid of the shortcut. Defaults to `quickshell`.
	/// You cannot change this at runtime.
	Q_PROPERTY(QString appid READ appid WRITE setAppid NOTIFY appidChanged);
	/// The name of the shortcut.
	/// You cannot change this at runtime.
	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged);
	/// The description of the shortcut that appears in `hyprctl globalshortcuts`.
	/// You cannot change this at runtime.
	Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged);
	/// Have not seen this used ever, but included for completeness. Safe to ignore.
	Q_PROPERTY(QString triggerDescription READ triggerDescription WRITE setTriggerDescription NOTIFY triggerDescriptionChanged);
	// clang-format on
	QML_ELEMENT;

public:
	explicit GlobalShortcut(QObject* parent = nullptr): PostReloadHook(parent) {}

	// Upstream registers the wayland shortcut here; there is nothing to
	// register on macOS, so this warns once and pressed stays false.
	void onPostReload() override;

	[[nodiscard]] static bool isPressed() { return false; }

	[[nodiscard]] QString appid() const { return this->mAppid; }
	void setAppid(QString appid);

	[[nodiscard]] QString name() const { return this->mName; }
	void setName(QString name);

	[[nodiscard]] QString description() const { return this->mDescription; }
	void setDescription(QString description);

	[[nodiscard]] QString triggerDescription() const { return this->mTriggerDescription; }
	void setTriggerDescription(QString triggerDescription);

signals:
	/// Fired when the keybind is pressed.
	void pressed();
	/// Fired when the keybind is released.
	void released();

	void pressedChanged();
	void appidChanged();
	void nameChanged();
	void descriptionChanged();
	void triggerDescriptionChanged();

private:
	// Upstream default appid "quickshell" (global_shortcuts/qml.hpp:100).
	QString mAppid = "quickshell";
	QString mName;
	QString mDescription;
	QString mTriggerDescription;
};

///! Hyprland specific QsWindow properties.
/// Allows setting hyprland specific window properties on a @@Quickshell.QsWindow or subclass,
/// as an attached object.
///
/// Inert on macOS: values are stored so bindings hold, but there is no
/// hyprland-surface-v1 to forward them to (see the module note).
class HyprlandWindow: public QObject {
	Q_OBJECT;
	// clang-format off
	/// A multiplier for the window's overall opacity, ranging from 1.0 to 0.0.
	///
	/// Default: 1.0
	Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity NOTIFY opacityChanged);
	/// A hint to the compositor that only certain regions of the surface should be rendered.
	Q_PROPERTY(PendingRegion* visibleMask READ visibleMask WRITE setVisibleMask NOTIFY visibleMaskChanged);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("HyprlandWindow can only be used as an attached object.");
	QML_ATTACHED(HyprlandWindow);

public:
	explicit HyprlandWindow(QObject* parent = nullptr): QObject(parent) {}

	static HyprlandWindow* qmlAttachedProperties(QObject* object);

	[[nodiscard]] qreal opacity() const { return this->mOpacity; }
	void setOpacity(qreal opacity);

	[[nodiscard]] PendingRegion* visibleMask() const { return this->mVisibleMask; }
	void setVisibleMask(PendingRegion* mask);

signals:
	void opacityChanged();
	void visibleMaskChanged();

private:
	qreal mOpacity = 1.0;
	PendingRegion* mVisibleMask = nullptr;
};

///! Access to Hyprland - inert on macOS, where the compositor is nigiri.
class Hyprland: public QObject {
	Q_OBJECT;
	// clang-format off
	/// True if Hyprland is running in lua mode. Dispatcher syntax changes when using lua.
	///
	/// This property will be false until the Hyprland module is initialized.
	/// (On macOS it is false forever - there is no Hyprland to initialize.)
	Q_PROPERTY(bool usingLua READ usingLua NOTIFY usingLuaChanged);
	/// Path to the request socket (.socket.sock). Empty on macOS, like
	/// upstream when $HYPRLAND_INSTANCE_SIGNATURE is unset.
	Q_PROPERTY(QString requestSocketPath READ requestSocketPath CONSTANT);
	/// Path to the event socket (.socket2.sock). Empty on macOS, like
	/// upstream when $HYPRLAND_INSTANCE_SIGNATURE is unset.
	Q_PROPERTY(QString eventSocketPath READ eventSocketPath CONSTANT);
	/// The currently focused hyprland monitor. May be null.
	Q_PROPERTY(qs::mac::hyprland::HyprlandMonitor* focusedMonitor READ focusedMonitor NOTIFY focusedMonitorChanged);
	/// The currently focused hyprland workspace. May be null.
	Q_PROPERTY(qs::mac::hyprland::HyprlandWorkspace* focusedWorkspace READ focusedWorkspace NOTIFY focusedWorkspaceChanged);
	/// Currently active toplevel (might be null)
	Q_PROPERTY(qs::mac::hyprland::HyprlandToplevel* activeToplevel READ activeToplevel NOTIFY activeToplevelChanged);
	/// All hyprland monitors.
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::hyprland::HyprlandMonitor>*);
	Q_PROPERTY(UntypedObjectModel* monitors READ monitors CONSTANT);
	/// All hyprland workspaces, sorted by id.
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::hyprland::HyprlandWorkspace>*);
	Q_PROPERTY(UntypedObjectModel* workspaces READ workspaces CONSTANT);
	/// All hyprland toplevels
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::hyprland::HyprlandToplevel>*);
	Q_PROPERTY(UntypedObjectModel* toplevels READ toplevels CONSTANT);
	// clang-format on
	QML_NAMED_ELEMENT(Hyprland);
	QML_SINGLETON;

public:
	explicit Hyprland(QObject* parent = nullptr): QObject(parent) {}

	/// Execute a hyprland [dispatcher](https://wiki.hyprland.org/Configuring/Dispatchers).
	Q_INVOKABLE static void dispatch(const QString& request);

	/// Get the HyprlandMonitor object that corresponds to a quickshell screen.
	Q_INVOKABLE static HyprlandMonitor* monitorFor(QuickshellScreenInfo* screen);

	/// Refresh monitor information.
	Q_INVOKABLE static void refreshMonitors() {}

	/// Refresh workspace information.
	Q_INVOKABLE static void refreshWorkspaces() {}

	/// Refresh toplevel information.
	Q_INVOKABLE static void refreshToplevels() {}

	[[nodiscard]] static bool usingLua() { return false; }
	[[nodiscard]] static QString requestSocketPath() { return {}; }
	[[nodiscard]] static QString eventSocketPath() { return {}; }
	[[nodiscard]] static HyprlandMonitor* focusedMonitor() { return nullptr; }
	[[nodiscard]] static HyprlandWorkspace* focusedWorkspace() { return nullptr; }
	[[nodiscard]] static HyprlandToplevel* activeToplevel() { return nullptr; }
	[[nodiscard]] ObjectModel<HyprlandMonitor>* monitors() { return &this->mMonitors; }
	[[nodiscard]] ObjectModel<HyprlandWorkspace>* workspaces() { return &this->mWorkspaces; }
	[[nodiscard]] ObjectModel<HyprlandToplevel>* toplevels() { return &this->mToplevels; }

signals:
	/// Emitted for every event that comes in through the hyprland event socket (socket2).
	/// Never emitted on macOS - no event socket exists.
	void rawEvent(qs::mac::hyprland::HyprlandIpcEvent* event);

	void usingLuaChanged();
	void focusedMonitorChanged();
	void focusedWorkspaceChanged();
	void activeToplevelChanged();

private:
	ObjectModel<HyprlandMonitor> mMonitors {this};
	ObjectModel<HyprlandWorkspace> mWorkspaces {this};
	ObjectModel<HyprlandToplevel> mToplevels {this};
};

} // namespace qs::mac::hyprland
