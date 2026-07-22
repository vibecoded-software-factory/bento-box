#pragma once

#include <qlist.h>
#include <qstring.h>
#include <qtypes.h>

// Thin CoreAudio helpers shared by the node and service. Devices are identified
// by their AudioObjectID (a quint32) so this header stays free of CoreAudio
// includes; the .cpp does the framework work. "input" selects the input scope
// (a source/microphone) versus the output scope (a sink/speaker).
namespace qs::mac::pipewire::coreaudio {

QList<quint32> allDevices();
quint32 defaultDevice(bool input);

QString deviceName(quint32 id);
QString deviceUid(quint32 id);
// Number of channels the device carries in the given scope (0 means the device
// does not operate in that scope - e.g. a microphone has 0 output channels).
int channelCount(quint32 id, bool input);

// Volume is an average scalar 0.0-1.0; mute is a bool. Getters return false in
// `ok` when the device exposes no such control.
float volume(quint32 id, bool input, bool* ok = nullptr);
bool setVolume(quint32 id, bool input, float volume);
bool muted(quint32 id, bool input, bool* ok = nullptr);
bool setMuted(quint32 id, bool input, bool muted);

} // namespace qs::mac::pipewire::coreaudio
