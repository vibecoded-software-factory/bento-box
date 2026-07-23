/****************************************************************************
** Meta object code from reading C++ file 'bluetooth.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/bluetooth/bluetooth.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetooth.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN2qs3mac9bluetooth21BluetoothAdapterStateE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::bluetooth::BluetoothAdapterState::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac9bluetooth21BluetoothAdapterStateE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::bluetooth::BluetoothAdapterState",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "toString",
        "",
        "qs::mac::bluetooth::BluetoothAdapterState::Enum",
        "state",
        "Enum",
        "Disabled",
        "Enabled",
        "Enabling",
        "Disabling",
        "Blocked"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'toString'
        QtMocHelpers::MethodData<QString(qs::mac::bluetooth::BluetoothAdapterState::Enum)>(5, 6, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 7, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<enum Enum>(9, 9, QMC::EnumFlags{}).add({
            {   10, Enum::Disabled },
            {   11, Enum::Enabled },
            {   12, Enum::Enabling },
            {   13, Enum::Disabling },
            {   14, Enum::Blocked },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<BluetoothAdapterState, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::bluetooth::BluetoothAdapterState::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac9bluetooth21BluetoothAdapterStateE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac9bluetooth21BluetoothAdapterStateE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac9bluetooth21BluetoothAdapterStateE_t>.metaTypes,
    nullptr
} };

void qs::mac::bluetooth::BluetoothAdapterState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BluetoothAdapterState *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = _t->toString((*reinterpret_cast<std::add_pointer_t<qs::mac::bluetooth::BluetoothAdapterState::Enum>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *qs::mac::bluetooth::BluetoothAdapterState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::bluetooth::BluetoothAdapterState::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac9bluetooth21BluetoothAdapterStateE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::bluetooth::BluetoothAdapterState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN2qs3mac9bluetooth20BluetoothDeviceStateE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::bluetooth::BluetoothDeviceState::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac9bluetooth20BluetoothDeviceStateE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::bluetooth::BluetoothDeviceState",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "toString",
        "",
        "qs::mac::bluetooth::BluetoothDeviceState::Enum",
        "state",
        "Enum",
        "Disconnected",
        "Connected",
        "Disconnecting",
        "Connecting"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'toString'
        QtMocHelpers::MethodData<QString(qs::mac::bluetooth::BluetoothDeviceState::Enum)>(5, 6, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 7, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<enum Enum>(9, 9, QMC::EnumFlags{}).add({
            {   10, Enum::Disconnected },
            {   11, Enum::Connected },
            {   12, Enum::Disconnecting },
            {   13, Enum::Connecting },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<BluetoothDeviceState, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::bluetooth::BluetoothDeviceState::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac9bluetooth20BluetoothDeviceStateE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac9bluetooth20BluetoothDeviceStateE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac9bluetooth20BluetoothDeviceStateE_t>.metaTypes,
    nullptr
} };

void qs::mac::bluetooth::BluetoothDeviceState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BluetoothDeviceState *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = _t->toString((*reinterpret_cast<std::add_pointer_t<qs::mac::bluetooth::BluetoothDeviceState::Enum>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *qs::mac::bluetooth::BluetoothDeviceState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::bluetooth::BluetoothDeviceState::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac9bluetooth20BluetoothDeviceStateE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::bluetooth::BluetoothDeviceState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN2qs3mac9bluetooth15BluetoothDeviceE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::bluetooth::BluetoothDevice::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac9bluetooth15BluetoothDeviceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::bluetooth::BluetoothDevice",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "",
        "addressChanged",
        "nameChanged",
        "iconChanged",
        "stateChanged",
        "pairedChanged",
        "pairingChanged",
        "trustedChanged",
        "blockedChanged",
        "wakeAllowedChanged",
        "batteryAvailableChanged",
        "batteryChanged",
        "connect",
        "disconnect",
        "pair",
        "cancelPair",
        "forget",
        "address",
        "name",
        "deviceName",
        "icon",
        "state",
        "qs::mac::bluetooth::BluetoothDeviceState::Enum",
        "connected",
        "paired",
        "bonded",
        "pairing",
        "trusted",
        "blocked",
        "wakeAllowed",
        "batteryAvailable",
        "battery",
        "adapter",
        "qs::mac::bluetooth::BluetoothAdapter*"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'addressChanged'
        QtMocHelpers::SignalData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'nameChanged'
        QtMocHelpers::SignalData<void()>(8, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'iconChanged'
        QtMocHelpers::SignalData<void()>(9, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'stateChanged'
        QtMocHelpers::SignalData<void()>(10, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'pairedChanged'
        QtMocHelpers::SignalData<void()>(11, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'pairingChanged'
        QtMocHelpers::SignalData<void()>(12, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'trustedChanged'
        QtMocHelpers::SignalData<void()>(13, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'blockedChanged'
        QtMocHelpers::SignalData<void()>(14, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'wakeAllowedChanged'
        QtMocHelpers::SignalData<void()>(15, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'batteryAvailableChanged'
        QtMocHelpers::SignalData<void()>(16, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'batteryChanged'
        QtMocHelpers::SignalData<void()>(17, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'connect'
        QtMocHelpers::MethodData<void()>(18, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'disconnect'
        QtMocHelpers::MethodData<void()>(19, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'pair'
        QtMocHelpers::MethodData<void()>(20, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'cancelPair'
        QtMocHelpers::MethodData<void()>(21, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'forget'
        QtMocHelpers::MethodData<void()>(22, 6, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'address'
        QtMocHelpers::PropertyData<QString>(23, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'name'
        QtMocHelpers::PropertyData<QString>(24, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'deviceName'
        QtMocHelpers::PropertyData<QString>(25, QMetaType::QString, QMC::DefaultPropertyFlags, 1),
        // property 'icon'
        QtMocHelpers::PropertyData<QString>(26, QMetaType::QString, QMC::DefaultPropertyFlags, 2),
        // property 'state'
        QtMocHelpers::PropertyData<qs::mac::bluetooth::BluetoothDeviceState::Enum>(27, 0x80000000 | 28, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 3),
        // property 'connected'
        QtMocHelpers::PropertyData<bool>(29, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'paired'
        QtMocHelpers::PropertyData<bool>(30, QMetaType::Bool, QMC::DefaultPropertyFlags, 4),
        // property 'bonded'
        QtMocHelpers::PropertyData<bool>(31, QMetaType::Bool, QMC::DefaultPropertyFlags, 4),
        // property 'pairing'
        QtMocHelpers::PropertyData<bool>(32, QMetaType::Bool, QMC::DefaultPropertyFlags, 5),
        // property 'trusted'
        QtMocHelpers::PropertyData<bool>(33, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'blocked'
        QtMocHelpers::PropertyData<bool>(34, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'wakeAllowed'
        QtMocHelpers::PropertyData<bool>(35, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 8),
        // property 'batteryAvailable'
        QtMocHelpers::PropertyData<bool>(36, QMetaType::Bool, QMC::DefaultPropertyFlags, 9),
        // property 'battery'
        QtMocHelpers::PropertyData<qreal>(37, QMetaType::QReal, QMC::DefaultPropertyFlags, 10),
        // property 'adapter'
        QtMocHelpers::PropertyData<qs::mac::bluetooth::BluetoothAdapter*>(38, 0x80000000 | 39, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<BluetoothDevice, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN2qs3mac9bluetooth15BluetoothDeviceE[] = {
    QMetaObject::SuperData::link<qs::mac::bluetooth::BluetoothDeviceState::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject qs::mac::bluetooth::BluetoothDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac9bluetooth15BluetoothDeviceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac9bluetooth15BluetoothDeviceE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN2qs3mac9bluetooth15BluetoothDeviceE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac9bluetooth15BluetoothDeviceE_t>.metaTypes,
    nullptr
} };

void qs::mac::bluetooth::BluetoothDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BluetoothDevice *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->addressChanged(); break;
        case 1: _t->nameChanged(); break;
        case 2: _t->iconChanged(); break;
        case 3: _t->stateChanged(); break;
        case 4: _t->pairedChanged(); break;
        case 5: _t->pairingChanged(); break;
        case 6: _t->trustedChanged(); break;
        case 7: _t->blockedChanged(); break;
        case 8: _t->wakeAllowedChanged(); break;
        case 9: _t->batteryAvailableChanged(); break;
        case 10: _t->batteryChanged(); break;
        case 11: _t->connect(); break;
        case 12: _t->disconnect(); break;
        case 13: _t->pair(); break;
        case 14: _t->cancelPair(); break;
        case 15: _t->forget(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (BluetoothDevice::*)()>(_a, &BluetoothDevice::addressChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (BluetoothDevice::*)()>(_a, &BluetoothDevice::nameChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (BluetoothDevice::*)()>(_a, &BluetoothDevice::iconChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (BluetoothDevice::*)()>(_a, &BluetoothDevice::stateChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (BluetoothDevice::*)()>(_a, &BluetoothDevice::pairedChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (BluetoothDevice::*)()>(_a, &BluetoothDevice::pairingChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (BluetoothDevice::*)()>(_a, &BluetoothDevice::trustedChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (BluetoothDevice::*)()>(_a, &BluetoothDevice::blockedChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (BluetoothDevice::*)()>(_a, &BluetoothDevice::wakeAllowedChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (BluetoothDevice::*)()>(_a, &BluetoothDevice::batteryAvailableChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (BluetoothDevice::*)()>(_a, &BluetoothDevice::batteryChanged, 10))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qs::mac::bluetooth::BluetoothAdapter* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->address(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->name(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->deviceName(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->icon(); break;
        case 4: *reinterpret_cast<qs::mac::bluetooth::BluetoothDeviceState::Enum*>(_v) = _t->state(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->connected(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->paired(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->paired(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->pairing(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->trusted(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->blocked(); break;
        case 11: *reinterpret_cast<bool*>(_v) = _t->wakeAllowed(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->batteryAvailable(); break;
        case 13: *reinterpret_cast<qreal*>(_v) = _t->battery(); break;
        case 14: *reinterpret_cast<qs::mac::bluetooth::BluetoothAdapter**>(_v) = _t->adapter(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setName(*reinterpret_cast<QString*>(_v)); break;
        case 5: _t->setConnected(*reinterpret_cast<bool*>(_v)); break;
        case 9: _t->setTrusted(*reinterpret_cast<bool*>(_v)); break;
        case 10: _t->setBlocked(*reinterpret_cast<bool*>(_v)); break;
        case 11: _t->setWakeAllowed(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::bluetooth::BluetoothDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::bluetooth::BluetoothDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac9bluetooth15BluetoothDeviceE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::bluetooth::BluetoothDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::bluetooth::BluetoothDevice::addressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::bluetooth::BluetoothDevice::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::mac::bluetooth::BluetoothDevice::iconChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::mac::bluetooth::BluetoothDevice::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qs::mac::bluetooth::BluetoothDevice::pairedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void qs::mac::bluetooth::BluetoothDevice::pairingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void qs::mac::bluetooth::BluetoothDevice::trustedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void qs::mac::bluetooth::BluetoothDevice::blockedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void qs::mac::bluetooth::BluetoothDevice::wakeAllowedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void qs::mac::bluetooth::BluetoothDevice::batteryAvailableChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void qs::mac::bluetooth::BluetoothDevice::batteryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac9bluetooth16BluetoothAdapterE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::bluetooth::BluetoothAdapter::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac9bluetooth16BluetoothAdapterE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::bluetooth::BluetoothAdapter",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "",
        "nameChanged",
        "stateChanged",
        "discoverableChanged",
        "discoveringChanged",
        "pairableChanged",
        "name",
        "enabled",
        "state",
        "qs::mac::bluetooth::BluetoothAdapterState::Enum",
        "discoverable",
        "discovering",
        "pairable",
        "devices",
        "UntypedObjectModel*",
        "adapterId"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'nameChanged'
        QtMocHelpers::SignalData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'stateChanged'
        QtMocHelpers::SignalData<void()>(8, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'discoverableChanged'
        QtMocHelpers::SignalData<void()>(9, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'discoveringChanged'
        QtMocHelpers::SignalData<void()>(10, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'pairableChanged'
        QtMocHelpers::SignalData<void()>(11, 6, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'name'
        QtMocHelpers::PropertyData<QString>(12, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'enabled'
        QtMocHelpers::PropertyData<bool>(13, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'state'
        QtMocHelpers::PropertyData<qs::mac::bluetooth::BluetoothAdapterState::Enum>(14, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 1),
        // property 'discoverable'
        QtMocHelpers::PropertyData<bool>(16, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'discovering'
        QtMocHelpers::PropertyData<bool>(17, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'pairable'
        QtMocHelpers::PropertyData<bool>(18, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'devices'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(19, 0x80000000 | 20, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'adapterId'
        QtMocHelpers::PropertyData<QString>(21, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<BluetoothAdapter, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN2qs3mac9bluetooth16BluetoothAdapterE[] = {
    QMetaObject::SuperData::link<qs::mac::bluetooth::BluetoothAdapterState::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject qs::mac::bluetooth::BluetoothAdapter::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac9bluetooth16BluetoothAdapterE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac9bluetooth16BluetoothAdapterE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN2qs3mac9bluetooth16BluetoothAdapterE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac9bluetooth16BluetoothAdapterE_t>.metaTypes,
    nullptr
} };

void qs::mac::bluetooth::BluetoothAdapter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BluetoothAdapter *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->nameChanged(); break;
        case 1: _t->stateChanged(); break;
        case 2: _t->discoverableChanged(); break;
        case 3: _t->discoveringChanged(); break;
        case 4: _t->pairableChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (BluetoothAdapter::*)()>(_a, &BluetoothAdapter::nameChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (BluetoothAdapter::*)()>(_a, &BluetoothAdapter::stateChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (BluetoothAdapter::*)()>(_a, &BluetoothAdapter::discoverableChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (BluetoothAdapter::*)()>(_a, &BluetoothAdapter::discoveringChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (BluetoothAdapter::*)()>(_a, &BluetoothAdapter::pairableChanged, 4))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< UntypedObjectModel* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->name(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->enabled(); break;
        case 2: *reinterpret_cast<qs::mac::bluetooth::BluetoothAdapterState::Enum*>(_v) = _t->state(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->discoverable(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->discovering(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->pairable(); break;
        case 6: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->devices(); break;
        case 7: *reinterpret_cast<QString*>(_v) = _t->adapterId(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setDiscoverable(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setDiscovering(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setPairable(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::bluetooth::BluetoothAdapter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::bluetooth::BluetoothAdapter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac9bluetooth16BluetoothAdapterE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::bluetooth::BluetoothAdapter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::bluetooth::BluetoothAdapter::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::bluetooth::BluetoothAdapter::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::mac::bluetooth::BluetoothAdapter::discoverableChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::mac::bluetooth::BluetoothAdapter::discoveringChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qs::mac::bluetooth::BluetoothAdapter::pairableChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac9bluetooth9BluetoothE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::bluetooth::Bluetooth::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac9bluetooth9BluetoothE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::bluetooth::Bluetooth",
        "QML.Element",
        "Bluetooth",
        "QML.Singleton",
        "true",
        "defaultAdapterChanged",
        "",
        "defaultAdapter",
        "qs::mac::bluetooth::BluetoothAdapter*",
        "adapters",
        "UntypedObjectModel*",
        "devices"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'defaultAdapterChanged'
        QtMocHelpers::SignalData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'defaultAdapter'
        QtMocHelpers::PropertyData<qs::mac::bluetooth::BluetoothAdapter*>(7, 0x80000000 | 8, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
        // property 'adapters'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(9, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'devices'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(11, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<Bluetooth, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::bluetooth::Bluetooth::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac9bluetooth9BluetoothE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac9bluetooth9BluetoothE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac9bluetooth9BluetoothE_t>.metaTypes,
    nullptr
} };

void qs::mac::bluetooth::Bluetooth::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Bluetooth *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->defaultAdapterChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Bluetooth::*)()>(_a, &Bluetooth::defaultAdapterChanged, 0))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< UntypedObjectModel* >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qs::mac::bluetooth::BluetoothAdapter* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qs::mac::bluetooth::BluetoothAdapter**>(_v) = _t->defaultAdapter(); break;
        case 1: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->adapters(); break;
        case 2: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->devices(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::bluetooth::Bluetooth::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::bluetooth::Bluetooth::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac9bluetooth9BluetoothE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::bluetooth::Bluetooth::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::bluetooth::Bluetooth::defaultAdapterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
