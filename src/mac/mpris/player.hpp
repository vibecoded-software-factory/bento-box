#pragma once

#include <qdatetime.h>
#include <qobject.h>
#include <qproperty.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>
#include <qtypes.h>
#include <qvariant.h>

namespace qs::mac::mpris {

///! Playback state of an MprisPlayer.
class MprisPlaybackState: public QObject {
	Q_OBJECT;
	QML_NAMED_ELEMENT(MprisPlaybackState);
	QML_SINGLETON;

public:
	// Same values as the Linux Mpris service, so DMS binds unchanged.
	enum Enum : quint8 {
		Stopped = 0,
		Playing = 1,
		Paused = 2,
	};
	Q_ENUM(Enum);

	Q_INVOKABLE static QString toString(qs::mac::mpris::MprisPlaybackState::Enum value);
};

///! Loop state of an MprisPlayer.
class MprisLoopState: public QObject {
	Q_OBJECT;
	QML_NAMED_ELEMENT(MprisLoopState);
	QML_SINGLETON;

public:
	enum Enum : quint8 {
		None = 0,
		Track = 1,
		Playlist = 2,
	};
	Q_ENUM(Enum);

	Q_INVOKABLE static QString toString(qs::mac::mpris::MprisLoopState::Enum value);
};

class MprisIpc;

// The macOS now-playing session as an MprisPlayer. There is at most one (the
// system aggregates now-playing to a single session), so `Mpris.players` holds
// zero or one of these. The property/method surface matches the Linux MPRIS
// MprisPlayer so DMS's media widget binds without changes; capabilities that
// MediaRemote does not expose (seek, volume, loop, shuffle, rate) are reported
// unsupported rather than faked.
class MprisPlayer: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(QString identity READ default NOTIFY identityChanged BINDABLE bindableIdentity);
	Q_PROPERTY(QString desktopEntry READ default NOTIFY desktopEntryChanged BINDABLE bindableDesktopEntry);
	Q_PROPERTY(QString dbusName READ dbusName CONSTANT);

	Q_PROPERTY(bool canControl READ default NOTIFY canControlChanged BINDABLE bindableCanControl);
	Q_PROPERTY(bool canPlay READ default NOTIFY canPlayChanged BINDABLE bindableCanPlay);
	Q_PROPERTY(bool canPause READ default NOTIFY canPauseChanged BINDABLE bindableCanPause);
	Q_PROPERTY(bool canTogglePlaying READ default NOTIFY canTogglePlayingChanged BINDABLE bindableCanTogglePlaying);
	Q_PROPERTY(bool canGoNext READ default NOTIFY canGoNextChanged BINDABLE bindableCanGoNext);
	Q_PROPERTY(bool canGoPrevious READ default NOTIFY canGoPreviousChanged BINDABLE bindableCanGoPrevious);
	Q_PROPERTY(bool canSeek READ default NOTIFY canSeekChanged BINDABLE bindableCanSeek);
	Q_PROPERTY(bool canQuit READ default NOTIFY canQuitChanged BINDABLE bindableCanQuit);
	Q_PROPERTY(bool canRaise READ default NOTIFY canRaiseChanged BINDABLE bindableCanRaise);

	Q_PROPERTY(qs::mac::mpris::MprisPlaybackState::Enum playbackState READ default WRITE setPlaybackState NOTIFY playbackStateChanged BINDABLE bindablePlaybackState);
	Q_PROPERTY(bool isPlaying READ isPlaying WRITE setPlaying NOTIFY isPlayingChanged);

	Q_PROPERTY(qreal position READ position WRITE setPosition NOTIFY positionChanged);
	Q_PROPERTY(bool positionSupported READ default NOTIFY positionSupportedChanged BINDABLE bindablePositionSupported);
	// Like upstream (player.hpp:141-144): the value of `position` when the
	// player never reported a duration. Custom READ instead of upstream's
	// BINDABLE so the fallback stays live; lengthChanged still notifies.
	Q_PROPERTY(qreal length READ length NOTIFY lengthChanged);
	Q_PROPERTY(bool lengthSupported READ default NOTIFY lengthSupportedChanged BINDABLE bindableLengthSupported);

	Q_PROPERTY(QVariantMap metadata READ default NOTIFY metadataChanged BINDABLE bindableMetadata);
	// Opaque per-player track counter, incremented on every track change -
	// upstream's uniqueId contract (player.hpp:159-163, player.cpp:308).
	Q_PROPERTY(quint32 uniqueId READ default NOTIFY uniqueIdChanged BINDABLE bindableUniqueId);
	Q_PROPERTY(QString trackTitle READ default NOTIFY trackTitleChanged BINDABLE bindableTrackTitle);
	Q_PROPERTY(QString trackArtist READ default NOTIFY trackArtistChanged BINDABLE bindableTrackArtist);
	// Deprecated upstream alias of trackArtist - same bindable, same NOTIFY.
	Q_PROPERTY(QString trackArtists READ default NOTIFY trackArtistChanged BINDABLE bindableTrackArtist);
	Q_PROPERTY(QString trackAlbum READ default NOTIFY trackAlbumChanged BINDABLE bindableTrackAlbum);
	// "" if none was provided - MediaRemote's payload has no album artist,
	// so this is always the upstream-sanctioned empty fallback.
	Q_PROPERTY(QString trackAlbumArtist READ default NOTIFY trackAlbumArtistChanged BINDABLE bindableTrackAlbumArtist);
	Q_PROPERTY(QString trackArtUrl READ default NOTIFY trackArtUrlChanged BINDABLE bindableTrackArtUrl);

	// Rate reads live from the payload's playbackRate. Writes carry
	// upstream's guard verbatim: only values within [minRate, maxRate], and
	// MPRIS defaults BOTH to 1.0 when the player does not advertise a range
	// - which MediaRemote never does - so exactly the writes upstream would
	// accept from such a player are accepted here (routed to the adapter's
	// `speed` command).
	Q_PROPERTY(qreal rate READ rate WRITE setRate NOTIFY rateChanged);
	Q_PROPERTY(qreal minRate READ default NOTIFY minRateChanged BINDABLE bindableMinRate);
	Q_PROPERTY(qreal maxRate READ default NOTIFY maxRateChanged BINDABLE bindableMaxRate);
	// MediaRemote has no fullscreen control: canSetFullscreen is false and
	// the write refuses with upstream's own message (player.cpp:444-448).
	Q_PROPERTY(bool fullscreen READ fullscreen WRITE setFullscreen NOTIFY fullscreenChanged);
	Q_PROPERTY(bool canSetFullscreen READ default NOTIFY canSetFullscreenChanged BINDABLE bindableCanSetFullscreen);
	// Unadvertised (MediaRemote exposes neither) - empty lists, like an
	// MPRIS player that does not implement the properties.
	Q_PROPERTY(QList<QString> supportedUriSchemes READ default NOTIFY supportedUriSchemesChanged BINDABLE bindableSupportedUriSchemes);
	Q_PROPERTY(QList<QString> supportedMimeTypes READ default NOTIFY supportedMimeTypesChanged BINDABLE bindableSupportedMimeTypes);

	// Volume stays unsupported (MediaRemote exposes no per-player volume);
	// present for binding compatibility, volumeSupported false, write ignored.
	Q_PROPERTY(qreal volume READ volume WRITE setVolume NOTIFY volumeChanged);
	Q_PROPERTY(bool volumeSupported READ default NOTIFY volumeSupportedChanged BINDABLE bindableVolumeSupported);
	// Loop and shuffle are REAL: read from the adapter stream's repeatMode/
	// shuffleMode, written through the vendored adapter's repeat/shuffle
	// commands (MRMediaRemoteSetRepeatMode/SetShuffleMode).
	Q_PROPERTY(qs::mac::mpris::MprisLoopState::Enum loopState READ loopState WRITE setLoopState NOTIFY loopStateChanged);
	Q_PROPERTY(bool loopSupported READ default NOTIFY loopSupportedChanged BINDABLE bindableLoopSupported);
	Q_PROPERTY(bool shuffle READ shuffle WRITE setShuffle NOTIFY shuffleChanged);
	Q_PROPERTY(bool shuffleSupported READ default NOTIFY shuffleSupportedChanged BINDABLE bindableShuffleSupported);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("MprisPlayers can only be acquired from Mpris.");

public:
	explicit MprisPlayer(MprisIpc* ipc);

	// Apply a parsed now-playing snapshot (one JSON line from the helper).
	void updateFromSnapshot(const QVariantMap& snapshot);

	[[nodiscard]] QString dbusName() const { return this->mBundleId; }
	void setBundleId(const QString& id) { this->mBundleId = id; }

	[[nodiscard]] bool isPlaying() const {
		return this->bPlaybackState.value() == MprisPlaybackState::Playing;
	}
	void setPlaying(bool playing);
	void setPlaybackState(MprisPlaybackState::Enum state);

	[[nodiscard]] qreal position() const;
	void setPosition(qreal position);
	[[nodiscard]] qreal length() const;

	[[nodiscard]] qreal rate() const { return this->bRate.value(); }
	void setRate(qreal rate);
	[[nodiscard]] bool fullscreen() const { return this->bFullscreen.value(); }
	void setFullscreen(bool fullscreen);
	// Opens the uri with the player's own app (NSWorkspace targeted open) -
	// the MPRIS OpenUri semantic.
	Q_INVOKABLE void openUri(const QString& uri);

	Q_INVOKABLE void play();
	Q_INVOKABLE void pause();
	Q_INVOKABLE void stop();
	Q_INVOKABLE void togglePlaying();
	Q_INVOKABLE void next();
	Q_INVOKABLE void previous();
	// Seek is REAL: the vendored adapter's `seek` sets an absolute elapsed
	// time (MRMediaRemoteSetElapsedTime), so setPosition maps directly and
	// seek(offset) is position + offset, upstream's relative form.
	Q_INVOKABLE void seek(qreal offset);
	// Present for API compatibility; MediaRemote offers no raise/quit.
	Q_INVOKABLE void raise() {}
	Q_INVOKABLE void quit() {}

	[[nodiscard]] QBindable<QString> bindableIdentity() { return &this->bIdentity; }
	[[nodiscard]] QBindable<QString> bindableDesktopEntry() { return &this->bDesktopEntry; }
	[[nodiscard]] QBindable<bool> bindableCanControl() { return &this->bCanControl; }
	[[nodiscard]] QBindable<bool> bindableCanPlay() { return &this->bCanPlay; }
	[[nodiscard]] QBindable<bool> bindableCanPause() { return &this->bCanPause; }
	[[nodiscard]] QBindable<bool> bindableCanTogglePlaying() { return &this->bCanTogglePlaying; }
	[[nodiscard]] QBindable<bool> bindableCanGoNext() { return &this->bCanGoNext; }
	[[nodiscard]] QBindable<bool> bindableCanGoPrevious() { return &this->bCanGoPrevious; }
	[[nodiscard]] QBindable<bool> bindableCanSeek() { return &this->bCanSeek; }
	[[nodiscard]] QBindable<bool> bindableCanQuit() { return &this->bCanQuit; }
	[[nodiscard]] QBindable<bool> bindableCanRaise() { return &this->bCanRaise; }
	[[nodiscard]] QBindable<MprisPlaybackState::Enum> bindablePlaybackState() {
		return &this->bPlaybackState;
	}
	[[nodiscard]] QBindable<bool> bindablePositionSupported() { return &this->bPositionSupported; }
	[[nodiscard]] QBindable<quint32> bindableUniqueId() { return &this->bUniqueId; }
	[[nodiscard]] QBindable<QString> bindableTrackAlbumArtist() { return &this->bTrackAlbumArtist; }
	[[nodiscard]] QBindable<qreal> bindableMinRate() { return &this->bMinRate; }
	[[nodiscard]] QBindable<qreal> bindableMaxRate() { return &this->bMaxRate; }
	[[nodiscard]] QBindable<bool> bindableCanSetFullscreen() { return &this->bCanSetFullscreen; }
	[[nodiscard]] QBindable<QList<QString>> bindableSupportedUriSchemes() {
		return &this->bSupportedUriSchemes;
	}
	[[nodiscard]] QBindable<QList<QString>> bindableSupportedMimeTypes() {
		return &this->bSupportedMimeTypes;
	}
	[[nodiscard]] QBindable<bool> bindableLengthSupported() { return &this->bLengthSupported; }
	[[nodiscard]] QBindable<QVariantMap> bindableMetadata() { return &this->bMetadata; }
	[[nodiscard]] QBindable<QString> bindableTrackTitle() { return &this->bTrackTitle; }
	[[nodiscard]] QBindable<QString> bindableTrackArtist() { return &this->bTrackArtist; }
	[[nodiscard]] QBindable<QString> bindableTrackAlbum() { return &this->bTrackAlbum; }
	[[nodiscard]] QBindable<QString> bindableTrackArtUrl() { return &this->bTrackArtUrl; }
	[[nodiscard]] QBindable<qreal> bindableVolume() { return &this->bVolume; }
	// MediaRemote exposes no control for these; accept the write, log, and
	// keep the readable state - the same as upstream's unsupported setters.
	[[nodiscard]] qreal volume() const { return this->bVolume.value(); }
	void setVolume(qreal volume);
	[[nodiscard]] MprisLoopState::Enum loopState() const { return this->bLoopState.value(); }
	void setLoopState(MprisLoopState::Enum loopState);
	[[nodiscard]] bool shuffle() const { return this->bShuffle.value(); }
	void setShuffle(bool shuffle);
	[[nodiscard]] QBindable<bool> bindableVolumeSupported() { return &this->bVolumeSupported; }
	[[nodiscard]] QBindable<MprisLoopState::Enum> bindableLoopState() { return &this->bLoopState; }
	[[nodiscard]] QBindable<bool> bindableLoopSupported() { return &this->bLoopSupported; }
	[[nodiscard]] QBindable<bool> bindableShuffle() { return &this->bShuffle; }
	[[nodiscard]] QBindable<bool> bindableShuffleSupported() { return &this->bShuffleSupported; }

signals:
	void trackChanged();
	// After the track properties updated, upstream's ordering
	// (player.hpp:351, player.cpp:319): trackChanged fires before the
	// update, postTrackChanged after.
	void postTrackChanged();
	void isPlayingChanged();
	void uniqueIdChanged();
	void trackAlbumArtistChanged();
	void rateChanged();
	void minRateChanged();
	void maxRateChanged();
	void fullscreenChanged();
	void canSetFullscreenChanged();
	void supportedUriSchemesChanged();
	void supportedMimeTypesChanged();
	void identityChanged();
	void desktopEntryChanged();
	void canControlChanged();
	void canPlayChanged();
	void canPauseChanged();
	void canTogglePlayingChanged();
	void canGoNextChanged();
	void canGoPreviousChanged();
	void canSeekChanged();
	void canQuitChanged();
	void canRaiseChanged();
	void playbackStateChanged();
	void positionChanged();
	void positionSupportedChanged();
	void lengthChanged();
	void lengthSupportedChanged();
	void metadataChanged();
	void trackTitleChanged();
	void trackArtistChanged();
	void trackAlbumChanged();
	void trackArtUrlChanged();
	void volumeChanged();
	void volumeSupportedChanged();
	void loopStateChanged();
	void loopSupportedChanged();
	void shuffleChanged();
	void shuffleSupportedChanged();

private:
	MprisIpc* mIpc;
	QString mBundleId;
	// Position sampling: last elapsed value from the helper and when we saw it,
	// so `position` advances smoothly while playing (the Linux service's model).
	qreal mSampledElapsed = 0;
	QDateTime mSampledAt;

	// clang-format off
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, QString, bIdentity, &MprisPlayer::identityChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, QString, bDesktopEntry, &MprisPlayer::desktopEntryChanged);
	Q_OBJECT_BINDABLE_PROPERTY_WITH_ARGS(MprisPlayer, bool, bCanControl, true, &MprisPlayer::canControlChanged);
	Q_OBJECT_BINDABLE_PROPERTY_WITH_ARGS(MprisPlayer, bool, bCanPlay, true, &MprisPlayer::canPlayChanged);
	Q_OBJECT_BINDABLE_PROPERTY_WITH_ARGS(MprisPlayer, bool, bCanPause, true, &MprisPlayer::canPauseChanged);
	Q_OBJECT_BINDABLE_PROPERTY_WITH_ARGS(MprisPlayer, bool, bCanTogglePlaying, true, &MprisPlayer::canTogglePlayingChanged);
	Q_OBJECT_BINDABLE_PROPERTY_WITH_ARGS(MprisPlayer, bool, bCanGoNext, true, &MprisPlayer::canGoNextChanged);
	Q_OBJECT_BINDABLE_PROPERTY_WITH_ARGS(MprisPlayer, bool, bCanGoPrevious, true, &MprisPlayer::canGoPreviousChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, bool, bCanSeek, &MprisPlayer::canSeekChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, bool, bCanQuit, &MprisPlayer::canQuitChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, bool, bCanRaise, &MprisPlayer::canRaiseChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, MprisPlaybackState::Enum, bPlaybackState, &MprisPlayer::playbackStateChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, bool, bPositionSupported, &MprisPlayer::positionSupportedChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, qreal, bLength, &MprisPlayer::lengthChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, quint32, bUniqueId, &MprisPlayer::uniqueIdChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, QString, bTrackAlbumArtist, &MprisPlayer::trackAlbumArtistChanged);
	Q_OBJECT_BINDABLE_PROPERTY_WITH_ARGS(MprisPlayer, qreal, bRate, 1, &MprisPlayer::rateChanged);
	Q_OBJECT_BINDABLE_PROPERTY_WITH_ARGS(MprisPlayer, qreal, bMinRate, 1, &MprisPlayer::minRateChanged);
	Q_OBJECT_BINDABLE_PROPERTY_WITH_ARGS(MprisPlayer, qreal, bMaxRate, 1, &MprisPlayer::maxRateChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, bool, bFullscreen, &MprisPlayer::fullscreenChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, bool, bCanSetFullscreen, &MprisPlayer::canSetFullscreenChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, QList<QString>, bSupportedUriSchemes, &MprisPlayer::supportedUriSchemesChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, QList<QString>, bSupportedMimeTypes, &MprisPlayer::supportedMimeTypesChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, bool, bLengthSupported, &MprisPlayer::lengthSupportedChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, QVariantMap, bMetadata, &MprisPlayer::metadataChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, QString, bTrackTitle, &MprisPlayer::trackTitleChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, QString, bTrackArtist, &MprisPlayer::trackArtistChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, QString, bTrackAlbum, &MprisPlayer::trackAlbumChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, QString, bTrackArtUrl, &MprisPlayer::trackArtUrlChanged);
	// Upstream defaults volume to 1.0 when volumeSupported is false
	// (player.hpp:145,455) - 0.0 read as "muted" by shells.
	Q_OBJECT_BINDABLE_PROPERTY_WITH_ARGS(MprisPlayer, qreal, bVolume, 1, &MprisPlayer::volumeChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, bool, bVolumeSupported, &MprisPlayer::volumeSupportedChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, MprisLoopState::Enum, bLoopState, &MprisPlayer::loopStateChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, bool, bLoopSupported, &MprisPlayer::loopSupportedChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, bool, bShuffle, &MprisPlayer::shuffleChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, bool, bShuffleSupported, &MprisPlayer::shuffleSupportedChanged);
	// clang-format on
};

} // namespace qs::mac::mpris
