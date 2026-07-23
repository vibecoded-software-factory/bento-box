/****************************************************************************
** Meta object code from reading C++ file 'panel_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/mac/panel_window.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'panel_window.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs3mac14MacPanelWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::MacPanelWindow::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac14MacPanelWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::MacPanelWindow",
        "QML.Element",
        "auto",
        "anchorsChanged",
        "",
        "exclusiveZoneChanged",
        "exclusionModeChanged",
        "marginsChanged",
        "aboveWindowsChanged",
        "focusableChanged",
        "updateDimensionsSlot",
        "anchors",
        "Anchors",
        "exclusiveZone",
        "exclusionMode",
        "ExclusionMode::Enum",
        "margins",
        "Margins",
        "aboveWindows",
        "focusable"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'anchorsChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'exclusiveZoneChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'exclusionModeChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'marginsChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'aboveWindowsChanged'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'focusableChanged'
        QtMocHelpers::SignalData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'updateDimensionsSlot'
        QtMocHelpers::SlotData<void()>(10, 4, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'anchors'
        QtMocHelpers::PropertyData<Anchors>(11, 0x80000000 | 12, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 0),
        // property 'exclusiveZone'
        QtMocHelpers::PropertyData<qint32>(13, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'exclusionMode'
        QtMocHelpers::PropertyData<ExclusionMode::Enum>(14, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 2),
        // property 'margins'
        QtMocHelpers::PropertyData<Margins>(16, 0x80000000 | 17, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 3),
        // property 'aboveWindows'
        QtMocHelpers::PropertyData<bool>(18, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'focusable'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<MacPanelWindow, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN2qs3mac14MacPanelWindowE[] = {
    QMetaObject::SuperData::link<ExclusionMode::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject qs::mac::MacPanelWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<ProxyWindowBase::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac14MacPanelWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac14MacPanelWindowE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN2qs3mac14MacPanelWindowE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac14MacPanelWindowE_t>.metaTypes,
    nullptr
} };

void qs::mac::MacPanelWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MacPanelWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->anchorsChanged(); break;
        case 1: _t->exclusiveZoneChanged(); break;
        case 2: _t->exclusionModeChanged(); break;
        case 3: _t->marginsChanged(); break;
        case 4: _t->aboveWindowsChanged(); break;
        case 5: _t->focusableChanged(); break;
        case 6: _t->updateDimensionsSlot(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MacPanelWindow::*)()>(_a, &MacPanelWindow::anchorsChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (MacPanelWindow::*)()>(_a, &MacPanelWindow::exclusiveZoneChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (MacPanelWindow::*)()>(_a, &MacPanelWindow::exclusionModeChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (MacPanelWindow::*)()>(_a, &MacPanelWindow::marginsChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (MacPanelWindow::*)()>(_a, &MacPanelWindow::aboveWindowsChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (MacPanelWindow::*)()>(_a, &MacPanelWindow::focusableChanged, 5))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<Anchors*>(_v) = _t->anchors(); break;
        case 1: *reinterpret_cast<qint32*>(_v) = _t->exclusiveZone(); break;
        case 2: *reinterpret_cast<ExclusionMode::Enum*>(_v) = _t->exclusionMode(); break;
        case 3: *reinterpret_cast<Margins*>(_v) = _t->margins(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->aboveWindows(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->focusable(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAnchors(*reinterpret_cast<Anchors*>(_v)); break;
        case 1: _t->setExclusiveZone(*reinterpret_cast<qint32*>(_v)); break;
        case 2: _t->setExclusionMode(*reinterpret_cast<ExclusionMode::Enum*>(_v)); break;
        case 3: _t->setMargins(*reinterpret_cast<Margins*>(_v)); break;
        case 4: _t->setAboveWindows(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setFocusable(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::MacPanelWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::MacPanelWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac14MacPanelWindowE_t>.strings))
        return static_cast<void*>(this);
    return ProxyWindowBase::qt_metacast(_clname);
}

int qs::mac::MacPanelWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ProxyWindowBase::qt_metacall(_c, _id, _a);
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
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::MacPanelWindow::anchorsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::MacPanelWindow::exclusiveZoneChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::mac::MacPanelWindow::exclusionModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::mac::MacPanelWindow::marginsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qs::mac::MacPanelWindow::aboveWindowsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void qs::mac::MacPanelWindow::focusableChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac17MacPanelInterfaceE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::MacPanelInterface::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac17MacPanelInterfaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::MacPanelInterface"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MacPanelInterface, qt_meta_tag_ZN2qs3mac17MacPanelInterfaceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject qs::mac::MacPanelInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<PanelWindowInterface::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac17MacPanelInterfaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac17MacPanelInterfaceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac17MacPanelInterfaceE_t>.metaTypes,
    nullptr
} };

void qs::mac::MacPanelInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MacPanelInterface *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *qs::mac::MacPanelInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::MacPanelInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac17MacPanelInterfaceE_t>.strings))
        return static_cast<void*>(this);
    return PanelWindowInterface::qt_metacast(_clname);
}

int qs::mac::MacPanelInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PanelWindowInterface::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
