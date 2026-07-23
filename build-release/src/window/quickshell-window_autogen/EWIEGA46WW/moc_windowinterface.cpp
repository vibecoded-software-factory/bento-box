/****************************************************************************
** Meta object code from reading C++ file 'windowinterface.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/window/windowinterface.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windowinterface.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15QsSurfaceFormatE_t {};
} // unnamed namespace

template <> constexpr inline auto QsSurfaceFormat::qt_create_metaobjectdata<qt_meta_tag_ZN15QsSurfaceFormatE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QsSurfaceFormat",
        "QML.Element",
        "surfaceFormat",
        "QML.Creatable",
        "true",
        "QML.CreationMethod",
        "structured",
        "opaque"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'opaque'
        QtMocHelpers::PropertyData<bool>(7, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<QsSurfaceFormat, void>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject QsSurfaceFormat::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QsSurfaceFormatE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QsSurfaceFormatE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15QsSurfaceFormatE_t>.metaTypes,
    nullptr
} };

void QsSurfaceFormat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<QsSurfaceFormat *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->opaque; break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setOpaque(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN15WindowInterfaceE_t {};
} // unnamed namespace

template <> constexpr inline auto WindowInterface::qt_create_metaobjectdata<qt_meta_tag_ZN15WindowInterfaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "WindowInterface",
        "DefaultProperty",
        "data",
        "QML.Element",
        "QsWindow",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "uncreatable base class",
        "QML.Attached",
        "QsWindowAttached",
        "closed",
        "",
        "resourcesLost",
        "windowConnected",
        "visibleChanged",
        "backingWindowVisibleChanged",
        "implicitWidthChanged",
        "implicitHeightChanged",
        "widthChanged",
        "heightChanged",
        "devicePixelRatioChanged",
        "screenChanged",
        "windowTransformChanged",
        "colorChanged",
        "maskChanged",
        "surfaceFormatChanged",
        "updatesEnabledChanged",
        "itemPosition",
        "QPointF",
        "QQuickItem*",
        "item",
        "itemRect",
        "QRectF",
        "mapFromItem",
        "point",
        "x",
        "y",
        "rect",
        "width",
        "height",
        "contentItem",
        "visible",
        "backingWindowVisible",
        "implicitWidth",
        "implicitHeight",
        "devicePixelRatio",
        "screen",
        "QuickshellScreenInfo*",
        "windowTransform",
        "color",
        "QColor",
        "mask",
        "PendingRegion*",
        "surfaceFormat",
        "QsSurfaceFormat",
        "updatesEnabled",
        "QQmlListProperty<QObject>"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'closed'
        QtMocHelpers::SignalData<void()>(11, 12, QMC::AccessPublic, QMetaType::Void),
        // Signal 'resourcesLost'
        QtMocHelpers::SignalData<void()>(13, 12, QMC::AccessPublic, QMetaType::Void),
        // Signal 'windowConnected'
        QtMocHelpers::SignalData<void()>(14, 12, QMC::AccessPublic, QMetaType::Void),
        // Signal 'visibleChanged'
        QtMocHelpers::SignalData<void()>(15, 12, QMC::AccessPublic, QMetaType::Void),
        // Signal 'backingWindowVisibleChanged'
        QtMocHelpers::SignalData<void()>(16, 12, QMC::AccessPublic, QMetaType::Void),
        // Signal 'implicitWidthChanged'
        QtMocHelpers::SignalData<void()>(17, 12, QMC::AccessPublic, QMetaType::Void),
        // Signal 'implicitHeightChanged'
        QtMocHelpers::SignalData<void()>(18, 12, QMC::AccessPublic, QMetaType::Void),
        // Signal 'widthChanged'
        QtMocHelpers::SignalData<void()>(19, 12, QMC::AccessPublic, QMetaType::Void),
        // Signal 'heightChanged'
        QtMocHelpers::SignalData<void()>(20, 12, QMC::AccessPublic, QMetaType::Void),
        // Signal 'devicePixelRatioChanged'
        QtMocHelpers::SignalData<void()>(21, 12, QMC::AccessPublic, QMetaType::Void),
        // Signal 'screenChanged'
        QtMocHelpers::SignalData<void()>(22, 12, QMC::AccessPublic, QMetaType::Void),
        // Signal 'windowTransformChanged'
        QtMocHelpers::SignalData<void()>(23, 12, QMC::AccessPublic, QMetaType::Void),
        // Signal 'colorChanged'
        QtMocHelpers::SignalData<void()>(24, 12, QMC::AccessPublic, QMetaType::Void),
        // Signal 'maskChanged'
        QtMocHelpers::SignalData<void()>(25, 12, QMC::AccessPublic, QMetaType::Void),
        // Signal 'surfaceFormatChanged'
        QtMocHelpers::SignalData<void()>(26, 12, QMC::AccessPublic, QMetaType::Void),
        // Signal 'updatesEnabledChanged'
        QtMocHelpers::SignalData<void()>(27, 12, QMC::AccessPublic, QMetaType::Void),
        // Method 'itemPosition'
        QtMocHelpers::MethodData<QPointF(QQuickItem *) const>(28, 12, QMC::AccessPublic, 0x80000000 | 29, {{
            { 0x80000000 | 30, 31 },
        }}),
        // Method 'itemRect'
        QtMocHelpers::MethodData<QRectF(QQuickItem *) const>(32, 12, QMC::AccessPublic, 0x80000000 | 33, {{
            { 0x80000000 | 30, 31 },
        }}),
        // Method 'mapFromItem'
        QtMocHelpers::MethodData<QPointF(QQuickItem *, QPointF) const>(34, 12, QMC::AccessPublic, 0x80000000 | 29, {{
            { 0x80000000 | 30, 31 }, { 0x80000000 | 29, 35 },
        }}),
        // Method 'mapFromItem'
        QtMocHelpers::MethodData<QPointF(QQuickItem *, qreal, qreal) const>(34, 12, QMC::AccessPublic, 0x80000000 | 29, {{
            { 0x80000000 | 30, 31 }, { QMetaType::QReal, 36 }, { QMetaType::QReal, 37 },
        }}),
        // Method 'mapFromItem'
        QtMocHelpers::MethodData<QRectF(QQuickItem *, QRectF) const>(34, 12, QMC::AccessPublic, 0x80000000 | 33, {{
            { 0x80000000 | 30, 31 }, { 0x80000000 | 33, 38 },
        }}),
        // Method 'mapFromItem'
        QtMocHelpers::MethodData<QRectF(QQuickItem *, qreal, qreal, qreal, qreal) const>(34, 12, QMC::AccessPublic, 0x80000000 | 33, {{
            { 0x80000000 | 30, 31 }, { QMetaType::QReal, 36 }, { QMetaType::QReal, 37 }, { QMetaType::QReal, 39 },
            { QMetaType::QReal, 40 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'contentItem'
        QtMocHelpers::PropertyData<QQuickItem*>(41, 0x80000000 | 30, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'visible'
        QtMocHelpers::PropertyData<bool>(42, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'backingWindowVisible'
        QtMocHelpers::PropertyData<bool>(43, QMetaType::Bool, QMC::DefaultPropertyFlags, 4),
        // property 'implicitWidth'
        QtMocHelpers::PropertyData<qint32>(44, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'implicitHeight'
        QtMocHelpers::PropertyData<qint32>(45, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'width'
        QtMocHelpers::PropertyData<qint32>(39, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'height'
        QtMocHelpers::PropertyData<qint32>(40, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 8),
        // property 'devicePixelRatio'
        QtMocHelpers::PropertyData<qreal>(46, QMetaType::QReal, QMC::DefaultPropertyFlags, 9),
        // property 'screen'
        QtMocHelpers::PropertyData<QuickshellScreenInfo*>(47, 0x80000000 | 48, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 10),
        // property 'windowTransform'
        QtMocHelpers::PropertyData<QObject*>(49, QMetaType::QObjectStar, QMC::DefaultPropertyFlags, 11),
        // property 'color'
        QtMocHelpers::PropertyData<QColor>(50, 0x80000000 | 51, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 12),
        // property 'mask'
        QtMocHelpers::PropertyData<PendingRegion*>(52, 0x80000000 | 53, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 13),
        // property 'surfaceFormat'
        QtMocHelpers::PropertyData<QsSurfaceFormat>(54, 0x80000000 | 55, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 14),
        // property 'updatesEnabled'
        QtMocHelpers::PropertyData<bool>(56, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 15),
        // property 'data'
        QtMocHelpers::PropertyData<QQmlListProperty<QObject>>(2, 0x80000000 | 57, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
            {    7,    8 },
            {    9,   10 },
    });
    return QtMocHelpers::metaObjectData<WindowInterface, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject WindowInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<Reloadable::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15WindowInterfaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15WindowInterfaceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15WindowInterfaceE_t>.metaTypes,
    nullptr
} };

void WindowInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<WindowInterface *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->resourcesLost(); break;
        case 2: _t->windowConnected(); break;
        case 3: _t->visibleChanged(); break;
        case 4: _t->backingWindowVisibleChanged(); break;
        case 5: _t->implicitWidthChanged(); break;
        case 6: _t->implicitHeightChanged(); break;
        case 7: _t->widthChanged(); break;
        case 8: _t->heightChanged(); break;
        case 9: _t->devicePixelRatioChanged(); break;
        case 10: _t->screenChanged(); break;
        case 11: _t->windowTransformChanged(); break;
        case 12: _t->colorChanged(); break;
        case 13: _t->maskChanged(); break;
        case 14: _t->surfaceFormatChanged(); break;
        case 15: _t->updatesEnabledChanged(); break;
        case 16: { QPointF _r = _t->itemPosition((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QPointF*>(_a[0]) = std::move(_r); }  break;
        case 17: { QRectF _r = _t->itemRect((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QRectF*>(_a[0]) = std::move(_r); }  break;
        case 18: { QPointF _r = _t->mapFromItem((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QPointF>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QPointF*>(_a[0]) = std::move(_r); }  break;
        case 19: { QPointF _r = _t->mapFromItem((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[3])));
            if (_a[0]) *reinterpret_cast<QPointF*>(_a[0]) = std::move(_r); }  break;
        case 20: { QRectF _r = _t->mapFromItem((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QRectF>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QRectF*>(_a[0]) = std::move(_r); }  break;
        case 21: { QRectF _r = _t->mapFromItem((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[5])));
            if (_a[0]) *reinterpret_cast<QRectF*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (WindowInterface::*)()>(_a, &WindowInterface::closed, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowInterface::*)()>(_a, &WindowInterface::resourcesLost, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowInterface::*)()>(_a, &WindowInterface::windowConnected, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowInterface::*)()>(_a, &WindowInterface::visibleChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowInterface::*)()>(_a, &WindowInterface::backingWindowVisibleChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowInterface::*)()>(_a, &WindowInterface::implicitWidthChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowInterface::*)()>(_a, &WindowInterface::implicitHeightChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowInterface::*)()>(_a, &WindowInterface::widthChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowInterface::*)()>(_a, &WindowInterface::heightChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowInterface::*)()>(_a, &WindowInterface::devicePixelRatioChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowInterface::*)()>(_a, &WindowInterface::screenChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowInterface::*)()>(_a, &WindowInterface::windowTransformChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowInterface::*)()>(_a, &WindowInterface::colorChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowInterface::*)()>(_a, &WindowInterface::maskChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowInterface::*)()>(_a, &WindowInterface::surfaceFormatChanged, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowInterface::*)()>(_a, &WindowInterface::updatesEnabledChanged, 15))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PendingRegion* >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQuickItem* >(); break;
        case 8:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QuickshellScreenInfo* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QQuickItem**>(_v) = _t->contentItem(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isVisible(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isBackingWindowVisible(); break;
        case 3: *reinterpret_cast<qint32*>(_v) = _t->implicitWidth(); break;
        case 4: *reinterpret_cast<qint32*>(_v) = _t->implicitHeight(); break;
        case 5: *reinterpret_cast<qint32*>(_v) = _t->width(); break;
        case 6: *reinterpret_cast<qint32*>(_v) = _t->height(); break;
        case 7: *reinterpret_cast<qreal*>(_v) = _t->devicePixelRatio(); break;
        case 8: *reinterpret_cast<QuickshellScreenInfo**>(_v) = _t->screen(); break;
        case 9: *reinterpret_cast<QObject**>(_v) = _t->windowTransform(); break;
        case 10: *reinterpret_cast<QColor*>(_v) = _t->color(); break;
        case 11: *reinterpret_cast<PendingRegion**>(_v) = _t->mask(); break;
        case 12: *reinterpret_cast<QsSurfaceFormat*>(_v) = _t->surfaceFormat(); break;
        case 13: *reinterpret_cast<bool*>(_v) = _t->updatesEnabled(); break;
        case 14: *reinterpret_cast<QQmlListProperty<QObject>*>(_v) = _t->data(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setVisible(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setImplicitWidth(*reinterpret_cast<qint32*>(_v)); break;
        case 4: _t->setImplicitHeight(*reinterpret_cast<qint32*>(_v)); break;
        case 5: _t->setWidth(*reinterpret_cast<qint32*>(_v)); break;
        case 6: _t->setHeight(*reinterpret_cast<qint32*>(_v)); break;
        case 8: _t->setScreen(*reinterpret_cast<QuickshellScreenInfo**>(_v)); break;
        case 10: _t->setColor(*reinterpret_cast<QColor*>(_v)); break;
        case 11: _t->setMask(*reinterpret_cast<PendingRegion**>(_v)); break;
        case 12: _t->setSurfaceFormat(*reinterpret_cast<QsSurfaceFormat*>(_v)); break;
        case 13: _t->setUpdatesEnabled(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *WindowInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WindowInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15WindowInterfaceE_t>.strings))
        return static_cast<void*>(this);
    return Reloadable::qt_metacast(_clname);
}

int WindowInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Reloadable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void WindowInterface::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WindowInterface::resourcesLost()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WindowInterface::windowConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void WindowInterface::visibleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void WindowInterface::backingWindowVisibleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void WindowInterface::implicitWidthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void WindowInterface::implicitHeightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void WindowInterface::widthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void WindowInterface::heightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void WindowInterface::devicePixelRatioChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void WindowInterface::screenChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void WindowInterface::windowTransformChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void WindowInterface::colorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void WindowInterface::maskChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void WindowInterface::surfaceFormatChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void WindowInterface::updatesEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}
namespace {
struct qt_meta_tag_ZN16QsWindowAttachedE_t {};
} // unnamed namespace

template <> constexpr inline auto QsWindowAttached::qt_create_metaobjectdata<qt_meta_tag_ZN16QsWindowAttachedE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QsWindowAttached",
        "QML.Element",
        "anonymous",
        "windowChanged",
        "",
        "updateWindow",
        "itemPosition",
        "QPointF",
        "QQuickItem*",
        "item",
        "itemRect",
        "QRectF",
        "mapFromItem",
        "point",
        "x",
        "y",
        "rect",
        "width",
        "height",
        "window",
        "contentItem"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'windowChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'updateWindow'
        QtMocHelpers::SlotData<void()>(5, 4, QMC::AccessProtected, QMetaType::Void),
        // Method 'itemPosition'
        QtMocHelpers::MethodData<QPointF(QQuickItem *) const>(6, 4, QMC::AccessPublic, 0x80000000 | 7, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Method 'itemRect'
        QtMocHelpers::MethodData<QRectF(QQuickItem *) const>(10, 4, QMC::AccessPublic, 0x80000000 | 11, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Method 'mapFromItem'
        QtMocHelpers::MethodData<QPointF(QQuickItem *, QPointF) const>(12, 4, QMC::AccessPublic, 0x80000000 | 7, {{
            { 0x80000000 | 8, 9 }, { 0x80000000 | 7, 13 },
        }}),
        // Method 'mapFromItem'
        QtMocHelpers::MethodData<QPointF(QQuickItem *, qreal, qreal) const>(12, 4, QMC::AccessPublic, 0x80000000 | 7, {{
            { 0x80000000 | 8, 9 }, { QMetaType::QReal, 14 }, { QMetaType::QReal, 15 },
        }}),
        // Method 'mapFromItem'
        QtMocHelpers::MethodData<QRectF(QQuickItem *, QRectF) const>(12, 4, QMC::AccessPublic, 0x80000000 | 11, {{
            { 0x80000000 | 8, 9 }, { 0x80000000 | 11, 16 },
        }}),
        // Method 'mapFromItem'
        QtMocHelpers::MethodData<QRectF(QQuickItem *, qreal, qreal, qreal, qreal) const>(12, 4, QMC::AccessPublic, 0x80000000 | 11, {{
            { 0x80000000 | 8, 9 }, { QMetaType::QReal, 14 }, { QMetaType::QReal, 15 }, { QMetaType::QReal, 17 },
            { QMetaType::QReal, 18 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'window'
        QtMocHelpers::PropertyData<QObject*>(19, QMetaType::QObjectStar, QMC::DefaultPropertyFlags, 0),
        // property 'contentItem'
        QtMocHelpers::PropertyData<QQuickItem*>(20, 0x80000000 | 8, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<QsWindowAttached, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject QsWindowAttached::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QsWindowAttachedE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QsWindowAttachedE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16QsWindowAttachedE_t>.metaTypes,
    nullptr
} };

void QsWindowAttached::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QsWindowAttached *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->windowChanged(); break;
        case 1: _t->updateWindow(); break;
        case 2: { QPointF _r = _t->itemPosition((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QPointF*>(_a[0]) = std::move(_r); }  break;
        case 3: { QRectF _r = _t->itemRect((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QRectF*>(_a[0]) = std::move(_r); }  break;
        case 4: { QPointF _r = _t->mapFromItem((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QPointF>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QPointF*>(_a[0]) = std::move(_r); }  break;
        case 5: { QPointF _r = _t->mapFromItem((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[3])));
            if (_a[0]) *reinterpret_cast<QPointF*>(_a[0]) = std::move(_r); }  break;
        case 6: { QRectF _r = _t->mapFromItem((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QRectF>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QRectF*>(_a[0]) = std::move(_r); }  break;
        case 7: { QRectF _r = _t->mapFromItem((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[5])));
            if (_a[0]) *reinterpret_cast<QRectF*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QsWindowAttached::*)()>(_a, &QsWindowAttached::windowChanged, 0))
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
        case 1: *reinterpret_cast<QQuickItem**>(_v) = _t->contentItem(); break;
        default: break;
        }
    }
}

const QMetaObject *QsWindowAttached::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QsWindowAttached::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QsWindowAttachedE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QsWindowAttached::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
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
void QsWindowAttached::windowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
