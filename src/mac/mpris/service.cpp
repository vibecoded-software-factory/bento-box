#include "service.hpp"

#include <qdir.h>
#include <qfile.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qloggingcategory.h>
#include <qprocess.h>
#include <qstandardpaths.h>

#include "player.hpp"

namespace qs::mac::mpris {

namespace {
Q_LOGGING_CATEGORY(logMpris, "quickshell.mac.mpris");
constexpr const char* OSASCRIPT = "/usr/bin/osascript";
} // namespace

MprisIpc* MprisIpc::instance() {
	static MprisIpc* instance = new MprisIpc(); // NOLINT
	return instance;
}

// Extract the embedded helper (bundled as a Qt resource) to a temp file once,
// so osascript has a real path to run. Kept in the temp dir; overwritten each
// run so an updated build ships an updated script.
QString MprisIpc::helperPath() {
	static QString path;
	if (!path.isEmpty()) return path;

	auto dir = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
	auto target = QDir(dir).filePath("bento-nowplaying.js");

	QFile source(":/mac/mpris/nowplaying.js");
	if (!source.open(QIODevice::ReadOnly)) {
		qCWarning(logMpris) << "helper script resource missing";
		return {};
	}
	auto contents = source.readAll();
	source.close();

	QFile out(target);
	if (!out.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
		qCWarning(logMpris) << "cannot write helper to" << target;
		return {};
	}
	out.write(contents);
	out.close();

	path = target;
	return path;
}

MprisIpc::MprisIpc() {
	QObject::connect(&this->mStream, &QProcess::readyReadStandardOutput, this, &MprisIpc::onStreamData);
	QObject::connect(
	    &this->mStream,
	    QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
	    this,
	    &MprisIpc::onStreamFinished
	);
	this->startStream();
}

void MprisIpc::startStream() {
	auto helper = helperPath();
	if (helper.isEmpty()) return;
	this->mStream.start(OSASCRIPT, {"-l", "JavaScript", helper});
}

void MprisIpc::onStreamFinished(int exitCode, QProcess::ExitStatus /*status*/) {
	// The helper should run forever; if it dies (osascript killed, a transient
	// error), restart it after a short delay so now-playing keeps flowing.
	qCDebug(logMpris) << "helper exited" << exitCode << "- restarting";
	QMetaObject::invokeMethod(this, &MprisIpc::startStream, Qt::QueuedConnection);
}

void MprisIpc::onStreamData() {
	this->mBuffer += this->mStream.readAllStandardOutput();
	qsizetype newline = 0;
	while ((newline = this->mBuffer.indexOf('\n')) != -1) {
		auto line = this->mBuffer.left(newline);
		this->mBuffer.remove(0, newline + 1);
		if (!line.trimmed().isEmpty()) this->applySnapshot(line);
	}
}

void MprisIpc::applySnapshot(const QByteArray& line) {
	auto doc = QJsonDocument::fromJson(line);
	if (!doc.isObject()) return;
	auto object = doc.object();

	if (!object.value("hasPlayer").toBool()) {
		// Nothing playing anywhere - drop the player so a bar hides its media
		// widget, matching an empty MPRIS player list on Linux.
		if (this->mPlayer != nullptr) {
			this->mPlayers.removeObject(this->mPlayer);
			this->mPlayer->deleteLater();
			this->mPlayer = nullptr;
		}
		return;
	}

	bool isNew = this->mPlayer == nullptr;
	if (isNew) this->mPlayer = new MprisPlayer(this);
	this->mPlayer->setBundleId(object.value("bundleId").toString());
	this->mPlayer->updateFromSnapshot(object.toVariantMap());
	// Insert only after the first snapshot has populated it, so a bar binding
	// to players.values sees a filled-in player, not a blank one.
	if (isNew) this->mPlayers.insertObject(this->mPlayer);
}

void MprisIpc::sendCommand(int command) {
	auto helper = helperPath();
	if (helper.isEmpty()) return;
	// One-shot: the entitled helper sends the MediaRemote command and exits.
	QProcess::startDetached(
	    OSASCRIPT,
	    {"-l", "JavaScript", helper, "command", QString::number(command)}
	);
}

} // namespace qs::mac::mpris
