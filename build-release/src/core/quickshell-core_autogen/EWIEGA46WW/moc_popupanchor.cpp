/****************************************************************************
** Meta object code from reading C++ file 'popupanchor.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/popupanchor.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'popupanchor.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11PopupAnchorE_t {};
} // unnamed namespace

template <> constexpr inline auto PopupAnchor::qt_create_metaobjectdata<qt_meta_tag_ZN11PopupAnchorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "PopupAnchor",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "",
        "anchoring",
        "windowChanged",
        "itemChanged",
        "backingWindowVisibilityChanged",
        "windowRectChanged",
        "rectChanged",
        "marginsChanged",
        "edgesChanged",
        "gravityChanged",
        "adjustmentChanged",
        "onWindowDestroyed",
        "onItemDestroyed",
        "onItemWindowChanged",
        "updateAnchor",
        "window",
        "item",
        "QQuickItem*",
        "rect",
        "Box",
        "margins",
        "Margins",
        "edges",
        "Edges::Flags",
        "gravity",
        "adjustment",
        "PopupAdjustment::Flags"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'anchoring'
        QtMocHelpers::SignalData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'windowChanged'
        QtMocHelpers::SignalData<void()>(8, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'itemChanged'
        QtMocHelpers::SignalData<void()>(9, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'backingWindowVisibilityChanged'
        QtMocHelpers::SignalData<void()>(10, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'windowRectChanged'
        QtMocHelpers::SignalData<void()>(11, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rectChanged'
        QtMocHelpers::SignalData<void()>(12, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'marginsChanged'
        QtMocHelpers::SignalData<void()>(13, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'edgesChanged'
        QtMocHelpers::SignalData<void()>(14, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'gravityChanged'
        QtMocHelpers::SignalData<void()>(15, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'adjustmentChanged'
        QtMocHelpers::SignalData<void()>(16, 6, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onWindowDestroyed'
        QtMocHelpers::SlotData<void()>(17, 6, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onItemDestroyed'
        QtMocHelpers::SlotData<void()>(18, 6, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onItemWindowChanged'
        QtMocHelpers::SlotData<void()>(19, 6, QMC::AccessPrivate, QMetaType::Void),
        // Method 'updateAnchor'
        QtMocHelpers::MethodData<void()>(20, 6, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'window'
        QtMocHelpers::PropertyData<QObject*>(21, QMetaType::QObjectStar, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'item'
        QtMocHelpers::PropertyData<QQuickItem*>(22, 0x80000000 | 23, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 2),
        // property 'rect'
        QtMocHelpers::PropertyData<Box>(24, 0x80000000 | 25, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::EnumOrFlag | QMC::StdCppSet, 5),
        // property 'margins'
        QtMocHelpers::PropertyData<Margins>(26, 0x80000000 | 27, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 6),
        // property 'edges'
        QtMocHelpers::PropertyData<Edges::Flags>(28, 0x80000000 | 29, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 7),
        // property 'gravity'
        QtMocHelpers::PropertyData<Edges::Flags>(30, 0x80000000 | 29, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 8),
        // property 'adjustment'
        QtMocHelpers::PropertyData<PopupAdjustment::Flags>(31, 0x80000000 | 32, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 9),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<PopupAnchor, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN11PopupAnchorE[] = {
    QMetaObject::SuperData::link<Edges::staticMetaObject>(),
    QMetaObject::SuperData::link<PopupAdjustment::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject PopupAnchor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11PopupAnchorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11PopupAnchorE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN11PopupAnchorE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11PopupAnchorE_t>.metaTypes,
    nullptr
} };

void PopupAnchor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PopupAnchor *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->anchoring(); break;
        case 1: _t->windowChanged(); break;
        case 2: _t->itemChanged(); break;
        case 3: _t->backingWindowVisibilityChanged(); break;
        case 4: _t->windowRectChanged(); break;
        case 5: _t->rectChanged(); break;
        case 6: _t->marginsChanged(); break;
        case 7: _t->edgesChanged(); break;
        case 8: _t->gravityChanged(); break;
        case 9: _t->adjustmentChanged(); break;
        case 10: _t->onWindowDestroyed(); break;
        case 11: _t->onItemDestroyed(); break;
        case 12: _t->onItemWindowChanged(); break;
        case 13: _t->updateAnchor(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (PopupAnchor::*)()>(_a, &PopupAnchor::anchoring, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (PopupAnchor::*)()>(_a, &PopupAnchor::windowChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (PopupAnchor::*)()>(_a, &PopupAnchor::itemChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (PopupAnchor::*)()>(_a, &PopupAnchor::backingWindowVisibilityChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (PopupAnchor::*)()>(_a, &PopupAnchor::windowRectChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (PopupAnchor::*)()>(_a, &PopupAnchor::rectChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (PopupAnchor::*)()>(_a, &PopupAnchor::marginsChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (PopupAnchor::*)()>(_a, &PopupAnchor::edgesChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (PopupAnchor::*)()>(_a, &PopupAnchor::gravityChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (PopupAnchor::*)()>(_a, &PopupAnchor::adjustmentChanged, 9))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQuickItem* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QObject**>(_v) = _t->window(); break;
        case 1: *reinterpret_cast<QQuickItem**>(_v) = _t->item(); break;
        case 2: *reinterpret_cast<Box*>(_v) = _t->rect(); break;
        case 3: *reinterpret_cast<Margins*>(_v) = _t->margins(); break;
        case 4: *reinterpret_cast<Edges::Flags*>(_v) = _t->edges(); break;
        case 5: *reinterpret_cast<Edges::Flags*>(_v) = _t->gravity(); break;
        case 6: *reinterpret_cast<PopupAdjustment::Flags*>(_v) = _t->adjustment(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setWindow(*reinterpret_cast<QObject**>(_v)); break;
        case 1: _t->setItem(*reinterpret_cast<QQuickItem**>(_v)); break;
        case 2: _t->setRect(*reinterpret_cast<Box*>(_v)); break;
        case 3: _t->setMargins(*reinterpret_cast<Margins*>(_v)); break;
        case 4: _t->setEdges(*reinterpret_cast<Edges::Flags*>(_v)); break;
        case 5: _t->setGravity(*reinterpret_cast<Edges::Flags*>(_v)); break;
        case 6: _t->setAdjustment(*reinterpret_cast<PopupAdjustment::Flags*>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 2: _t->resetRect(); break;
        default: break;
        }
    }
}

const QMetaObject *PopupAnchor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PopupAnchor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11PopupAnchorE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PopupAnchor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
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
void PopupAnchor::anchoring()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PopupAnchor::windowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PopupAnchor::itemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PopupAnchor::backingWindowVisibilityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void PopupAnchor::windowRectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void PopupAnchor::rectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void PopupAnchor::marginsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void PopupAnchor::edgesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void PopupAnchor::gravityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void PopupAnchor::adjustmentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
namespace {
struct qt_meta_tag_ZN15PopupAdjustmentE_t {};
} // unnamed namespace

template <> constexpr inline auto PopupAdjustment::qt_create_metaobjectdata<qt_meta_tag_ZN15PopupAdjustmentE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "PopupAdjustment",
        "QML.Element",
        "auto",
        "Enum",
        "None",
        "SlideX",
        "SlideY",
        "Slide",
        "FlipX",
        "FlipY",
        "Flip",
        "ResizeX",
        "ResizeY",
        "Resize",
        "All"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<Enum>(3, 3, QMC::EnumFlags{}).add({
            {    4, Enum::None },
            {    5, Enum::SlideX },
            {    6, Enum::SlideY },
            {    7, Enum::Slide },
            {    8, Enum::FlipX },
            {    9, Enum::FlipY },
            {   10, Enum::Flip },
            {   11, Enum::ResizeX },
            {   12, Enum::ResizeY },
            {   13, Enum::Resize },
            {   14, Enum::All },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN15PopupAdjustmentE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}

static constexpr auto qt_staticMetaObjectContent_ZN15PopupAdjustmentE =
    PopupAdjustment::qt_create_metaobjectdata<qt_meta_tag_ZN15PopupAdjustmentE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN15PopupAdjustmentE =
    qt_staticMetaObjectContent_ZN15PopupAdjustmentE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN15PopupAdjustmentE =
    qt_staticMetaObjectContent_ZN15PopupAdjustmentE.relocatingData;

Q_CONSTINIT const QMetaObject PopupAdjustment::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN15PopupAdjustmentE.stringdata,
    qt_staticMetaObjectStaticContent_ZN15PopupAdjustmentE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN15PopupAdjustmentE.metaTypes,
    nullptr
} };

QT_WARNING_POP
