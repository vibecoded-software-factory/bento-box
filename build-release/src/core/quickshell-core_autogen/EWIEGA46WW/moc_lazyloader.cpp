/****************************************************************************
** Meta object code from reading C++ file 'lazyloader.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/lazyloader.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lazyloader.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10LazyLoaderE_t {};
} // unnamed namespace

template <> constexpr inline auto LazyLoader::qt_create_metaobjectdata<qt_meta_tag_ZN10LazyLoaderE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "LazyLoader",
        "DefaultProperty",
        "component",
        "QML.Element",
        "auto",
        "activeChanged",
        "",
        "loadingChanged",
        "itemChanged",
        "sourceChanged",
        "componentChanged",
        "onIncubationCompleted",
        "onIncubationFailed",
        "onComponentDestroyed",
        "item",
        "loading",
        "active",
        "activeAsync",
        "QQmlComponent*",
        "source"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'activeChanged'
        QtMocHelpers::SignalData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'loadingChanged'
        QtMocHelpers::SignalData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'itemChanged'
        QtMocHelpers::SignalData<void()>(8, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sourceChanged'
        QtMocHelpers::SignalData<void()>(9, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'componentChanged'
        QtMocHelpers::SignalData<void()>(10, 6, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onIncubationCompleted'
        QtMocHelpers::SlotData<void()>(11, 6, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onIncubationFailed'
        QtMocHelpers::SlotData<void()>(12, 6, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onComponentDestroyed'
        QtMocHelpers::SlotData<void()>(13, 6, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'item'
        QtMocHelpers::PropertyData<QObject*>(14, QMetaType::QObjectStar, QMC::DefaultPropertyFlags, 2),
        // property 'loading'
        QtMocHelpers::PropertyData<bool>(15, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'active'
        QtMocHelpers::PropertyData<bool>(16, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'activeAsync'
        QtMocHelpers::PropertyData<bool>(17, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'component'
        QtMocHelpers::PropertyData<QQmlComponent*>(2, 0x80000000 | 18, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 4),
        // property 'source'
        QtMocHelpers::PropertyData<QString>(19, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<LazyLoader, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject LazyLoader::staticMetaObject = { {
    QMetaObject::SuperData::link<Reloadable::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10LazyLoaderE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10LazyLoaderE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10LazyLoaderE_t>.metaTypes,
    nullptr
} };

void LazyLoader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<LazyLoader *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->activeChanged(); break;
        case 1: _t->loadingChanged(); break;
        case 2: _t->itemChanged(); break;
        case 3: _t->sourceChanged(); break;
        case 4: _t->componentChanged(); break;
        case 5: _t->onIncubationCompleted(); break;
        case 6: _t->onIncubationFailed(); break;
        case 7: _t->onComponentDestroyed(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (LazyLoader::*)()>(_a, &LazyLoader::activeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (LazyLoader::*)()>(_a, &LazyLoader::loadingChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (LazyLoader::*)()>(_a, &LazyLoader::itemChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (LazyLoader::*)()>(_a, &LazyLoader::sourceChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (LazyLoader::*)()>(_a, &LazyLoader::componentChanged, 4))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQmlComponent* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QObject**>(_v) = _t->item(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isLoading(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isActive(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->isActive(); break;
        case 4: *reinterpret_cast<QQmlComponent**>(_v) = _t->component(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->source(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setLoading(*reinterpret_cast<bool*>(_v)); break;
        case 2: _t->setActive(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setActiveAsync(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setComponent(*reinterpret_cast<QQmlComponent**>(_v)); break;
        case 5: _t->setSource(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *LazyLoader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LazyLoader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10LazyLoaderE_t>.strings))
        return static_cast<void*>(this);
    return Reloadable::qt_metacast(_clname);
}

int LazyLoader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Reloadable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
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
void LazyLoader::activeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LazyLoader::loadingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LazyLoader::itemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void LazyLoader::sourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void LazyLoader::componentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
