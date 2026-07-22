#include "window.hpp"

#include <qjsonobject.h>
#include <qstring.h>

#include "connection.hpp"

namespace qs::nigiri {

NigiriWindow::NigiriWindow(NigiriIpc* ipc): QObject(nullptr), mIpc(ipc) {
	// active is derived, exactly like Hyprland's focused: it tracks the
	// singleton's focused window id, so a taskbar highlight recomputes on its
	// own when focus moves - no per-window toggling from the event handler.
	this->bActive.setBinding([this]() {
		return this->mIpc->bindableFocusedWindowId().value() == this->bId.value();
	});
}

void NigiriWindow::updateFromJson(const QJsonObject& object) {
	// nigiri's window entry: {id, title, app_id, pid, workspace_id, is_focused,
	// is_floating, column?, row?, layout}. Only what a window list needs.
	if (object.contains("id")) this->bId = object.value("id").toInt();
	if (object.contains("title")) this->bTitle = object.value("title").toString();
	if (object.contains("app_id")) this->bAppId = object.value("app_id").toString();
	if (object.contains("pid")) this->bPid = object.value("pid").toInt();
	if (object.contains("workspace_id")) this->bWorkspaceId = object.value("workspace_id").toInt();
	if (object.contains("is_floating")) this->bFloating = object.value("is_floating").toBool();
}

void NigiriWindow::activate() {
	// nigiri focuses a window by id via focus-window-by-id.
	this->mIpc->dispatch(QStringLiteral("focus-window-by-id %1").arg(this->bId.value()));
}

} // namespace qs::nigiri
