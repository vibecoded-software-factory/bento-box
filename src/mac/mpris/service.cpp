#include "service.hpp"

#include <qbytearray.h>
#include <qdatetime.h>
#include <qdir.h>
#include <qfile.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qjsonvalue.h>
#include <qloggingcategory.h>
#include <qprocess.h>
#include <qstandardpaths.h>
#include <qstringlist.h>

#include "player.hpp"

namespace qs::mac::mpris {

namespace {
Q_LOGGING_CATEGORY(logMpris, "quickshell.mac.mpris");
constexpr const char* PERL = "/usr/bin/perl";
} // namespace

MprisIpc* MprisIpc::instance() {
	static MprisIpc* instance = new MprisIpc(); // NOLINT
	return instance;
}

// Extract the embedded perl loader (a Qt resource) to a temp file once, so perl
// has a real path to run. Overwritten each run so an updated build ships an
// updated loader.
QString MprisIpc::loaderPath() {
	static QString path;
	if (!path.isEmpty()) return path;

	auto dir = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
	auto target = QDir(dir).filePath("bento-mediaremote-adapter.pl");

	QFile source(":/mac/mpris/mediaremote-adapter.pl");
	if (!source.open(QIODevice::ReadOnly)) {
		qCWarning(logMpris) << "adapter loader resource missing";
		return {};
	}
	auto contents = source.readAll();
	source.close();

	QFile out(target);
	if (!out.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
		qCWarning(logMpris) << "cannot write loader to" << target;
		return {};
	}
	out.write(contents);
	out.close();

	path = target;
	return path;
}

// The adapter framework bundle. Baked in at build time; an env override lets a
// packaged build (or a dev run) point at a framework elsewhere.
QString MprisIpc::frameworkPath() {
	auto env = qEnvironmentVariable("BENTO_MRA_FRAMEWORK");
	if (!env.isEmpty()) return env;
#ifdef BENTO_MRA_FRAMEWORK_PATH
	return QStringLiteral(BENTO_MRA_FRAMEWORK_PATH);
#else
	return {};
#endif
}

QStringList MprisIpc::adapterArgs(const QStringList& command) const {
	return QStringList {loaderPath(), frameworkPath()} + command;
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
	if (loaderPath().isEmpty() || frameworkPath().isEmpty()) {
		qCWarning(logMpris) << "no adapter loader/framework; now-playing disabled";
		return;
	}
	// --no-diff: each line is a full snapshot, mapped straight onto the player
	// (no need to merge diffs). --debounce coalesces rapid updates.
	this->mStream.start(PERL, this->adapterArgs({"stream", "--no-diff", "--debounce=250"}));
}

void MprisIpc::onStreamFinished(int exitCode, QProcess::ExitStatus /*status*/) {
	// The stream should run forever; if it dies, restart it so now-playing keeps
	// flowing.
	qCDebug(logMpris) << "adapter stream exited" << exitCode << "- restarting";
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

QString MprisIpc::writeArtwork(const QJsonObject& payload) {
	auto data = payload.value("artworkData").toString();
	if (data.isEmpty()) {
		// No artwork for this track - forget any previous file so the next track
		// that does have art gets a fresh sequence.
		this->mArtContentId.clear();
		return {};
	}

	// Only decode/rewrite when the track changed; --no-diff repeats artworkData
	// on every snapshot, so keying on the content id (title as fallback) avoids
	// rewriting the same JPEG each tick.
	auto id = payload.value("contentItemIdentifier").toString();
	if (id.isEmpty()) id = payload.value("title").toString();
	auto ext = payload.value("artworkMimeType").toString() == "image/png" ? "png" : "jpg";
	auto currentPath = [&] {
		auto dir = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
		return QDir(dir).filePath(QString("bento-art-%1.%2").arg(this->mArtSeq).arg(ext));
	};

	if (id == this->mArtContentId && this->mArtSeq > 0) {
		return QString("file://%1").arg(currentPath());
	}

	auto bytes = QByteArray::fromBase64(data.toUtf8());
	if (bytes.isEmpty()) return {};

	this->mArtSeq += 1;
	this->mArtContentId = id;
	auto path = currentPath();
	QFile out(path);
	if (!out.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
		qCWarning(logMpris) << "cannot write artwork to" << path;
		return {};
	}
	out.write(bytes);
	out.close();
	return QString("file://%1").arg(path);
}

void MprisIpc::applySnapshot(const QByteArray& line) {
	auto doc = QJsonDocument::fromJson(line);
	if (!doc.isObject()) return;
	auto object = doc.object();
	if (object.value("type").toString() != "data") return;
	auto payload = object.value("payload").toObject();

	// An empty payload means nothing is playing anywhere - drop the player so a
	// bar hides its media widget, matching an empty player list on Linux.
	if (payload.isEmpty() || !payload.contains("title")) {
		if (this->mPlayer != nullptr) {
			this->mPlayers.removeObject(this->mPlayer);
			this->mPlayer->deleteLater();
			this->mPlayer = nullptr;
		}
		this->mArtContentId.clear();
		return;
	}

	// Map the adapter payload onto the snapshot keys MprisPlayer expects.
	QVariantMap snapshot;
	auto bundleId = payload.value("bundleIdentifier").toString();
	snapshot["bundleId"] = bundleId;
	snapshot["app"] = bundleId;
	snapshot["title"] = payload.value("title").toString();
	snapshot["artist"] = payload.value("artist").toString();
	snapshot["album"] = payload.value("album").toString();
	snapshot["playing"] = payload.value("playing").toBool();
	snapshot["art"] = this->writeArtwork(payload);
	if (payload.contains("duration")) snapshot["duration"] = payload.value("duration").toDouble();
	if (payload.contains("elapsedTime")) snapshot["elapsed"] = payload.value("elapsedTime").toDouble();
	// The adapter emits an ISO-8601 timestamp for when elapsedTime was true;
	// MprisPlayer wants it as epoch seconds so it can advance position live.
	auto ts = QDateTime::fromString(payload.value("timestamp").toString(), Qt::ISODate);
	if (ts.isValid()) snapshot["timestamp"] = ts.toMSecsSinceEpoch() / 1000.0;

	bool isNew = this->mPlayer == nullptr;
	if (isNew) this->mPlayer = new MprisPlayer(this);
	this->mPlayer->setBundleId(bundleId);
	this->mPlayer->updateFromSnapshot(snapshot);
	// Insert only after the first snapshot has populated it, so a bar binding to
	// players.values sees a filled-in player, not a blank one.
	if (isNew) this->mPlayers.insertObject(this->mPlayer);
}

void MprisIpc::sendCommand(int command) {
	if (loaderPath().isEmpty() || frameworkPath().isEmpty()) return;
	// One-shot: the entitled perl runs the adapter's `send` and exits.
	QProcess::startDetached(PERL, this->adapterArgs({"send", QString::number(command)}));
}

} // namespace qs::mac::mpris
