/****************************************************************************
** Meta object code from reading C++ file 'wayland.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/wayland/wayland.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wayland.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs3mac7wayland13WlrLayershellE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::wayland::WlrLayershell::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac7wayland13WlrLayershellE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::wayland::WlrLayershell",
        "QML.Element",
        "auto",
        "QML.Attached",
        "WlrLayershell",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "WlrLayershell is only available as an attached object",
        "layerChanged",
        "",
        "namespaceChanged",
        "keyboardFocusChanged",
        "exclusiveZoneChanged",
        "exclusionModeChanged",
        "marginsChanged",
        "layer",
        "qs::mac::wayland::WlrLayer::Enum",
        "namespace",
        "keyboardFocus",
        "qs::mac::wayland::WlrKeyboardFocus::Enum",
        "exclusiveZone",
        "exclusionMode",
        "margins",
        "Margins",
        "Layer",
        "Background",
        "Bottom",
        "Top",
        "Overlay"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'layerChanged'
        QtMocHelpers::SignalData<void()>(9, 10, QMC::AccessPublic, QMetaType::Void),
        // Signal 'namespaceChanged'
        QtMocHelpers::SignalData<void()>(11, 10, QMC::AccessPublic, QMetaType::Void),
        // Signal 'keyboardFocusChanged'
        QtMocHelpers::SignalData<void()>(12, 10, QMC::AccessPublic, QMetaType::Void),
        // Signal 'exclusiveZoneChanged'
        QtMocHelpers::SignalData<void()>(13, 10, QMC::AccessPublic, QMetaType::Void),
        // Signal 'exclusionModeChanged'
        QtMocHelpers::SignalData<void()>(14, 10, QMC::AccessPublic, QMetaType::Void),
        // Signal 'marginsChanged'
        QtMocHelpers::SignalData<void()>(15, 10, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'layer'
        QtMocHelpers::PropertyData<qs::mac::wayland::WlrLayer::Enum>(16, 0x80000000 | 17, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 0),
        // property 'namespace'
        QtMocHelpers::PropertyData<QString>(18, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'keyboardFocus'
        QtMocHelpers::PropertyData<qs::mac::wayland::WlrKeyboardFocus::Enum>(19, 0x80000000 | 20, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 2),
        // property 'exclusiveZone'
        QtMocHelpers::PropertyData<qint32>(21, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'exclusionMode'
        QtMocHelpers::PropertyData<int>(22, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'margins'
        QtMocHelpers::PropertyData<Margins>(23, 0x80000000 | 24, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 5),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Layer'
        QtMocHelpers::EnumData<enum Layer>(25, 25, QMC::EnumFlags{}).add({
            {   26, Layer::Background },
            {   27, Layer::Bottom },
            {   28, Layer::Top },
            {   29, Layer::Overlay },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
            {    7,    8 },
    });
    return QtMocHelpers::metaObjectData<WlrLayershell, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN2qs3mac7wayland13WlrLayershellE[] = {
    QMetaObject::SuperData::link<qs::mac::wayland::WlrLayer::staticMetaObject>(),
    QMetaObject::SuperData::link<qs::mac::wayland::WlrKeyboardFocus::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject qs::mac::wayland::WlrLayershell::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland13WlrLayershellE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland13WlrLayershellE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN2qs3mac7wayland13WlrLayershellE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac7wayland13WlrLayershellE_t>.metaTypes,
    nullptr
} };

void qs::mac::wayland::WlrLayershell::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<WlrLayershell *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->layerChanged(); break;
        case 1: _t->namespaceChanged(); break;
        case 2: _t->keyboardFocusChanged(); break;
        case 3: _t->exclusiveZoneChanged(); break;
        case 4: _t->exclusionModeChanged(); break;
        case 5: _t->marginsChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (WlrLayershell::*)()>(_a, &WlrLayershell::layerChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (WlrLayershell::*)()>(_a, &WlrLayershell::namespaceChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (WlrLayershell::*)()>(_a, &WlrLayershell::keyboardFocusChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (WlrLayershell::*)()>(_a, &WlrLayershell::exclusiveZoneChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (WlrLayershell::*)()>(_a, &WlrLayershell::exclusionModeChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (WlrLayershell::*)()>(_a, &WlrLayershell::marginsChanged, 5))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qs::mac::wayland::WlrLayer::Enum*>(_v) = _t->layer(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->ns(); break;
        case 2: *reinterpret_cast<qs::mac::wayland::WlrKeyboardFocus::Enum*>(_v) = _t->keyboardFocus(); break;
        case 3: *reinterpret_cast<qint32*>(_v) = _t->exclusiveZone(); break;
        case 4: *reinterpret_cast<int*>(_v) = _t->exclusionMode(); break;
        case 5: *reinterpret_cast<Margins*>(_v) = _t->margins(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLayer(*reinterpret_cast<qs::mac::wayland::WlrLayer::Enum*>(_v)); break;
        case 1: _t->setNamespace(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setKeyboardFocus(*reinterpret_cast<qs::mac::wayland::WlrKeyboardFocus::Enum*>(_v)); break;
        case 3: _t->setExclusiveZone(*reinterpret_cast<qint32*>(_v)); break;
        case 4: _t->setExclusionMode(*reinterpret_cast<int*>(_v)); break;
        case 5: _t->setMargins(*reinterpret_cast<Margins*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::wayland::WlrLayershell::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::wayland::WlrLayershell::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland13WlrLayershellE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::wayland::WlrLayershell::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::wayland::WlrLayershell::layerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::wayland::WlrLayershell::namespaceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::mac::wayland::WlrLayershell::keyboardFocusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::mac::wayland::WlrLayershell::exclusiveZoneChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qs::mac::wayland::WlrLayershell::exclusionModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void qs::mac::wayland::WlrLayershell::marginsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac7wayland11IdleMonitorE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::wayland::IdleMonitor::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac7wayland11IdleMonitorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::wayland::IdleMonitor",
        "QML.Element",
        "auto",
        "enabledChanged",
        "",
        "isIdleChanged",
        "timeoutChanged",
        "respectInhibitorsChanged",
        "enabled",
        "isIdle",
        "respected",
        "respectInhibitors",
        "timeout"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'enabledChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isIdleChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'timeoutChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'respectInhibitorsChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'enabled'
        QtMocHelpers::PropertyData<bool>(8, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'isIdle'
        QtMocHelpers::PropertyData<bool>(9, QMetaType::Bool, QMC::DefaultPropertyFlags, 1),
        // property 'respected'
        QtMocHelpers::PropertyData<bool>(10, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'respectInhibitors'
        QtMocHelpers::PropertyData<bool>(11, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'timeout'
        QtMocHelpers::PropertyData<qreal>(12, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<IdleMonitor, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::wayland::IdleMonitor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland11IdleMonitorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland11IdleMonitorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac7wayland11IdleMonitorE_t>.metaTypes,
    nullptr
} };

void qs::mac::wayland::IdleMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IdleMonitor *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->enabledChanged(); break;
        case 1: _t->isIdleChanged(); break;
        case 2: _t->timeoutChanged(); break;
        case 3: _t->respectInhibitorsChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (IdleMonitor::*)()>(_a, &IdleMonitor::enabledChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (IdleMonitor::*)()>(_a, &IdleMonitor::isIdleChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (IdleMonitor::*)()>(_a, &IdleMonitor::timeoutChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (IdleMonitor::*)()>(_a, &IdleMonitor::respectInhibitorsChanged, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->enabled(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isIdle(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->respected(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->respectInhibitors(); break;
        case 4: *reinterpret_cast<qreal*>(_v) = _t->timeout(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setRespectInhibitors(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setTimeout(*reinterpret_cast<qreal*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::wayland::IdleMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::wayland::IdleMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland11IdleMonitorE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::wayland::IdleMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::wayland::IdleMonitor::enabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::wayland::IdleMonitor::isIdleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::mac::wayland::IdleMonitor::timeoutChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::mac::wayland::IdleMonitor::respectInhibitorsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac7wayland13IdleInhibitorE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::wayland::IdleInhibitor::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac7wayland13IdleInhibitorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::wayland::IdleInhibitor",
        "QML.Element",
        "auto",
        "enabledChanged",
        "",
        "windowChanged",
        "enabled",
        "window"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'enabledChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'windowChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'enabled'
        QtMocHelpers::PropertyData<bool>(6, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'window'
        QtMocHelpers::PropertyData<QObject*>(7, QMetaType::QObjectStar, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<IdleInhibitor, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::wayland::IdleInhibitor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland13IdleInhibitorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland13IdleInhibitorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac7wayland13IdleInhibitorE_t>.metaTypes,
    nullptr
} };

void qs::mac::wayland::IdleInhibitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<IdleInhibitor *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->enabledChanged(); break;
        case 1: _t->windowChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (IdleInhibitor::*)()>(_a, &IdleInhibitor::enabledChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (IdleInhibitor::*)()>(_a, &IdleInhibitor::windowChanged, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->enabled(); break;
        case 1: *reinterpret_cast<QObject**>(_v) = _t->window(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setWindow(*reinterpret_cast<QObject**>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::wayland::IdleInhibitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::wayland::IdleInhibitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland13IdleInhibitorE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::wayland::IdleInhibitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::wayland::IdleInhibitor::enabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::wayland::IdleInhibitor::windowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac7wayland17ShortcutInhibitorE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::wayland::ShortcutInhibitor::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac7wayland17ShortcutInhibitorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::wayland::ShortcutInhibitor",
        "QML.Element",
        "auto",
        "enabledChanged",
        "",
        "windowChanged",
        "enabled",
        "window"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'enabledChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'windowChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'enabled'
        QtMocHelpers::PropertyData<bool>(6, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'window'
        QtMocHelpers::PropertyData<QObject*>(7, QMetaType::QObjectStar, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<ShortcutInhibitor, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::wayland::ShortcutInhibitor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland17ShortcutInhibitorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland17ShortcutInhibitorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac7wayland17ShortcutInhibitorE_t>.metaTypes,
    nullptr
} };

void qs::mac::wayland::ShortcutInhibitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ShortcutInhibitor *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->enabledChanged(); break;
        case 1: _t->windowChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ShortcutInhibitor::*)()>(_a, &ShortcutInhibitor::enabledChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ShortcutInhibitor::*)()>(_a, &ShortcutInhibitor::windowChanged, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->enabled(); break;
        case 1: *reinterpret_cast<QObject**>(_v) = _t->window(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setWindow(*reinterpret_cast<QObject**>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::wayland::ShortcutInhibitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::wayland::ShortcutInhibitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland17ShortcutInhibitorE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::wayland::ShortcutInhibitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::wayland::ShortcutInhibitor::enabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::wayland::ShortcutInhibitor::windowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac7wayland13WlSessionLockE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::wayland::WlSessionLock::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac7wayland13WlSessionLockE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::wayland::WlSessionLock",
        "DefaultProperty",
        "data",
        "QML.Element",
        "auto",
        "lockedChanged",
        "",
        "locked",
        "secure",
        "QQmlListProperty<QObject>"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'lockedChanged'
        QtMocHelpers::SignalData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'locked'
        QtMocHelpers::PropertyData<bool>(7, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'secure'
        QtMocHelpers::PropertyData<bool>(8, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'data'
        QtMocHelpers::PropertyData<QQmlListProperty<QObject>>(2, 0x80000000 | 9, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<WlSessionLock, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::wayland::WlSessionLock::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland13WlSessionLockE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland13WlSessionLockE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac7wayland13WlSessionLockE_t>.metaTypes,
    nullptr
} };

void qs::mac::wayland::WlSessionLock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<WlSessionLock *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->lockedChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (WlSessionLock::*)()>(_a, &WlSessionLock::lockedChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->locked(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->secure(); break;
        case 2: *reinterpret_cast<QQmlListProperty<QObject>*>(_v) = _t->data(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLocked(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::wayland::WlSessionLock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::wayland::WlSessionLock::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland13WlSessionLockE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::wayland::WlSessionLock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::wayland::WlSessionLock::lockedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac7wayland20WlSessionLockSurfaceE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::wayland::WlSessionLockSurface::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac7wayland20WlSessionLockSurfaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::wayland::WlSessionLockSurface",
        "QML.Element",
        "auto",
        "colorChanged",
        "",
        "screen",
        "color",
        "QColor"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'colorChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'screen'
        QtMocHelpers::PropertyData<QObject*>(5, QMetaType::QObjectStar, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'color'
        QtMocHelpers::PropertyData<QColor>(6, 0x80000000 | 7, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<WlSessionLockSurface, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::wayland::WlSessionLockSurface::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland20WlSessionLockSurfaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland20WlSessionLockSurfaceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac7wayland20WlSessionLockSurfaceE_t>.metaTypes,
    nullptr
} };

void qs::mac::wayland::WlSessionLockSurface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<WlSessionLockSurface *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->colorChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (WlSessionLockSurface::*)()>(_a, &WlSessionLockSurface::colorChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QObject**>(_v) = _t->screen(); break;
        case 1: *reinterpret_cast<QColor*>(_v) = _t->color(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setColor(*reinterpret_cast<QColor*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::wayland::WlSessionLockSurface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::wayland::WlSessionLockSurface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland20WlSessionLockSurfaceE_t>.strings))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int qs::mac::wayland::WlSessionLockSurface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
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
void qs::mac::wayland::WlSessionLockSurface::colorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac7wayland8WlrLayerE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::wayland::WlrLayer::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac7wayland8WlrLayerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::wayland::WlrLayer",
        "QML.Element",
        "auto",
        "Enum",
        "Background",
        "Bottom",
        "Top",
        "Overlay"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<Enum>(3, 3, QMC::EnumFlags{}).add({
            {    4, Enum::Background },
            {    5, Enum::Bottom },
            {    6, Enum::Top },
            {    7, Enum::Overlay },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN2qs3mac7wayland8WlrLayerE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}

static constexpr auto qt_staticMetaObjectContent_ZN2qs3mac7wayland8WlrLayerE =
    qs::mac::wayland::WlrLayer::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac7wayland8WlrLayerE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN2qs3mac7wayland8WlrLayerE =
    qt_staticMetaObjectContent_ZN2qs3mac7wayland8WlrLayerE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN2qs3mac7wayland8WlrLayerE =
    qt_staticMetaObjectContent_ZN2qs3mac7wayland8WlrLayerE.relocatingData;

Q_CONSTINIT const QMetaObject qs::mac::wayland::WlrLayer::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN2qs3mac7wayland8WlrLayerE.stringdata,
    qt_staticMetaObjectStaticContent_ZN2qs3mac7wayland8WlrLayerE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN2qs3mac7wayland8WlrLayerE.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN2qs3mac7wayland16WlrKeyboardFocusE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::wayland::WlrKeyboardFocus::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac7wayland16WlrKeyboardFocusE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::wayland::WlrKeyboardFocus",
        "QML.Element",
        "auto",
        "Enum",
        "None",
        "Exclusive",
        "OnDemand"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<Enum>(3, 3, QMC::EnumFlags{}).add({
            {    4, Enum::None },
            {    5, Enum::Exclusive },
            {    6, Enum::OnDemand },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN2qs3mac7wayland16WlrKeyboardFocusE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}

static constexpr auto qt_staticMetaObjectContent_ZN2qs3mac7wayland16WlrKeyboardFocusE =
    qs::mac::wayland::WlrKeyboardFocus::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac7wayland16WlrKeyboardFocusE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN2qs3mac7wayland16WlrKeyboardFocusE =
    qt_staticMetaObjectContent_ZN2qs3mac7wayland16WlrKeyboardFocusE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN2qs3mac7wayland16WlrKeyboardFocusE =
    qt_staticMetaObjectContent_ZN2qs3mac7wayland16WlrKeyboardFocusE.relocatingData;

Q_CONSTINIT const QMetaObject qs::mac::wayland::WlrKeyboardFocus::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN2qs3mac7wayland16WlrKeyboardFocusE.stringdata,
    qt_staticMetaObjectStaticContent_ZN2qs3mac7wayland16WlrKeyboardFocusE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN2qs3mac7wayland16WlrKeyboardFocusE.metaTypes,
    nullptr
} };

QT_WARNING_POP
