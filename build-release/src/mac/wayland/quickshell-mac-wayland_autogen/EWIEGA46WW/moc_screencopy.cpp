/****************************************************************************
** Meta object code from reading C++ file 'screencopy.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/wayland/screencopy.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screencopy.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs3mac7wayland14ScreencopyViewE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::wayland::ScreencopyView::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac7wayland14ScreencopyViewE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::wayland::ScreencopyView",
        "QML.Element",
        "auto",
        "captureSourceChanged",
        "",
        "paintCursorChanged",
        "liveChanged",
        "hasContentChanged",
        "sourceSizeChanged",
        "captureFrame",
        "captureSource",
        "paintCursor",
        "live",
        "hasContent",
        "sourceSize",
        "QSize"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'captureSourceChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'paintCursorChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'liveChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'hasContentChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sourceSizeChanged'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'captureFrame'
        QtMocHelpers::MethodData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'captureSource'
        QtMocHelpers::PropertyData<QObject*>(10, QMetaType::QObjectStar, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'paintCursor'
        QtMocHelpers::PropertyData<bool>(11, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'live'
        QtMocHelpers::PropertyData<bool>(12, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'hasContent'
        QtMocHelpers::PropertyData<bool>(13, QMetaType::Bool, QMC::DefaultPropertyFlags, 3),
        // property 'sourceSize'
        QtMocHelpers::PropertyData<QSize>(14, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 4),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<ScreencopyView, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::wayland::ScreencopyView::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland14ScreencopyViewE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland14ScreencopyViewE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac7wayland14ScreencopyViewE_t>.metaTypes,
    nullptr
} };

void qs::mac::wayland::ScreencopyView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ScreencopyView *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->captureSourceChanged(); break;
        case 1: _t->paintCursorChanged(); break;
        case 2: _t->liveChanged(); break;
        case 3: _t->hasContentChanged(); break;
        case 4: _t->sourceSizeChanged(); break;
        case 5: _t->captureFrame(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ScreencopyView::*)()>(_a, &ScreencopyView::captureSourceChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ScreencopyView::*)()>(_a, &ScreencopyView::paintCursorChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ScreencopyView::*)()>(_a, &ScreencopyView::liveChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ScreencopyView::*)()>(_a, &ScreencopyView::hasContentChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ScreencopyView::*)()>(_a, &ScreencopyView::sourceSizeChanged, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QObject**>(_v) = _t->captureSource(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->paintCursor(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->live(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->hasContent(); break;
        case 4: *reinterpret_cast<QSize*>(_v) = _t->sourceSize(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCaptureSource(*reinterpret_cast<QObject**>(_v)); break;
        case 1: _t->setPaintCursor(*reinterpret_cast<bool*>(_v)); break;
        case 2: _t->setLive(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::wayland::ScreencopyView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::wayland::ScreencopyView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac7wayland14ScreencopyViewE_t>.strings))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int qs::mac::wayland::ScreencopyView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
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
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::wayland::ScreencopyView::captureSourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::wayland::ScreencopyView::paintCursorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::mac::wayland::ScreencopyView::liveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::mac::wayland::ScreencopyView::hasContentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qs::mac::wayland::ScreencopyView::sourceSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
