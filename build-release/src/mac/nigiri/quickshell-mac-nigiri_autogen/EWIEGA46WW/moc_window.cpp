/****************************************************************************
** Meta object code from reading C++ file 'window.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/nigiri/window.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs6nigiri12NigiriWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::nigiri::NigiriWindow::qt_create_metaobjectdata<qt_meta_tag_ZN2qs6nigiri12NigiriWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::nigiri::NigiriWindow",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "NigiriWindows are retrieved from the Nigiri singleton.",
        "idChanged",
        "",
        "titleChanged",
        "appIdChanged",
        "pidChanged",
        "workspaceIdChanged",
        "floatingChanged",
        "activeChanged",
        "activate",
        "id",
        "title",
        "appId",
        "pid",
        "workspaceId",
        "floating",
        "active"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'idChanged'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'titleChanged'
        QtMocHelpers::SignalData<void()>(9, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'appIdChanged'
        QtMocHelpers::SignalData<void()>(10, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'pidChanged'
        QtMocHelpers::SignalData<void()>(11, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'workspaceIdChanged'
        QtMocHelpers::SignalData<void()>(12, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'floatingChanged'
        QtMocHelpers::SignalData<void()>(13, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'activeChanged'
        QtMocHelpers::SignalData<void()>(14, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'activate'
        QtMocHelpers::MethodData<void()>(15, 8, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'id'
        QtMocHelpers::PropertyData<qint32>(16, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Bindable, 0),
        // property 'title'
        QtMocHelpers::PropertyData<QString>(17, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Bindable, 1),
        // property 'appId'
        QtMocHelpers::PropertyData<QString>(18, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Bindable, 2),
        // property 'pid'
        QtMocHelpers::PropertyData<qint32>(19, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Bindable, 3),
        // property 'workspaceId'
        QtMocHelpers::PropertyData<qint32>(20, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Bindable, 4),
        // property 'floating'
        QtMocHelpers::PropertyData<bool>(21, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 5),
        // property 'active'
        QtMocHelpers::PropertyData<bool>(22, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 6),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<NigiriWindow, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::nigiri::NigiriWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs6nigiri12NigiriWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs6nigiri12NigiriWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs6nigiri12NigiriWindowE_t>.metaTypes,
    nullptr
} };

void qs::nigiri::NigiriWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NigiriWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->idChanged(); break;
        case 1: _t->titleChanged(); break;
        case 2: _t->appIdChanged(); break;
        case 3: _t->pidChanged(); break;
        case 4: _t->workspaceIdChanged(); break;
        case 5: _t->floatingChanged(); break;
        case 6: _t->activeChanged(); break;
        case 7: _t->activate(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (NigiriWindow::*)()>(_a, &NigiriWindow::idChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (NigiriWindow::*)()>(_a, &NigiriWindow::titleChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (NigiriWindow::*)()>(_a, &NigiriWindow::appIdChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (NigiriWindow::*)()>(_a, &NigiriWindow::pidChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (NigiriWindow::*)()>(_a, &NigiriWindow::workspaceIdChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (NigiriWindow::*)()>(_a, &NigiriWindow::floatingChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (NigiriWindow::*)()>(_a, &NigiriWindow::activeChanged, 6))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qint32*>(_v) = _t->bindableId().value(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->bindableTitle().value(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->bindableAppId().value(); break;
        case 3: *reinterpret_cast<qint32*>(_v) = _t->bindablePid().value(); break;
        case 4: *reinterpret_cast<qint32*>(_v) = _t->bindableWorkspaceId().value(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->bindableFloating().value(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->bindableActive().value(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableId(); break;
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableTitle(); break;
        case 2: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableAppId(); break;
        case 3: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindablePid(); break;
        case 4: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableWorkspaceId(); break;
        case 5: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableFloating(); break;
        case 6: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableActive(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::nigiri::NigiriWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::nigiri::NigiriWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs6nigiri12NigiriWindowE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::nigiri::NigiriWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void qs::nigiri::NigiriWindow::idChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::nigiri::NigiriWindow::titleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::nigiri::NigiriWindow::appIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::nigiri::NigiriWindow::pidChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qs::nigiri::NigiriWindow::workspaceIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void qs::nigiri::NigiriWindow::floatingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void qs::nigiri::NigiriWindow::activeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
