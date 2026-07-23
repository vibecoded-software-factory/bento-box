/****************************************************************************
** Meta object code from reading C++ file 'cliprect.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/cliprect.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cliprect.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN23ClippingRectangleBorderE_t {};
} // unnamed namespace

template <> constexpr inline auto ClippingRectangleBorder::qt_create_metaobjectdata<qt_meta_tag_ZN23ClippingRectangleBorderE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ClippingRectangleBorder",
        "QML.Element",
        "clippingRectangleBorder",
        "color",
        "QColor",
        "pixelAligned",
        "width"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'color'
        QtMocHelpers::PropertyData<QColor>(3, 0x80000000 | 4, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag),
        // property 'pixelAligned'
        QtMocHelpers::PropertyData<bool>(5, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'width'
        QtMocHelpers::PropertyData<int>(6, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<ClippingRectangleBorder, void>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject ClippingRectangleBorder::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23ClippingRectangleBorderE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23ClippingRectangleBorderE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN23ClippingRectangleBorderE_t>.metaTypes,
    nullptr
} };

void ClippingRectangleBorder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<ClippingRectangleBorder *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QColor*>(_v) = _t->color; break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->pixelAligned; break;
        case 2: *reinterpret_cast<int*>(_v) = _t->width; break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: QtMocHelpers::setProperty(_t->color, *reinterpret_cast<QColor*>(_v)); break;
        case 1: QtMocHelpers::setProperty(_t->pixelAligned, *reinterpret_cast<bool*>(_v)); break;
        case 2: QtMocHelpers::setProperty(_t->width, *reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}
QT_WARNING_POP
