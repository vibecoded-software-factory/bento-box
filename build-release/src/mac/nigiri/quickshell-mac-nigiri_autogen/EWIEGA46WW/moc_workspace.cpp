/****************************************************************************
** Meta object code from reading C++ file 'workspace.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/nigiri/workspace.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workspace.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs6nigiri15NigiriWorkspaceE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::nigiri::NigiriWorkspace::qt_create_metaobjectdata<qt_meta_tag_ZN2qs6nigiri15NigiriWorkspaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::nigiri::NigiriWorkspace",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "NigiriWorkspaces are retrieved from the Nigiri singleton.",
        "idChanged",
        "",
        "idxChanged",
        "nameChanged",
        "activeChanged",
        "focusedChanged",
        "activate",
        "id",
        "idx",
        "name",
        "active",
        "focused"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'idChanged'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'idxChanged'
        QtMocHelpers::SignalData<void()>(9, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'nameChanged'
        QtMocHelpers::SignalData<void()>(10, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'activeChanged'
        QtMocHelpers::SignalData<void()>(11, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'focusedChanged'
        QtMocHelpers::SignalData<void()>(12, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'activate'
        QtMocHelpers::MethodData<void()>(13, 8, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'id'
        QtMocHelpers::PropertyData<qint32>(14, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Bindable, 0),
        // property 'idx'
        QtMocHelpers::PropertyData<qint32>(15, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Bindable, 1),
        // property 'name'
        QtMocHelpers::PropertyData<QString>(16, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Bindable, 2),
        // property 'active'
        QtMocHelpers::PropertyData<bool>(17, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 3),
        // property 'focused'
        QtMocHelpers::PropertyData<bool>(18, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 4),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<NigiriWorkspace, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::nigiri::NigiriWorkspace::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs6nigiri15NigiriWorkspaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs6nigiri15NigiriWorkspaceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs6nigiri15NigiriWorkspaceE_t>.metaTypes,
    nullptr
} };

void qs::nigiri::NigiriWorkspace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NigiriWorkspace *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->idChanged(); break;
        case 1: _t->idxChanged(); break;
        case 2: _t->nameChanged(); break;
        case 3: _t->activeChanged(); break;
        case 4: _t->focusedChanged(); break;
        case 5: _t->activate(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (NigiriWorkspace::*)()>(_a, &NigiriWorkspace::idChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (NigiriWorkspace::*)()>(_a, &NigiriWorkspace::idxChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (NigiriWorkspace::*)()>(_a, &NigiriWorkspace::nameChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (NigiriWorkspace::*)()>(_a, &NigiriWorkspace::activeChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (NigiriWorkspace::*)()>(_a, &NigiriWorkspace::focusedChanged, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qint32*>(_v) = _t->bindableId().value(); break;
        case 1: *reinterpret_cast<qint32*>(_v) = _t->bindableIdx().value(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->bindableName().value(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->bindableActive().value(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->bindableFocused().value(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableId(); break;
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableIdx(); break;
        case 2: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableName(); break;
        case 3: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableActive(); break;
        case 4: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableFocused(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::nigiri::NigiriWorkspace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::nigiri::NigiriWorkspace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs6nigiri15NigiriWorkspaceE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::nigiri::NigiriWorkspace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void qs::nigiri::NigiriWorkspace::idChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::nigiri::NigiriWorkspace::idxChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::nigiri::NigiriWorkspace::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::nigiri::NigiriWorkspace::activeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qs::nigiri::NigiriWorkspace::focusedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
