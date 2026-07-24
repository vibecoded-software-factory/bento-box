#pragma once

#include <qobject.h>
#include <qqmlintegration.h>
#include <qset.h>
#include <qstring.h>
#include <qtimer.h>
#include <qtmetamacros.h>
#include <qtypes.h>

#include "../../core/doc.hpp"
#include "../../core/model.hpp"

// macOS Bluetooth, backed by IOBluetooth (classic BR-EDR). Mirrors the Linux
// BlueZ service's QML surface so DMS's bluetooth widget binds unchanged:
// paired devices with name/icon/connection state, connect/disconnect, the
// adapter's power state, discovery (IOBluetoothDeviceInquiry), pairing
// (IOBluetoothDevicePair - just-works and numeric-comparison auto-confirmed
// like a NoInputNoOutput BlueZ agent, keyboard passkeys surfaced via a
// notification), unpairing (the framework's long-stable private `remove`,
// the same call blueutil makes - there is no public unpair), and per-device
// battery from the IOKit registry. Controls macOS truly keeps to itself
// (discoverable, pairable, trust, block, wake) stay present but inert.

namespace qs::mac::bluetooth {

///! State of a bluetooth adapter.
class BluetoothAdapterState: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_SINGLETON;

public:
	enum Enum : quint8 {
		Disabled = 0,
		Enabled = 1,
		Enabling = 2,
		Disabling = 3,
		Blocked = 4,
	};
	Q_ENUM(Enum);
	Q_INVOKABLE static QString toString(qs::mac::bluetooth::BluetoothAdapterState::Enum state);
};

///! Connection state of a bluetooth device.
class BluetoothDeviceState: public QObject {
	Q_OBJECT;
	QML_ELEMENT;
	QML_SINGLETON;

public:
	enum Enum : quint8 {
		Disconnected = 0,
		Connected = 1,
		Disconnecting = 2,
		Connecting = 3,
	};
	Q_ENUM(Enum);
	Q_INVOKABLE static QString toString(qs::mac::bluetooth::BluetoothDeviceState::Enum state);
};

class BluetoothAdapter;

///! A bluetooth device.
class BluetoothDevice: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(QString address READ address NOTIFY addressChanged);
	/// BlueZ-style object path derived from the address, so the shell's
	/// daemon-pairing path (DMSService.bluetoothPair) has a device token.
	Q_PROPERTY(QString dbusPath READ dbusPath NOTIFY addressChanged);
	/// The name of the Bluetooth device. This property may be written to create an alias, or set to
	/// an empty string to fall back to the device provided name. On macOS the
	/// alias is SESSION-LOCAL (IOBluetooth has no public persistent alias
	/// store, BlueZ does) - the read/write contract is upstream's, the
	/// persistence is not.
	Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged);
	/// The name provided by the device itself, ignoring aliases.
	Q_PROPERTY(QString deviceName READ deviceName NOTIFY deviceNameChanged);
	Q_PROPERTY(QString icon READ icon NOTIFY iconChanged);
	Q_PROPERTY(qs::mac::bluetooth::BluetoothDeviceState::Enum state READ state NOTIFY stateChanged);
	/// Whether the device is connected. Setting it connects/disconnects.
	Q_PROPERTY(bool connected READ connected WRITE setConnected NOTIFY connectedChanged);
	Q_PROPERTY(bool paired READ paired NOTIFY pairedChanged);
	/// On macOS pairing IS bonding (IOBluetooth stores link keys for every
	/// pair), so this reads the paired flag - with upstream's own NOTIFY name.
	Q_PROPERTY(bool bonded READ paired NOTIFY bondedChanged);
	Q_PROPERTY(bool pairing READ pairing NOTIFY pairingChanged);
	/// No IOBluetooth equivalent - always false, setter inert.
	Q_PROPERTY(bool trusted READ trusted WRITE setTrusted NOTIFY trustedChanged);
	/// No IOBluetooth equivalent - always false, setter inert.
	Q_PROPERTY(bool blocked READ blocked WRITE setBlocked NOTIFY blockedChanged);
	/// No IOBluetooth equivalent - always false, setter inert.
	Q_PROPERTY(bool wakeAllowed READ wakeAllowed WRITE setWakeAllowed NOTIFY wakeAllowedChanged);
	/// From the IOKit registry (BatteryPercent), where the device reports it.
	Q_PROPERTY(bool batteryAvailable READ batteryAvailable NOTIFY batteryAvailableChanged);
	Q_PROPERTY(qreal battery READ battery NOTIFY batteryChanged);
	/// The adapter this device belongs to. Never changes on macOS (one
	/// controller), but carries upstream's NOTIFY so handlers resolve.
	Q_PROPERTY(qs::mac::bluetooth::BluetoothAdapter* adapter READ adapter NOTIFY adapterChanged);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("");

public:
	// device is an IOBluetoothDevice* (opaque here; retained by the .mm).
	explicit BluetoothDevice(void* device, BluetoothAdapter* adapter, QObject* parent = nullptr);
	~BluetoothDevice() override;
	Q_DISABLE_COPY_MOVE(BluetoothDevice);

	[[nodiscard]] QString address() const { return this->mAddress; }
	[[nodiscard]] QString dbusPath() const;
	[[nodiscard]] QString name() const { return this->mAlias.isEmpty() ? this->mName : this->mAlias; }
	void setName(const QString& name);
	[[nodiscard]] QString deviceName() const { return this->mName; }
	[[nodiscard]] QString icon() const { return this->mIcon; }
	[[nodiscard]] BluetoothDeviceState::Enum state() const { return this->mState; }
	[[nodiscard]] bool connected() const { return this->mState == BluetoothDeviceState::Connected; }
	void setConnected(bool connected);
	[[nodiscard]] bool paired() const { return this->mPaired; }
	[[nodiscard]] bool pairing() const { return this->mPairing; }
	[[nodiscard]] bool trusted() const { return false; }
	void setTrusted(bool /*trusted*/) {}
	[[nodiscard]] bool blocked() const { return false; }
	void setBlocked(bool /*blocked*/) {}
	[[nodiscard]] bool wakeAllowed() const { return false; }
	void setWakeAllowed(bool /*wakeAllowed*/) {}
	[[nodiscard]] bool batteryAvailable() const { return this->mBatteryAvailable; }
	[[nodiscard]] qreal battery() const { return this->mBattery; }
	[[nodiscard]] BluetoothAdapter* adapter() const { return this->mAdapter; }

	Q_INVOKABLE void connect();
	Q_INVOKABLE void disconnect();
	Q_INVOKABLE void pair();
	Q_INVOKABLE void cancelPair();
	Q_INVOKABLE void forget();

	// Re-read state from the underlying IOBluetoothDevice.
	void refresh();
	// The one state writer: emits stateChanged, and connectedChanged when
	// the derived boolean actually flips.
	void transitionState(BluetoothDeviceState::Enum state);
	// Settle a transient Connecting/Disconnecting to the real state and notify.
	void settleState();
	[[nodiscard]] void* handle() const { return this->mDevice; }

	// Backend hooks.
	void setBatteryInfo(bool available, qreal level);
	void pairingFinished(bool success); // called by the pairing delegate

signals:
	void addressChanged();
	void nameChanged();
	void deviceNameChanged();
	void iconChanged();
	void stateChanged();
	// Dedicated NOTIFY, like upstream device.hpp:79 - onConnectedChanged
	// handlers resolve against the signal name.
	void connectedChanged();
	void pairedChanged();
	void bondedChanged();
	void pairingChanged();
	// Never emitted - a device cannot move between adapters on macOS.
	void adapterChanged();
	void trustedChanged();
	void blockedChanged();
	void wakeAllowedChanged();
	void batteryAvailableChanged();
	void batteryChanged();

private:
	void* mDevice; // IOBluetoothDevice* (retained)
	BluetoothAdapter* mAdapter;
	QString mAddress;
	QString mName;
	// Session-local alias (see the `name` property note).
	QString mAlias;
	QString mIcon;
	BluetoothDeviceState::Enum mState = BluetoothDeviceState::Disconnected;
	bool mPaired = true;
	bool mPairing = false;
	bool mBatteryAvailable = false;
	qreal mBattery = 0.0;
	void* mPair = nullptr;         // IOBluetoothDevicePair* while pairing (retained)
	void* mPairDelegate = nullptr; // its delegate (retained)
};

///! A bluetooth adapter.
class BluetoothAdapter: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(QString name READ name NOTIFY nameChanged);
	/// Whether the adapter is powered on. Writable (toggles Bluetooth power).
	Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged);
	Q_PROPERTY(qs::mac::bluetooth::BluetoothAdapterState::Enum state READ state NOTIFY stateChanged);
	/// macOS controls discoverable/pairable in System Settings; present but inert.
	Q_PROPERTY(bool discoverable READ discoverable WRITE setDiscoverable NOTIFY discoverableChanged);
	/// Stored so writes round-trip, but INERT like `discoverable` itself -
	/// macOS owns discoverability. Upstream: seconds before discoverable
	/// drops, 0 = forever.
	Q_PROPERTY(quint32 discoverableTimeout READ discoverableTimeout WRITE setDiscoverableTimeout NOTIFY discoverableTimeoutChanged);
	/// Device discovery (IOBluetoothDeviceInquiry); found devices join `devices`.
	Q_PROPERTY(bool discovering READ discovering WRITE setDiscovering NOTIFY discoveringChanged);
	Q_PROPERTY(bool pairable READ pairable WRITE setPairable NOTIFY pairableChanged);
	/// Stored so writes round-trip, but INERT like `pairable` itself.
	/// Upstream default 0 = forever.
	Q_PROPERTY(quint32 pairableTimeout READ pairableTimeout WRITE setPairableTimeout NOTIFY pairableTimeoutChanged);
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::bluetooth::BluetoothDevice>*);
	Q_PROPERTY(UntypedObjectModel* devices READ devices CONSTANT);
	/// The internal ID of the adapter. Upstream derives it from the DBus path
	/// ("hci0"); the synthetic BlueZ paths here use hci0, so this matches the
	/// hci-style id, not the controller MAC.
	Q_PROPERTY(QString adapterId READ adapterId CONSTANT);
	/// BlueZ-style object path, consistent with the devices' dbusPath tokens.
	Q_PROPERTY(QString dbusPath READ dbusPath CONSTANT);
	// clang-format on
	QML_ELEMENT;
	QML_UNCREATABLE("");

public:
	explicit BluetoothAdapter(QObject* parent = nullptr): QObject(parent) {}

	[[nodiscard]] QString name() const { return this->mName; }
	[[nodiscard]] bool enabled() const { return this->mState == BluetoothAdapterState::Enabled; }
	void setEnabled(bool enabled);
	[[nodiscard]] BluetoothAdapterState::Enum state() const { return this->mState; }
	[[nodiscard]] bool discoverable() const { return false; }
	void setDiscoverable(bool /*discoverable*/) {}
	[[nodiscard]] bool discovering() const { return this->mDiscovering; }
	void setDiscovering(bool discovering);
	[[nodiscard]] bool pairable() const { return false; }
	void setPairable(bool /*pairable*/) {}
	[[nodiscard]] quint32 discoverableTimeout() const { return this->mDiscoverableTimeout; }
	void setDiscoverableTimeout(quint32 timeout);
	[[nodiscard]] quint32 pairableTimeout() const { return this->mPairableTimeout; }
	void setPairableTimeout(quint32 timeout);
	[[nodiscard]] ObjectModel<BluetoothDevice>* devices() { return &this->mDevices; }
	// Upstream: the last path segment of the DBus path (adapter.cpp:48-51).
	// The synthetic paths here are /org/bluez/hci0/..., so the id is "hci0" -
	// the hci-style id, matching upstream's format (the controller MAC lives
	// in `name`-adjacent metadata, not here).
	[[nodiscard]] static QString adapterId() { return QStringLiteral("hci0"); }
	[[nodiscard]] static QString dbusPath() { return QStringLiteral("/org/bluez/hci0"); }

	// Backend hooks (set from the singleton).
	void setInfo(const QString& name, const QString& address, BluetoothAdapterState::Enum state);
	// The one state writer: emits stateChanged, and enabledChanged when the
	// derived boolean actually flips.
	void transitionState(BluetoothAdapterState::Enum state);
	void setDiscoveringState(bool discovering);
	ObjectModel<BluetoothDevice> mDevices {this};

signals:
	void nameChanged();
	void stateChanged();
	// Dedicated NOTIFY, like upstream adapter.hpp:65.
	void enabledChanged();
	void discoverableChanged();
	void discoverableTimeoutChanged();
	void discoveringChanged();
	void pairableChanged();
	void pairableTimeoutChanged();

private:
	QString mName;
	QString mAddress;
	BluetoothAdapterState::Enum mState = BluetoothAdapterState::Disabled;
	bool mDiscovering = false;
	quint32 mDiscoverableTimeout = 0;
	quint32 mPairableTimeout = 0;
};

///! Bluetooth manager.
/// The macOS counterpart of the Linux `Bluetooth` singleton, backed by
/// IOBluetooth.
class Bluetooth: public QObject {
	Q_OBJECT;
	// clang-format off
	Q_PROPERTY(qs::mac::bluetooth::BluetoothAdapter* defaultAdapter READ defaultAdapter NOTIFY defaultAdapterChanged);
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::bluetooth::BluetoothAdapter>*);
	Q_PROPERTY(UntypedObjectModel* adapters READ adapters CONSTANT);
	QSDOC_TYPE_OVERRIDE(ObjectModel<qs::mac::bluetooth::BluetoothDevice>*);
	Q_PROPERTY(UntypedObjectModel* devices READ devices CONSTANT);
	// clang-format on
	QML_NAMED_ELEMENT(Bluetooth);
	QML_SINGLETON;

public:
	explicit Bluetooth(QObject* parent = nullptr);

	[[nodiscard]] BluetoothAdapter* defaultAdapter() const { return this->mAdapter; }
	[[nodiscard]] ObjectModel<BluetoothAdapter>* adapters() { return &this->mAdapters; }
	[[nodiscard]] ObjectModel<BluetoothDevice>* devices() { return &this->mDevices; }

	// Refresh adapter power state, the device list and battery levels.
	void refresh();

	// Discovery (IOBluetoothDeviceInquiry). Found devices join the models
	// unpaired; they are pruned once discovery ends unless busy or paired.
	void setDiscovering(bool discovering);
	[[nodiscard]] bool discovering() const { return this->mDiscovering; }
	void inquiryFound(void* device); // IOBluetoothDevice*, from the delegate
	void inquiryComplete();          // from the delegate

signals:
	void defaultAdapterChanged();

private:
	BluetoothDevice* deviceByAddress(const QString& address);
	void insertDevice(void* device); // IOBluetoothDevice*, transfers retain

	BluetoothAdapter* mAdapter = nullptr;
	ObjectModel<BluetoothAdapter> mAdapters {this};
	ObjectModel<BluetoothDevice> mDevices {this};
	QTimer mPollTimer;
	bool mDiscovering = false;
	void* mInquiry = nullptr;         // IOBluetoothDeviceInquiry* (retained)
	void* mInquiryDelegate = nullptr; // its delegate (retained)
	QSet<QString> mDiscovered;        // addresses found by the current discovery
};

} // namespace qs::mac::bluetooth
