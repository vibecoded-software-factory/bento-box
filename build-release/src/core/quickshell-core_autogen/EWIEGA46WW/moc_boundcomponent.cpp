/****************************************************************************
** Meta object code from reading C++ file 'boundcomponent.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/boundcomponent.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boundcomponent.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14BoundComponentE_t {};
} // unnamed namespace

template <> constexpr inline auto BoundComponent::qt_create_metaobjectdata<qt_meta_tag_ZN14BoundComponentE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "BoundComponent",
        "QML.Element",
        "auto",
        "loaded",
        "",
        "sourceComponentChanged",
        "sourceChanged",
        "bindValuesChanged",
        "onComponentDestroyed",
        "onIncubationCompleted",
        "onIncubationFailed",
        "updateSize",
        "updateImplicitSize",
        "implicitWidthChanged",
        "implicitHeightChanged",
        "item",
        "sourceComponent",
        "QQmlComponent*",
        "source",
        "bindValues",
        "implicitWidth",
        "implicitHeight"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'loaded'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sourceComponentChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sourceChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'bindValuesChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onComponentDestroyed'
        QtMocHelpers::SlotData<void()>(8, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onIncubationCompleted'
        QtMocHelpers::SlotData<void()>(9, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onIncubationFailed'
        QtMocHelpers::SlotData<void()>(10, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updateSize'
        QtMocHelpers::SlotData<void()>(11, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'updateImplicitSize'
        QtMocHelpers::SlotData<void()>(12, 4, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'item'
        QtMocHelpers::PropertyData<QObject*>(15, QMetaType::QObjectStar, QMC::DefaultPropertyFlags, 0),
        // property 'sourceComponent'
        QtMocHelpers::PropertyData<QQmlComponent*>(16, 0x80000000 | 17, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 1),
        // property 'source'
        QtMocHelpers::PropertyData<QString>(18, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'bindValues'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'implicitWidth'
        QtMocHelpers::PropertyData<qreal>(20, QMetaType::QReal, QMC::DefaultPropertyFlags, 0x70000000 | 13),
        // property 'implicitHeight'
        QtMocHelpers::PropertyData<qreal>(21, QMetaType::QReal, QMC::DefaultPropertyFlags, 0x70000000 | 14),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<BoundComponent, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject BoundComponent::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14BoundComponentE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14BoundComponentE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14BoundComponentE_t>.metaTypes,
    nullptr
} };

void BoundComponent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BoundComponent *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->loaded(); break;
        case 1: _t->sourceComponentChanged(); break;
        case 2: _t->sourceChanged(); break;
        case 3: _t->bindValuesChanged(); break;
        case 4: _t->onComponentDestroyed(); break;
        case 5: _t->onIncubationCompleted(); break;
        case 6: _t->onIncubationFailed(); break;
        case 7: _t->updateSize(); break;
        case 8: _t->updateImplicitSize(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (BoundComponent::*)()>(_a, &BoundComponent::loaded, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (BoundComponent::*)()>(_a, &BoundComponent::sourceComponentChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (BoundComponent::*)()>(_a, &BoundComponent::sourceChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (BoundComponent::*)()>(_a, &BoundComponent::bindValuesChanged, 3))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQmlComponent* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QObject**>(_v) = _t->item(); break;
        case 1: *reinterpret_cast<QQmlComponent**>(_v) = _t->sourceComponent(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->source(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->bindValues(); break;
        case 4: *reinterpret_cast<qreal*>(_v) = _t->implicitWidth(); break;
        case 5: *reinterpret_cast<qreal*>(_v) = _t->implicitHeight(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setSourceComponent(*reinterpret_cast<QQmlComponent**>(_v)); break;
        case 2: _t->setSource(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->setBindValues(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *BoundComponent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BoundComponent::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14BoundComponentE_t>.strings))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int BoundComponent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
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
void BoundComponent::loaded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BoundComponent::sourceComponentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BoundComponent::sourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BoundComponent::bindValuesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
namespace CheckNotifySignalValidity_ZN14BoundComponentE {
template<typename T> using has_nullary_implicitWidthChanged = decltype(std::declval<T>().implicitWidthChanged());
template<typename T> using has_unary_implicitWidthChanged = decltype(std::declval<T>().implicitWidthChanged(std::declval<qreal>()));
static_assert(qxp::is_detected_v<has_nullary_implicitWidthChanged, BoundComponent> || qxp::is_detected_v<has_unary_implicitWidthChanged, BoundComponent>,
              "NOTIFY signal implicitWidthChanged does not exist in class (or is private in its parent)");
template<typename T> using has_nullary_implicitHeightChanged = decltype(std::declval<T>().implicitHeightChanged());
template<typename T> using has_unary_implicitHeightChanged = decltype(std::declval<T>().implicitHeightChanged(std::declval<qreal>()));
static_assert(qxp::is_detected_v<has_nullary_implicitHeightChanged, BoundComponent> || qxp::is_detected_v<has_unary_implicitHeightChanged, BoundComponent>,
              "NOTIFY signal implicitHeightChanged does not exist in class (or is private in its parent)");
}
namespace {
struct qt_meta_tag_ZN27BoundComponentPropertyProxyE_t {};
} // unnamed namespace

template <> constexpr inline auto BoundComponentPropertyProxy::qt_create_metaobjectdata<qt_meta_tag_ZN27BoundComponentPropertyProxyE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "BoundComponentPropertyProxy",
        "onNotified",
        ""
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'onNotified'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<BoundComponentPropertyProxy, qt_meta_tag_ZN27BoundComponentPropertyProxyE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject BoundComponentPropertyProxy::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27BoundComponentPropertyProxyE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27BoundComponentPropertyProxyE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN27BoundComponentPropertyProxyE_t>.metaTypes,
    nullptr
} };

void BoundComponentPropertyProxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BoundComponentPropertyProxy *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onNotified(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *BoundComponentPropertyProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BoundComponentPropertyProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27BoundComponentPropertyProxyE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BoundComponentPropertyProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
