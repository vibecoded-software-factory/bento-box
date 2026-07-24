#include "player.hpp"

#include <qdatetime.h>
#include <qdebug.h>
#include <qstring.h>
#include <qtimezone.h>
#include <qvariant.h>

#include "identity.hpp"
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
	// positionSupported: elapsed/timestamp are standard MediaRemote payload
	// fields, present for every real session. lengthSupported starts false
	// and latches true the first time this player reports a duration.
	this->bPositionSupported = true;
	// The vendored adapter can seek (absolute elapsed time) and set
	// shuffle/repeat for whatever the system's now-playing app is.
	this->bCanSeek = true;
	this->bLoopSupported = true;
	this->bShuffleSupported = true;
}

void MprisPlayer::updateFromSnapshot(const QVariantMap& snapshot) {
	auto app = snapshot.value("app").toString();
	if (!app.isEmpty()) this->bIdentity = app;

	auto title = snapshot.value("title").toString();
	auto artist = snapshot.value("artist").toString();
	auto album = snapshot.value("album").toString();

	bool trackChangedNow = title != this->bTrackTitle.value() || artist != this->bTrackArtist.value();
	if (trackChangedNow) {
		emit this->trackChanged();
		// uniqueId is an opaque per-player counter bumped on every track
		// change, upstream's exact implementation (player.cpp:308).
		this->bUniqueId = this->bUniqueId + 1;
	}

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
	// mpris:length is MICROSECONDS in the MPRIS metadata map (the `length`
	// property stays seconds, like upstream's split).
	if (snapshot.contains("duration"))
		metadata["mpris:length"] = static_cast<qint64>(snapshot.value("duration").toReal() * 1000000.0);
	// MediaRemote's content item identifier is the closest real analogue of
	// mpris:trackid; omitted when the payload has none rather than invented.
	auto trackId = snapshot.value("trackId").toString();
	if (!trackId.isEmpty()) metadata["mpris:trackid"] = trackId;
	this->bMetadata = metadata;

	// lengthSupported tracks whether THIS player ever reported a duration;
	// without one, `length` falls back to `position` like upstream documents.
	if (snapshot.contains("duration")) {
		this->bLength = snapshot.value("duration").toReal();
		this->bLengthSupported = true;
	}

	if (snapshot.contains("playbackRate")) {
		auto rate = snapshot.value("playbackRate").toReal();
		if (rate > 0) this->bRate = rate;
	}

	// Resample position. The sample time is the info's OWN timestamp, not now:
	// a browser reports elapsed=0 with a timestamp that is really "when
	// playback started", so position must count from that timestamp, not from
	// when this snapshot happened to arrive. Falls back to now if absent.
	if (snapshot.contains("elapsed")) {
		this->mSampledElapsed = snapshot.value("elapsed").toReal();
		auto ts = snapshot.value("timestamp");
		this->mSampledAt = ts.isValid() && !ts.isNull() ? QDateTime::fromMSecsSinceEpoch(
		                                                      static_cast<qint64>(ts.toReal() * 1000),
		                                                      QTimeZone::UTC
		                                                  )
		                                                : QDateTime::currentDateTimeUtc();
		emit this->positionChanged();
	}

	auto wasPlaying = this->isPlaying();
	// MediaRemote's now-playing session is binary (playing or not): a session
	// that STOPS deregisters and the player is removed (service.cpp), which is
	// also what upstream does when an MPRIS app quits. `Stopped` is therefore
	// unreachable here - macOS has no alive-but-stopped session state - and
	// that is a documented platform mapping, not an oversight.
	this->bPlaybackState =
	    snapshot.value("playing").toBool() ? MprisPlaybackState::Playing : MprisPlaybackState::Paused;
	// isPlaying is derived from playbackState but carries its OWN NOTIFY
	// upstream (player.hpp:199): an onIsPlayingChanged handler must resolve
	// and fire here too.
	if (this->isPlaying() != wasPlaying) emit this->isPlayingChanged();

	// Loop and shuffle, straight from MediaRemote's repeat/shuffle modes
	// (adapter enums: repeat 1 disabled / 2 track / 3 playlist; shuffle 1
	// disabled / 2 albums / 3 tracks - any enabled shuffle reads true).
	if (snapshot.contains("repeatMode")) {
		auto mode = snapshot.value("repeatMode").toInt();
		this->bLoopState = mode == 2 ? MprisLoopState::Track
		                 : mode == 3 ? MprisLoopState::Playlist
		                             : MprisLoopState::None;
	}
	if (snapshot.contains("shuffleMode")) {
		this->bShuffle = snapshot.value("shuffleMode").toInt() > 1;
	}

	// After every track property updated - upstream's ordering
	// (player.cpp:319).
	if (trackChangedNow) emit this->postTrackChanged();
}

qreal MprisPlayer::length() const {
	// "or the value of position if lengthSupported is false" (upstream
	// player.hpp:141-142).
	return this->bLengthSupported.value() ? this->bLength.value() : this->position();
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

void MprisPlayer::setPosition(qreal position) {
	if (position < 0) position = 0;
	// The adapter's `seek` takes MICROSECONDS and calls
	// MRMediaRemoteSetElapsedTime (mediaremote-adapter/src/adapter/seek.m).
	// The next stream snapshot confirms the new elapsed time - position is
	// never faked locally.
	this->mIpc->sendAdapter({"seek", QString::number(static_cast<qint64>(position * 1000000.0))});
}

void MprisPlayer::seek(qreal offset) {
	// Upstream's seek is a RELATIVE offset in seconds (player.hpp:261);
	// resolved against the live-computed position.
	this->setPosition(this->position() + offset);
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

void MprisPlayer::setRate(qreal rate) {
	if (rate == this->bRate.value()) return;

	// Upstream's guard verbatim (player.cpp:413-421). MPRIS defaults both
	// bounds to 1.0 for players that advertise no range - MediaRemote never
	// does - so out-of-range writes refuse exactly like upstream would.
	if (rate < this->bMinRate.value() || rate > this->bMaxRate.value()) {
		qWarning() << "Cannot set rate for" << this << "to" << rate
		           << "which is outside of minRate and maxRate" << this->bMinRate.value()
		           << this->bMaxRate.value();
		return;
	}

	// The adapter's `speed` command takes an integer multiplier.
	this->mIpc->sendAdapter({"speed", QString::number(static_cast<int>(rate))});
}

void MprisPlayer::setFullscreen(bool fullscreen) {
	// Upstream's guard verbatim (player.cpp:444-448); canSetFullscreen is
	// always false here (MediaRemote has no fullscreen control).
	if (!this->bCanSetFullscreen.value()) {
		qWarning() << "Cannot set fullscreen for" << this << "because canSetFullscreen is false.";
		return;
	}
	Q_UNUSED(fullscreen);
}

void MprisPlayer::openUri(const QString& uri) {
	// MPRIS OpenUri semantics: the PLAYER opens the uri. Routed to the
	// player's own app via a targeted NSWorkspace open.
	if (!openUriWithBundleId(this->mBundleId, uri)) {
		qWarning() << "openUri: could not open" << uri << "with" << this->mBundleId;
	}
}

void MprisPlayer::setVolume(qreal volume) {
	qWarning() << "MprisPlayer.volume is not settable through MediaRemote; ignoring" << volume;
}

void MprisPlayer::setLoopState(MprisLoopState::Enum loopState) {
	// MRARepeatMode: 1 disabled, 2 track, 3 playlist.
	auto mode = loopState == MprisLoopState::Track    ? 2
	          : loopState == MprisLoopState::Playlist ? 3
	                                                  : 1;
	this->mIpc->sendAdapter({"repeat", QString::number(mode)});
}

void MprisPlayer::setShuffle(bool shuffle) {
	// MRAShuffleMode: 1 disabled, 3 tracks (2 = albums, not part of MPRIS).
	this->mIpc->sendAdapter({"shuffle", shuffle ? "3" : "1"});
}

} // namespace qs::mac::mpris
