/****************************************************************************
** Meta object code from reading C++ file 'toplevel.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/wayland/toplevel.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toplevel.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs3mac7wayland8ToplevelE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::wayland::Toplevel::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac7wayland8ToplevelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::wayland::Toplevel",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "Toplevels must be acquired from the ToplevelManager.",
        "closed",
        "",
        "appIdChanged",
        "titleChanged",
        "parentChanged",
        "activatedChanged",
        "screensChanged",
        "maximizedChanged",
        "minimizedChanged",
        "fullscreenChanged",
        "activate",
        "close",
        "fullscreenOn",
        "QuickshellScreenInfo*",
        "screen",
        "setRectangle",
        "window",
        "QRect",
        "rect",
        "unsetRectangle",
        "appId",
        "title",
        "parent",
        "qs::mac::wayland::Toplevel*",
        "activated",
        "screens",
        "QList<QuickshellScreenInfo*>",
        "maximized",
        "minimized",
        "fullscreen"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'closed'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'appIdChanged'
        QtMocHelpers::SignalData<void()>(9, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'titleChanged'
        QtMocHelpers::SignalData<void()>(10, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'parentChanged'
        QtMocHelpers::SignalData<void()>(11, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'activatedChanged'
        QtMocHelpers::SignalData<void()>(12, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'screensChanged'
        QtMocHelpers::SignalData<void()>(13, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'maximizedChanged'
        QtMocHelpers::SignalData<void()>(14, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'minimizedChanged'
        QtMocHelpers::SignalData<void()>(15, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'fullscreenChanged'
        QtMocHelpers::SignalData<void()>(16, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'activate'
        QtMocHelpers::MethodData<void()>(17, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'close'
        QtMocHelpers::MethodData<void()>(18, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'fullscreenOn'
        QtMocHelpers::MethodData<void(QuickshellScreenInfo *)>(19, 8, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 20, 21 },
        }}),
        // Method 'setRectangle'
        QtMocHelpers::MethodData<void(QObject *, QRect)>(22, 8, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 23 }, { 0x80000000 | 24, 25 },
        }}),
        // Method 'unsetRectangle'
        QtMocHelpers::MethodData<void()>(26, 8, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'appId'
        QtMocHelpers::PropertyData<QString>(27, QMetaType::QString, QMC::DefaultPropertyFlags, 1),
        // property 'title'
        QtMocHelpers::PropertyData<QString>(28, QMetaType::QString, QMC::DefaultPropertyFlags, 2),
        // property 'parent'
        QtMocHelpers::PropertyData<qs::mac::wayland::Toplevel*>(29, 0x80000000 | 30, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 3),
        // property 'activated'
        QtMocHelpers::PropertyData<bool>(31, QMetaType::Bool, QMC::DefaultPropertyFlags, 4),
        // property 'screens'
        QtMocHelpers::PropertyData<QList<QuickshellScreenInfo*>>(32, 0x80000000 | 33, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 5),
        // property 'maximized'
        QtMocHelpers::PropertyData<bool>(34, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'minimized'
        QtMocHelpers::PropertyData<bool>(35, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'fullscreen'
        QtMocHelpers::PropertyData<bool>(36, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 8),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<Toplevel, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::wayland::Toplevel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland8ToplevelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland8ToplevelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac7wayland8ToplevelE_t>.metaTypes,
    nullptr
} };

void qs::mac::wayland::Toplevel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Toplevel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->appIdChanged(); break;
        case 2: _t->titleChanged(); break;
        case 3: _t->parentChanged(); break;
        case 4: _t->activatedChanged(); break;
        case 5: _t->screensChanged(); break;
        case 6: _t->maximizedChanged(); break;
        case 7: _t->minimizedChanged(); break;
        case 8: _t->fullscreenChanged(); break;
        case 9: _t->activate(); break;
        case 10: _t->close(); break;
        case 11: _t->fullscreenOn((*reinterpret_cast<std::add_pointer_t<QuickshellScreenInfo*>>(_a[1]))); break;
        case 12: _t->setRectangle((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QRect>>(_a[2]))); break;
        case 13: _t->unsetRectangle(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QuickshellScreenInfo* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Toplevel::*)()>(_a, &Toplevel::closed, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Toplevel::*)()>(_a, &Toplevel::appIdChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Toplevel::*)()>(_a, &Toplevel::titleChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Toplevel::*)()>(_a, &Toplevel::parentChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Toplevel::*)()>(_a, &Toplevel::activatedChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (Toplevel::*)()>(_a, &Toplevel::screensChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (Toplevel::*)()>(_a, &Toplevel::maximizedChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (Toplevel::*)()>(_a, &Toplevel::minimizedChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (Toplevel::*)()>(_a, &Toplevel::fullscreenChanged, 8))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QuickshellScreenInfo*> >(); break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qs::mac::wayland::Toplevel* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->appId(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->title(); break;
        case 2: *reinterpret_cast<qs::mac::wayland::Toplevel**>(_v) = _t->parentToplevel(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->activated(); break;
        case 4: *reinterpret_cast<QList<QuickshellScreenInfo*>*>(_v) = _t->screens(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->maximized(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->minimized(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->fullscreen(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 5: _t->setMaximized(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setMinimized(*reinterpret_cast<bool*>(_v)); break;
        case 7: _t->setFullscreen(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::wayland::Toplevel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::wayland::Toplevel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland8ToplevelE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::wayland::Toplevel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::wayland::Toplevel::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::wayland::Toplevel::appIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::mac::wayland::Toplevel::titleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::mac::wayland::Toplevel::parentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qs::mac::wayland::Toplevel::activatedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void qs::mac::wayland::Toplevel::screensChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void qs::mac::wayland::Toplevel::maximizedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void qs::mac::wayland::Toplevel::minimizedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void qs::mac::wayland::Toplevel::fullscreenChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac7wayland18MacToplevelManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::wayland::MacToplevelManager::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac7wayland18MacToplevelManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::wayland::MacToplevelManager",
        "activeToplevelChanged",
        "",
        "onWindowInserted",
        "object",
        "qsizetype",
        "index",
        "onWindowRemoved",
        "updateActiveToplevel"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'activeToplevelChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onWindowInserted'
        QtMocHelpers::SlotData<void(QObject *, qsizetype)>(3, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QObjectStar, 4 }, { 0x80000000 | 5, 6 },
        }}),
        // Slot 'onWindowRemoved'
        QtMocHelpers::SlotData<void(QObject *, qsizetype)>(7, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QObjectStar, 4 }, { 0x80000000 | 5, 6 },
        }}),
        // Slot 'updateActiveToplevel'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MacToplevelManager, qt_meta_tag_ZN2qs3mac7wayland18MacToplevelManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject qs::mac::wayland::MacToplevelManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland18MacToplevelManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland18MacToplevelManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac7wayland18MacToplevelManagerE_t>.metaTypes,
    nullptr
} };

void qs::mac::wayland::MacToplevelManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MacToplevelManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->activeToplevelChanged(); break;
        case 1: _t->onWindowInserted((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qsizetype>>(_a[2]))); break;
        case 2: _t->onWindowRemoved((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qsizetype>>(_a[2]))); break;
        case 3: _t->updateActiveToplevel(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MacToplevelManager::*)()>(_a, &MacToplevelManager::activeToplevelChanged, 0))
            return;
    }
}

const QMetaObject *qs::mac::wayland::MacToplevelManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::wayland::MacToplevelManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland18MacToplevelManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::wayland::MacToplevelManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void qs::mac::wayland::MacToplevelManager::activeToplevelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac7wayland15ToplevelManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::wayland::ToplevelManager::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac7wayland15ToplevelManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::wayland::ToplevelManager",
        "QML.Element",
        "ToplevelManager",
        "QML.Singleton",
        "true",
        "activeToplevelChanged",
        "",
        "toplevels",
        "UntypedObjectModel*",
        "activeToplevel",
        "qs::mac::wayland::Toplevel*"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'activeToplevelChanged'
        QtMocHelpers::SignalData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'toplevels'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(7, 0x80000000 | 8, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'activeToplevel'
        QtMocHelpers::PropertyData<qs::mac::wayland::Toplevel*>(9, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<ToplevelManager, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::wayland::ToplevelManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland15ToplevelManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland15ToplevelManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac7wayland15ToplevelManagerE_t>.metaTypes,
    nullptr
} };

void qs::mac::wayland::ToplevelManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ToplevelManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->activeToplevelChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ToplevelManager::*)()>(_a, &ToplevelManager::activeToplevelChanged, 0))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< UntypedObjectModel* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qs::mac::wayland::Toplevel* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->toplevels(); break;
        case 1: *reinterpret_cast<qs::mac::wayland::Toplevel**>(_v) = _t->activeToplevel(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::wayland::ToplevelManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::wayland::ToplevelManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland15ToplevelManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::wayland::ToplevelManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::wayland::ToplevelManager::activeToplevelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
