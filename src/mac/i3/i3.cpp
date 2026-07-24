#include "i3.hpp"
#include <utility>

#include <qlogging.h>
#include <qstring.h>

namespace qs::mac::i3 {

void I3Workspace::activate() {
	// Upstream: I3.dispatch(`workspace number ${number}`). Same route here,
	// which refuses honestly - there is no i3 socket on macOS.
	I3::dispatch(QString("workspace number %1").arg(I3Workspace::number()));
}

void I3::dispatch(const QString& request) {
	// Upstream refuses similarly when $I3SOCK and $SWAYSOCK are unset:
	// "Cannot connect to socket." - there is no i3 socket on macOS.
	qWarning() << "I3.dispatch: i3/Sway is not the compositor on macOS; ignoring" << request;
}

I3Workspace* I3::findWorkspaceByName(const QString& /*name*/) {
	// There are no i3 workspaces here - upstream's not-found result.
	return nullptr;
}

I3Monitor* I3::findMonitorByName(const QString& /*name*/) {
	// There are no i3 monitors here - upstream's not-found result.
	return nullptr;
}

I3Monitor* I3::monitorFor(QuickshellScreenInfo* /*screen*/) {
	// Upstream matches by monitor name; there are no i3 monitors here.
	return nullptr;
}

void I3IpcListener::onPostReload() {
	qWarning() << "I3IpcListener: there is no i3/Sway socket on macOS; not connecting - no event "
	              "will ever fire.";
}

void I3IpcListener::setSubscriptions(QList<QString> subscriptions) {
	if (subscriptions == this->mSubscriptions) return;
	this->mSubscriptions = std::move(subscriptions);
	emit this->subscriptionsChanged();
}

} // namespace qs::mac::i3
