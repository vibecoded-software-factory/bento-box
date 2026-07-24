#include "pam.hpp"

#include <qdebug.h>
#include <qlogging.h>
#include <qstring.h>

namespace qs::mac::pam {

QString PamResult::toString(PamResult::Enum value) {
	// Upstream's, string for string (conversation.cpp:29-37).
	switch (value) {
	case Success: return "Success";
	case Failed: return "Failed";
	case Error: return "Error occurred while authenticating";
	case MaxTries: return "The authentication method has no more attempts available";
	default: return "Invalid result";
	}
}

QString PamError::toString(PamError::Enum value) {
	// Upstream's, string for string (conversation.cpp:20-27).
	switch (value) {
	case StartFailed: return "Failed to start the PAM session";
	case TryAuthFailed: return "Failed to try authenticating";
	case InternalError: return "Internal error occurred";
	default: return "Invalid error";
	}
}

bool PamContext::start() {
	// Honest refusal: on macOS the lock/auth path is system-owned (dms-darwin
	// NativeLock), so no PAM conversation runs from the shell. Mirrors
	// upstream's failed-start contract: error then completed(Error).
	qWarning() << "PamContext.start(): PAM conversations do not run on macOS "
	              "(the lock path is system-owned); refusing.";
	emit this->error(PamError::StartFailed);
	emit this->completed(PamResult::Error);
	return false;
}

void PamContext::respond(const QString& response) {
	Q_UNUSED(response);
	// Upstream refuses when no response is wanted; here one never is.
	qWarning() << "PamContext.respond() called, but responseRequired is false.";
}

void PamContext::setActive(bool active) {
	if (active) {
		this->start();
	} else {
		this->abort();
	}
}

void PamContext::setConfig(const QString& config) {
	if (config == this->mConfig) return;
	this->mConfig = config;
	emit this->configChanged();
}

void PamContext::setConfigDirectory(const QString& configDirectory) {
	if (configDirectory == this->mConfigDirectory) return;
	this->mConfigDirectory = configDirectory;
	emit this->configDirectoryChanged();
}

void PamContext::setUser(const QString& user) {
	if (user == this->mUser) return;
	this->mUser = user;
	emit this->userChanged();
}

} // namespace qs::mac::pam
