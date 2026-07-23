/****************************************************************************
** Meta object code from reading C++ file 'retainable.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/retainable.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'retainable.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14RetainableHookE_t {};
} // unnamed namespace

template <> constexpr inline auto RetainableHook::qt_create_metaobjectdata<qt_meta_tag_ZN14RetainableHookE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "RetainableHook",
        "QML.Attached",
        "QML.Element",
        "Retainable",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "Retainable can only be used as an attached object.",
        "dropped",
        "",
        "aboutToDestroy",
        "retainedChanged",
        "lock",
        "unlock",
        "forceUnlock",
        "retained"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'dropped'
        QtMocHelpers::SignalData<void()>(8, 9, QMC::AccessPublic, QMetaType::Void),
        // Signal 'aboutToDestroy'
        QtMocHelpers::SignalData<void()>(10, 9, QMC::AccessPublic, QMetaType::Void),
        // Signal 'retainedChanged'
        QtMocHelpers::SignalData<void()>(11, 9, QMC::AccessPublic, QMetaType::Void),
        // Method 'lock'
        QtMocHelpers::MethodData<void()>(12, 9, QMC::AccessPublic, QMetaType::Void),
        // Method 'unlock'
        QtMocHelpers::MethodData<void()>(13, 9, QMC::AccessPublic, QMetaType::Void),
        // Method 'forceUnlock'
        QtMocHelpers::MethodData<void()>(14, 9, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'retained'
        QtMocHelpers::PropertyData<bool>(15, QMetaType::Bool, QMC::DefaultPropertyFlags, 2),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    0 },
            {    2,    3 },
            {    4,    5 },
            {    6,    7 },
    });
    return QtMocHelpers::metaObjectData<RetainableHook, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject RetainableHook::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14RetainableHookE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14RetainableHookE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14RetainableHookE_t>.metaTypes,
    nullptr
} };

void RetainableHook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<RetainableHook *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->dropped(); break;
        case 1: _t->aboutToDestroy(); break;
        case 2: _t->retainedChanged(); break;
        case 3: _t->lock(); break;
        case 4: _t->unlock(); break;
        case 5: _t->forceUnlock(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (RetainableHook::*)()>(_a, &RetainableHook::dropped, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (RetainableHook::*)()>(_a, &RetainableHook::aboutToDestroy, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (RetainableHook::*)()>(_a, &RetainableHook::retainedChanged, 2))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isRetained(); break;
        default: break;
        }
    }
}

const QMetaObject *RetainableHook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RetainableHook::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14RetainableHookE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RetainableHook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void RetainableHook::dropped()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RetainableHook::aboutToDestroy()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void RetainableHook::retainedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
namespace {
struct qt_meta_tag_ZN14RetainableLockE_t {};
} // unnamed namespace

template <> constexpr inline auto RetainableLock::qt_create_metaobjectdata<qt_meta_tag_ZN14RetainableLockE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "RetainableLock",
        "QML.Element",
        "auto",
        "dropped",
        "",
        "aboutToDestroy",
        "retainedChanged",
        "objectChanged",
        "lockedChanged",
        "onObjectDestroyed",
        "object",
        "locked",
        "retained"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'dropped'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'aboutToDestroy'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'retainedChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'objectChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'lockedChanged'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onObjectDestroyed'
        QtMocHelpers::SlotData<void()>(9, 4, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'object'
        QtMocHelpers::PropertyData<QObject*>(10, QMetaType::QObjectStar, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'locked'
        QtMocHelpers::PropertyData<bool>(11, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'retained'
        QtMocHelpers::PropertyData<bool>(12, QMetaType::Bool, QMC::DefaultPropertyFlags, 2),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<RetainableLock, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject RetainableLock::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14RetainableLockE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14RetainableLockE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14RetainableLockE_t>.metaTypes,
    nullptr
} };

void RetainableLock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<RetainableLock *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->dropped(); break;
        case 1: _t->aboutToDestroy(); break;
        case 2: _t->retainedChanged(); break;
        case 3: _t->objectChanged(); break;
        case 4: _t->lockedChanged(); break;
        case 5: _t->onObjectDestroyed(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (RetainableLock::*)()>(_a, &RetainableLock::dropped, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (RetainableLock::*)()>(_a, &RetainableLock::aboutToDestroy, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (RetainableLock::*)()>(_a, &RetainableLock::retainedChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (RetainableLock::*)()>(_a, &RetainableLock::objectChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (RetainableLock::*)()>(_a, &RetainableLock::lockedChanged, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QObject**>(_v) = _t->object(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->locked(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isRetained(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setObject(*reinterpret_cast<QObject**>(_v)); break;
        case 1: _t->setLocked(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *RetainableLock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RetainableLock::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14RetainableLockE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RetainableLock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
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
void RetainableLock::dropped()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RetainableLock::aboutToDestroy()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void RetainableLock::retainedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void RetainableLock::objectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void RetainableLock::lockedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
