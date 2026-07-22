#pragma once

#include <qobject.h>
#include <qproperty.h>
#include <qqmlintegration.h>
#include <qtimer.h>
#include <qtmetamacros.h>

#include "../../core/doc.hpp"
#include "../../core/model.hpp"
#include "device.hpp"

using CFRunLoopSourceRef = struct __CFRunLoopSource*;

namespace qs::mac::upower {

// Backend singleton reading battery state from IOKit power sources. Refreshes
// on the system's power-source change notification (plus a slow timer so time
// estimates stay fresh) and updates the display device and the device model.
// Not a QML type - the UPower facade forwards to it.
class UPower: public QObject {
	Q_OBJECT;

public:
	static UPower* instance();

	[[nodiscard]] UPowerDevice* displayDevice() { return &this->mDisplayDevice; }
	[[nodiscard]] ObjectModel<UPowerDevice>* devices() { return &this->mDevices; }
	[[nodiscard]] QBindable<bool> bindableOnBattery() { return &this->bOnBattery; }

signals:
	void onBatteryChanged();

private:
	explicit UPower();

	void refresh();

	UPowerDevice mDisplayDevice {this};
	UPowerDevice* mBattery = nullptr; // the one entry in mDevices, when present
	ObjectModel<UPowerDevice> mDevices {this};
	QTimer mPollTimer;
	CFRunLoopSourceRef mRunLoopSource = nullptr;

	Q_OBJECT_BINDABLE_PROPERTY(UPower, bool, bOnBattery, &UPower::onBatteryChanged);
};

///! Provides access to the system battery and power state.
/// The macOS counterpart of the Linux `UPower` service, backed by IOKit power
/// sources instead of the UPower daemon. Same QML surface so DMS's battery
/// widget binds unchanged.
class UPowerQml: public QObject {
	Q_OBJECT;
	// clang-format off
	/// The aggregate display device for your system. Cannot be null, but might
	/// not be initialized (check @@UPowerDevice.ready if you need to know).
	Q_PROPERTY(qs::mac::upower::UPowerDevice* displayDevice READ displayDevice CONSTANT);
	/// All connected power devices (on macOS, the internal battery when present).
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::upower::UPowerDevice>*);
	Q_PROPERTY(UntypedObjectModel* devices READ devices CONSTANT);
	/// If the system is currently running on battery power, or discharging.
	Q_PROPERTY(bool onBattery READ default NOTIFY onBatteryChanged BINDABLE bindableOnBattery);
	// clang-format on
	QML_NAMED_ELEMENT(UPower);
	QML_SINGLETON;

public:
	explicit UPowerQml(QObject* parent = nullptr);

	[[nodiscard]] UPowerDevice* displayDevice() { return UPower::instance()->displayDevice(); }
	[[nodiscard]] UntypedObjectModel* devices() { return UPower::instance()->devices(); }
	[[nodiscard]] static QBindable<bool> bindableOnBattery() {
		return UPower::instance()->bindableOnBattery();
	}

signals:
	void onBatteryChanged();
};

} // namespace qs::mac::upower
