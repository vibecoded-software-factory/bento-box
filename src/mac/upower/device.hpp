#pragma once

#include <qobject.h>
#include <qproperty.h>
#include <qqmlintegration.h>
#include <qtmetamacros.h>
#include <qtypes.h>
#include <qvariant.h>

namespace qs::mac::upower {

///! Power state of a UPower device.
/// See @@UPowerDevice.state.
class UPowerDeviceState: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_SINGLETON;

public:
	enum Enum : quint8 {
		Unknown = 0,
		Charging = 1,
		Discharging = 2,
		Empty = 3,
		FullyCharged = 4,
		/// The device is waiting to be charged after it was plugged in.
		PendingCharge = 5,
		/// The device is waiting to be discharged after being unplugged.
		PendingDischarge = 6,
	};
	Q_ENUM(Enum);

	Q_INVOKABLE static QString toString(qs::mac::upower::UPowerDeviceState::Enum status);
};

///! Type of a UPower device.
/// See @@UPowerDevice.type.
class UPowerDeviceType: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_SINGLETON;

public:
	enum Enum : quint8 {
		Unknown = 0,
		LinePower = 1,
		Battery = 2,
		Ups = 3,
		Monitor = 4,
		Mouse = 5,
		Keyboard = 6,
		Pda = 7,
		Phone = 8,
		MediaPlayer = 9,
		Tablet = 10,
		Computer = 11,
		GamingInput = 12,
		Pen = 13,
		Touchpad = 14,
		Modem = 15,
		Network = 16,
		Headset = 17,
		Speakers = 18,
		Headphones = 19,
		Video = 20,
		OtherAudio = 21,
		RemoteControl = 22,
		Printer = 23,
		Scanner = 24,
		Camera = 25,
		Wearable = 26,
		Toy = 27,
		BluetoothGeneric = 28,
	};
	Q_ENUM(Enum);

	Q_INVOKABLE static QString toString(qs::mac::upower::UPowerDeviceType::Enum type);
};

///! A device exposed through the UPower service.
/// The macOS counterpart of the Linux `UPowerDevice`, backed by IOKit power
/// sources instead of the UPower daemon. Same property surface so DMS binds
/// unchanged.
class UPowerDevice: public QObject {
	Q_OBJECT;
	// clang-format off
	/// The type of device.
	Q_PROPERTY(qs::mac::upower::UPowerDeviceType::Enum type READ default NOTIFY typeChanged BINDABLE bindableType);
	/// If the device is a power supply for your computer and can provide charge.
	Q_PROPERTY(bool powerSupply READ default NOTIFY powerSupplyChanged BINDABLE bindablePowerSupply);
	/// Current energy level of the device in watt-hours.
	Q_PROPERTY(qreal energy READ default NOTIFY energyChanged BINDABLE bindableEnergy);
	/// Maximum energy capacity of the device in watt-hours
	Q_PROPERTY(qreal energyCapacity READ default NOTIFY energyCapacityChanged BINDABLE bindableEnergyCapacity);
	/// Rate of energy change in watts (positive when charging, negative when discharging).
	Q_PROPERTY(qreal changeRate READ default NOTIFY changeRateChanged BINDABLE bindableChangeRate);
	/// Estimated time until the device is fully discharged, in seconds.
	///
	/// Will be set to `0` if charging.
	Q_PROPERTY(qreal timeToEmpty READ default NOTIFY timeToEmptyChanged BINDABLE bindableTimeToEmpty);
	/// Estimated time until the device is fully charged, in seconds.
	///
	/// Will be set to `0` if discharging.
	Q_PROPERTY(qreal timeToFull READ default NOTIFY timeToFullChanged BINDABLE bindableTimeToFull);
	/// Current charge level as a percentage, from `0.0` to `1.0`.
	Q_PROPERTY(qreal percentage READ default NOTIFY percentageChanged BINDABLE bindablePercentage);
	/// If the power source is present in the bay or slot, useful for hot-removable batteries.
	Q_PROPERTY(bool isPresent READ default NOTIFY isPresentChanged BINDABLE bindableIsPresent);
	/// Current state of the device.
	Q_PROPERTY(qs::mac::upower::UPowerDeviceState::Enum state READ default NOTIFY stateChanged BINDABLE bindableState);
	/// Health of the device as a percentage of its original health.
	Q_PROPERTY(qreal healthPercentage READ default NOTIFY healthPercentageChanged BINDABLE bindableHealthPercentage);
	Q_PROPERTY(bool healthSupported READ default NOTIFY healthSupportedChanged BINDABLE bindableHealthSupported);
	/// Name of the icon representing the current state of the device, or an empty string if not provided.
	Q_PROPERTY(QString iconName READ default NOTIFY iconNameChanged BINDABLE bindableIconName);
	/// If the device is a laptop battery or not. Use this to check if your device is a valid battery.
	///
	/// This will be equivalent to @@type == Battery && @@powerSupply == true.
	Q_PROPERTY(bool isLaptopBattery READ default NOTIFY isLaptopBatteryChanged BINDABLE bindableIsLaptopBattery);
	/// Native path of the device specific to your OS.
	Q_PROPERTY(QString nativePath READ default NOTIFY nativePathChanged BINDABLE bindableNativePath);
	/// Model name of the device. Unlikely to be useful for internal devices.
	Q_PROPERTY(QString model READ default NOTIFY modelChanged BINDABLE bindableModel);
	/// If device statistics have been queried for this device yet.
	Q_PROPERTY(bool ready READ default NOTIFY readyChanged BINDABLE bindableReady);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("UPowerDevices can only be acquired from UPower");

public:
	explicit UPowerDevice(QObject* parent = nullptr);

	// Apply a fresh IOKit snapshot. Keys mirror the property names; missing keys
	// leave the corresponding property untouched.
	void updateFromSnapshot(const QVariantMap& snapshot);

	[[nodiscard]] QBindable<UPowerDeviceType::Enum> bindableType() { return &this->bType; }
	[[nodiscard]] QBindable<bool> bindablePowerSupply() { return &this->bPowerSupply; }
	[[nodiscard]] QBindable<qreal> bindableEnergy() { return &this->bEnergy; }
	[[nodiscard]] QBindable<qreal> bindableEnergyCapacity() { return &this->bEnergyCapacity; }
	[[nodiscard]] QBindable<qreal> bindableChangeRate() { return &this->bChangeRate; }
	[[nodiscard]] QBindable<qreal> bindableTimeToEmpty() { return &this->bTimeToEmpty; }
	[[nodiscard]] QBindable<qreal> bindableTimeToFull() { return &this->bTimeToFull; }
	[[nodiscard]] QBindable<qreal> bindablePercentage() { return &this->bPercentage; }
	[[nodiscard]] QBindable<bool> bindableIsPresent() { return &this->bIsPresent; }
	[[nodiscard]] QBindable<UPowerDeviceState::Enum> bindableState() { return &this->bState; }
	[[nodiscard]] QBindable<qreal> bindableHealthPercentage() { return &this->bHealthPercentage; }
	[[nodiscard]] QBindable<bool> bindableHealthSupported() { return &this->bHealthSupported; }
	[[nodiscard]] QBindable<QString> bindableIconName() { return &this->bIconName; }
	[[nodiscard]] QBindable<bool> bindableIsLaptopBattery() { return &this->bIsLaptopBattery; }
	[[nodiscard]] QBindable<QString> bindableNativePath() { return &this->bNativePath; }
	[[nodiscard]] QBindable<QString> bindableModel() { return &this->bModel; }
	[[nodiscard]] QBindable<bool> bindableReady() { return &this->bReady; }

signals:
	void readyChanged();
	void typeChanged();
	void powerSupplyChanged();
	void energyChanged();
	void energyCapacityChanged();
	void changeRateChanged();
	void timeToEmptyChanged();
	void timeToFullChanged();
	void percentageChanged();
	void isPresentChanged();
	void stateChanged();
	void healthPercentageChanged();
	void healthSupportedChanged();
	void iconNameChanged();
	void isLaptopBatteryChanged();
	void nativePathChanged();
	void modelChanged();

private:
	// clang-format off
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, UPowerDeviceType::Enum, bType, &UPowerDevice::typeChanged);
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, bool, bPowerSupply, &UPowerDevice::powerSupplyChanged);
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, qreal, bEnergy, &UPowerDevice::energyChanged);
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, qreal, bEnergyCapacity, &UPowerDevice::energyCapacityChanged);
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, qreal, bChangeRate, &UPowerDevice::changeRateChanged);
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, qreal, bTimeToEmpty, &UPowerDevice::timeToEmptyChanged);
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, qreal, bTimeToFull, &UPowerDevice::timeToFullChanged);
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, qreal, bPercentage, &UPowerDevice::percentageChanged);
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, bool, bIsPresent, &UPowerDevice::isPresentChanged);
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, UPowerDeviceState::Enum, bState, &UPowerDevice::stateChanged);
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, qreal, bHealthPercentage, &UPowerDevice::healthPercentageChanged);
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, bool, bHealthSupported, &UPowerDevice::healthSupportedChanged);
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, QString, bIconName, &UPowerDevice::iconNameChanged);
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, bool, bIsLaptopBattery, &UPowerDevice::isLaptopBatteryChanged);
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, QString, bNativePath, &UPowerDevice::nativePathChanged);
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, QString, bModel, &UPowerDevice::modelChanged);
	Q_OBJECT_BINDABLE_PROPERTY(UPowerDevice, bool, bReady, &UPowerDevice::readyChanged);
	// clang-format on
};

} // namespace qs::mac::upower
