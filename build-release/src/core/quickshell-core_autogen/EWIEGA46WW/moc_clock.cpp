/****************************************************************************
** Meta object code from reading C++ file 'clock.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/clock.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clock.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11SystemClockE_t {};
} // unnamed namespace

template <> constexpr inline auto SystemClock::qt_create_metaobjectdata<qt_meta_tag_ZN11SystemClockE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SystemClock",
        "QML.Element",
        "auto",
        "enabledChanged",
        "",
        "precisionChanged",
        "dateChanged",
        "onTimeout",
        "enabled",
        "precision",
        "SystemClock::Enum",
        "date",
        "hours",
        "minutes",
        "seconds",
        "Enum",
        "Hours",
        "Minutes",
        "Seconds"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'enabledChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'precisionChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'dateChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onTimeout'
        QtMocHelpers::SlotData<void()>(7, 4, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'enabled'
        QtMocHelpers::PropertyData<bool>(8, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'precision'
        QtMocHelpers::PropertyData<SystemClock::Enum>(9, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 1),
        // property 'date'
        QtMocHelpers::PropertyData<QDateTime>(11, QMetaType::QDateTime, QMC::DefaultPropertyFlags, 2),
        // property 'hours'
        QtMocHelpers::PropertyData<quint32>(12, QMetaType::UInt, QMC::DefaultPropertyFlags, 2),
        // property 'minutes'
        QtMocHelpers::PropertyData<quint32>(13, QMetaType::UInt, QMC::DefaultPropertyFlags, 2),
        // property 'seconds'
        QtMocHelpers::PropertyData<quint32>(14, QMetaType::UInt, QMC::DefaultPropertyFlags, 2),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<enum Enum>(15, 15, QMC::EnumFlags{}).add({
            {   16, Enum::Hours },
            {   17, Enum::Minutes },
            {   18, Enum::Seconds },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<SystemClock, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject SystemClock::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11SystemClockE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11SystemClockE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11SystemClockE_t>.metaTypes,
    nullptr
} };

void SystemClock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SystemClock *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->enabledChanged(); break;
        case 1: _t->precisionChanged(); break;
        case 2: _t->dateChanged(); break;
        case 3: _t->onTimeout(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SystemClock::*)()>(_a, &SystemClock::enabledChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (SystemClock::*)()>(_a, &SystemClock::precisionChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (SystemClock::*)()>(_a, &SystemClock::dateChanged, 2))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->enabled(); break;
        case 1: *reinterpret_cast<SystemClock::Enum*>(_v) = _t->precision(); break;
        case 2: *reinterpret_cast<QDateTime*>(_v) = _t->date(); break;
        case 3: *reinterpret_cast<quint32*>(_v) = _t->hours(); break;
        case 4: *reinterpret_cast<quint32*>(_v) = _t->minutes(); break;
        case 5: *reinterpret_cast<quint32*>(_v) = _t->seconds(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setPrecision(*reinterpret_cast<SystemClock::Enum*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *SystemClock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SystemClock::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11SystemClockE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SystemClock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SystemClock::enabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SystemClock::precisionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SystemClock::dateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
