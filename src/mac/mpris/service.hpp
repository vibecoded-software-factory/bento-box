#pragma once

#include <qelapsedtimer.h>
#include <qobject.h>
#include <qprocess.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>

#include "../../core/model.hpp"
#include "player.hpp"

namespace qs::mac::mpris {

// Backend singleton driving the macOS now-playing bridge. Spawns the entitled
// system perl running the vendored MediaRemoteAdapter framework as a long-lived
// Process (`... stream`), parses its JSON lines into the single MprisPlayer, and
// sends transport commands by spawning perl one-shot (`... send <n>`). Perl is
// Apple-signed (com.apple.perl5), which is how the framework reaches the
// otherwise-restricted MediaRemote - and being compiled it can call the
// block-based API that carries album artwork, which the osascript path could
// not. Not a QML type - the Mpris facade forwards to it.
class MprisIpc: public QObject {
	Q_OBJECT;

public:
	static MprisIpc* instance();

	[[nodiscard]] ObjectModel<MprisPlayer>* players() { return &this->mPlayers; }

	// Send a MediaRemote transport command (0 play, 1 pause, 2 toggle, 3 stop,
	// 4 next, 5 previous) through a one-shot entitled helper.
	void sendCommand(int command);

private slots:
	void onStreamData();
	void onStreamFinished(int exitCode, QProcess::ExitStatus status);

private:
	explicit MprisIpc();

	// The perl loader (extracted from the Qt resource) and the adapter framework
	// bundle path (baked in at build time, overridable via $BENTO_MRA_FRAMEWORK).
	static QString loaderPath();
	static QString frameworkPath();
	QStringList adapterArgs(const QStringList& command) const;

	void startStream();
	// Backoff-restart for a dead/unstartable stream: doubles the delay per
	// consecutive quick failure (1s..32s); reset after a healthy run.
	void scheduleStreamRestart();
	void applySnapshot(const QByteArray& line);
	// Decode a payload's base64 artworkData to a temp file, returning a file://
	// URL, or empty when the payload carries no artwork.
	QString writeArtwork(const class QJsonObject& payload);

	QProcess mStream;
	QByteArray mBuffer;
	QElapsedTimer mStreamStarted;
	int mStreamRestartStrikes = 0;
	MprisPlayer* mPlayer = nullptr;
	ObjectModel<MprisPlayer> mPlayers {this};

	// Artwork is written to a fresh temp file per track change; the sequence
	// number forces a new URL so a bound Image reloads instead of caching.
	QString mArtContentId;
	int mArtSeq = 0;
};

///! Media players exposed by the system now-playing.
/// The macOS counterpart of the Linux `Mpris` service. `Mpris.players` holds
/// zero or one MprisPlayer (the system aggregates now-playing to one session),
/// fed by the MediaRemote framework through an entitled perl helper.
class MprisQml: public QObject {
	Q_OBJECT;
	// clang-format off
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::mpris::MprisPlayer>*);
	Q_PROPERTY(UntypedObjectModel* players READ players CONSTANT);
	// clang-format on
	QML_NAMED_ELEMENT(Mpris);
	QML_SINGLETON;

public:
	explicit MprisQml(QObject* parent = nullptr): QObject(parent) {}
	[[nodiscard]] UntypedObjectModel* players() const { return MprisIpc::instance()->players(); }
};

} // namespace qs::mac::mpris
