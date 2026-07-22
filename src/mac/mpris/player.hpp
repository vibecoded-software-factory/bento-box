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
	Q_PROPERTY(bool isPlaying READ isPlaying WRITE setPlaying NOTIFY playbackStateChanged);

	Q_PROPERTY(qreal position READ position WRITE setPosition NOTIFY positionChanged);
	Q_PROPERTY(bool positionSupported READ default NOTIFY positionSupportedChanged BINDABLE bindablePositionSupported);
	Q_PROPERTY(qreal length READ default NOTIFY lengthChanged BINDABLE bindableLength);
	Q_PROPERTY(bool lengthSupported READ default NOTIFY lengthSupportedChanged BINDABLE bindableLengthSupported);

	Q_PROPERTY(QVariantMap metadata READ default NOTIFY metadataChanged BINDABLE bindableMetadata);
	Q_PROPERTY(QString trackTitle READ default NOTIFY trackTitleChanged BINDABLE bindableTrackTitle);
	Q_PROPERTY(QString trackArtist READ default NOTIFY trackArtistChanged BINDABLE bindableTrackArtist);
	Q_PROPERTY(QString trackAlbum READ default NOTIFY trackAlbumChanged BINDABLE bindableTrackAlbum);
	Q_PROPERTY(QString trackArtUrl READ default NOTIFY trackArtUrlChanged BINDABLE bindableTrackArtUrl);

	// Unsupported on macOS/MediaRemote - present for binding compatibility,
	// their *Supported flag is false and writes are ignored.
	Q_PROPERTY(qreal volume READ default NOTIFY volumeChanged BINDABLE bindableVolume);
	Q_PROPERTY(bool volumeSupported READ default NOTIFY volumeSupportedChanged BINDABLE bindableVolumeSupported);
	Q_PROPERTY(qs::mac::mpris::MprisLoopState::Enum loopState READ default NOTIFY loopStateChanged BINDABLE bindableLoopState);
	Q_PROPERTY(bool loopSupported READ default NOTIFY loopSupportedChanged BINDABLE bindableLoopSupported);
	Q_PROPERTY(bool shuffle READ default NOTIFY shuffleChanged BINDABLE bindableShuffle);
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

	[[nodiscard]] bool isPlaying() const { return this->bPlaybackState.value() == MprisPlaybackState::Playing; }
	void setPlaying(bool playing);
	void setPlaybackState(MprisPlaybackState::Enum state);

	[[nodiscard]] qreal position() const;
	void setPosition(qreal position);

	Q_INVOKABLE void play();
	Q_INVOKABLE void pause();
	Q_INVOKABLE void stop();
	Q_INVOKABLE void togglePlaying();
	Q_INVOKABLE void next();
	Q_INVOKABLE void previous();
	// Present for API compatibility; MediaRemote offers no seek/raise/quit.
	Q_INVOKABLE void seek(qreal /*offset*/) {}
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
	[[nodiscard]] QBindable<MprisPlaybackState::Enum> bindablePlaybackState() { return &this->bPlaybackState; }
	[[nodiscard]] QBindable<bool> bindablePositionSupported() { return &this->bPositionSupported; }
	[[nodiscard]] QBindable<qreal> bindableLength() { return &this->bLength; }
	[[nodiscard]] QBindable<bool> bindableLengthSupported() { return &this->bLengthSupported; }
	[[nodiscard]] QBindable<QVariantMap> bindableMetadata() { return &this->bMetadata; }
	[[nodiscard]] QBindable<QString> bindableTrackTitle() { return &this->bTrackTitle; }
	[[nodiscard]] QBindable<QString> bindableTrackArtist() { return &this->bTrackArtist; }
	[[nodiscard]] QBindable<QString> bindableTrackAlbum() { return &this->bTrackAlbum; }
	[[nodiscard]] QBindable<QString> bindableTrackArtUrl() { return &this->bTrackArtUrl; }
	[[nodiscard]] QBindable<qreal> bindableVolume() { return &this->bVolume; }
	[[nodiscard]] QBindable<bool> bindableVolumeSupported() { return &this->bVolumeSupported; }
	[[nodiscard]] QBindable<MprisLoopState::Enum> bindableLoopState() { return &this->bLoopState; }
	[[nodiscard]] QBindable<bool> bindableLoopSupported() { return &this->bLoopSupported; }
	[[nodiscard]] QBindable<bool> bindableShuffle() { return &this->bShuffle; }
	[[nodiscard]] QBindable<bool> bindableShuffleSupported() { return &this->bShuffleSupported; }

signals:
	void trackChanged();
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
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, bool, bLengthSupported, &MprisPlayer::lengthSupportedChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, QVariantMap, bMetadata, &MprisPlayer::metadataChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, QString, bTrackTitle, &MprisPlayer::trackTitleChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, QString, bTrackArtist, &MprisPlayer::trackArtistChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, QString, bTrackAlbum, &MprisPlayer::trackAlbumChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, QString, bTrackArtUrl, &MprisPlayer::trackArtUrlChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, qreal, bVolume, &MprisPlayer::volumeChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, bool, bVolumeSupported, &MprisPlayer::volumeSupportedChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, MprisLoopState::Enum, bLoopState, &MprisPlayer::loopStateChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, bool, bLoopSupported, &MprisPlayer::loopSupportedChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, bool, bShuffle, &MprisPlayer::shuffleChanged);
	Q_OBJECT_BINDABLE_PROPERTY(MprisPlayer, bool, bShuffleSupported, &MprisPlayer::shuffleSupportedChanged);
	// clang-format on
};

} // namespace qs::mac::mpris
