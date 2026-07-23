/****************************************************************************
** Meta object code from reading C++ file 'i3.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/i3/i3.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'i3.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs3mac2i311I3WorkspaceE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::i3::I3Workspace::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac2i311I3WorkspaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::i3::I3Workspace",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "i3 is not the compositor on macOS"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<I3Workspace, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::i3::I3Workspace::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac2i311I3WorkspaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac2i311I3WorkspaceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac2i311I3WorkspaceE_t>.metaTypes,
    nullptr
} };

void qs::mac::i3::I3Workspace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<I3Workspace *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *qs::mac::i3::I3Workspace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::i3::I3Workspace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac2i311I3WorkspaceE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::i3::I3Workspace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN2qs3mac2i32I3E_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::i3::I3::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac2i32I3E_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::i3::I3",
        "QML.Element",
        "I3",
        "QML.Singleton",
        "true",
        "dispatch",
        "",
        "workspaces",
        "UntypedObjectModel*"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'dispatch'
        QtMocHelpers::MethodData<void(const QString &)>(5, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 },
        }}),
        // Method 'dispatch'
        QtMocHelpers::MethodData<void()>(5, 6, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'workspaces'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(7, 0x80000000 | 8, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<I3, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::i3::I3::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac2i32I3E_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac2i32I3E_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac2i32I3E_t>.metaTypes,
    nullptr
} };

void qs::mac::i3::I3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<I3 *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->dispatch((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->dispatch(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< UntypedObjectModel* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->workspaces(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::i3::I3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::i3::I3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac2i32I3E_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::i3::I3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN2qs3mac2i313I3IpcListenerE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::i3::I3IpcListener::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac2i313I3IpcListenerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::i3::I3IpcListener",
        "QML.Element",
        "auto",
        "ipcEvent",
        "",
        "type",
        "payload",
        "subscriptionsChanged",
        "start",
        "stop",
        "subscriptions"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'ipcEvent'
        QtMocHelpers::SignalData<void(const QString &, const QString &)>(3, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 }, { QMetaType::QString, 6 },
        }}),
        // Signal 'subscriptionsChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'start'
        QtMocHelpers::MethodData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'stop'
        QtMocHelpers::MethodData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'subscriptions'
        QtMocHelpers::PropertyData<QStringList>(10, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<I3IpcListener, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::i3::I3IpcListener::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac2i313I3IpcListenerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac2i313I3IpcListenerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac2i313I3IpcListenerE_t>.metaTypes,
    nullptr
} };

void qs::mac::i3::I3IpcListener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<I3IpcListener *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->ipcEvent((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->subscriptionsChanged(); break;
        case 2: _t->start(); break;
        case 3: _t->stop(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (I3IpcListener::*)(const QString & , const QString & )>(_a, &I3IpcListener::ipcEvent, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (I3IpcListener::*)()>(_a, &I3IpcListener::subscriptionsChanged, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QStringList*>(_v) = _t->subscriptions(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSubscriptions(*reinterpret_cast<QStringList*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::i3::I3IpcListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::i3::I3IpcListener::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac2i313I3IpcListenerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::i3::I3IpcListener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::i3::I3IpcListener::ipcEvent(const QString & _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void qs::mac::i3::I3IpcListener::subscriptionsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
