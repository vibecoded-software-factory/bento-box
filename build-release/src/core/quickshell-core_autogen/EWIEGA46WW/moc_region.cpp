/****************************************************************************
** Meta object code from reading C++ file 'region.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/region.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'region.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13PendingRegionE_t {};
} // unnamed namespace

template <> constexpr inline auto PendingRegion::qt_create_metaobjectdata<qt_meta_tag_ZN13PendingRegionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "PendingRegion",
        "DefaultProperty",
        "regions",
        "QML.Element",
        "Region",
        "shapeChanged",
        "",
        "intersectionChanged",
        "itemChanged",
        "xChanged",
        "yChanged",
        "widthChanged",
        "heightChanged",
        "radiusChanged",
        "topLeftRadiusChanged",
        "topRightRadiusChanged",
        "bottomLeftRadiusChanged",
        "bottomRightRadiusChanged",
        "childrenChanged",
        "changed",
        "onItemDestroyed",
        "onChildDestroyed",
        "shape",
        "RegionShape::Enum",
        "intersection",
        "Intersection::Enum",
        "item",
        "QQuickItem*",
        "x",
        "y",
        "width",
        "height",
        "radius",
        "topLeftRadius",
        "topRightRadius",
        "bottomLeftRadius",
        "bottomRightRadius",
        "QQmlListProperty<PendingRegion>"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'shapeChanged'
        QtMocHelpers::SignalData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'intersectionChanged'
        QtMocHelpers::SignalData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'itemChanged'
        QtMocHelpers::SignalData<void()>(8, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'xChanged'
        QtMocHelpers::SignalData<void()>(9, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'yChanged'
        QtMocHelpers::SignalData<void()>(10, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'widthChanged'
        QtMocHelpers::SignalData<void()>(11, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'heightChanged'
        QtMocHelpers::SignalData<void()>(12, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'radiusChanged'
        QtMocHelpers::SignalData<void()>(13, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'topLeftRadiusChanged'
        QtMocHelpers::SignalData<void()>(14, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'topRightRadiusChanged'
        QtMocHelpers::SignalData<void()>(15, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'bottomLeftRadiusChanged'
        QtMocHelpers::SignalData<void()>(16, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'bottomRightRadiusChanged'
        QtMocHelpers::SignalData<void()>(17, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'childrenChanged'
        QtMocHelpers::SignalData<void()>(18, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'changed'
        QtMocHelpers::SignalData<void()>(19, 6, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onItemDestroyed'
        QtMocHelpers::SlotData<void()>(20, 6, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onChildDestroyed'
        QtMocHelpers::SlotData<void()>(21, 6, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'shape'
        QtMocHelpers::PropertyData<RegionShape::Enum>(22, 0x80000000 | 23, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag, 0),
        // property 'intersection'
        QtMocHelpers::PropertyData<Intersection::Enum>(24, 0x80000000 | 25, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag, 1),
        // property 'item'
        QtMocHelpers::PropertyData<QQuickItem*>(26, 0x80000000 | 27, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 2),
        // property 'x'
        QtMocHelpers::PropertyData<qint32>(28, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable, 3),
        // property 'y'
        QtMocHelpers::PropertyData<qint32>(29, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable, 4),
        // property 'width'
        QtMocHelpers::PropertyData<qint32>(30, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable, 5),
        // property 'height'
        QtMocHelpers::PropertyData<qint32>(31, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable, 6),
        // property 'radius'
        QtMocHelpers::PropertyData<qint32>(32, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'topLeftRadius'
        QtMocHelpers::PropertyData<qint32>(33, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet, 8),
        // property 'topRightRadius'
        QtMocHelpers::PropertyData<qint32>(34, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet, 9),
        // property 'bottomLeftRadius'
        QtMocHelpers::PropertyData<qint32>(35, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet, 10),
        // property 'bottomRightRadius'
        QtMocHelpers::PropertyData<qint32>(36, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet, 11),
        // property 'regions'
        QtMocHelpers::PropertyData<QQmlListProperty<PendingRegion>>(2, 0x80000000 | 37, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<PendingRegion, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN13PendingRegionE[] = {
    QMetaObject::SuperData::link<RegionShape::staticMetaObject>(),
    QMetaObject::SuperData::link<Intersection::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject PendingRegion::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13PendingRegionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13PendingRegionE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN13PendingRegionE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13PendingRegionE_t>.metaTypes,
    nullptr
} };

void PendingRegion::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PendingRegion *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->shapeChanged(); break;
        case 1: _t->intersectionChanged(); break;
        case 2: _t->itemChanged(); break;
        case 3: _t->xChanged(); break;
        case 4: _t->yChanged(); break;
        case 5: _t->widthChanged(); break;
        case 6: _t->heightChanged(); break;
        case 7: _t->radiusChanged(); break;
        case 8: _t->topLeftRadiusChanged(); break;
        case 9: _t->topRightRadiusChanged(); break;
        case 10: _t->bottomLeftRadiusChanged(); break;
        case 11: _t->bottomRightRadiusChanged(); break;
        case 12: _t->childrenChanged(); break;
        case 13: _t->changed(); break;
        case 14: _t->onItemDestroyed(); break;
        case 15: _t->onChildDestroyed(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (PendingRegion::*)()>(_a, &PendingRegion::shapeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (PendingRegion::*)()>(_a, &PendingRegion::intersectionChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (PendingRegion::*)()>(_a, &PendingRegion::itemChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (PendingRegion::*)()>(_a, &PendingRegion::xChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (PendingRegion::*)()>(_a, &PendingRegion::yChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (PendingRegion::*)()>(_a, &PendingRegion::widthChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (PendingRegion::*)()>(_a, &PendingRegion::heightChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (PendingRegion::*)()>(_a, &PendingRegion::radiusChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (PendingRegion::*)()>(_a, &PendingRegion::topLeftRadiusChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (PendingRegion::*)()>(_a, &PendingRegion::topRightRadiusChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (PendingRegion::*)()>(_a, &PendingRegion::bottomLeftRadiusChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (PendingRegion::*)()>(_a, &PendingRegion::bottomRightRadiusChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (PendingRegion::*)()>(_a, &PendingRegion::childrenChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (PendingRegion::*)()>(_a, &PendingRegion::changed, 13))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQuickItem* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<RegionShape::Enum*>(_v) = _t->mShape; break;
        case 1: *reinterpret_cast<Intersection::Enum*>(_v) = _t->mIntersection; break;
        case 2: *reinterpret_cast<QQuickItem**>(_v) = _t->mItem; break;
        case 3: *reinterpret_cast<qint32*>(_v) = _t->mX; break;
        case 4: *reinterpret_cast<qint32*>(_v) = _t->mY; break;
        case 5: *reinterpret_cast<qint32*>(_v) = _t->mWidth; break;
        case 6: *reinterpret_cast<qint32*>(_v) = _t->mHeight; break;
        case 7: *reinterpret_cast<qint32*>(_v) = _t->radius(); break;
        case 8: *reinterpret_cast<qint32*>(_v) = _t->topLeftRadius(); break;
        case 9: *reinterpret_cast<qint32*>(_v) = _t->topRightRadius(); break;
        case 10: *reinterpret_cast<qint32*>(_v) = _t->bottomLeftRadius(); break;
        case 11: *reinterpret_cast<qint32*>(_v) = _t->bottomRightRadius(); break;
        case 12: *reinterpret_cast<QQmlListProperty<PendingRegion>*>(_v) = _t->regions(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (QtMocHelpers::setProperty(_t->mShape, *reinterpret_cast<RegionShape::Enum*>(_v)))
                Q_EMIT _t->shapeChanged();
            break;
        case 1:
            if (QtMocHelpers::setProperty(_t->mIntersection, *reinterpret_cast<Intersection::Enum*>(_v)))
                Q_EMIT _t->intersectionChanged();
            break;
        case 2: _t->setItem(*reinterpret_cast<QQuickItem**>(_v)); break;
        case 3:
            if (QtMocHelpers::setProperty(_t->mX, *reinterpret_cast<qint32*>(_v)))
                Q_EMIT _t->xChanged();
            break;
        case 4:
            if (QtMocHelpers::setProperty(_t->mY, *reinterpret_cast<qint32*>(_v)))
                Q_EMIT _t->yChanged();
            break;
        case 5:
            if (QtMocHelpers::setProperty(_t->mWidth, *reinterpret_cast<qint32*>(_v)))
                Q_EMIT _t->widthChanged();
            break;
        case 6:
            if (QtMocHelpers::setProperty(_t->mHeight, *reinterpret_cast<qint32*>(_v)))
                Q_EMIT _t->heightChanged();
            break;
        case 7: _t->setRadius(*reinterpret_cast<qint32*>(_v)); break;
        case 8: _t->setTopLeftRadius(*reinterpret_cast<qint32*>(_v)); break;
        case 9: _t->setTopRightRadius(*reinterpret_cast<qint32*>(_v)); break;
        case 10: _t->setBottomLeftRadius(*reinterpret_cast<qint32*>(_v)); break;
        case 11: _t->setBottomRightRadius(*reinterpret_cast<qint32*>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 8: _t->resetTopLeftRadius(); break;
        case 9: _t->resetTopRightRadius(); break;
        case 10: _t->resetBottomLeftRadius(); break;
        case 11: _t->resetBottomRightRadius(); break;
        default: break;
        }
    }
}

const QMetaObject *PendingRegion::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PendingRegion::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13PendingRegionE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PendingRegion::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void PendingRegion::shapeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PendingRegion::intersectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PendingRegion::itemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PendingRegion::xChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void PendingRegion::yChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void PendingRegion::widthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void PendingRegion::heightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void PendingRegion::radiusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void PendingRegion::topLeftRadiusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void PendingRegion::topRightRadiusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void PendingRegion::bottomLeftRadiusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void PendingRegion::bottomRightRadiusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void PendingRegion::childrenChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void PendingRegion::changed()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}
namespace {
struct qt_meta_tag_ZN11RegionShapeE_t {};
} // unnamed namespace

template <> constexpr inline auto RegionShape::qt_create_metaobjectdata<qt_meta_tag_ZN11RegionShapeE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "RegionShape",
        "QML.Element",
        "auto",
        "Enum",
        "Rect",
        "Ellipse"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<Enum>(3, 3, QMC::EnumFlags{}).add({
            {    4, Enum::Rect },
            {    5, Enum::Ellipse },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN11RegionShapeE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}

static constexpr auto qt_staticMetaObjectContent_ZN11RegionShapeE =
    RegionShape::qt_create_metaobjectdata<qt_meta_tag_ZN11RegionShapeE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN11RegionShapeE =
    qt_staticMetaObjectContent_ZN11RegionShapeE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN11RegionShapeE =
    qt_staticMetaObjectContent_ZN11RegionShapeE.relocatingData;

Q_CONSTINIT const QMetaObject RegionShape::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN11RegionShapeE.stringdata,
    qt_staticMetaObjectStaticContent_ZN11RegionShapeE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN11RegionShapeE.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN12IntersectionE_t {};
} // unnamed namespace

template <> constexpr inline auto Intersection::qt_create_metaobjectdata<qt_meta_tag_ZN12IntersectionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Intersection",
        "QML.Element",
        "auto",
        "Enum",
        "Combine",
        "Subtract",
        "Intersect",
        "Xor"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<Enum>(3, 3, QMC::EnumFlags{}).add({
            {    4, Enum::Combine },
            {    5, Enum::Subtract },
            {    6, Enum::Intersect },
            {    7, Enum::Xor },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN12IntersectionE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}

static constexpr auto qt_staticMetaObjectContent_ZN12IntersectionE =
    Intersection::qt_create_metaobjectdata<qt_meta_tag_ZN12IntersectionE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN12IntersectionE =
    qt_staticMetaObjectContent_ZN12IntersectionE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN12IntersectionE =
    qt_staticMetaObjectContent_ZN12IntersectionE.relocatingData;

Q_CONSTINIT const QMetaObject Intersection::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN12IntersectionE.stringdata,
    qt_staticMetaObjectStaticContent_ZN12IntersectionE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN12IntersectionE.metaTypes,
    nullptr
} };

QT_WARNING_POP
