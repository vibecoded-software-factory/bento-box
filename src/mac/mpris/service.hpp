#pragma once

#include <qobject.h>
#include <qprocess.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>

#include "../../core/model.hpp"
#include "player.hpp"

namespace qs::mac::mpris {

// Backend singleton driving the macOS now-playing bridge. Spawns the entitled
// osascript helper (nowplaying.js) as a long-lived Process and parses its JSON
// lines into the single MprisPlayer; sends transport commands by spawning the
// helper one-shot in command mode. Not a QML type - the Mpris facade forwards
// to it.
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

	static QString helperPath();
	void startStream();
	void applySnapshot(const QByteArray& line);

	QProcess mStream;
	QByteArray mBuffer;
	MprisPlayer* mPlayer = nullptr;
	ObjectModel<MprisPlayer> mPlayers {this};
};

///! Media players exposed by the system now-playing.
/// The macOS counterpart of the Linux `Mpris` service. `Mpris.players` holds
/// zero or one MprisPlayer (the system aggregates now-playing to one session),
/// fed by the MediaRemote framework through an entitled osascript helper.
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
