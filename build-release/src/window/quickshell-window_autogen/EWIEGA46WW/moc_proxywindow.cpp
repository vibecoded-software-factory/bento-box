/****************************************************************************
** Meta object code from reading C++ file 'proxywindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/window/proxywindow.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proxywindow.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15ProxyWindowBaseE_t {};
} // unnamed namespace

template <> constexpr inline auto ProxyWindowBase::qt_create_metaobjectdata<qt_meta_tag_ZN15ProxyWindowBaseE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ProxyWindowBase",
        "DefaultProperty",
        "data",
        "closed",
        "",
        "resourcesLost",
        "windowConnected",
        "windowDestroyed",
        "visibleChanged",
        "backerVisibilityChanged",
        "xChanged",
        "yChanged",
        "implicitWidthChanged",
        "implicitHeightChanged",
        "widthChanged",
        "heightChanged",
        "devicePixelRatioChanged",
        "windowTransformChanged",
        "screenChanged",
        "colorChanged",
        "maskChanged",
        "surfaceFormatChanged",
        "updatesEnabledChanged",
        "polished",
        "onWidthChanged",
        "onHeightChanged",
        "onPolished",
        "onSceneGraphError",
        "QQuickWindow::SceneGraphError",
        "error",
        "message",
        "onVisibleChanged",
        "onMaskChanged",
        "onMaskDestroyed",
        "onScreenDestroyed",
        "onExposed",
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
        "_backingWindow",
        "QQuickWindow*",
        "contentItem",
        "visible",
        "implicitWidth",
        "implicitHeight",
        "devicePixelRatio",
        "screen",
        "QuickshellScreenInfo*",
        "color",
        "QColor",
        "mask",
        "PendingRegion*",
        "windowTransform",
        "backingWindowVisible",
        "surfaceFormat",
        "QsSurfaceFormat",
        "updatesEnabled",
        "QQmlListProperty<QObject>"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'closed'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'resourcesLost'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'windowConnected'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'windowDestroyed'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'visibleChanged'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'backerVisibilityChanged'
        QtMocHelpers::SignalData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'xChanged'
        QtMocHelpers::SignalData<void()>(10, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'yChanged'
        QtMocHelpers::SignalData<void()>(11, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'implicitWidthChanged'
        QtMocHelpers::SignalData<void()>(12, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'implicitHeightChanged'
        QtMocHelpers::SignalData<void()>(13, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'widthChanged'
        QtMocHelpers::SignalData<void()>(14, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'heightChanged'
        QtMocHelpers::SignalData<void()>(15, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'devicePixelRatioChanged'
        QtMocHelpers::SignalData<void()>(16, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'windowTransformChanged'
        QtMocHelpers::SignalData<void()>(17, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'screenChanged'
        QtMocHelpers::SignalData<void()>(18, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'colorChanged'
        QtMocHelpers::SignalData<void()>(19, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'maskChanged'
        QtMocHelpers::SignalData<void()>(20, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'surfaceFormatChanged'
        QtMocHelpers::SignalData<void()>(21, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'updatesEnabledChanged'
        QtMocHelpers::SignalData<void()>(22, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'polished'
        QtMocHelpers::SignalData<void()>(23, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onWidthChanged'
        QtMocHelpers::SlotData<void()>(24, 4, QMC::AccessProtected, QMetaType::Void),
        // Slot 'onHeightChanged'
        QtMocHelpers::SlotData<void()>(25, 4, QMC::AccessProtected, QMetaType::Void),
        // Slot 'onPolished'
        QtMocHelpers::SlotData<void()>(26, 4, QMC::AccessProtected, QMetaType::Void),
        // Slot 'onSceneGraphError'
        QtMocHelpers::SlotData<void(QQuickWindow::SceneGraphError, const QString &)>(27, 4, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 28, 29 }, { QMetaType::QString, 30 },
        }}),
        // Slot 'onVisibleChanged'
        QtMocHelpers::SlotData<void()>(31, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onMaskChanged'
        QtMocHelpers::SlotData<void()>(32, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onMaskDestroyed'
        QtMocHelpers::SlotData<void()>(33, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onScreenDestroyed'
        QtMocHelpers::SlotData<void()>(34, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onExposed'
        QtMocHelpers::SlotData<void()>(35, 4, QMC::AccessPrivate, QMetaType::Void),
        // Method 'itemPosition'
        QtMocHelpers::MethodData<QPointF(QQuickItem *) const>(36, 4, QMC::AccessPublic, 0x80000000 | 37, {{
            { 0x80000000 | 38, 39 },
        }}),
        // Method 'itemRect'
        QtMocHelpers::MethodData<QRectF(QQuickItem *) const>(40, 4, QMC::AccessPublic, 0x80000000 | 41, {{
            { 0x80000000 | 38, 39 },
        }}),
        // Method 'mapFromItem'
        QtMocHelpers::MethodData<QPointF(QQuickItem *, QPointF) const>(42, 4, QMC::AccessPublic, 0x80000000 | 37, {{
            { 0x80000000 | 38, 39 }, { 0x80000000 | 37, 43 },
        }}),
        // Method 'mapFromItem'
        QtMocHelpers::MethodData<QPointF(QQuickItem *, qreal, qreal) const>(42, 4, QMC::AccessPublic, 0x80000000 | 37, {{
            { 0x80000000 | 38, 39 }, { QMetaType::QReal, 44 }, { QMetaType::QReal, 45 },
        }}),
        // Method 'mapFromItem'
        QtMocHelpers::MethodData<QRectF(QQuickItem *, QRectF) const>(42, 4, QMC::AccessPublic, 0x80000000 | 41, {{
            { 0x80000000 | 38, 39 }, { 0x80000000 | 41, 46 },
        }}),
        // Method 'mapFromItem'
        QtMocHelpers::MethodData<QRectF(QQuickItem *, qreal, qreal, qreal, qreal) const>(42, 4, QMC::AccessPublic, 0x80000000 | 41, {{
            { 0x80000000 | 38, 39 }, { QMetaType::QReal, 44 }, { QMetaType::QReal, 45 }, { QMetaType::QReal, 47 },
            { QMetaType::QReal, 48 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property '_backingWindow'
        QtMocHelpers::PropertyData<QQuickWindow*>(49, 0x80000000 | 50, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'contentItem'
        QtMocHelpers::PropertyData<QQuickItem*>(51, 0x80000000 | 38, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'visible'
        QtMocHelpers::PropertyData<bool>(52, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'implicitWidth'
        QtMocHelpers::PropertyData<qint32>(53, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 8),
        // property 'implicitHeight'
        QtMocHelpers::PropertyData<qint32>(54, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 9),
        // property 'width'
        QtMocHelpers::PropertyData<qint32>(47, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 10),
        // property 'height'
        QtMocHelpers::PropertyData<qint32>(48, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 11),
        // property 'devicePixelRatio'
        QtMocHelpers::PropertyData<qreal>(55, QMetaType::QReal, QMC::DefaultPropertyFlags, 12),
        // property 'screen'
        QtMocHelpers::PropertyData<QuickshellScreenInfo*>(56, 0x80000000 | 57, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 14),
        // property 'color'
        QtMocHelpers::PropertyData<QColor>(58, 0x80000000 | 59, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 15),
        // property 'mask'
        QtMocHelpers::PropertyData<PendingRegion*>(60, 0x80000000 | 61, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 16),
        // property 'windowTransform'
        QtMocHelpers::PropertyData<QObject*>(62, QMetaType::QObjectStar, QMC::DefaultPropertyFlags, 13),
        // property 'backingWindowVisible'
        QtMocHelpers::PropertyData<bool>(63, QMetaType::Bool, QMC::DefaultPropertyFlags, 5),
        // property 'surfaceFormat'
        QtMocHelpers::PropertyData<QsSurfaceFormat>(64, 0x80000000 | 65, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 17),
        // property 'updatesEnabled'
        QtMocHelpers::PropertyData<bool>(66, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 18),
        // property 'data'
        QtMocHelpers::PropertyData<QQmlListProperty<QObject>>(2, 0x80000000 | 67, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<ProxyWindowBase, qt_meta_tag_ZN15ProxyWindowBaseE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject ProxyWindowBase::staticMetaObject = { {
    QMetaObject::SuperData::link<Reloadable::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15ProxyWindowBaseE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15ProxyWindowBaseE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15ProxyWindowBaseE_t>.metaTypes,
    nullptr
} };

void ProxyWindowBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ProxyWindowBase *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->resourcesLost(); break;
        case 2: _t->windowConnected(); break;
        case 3: _t->windowDestroyed(); break;
        case 4: _t->visibleChanged(); break;
        case 5: _t->backerVisibilityChanged(); break;
        case 6: _t->xChanged(); break;
        case 7: _t->yChanged(); break;
        case 8: _t->implicitWidthChanged(); break;
        case 9: _t->implicitHeightChanged(); break;
        case 10: _t->widthChanged(); break;
        case 11: _t->heightChanged(); break;
        case 12: _t->devicePixelRatioChanged(); break;
        case 13: _t->windowTransformChanged(); break;
        case 14: _t->screenChanged(); break;
        case 15: _t->colorChanged(); break;
        case 16: _t->maskChanged(); break;
        case 17: _t->surfaceFormatChanged(); break;
        case 18: _t->updatesEnabledChanged(); break;
        case 19: _t->polished(); break;
        case 20: _t->onWidthChanged(); break;
        case 21: _t->onHeightChanged(); break;
        case 22: _t->onPolished(); break;
        case 23: _t->onSceneGraphError((*reinterpret_cast<std::add_pointer_t<QQuickWindow::SceneGraphError>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 24: _t->onVisibleChanged(); break;
        case 25: _t->onMaskChanged(); break;
        case 26: _t->onMaskDestroyed(); break;
        case 27: _t->onScreenDestroyed(); break;
        case 28: _t->onExposed(); break;
        case 29: { QPointF _r = _t->itemPosition((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QPointF*>(_a[0]) = std::move(_r); }  break;
        case 30: { QRectF _r = _t->itemRect((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QRectF*>(_a[0]) = std::move(_r); }  break;
        case 31: { QPointF _r = _t->mapFromItem((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QPointF>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QPointF*>(_a[0]) = std::move(_r); }  break;
        case 32: { QPointF _r = _t->mapFromItem((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[3])));
            if (_a[0]) *reinterpret_cast<QPointF*>(_a[0]) = std::move(_r); }  break;
        case 33: { QRectF _r = _t->mapFromItem((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QRectF>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QRectF*>(_a[0]) = std::move(_r); }  break;
        case 34: { QRectF _r = _t->mapFromItem((*reinterpret_cast<std::add_pointer_t<QQuickItem*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[4])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[5])));
            if (_a[0]) *reinterpret_cast<QRectF*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 29:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        case 30:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        case 31:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        case 32:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        case 33:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        case 34:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::closed, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::resourcesLost, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::windowConnected, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::windowDestroyed, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::visibleChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::backerVisibilityChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::xChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::yChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::implicitWidthChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::implicitHeightChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::widthChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::heightChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::devicePixelRatioChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::windowTransformChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::screenChanged, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::colorChanged, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::maskChanged, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::surfaceFormatChanged, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::updatesEnabledChanged, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowBase::*)()>(_a, &ProxyWindowBase::polished, 19))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PendingRegion* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQuickItem* >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQuickWindow* >(); break;
        case 8:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QuickshellScreenInfo* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QQuickWindow**>(_v) = _t->backingWindow(); break;
        case 1: *reinterpret_cast<QQuickItem**>(_v) = _t->contentItem(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isVisible(); break;
        case 3: *reinterpret_cast<qint32*>(_v) = _t->implicitWidth(); break;
        case 4: *reinterpret_cast<qint32*>(_v) = _t->implicitHeight(); break;
        case 5: *reinterpret_cast<qint32*>(_v) = _t->width(); break;
        case 6: *reinterpret_cast<qint32*>(_v) = _t->height(); break;
        case 7: *reinterpret_cast<qreal*>(_v) = _t->devicePixelRatio(); break;
        case 8: *reinterpret_cast<QuickshellScreenInfo**>(_v) = _t->screen(); break;
        case 9: *reinterpret_cast<QColor*>(_v) = _t->color(); break;
        case 10: *reinterpret_cast<PendingRegion**>(_v) = _t->mask(); break;
        case 11: *reinterpret_cast<QObject**>(_v) = _t->windowTransform(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->isVisibleDirect(); break;
        case 13: *reinterpret_cast<QsSurfaceFormat*>(_v) = _t->surfaceFormat(); break;
        case 14: *reinterpret_cast<bool*>(_v) = _t->updatesEnabled(); break;
        case 15: *reinterpret_cast<QQmlListProperty<QObject>*>(_v) = _t->data(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setVisible(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setImplicitWidth(*reinterpret_cast<qint32*>(_v)); break;
        case 4: _t->setImplicitHeight(*reinterpret_cast<qint32*>(_v)); break;
        case 5: _t->setWidth(*reinterpret_cast<qint32*>(_v)); break;
        case 6: _t->setHeight(*reinterpret_cast<qint32*>(_v)); break;
        case 8: _t->setScreen(*reinterpret_cast<QuickshellScreenInfo**>(_v)); break;
        case 9: _t->setColor(*reinterpret_cast<QColor*>(_v)); break;
        case 10: _t->setMask(*reinterpret_cast<PendingRegion**>(_v)); break;
        case 13: _t->setSurfaceFormat(*reinterpret_cast<QsSurfaceFormat*>(_v)); break;
        case 14: _t->setUpdatesEnabled(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *ProxyWindowBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProxyWindowBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15ProxyWindowBaseE_t>.strings))
        return static_cast<void*>(this);
    return Reloadable::qt_metacast(_clname);
}

int ProxyWindowBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Reloadable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void ProxyWindowBase::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ProxyWindowBase::resourcesLost()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ProxyWindowBase::windowConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ProxyWindowBase::windowDestroyed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ProxyWindowBase::visibleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ProxyWindowBase::backerVisibilityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ProxyWindowBase::xChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void ProxyWindowBase::yChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void ProxyWindowBase::implicitWidthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void ProxyWindowBase::implicitHeightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void ProxyWindowBase::widthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void ProxyWindowBase::heightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void ProxyWindowBase::devicePixelRatioChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void ProxyWindowBase::windowTransformChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void ProxyWindowBase::screenChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void ProxyWindowBase::colorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void ProxyWindowBase::maskChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void ProxyWindowBase::surfaceFormatChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void ProxyWindowBase::updatesEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void ProxyWindowBase::polished()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}
namespace {
struct qt_meta_tag_ZN19ProxyWindowAttachedE_t {};
} // unnamed namespace

template <> constexpr inline auto ProxyWindowAttached::qt_create_metaobjectdata<qt_meta_tag_ZN19ProxyWindowAttachedE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ProxyWindowAttached"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ProxyWindowAttached, qt_meta_tag_ZN19ProxyWindowAttachedE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ProxyWindowAttached::staticMetaObject = { {
    QMetaObject::SuperData::link<QsWindowAttached::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19ProxyWindowAttachedE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19ProxyWindowAttachedE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19ProxyWindowAttachedE_t>.metaTypes,
    nullptr
} };

void ProxyWindowAttached::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ProxyWindowAttached *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *ProxyWindowAttached::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProxyWindowAttached::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19ProxyWindowAttachedE_t>.strings))
        return static_cast<void*>(this);
    return QsWindowAttached::qt_metacast(_clname);
}

int ProxyWindowAttached::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QsWindowAttached::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN17QsQuickWindowBaseE_t {};
} // unnamed namespace

template <> constexpr inline auto QsQuickWindowBase::qt_create_metaobjectdata<qt_meta_tag_ZN17QsQuickWindowBaseE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QsQuickWindowBase",
        "onSceneGraphInitialized",
        ""
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'onSceneGraphInitialized'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QsQuickWindowBase, qt_meta_tag_ZN17QsQuickWindowBaseE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QsQuickWindowBase::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QsQuickWindowBaseE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QsQuickWindowBaseE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QsQuickWindowBaseE_t>.metaTypes,
    nullptr
} };

void QsQuickWindowBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QsQuickWindowBase *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onSceneGraphInitialized(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *QsQuickWindowBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QsQuickWindowBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QsQuickWindowBaseE_t>.strings))
        return static_cast<void*>(this);
    return QQuickWindow::qt_metacast(_clname);
}

int QsQuickWindowBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickWindow::qt_metacall(_c, _id, _a);
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
    return _id;
}
namespace {
struct qt_meta_tag_ZN13ProxiedWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto ProxiedWindow::qt_create_metaobjectdata<qt_meta_tag_ZN13ProxiedWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ProxiedWindow",
        "exposed",
        "",
        "devicePixelRatioChanged"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'exposed'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'devicePixelRatioChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ProxiedWindow, qt_meta_tag_ZN13ProxiedWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ProxiedWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QsQuickWindowBase::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ProxiedWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ProxiedWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13ProxiedWindowE_t>.metaTypes,
    nullptr
} };

void ProxiedWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ProxiedWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->exposed(); break;
        case 1: _t->devicePixelRatioChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ProxiedWindow::*)()>(_a, &ProxiedWindow::exposed, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxiedWindow::*)()>(_a, &ProxiedWindow::devicePixelRatioChanged, 1))
            return;
    }
}

const QMetaObject *ProxiedWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProxiedWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ProxiedWindowE_t>.strings))
        return static_cast<void*>(this);
    return QsQuickWindowBase::qt_metacast(_clname);
}

int ProxiedWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QsQuickWindowBase::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void ProxiedWindow::exposed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ProxiedWindow::devicePixelRatioChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
namespace {
struct qt_meta_tag_ZN22ProxyWindowContentItemE_t {};
} // unnamed namespace

template <> constexpr inline auto ProxyWindowContentItem::qt_create_metaobjectdata<qt_meta_tag_ZN22ProxyWindowContentItemE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ProxyWindowContentItem",
        "polished",
        ""
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'polished'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ProxyWindowContentItem, qt_meta_tag_ZN22ProxyWindowContentItemE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ProxyWindowContentItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22ProxyWindowContentItemE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22ProxyWindowContentItemE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN22ProxyWindowContentItemE_t>.metaTypes,
    nullptr
} };

void ProxyWindowContentItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ProxyWindowContentItem *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->polished(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ProxyWindowContentItem::*)()>(_a, &ProxyWindowContentItem::polished, 0))
            return;
    }
}

const QMetaObject *ProxyWindowContentItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProxyWindowContentItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22ProxyWindowContentItemE_t>.strings))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int ProxyWindowContentItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void ProxyWindowContentItem::polished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
