#include "coreaudio.hpp"

#include <CoreAudio/CoreAudio.h>
#include <CoreFoundation/CoreFoundation.h>

namespace qs::mac::pipewire::coreaudio {

namespace {

AudioObjectPropertyScope scopeFor(bool input) {
	return input ? kAudioObjectPropertyScopeInput : kAudioObjectPropertyScopeOutput;
}

QString cfStringProperty(AudioObjectID id, AudioObjectPropertySelector selector) {
	AudioObjectPropertyAddress addr =
	    {selector, kAudioObjectPropertyScopeGlobal, kAudioObjectPropertyElementMain};
	CFStringRef value = nullptr;
	UInt32 size = sizeof(value);
	if (AudioObjectGetPropertyData(id, &addr, 0, nullptr, &size, &value) != noErr || value == nullptr)
	{
		return {};
	}
	char buffer[512];
	QString out;
	if (CFStringGetCString(value, buffer, sizeof(buffer), kCFStringEncodingUTF8)) {
		out = QString::fromUtf8(buffer);
	}
	CFRelease(value);
	return out;
}

// Read one channel's (or the master's) scalar volume. Returns false if the
// element carries no volume control.
bool readChannelVolume(AudioObjectID id, bool input, UInt32 element, Float32* out) {
	AudioObjectPropertyAddress addr = {kAudioDevicePropertyVolumeScalar, scopeFor(input), element};
	if (!AudioObjectHasProperty(id, &addr)) return false;
	UInt32 size = sizeof(*out);
	return AudioObjectGetPropertyData(id, &addr, 0, nullptr, &size, out) == noErr;
}

// The active sub-devices of an AGGREGATE device; empty for ordinary ones.
// An aggregate (e.g. a speakers+loopback stack built for an audio
// visualizer) carries NO volume control itself - not on the master element,
// not per channel - the controls live on the real devices underneath. Both
// the system volume keys and a naive scalar read report nothing for them,
// which left the shell's volume at a lying 0%.
QList<quint32> subDevices(AudioObjectID id) {
	AudioObjectPropertyAddress addr = {
	    kAudioAggregateDevicePropertyActiveSubDeviceList,
	    kAudioObjectPropertyScopeGlobal,
	    kAudioObjectPropertyElementMain
	};
	if (!AudioObjectHasProperty(id, &addr)) return {};
	UInt32 size = 0;
	if (AudioObjectGetPropertyDataSize(id, &addr, 0, nullptr, &size) != noErr || size == 0) {
		return {};
	}
	QList<quint32> ids(static_cast<qsizetype>(size / sizeof(AudioObjectID)), 0);
	if (ids.isEmpty()) return {};
	if (AudioObjectGetPropertyData(id, &addr, 0, nullptr, &size, ids.data()) != noErr) return {};
	return ids;
}

} // namespace

QList<quint32> allDevices() {
	AudioObjectPropertyAddress addr = {
	    kAudioHardwarePropertyDevices,
	    kAudioObjectPropertyScopeGlobal,
	    kAudioObjectPropertyElementMain
	};
	UInt32 size = 0;
	if (AudioObjectGetPropertyDataSize(kAudioObjectSystemObject, &addr, 0, nullptr, &size) != noErr) {
		return {};
	}
	QList<quint32> ids(static_cast<qsizetype>(size / sizeof(AudioDeviceID)), 0);
	if (ids.isEmpty()) return {};
	if (AudioObjectGetPropertyData(kAudioObjectSystemObject, &addr, 0, nullptr, &size, ids.data())
	    != noErr)
	{
		return {};
	}
	return ids;
}

quint32 defaultDevice(bool input) {
	AudioObjectPropertyAddress addr = {
	    input ? kAudioHardwarePropertyDefaultInputDevice : kAudioHardwarePropertyDefaultOutputDevice,
	    kAudioObjectPropertyScopeGlobal,
	    kAudioObjectPropertyElementMain
	};
	AudioDeviceID device = kAudioObjectUnknown;
	UInt32 size = sizeof(device);
	AudioObjectGetPropertyData(kAudioObjectSystemObject, &addr, 0, nullptr, &size, &device);
	return device;
}

QString deviceName(quint32 id) { return cfStringProperty(id, kAudioObjectPropertyName); }
QString deviceUid(quint32 id) { return cfStringProperty(id, kAudioDevicePropertyDeviceUID); }

int channelCount(quint32 id, bool input) {
	AudioObjectPropertyAddress addr =
	    {kAudioDevicePropertyStreamConfiguration, scopeFor(input), kAudioObjectPropertyElementMain};
	UInt32 size = 0;
	if (AudioObjectGetPropertyDataSize(id, &addr, 0, nullptr, &size) != noErr || size == 0) return 0;

	auto* list = static_cast<AudioBufferList*>(malloc(size));
	if (list == nullptr) return 0;
	int channels = 0;
	if (AudioObjectGetPropertyData(id, &addr, 0, nullptr, &size, list) == noErr) {
		for (UInt32 i = 0; i < list->mNumberBuffers; i++) {
			channels += static_cast<int>(list->mBuffers[i].mNumberChannels);
		}
	}
	free(list);
	return channels;
}

float volume(quint32 id, bool input, bool* ok) {
	if (ok != nullptr) *ok = false;

	// Prefer the device's master volume; fall back to averaging the individual
	// channels, since not every device exposes a master control.
	Float32 value = 0.0;
	if (readChannelVolume(id, input, kAudioObjectPropertyElementMain, &value)) {
		if (ok != nullptr) *ok = true;
		return value;
	}

	int channels = channelCount(id, input);
	float sum = 0.0;
	int counted = 0;
	for (int channel = 1; channel <= channels; channel++) {
		Float32 chan = 0.0;
		if (readChannelVolume(id, input, static_cast<UInt32>(channel), &chan)) {
			sum += chan;
			counted++;
		}
	}
	if (counted > 0) {
		if (ok != nullptr) *ok = true;
		return sum / counted;
	}

	// Aggregate: report the first sub-device that has a real control (the
	// speakers; a loopback sub exposes none).
	for (auto sub: subDevices(id)) {
		bool subOk = false;
		float value = volume(sub, input, &subOk);
		if (subOk) {
			if (ok != nullptr) *ok = true;
			return value;
		}
	}
	return 0.0;
}

bool setVolume(quint32 id, bool input, float volume) {
	auto clamped = static_cast<Float32>(volume < 0.0 ? 0.0 : (volume > 1.0 ? 1.0 : volume));

	AudioObjectPropertyAddress master =
	    {kAudioDevicePropertyVolumeScalar, scopeFor(input), kAudioObjectPropertyElementMain};
	Boolean settable = false;
	if (AudioObjectHasProperty(id, &master)
	    && AudioObjectIsPropertySettable(id, &master, &settable) == noErr && settable)
	{
		return AudioObjectSetPropertyData(id, &master, 0, nullptr, sizeof(clamped), &clamped) == noErr;
	}

	// No settable master - write each channel instead.
	int channels = channelCount(id, input);
	bool any = false;
	for (int channel = 1; channel <= channels; channel++) {
		AudioObjectPropertyAddress addr =
		    {kAudioDevicePropertyVolumeScalar, scopeFor(input), static_cast<UInt32>(channel)};
		if (AudioObjectHasProperty(id, &addr)
		    && AudioObjectSetPropertyData(id, &addr, 0, nullptr, sizeof(clamped), &clamped) == noErr)
		{
			any = true;
		}
	}
	if (any) return true;

	// Aggregate: fan the write out to every sub-device that takes it.
	for (auto sub: subDevices(id)) {
		any = setVolume(sub, input, volume) || any;
	}
	return any;
}

bool muted(quint32 id, bool input, bool* ok) {
	if (ok != nullptr) *ok = false;
	AudioObjectPropertyAddress addr =
	    {kAudioDevicePropertyMute, scopeFor(input), kAudioObjectPropertyElementMain};
	if (!AudioObjectHasProperty(id, &addr)) {
		// Aggregate: the mute control lives on the sub-devices.
		for (auto sub: subDevices(id)) {
			bool subOk = false;
			bool value = muted(sub, input, &subOk);
			if (subOk) {
				if (ok != nullptr) *ok = true;
				return value;
			}
		}
		return false;
	}
	UInt32 value = 0;
	UInt32 size = sizeof(value);
	if (AudioObjectGetPropertyData(id, &addr, 0, nullptr, &size, &value) != noErr) return false;
	if (ok != nullptr) *ok = true;
	return value != 0;
}

bool setMuted(quint32 id, bool input, bool muted) {
	AudioObjectPropertyAddress addr =
	    {kAudioDevicePropertyMute, scopeFor(input), kAudioObjectPropertyElementMain};
	Boolean settable = false;
	if (!AudioObjectHasProperty(id, &addr)
	    || AudioObjectIsPropertySettable(id, &addr, &settable) != noErr || !settable)
	{
		// Aggregate: fan out to the sub-devices.
		bool any = false;
		for (auto sub: subDevices(id)) {
			any = setMuted(sub, input, muted) || any;
		}
		return any;
	}
	UInt32 value = muted ? 1 : 0;
	return AudioObjectSetPropertyData(id, &addr, 0, nullptr, sizeof(value), &value) == noErr;
}

} // namespace qs::mac::pipewire::coreaudio
