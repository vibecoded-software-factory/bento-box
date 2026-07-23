/****************************************************************************
** Meta object code from reading C++ file 'variants.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/variants.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'variants.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8VariantsE_t {};
} // unnamed namespace

template <> constexpr inline auto Variants::qt_create_metaobjectdata<qt_meta_tag_ZN8VariantsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Variants",
        "DefaultProperty",
        "delegate",
        "QML.Element",
        "auto",
        "modelChanged",
        "",
        "instancesChanged",
        "QQmlComponent*",
        "model",
        "QVariant",
        "instances",
        "QQmlListProperty<QObject>"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'modelChanged'
        QtMocHelpers::SignalData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'instancesChanged'
        QtMocHelpers::SignalData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'delegate'
        QtMocHelpers::PropertyData<QQmlComponent*>(2, 0x80000000 | 8, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag),
        // property 'model'
        QtMocHelpers::PropertyData<QVariant>(9, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 0),
        // property 'instances'
        QtMocHelpers::PropertyData<QQmlListProperty<QObject>>(11, 0x80000000 | 12, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 1),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<Variants, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject Variants::staticMetaObject = { {
    QMetaObject::SuperData::link<Reloadable::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8VariantsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8VariantsE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8VariantsE_t>.metaTypes,
    nullptr
} };

void Variants::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Variants *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->modelChanged(); break;
        case 1: _t->instancesChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Variants::*)()>(_a, &Variants::modelChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Variants::*)()>(_a, &Variants::instancesChanged, 1))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQmlComponent* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QQmlComponent**>(_v) = _t->mDelegate; break;
        case 1: *reinterpret_cast<QVariant*>(_v) = _t->model(); break;
        case 2: *reinterpret_cast<QQmlListProperty<QObject>*>(_v) = _t->instances(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: QtMocHelpers::setProperty(_t->mDelegate, *reinterpret_cast<QQmlComponent**>(_v)); break;
        case 1: _t->setModel(*reinterpret_cast<QVariant*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *Variants::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Variants::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8VariantsE_t>.strings))
        return static_cast<void*>(this);
    return Reloadable::qt_metacast(_clname);
}

int Variants::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Reloadable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
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
void Variants::modelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Variants::instancesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
