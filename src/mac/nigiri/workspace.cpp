#include "workspace.hpp"

#include <qjsonobject.h>
#include <qstring.h>

#include "connection.hpp"

namespace qs::nigiri {

void NigiriWorkspace::updateFromJson(const QJsonObject& object) {
	// nigiri's WorkspacesChanged entry: {id, idx, name, is_active, is_focused,
	// output, active_window_id}. Only the fields a bar needs are mirrored.
	if (object.contains("id")) this->bId = object.value("id").toInt();
	if (object.contains("idx")) this->bIdx = object.value("idx").toInt();
	// name is null when unset.
	auto name = object.value("name");
	this->bName = name.isString() ? name.toString() : QString();
	this->bActive = object.value("is_active").toBool();
	this->bFocused = object.value("is_focused").toBool();
}

void NigiriWorkspace::activate() {
	// niri/nigiri's focus-workspace takes the 1-based strip position.
	this->mIpc->dispatch(QStringLiteral("focus-workspace %1").arg(this->bIdx.value()));
}

} // namespace qs::nigiri
