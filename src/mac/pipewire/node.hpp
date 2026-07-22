#pragma once

#include <qobject.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>
#include <qtypes.h>
#include <qvariant.h>
#include <qvector.h>

namespace qs::mac::pipewire {

///! An audio channel position.
/// A subset of PipeWire's channel positions - the ones macOS audio devices
/// actually report. Values match PipeWire's for the shared channels.
class PwAudioChannel: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_SINGLETON;

public:
	enum Enum {
		Unknown = 0,
		NA = 1,
		Mono = 2,
		FrontLeft = 3,
		FrontRight = 4,
		FrontCenter = 5,
		LowFrequencyEffects = 6,
		SideLeft = 7,
		SideRight = 8,
	};
	Q_ENUM(Enum);

	Q_INVOKABLE static QString toString(qs::mac::pipewire::PwAudioChannel::Enum channel);
};

///! The type of a pipewire node, as a set of flags.
class PwNodeType: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_SINGLETON;

public:
	enum Flag : quint8 {
		Untracked = 0b0,
		Audio = 0b1,
		Video = 0b10,
		Stream = 0b100,
		Source = 0b1000,
		Sink = 0b10000,
		AudioSink = Audio | Sink,
		AudioSource = Audio | Source,
		AudioDuplex = Audio | Sink | Source,
		AudioOutStream = Audio | Sink | Stream,
		AudioInStream = Audio | Source | Stream,
		VideoSource = Video | Source,
		VideoSink = Video | Sink,
	};
	Q_ENUM(Flag);
	Q_DECLARE_FLAGS(Flags, Flag);
	Q_INVOKABLE static QString toString(qs::mac::pipewire::PwNodeType::Flags type);
};

///! Audio specific properties of pipewire nodes.
/// Extra properties of a @@PwNode if the node is an audio node, backed by the
/// underlying CoreAudio device's volume and mute controls.
class PwNodeAudio: public QObject {
	Q_OBJECT;
	// clang-format off
	/// If the node is currently muted. Setting this property changes the mute state.
	Q_PROPERTY(bool muted READ isMuted WRITE setMuted NOTIFY mutedChanged);
	/// The average volume over all channels of the node, from `0.0` to `1.0`.
	/// Setting this property modifies the volume of all channels.
	Q_PROPERTY(float volume READ averageVolume WRITE setAverageVolume NOTIFY volumesChanged);
	/// The audio channels present on the node.
	Q_PROPERTY(QVector<qs::mac::pipewire::PwAudioChannel::Enum> channels READ channels NOTIFY channelsChanged);
	/// The volumes of each audio channel individually.
	Q_PROPERTY(QVector<float> volumes READ volumes WRITE setVolumes NOTIFY volumesChanged);
	// clang-format on
	QML_NAMED_ELEMENT(PwNodeAudio);
	QML_UNCREATABLE("PwNodeAudio cannot be created directly");

public:
	// deviceId is the CoreAudio AudioObjectID; input selects the source scope.
	explicit PwNodeAudio(quint32 deviceId, bool input, QObject* parent);

	[[nodiscard]] bool isMuted() const { return this->mMuted; }
	void setMuted(bool muted);

	[[nodiscard]] float averageVolume() const { return this->mVolume; }
	void setAverageVolume(float volume);

	[[nodiscard]] QVector<PwAudioChannel::Enum> channels() const { return this->mChannels; }

	[[nodiscard]] QVector<float> volumes() const;
	void setVolumes(const QVector<float>& volumes);

	// Re-read volume/mute from CoreAudio (called on the device's change listener)
	// and emit whatever changed.
	void refresh();

signals:
	void mutedChanged();
	void channelsChanged();
	void volumesChanged();

private:
	quint32 mDeviceId;
	bool mInput;
	bool mMuted = false;
	float mVolume = 0.0;
	QVector<PwAudioChannel::Enum> mChannels;
};

///! A node in the audio graph.
/// The macOS counterpart of a PipeWire node, backed by a CoreAudio device.
class PwNode: public QObject {
	Q_OBJECT;
	// clang-format off
	/// The object id of the node (the CoreAudio device id).
	Q_PROPERTY(quint32 id READ id CONSTANT);
	/// The node's name.
	Q_PROPERTY(QString name READ name CONSTANT);
	/// The node's description. Generally more human readable than @@name.
	Q_PROPERTY(QString description READ description CONSTANT);
	/// The node's nickname.
	Q_PROPERTY(QString nickname READ nickname CONSTANT);
	/// If `true`, the node accepts audio input from other nodes (a sink/output).
	Q_PROPERTY(bool isSink READ isSink CONSTANT);
	/// If `true` the node is a program stream, if `false` a hardware device.
	Q_PROPERTY(bool isStream READ isStream CONSTANT);
	/// The type of this node.
	Q_PROPERTY(qs::mac::pipewire::PwNodeType::Flags type READ type CONSTANT);
	/// The property set present on the node, as key-value pairs.
	Q_PROPERTY(QVariantMap properties READ properties CONSTANT);
	/// Extra information present only if the node sends or receives audio.
	Q_PROPERTY(qs::mac::pipewire::PwNodeAudio* audio READ audio CONSTANT);
	/// True if the node is fully bound and ready to use. Always true on macOS.
	Q_PROPERTY(bool ready READ isReady NOTIFY readyChanged);
	// clang-format on
	QML_NAMED_ELEMENT(PwNode);
	QML_UNCREATABLE("PwNodes cannot be created directly");

public:
	explicit PwNode(quint32 deviceId, bool input, QObject* parent = nullptr);

	[[nodiscard]] quint32 id() const { return this->mId; }
	[[nodiscard]] QString name() const { return this->mName; }
	[[nodiscard]] QString description() const { return this->mDescription; }
	[[nodiscard]] QString nickname() const { return this->mNickname; }
	[[nodiscard]] bool isSink() const { return !this->mInput; }
	[[nodiscard]] bool isStream() const { return false; }
	[[nodiscard]] bool isReady() const { return true; }
	[[nodiscard]] PwNodeType::Flags type() const;
	[[nodiscard]] QVariantMap properties() const { return this->mProperties; }
	[[nodiscard]] PwNodeAudio* audio() const { return this->mAudio; }

	[[nodiscard]] bool input() const { return this->mInput; }
	void refresh() {
		if (this->mAudio != nullptr) this->mAudio->refresh();
	}

signals:
	void readyChanged();

private:
	quint32 mId;
	bool mInput;
	QString mName;
	QString mDescription;
	QString mNickname;
	QVariantMap mProperties;
	PwNodeAudio* mAudio = nullptr;
};

} // namespace qs::mac::pipewire

Q_DECLARE_OPERATORS_FOR_FLAGS(qs::mac::pipewire::PwNodeType::Flags)
