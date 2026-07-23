/****************************************************************************
** Meta object code from reading C++ file 'floatingwindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/window/floatingwindow.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'floatingwindow.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19ProxyFloatingWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto ProxyFloatingWindow::qt_create_metaobjectdata<qt_meta_tag_ZN19ProxyFloatingWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ProxyFloatingWindow",
        "minimumSizeChanged",
        "",
        "maximumSizeChanged",
        "titleChanged",
        "parentWindowChanged",
        "onParentDestroyed"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'minimumSizeChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'maximumSizeChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'titleChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'parentWindowChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onParentDestroyed'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ProxyFloatingWindow, qt_meta_tag_ZN19ProxyFloatingWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ProxyFloatingWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<ProxyWindowBase::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19ProxyFloatingWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19ProxyFloatingWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19ProxyFloatingWindowE_t>.metaTypes,
    nullptr
} };

void ProxyFloatingWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ProxyFloatingWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->minimumSizeChanged(); break;
        case 1: _t->maximumSizeChanged(); break;
        case 2: _t->titleChanged(); break;
        case 3: _t->parentWindowChanged(); break;
        case 4: _t->onParentDestroyed(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ProxyFloatingWindow::*)()>(_a, &ProxyFloatingWindow::minimumSizeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyFloatingWindow::*)()>(_a, &ProxyFloatingWindow::maximumSizeChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyFloatingWindow::*)()>(_a, &ProxyFloatingWindow::titleChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ProxyFloatingWindow::*)()>(_a, &ProxyFloatingWindow::parentWindowChanged, 3))
            return;
    }
}

const QMetaObject *ProxyFloatingWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProxyFloatingWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19ProxyFloatingWindowE_t>.strings))
        return static_cast<void*>(this);
    return ProxyWindowBase::qt_metacast(_clname);
}

int ProxyFloatingWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ProxyWindowBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ProxyFloatingWindow::minimumSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ProxyFloatingWindow::maximumSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ProxyFloatingWindow::titleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ProxyFloatingWindow::parentWindowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
namespace {
struct qt_meta_tag_ZN23FloatingWindowInterfaceE_t {};
} // unnamed namespace

template <> constexpr inline auto FloatingWindowInterface::qt_create_metaobjectdata<qt_meta_tag_ZN23FloatingWindowInterfaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "FloatingWindowInterface",
        "QML.Element",
        "FloatingWindow",
        "minimumSizeChanged",
        "",
        "maximumSizeChanged",
        "titleChanged",
        "minimizedChanged",
        "maximizedChanged",
        "fullscreenChanged",
        "parentWindowChanged",
        "onWindowConnected",
        "onWindowStateChanged",
        "startSystemMove",
        "startSystemResize",
        "Qt::Edges",
        "edges",
        "title",
        "minimumSize",
        "QSize",
        "maximumSize",
        "minimized",
        "maximized",
        "fullscreen",
        "parentWindow"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'minimumSizeChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'maximumSizeChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'titleChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'minimizedChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'maximizedChanged'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'fullscreenChanged'
        QtMocHelpers::SignalData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'parentWindowChanged'
        QtMocHelpers::SignalData<void()>(10, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onWindowConnected'
        QtMocHelpers::SlotData<void()>(11, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onWindowStateChanged'
        QtMocHelpers::SlotData<void()>(12, 4, QMC::AccessPrivate, QMetaType::Void),
        // Method 'startSystemMove'
        QtMocHelpers::MethodData<bool() const>(13, 4, QMC::AccessPublic, QMetaType::Bool),
        // Method 'startSystemResize'
        QtMocHelpers::MethodData<bool(Qt::Edges) const>(14, 4, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 15, 16 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'title'
        QtMocHelpers::PropertyData<QString>(17, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 2),
        // property 'minimumSize'
        QtMocHelpers::PropertyData<QSize>(18, 0x80000000 | 19, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::Bindable, 0),
        // property 'maximumSize'
        QtMocHelpers::PropertyData<QSize>(20, 0x80000000 | 19, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::Bindable, 1),
        // property 'minimized'
        QtMocHelpers::PropertyData<bool>(21, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'maximized'
        QtMocHelpers::PropertyData<bool>(22, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'fullscreen'
        QtMocHelpers::PropertyData<bool>(23, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'parentWindow'
        QtMocHelpers::PropertyData<QObject*>(24, QMetaType::QObjectStar, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<FloatingWindowInterface, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject FloatingWindowInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<WindowInterface::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23FloatingWindowInterfaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23FloatingWindowInterfaceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN23FloatingWindowInterfaceE_t>.metaTypes,
    nullptr
} };

void FloatingWindowInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<FloatingWindowInterface *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->minimumSizeChanged(); break;
        case 1: _t->maximumSizeChanged(); break;
        case 2: _t->titleChanged(); break;
        case 3: _t->minimizedChanged(); break;
        case 4: _t->maximizedChanged(); break;
        case 5: _t->fullscreenChanged(); break;
        case 6: _t->parentWindowChanged(); break;
        case 7: _t->onWindowConnected(); break;
        case 8: _t->onWindowStateChanged(); break;
        case 9: { bool _r = _t->startSystemMove();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->startSystemResize((*reinterpret_cast<std::add_pointer_t<Qt::Edges>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (FloatingWindowInterface::*)()>(_a, &FloatingWindowInterface::minimumSizeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (FloatingWindowInterface::*)()>(_a, &FloatingWindowInterface::maximumSizeChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (FloatingWindowInterface::*)()>(_a, &FloatingWindowInterface::titleChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (FloatingWindowInterface::*)()>(_a, &FloatingWindowInterface::minimizedChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (FloatingWindowInterface::*)()>(_a, &FloatingWindowInterface::maximizedChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (FloatingWindowInterface::*)()>(_a, &FloatingWindowInterface::fullscreenChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (FloatingWindowInterface::*)()>(_a, &FloatingWindowInterface::parentWindowChanged, 6))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->bindableTitle().value(); break;
        case 1: *reinterpret_cast<QSize*>(_v) = _t->bindableMinimumSize().value(); break;
        case 2: *reinterpret_cast<QSize*>(_v) = _t->bindableMaximumSize().value(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->isMinimized(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isMaximized(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->isFullscreen(); break;
        case 6: *reinterpret_cast<QObject**>(_v) = _t->parentWindow(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: {
            _t->bindableTitle().setValue(*reinterpret_cast<QString*>(_v));
            break;
        }
        case 1: {
            _t->bindableMinimumSize().setValue(*reinterpret_cast<QSize*>(_v));
            break;
        }
        case 2: {
            _t->bindableMaximumSize().setValue(*reinterpret_cast<QSize*>(_v));
            break;
        }
        case 3: _t->setMinimized(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setMaximized(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setFullscreen(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setParentWindow(*reinterpret_cast<QObject**>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableTitle(); break;
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableMinimumSize(); break;
        case 2: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableMaximumSize(); break;
        default: break;
        }
    }
}

const QMetaObject *FloatingWindowInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FloatingWindowInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23FloatingWindowInterfaceE_t>.strings))
        return static_cast<void*>(this);
    return WindowInterface::qt_metacast(_clname);
}

int FloatingWindowInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WindowInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
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
void FloatingWindowInterface::minimumSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FloatingWindowInterface::maximumSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FloatingWindowInterface::titleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FloatingWindowInterface::minimizedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void FloatingWindowInterface::maximizedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void FloatingWindowInterface::fullscreenChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void FloatingWindowInterface::parentWindowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
