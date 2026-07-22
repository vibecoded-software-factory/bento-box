#include "service.hpp"

#include <CoreAudio/CoreAudio.h>
#include <qset.h>

#include "coreaudio.hpp"
#include "node.hpp"

namespace qs::mac::pipewire {

namespace {

Pipewire* sInstance = nullptr;

quint64 keyOf(quint32 deviceId, bool input) {
	return (static_cast<quint64>(deviceId) << 1) | (input ? 1 : 0);
}

// CoreAudio delivers property notifications on its own HAL thread, so bounce
// back onto the main thread before touching Qt objects.
OSStatus listenerProc(
    AudioObjectID /*object*/,
    UInt32 /*count*/,
    const AudioObjectPropertyAddress* /*addresses*/,
    void* context
) {
	auto* pw = static_cast<Pipewire*>(context);
	QMetaObject::invokeMethod(pw, [pw]() { pw->update(); }, Qt::QueuedConnection);
	return noErr;
}

void listen(
    AudioObjectID object,
    AudioObjectPropertySelector selector,
    AudioObjectPropertyScope scope,
    void* context,
    bool add
) {
	AudioObjectPropertyAddress addr = {selector, scope, kAudioObjectPropertyElementMain};
	if (add) AudioObjectAddPropertyListener(object, &addr, listenerProc, context);
	else AudioObjectRemovePropertyListener(object, &addr, listenerProc, context);
}

} // namespace

Pipewire* Pipewire::instance() { return sInstance; }

Pipewire::Pipewire(QObject* parent): QObject(parent) {
	sInstance = this;
	this->setListeners(true);
	this->update();
}

Pipewire::~Pipewire() {
	this->setListeners(false);
	if (this->mListenedSink != 0) this->setDeviceVolumeListeners(this->mListenedSink, false, false);
	if (this->mListenedSource != 0)
		this->setDeviceVolumeListeners(this->mListenedSource, true, false);
	if (sInstance == this) sInstance = nullptr;
}

void Pipewire::setListeners(bool add) {
	// System-level: device list and the two default-device selectors.
	listen(
	    kAudioObjectSystemObject,
	    kAudioHardwarePropertyDevices,
	    kAudioObjectPropertyScopeGlobal,
	    this,
	    add
	);
	listen(
	    kAudioObjectSystemObject,
	    kAudioHardwarePropertyDefaultOutputDevice,
	    kAudioObjectPropertyScopeGlobal,
	    this,
	    add
	);
	listen(
	    kAudioObjectSystemObject,
	    kAudioHardwarePropertyDefaultInputDevice,
	    kAudioObjectPropertyScopeGlobal,
	    this,
	    add
	);
}

void Pipewire::setDeviceVolumeListeners(quint32 deviceId, bool input, bool add) {
	auto scope = input ? kAudioObjectPropertyScopeInput : kAudioObjectPropertyScopeOutput;
	listen(deviceId, kAudioDevicePropertyVolumeScalar, scope, this, add);
	listen(deviceId, kAudioDevicePropertyMute, scope, this, add);
}

PwNode* Pipewire::findNode(quint32 deviceId, bool input) const {
	return this->mByKey.value(keyOf(deviceId, input), nullptr);
}

void Pipewire::update() {
	// Reconcile the node model against the current device list.
	QSet<quint64> present;
	for (auto deviceId: coreaudio::allDevices()) {
		for (bool input: {false, true}) {
			if (coreaudio::channelCount(deviceId, input) <= 0) continue;
			auto key = keyOf(deviceId, input);
			present.insert(key);
			if (!this->mByKey.contains(key)) {
				auto* node = new PwNode(deviceId, input, this);
				this->mByKey.insert(key, node);
				this->mNodes.insertObject(node);
			}
		}
	}

	for (auto key: this->mByKey.keys()) {
		if (present.contains(key)) continue;
		auto* node = this->mByKey.take(key);
		this->mNodes.removeObject(node);
		node->deleteLater();
	}

	// Pick up any external volume/mute change on the nodes we still have.
	for (auto* node: this->mByKey.values()) node->refresh();

	// Resolve the default sink/source, re-homing the per-device listeners when
	// the default moves.
	auto outId = coreaudio::defaultDevice(false);
	auto* newSink = this->findNode(outId, false);
	if (newSink != this->mDefaultSink) {
		if (this->mListenedSink != 0) this->setDeviceVolumeListeners(this->mListenedSink, false, false);
		this->mDefaultSink = newSink;
		this->mListenedSink = newSink != nullptr ? outId : 0;
		if (this->mListenedSink != 0) this->setDeviceVolumeListeners(outId, false, true);
		emit this->defaultAudioSinkChanged();
	}

	auto inId = coreaudio::defaultDevice(true);
	auto* newSource = this->findNode(inId, true);
	if (newSource != this->mDefaultSource) {
		if (this->mListenedSource != 0)
			this->setDeviceVolumeListeners(this->mListenedSource, true, false);
		this->mDefaultSource = newSource;
		this->mListenedSource = newSource != nullptr ? inId : 0;
		if (this->mListenedSource != 0) this->setDeviceVolumeListeners(inId, true, true);
		emit this->defaultAudioSourceChanged();
	}

	if (!this->mReady) {
		this->mReady = true;
		emit this->readyChanged();
	}
}

void Pipewire::setPreferredDefaultAudioSink(PwNode* node) {
	if (node == nullptr) return;
	AudioObjectPropertyAddress addr = {
	    kAudioHardwarePropertyDefaultOutputDevice,
	    kAudioObjectPropertyScopeGlobal,
	    kAudioObjectPropertyElementMain
	};
	auto device = static_cast<AudioDeviceID>(node->deviceId());
	AudioObjectSetPropertyData(kAudioObjectSystemObject, &addr, 0, nullptr, sizeof(device), &device);
}

void Pipewire::setPreferredDefaultAudioSource(PwNode* node) {
	if (node == nullptr) return;
	AudioObjectPropertyAddress addr = {
	    kAudioHardwarePropertyDefaultInputDevice,
	    kAudioObjectPropertyScopeGlobal,
	    kAudioObjectPropertyElementMain
	};
	auto device = static_cast<AudioDeviceID>(node->deviceId());
	AudioObjectSetPropertyData(kAudioObjectSystemObject, &addr, 0, nullptr, sizeof(device), &device);
}

} // namespace qs::mac::pipewire
