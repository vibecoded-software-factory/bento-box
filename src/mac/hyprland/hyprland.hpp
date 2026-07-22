#pragma once

#include <qlist.h>
#include <qobject.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>
#include <qvariant.h>

#include "../../core/doc.hpp"
#include "../../core/model.hpp"

// macOS stub for Quickshell.Hyprland.
//
// Shells that support multiple compositors (DankMaterialShell) import the
// Hyprland module unconditionally but only USE it when their compositor
// detection says the session is Hyprland. On macOS the compositor is nigiri
// (niri-shaped), so DMS drives its niri path instead and this module is never
// exercised - but the import and the type references still have to resolve for
// the QML to load. So the `Hyprland` singleton is inert: empty models, no-op
// dispatch. The niri integration proper is `Quickshell.Nigiri`.
namespace qs::mac::hyprland {

///! An inert Hyprland workspace (macOS uses nigiri; see Quickshell.Nigiri).
class HyprlandWorkspace: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_UNCREATABLE("Hyprland is not the compositor on macOS");

public:
	explicit HyprlandWorkspace(QObject* parent = nullptr): QObject(parent) {}
};

///! An inert Hyprland monitor.
class HyprlandMonitor: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_UNCREATABLE("Hyprland is not the compositor on macOS");

public:
	explicit HyprlandMonitor(QObject* parent = nullptr): QObject(parent) {}
};

///! An inert Hyprland toplevel.
class HyprlandToplevel: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_UNCREATABLE("Hyprland is not the compositor on macOS");

public:
	explicit HyprlandToplevel(QObject* parent = nullptr): QObject(parent) {}
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
	[[nodiscard]] bool active() const { return this->mActive; }
	void setActive(bool active) {
		if (this->mActive == active) return;
		this->mActive = active;
		emit this->activeChanged();
		if (!active) emit this->cleared();
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
	bool mActive = false;
	QList<QObject*> mWindows;
};

///! Access to Hyprland - inert on macOS, where the compositor is nigiri.
class Hyprland: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(qs::mac::hyprland::HyprlandWorkspace* focusedWorkspace READ focusedWorkspace NOTIFY focusedWorkspaceChanged);
	Q_PROPERTY(qs::mac::hyprland::HyprlandMonitor* focusedMonitor READ focusedMonitor NOTIFY focusedMonitorChanged);
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::hyprland::HyprlandWorkspace>*);
	Q_PROPERTY(UntypedObjectModel* workspaces READ workspaces CONSTANT);
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::hyprland::HyprlandMonitor>*);
	Q_PROPERTY(UntypedObjectModel* monitors READ monitors CONSTANT);
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::hyprland::HyprlandToplevel>*);
	Q_PROPERTY(UntypedObjectModel* toplevels READ toplevels CONSTANT);
	// clang-format on
	QML_NAMED_ELEMENT(Hyprland);
	QML_SINGLETON;

public:
	explicit Hyprland(QObject* parent = nullptr): QObject(parent) {}

	[[nodiscard]] HyprlandWorkspace* focusedWorkspace() const { return nullptr; }
	[[nodiscard]] HyprlandMonitor* focusedMonitor() const { return nullptr; }
	[[nodiscard]] ObjectModel<HyprlandWorkspace>* workspaces() { return &this->mWorkspaces; }
	[[nodiscard]] ObjectModel<HyprlandMonitor>* monitors() { return &this->mMonitors; }
	[[nodiscard]] ObjectModel<HyprlandToplevel>* toplevels() { return &this->mToplevels; }

	Q_INVOKABLE void dispatch(const QString& /*request*/) {}
	Q_INVOKABLE void refreshToplevels() {}
	Q_INVOKABLE void refreshWorkspaces() {}
	Q_INVOKABLE void refreshMonitors() {}
	Q_INVOKABLE QObject* monitorFor(QObject* /*screen*/) { return nullptr; }

signals:
	void focusedWorkspaceChanged();
	void focusedMonitorChanged();

private:
	ObjectModel<HyprlandWorkspace> mWorkspaces {this};
	ObjectModel<HyprlandMonitor> mMonitors {this};
	ObjectModel<HyprlandToplevel> mToplevels {this};
};

} // namespace qs::mac::hyprland
