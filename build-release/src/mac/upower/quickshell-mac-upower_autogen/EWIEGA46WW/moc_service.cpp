/****************************************************************************
** Meta object code from reading C++ file 'service.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/upower/service.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'service.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs3mac6upower6UPowerE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::upower::UPower::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac6upower6UPowerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::upower::UPower",
        "onBatteryChanged",
        ""
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'onBatteryChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<UPower, qt_meta_tag_ZN2qs3mac6upower6UPowerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject qs::mac::upower::UPower::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac6upower6UPowerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac6upower6UPowerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac6upower6UPowerE_t>.metaTypes,
    nullptr
} };

void qs::mac::upower::UPower::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<UPower *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onBatteryChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (UPower::*)()>(_a, &UPower::onBatteryChanged, 0))
            return;
    }
}

const QMetaObject *qs::mac::upower::UPower::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::upower::UPower::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac6upower6UPowerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::upower::UPower::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void qs::mac::upower::UPower::onBatteryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac6upower9UPowerQmlE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::upower::UPowerQml::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac6upower9UPowerQmlE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::upower::UPowerQml",
        "QML.Element",
        "UPower",
        "QML.Singleton",
        "true",
        "onBatteryChanged",
        "",
        "displayDevice",
        "qs::mac::upower::UPowerDevice*",
        "devices",
        "UntypedObjectModel*",
        "onBattery"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'onBatteryChanged'
        QtMocHelpers::SignalData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'displayDevice'
        QtMocHelpers::PropertyData<qs::mac::upower::UPowerDevice*>(7, 0x80000000 | 8, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'devices'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(9, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'onBattery'
        QtMocHelpers::PropertyData<bool>(11, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<UPowerQml, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::upower::UPowerQml::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac6upower9UPowerQmlE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac6upower9UPowerQmlE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac6upower9UPowerQmlE_t>.metaTypes,
    nullptr
} };

void qs::mac::upower::UPowerQml::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<UPowerQml *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onBatteryChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (UPowerQml::*)()>(_a, &UPowerQml::onBatteryChanged, 0))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< UntypedObjectModel* >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qs::mac::upower::UPowerDevice* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qs::mac::upower::UPowerDevice**>(_v) = _t->displayDevice(); break;
        case 1: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->devices(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->bindableOnBattery().value(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 2: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableOnBattery(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::upower::UPowerQml::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::upower::UPowerQml::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac6upower9UPowerQmlE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::upower::UPowerQml::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void qs::mac::upower::UPowerQml::onBatteryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
