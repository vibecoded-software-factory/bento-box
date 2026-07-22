#include "service.hpp"

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/ps/IOPSKeys.h>
#include <IOKit/ps/IOPowerSources.h>
#include <qstring.h>
#include <qvariant.h>

#include "device.hpp"

namespace qs::mac::upower {

namespace {

// Small CoreFoundation readers - a battery dictionary mixes CFNumber, CFBoolean
// and CFString values, so pull each out defensively (missing/typemismatched
// keys return the fallback rather than crashing).
int cfInt(CFDictionaryRef dict, CFStringRef key, int fallback = 0) {
	auto value = static_cast<CFNumberRef>(CFDictionaryGetValue(dict, key));
	int out = fallback;
	if (value && CFGetTypeID(value) == CFNumberGetTypeID())
		CFNumberGetValue(value, kCFNumberIntType, &out);
	return out;
}

bool cfBool(CFDictionaryRef dict, CFStringRef key, bool fallback = false) {
	auto value = static_cast<CFBooleanRef>(CFDictionaryGetValue(dict, key));
	if (value && CFGetTypeID(value) == CFBooleanGetTypeID()) return CFBooleanGetValue(value);
	return fallback;
}

QString cfString(CFDictionaryRef dict, CFStringRef key) {
	auto value = static_cast<CFStringRef>(CFDictionaryGetValue(dict, key));
	if (!value || CFGetTypeID(value) != CFStringGetTypeID()) return {};
	char buffer[256];
	if (CFStringGetCString(value, buffer, sizeof(buffer), kCFStringEncodingUTF8)) {
		return QString::fromUtf8(buffer);
	}
	return {};
}

// A freedesktop-style icon name so the property carries something meaningful,
// matching what UPower would report on Linux.
QString batteryIcon(bool present, bool charging, UPowerDeviceState::Enum state, qreal pct) {
	if (!present) return "battery-missing-symbolic";
	if (state == UPowerDeviceState::FullyCharged) return "battery-full-charged-symbolic";
	const char* level = pct < 0.10 ? "empty"
	                  : pct < 0.30 ? "caution"
	                  : pct < 0.55 ? "low"
	                  : pct < 0.85 ? "good"
	                               : "full";
	return QString("battery-%1%2-symbolic").arg(level, charging ? "-charging" : "");
}

// Enrich the snapshot with energy/health/model from AppleSmartBattery, which
// IOPowerSources does not expose. Absent on desktops - the fields simply stay
// unset (0 / empty) and healthSupported binds to false.
void readSmartBattery(QVariantMap& snapshot) {
	auto service =
	    IOServiceGetMatchingService(kIOMainPortDefault, IOServiceMatching("AppleSmartBattery"));
	if (service == MACH_PORT_NULL) return;

	CFMutableDictionaryRef props = nullptr;
	if (IORegistryEntryCreateCFProperties(service, &props, kCFAllocatorDefault, 0) == KERN_SUCCESS
	    && props != nullptr)
	{
		auto dict = static_cast<CFDictionaryRef>(props);
		auto voltage = cfInt(dict, CFSTR("Voltage"));                    // mV
		auto amperage = cfInt(dict, CFSTR("Amperage"));                  // mA, signed
		auto rawCurrent = cfInt(dict, CFSTR("AppleRawCurrentCapacity")); // mAh
		auto rawMax = cfInt(dict, CFSTR("AppleRawMaxCapacity"));         // mAh
		auto design = cfInt(dict, CFSTR("DesignCapacity"));              // mAh

		if (voltage > 0) {
			// Wh = mAh * mV / 1e6; W = mA * mV / 1e6.
			snapshot["energy"] = rawCurrent * voltage / 1.0e6;
			snapshot["energyCapacity"] = rawMax * voltage / 1.0e6;
			snapshot["changeRate"] = amperage * voltage / 1.0e6;
		}
		if (design > 0 && rawMax > 0) snapshot["healthPercentage"] = rawMax * 100.0 / design;
		auto model = cfString(dict, CFSTR("DeviceName"));
		if (!model.isEmpty()) snapshot["model"] = model;

		CFRelease(props);
	}
	IOObjectRelease(service);
}

} // namespace

UPower* UPower::instance() {
	static UPower* instance = new UPower(); // NOLINT
	return instance;
}

UPower::UPower() {
	// Refresh on the system notification, and slowly on a timer so time-to-empty
	// / time-to-full keep ticking even when nothing else changes.
	this->mRunLoopSource = IOPSNotificationCreateRunLoopSource(
	    [](void* context) { static_cast<UPower*>(context)->refresh(); },
	    this
	);
	if (this->mRunLoopSource != nullptr) {
		CFRunLoopAddSource(CFRunLoopGetMain(), this->mRunLoopSource, kCFRunLoopDefaultMode);
	}

	this->mPollTimer.setInterval(10000);
	QObject::connect(&this->mPollTimer, &QTimer::timeout, this, &UPower::refresh);
	this->mPollTimer.start();

	this->refresh();
}

void UPower::refresh() {
	QVariantMap snapshot;
	bool present = false;
	bool onBattery = false;

	CFTypeRef blob = IOPSCopyPowerSourcesInfo();
	if (blob != nullptr) {
		CFArrayRef list = IOPSCopyPowerSourcesList(blob);
		if (list != nullptr) {
			for (CFIndex i = 0; i < CFArrayGetCount(list); i++) {
				auto source = CFArrayGetValueAtIndex(list, i);
				auto desc = IOPSGetPowerSourceDescription(blob, source);
				if (desc == nullptr) continue;

				auto type = cfString(desc, CFSTR(kIOPSTypeKey));
				if (type != kIOPSInternalBatteryType) continue; // only the internal battery

				present = cfBool(desc, CFSTR(kIOPSIsPresentKey), true);
				auto current = cfInt(desc, CFSTR(kIOPSCurrentCapacityKey));
				auto max = cfInt(desc, CFSTR(kIOPSMaxCapacityKey), 100);
				auto charging = cfBool(desc, CFSTR(kIOPSIsChargingKey));
				auto psState = cfString(desc, CFSTR(kIOPSPowerSourceStateKey));
				auto tte = cfInt(desc, CFSTR(kIOPSTimeToEmptyKey), -1);
				auto ttf = cfInt(desc, CFSTR(kIOPSTimeToFullChargeKey), -1);

				onBattery = psState == QString::fromUtf8(kIOPSBatteryPowerValue);
				qreal pct = max > 0 ? static_cast<qreal>(current) / max : 0.0;

				UPowerDeviceState::Enum state;
				if (charging) state = UPowerDeviceState::Charging;
				else if (onBattery) state = UPowerDeviceState::Discharging;
				else state = UPowerDeviceState::FullyCharged;

				snapshot["type"] = UPowerDeviceType::Battery;
				snapshot["powerSupply"] = true;
				snapshot["isPresent"] = present;
				snapshot["percentage"] = pct;
				snapshot["state"] = state;
				// IOKit reports minutes (-1 = still calculating); UPower uses seconds
				// and 0 for the direction that does not apply.
				snapshot["timeToEmpty"] = (!charging && tte > 0) ? tte * 60.0 : 0.0;
				snapshot["timeToFull"] = (charging && ttf > 0) ? ttf * 60.0 : 0.0;
				snapshot["nativePath"] = cfString(desc, CFSTR(kIOPSNameKey));
				snapshot["iconName"] = batteryIcon(present, charging, state, pct);
				break;
			}
			CFRelease(list);
		}
		CFRelease(blob);
	}

	if (present) readSmartBattery(snapshot);

	this->bOnBattery = onBattery;
	this->mDisplayDevice.updateFromSnapshot(snapshot);

	if (present) {
		if (this->mBattery == nullptr) {
			this->mBattery = new UPowerDevice(this);
			this->mBattery->updateFromSnapshot(snapshot);
			this->mDevices.insertObject(this->mBattery);
		} else {
			this->mBattery->updateFromSnapshot(snapshot);
		}
	} else if (this->mBattery != nullptr) {
		this->mDevices.removeObject(this->mBattery);
		this->mBattery->deleteLater();
		this->mBattery = nullptr;
	}
}

UPowerQml::UPowerQml(QObject* parent): QObject(parent) {
	QObject::connect(
	    UPower::instance(),
	    &UPower::onBatteryChanged,
	    this,
	    &UPowerQml::onBatteryChanged
	);
}

} // namespace qs::mac::upower
