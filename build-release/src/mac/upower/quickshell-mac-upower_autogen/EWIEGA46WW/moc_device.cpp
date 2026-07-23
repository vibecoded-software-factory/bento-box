/****************************************************************************
** Meta object code from reading C++ file 'device.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/upower/device.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'device.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs3mac6upower17UPowerDeviceStateE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::upower::UPowerDeviceState::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac6upower17UPowerDeviceStateE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::upower::UPowerDeviceState",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "toString",
        "",
        "qs::mac::upower::UPowerDeviceState::Enum",
        "status",
        "Enum",
        "Unknown",
        "Charging",
        "Discharging",
        "Empty",
        "FullyCharged",
        "PendingCharge",
        "PendingDischarge"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'toString'
        QtMocHelpers::MethodData<QString(qs::mac::upower::UPowerDeviceState::Enum)>(5, 6, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 7, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<enum Enum>(9, 9, QMC::EnumFlags{}).add({
            {   10, Enum::Unknown },
            {   11, Enum::Charging },
            {   12, Enum::Discharging },
            {   13, Enum::Empty },
            {   14, Enum::FullyCharged },
            {   15, Enum::PendingCharge },
            {   16, Enum::PendingDischarge },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<UPowerDeviceState, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::upower::UPowerDeviceState::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac6upower17UPowerDeviceStateE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac6upower17UPowerDeviceStateE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac6upower17UPowerDeviceStateE_t>.metaTypes,
    nullptr
} };

void qs::mac::upower::UPowerDeviceState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<UPowerDeviceState *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = _t->toString((*reinterpret_cast<std::add_pointer_t<qs::mac::upower::UPowerDeviceState::Enum>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *qs::mac::upower::UPowerDeviceState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::upower::UPowerDeviceState::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac6upower17UPowerDeviceStateE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::upower::UPowerDeviceState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_tag_ZN2qs3mac6upower16UPowerDeviceTypeE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::upower::UPowerDeviceType::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac6upower16UPowerDeviceTypeE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::upower::UPowerDeviceType",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "toString",
        "",
        "qs::mac::upower::UPowerDeviceType::Enum",
        "type",
        "Enum",
        "Unknown",
        "LinePower",
        "Battery",
        "Ups",
        "Monitor",
        "Mouse",
        "Keyboard",
        "Pda",
        "Phone",
        "MediaPlayer",
        "Tablet",
        "Computer",
        "GamingInput",
        "Pen",
        "Touchpad",
        "Modem",
        "Network",
        "Headset",
        "Speakers",
        "Headphones",
        "Video",
        "OtherAudio",
        "RemoteControl",
        "Printer",
        "Scanner",
        "Camera",
        "Wearable",
        "Toy",
        "BluetoothGeneric"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'toString'
        QtMocHelpers::MethodData<QString(qs::mac::upower::UPowerDeviceType::Enum)>(5, 6, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 7, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<enum Enum>(9, 9, QMC::EnumFlags{}).add({
            {   10, Enum::Unknown },
            {   11, Enum::LinePower },
            {   12, Enum::Battery },
            {   13, Enum::Ups },
            {   14, Enum::Monitor },
            {   15, Enum::Mouse },
            {   16, Enum::Keyboard },
            {   17, Enum::Pda },
            {   18, Enum::Phone },
            {   19, Enum::MediaPlayer },
            {   20, Enum::Tablet },
            {   21, Enum::Computer },
            {   22, Enum::GamingInput },
            {   23, Enum::Pen },
            {   24, Enum::Touchpad },
            {   25, Enum::Modem },
            {   26, Enum::Network },
            {   27, Enum::Headset },
            {   28, Enum::Speakers },
            {   29, Enum::Headphones },
            {   30, Enum::Video },
            {   31, Enum::OtherAudio },
            {   32, Enum::RemoteControl },
            {   33, Enum::Printer },
            {   34, Enum::Scanner },
            {   35, Enum::Camera },
            {   36, Enum::Wearable },
            {   37, Enum::Toy },
            {   38, Enum::BluetoothGeneric },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<UPowerDeviceType, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::upower::UPowerDeviceType::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac6upower16UPowerDeviceTypeE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac6upower16UPowerDeviceTypeE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac6upower16UPowerDeviceTypeE_t>.metaTypes,
    nullptr
} };

void qs::mac::upower::UPowerDeviceType::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<UPowerDeviceType *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = _t->toString((*reinterpret_cast<std::add_pointer_t<qs::mac::upower::UPowerDeviceType::Enum>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *qs::mac::upower::UPowerDeviceType::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::upower::UPowerDeviceType::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac6upower16UPowerDeviceTypeE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::upower::UPowerDeviceType::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_tag_ZN2qs3mac6upower12UPowerDeviceE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::upower::UPowerDevice::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac6upower12UPowerDeviceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::upower::UPowerDevice",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "UPowerDevices can only be acquired from UPower",
        "readyChanged",
        "",
        "typeChanged",
        "powerSupplyChanged",
        "energyChanged",
        "energyCapacityChanged",
        "changeRateChanged",
        "timeToEmptyChanged",
        "timeToFullChanged",
        "percentageChanged",
        "isPresentChanged",
        "stateChanged",
        "healthPercentageChanged",
        "healthSupportedChanged",
        "iconNameChanged",
        "isLaptopBatteryChanged",
        "nativePathChanged",
        "modelChanged",
        "type",
        "qs::mac::upower::UPowerDeviceType::Enum",
        "powerSupply",
        "energy",
        "energyCapacity",
        "changeRate",
        "timeToEmpty",
        "timeToFull",
        "percentage",
        "isPresent",
        "state",
        "qs::mac::upower::UPowerDeviceState::Enum",
        "healthPercentage",
        "healthSupported",
        "iconName",
        "isLaptopBattery",
        "nativePath",
        "model",
        "ready"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'readyChanged'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'typeChanged'
        QtMocHelpers::SignalData<void()>(9, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'powerSupplyChanged'
        QtMocHelpers::SignalData<void()>(10, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'energyChanged'
        QtMocHelpers::SignalData<void()>(11, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'energyCapacityChanged'
        QtMocHelpers::SignalData<void()>(12, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'changeRateChanged'
        QtMocHelpers::SignalData<void()>(13, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'timeToEmptyChanged'
        QtMocHelpers::SignalData<void()>(14, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'timeToFullChanged'
        QtMocHelpers::SignalData<void()>(15, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'percentageChanged'
        QtMocHelpers::SignalData<void()>(16, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isPresentChanged'
        QtMocHelpers::SignalData<void()>(17, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'stateChanged'
        QtMocHelpers::SignalData<void()>(18, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'healthPercentageChanged'
        QtMocHelpers::SignalData<void()>(19, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'healthSupportedChanged'
        QtMocHelpers::SignalData<void()>(20, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'iconNameChanged'
        QtMocHelpers::SignalData<void()>(21, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isLaptopBatteryChanged'
        QtMocHelpers::SignalData<void()>(22, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'nativePathChanged'
        QtMocHelpers::SignalData<void()>(23, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'modelChanged'
        QtMocHelpers::SignalData<void()>(24, 8, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'type'
        QtMocHelpers::PropertyData<qs::mac::upower::UPowerDeviceType::Enum>(25, 0x80000000 | 26, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Bindable, 1),
        // property 'powerSupply'
        QtMocHelpers::PropertyData<bool>(27, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 2),
        // property 'energy'
        QtMocHelpers::PropertyData<qreal>(28, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Bindable, 3),
        // property 'energyCapacity'
        QtMocHelpers::PropertyData<qreal>(29, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Bindable, 4),
        // property 'changeRate'
        QtMocHelpers::PropertyData<qreal>(30, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Bindable, 5),
        // property 'timeToEmpty'
        QtMocHelpers::PropertyData<qreal>(31, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Bindable, 6),
        // property 'timeToFull'
        QtMocHelpers::PropertyData<qreal>(32, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Bindable, 7),
        // property 'percentage'
        QtMocHelpers::PropertyData<qreal>(33, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Bindable, 8),
        // property 'isPresent'
        QtMocHelpers::PropertyData<bool>(34, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 9),
        // property 'state'
        QtMocHelpers::PropertyData<qs::mac::upower::UPowerDeviceState::Enum>(35, 0x80000000 | 36, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Bindable, 10),
        // property 'healthPercentage'
        QtMocHelpers::PropertyData<qreal>(37, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Bindable, 11),
        // property 'healthSupported'
        QtMocHelpers::PropertyData<bool>(38, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 12),
        // property 'iconName'
        QtMocHelpers::PropertyData<QString>(39, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Bindable, 13),
        // property 'isLaptopBattery'
        QtMocHelpers::PropertyData<bool>(40, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 14),
        // property 'nativePath'
        QtMocHelpers::PropertyData<QString>(41, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Bindable, 15),
        // property 'model'
        QtMocHelpers::PropertyData<QString>(42, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Bindable, 16),
        // property 'ready'
        QtMocHelpers::PropertyData<bool>(43, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<UPowerDevice, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN2qs3mac6upower12UPowerDeviceE[] = {
    QMetaObject::SuperData::link<qs::mac::upower::UPowerDeviceType::staticMetaObject>(),
    QMetaObject::SuperData::link<qs::mac::upower::UPowerDeviceState::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject qs::mac::upower::UPowerDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac6upower12UPowerDeviceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac6upower12UPowerDeviceE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN2qs3mac6upower12UPowerDeviceE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac6upower12UPowerDeviceE_t>.metaTypes,
    nullptr
} };

void qs::mac::upower::UPowerDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<UPowerDevice *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->readyChanged(); break;
        case 1: _t->typeChanged(); break;
        case 2: _t->powerSupplyChanged(); break;
        case 3: _t->energyChanged(); break;
        case 4: _t->energyCapacityChanged(); break;
        case 5: _t->changeRateChanged(); break;
        case 6: _t->timeToEmptyChanged(); break;
        case 7: _t->timeToFullChanged(); break;
        case 8: _t->percentageChanged(); break;
        case 9: _t->isPresentChanged(); break;
        case 10: _t->stateChanged(); break;
        case 11: _t->healthPercentageChanged(); break;
        case 12: _t->healthSupportedChanged(); break;
        case 13: _t->iconNameChanged(); break;
        case 14: _t->isLaptopBatteryChanged(); break;
        case 15: _t->nativePathChanged(); break;
        case 16: _t->modelChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::readyChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::typeChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::powerSupplyChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::energyChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::energyCapacityChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::changeRateChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::timeToEmptyChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::timeToFullChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::percentageChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::isPresentChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::stateChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::healthPercentageChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::healthSupportedChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::iconNameChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::isLaptopBatteryChanged, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::nativePathChanged, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (UPowerDevice::*)()>(_a, &UPowerDevice::modelChanged, 16))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qs::mac::upower::UPowerDeviceType::Enum*>(_v) = _t->bindableType().value(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->bindablePowerSupply().value(); break;
        case 2: *reinterpret_cast<qreal*>(_v) = _t->bindableEnergy().value(); break;
        case 3: *reinterpret_cast<qreal*>(_v) = _t->bindableEnergyCapacity().value(); break;
        case 4: *reinterpret_cast<qreal*>(_v) = _t->bindableChangeRate().value(); break;
        case 5: *reinterpret_cast<qreal*>(_v) = _t->bindableTimeToEmpty().value(); break;
        case 6: *reinterpret_cast<qreal*>(_v) = _t->bindableTimeToFull().value(); break;
        case 7: *reinterpret_cast<qreal*>(_v) = _t->bindablePercentage().value(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->bindableIsPresent().value(); break;
        case 9: *reinterpret_cast<qs::mac::upower::UPowerDeviceState::Enum*>(_v) = _t->bindableState().value(); break;
        case 10: *reinterpret_cast<qreal*>(_v) = _t->bindableHealthPercentage().value(); break;
        case 11: *reinterpret_cast<bool*>(_v) = _t->bindableHealthSupported().value(); break;
        case 12: *reinterpret_cast<QString*>(_v) = _t->bindableIconName().value(); break;
        case 13: *reinterpret_cast<bool*>(_v) = _t->bindableIsLaptopBattery().value(); break;
        case 14: *reinterpret_cast<QString*>(_v) = _t->bindableNativePath().value(); break;
        case 15: *reinterpret_cast<QString*>(_v) = _t->bindableModel().value(); break;
        case 16: *reinterpret_cast<bool*>(_v) = _t->bindableReady().value(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableType(); break;
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindablePowerSupply(); break;
        case 2: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableEnergy(); break;
        case 3: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableEnergyCapacity(); break;
        case 4: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableChangeRate(); break;
        case 5: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableTimeToEmpty(); break;
        case 6: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableTimeToFull(); break;
        case 7: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindablePercentage(); break;
        case 8: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableIsPresent(); break;
        case 9: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableState(); break;
        case 10: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableHealthPercentage(); break;
        case 11: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableHealthSupported(); break;
        case 12: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableIconName(); break;
        case 13: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableIsLaptopBattery(); break;
        case 14: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableNativePath(); break;
        case 15: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableModel(); break;
        case 16: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableReady(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::upower::UPowerDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::upower::UPowerDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac6upower12UPowerDeviceE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::upower::UPowerDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::upower::UPowerDevice::readyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::upower::UPowerDevice::typeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::mac::upower::UPowerDevice::powerSupplyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::mac::upower::UPowerDevice::energyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qs::mac::upower::UPowerDevice::energyCapacityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void qs::mac::upower::UPowerDevice::changeRateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void qs::mac::upower::UPowerDevice::timeToEmptyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void qs::mac::upower::UPowerDevice::timeToFullChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void qs::mac::upower::UPowerDevice::percentageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void qs::mac::upower::UPowerDevice::isPresentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void qs::mac::upower::UPowerDevice::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void qs::mac::upower::UPowerDevice::healthPercentageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void qs::mac::upower::UPowerDevice::healthSupportedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void qs::mac::upower::UPowerDevice::iconNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void qs::mac::upower::UPowerDevice::isLaptopBatteryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void qs::mac::upower::UPowerDevice::nativePathChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void qs::mac::upower::UPowerDevice::modelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}
QT_WARNING_POP
