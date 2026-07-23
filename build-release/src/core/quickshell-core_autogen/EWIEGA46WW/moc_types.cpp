/****************************************************************************
** Meta object code from reading C++ file 'types.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/types.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'types.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN3BoxE_t {};
} // unnamed namespace

template <> constexpr inline auto Box::qt_create_metaobjectdata<qt_meta_tag_ZN3BoxE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Box",
        "QML.Creatable",
        "true",
        "QML.CreationMethod",
        "construct",
        "QML.Element",
        "box",
        "",
        "QRect",
        "rect",
        "QPoint",
        "QRectF",
        "QPointF",
        "x",
        "y",
        "w",
        "h",
        "width",
        "height"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'x'
        QtMocHelpers::PropertyData<qint32>(13, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'y'
        QtMocHelpers::PropertyData<qint32>(14, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'w'
        QtMocHelpers::PropertyData<qint32>(15, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'h'
        QtMocHelpers::PropertyData<qint32>(16, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'width'
        QtMocHelpers::PropertyData<qint32>(17, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'height'
        QtMocHelpers::PropertyData<qint32>(18, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable),
    };
    QtMocHelpers::UintData qt_enums {
    };
    using Constructor = QtMocHelpers::NoType;
    QtMocHelpers::UintData qt_constructors {
        QtMocHelpers::ConstructorData<Constructor(const QRect &)>(7, QMC::AccessPublic, {{
            { 0x80000000 | 8, 9 },
        }}),
        QtMocHelpers::ConstructorData<Constructor(const QPoint &)>(7, QMC::AccessPublic, {{
            { 0x80000000 | 10, 9 },
        }}),
        QtMocHelpers::ConstructorData<Constructor(const QRectF &)>(7, QMC::AccessPublic, {{
            { 0x80000000 | 11, 9 },
        }}),
        QtMocHelpers::ConstructorData<Constructor(const QPointF &)>(7, QMC::AccessPublic, {{
            { 0x80000000 | 12, 9 },
        }}),
    };
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<Box, void>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject Box::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3BoxE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3BoxE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN3BoxE_t>.metaTypes,
    nullptr
} };

void Box::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<Box *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { Box *_r = new Box((*reinterpret_cast<std::add_pointer_t<QRect>>(_a[1])));
            if (_a[0]) *reinterpret_cast<void**>(_a[0]) = _r; } break;
        case 1: { Box *_r = new Box((*reinterpret_cast<std::add_pointer_t<QPoint>>(_a[1])));
            if (_a[0]) *reinterpret_cast<void**>(_a[0]) = _r; } break;
        case 2: { Box *_r = new Box((*reinterpret_cast<std::add_pointer_t<QRectF>>(_a[1])));
            if (_a[0]) *reinterpret_cast<void**>(_a[0]) = _r; } break;
        case 3: { Box *_r = new Box((*reinterpret_cast<std::add_pointer_t<QPointF>>(_a[1])));
            if (_a[0]) *reinterpret_cast<void**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) Box((*reinterpret_cast<std::add_pointer_t<QRect>>(_a[1]))); } break;
        case 1: { new (_a[0]) Box((*reinterpret_cast<std::add_pointer_t<QPoint>>(_a[1]))); } break;
        case 2: { new (_a[0]) Box((*reinterpret_cast<std::add_pointer_t<QRectF>>(_a[1]))); } break;
        case 3: { new (_a[0]) Box((*reinterpret_cast<std::add_pointer_t<QPointF>>(_a[1]))); } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qint32*>(_v) = _t->x; break;
        case 1: *reinterpret_cast<qint32*>(_v) = _t->y; break;
        case 2: *reinterpret_cast<qint32*>(_v) = _t->w; break;
        case 3: *reinterpret_cast<qint32*>(_v) = _t->h; break;
        case 4: *reinterpret_cast<qint32*>(_v) = _t->w; break;
        case 5: *reinterpret_cast<qint32*>(_v) = _t->h; break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: QtMocHelpers::setProperty(_t->x, *reinterpret_cast<qint32*>(_v)); break;
        case 1: QtMocHelpers::setProperty(_t->y, *reinterpret_cast<qint32*>(_v)); break;
        case 2: QtMocHelpers::setProperty(_t->w, *reinterpret_cast<qint32*>(_v)); break;
        case 3: QtMocHelpers::setProperty(_t->h, *reinterpret_cast<qint32*>(_v)); break;
        case 4: QtMocHelpers::setProperty(_t->w, *reinterpret_cast<qint32*>(_v)); break;
        case 5: QtMocHelpers::setProperty(_t->h, *reinterpret_cast<qint32*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN7MarginsE_t {};
} // unnamed namespace

template <> constexpr inline auto Margins::qt_create_metaobjectdata<qt_meta_tag_ZN7MarginsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Margins",
        "QML.Creatable",
        "true",
        "QML.CreationMethod",
        "construct",
        "QML.Element",
        "margins",
        "left",
        "right",
        "top",
        "bottom"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'left'
        QtMocHelpers::PropertyData<qint32>(7, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'right'
        QtMocHelpers::PropertyData<qint32>(8, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'top'
        QtMocHelpers::PropertyData<qint32>(9, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'bottom'
        QtMocHelpers::PropertyData<qint32>(10, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<Margins, void>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject Margins::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7MarginsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7MarginsE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7MarginsE_t>.metaTypes,
    nullptr
} };

void Margins::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<Margins *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qint32*>(_v) = _t->left; break;
        case 1: *reinterpret_cast<qint32*>(_v) = _t->right; break;
        case 2: *reinterpret_cast<qint32*>(_v) = _t->top; break;
        case 3: *reinterpret_cast<qint32*>(_v) = _t->bottom; break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: QtMocHelpers::setProperty(_t->left, *reinterpret_cast<qint32*>(_v)); break;
        case 1: QtMocHelpers::setProperty(_t->right, *reinterpret_cast<qint32*>(_v)); break;
        case 2: QtMocHelpers::setProperty(_t->top, *reinterpret_cast<qint32*>(_v)); break;
        case 3: QtMocHelpers::setProperty(_t->bottom, *reinterpret_cast<qint32*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN5EdgesE_t {};
} // unnamed namespace

template <> constexpr inline auto Edges::qt_create_metaobjectdata<qt_meta_tag_ZN5EdgesE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Edges",
        "QML.Element",
        "Enum",
        "None",
        "Top",
        "Left",
        "Right",
        "Bottom"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<Enum>(2, 2, QMC::EnumFlags{}).add({
            {    3, Enum::None },
            {    4, Enum::Top },
            {    5, Enum::Left },
            {    6, Enum::Right },
            {    7, Enum::Bottom },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    0 },
    });
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN5EdgesE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}

static constexpr auto qt_staticMetaObjectContent_ZN5EdgesE =
    Edges::qt_create_metaobjectdata<qt_meta_tag_ZN5EdgesE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN5EdgesE =
    qt_staticMetaObjectContent_ZN5EdgesE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN5EdgesE =
    qt_staticMetaObjectContent_ZN5EdgesE.relocatingData;

Q_CONSTINIT const QMetaObject Edges::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN5EdgesE.stringdata,
    qt_staticMetaObjectStaticContent_ZN5EdgesE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN5EdgesE.metaTypes,
    nullptr
} };

QT_WARNING_POP
