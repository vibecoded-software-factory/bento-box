#include "polkit.hpp"

#include <qdebug.h>
#include <qlogging.h>

namespace qs::mac::polkit {

PolkitAgent::PolkitAgent(QObject* parent): QObject(parent) {
	// Honest once-per-instance note: registration is impossible, not skipped.
	qInfo() << "PolkitAgent: macOS has no polkit daemon; the agent cannot "
	           "register and will stay inactive (privilege prompts are "
	           "system-owned dialogs).";
}

void AuthFlow::submit(const QString& value) {
	Q_UNUSED(value);
	// Never reachable through a real flow (none is ever created); refuse
	// honestly if called on a hypothetical instance.
	qWarning() << "AuthFlow.submit() called, but no polkit conversation can "
	              "exist on macOS.";
}

void AuthFlow::cancelAuthenticationRequest() {
	qWarning() << "AuthFlow.cancelAuthenticationRequest() called, but no "
	              "polkit conversation can exist on macOS.";
}

void AuthFlow::setSelectedIdentity(Identity* identity) { this->bSelectedIdentity = identity; }

} // namespace qs::mac::polkit
