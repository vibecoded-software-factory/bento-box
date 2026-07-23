/****************************************************************************
** Meta object code from reading C++ file 'popupwindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/window/popupwindow.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'popupwindow.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN16ProxyPopupWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto ProxyPopupWindow::qt_create_metaobjectdata<qt_meta_tag_ZN16ProxyPopupWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ProxyPopupWindow",
        "QML.Element",
        "PopupWindow",
        "parentWindowChanged",
        "",
        "relativeXChanged",
        "relativeYChanged",
        "grabFocusChanged",
        "onParentWindowChanged",
        "onClosed",
        "reposition",
        "parentWindow",
        "relativeX",
        "relativeY",
        "anchor",
        "PopupAnchor*",
        "grabFocus"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'parentWindowChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'relativeXChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'relativeYChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'grabFocusChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onParentWindowChanged'
        QtMocHelpers::SlotData<void()>(8, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onClosed'
        QtMocHelpers::SlotData<void()>(9, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'reposition'
        QtMocHelpers::SlotData<void()>(10, 4, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'parentWindow'
        QtMocHelpers::PropertyData<QObject*>(11, QMetaType::QObjectStar, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'relativeX'
        QtMocHelpers::PropertyData<qint32>(12, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'relativeY'
        QtMocHelpers::PropertyData<qint32>(13, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'anchor'
        QtMocHelpers::PropertyData<PopupAnchor*>(14, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'grabFocus'
        QtMocHelpers::PropertyData<bool>(16, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<ProxyPopupWindow, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject ProxyPopupWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<ProxyWindowBase::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16ProxyPopupWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16ProxyPopupWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16ProxyPopupWindowE_t>.metaTypes,
    nullptr
} };

void ProxyPopupWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ProxyPopupWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->parentWindowChanged(); break;
        case 1: _t->relativeXChanged(); break;
        case 2: _t->relativeYChanged(); break;
        case 3: _t->grabFocusChanged(); break;
        case 4: _t->onParentWindowChanged(); break;
        case 5: _t->onClosed(); break;
        case 6: _t->reposition(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ProxyPopupWindow::*)()>(_a, &ProxyPopupWindow::parentWindowChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyPopupWindow::*)()>(_a, &ProxyPopupWindow::relativeXChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyPopupWindow::*)()>(_a, &ProxyPopupWindow::relativeYChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyPopupWindow::*)()>(_a, &ProxyPopupWindow::grabFocusChanged, 3))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PopupAnchor* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QObject**>(_v) = _t->parentWindow(); break;
        case 1: *reinterpret_cast<qint32*>(_v) = _t->relativeX(); break;
        case 2: *reinterpret_cast<qint32*>(_v) = _t->relativeY(); break;
        case 3: *reinterpret_cast<PopupAnchor**>(_v) = _t->anchor(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->bindableGrabFocus().value(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setParentWindow(*reinterpret_cast<QObject**>(_v)); break;
        case 1: _t->setRelativeX(*reinterpret_cast<qint32*>(_v)); break;
        case 2: _t->setRelativeY(*reinterpret_cast<qint32*>(_v)); break;
        case 4: {
            _t->bindableGrabFocus().setValue(*reinterpret_cast<bool*>(_v));
            break;
        }
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 4: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableGrabFocus(); break;
        default: break;
        }
    }
}

const QMetaObject *ProxyPopupWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProxyPopupWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16ProxyPopupWindowE_t>.strings))
        return static_cast<void*>(this);
    return ProxyWindowBase::qt_metacast(_clname);
}

int ProxyPopupWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ProxyPopupWindow::parentWindowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ProxyPopupWindow::relativeXChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ProxyPopupWindow::relativeYChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ProxyPopupWindow::grabFocusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
