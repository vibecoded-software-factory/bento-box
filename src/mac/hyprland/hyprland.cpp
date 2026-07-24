#include "hyprland.hpp"
#include <utility>

#include <qbytearrayview.h>
#include <qlogging.h>
#include <qstring.h>
#include <qvector.h>

namespace qs::mac::hyprland {

QVector<QString> HyprlandIpcEvent::parse(qint32 argumentCount) const {
	// Upstream's parseEventArgs, verbatim (ipc/connection.cpp) - over this
	// stub's always-empty data it degenerates to argumentCount empty strings,
	// which is exactly what upstream returns for an empty event body.
	auto event = QByteArrayView();
	auto args = QVector<QString>();

	for (auto i = 0; i < argumentCount - 1; i++) {
		auto splitIdx = event.indexOf(',');
		if (splitIdx == -1) break;
		args.push_back(QString::fromUtf8(event.sliced(0, splitIdx)));
		event = event.sliced(splitIdx + 1);
	}

	if (!event.isEmpty()) {
		args.push_back(QString::fromUtf8(event));
	}

	while (args.length() < argumentCount) {
		args.emplace_back();
	}

	return args;
}

void HyprlandWorkspace::activate() {
	// Upstream: HyprlandIpc.dispatch(`workspace ${name}`). Same route here,
	// which refuses honestly - there is no Hyprland socket on macOS.
	Hyprland::dispatch(QString("workspace %1").arg(HyprlandWorkspace::name()));
}

HyprlandToplevel* HyprlandToplevel::qmlAttachedProperties(QObject* object) {
	// Upstream resolves the Hyprland handle for a wayland Toplevel once its
	// address is reported. No address is ever reported on macOS, so the
	// attached object exists (bindings hold) with null handles forever.
	return new HyprlandToplevel(object);
}

void GlobalShortcut::onPostReload() {
	qWarning() << "GlobalShortcut: hyprland-global-shortcuts-v1 does not exist on macOS; the "
	              "shortcut is not registered and will never fire.";
}

void GlobalShortcut::setAppid(QString appid) {
	if (appid == this->mAppid) return;
	this->mAppid = std::move(appid);
	emit this->appidChanged();
}

void GlobalShortcut::setName(QString name) {
	if (name == this->mName) return;
	this->mName = std::move(name);
	emit this->nameChanged();
}

void GlobalShortcut::setDescription(QString description) {
	if (description == this->mDescription) return;
	this->mDescription = std::move(description);
	emit this->descriptionChanged();
}

void GlobalShortcut::setTriggerDescription(QString triggerDescription) {
	if (triggerDescription == this->mTriggerDescription) return;
	this->mTriggerDescription = std::move(triggerDescription);
	emit this->triggerDescriptionChanged();
}

HyprlandWindow* HyprlandWindow::qmlAttachedProperties(QObject* object) {
	// Values are stored so bindings hold; there is no hyprland-surface-v1 on
	// macOS to forward them to.
	return new HyprlandWindow(object);
}

void HyprlandWindow::setOpacity(qreal opacity) {
	if (opacity == this->mOpacity) return;
	this->mOpacity = opacity;
	emit this->opacityChanged();
}

void HyprlandWindow::setVisibleMask(PendingRegion* mask) {
	if (mask == this->mVisibleMask) return;
	this->mVisibleMask = mask;
	emit this->visibleMaskChanged();
}

void Hyprland::dispatch(const QString& request) {
	// Upstream refuses similarly when $HYPRLAND_INSTANCE_SIGNATURE is unset:
	// "Cannot connect to hyprland." - there is no Hyprland socket on macOS.
	qWarning() << "Hyprland.dispatch: Hyprland is not the compositor on macOS; ignoring" << request;
}

HyprlandMonitor* Hyprland::monitorFor(QuickshellScreenInfo* /*screen*/) {
	// Upstream matches by monitor name; there are no Hyprland monitors here.
	return nullptr;
}

} // namespace qs::mac::hyprland
