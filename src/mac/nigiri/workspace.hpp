#pragma once

#include <qjsonobject.h>
#include <qobject.h>
#include <qproperty.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>
#include <qtypes.h>

namespace qs::nigiri {

class NigiriIpc;

// One of nigiri's dynamic workspaces, mirrored from its event stream. The
// model equivalent of HyprlandWorkspace: bindable source-of-truth properties
// that QML binds to, updated in place as WorkspacesChanged events arrive.
class NigiriWorkspace: public QObject {
	Q_OBJECT;
	// clang-format off
	/// Stable id of the workspace (niri's workspace id).
	Q_PROPERTY(qint32 id READ default NOTIFY idChanged BINDABLE bindableId);
	/// 1-based position in the strip. This is what shifts as workspaces are
	/// added and removed, and what a bar usually shows.
	Q_PROPERTY(qint32 idx READ default NOTIFY idxChanged BINDABLE bindableIdx);
	/// Optional name, or empty.
	Q_PROPERTY(QString name READ default NOTIFY nameChanged BINDABLE bindableName);
	/// Whether this is the active workspace.
	Q_PROPERTY(bool active READ default NOTIFY activeChanged BINDABLE bindableActive);
	/// Whether this workspace is active and focused.
	Q_PROPERTY(bool focused READ default NOTIFY focusedChanged BINDABLE bindableFocused);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("NigiriWorkspaces are retrieved from the Nigiri singleton.");

public:
	explicit NigiriWorkspace(NigiriIpc* ipc): QObject(nullptr), mIpc(ipc) {}

	void updateFromJson(const QJsonObject& object);

	/// Switch to this workspace.
	Q_INVOKABLE void activate();

	[[nodiscard]] QBindable<qint32> bindableId() { return &this->bId; }
	[[nodiscard]] QBindable<qint32> bindableIdx() { return &this->bIdx; }
	[[nodiscard]] QBindable<QString> bindableName() { return &this->bName; }
	[[nodiscard]] QBindable<bool> bindableActive() { return &this->bActive; }
	[[nodiscard]] QBindable<bool> bindableFocused() { return &this->bFocused; }

signals:
	void idChanged();
	void idxChanged();
	void nameChanged();
	void activeChanged();
	void focusedChanged();

private:
	NigiriIpc* mIpc;

	// clang-format off
	Q_OBJECT_BINDABLE_PROPERTY(NigiriWorkspace, qint32, bId, &NigiriWorkspace::idChanged);
	Q_OBJECT_BINDABLE_PROPERTY(NigiriWorkspace, qint32, bIdx, &NigiriWorkspace::idxChanged);
	Q_OBJECT_BINDABLE_PROPERTY(NigiriWorkspace, QString, bName, &NigiriWorkspace::nameChanged);
	Q_OBJECT_BINDABLE_PROPERTY(NigiriWorkspace, bool, bActive, &NigiriWorkspace::activeChanged);
	Q_OBJECT_BINDABLE_PROPERTY(NigiriWorkspace, bool, bFocused, &NigiriWorkspace::focusedChanged);
	// clang-format on
};

} // namespace qs::nigiri
