/****************************************************************************
** Meta object code from reading C++ file 'windowmanager.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/windowmanager/windowmanager.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windowmanager.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs2wm13WindowManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::wm::WindowManager::qt_create_metaobjectdata<qt_meta_tag_ZN2qs2wm13WindowManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::wm::WindowManager",
        "windowsetsChanged",
        "",
        "windowsetProjectionsChanged",
        "screenProjection",
        "ScreenProjection*",
        "QuickshellScreenInfo*",
        "screen"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'windowsetsChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'windowsetProjectionsChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'screenProjection'
        QtMocHelpers::MethodData<ScreenProjection *(QuickshellScreenInfo *)>(4, 2, QMC::AccessPublic, 0x80000000 | 5, {{
            { 0x80000000 | 6, 7 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<WindowManager, qt_meta_tag_ZN2qs2wm13WindowManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject qs::wm::WindowManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2wm13WindowManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2wm13WindowManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs2wm13WindowManagerE_t>.metaTypes,
    nullptr
} };

void qs::wm::WindowManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<WindowManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->windowsetsChanged(); break;
        case 1: _t->windowsetProjectionsChanged(); break;
        case 2: { ScreenProjection* _r = _t->screenProjection((*reinterpret_cast<std::add_pointer_t<QuickshellScreenInfo*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<ScreenProjection**>(_a[0]) = std::move(_r); }  break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QuickshellScreenInfo* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (WindowManager::*)()>(_a, &WindowManager::windowsetsChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowManager::*)()>(_a, &WindowManager::windowsetProjectionsChanged, 1))
            return;
    }
}

const QMetaObject *qs::wm::WindowManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::wm::WindowManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2wm13WindowManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::wm::WindowManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void qs::wm::WindowManager::windowsetsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::wm::WindowManager::windowsetProjectionsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs2wm16WindowManagerQmlE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::wm::WindowManagerQml::qt_create_metaobjectdata<qt_meta_tag_ZN2qs2wm16WindowManagerQmlE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::wm::WindowManagerQml",
        "QML.Element",
        "WindowManager",
        "QML.Singleton",
        "true",
        "screenProjection",
        "ScreenProjection*",
        "",
        "QuickshellScreenInfo*",
        "screen",
        "windowsets",
        "QList<Windowset*>",
        "windowsetProjections",
        "QList<WindowsetProjection*>"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'screenProjection'
        QtMocHelpers::MethodData<ScreenProjection *(QuickshellScreenInfo *)>(5, 7, QMC::AccessPublic, 0x80000000 | 6, {{
            { 0x80000000 | 8, 9 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'windowsets'
        QtMocHelpers::PropertyData<QList<Windowset*>>(10, 0x80000000 | 11, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Bindable),
        // property 'windowsetProjections'
        QtMocHelpers::PropertyData<QList<WindowsetProjection*>>(12, 0x80000000 | 13, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Bindable),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<WindowManagerQml, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::wm::WindowManagerQml::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2wm16WindowManagerQmlE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2wm16WindowManagerQmlE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs2wm16WindowManagerQmlE_t>.metaTypes,
    nullptr
} };

void qs::wm::WindowManagerQml::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<WindowManagerQml *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { ScreenProjection* _r = _t->screenProjection((*reinterpret_cast<std::add_pointer_t<QuickshellScreenInfo*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<ScreenProjection**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QuickshellScreenInfo* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Windowset*> >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<WindowsetProjection*> >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QList<Windowset*>*>(_v) = _t->bindableWindowsets().value(); break;
        case 1: *reinterpret_cast<QList<WindowsetProjection*>*>(_v) = _t->bindableWindowsetProjections().value(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableWindowsets(); break;
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableWindowsetProjections(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::wm::WindowManagerQml::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::wm::WindowManagerQml::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2wm16WindowManagerQmlE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::wm::WindowManagerQml::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
