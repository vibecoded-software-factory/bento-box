#pragma once

#include <qjsonobject.h>
#include <qobject.h>
#include <qproperty.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>
#include <qtypes.h>

namespace qs::nigiri {

class NigiriIpc;

// One window (niri's "toplevel"), mirrored from nigiri's WindowOpenedOrChanged
// events. The window-list counterpart of NigiriWorkspace: bindable source-of-
// truth properties, plus `active` derived from the singleton's focused window
// so a taskbar highlight updates automatically.
class NigiriWindow: public QObject {
	Q_OBJECT;
	// clang-format off
	/// Stable window id.
	Q_PROPERTY(qint32 id READ default NOTIFY idChanged BINDABLE bindableId);
	/// Window title.
	Q_PROPERTY(QString title READ default NOTIFY titleChanged BINDABLE bindableTitle);
	/// The owning application's bundle identifier, or empty.
	Q_PROPERTY(QString appId READ default NOTIFY appIdChanged BINDABLE bindableAppId);
	/// The owning process id.
	Q_PROPERTY(qint32 pid READ default NOTIFY pidChanged BINDABLE bindablePid);
	/// Id of the workspace this window is on.
	Q_PROPERTY(qint32 workspaceId READ default NOTIFY workspaceIdChanged BINDABLE bindableWorkspaceId);
	/// Whether the window is in the floating layer rather than tiled.
	Q_PROPERTY(bool floating READ default NOTIFY floatingChanged BINDABLE bindableFloating);
	/// Whether this is the focused window.
	Q_PROPERTY(bool active READ default NOTIFY activeChanged BINDABLE bindableActive);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("NigiriWindows are retrieved from the Nigiri singleton.");

public:
	explicit NigiriWindow(NigiriIpc* ipc);

	void updateFromJson(const QJsonObject& object);

	/// Focus this window.
	Q_INVOKABLE void activate();

	[[nodiscard]] QBindable<qint32> bindableId() { return &this->bId; }
	[[nodiscard]] QBindable<QString> bindableTitle() { return &this->bTitle; }
	[[nodiscard]] QBindable<QString> bindableAppId() { return &this->bAppId; }
	[[nodiscard]] QBindable<qint32> bindablePid() { return &this->bPid; }
	[[nodiscard]] QBindable<qint32> bindableWorkspaceId() { return &this->bWorkspaceId; }
	[[nodiscard]] QBindable<bool> bindableFloating() { return &this->bFloating; }
	[[nodiscard]] QBindable<bool> bindableActive() { return &this->bActive; }

signals:
	void idChanged();
	void titleChanged();
	void appIdChanged();
	void pidChanged();
	void workspaceIdChanged();
	void floatingChanged();
	void activeChanged();

private:
	NigiriIpc* mIpc;

	// clang-format off
	Q_OBJECT_BINDABLE_PROPERTY(NigiriWindow, qint32, bId, &NigiriWindow::idChanged);
	Q_OBJECT_BINDABLE_PROPERTY(NigiriWindow, QString, bTitle, &NigiriWindow::titleChanged);
	Q_OBJECT_BINDABLE_PROPERTY(NigiriWindow, QString, bAppId, &NigiriWindow::appIdChanged);
	Q_OBJECT_BINDABLE_PROPERTY(NigiriWindow, qint32, bPid, &NigiriWindow::pidChanged);
	Q_OBJECT_BINDABLE_PROPERTY(NigiriWindow, qint32, bWorkspaceId, &NigiriWindow::workspaceIdChanged);
	Q_OBJECT_BINDABLE_PROPERTY(NigiriWindow, bool, bFloating, &NigiriWindow::floatingChanged);
	Q_OBJECT_BINDABLE_PROPERTY(NigiriWindow, bool, bActive, &NigiriWindow::activeChanged);
	// clang-format on
};

} // namespace qs::nigiri
