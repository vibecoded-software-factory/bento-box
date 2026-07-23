/****************************************************************************
** Meta object code from reading C++ file 'qml.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/nigiri/qml.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qml.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs6nigiri12NigiriIpcQmlE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::nigiri::NigiriIpcQml::qt_create_metaobjectdata<qt_meta_tag_ZN2qs6nigiri12NigiriIpcQmlE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::nigiri::NigiriIpcQml",
        "QML.Element",
        "Nigiri",
        "QML.Singleton",
        "true",
        "focusedWorkspaceChanged",
        "",
        "activeWindowChanged",
        "focusedWindowIdChanged",
        "rawEvent",
        "name",
        "QJsonObject",
        "data",
        "dispatch",
        "action",
        "workspaces",
        "UntypedObjectModel*",
        "windows",
        "focusedWorkspace",
        "qs::nigiri::NigiriWorkspace*",
        "activeWindow",
        "qs::nigiri::NigiriWindow*",
        "focusedWindowId"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'focusedWorkspaceChanged'
        QtMocHelpers::SignalData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'activeWindowChanged'
        QtMocHelpers::SignalData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'focusedWindowIdChanged'
        QtMocHelpers::SignalData<void()>(8, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rawEvent'
        QtMocHelpers::SignalData<void(const QString &, const QJsonObject &)>(9, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Method 'dispatch'
        QtMocHelpers::MethodData<void(const QString &)>(13, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'workspaces'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(15, 0x80000000 | 16, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'windows'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(17, 0x80000000 | 16, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'focusedWorkspace'
        QtMocHelpers::PropertyData<qs::nigiri::NigiriWorkspace*>(18, 0x80000000 | 19, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
        // property 'activeWindow'
        QtMocHelpers::PropertyData<qs::nigiri::NigiriWindow*>(20, 0x80000000 | 21, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 1),
        // property 'focusedWindowId'
        QtMocHelpers::PropertyData<qint32>(22, QMetaType::Int, QMC::DefaultPropertyFlags, 2),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<NigiriIpcQml, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::nigiri::NigiriIpcQml::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs6nigiri12NigiriIpcQmlE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs6nigiri12NigiriIpcQmlE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs6nigiri12NigiriIpcQmlE_t>.metaTypes,
    nullptr
} };

void qs::nigiri::NigiriIpcQml::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NigiriIpcQml *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->focusedWorkspaceChanged(); break;
        case 1: _t->activeWindowChanged(); break;
        case 2: _t->focusedWindowIdChanged(); break;
        case 3: _t->rawEvent((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 4: _t->dispatch((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (NigiriIpcQml::*)()>(_a, &NigiriIpcQml::focusedWorkspaceChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (NigiriIpcQml::*)()>(_a, &NigiriIpcQml::activeWindowChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (NigiriIpcQml::*)()>(_a, &NigiriIpcQml::focusedWindowIdChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (NigiriIpcQml::*)(const QString & , const QJsonObject & )>(_a, &NigiriIpcQml::rawEvent, 3))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< UntypedObjectModel* >(); break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qs::nigiri::NigiriWindow* >(); break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qs::nigiri::NigiriWorkspace* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->workspaces(); break;
        case 1: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->windows(); break;
        case 2: *reinterpret_cast<qs::nigiri::NigiriWorkspace**>(_v) = _t->focusedWorkspace(); break;
        case 3: *reinterpret_cast<qs::nigiri::NigiriWindow**>(_v) = _t->activeWindow(); break;
        case 4: *reinterpret_cast<qint32*>(_v) = _t->focusedWindowId(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::nigiri::NigiriIpcQml::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::nigiri::NigiriIpcQml::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs6nigiri12NigiriIpcQmlE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::nigiri::NigiriIpcQml::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void qs::nigiri::NigiriIpcQml::focusedWorkspaceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::nigiri::NigiriIpcQml::activeWindowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::nigiri::NigiriIpcQml::focusedWindowIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::nigiri::NigiriIpcQml::rawEvent(const QString & _t1, const QJsonObject & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}
QT_WARNING_POP
