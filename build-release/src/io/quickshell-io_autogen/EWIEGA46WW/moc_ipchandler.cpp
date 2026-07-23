/****************************************************************************
** Meta object code from reading C++ file 'ipchandler.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/io/ipchandler.hpp"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ipchandler.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs2io3ipc17IpcSignalListenerE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::io::ipc::IpcSignalListener::qt_create_metaobjectdata<qt_meta_tag_ZN2qs2io3ipc17IpcSignalListenerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::io::ipc::IpcSignalListener",
        "triggered",
        "",
        "signal",
        "value",
        "invokeVoid",
        "invokeString",
        "invokeInt",
        "invokeBool",
        "invokeReal",
        "invokeColor",
        "QColor"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'triggered'
        QtMocHelpers::SignalData<void(const QString &, const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 4 },
        }}),
        // Slot 'invokeVoid'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'invokeString'
        QtMocHelpers::SlotData<void(const QString &)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Slot 'invokeInt'
        QtMocHelpers::SlotData<void(int)>(7, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Slot 'invokeBool'
        QtMocHelpers::SlotData<void(bool)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 4 },
        }}),
        // Slot 'invokeReal'
        QtMocHelpers::SlotData<void(double)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Double, 4 },
        }}),
        // Slot 'invokeColor'
        QtMocHelpers::SlotData<void(QColor)>(10, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 11, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<IpcSignalListener, qt_meta_tag_ZN2qs2io3ipc17IpcSignalListenerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject qs::io::ipc::IpcSignalListener::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io3ipc17IpcSignalListenerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io3ipc17IpcSignalListenerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs2io3ipc17IpcSignalListenerE_t>.metaTypes,
    nullptr
} };

void qs::io::ipc::IpcSignalListener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IpcSignalListener *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->triggered((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->invokeVoid(); break;
        case 2: _t->invokeString((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->invokeInt((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->invokeBool((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->invokeReal((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 6: _t->invokeColor((*reinterpret_cast<std::add_pointer_t<QColor>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (IpcSignalListener::*)(const QString & , const QString & )>(_a, &IpcSignalListener::triggered, 0))
            return;
    }
}

const QMetaObject *qs::io::ipc::IpcSignalListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::io::ipc::IpcSignalListener::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io3ipc17IpcSignalListenerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::io::ipc::IpcSignalListener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void qs::io::ipc::IpcSignalListener::triggered(const QString & _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}
namespace {
struct qt_meta_tag_ZN2qs2io3ipc10IpcHandlerE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::io::ipc::IpcHandler::qt_create_metaobjectdata<qt_meta_tag_ZN2qs2io3ipc10IpcHandlerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::io::ipc::IpcHandler",
        "QML.Element",
        "auto",
        "enabledChanged",
        "",
        "targetChanged",
        "onSignalTriggered",
        "signal",
        "value",
        "enabled",
        "target"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'enabledChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'targetChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onSignalTriggered'
        QtMocHelpers::SlotData<void(const QString &, const QString &) const>(6, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 }, { QMetaType::QString, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'enabled'
        QtMocHelpers::PropertyData<bool>(9, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'target'
        QtMocHelpers::PropertyData<QString>(10, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<IpcHandler, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::io::ipc::IpcHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<PostReloadHook::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io3ipc10IpcHandlerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io3ipc10IpcHandlerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs2io3ipc10IpcHandlerE_t>.metaTypes,
    nullptr
} };

void qs::io::ipc::IpcHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IpcHandler *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->enabledChanged(); break;
        case 1: _t->targetChanged(); break;
        case 2: _t->onSignalTriggered((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (IpcHandler::*)()>(_a, &IpcHandler::enabledChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (IpcHandler::*)()>(_a, &IpcHandler::targetChanged, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->enabled(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->target(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setTarget(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::io::ipc::IpcHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::io::ipc::IpcHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io3ipc10IpcHandlerE_t>.strings))
        return static_cast<void*>(this);
    return PostReloadHook::qt_metacast(_clname);
}

int qs::io::ipc::IpcHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PostReloadHook::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void qs::io::ipc::IpcHandler::enabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::io::ipc::IpcHandler::targetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs2io3ipc23IpcSignalRemoteListenerE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::io::ipc::IpcSignalRemoteListener::qt_create_metaobjectdata<qt_meta_tag_ZN2qs2io3ipc23IpcSignalRemoteListenerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::io::ipc::IpcSignalRemoteListener",
        "triggered",
        "",
        "target",
        "signal",
        "value"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'triggered'
        QtMocHelpers::SignalData<void(const QString &, const QString &, const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 4 }, { QMetaType::QString, 5 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<IpcSignalRemoteListener, qt_meta_tag_ZN2qs2io3ipc23IpcSignalRemoteListenerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject qs::io::ipc::IpcSignalRemoteListener::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io3ipc23IpcSignalRemoteListenerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io3ipc23IpcSignalRemoteListenerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs2io3ipc23IpcSignalRemoteListenerE_t>.metaTypes,
    nullptr
} };

void qs::io::ipc::IpcSignalRemoteListener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IpcSignalRemoteListener *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->triggered((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[3]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (IpcSignalRemoteListener::*)(const QString & , const QString & , const QString & )>(_a, &IpcSignalRemoteListener::triggered, 0))
            return;
    }
}

const QMetaObject *qs::io::ipc::IpcSignalRemoteListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::io::ipc::IpcSignalRemoteListener::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io3ipc23IpcSignalRemoteListenerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::io::ipc::IpcSignalRemoteListener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void qs::io::ipc::IpcSignalRemoteListener::triggered(const QString & _t1, const QString & _t2, const QString & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3);
}
QT_WARNING_POP
