/****************************************************************************
** Meta object code from reading C++ file 'panelinterface.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/window/panelinterface.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'panelinterface.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7AnchorsE_t {};
} // unnamed namespace

template <> constexpr inline auto Anchors::qt_create_metaobjectdata<qt_meta_tag_ZN7AnchorsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Anchors",
        "QML.Element",
        "panelAnchors",
        "QML.Creatable",
        "true",
        "QML.CreationMethod",
        "structured",
        "left",
        "right",
        "top",
        "bottom"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'left'
        QtMocHelpers::PropertyData<bool>(7, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'right'
        QtMocHelpers::PropertyData<bool>(8, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'top'
        QtMocHelpers::PropertyData<bool>(9, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'bottom'
        QtMocHelpers::PropertyData<bool>(10, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<Anchors, void>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject Anchors::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7AnchorsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7AnchorsE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7AnchorsE_t>.metaTypes,
    nullptr
} };

void Anchors::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<Anchors *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->mLeft; break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->mRight; break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->mTop; break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->mBottom; break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: QtMocHelpers::setProperty(_t->mLeft, *reinterpret_cast<bool*>(_v)); break;
        case 1: QtMocHelpers::setProperty(_t->mRight, *reinterpret_cast<bool*>(_v)); break;
        case 2: QtMocHelpers::setProperty(_t->mTop, *reinterpret_cast<bool*>(_v)); break;
        case 3: QtMocHelpers::setProperty(_t->mBottom, *reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN20PanelWindowInterfaceE_t {};
} // unnamed namespace

template <> constexpr inline auto PanelWindowInterface::qt_create_metaobjectdata<qt_meta_tag_ZN20PanelWindowInterfaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "PanelWindowInterface",
        "QML.Element",
        "PanelWindow",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "No PanelWindow backend loaded.",
        "anchorsChanged",
        "",
        "marginsChanged",
        "exclusiveZoneChanged",
        "exclusionModeChanged",
        "aboveWindowsChanged",
        "focusableChanged",
        "anchors",
        "Anchors",
        "margins",
        "Margins",
        "exclusiveZone",
        "exclusionMode",
        "ExclusionMode::Enum",
        "aboveWindows",
        "focusable"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'anchorsChanged'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'marginsChanged'
        QtMocHelpers::SignalData<void()>(9, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'exclusiveZoneChanged'
        QtMocHelpers::SignalData<void()>(10, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'exclusionModeChanged'
        QtMocHelpers::SignalData<void()>(11, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'aboveWindowsChanged'
        QtMocHelpers::SignalData<void()>(12, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'focusableChanged'
        QtMocHelpers::SignalData<void()>(13, 8, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'anchors'
        QtMocHelpers::PropertyData<Anchors>(14, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 0),
        // property 'margins'
        QtMocHelpers::PropertyData<Margins>(16, 0x80000000 | 17, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 1),
        // property 'exclusiveZone'
        QtMocHelpers::PropertyData<qint32>(18, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'exclusionMode'
        QtMocHelpers::PropertyData<ExclusionMode::Enum>(19, 0x80000000 | 20, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 3),
        // property 'aboveWindows'
        QtMocHelpers::PropertyData<bool>(21, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'focusable'
        QtMocHelpers::PropertyData<bool>(22, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<PanelWindowInterface, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN20PanelWindowInterfaceE[] = {
    QMetaObject::SuperData::link<ExclusionMode::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject PanelWindowInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<WindowInterface::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20PanelWindowInterfaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20PanelWindowInterfaceE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN20PanelWindowInterfaceE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN20PanelWindowInterfaceE_t>.metaTypes,
    nullptr
} };

void PanelWindowInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PanelWindowInterface *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->anchorsChanged(); break;
        case 1: _t->marginsChanged(); break;
        case 2: _t->exclusiveZoneChanged(); break;
        case 3: _t->exclusionModeChanged(); break;
        case 4: _t->aboveWindowsChanged(); break;
        case 5: _t->focusableChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (PanelWindowInterface::*)()>(_a, &PanelWindowInterface::anchorsChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (PanelWindowInterface::*)()>(_a, &PanelWindowInterface::marginsChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (PanelWindowInterface::*)()>(_a, &PanelWindowInterface::exclusiveZoneChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (PanelWindowInterface::*)()>(_a, &PanelWindowInterface::exclusionModeChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (PanelWindowInterface::*)()>(_a, &PanelWindowInterface::aboveWindowsChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (PanelWindowInterface::*)()>(_a, &PanelWindowInterface::focusableChanged, 5))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<Anchors*>(_v) = _t->anchors(); break;
        case 1: *reinterpret_cast<Margins*>(_v) = _t->margins(); break;
        case 2: *reinterpret_cast<qint32*>(_v) = _t->exclusiveZone(); break;
        case 3: *reinterpret_cast<ExclusionMode::Enum*>(_v) = _t->exclusionMode(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->aboveWindows(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->focusable(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAnchors(*reinterpret_cast<Anchors*>(_v)); break;
        case 1: _t->setMargins(*reinterpret_cast<Margins*>(_v)); break;
        case 2: _t->setExclusiveZone(*reinterpret_cast<qint32*>(_v)); break;
        case 3: _t->setExclusionMode(*reinterpret_cast<ExclusionMode::Enum*>(_v)); break;
        case 4: _t->setAboveWindows(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setFocusable(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *PanelWindowInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PanelWindowInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20PanelWindowInterfaceE_t>.strings))
        return static_cast<void*>(this);
    return WindowInterface::qt_metacast(_clname);
}

int PanelWindowInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WindowInterface::qt_metacall(_c, _id, _a);
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
void PanelWindowInterface::anchorsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PanelWindowInterface::marginsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PanelWindowInterface::exclusiveZoneChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PanelWindowInterface::exclusionModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void PanelWindowInterface::aboveWindowsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void PanelWindowInterface::focusableChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
namespace {
struct qt_meta_tag_ZN13ExclusionModeE_t {};
} // unnamed namespace

template <> constexpr inline auto ExclusionMode::qt_create_metaobjectdata<qt_meta_tag_ZN13ExclusionModeE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ExclusionMode",
        "QML.Element",
        "auto",
        "Enum",
        "Normal",
        "Ignore",
        "Auto"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<Enum>(3, 3, QMC::EnumFlags{}).add({
            {    4, Enum::Normal },
            {    5, Enum::Ignore },
            {    6, Enum::Auto },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN13ExclusionModeE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}

static constexpr auto qt_staticMetaObjectContent_ZN13ExclusionModeE =
    ExclusionMode::qt_create_metaobjectdata<qt_meta_tag_ZN13ExclusionModeE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN13ExclusionModeE =
    qt_staticMetaObjectContent_ZN13ExclusionModeE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN13ExclusionModeE =
    qt_staticMetaObjectContent_ZN13ExclusionModeE.relocatingData;

Q_CONSTINIT const QMetaObject ExclusionMode::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN13ExclusionModeE.stringdata,
    qt_staticMetaObjectStaticContent_ZN13ExclusionModeE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN13ExclusionModeE.metaTypes,
    nullptr
} };

QT_WARNING_POP
