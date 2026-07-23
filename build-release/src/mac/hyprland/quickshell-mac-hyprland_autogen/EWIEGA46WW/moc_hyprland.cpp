/****************************************************************************
** Meta object code from reading C++ file 'hyprland.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/hyprland/hyprland.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hyprland.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs3mac8hyprland17HyprlandWorkspaceE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::hyprland::HyprlandWorkspace::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac8hyprland17HyprlandWorkspaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::hyprland::HyprlandWorkspace",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "Hyprland is not the compositor on macOS"
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
    return QtMocHelpers::metaObjectData<HyprlandWorkspace, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::hyprland::HyprlandWorkspace::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8hyprland17HyprlandWorkspaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8hyprland17HyprlandWorkspaceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac8hyprland17HyprlandWorkspaceE_t>.metaTypes,
    nullptr
} };

void qs::mac::hyprland::HyprlandWorkspace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<HyprlandWorkspace *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *qs::mac::hyprland::HyprlandWorkspace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::hyprland::HyprlandWorkspace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8hyprland17HyprlandWorkspaceE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::hyprland::HyprlandWorkspace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN2qs3mac8hyprland15HyprlandMonitorE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::hyprland::HyprlandMonitor::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac8hyprland15HyprlandMonitorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::hyprland::HyprlandMonitor",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "Hyprland is not the compositor on macOS"
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
    return QtMocHelpers::metaObjectData<HyprlandMonitor, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::hyprland::HyprlandMonitor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8hyprland15HyprlandMonitorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8hyprland15HyprlandMonitorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac8hyprland15HyprlandMonitorE_t>.metaTypes,
    nullptr
} };

void qs::mac::hyprland::HyprlandMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<HyprlandMonitor *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *qs::mac::hyprland::HyprlandMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::hyprland::HyprlandMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8hyprland15HyprlandMonitorE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::hyprland::HyprlandMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN2qs3mac8hyprland16HyprlandToplevelE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::hyprland::HyprlandToplevel::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac8hyprland16HyprlandToplevelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::hyprland::HyprlandToplevel",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "Hyprland is not the compositor on macOS"
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
    return QtMocHelpers::metaObjectData<HyprlandToplevel, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::hyprland::HyprlandToplevel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8hyprland16HyprlandToplevelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8hyprland16HyprlandToplevelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac8hyprland16HyprlandToplevelE_t>.metaTypes,
    nullptr
} };

void qs::mac::hyprland::HyprlandToplevel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<HyprlandToplevel *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *qs::mac::hyprland::HyprlandToplevel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::hyprland::HyprlandToplevel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8hyprland16HyprlandToplevelE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::hyprland::HyprlandToplevel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN2qs3mac8hyprland17HyprlandFocusGrabE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::hyprland::HyprlandFocusGrab::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac8hyprland17HyprlandFocusGrabE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::hyprland::HyprlandFocusGrab",
        "QML.Element",
        "auto",
        "activeChanged",
        "",
        "windowsChanged",
        "cleared",
        "active",
        "windows",
        "QList<QObject*>"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'activeChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'windowsChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'cleared'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'active'
        QtMocHelpers::PropertyData<bool>(7, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'windows'
        QtMocHelpers::PropertyData<QList<QObject*>>(8, 0x80000000 | 9, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 1),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<HyprlandFocusGrab, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::hyprland::HyprlandFocusGrab::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8hyprland17HyprlandFocusGrabE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8hyprland17HyprlandFocusGrabE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac8hyprland17HyprlandFocusGrabE_t>.metaTypes,
    nullptr
} };

void qs::mac::hyprland::HyprlandFocusGrab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<HyprlandFocusGrab *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->activeChanged(); break;
        case 1: _t->windowsChanged(); break;
        case 2: _t->cleared(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (HyprlandFocusGrab::*)()>(_a, &HyprlandFocusGrab::activeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (HyprlandFocusGrab::*)()>(_a, &HyprlandFocusGrab::windowsChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (HyprlandFocusGrab::*)()>(_a, &HyprlandFocusGrab::cleared, 2))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->active(); break;
        case 1: *reinterpret_cast<QList<QObject*>*>(_v) = _t->windows(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setActive(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setWindows(*reinterpret_cast<QList<QObject*>*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::hyprland::HyprlandFocusGrab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::hyprland::HyprlandFocusGrab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8hyprland17HyprlandFocusGrabE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::hyprland::HyprlandFocusGrab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void qs::mac::hyprland::HyprlandFocusGrab::activeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::hyprland::HyprlandFocusGrab::windowsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::mac::hyprland::HyprlandFocusGrab::cleared()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac8hyprland8HyprlandE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::hyprland::Hyprland::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac8hyprland8HyprlandE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::hyprland::Hyprland",
        "QML.Element",
        "Hyprland",
        "QML.Singleton",
        "true",
        "focusedWorkspaceChanged",
        "",
        "focusedMonitorChanged",
        "dispatch",
        "refreshToplevels",
        "refreshWorkspaces",
        "refreshMonitors",
        "monitorFor",
        "focusedWorkspace",
        "qs::mac::hyprland::HyprlandWorkspace*",
        "focusedMonitor",
        "qs::mac::hyprland::HyprlandMonitor*",
        "workspaces",
        "UntypedObjectModel*",
        "monitors",
        "toplevels"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'focusedWorkspaceChanged'
        QtMocHelpers::SignalData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'focusedMonitorChanged'
        QtMocHelpers::SignalData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'dispatch'
        QtMocHelpers::MethodData<void(const QString &)>(8, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 },
        }}),
        // Method 'refreshToplevels'
        QtMocHelpers::MethodData<void()>(9, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'refreshWorkspaces'
        QtMocHelpers::MethodData<void()>(10, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'refreshMonitors'
        QtMocHelpers::MethodData<void()>(11, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'monitorFor'
        QtMocHelpers::MethodData<QObject *(QObject *)>(12, 6, QMC::AccessPublic, QMetaType::QObjectStar, {{
            { QMetaType::QObjectStar, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'focusedWorkspace'
        QtMocHelpers::PropertyData<qs::mac::hyprland::HyprlandWorkspace*>(13, 0x80000000 | 14, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
        // property 'focusedMonitor'
        QtMocHelpers::PropertyData<qs::mac::hyprland::HyprlandMonitor*>(15, 0x80000000 | 16, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 1),
        // property 'workspaces'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(17, 0x80000000 | 18, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'monitors'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(19, 0x80000000 | 18, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'toplevels'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(20, 0x80000000 | 18, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<Hyprland, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::hyprland::Hyprland::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8hyprland8HyprlandE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8hyprland8HyprlandE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac8hyprland8HyprlandE_t>.metaTypes,
    nullptr
} };

void qs::mac::hyprland::Hyprland::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Hyprland *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->focusedWorkspaceChanged(); break;
        case 1: _t->focusedMonitorChanged(); break;
        case 2: _t->dispatch((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->refreshToplevels(); break;
        case 4: _t->refreshWorkspaces(); break;
        case 5: _t->refreshMonitors(); break;
        case 6: { QObject* _r = _t->monitorFor((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Hyprland::*)()>(_a, &Hyprland::focusedWorkspaceChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Hyprland::*)()>(_a, &Hyprland::focusedMonitorChanged, 1))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
        case 3:
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< UntypedObjectModel* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qs::mac::hyprland::HyprlandMonitor* >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qs::mac::hyprland::HyprlandWorkspace* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qs::mac::hyprland::HyprlandWorkspace**>(_v) = _t->focusedWorkspace(); break;
        case 1: *reinterpret_cast<qs::mac::hyprland::HyprlandMonitor**>(_v) = _t->focusedMonitor(); break;
        case 2: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->workspaces(); break;
        case 3: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->monitors(); break;
        case 4: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->toplevels(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::hyprland::Hyprland::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::hyprland::Hyprland::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8hyprland8HyprlandE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::hyprland::Hyprland::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::hyprland::Hyprland::focusedWorkspaceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::hyprland::Hyprland::focusedMonitorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
