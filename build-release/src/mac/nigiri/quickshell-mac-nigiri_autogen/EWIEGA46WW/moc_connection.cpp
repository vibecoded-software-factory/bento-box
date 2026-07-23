/****************************************************************************
** Meta object code from reading C++ file 'connection.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/nigiri/connection.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connection.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs6nigiri9NigiriIpcE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::nigiri::NigiriIpc::qt_create_metaobjectdata<qt_meta_tag_ZN2qs6nigiri9NigiriIpcE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::nigiri::NigiriIpc",
        "focusedWorkspaceChanged",
        "",
        "activeWindowChanged",
        "focusedWindowIdChanged",
        "rawEvent",
        "name",
        "QJsonObject",
        "data",
        "onEventSocketState",
        "QLocalSocket::LocalSocketState",
        "state",
        "onEventSocketReady"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'focusedWorkspaceChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'activeWindowChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'focusedWindowIdChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rawEvent'
        QtMocHelpers::SignalData<void(const QString &, const QJsonObject &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 }, { 0x80000000 | 7, 8 },
        }}),
        // Slot 'onEventSocketState'
        QtMocHelpers::SlotData<void(QLocalSocket::LocalSocketState)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
        // Slot 'onEventSocketReady'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<NigiriIpc, qt_meta_tag_ZN2qs6nigiri9NigiriIpcE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject qs::nigiri::NigiriIpc::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs6nigiri9NigiriIpcE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs6nigiri9NigiriIpcE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs6nigiri9NigiriIpcE_t>.metaTypes,
    nullptr
} };

void qs::nigiri::NigiriIpc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NigiriIpc *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->focusedWorkspaceChanged(); break;
        case 1: _t->activeWindowChanged(); break;
        case 2: _t->focusedWindowIdChanged(); break;
        case 3: _t->rawEvent((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[2]))); break;
        case 4: _t->onEventSocketState((*reinterpret_cast<std::add_pointer_t<QLocalSocket::LocalSocketState>>(_a[1]))); break;
        case 5: _t->onEventSocketReady(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (NigiriIpc::*)()>(_a, &NigiriIpc::focusedWorkspaceChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (NigiriIpc::*)()>(_a, &NigiriIpc::activeWindowChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (NigiriIpc::*)()>(_a, &NigiriIpc::focusedWindowIdChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (NigiriIpc::*)(const QString & , const QJsonObject & )>(_a, &NigiriIpc::rawEvent, 3))
            return;
    }
}

const QMetaObject *qs::nigiri::NigiriIpc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::nigiri::NigiriIpc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs6nigiri9NigiriIpcE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::nigiri::NigiriIpc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void qs::nigiri::NigiriIpc::focusedWorkspaceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::nigiri::NigiriIpc::activeWindowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::nigiri::NigiriIpc::focusedWindowIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::nigiri::NigiriIpc::rawEvent(const QString & _t1, const QJsonObject & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}
QT_WARNING_POP
