#include "node.hpp"

#include <qstring.h>
#include <qstringlist.h>

#include "coreaudio.hpp"

namespace qs::mac::pipewire {

QString PwAudioChannel::toString(PwAudioChannel::Enum value) {
	// Upstream's, string for string (node.cpp:40-88) - including "N/A" and
	// the 1-based Aux/Custom range formatting.
	switch (value) {
	case Unknown: return "Unknown";
	case NA: return "N/A";
	case Mono: return "Mono";
	case FrontCenter: return "Front Center";
	case FrontLeft: return "Front Left";
	case FrontRight: return "Front Right";
	case FrontLeftCenter: return "Front Left Center";
	case FrontRightCenter: return "Front Right Center";
	case FrontLeftWide: return "Front Left Wide";
	case FrontRightWide: return "Front Right Wide";
	case FrontCenterHigh: return "Front Center High";
	case FrontLeftHigh: return "Front Left High";
	case FrontRightHigh: return "Front Right High";
	case LowFrequencyEffects: return "Low Frequency Effects";
	case LowFrequencyEffects2: return "Low Frequency Effects 2";
	case LowFrequencyEffectsLeft: return "Low Frequency Effects Left";
	case LowFrequencyEffectsRight: return "Low Frequency Effects Right";
	case SideLeft: return "Side Left";
	case SideRight: return "Side Right";
	case RearCenter: return "Rear Center";
	case RearLeft: return "Rear Left";
	case RearRight: return "Rear Right";
	case RearLeftCenter: return "Rear Left Center";
	case RearRightCenter: return "Rear Right Center";
	case TopCenter: return "Top Center";
	case TopFrontCenter: return "Top Front Center";
	case TopFrontLeft: return "Top Front Left";
	case TopFrontRight: return "Top Front Right";
	case TopFrontLeftCenter: return "Top Front Left Center";
	case TopFrontRightCenter: return "Top Front Right Center";
	case TopSideLeft: return "Top Side Left";
	case TopSideRight: return "Top Side Right";
	case TopRearCenter: return "Top Rear Center";
	case TopRearLeft: return "Top Rear Left";
	case TopRearRight: return "Top Rear Right";
	case BottomCenter: return "Bottom Center";
	case BottomLeftCenter: return "Bottom Left Center";
	case BottomRightCenter: return "Bottom Right Center";
	default:
		if (value >= AuxRangeStart && value <= AuxRangeEnd) {
			return QString("Aux %1").arg(value - AuxRangeStart + 1);
		} else if (value >= CustomRangeStart) {
			return QString("Custom %1").arg(value - CustomRangeStart + 1);
		} else {
			return "Unknown";
		}
	}
}

QString PwNodeType::toString(PwNodeType::Flags type) {
	QStringList parts;
	if (type.testFlag(Audio)) parts << "Audio";
	if (type.testFlag(Video)) parts << "Video";
	if (type.testFlag(Stream)) parts << "Stream";
	if (type.testFlag(Source)) parts << "Source";
	if (type.testFlag(Sink)) parts << "Sink";
	return parts.isEmpty() ? "Untracked" : parts.join(" | ");
}

// Map a CoreAudio channel count to plausible channel positions - mono, stereo,
// or a generic front-left/right plus extras. Only used for the `channels`
// property; volume is applied uniformly regardless.
static QVector<PwAudioChannel::Enum> channelsForCount(int count) {
	if (count <= 0) return {};
	if (count == 1) return {PwAudioChannel::Mono};
	QVector<PwAudioChannel::Enum> channels {PwAudioChannel::FrontLeft, PwAudioChannel::FrontRight};
	for (int i = 2; i < count; i++) channels << PwAudioChannel::Unknown;
	return channels;
}

PwNodeAudio::PwNodeAudio(quint32 deviceId, bool input, QObject* parent)
    : QObject(parent)
    , mDeviceId(deviceId)
    , mInput(input) {
	this->mChannels = channelsForCount(coreaudio::channelCount(deviceId, input));
	this->refresh();
}

void PwNodeAudio::refresh() {
	bool volumeOk = false;
	auto volume = coreaudio::volume(this->mDeviceId, this->mInput, &volumeOk);
	bool muteOk = false;
	auto muted = coreaudio::muted(this->mDeviceId, this->mInput, &muteOk);

	if (volumeOk && !qFuzzyCompare(volume, this->mVolume)) {
		this->mVolume = volume;
		emit this->volumesChanged();
	}
	if (muteOk && muted != this->mMuted) {
		this->mMuted = muted;
		emit this->mutedChanged();
	}
}

void PwNodeAudio::setMuted(bool muted) {
	if (coreaudio::setMuted(this->mDeviceId, this->mInput, muted)) {
		if (muted != this->mMuted) {
			this->mMuted = muted;
			emit this->mutedChanged();
		}
	}
}

void PwNodeAudio::setAverageVolume(float volume) {
	if (coreaudio::setVolume(this->mDeviceId, this->mInput, volume)) {
		if (!qFuzzyCompare(volume, this->mVolume)) {
			this->mVolume = volume;
			emit this->volumesChanged();
		}
	}
}

QVector<float> PwNodeAudio::volumes() const {
	// CoreAudio is driven here through a single average scalar, so report the
	// same value for every channel - matching what the average setter applies.
	return QVector<float>(this->mChannels.size(), this->mVolume);
}

void PwNodeAudio::setVolumes(const QVector<float>& volumes) {
	if (volumes.isEmpty()) return;
	float sum = 0.0;
	for (auto v: volumes) sum += v;
	this->setAverageVolume(sum / volumes.size());
}

PwNode::PwNode(quint32 deviceId, bool input, QObject* parent)
    : QObject(parent)
    // A duplex device reports one AudioObjectID for both directions; fold the
    // direction into the exposed id so its source and sink are distinct objects
    // (PipeWire node ids are unique). mDeviceId keeps the real id for CoreAudio.
    // Matches the low bits of the service's keyOf, by construction.
    , mId((deviceId << 1) | (input ? 1U : 0U))
    , mDeviceId(deviceId)
    , mInput(input) {
	this->mName = coreaudio::deviceName(deviceId);
	this->mDescription = this->mName;
	this->mNickname = this->mName;

	auto uid = coreaudio::deviceUid(deviceId);
	this->mProperties["node.name"] = this->mName;
	this->mProperties["node.description"] = this->mName;
	this->mProperties["device.uid"] = uid;
	this->mProperties["media.class"] = input ? QString("Audio/Source") : QString("Audio/Sink");

	this->mAudio = new PwNodeAudio(deviceId, input, this);
}

PwNodeType::Flags PwNode::type() const {
	return this->mInput ? PwNodeType::AudioSource : PwNodeType::AudioSink;
}

} // namespace qs::mac::pipewire
