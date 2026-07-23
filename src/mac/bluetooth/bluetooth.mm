#include "bluetooth.hpp"

#import <IOBluetooth/IOBluetooth.h>
#import <IOKit/IOKitLib.h>
#include <qhash.h>
#include <qset.h>
#include <qstring.h>

// Toggle overall Bluetooth power. Declared here because it is not in the public
// IOBluetooth headers, though it has long lived in the framework and is what
// menu-bar bluetooth togglers use.
extern "C" int IOBluetoothPreferenceSetControllerPowerState(int powered);

// Discovery: found devices are handed to the Bluetooth manager as they appear.
@interface QSBluetoothInquiryDelegate: NSObject <IOBluetoothDeviceInquiryDelegate> {
@public
	qs::mac::bluetooth::Bluetooth* owner;
}
@end

@implementation QSBluetoothInquiryDelegate
- (void)deviceInquiryDeviceFound:(IOBluetoothDeviceInquiry*)sender
                          device:(IOBluetoothDevice*)device {
	if (self->owner != nullptr) self->owner->inquiryFound((__bridge void*) device);
}

- (void)deviceInquiryComplete:(IOBluetoothDeviceInquiry*)sender
                        error:(IOReturn)error
                      aborted:(BOOL)aborted {
	if (self->owner != nullptr) self->owner->inquiryComplete();
}
@end

// Pairing: the same policy as a BlueZ NoInputNoOutput agent - just-works and
// numeric-comparison confirmations are accepted, legacy PIN devices get the
// conventional 0000, and a keyboard passkey (which must be typed on the
// device) is surfaced through a notification.
@interface QSBluetoothPairDelegate: NSObject <IOBluetoothDevicePairDelegate> {
@public
	qs::mac::bluetooth::BluetoothDevice* owner;
}
@end

@implementation QSBluetoothPairDelegate
- (void)devicePairingPINCodeRequest:(id)sender {
	BluetoothPINCode pin {};
	memcpy(pin.data, "0000", 4);
	[sender replyPINCode:4 PINCode:&pin];
}

- (void)devicePairingUserConfirmationRequest:(id)sender
                                numericValue:(BluetoothNumericValue)numericValue {
	[sender replyUserConfirmation:YES];
}

- (void)devicePairingUserPasskeyNotification:(id)sender passkey:(BluetoothPasskey)passkey {
	NSLog(@"[bento] bluetooth pairing passkey: %06u", passkey);
	NSString* script = [NSString
	    stringWithFormat:@"display notification \"Type %06u on the device, then press Enter\" "
	                     @"with title \"Bluetooth pairing\"",
	                     passkey];
	NSTask* task = [NSTask new];
	task.executableURL = [NSURL fileURLWithPath:@"/usr/bin/osascript"];
	task.arguments = @[ @"-e", script ];
	[task launchAndReturnError:nil];
}

- (void)devicePairingFinished:(id)sender error:(IOReturn)error {
	if (self->owner != nullptr) self->owner->pairingFinished(error == kIOReturnSuccess);
}
@end

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

// Bluetooth accessories that report battery show up in the IOKit registry as
// HID event services carrying DeviceAddress + BatteryPercent (Magic Mouse,
// keyboards, many headphones). Addresses normalized to lowercase-dashes, the
// same shape IOBluetoothDevice.addressString uses.
QHash<QString, int> batteryPercents() {
	QHash<QString, int> out;
	io_iterator_t iterator = IO_OBJECT_NULL;
	CFMutableDictionaryRef match = IOServiceMatching("AppleDeviceManagementHIDEventService");
	if (IOServiceGetMatchingServices(kIOMainPortDefault, match, &iterator) != KERN_SUCCESS) {
		return out;
	}
	io_object_t service = IO_OBJECT_NULL;
	while ((service = IOIteratorNext(iterator)) != IO_OBJECT_NULL) {
		CFTypeRef address =
		    IORegistryEntryCreateCFProperty(service, CFSTR("DeviceAddress"), kCFAllocatorDefault, 0);
		CFTypeRef percent =
		    IORegistryEntryCreateCFProperty(service, CFSTR("BatteryPercent"), kCFAllocatorDefault, 0);
		if (address != nullptr && percent != nullptr) {
			auto key = QString::fromNSString((__bridge NSString*) address)
			               .toLower()
			               .replace(QChar(':'), QChar('-'));
			out.insert(key, [(__bridge NSNumber*) percent intValue]);
		}
		if (address != nullptr) CFRelease(address);
		if (percent != nullptr) CFRelease(percent);
		IOObjectRelease(service);
	}
	IOObjectRelease(iterator);
	return out;
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

	// An unpaired device (found via discovery) pairs first - the same implicit
	// pair-on-connect the shell's non-agent fallback path expects from BlueZ.
	if (!this->mPaired) {
		this->startPairing(true);
		return;
	}

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

void BluetoothDevice::pair() {
	if (!this->mPaired && !this->mPairing) this->startPairing(false);
}

void BluetoothDevice::startPairing(bool connectAfter) {
	if (this->mPairing) return;

	auto* device = (__bridge IOBluetoothDevice*) this->mDevice;
	auto* delegate = [QSBluetoothPairDelegate new];
	delegate->owner = this;
	IOBluetoothDevicePair* pairing = [IOBluetoothDevicePair pairWithDevice:device];
	pairing.delegate = delegate;

	this->mPair = (__bridge_retained void*) pairing;
	this->mPairDelegate = (__bridge_retained void*) delegate;
	this->mConnectAfterPair = connectAfter;
	this->mPairing = true;
	emit this->pairingChanged();

	if ([pairing start] != kIOReturnSuccess) this->pairingFinished(false);
}

void BluetoothDevice::cancelPair() {
	if (!this->mPairing) return;
	[(__bridge IOBluetoothDevicePair*) this->mPair stop];
	this->pairingFinished(false);
}

void BluetoothDevice::pairingFinished(bool success) {
	if (!this->mPairing) return;
	this->mPairing = false;

	if (this->mPair != nullptr) {
		auto* pairing = (__bridge_transfer IOBluetoothDevicePair*) this->mPair; // release
		(void) pairing;
		this->mPair = nullptr;
	}
	if (this->mPairDelegate != nullptr) {
		auto* delegate = (__bridge_transfer QSBluetoothPairDelegate*) this->mPairDelegate; // release
		delegate->owner = nullptr;
		this->mPairDelegate = nullptr;
	}

	emit this->pairingChanged();
	this->refresh();

	const bool connectAfter = this->mConnectAfterPair;
	this->mConnectAfterPair = false;
	if (success && connectAfter) this->connect();
}

void BluetoothDevice::forget() {
	auto* device = (__bridge IOBluetoothDevice*) this->mDevice;
	// There is no public unpair. The framework's private `remove` (blueutil's
	// call) works on older macOS; current releases gate unpairing behind a
	// bluetoothd entitlement and silently ignore it (verified: remove and
	// forceRemove both return a CoreBluetooth coordinator and the pairing
	// stays). Attempt it and log the truth either way - the shell stays in
	// charge of its own UX, so no OS UI is opened from here. Surfacing the
	// failure as an in-shell toast needs the daemon's bluez-agent channel
	// (DMSService.bluetoothRemove carries an error callback); tracked in the
	// parity audit.
	SEL removeSel = NSSelectorFromString(@"remove");
	if ([device respondsToSelector:removeSel]) {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
		[device performSelector:removeSel];
#pragma clang diagnostic pop
	}

	NSString* address = [device addressString];
	dispatch_after(
	    dispatch_time(DISPATCH_TIME_NOW, (int64_t) (1.5 * NSEC_PER_SEC)),
	    dispatch_get_main_queue(),
	    ^{
		    for (IOBluetoothDevice* paired in [IOBluetoothDevice pairedDevices]) {
			    if (![[paired addressString] isEqualToString:address]) continue;
			    NSLog(
			        @"[bento] bluetooth: unpair of %@ ignored by the OS "
			        @"(entitlement-gated on this macOS)",
			        address
			    );
			    return;
		    }
	    }
	);
}

void BluetoothDevice::setBatteryInfo(bool available, qreal level) {
	if (available != this->mBatteryAvailable) {
		this->mBatteryAvailable = available;
		emit this->batteryAvailableChanged();
	}
	if (level != this->mBattery) {
		this->mBattery = level;
		emit this->batteryChanged();
	}
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

void BluetoothAdapter::setDiscovering(bool discovering) {
	auto* manager = qobject_cast<Bluetooth*>(this->parent());
	if (manager != nullptr) manager->setDiscovering(discovering);
}

void BluetoothAdapter::setDiscoveringState(bool discovering) {
	if (discovering == this->mDiscovering) return;
	this->mDiscovering = discovering;
	emit this->discoveringChanged();
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

BluetoothDevice* Bluetooth::deviceByAddress(const QString& address) {
	for (auto* existing: this->mDevices.valueList()) {
		if (existing->address() == address) return existing;
	}
	return nullptr;
}

void Bluetooth::insertDevice(void* device) {
	auto* node = new BluetoothDevice(device, this->mAdapter, this);
	this->mDevices.insertObject(node);
	this->mAdapter->mDevices.insertObject(node);
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

		auto* existing = this->deviceByAddress(address);
		if (existing != nullptr) {
			existing->refresh();
		} else {
			this->insertDevice((__bridge_retained void*) device);
		}
	}

	// Drop what is neither paired nor a live discovery result. A discovered
	// device survives while discovery runs and while it is busy pairing or
	// connected; once discovery is off and it is idle, it goes.
	const auto snapshot = this->mDevices.valueList();
	for (auto* device: snapshot) {
		if (present.contains(device->address())) continue;
		if (this->mDiscovered.contains(device->address())
		    && (this->mDiscovering || device->pairing() || device->connected()))
		{
			continue;
		}
		this->mDiscovered.remove(device->address());
		this->mDevices.removeObject(device);
		this->mAdapter->mDevices.removeObject(device);
		device->deleteLater();
	}

	// Battery levels from the IOKit registry.
	const auto levels = batteryPercents();
	for (auto* device: this->mDevices.valueList()) {
		auto key = device->address().toLower().replace(QChar(':'), QChar('-'));
		const bool available = levels.contains(key);
		device->setBatteryInfo(available, available ? levels.value(key) / 100.0 : 0.0);
	}
}

void Bluetooth::setDiscovering(bool discovering) {
	if (discovering == this->mDiscovering) return;
	this->mDiscovering = discovering;

	if (discovering) {
		auto* delegate = [QSBluetoothInquiryDelegate new];
		delegate->owner = this;
		IOBluetoothDeviceInquiry* inquiry = [IOBluetoothDeviceInquiry inquiryWithDelegate:delegate];
		[inquiry setUpdateNewDeviceNames:YES];
		this->mInquiryDelegate = (__bridge_retained void*) delegate;
		this->mInquiry = (__bridge_retained void*) inquiry;
		[inquiry start];
	} else if (this->mInquiry != nullptr) {
		[(__bridge IOBluetoothDeviceInquiry*) this->mInquiry stop];
	}

	this->mAdapter->setDiscoveringState(discovering);
	this->refresh();
}

void Bluetooth::inquiryFound(void* found) {
	auto* device = (__bridge IOBluetoothDevice*) found;
	auto address = QString::fromNSString([device addressString]);
	this->mDiscovered.insert(address);

	auto* existing = this->deviceByAddress(address);
	if (existing != nullptr) {
		existing->refresh();
	} else {
		this->insertDevice((__bridge_retained void*) device);
	}
}

void Bluetooth::inquiryComplete() {
	// An inquiry runs ~10s; while discovery is still wanted, run another -
	// BlueZ-style continuous scanning until the toggle turns it off.
	if (this->mDiscovering && this->mInquiry != nullptr) {
		[(__bridge IOBluetoothDeviceInquiry*) this->mInquiry start];
		return;
	}

	if (this->mInquiry != nullptr) {
		auto* inquiry = (__bridge_transfer IOBluetoothDeviceInquiry*) this->mInquiry; // release
		(void) inquiry;
		this->mInquiry = nullptr;
	}
	if (this->mInquiryDelegate != nullptr) {
		auto* delegate = (__bridge_transfer QSBluetoothInquiryDelegate*) this->mInquiryDelegate;
		delegate->owner = nullptr;
		this->mInquiryDelegate = nullptr;
	}
}

} // namespace qs::mac::bluetooth
