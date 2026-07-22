#include "device.hpp"

#include <qstring.h>
#include <qvariant.h>

namespace qs::mac::upower {

QString UPowerDeviceState::toString(UPowerDeviceState::Enum status) {
	switch (status) {
	case UPowerDeviceState::Unknown: return "Unknown";
	case UPowerDeviceState::Charging: return "Charging";
	case UPowerDeviceState::Discharging: return "Discharging";
	case UPowerDeviceState::Empty: return "Empty";
	case UPowerDeviceState::FullyCharged: return "Fully Charged";
	case UPowerDeviceState::PendingCharge: return "Pending Charge";
	case UPowerDeviceState::PendingDischarge: return "Pending Discharge";
	default: return "Invalid Status";
	}
}

QString UPowerDeviceType::toString(UPowerDeviceType::Enum type) {
	switch (type) {
	case UPowerDeviceType::Unknown: return "Unknown";
	case UPowerDeviceType::LinePower: return "Line Power";
	case UPowerDeviceType::Battery: return "Battery";
	case UPowerDeviceType::Ups: return "Ups";
	case UPowerDeviceType::Monitor: return "Monitor";
	case UPowerDeviceType::Mouse: return "Mouse";
	case UPowerDeviceType::Keyboard: return "Keyboard";
	case UPowerDeviceType::Pda: return "Pda";
	case UPowerDeviceType::Phone: return "Phone";
	case UPowerDeviceType::MediaPlayer: return "Media Player";
	case UPowerDeviceType::Tablet: return "Tablet";
	case UPowerDeviceType::Computer: return "Computer";
	case UPowerDeviceType::GamingInput: return "Gaming Input";
	case UPowerDeviceType::Pen: return "Pen";
	case UPowerDeviceType::Touchpad: return "Touchpad";
	case UPowerDeviceType::Modem: return "Modem";
	case UPowerDeviceType::Network: return "Network";
	case UPowerDeviceType::Headset: return "Headset";
	case UPowerDeviceType::Speakers: return "Speakers";
	case UPowerDeviceType::Headphones: return "Headphones";
	case UPowerDeviceType::Video: return "Video";
	case UPowerDeviceType::OtherAudio: return "Other Audio";
	case UPowerDeviceType::RemoteControl: return "Remote Control";
	case UPowerDeviceType::Printer: return "Printer";
	case UPowerDeviceType::Scanner: return "Scanner";
	case UPowerDeviceType::Camera: return "Camera";
	case UPowerDeviceType::Wearable: return "Wearable";
	case UPowerDeviceType::Toy: return "Toy";
	case UPowerDeviceType::BluetoothGeneric: return "Bluetooth Generic";
	default: return "Invalid Type";
	}
}

UPowerDevice::UPowerDevice(QObject* parent): QObject(parent) {
	// Same derived bindings as the Linux service, so the two behave identically.
	this->bIsLaptopBattery.setBinding([this]() {
		return this->bType.value() == UPowerDeviceType::Battery && this->bPowerSupply.value();
	});
	this->bHealthSupported.setBinding([this]() { return this->bHealthPercentage.value() != 0; });
}

void UPowerDevice::updateFromSnapshot(const QVariantMap& s) {
	auto has = [&](const char* k) { return s.contains(k); };
	if (has("type")) this->bType = static_cast<UPowerDeviceType::Enum>(s.value("type").toUInt());
	if (has("powerSupply")) this->bPowerSupply = s.value("powerSupply").toBool();
	if (has("energy")) this->bEnergy = s.value("energy").toReal();
	if (has("energyCapacity")) this->bEnergyCapacity = s.value("energyCapacity").toReal();
	if (has("changeRate")) this->bChangeRate = s.value("changeRate").toReal();
	if (has("timeToEmpty")) this->bTimeToEmpty = s.value("timeToEmpty").toReal();
	if (has("timeToFull")) this->bTimeToFull = s.value("timeToFull").toReal();
	if (has("percentage")) this->bPercentage = s.value("percentage").toReal();
	if (has("isPresent")) this->bIsPresent = s.value("isPresent").toBool();
	if (has("state")) this->bState = static_cast<UPowerDeviceState::Enum>(s.value("state").toUInt());
	if (has("healthPercentage")) this->bHealthPercentage = s.value("healthPercentage").toReal();
	if (has("iconName")) this->bIconName = s.value("iconName").toString();
	if (has("nativePath")) this->bNativePath = s.value("nativePath").toString();
	if (has("model")) this->bModel = s.value("model").toString();
	this->bReady = true;
}

} // namespace qs::mac::upower
