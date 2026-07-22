#include "bluetooth.hpp"

#import <IOBluetooth/IOBluetooth.h>
#include <qset.h>
#include <qstring.h>

// Toggle overall Bluetooth power. Declared here because it is not in the public
// IOBluetooth headers, though it has long lived in the framework and is what
// menu-bar bluetooth togglers use.
extern "C" int IOBluetoothPreferenceSetControllerPowerState(int powered);

namespace qs::mac::bluetooth {

QString BluetoothAdapterState::toString(BluetoothAdapterState::Enum state) {
	switch (state) {
	case Disabled: return "Disabled";
	case Enabled: return "Enabled";
	case Enabling: return "Enabling";
	case Disabling: return "Disabling";
	case Blocked: return "Blocked";
	default: return "Unknown";
	}
}

QString BluetoothDeviceState::toString(BluetoothDeviceState::Enum state) {
	switch (state) {
	case Disconnected: return "Disconnected";
	case Connected: return "Connected";
	case Disconnecting: return "Disconnecting";
	case Connecting: return "Connecting";
	default: return "Unknown";
	}
}

namespace {

QString iconForDevice(IOBluetoothDevice* device) {
	switch ([device deviceClassMajor]) {
	case kBluetoothDeviceClassMajorComputer: return "computer";
	case kBluetoothDeviceClassMajorPhone: return "phone";
	case kBluetoothDeviceClassMajorAudio: return "audio-headphones";
	case kBluetoothDeviceClassMajorPeripheral:
		switch ([device deviceClassMinor]) {
		case kBluetoothDeviceClassMinorPeripheral1Keyboard: return "input-keyboard";
		case kBluetoothDeviceClassMinorPeripheral1Pointing: return "input-mouse";
		default: return "input-gaming";
		}
	default: return "bluetooth";
	}
}

} // namespace

// === BluetoothDevice ===

BluetoothDevice::BluetoothDevice(void* device, BluetoothAdapter* adapter, QObject* parent)
    : QObject(parent)
    , mDevice(device)
    , mAdapter(adapter) {
	this->refresh();
}

BluetoothDevice::~BluetoothDevice() {
	if (this->mDevice != nullptr) {
		auto* device = (__bridge_transfer IOBluetoothDevice*) this->mDevice; // release
		(void) device;
	}
}

void BluetoothDevice::refresh() {
	auto* device = (__bridge IOBluetoothDevice*) this->mDevice;

	auto address = QString::fromNSString([device addressString]);
	if (address != this->mAddress) {
		this->mAddress = address;
		emit this->addressChanged();
	}

	NSString* name = [device name];
	auto qname = name != nil ? QString::fromNSString(name) : address;
	if (qname != this->mName) {
		this->mName = qname;
		emit this->nameChanged();
	}

	auto icon = iconForDevice(device);
	if (icon != this->mIcon) {
		this->mIcon = icon;
		emit this->iconChanged();
	}

	bool paired = [device isPaired];
	if (paired != this->mPaired) {
		this->mPaired = paired;
		emit this->pairedChanged();
	}

	// Only settle to Connected/Disconnected here; a transient Connecting /
	// Disconnecting set by our own action is left until the operation returns.
	if (this->mState != BluetoothDeviceState::Connecting
	    && this->mState != BluetoothDeviceState::Disconnecting)
	{
		auto state =
		    [device isConnected] ? BluetoothDeviceState::Connected : BluetoothDeviceState::Disconnected;
		if (state != this->mState) {
			this->mState = state;
			emit this->stateChanged();
		}
	}
}

void BluetoothDevice::setConnected(bool connected) {
	connected ? this->connect() : this->disconnect();
}

void BluetoothDevice::connect() {
	if (this->mState == BluetoothDeviceState::Connected) return;
	this->mState = BluetoothDeviceState::Connecting;
	emit this->stateChanged();

	auto* device = (__bridge IOBluetoothDevice*) this->mDevice;
	// openConnection blocks, so run it off the main thread and settle back.
	dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
		[device openConnection];
		dispatch_async(dispatch_get_main_queue(), ^{
			this->mState = BluetoothDeviceState::Disconnected; // refresh reads truth
			this->refresh();
		});
	});
}

void BluetoothDevice::disconnect() {
	if (this->mState == BluetoothDeviceState::Disconnected) return;
	this->mState = BluetoothDeviceState::Disconnecting;
	emit this->stateChanged();

	auto* device = (__bridge IOBluetoothDevice*) this->mDevice;
	dispatch_async(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), ^{
		[device closeConnection];
		dispatch_async(dispatch_get_main_queue(), ^{
			this->mState = BluetoothDeviceState::Connected; // refresh reads truth
			this->refresh();
		});
	});
}

// === BluetoothAdapter ===

void BluetoothAdapter::setInfo(
    const QString& name,
    const QString& address,
    BluetoothAdapterState::Enum state
) {
	if (name != this->mName) {
		this->mName = name;
		emit this->nameChanged();
	}
	this->mAddress = address;
	if (state != this->mState) {
		this->mState = state;
		emit this->stateChanged();
	}
}

void BluetoothAdapter::setEnabled(bool enabled) {
	IOBluetoothPreferenceSetControllerPowerState(enabled ? 1 : 0);
	this->mState = enabled ? BluetoothAdapterState::Enabling : BluetoothAdapterState::Disabling;
	emit this->stateChanged();
}

// === Bluetooth ===

Bluetooth::Bluetooth(QObject* parent): QObject(parent) {
	this->mAdapter = new BluetoothAdapter(this);
	this->mAdapters.insertObject(this->mAdapter);

	this->mPollTimer.setInterval(2000);
	QObject::connect(&this->mPollTimer, &QTimer::timeout, this, &Bluetooth::refresh);
	this->mPollTimer.start();
	this->refresh();

	emit this->defaultAdapterChanged();
}

void Bluetooth::refresh() {
	// Adapter power/name from the default host controller.
	IOBluetoothHostController* controller = [IOBluetoothHostController defaultController];
	if (controller != nil) {
		auto name = QString::fromNSString([controller nameAsString]);
		auto address = QString::fromNSString([controller addressAsString]);
		auto state = [controller powerState] == kBluetoothHCIPowerStateON
		               ? BluetoothAdapterState::Enabled
		               : BluetoothAdapterState::Disabled;
		this->mAdapter->setInfo(name, address, state);
	}

	// Reconcile the paired-device list.
	NSArray* paired = [IOBluetoothDevice pairedDevices];
	QSet<QString> present;
	for (IOBluetoothDevice* device in paired) {
		auto address = QString::fromNSString([device addressString]);
		present.insert(address);

		bool found = false;
		for (auto* existing: this->mDevices.valueList()) {
			if (existing->address() == address) {
				existing->refresh();
				found = true;
				break;
			}
		}
		if (!found) {
			auto* node = new BluetoothDevice((__bridge_retained void*) device, this->mAdapter, this);
			this->mDevices.insertObject(node);
			this->mAdapter->mDevices.insertObject(node);
		}
	}

	// Drop devices that are no longer paired.
	const auto snapshot = this->mDevices.valueList();
	for (auto* device: snapshot) {
		if (present.contains(device->address())) continue;
		this->mDevices.removeObject(device);
		this->mAdapter->mDevices.removeObject(device);
		device->deleteLater();
	}
}

} // namespace qs::mac::bluetooth
