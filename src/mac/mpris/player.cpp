#include "player.hpp"

#include <qdatetime.h>
#include <qstring.h>
#include <qvariant.h>

#include "service.hpp"

namespace qs::mac::mpris {

QString MprisPlaybackState::toString(MprisPlaybackState::Enum value) {
	switch (value) {
	case Playing: return "Playing";
	case Paused: return "Paused";
	case Stopped: return "Stopped";
	default: return "Unknown";
	}
}

QString MprisLoopState::toString(MprisLoopState::Enum value) {
	switch (value) {
	case None: return "None";
	case Track: return "Track";
	case Playlist: return "Playlist";
	default: return "Unknown";
	}
}

MprisPlayer::MprisPlayer(MprisIpc* ipc): QObject(nullptr), mIpc(ipc) {
	this->bLengthSupported = true;
	this->bPositionSupported = true;
}

void MprisPlayer::updateFromSnapshot(const QVariantMap& snapshot) {
	auto app = snapshot.value("app").toString();
	if (!app.isEmpty()) this->bIdentity = app;

	auto title = snapshot.value("title").toString();
	auto artist = snapshot.value("artist").toString();
	auto album = snapshot.value("album").toString();

	bool trackChangedNow = title != this->bTrackTitle.value() || artist != this->bTrackArtist.value();
	if (trackChangedNow) emit this->trackChanged();

	this->bTrackTitle = title;
	this->bTrackArtist = artist;
	this->bTrackAlbum = album;
	// A file:// URL the helper wrote the artwork to, or empty when the track
	// has none.
	this->bTrackArtUrl = snapshot.value("art").toString();

	// The metadata map mirrors the Linux service's xesam:*/mpris:* keys so DMS
	// reads the same fields.
	QVariantMap metadata;
	metadata["xesam:title"] = title;
	metadata["xesam:artist"] = QStringList {artist};
	metadata["xesam:album"] = album;
	auto artUrl = snapshot.value("art").toString();
	if (!artUrl.isEmpty()) metadata["mpris:artUrl"] = artUrl;
	this->bMetadata = metadata;

	if (snapshot.contains("duration")) this->bLength = snapshot.value("duration").toReal();

	// Resample position. The sample time is the info's OWN timestamp, not now:
	// a browser reports elapsed=0 with a timestamp that is really "when
	// playback started", so position must count from that timestamp, not from
	// when this snapshot happened to arrive. Falls back to now if absent.
	if (snapshot.contains("elapsed")) {
		this->mSampledElapsed = snapshot.value("elapsed").toReal();
		auto ts = snapshot.value("timestamp");
		this->mSampledAt =
		    ts.isValid() && !ts.isNull()
		        ? QDateTime::fromMSecsSinceEpoch(static_cast<qint64>(ts.toReal() * 1000), Qt::UTC)
		        : QDateTime::currentDateTimeUtc();
		emit this->positionChanged();
	}

	this->bPlaybackState =
	    snapshot.value("playing").toBool() ? MprisPlaybackState::Playing : MprisPlaybackState::Paused;
}

qreal MprisPlayer::position() const {
	if (this->bPlaybackState.value() != MprisPlaybackState::Playing || this->mSampledAt.isNull()) {
		return this->mSampledElapsed;
	}
	// Sampled elapsed plus the wall-clock time that has passed since - the same
	// live-computed model the Linux service uses, so a progress bar advances
	// smoothly between the coarse snapshots.
	auto elapsed = this->mSampledAt.msecsTo(QDateTime::currentDateTimeUtc()) / 1000.0;
	return this->mSampledElapsed + elapsed;
}

void MprisPlayer::setPosition(qreal /*position*/) {
	// MediaRemote exposes no absolute seek reachable from the entitled helper;
	// left as a no-op rather than faked.
}

void MprisPlayer::setPlaying(bool playing) { playing ? this->play() : this->pause(); }

void MprisPlayer::setPlaybackState(MprisPlaybackState::Enum state) {
	switch (state) {
	case MprisPlaybackState::Playing: this->play(); break;
	case MprisPlaybackState::Paused: this->pause(); break;
	case MprisPlaybackState::Stopped: this->stop(); break;
	default: break;
	}
}

// MediaRemote command ids, per the framework: 0 play, 1 pause, 2 toggle,
// 3 stop, 4 next, 5 previous.
void MprisPlayer::play() { this->mIpc->sendCommand(0); }
void MprisPlayer::pause() { this->mIpc->sendCommand(1); }
void MprisPlayer::togglePlaying() { this->mIpc->sendCommand(2); }
void MprisPlayer::stop() { this->mIpc->sendCommand(3); }
void MprisPlayer::next() { this->mIpc->sendCommand(4); }
void MprisPlayer::previous() { this->mIpc->sendCommand(5); }

} // namespace qs::mac::mpris
