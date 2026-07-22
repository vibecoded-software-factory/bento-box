#include "qml.hpp"

#include <qobject.h>

#include "connection.hpp"

namespace qs::nigiri {

NigiriIpcQml::NigiriIpcQml(QObject* parent): QObject(parent) {
	auto* ipc = NigiriIpc::instance();
	QObject::connect(ipc, &NigiriIpc::focusedWorkspaceChanged, this, &NigiriIpcQml::focusedWorkspaceChanged);
	QObject::connect(ipc, &NigiriIpc::focusedWindowIdChanged, this, &NigiriIpcQml::focusedWindowIdChanged);
	QObject::connect(ipc, &NigiriIpc::rawEvent, this, &NigiriIpcQml::rawEvent);
}

UntypedObjectModel* NigiriIpcQml::workspaces() const { return NigiriIpc::instance()->workspaces(); }

NigiriWorkspace* NigiriIpcQml::focusedWorkspace() const {
	return NigiriIpc::instance()->bindableFocusedWorkspace().value();
}

qint32 NigiriIpcQml::focusedWindowId() const {
	return NigiriIpc::instance()->bindableFocusedWindowId().value();
}

void NigiriIpcQml::dispatch(const QString& action) { NigiriIpc::instance()->dispatch(action); }

} // namespace qs::nigiri
