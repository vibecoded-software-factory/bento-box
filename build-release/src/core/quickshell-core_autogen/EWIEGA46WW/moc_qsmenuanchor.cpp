/****************************************************************************
** Meta object code from reading C++ file 'qsmenuanchor.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/qsmenuanchor.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsmenuanchor.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs4menu12QsMenuAnchorE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::menu::QsMenuAnchor::qt_create_metaobjectdata<qt_meta_tag_ZN2qs4menu12QsMenuAnchorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::menu::QsMenuAnchor",
        "QML.Element",
        "auto",
        "opened",
        "",
        "closed",
        "menuChanged",
        "visibleChanged",
        "onMenuChanged",
        "onMenuDestroyed",
        "open",
        "close",
        "anchor",
        "PopupAnchor*",
        "menu",
        "qs::menu::QsMenuHandle*",
        "visible"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'opened'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'closed'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'menuChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'visibleChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onMenuChanged'
        QtMocHelpers::SlotData<void()>(8, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onMenuDestroyed'
        QtMocHelpers::SlotData<void()>(9, 4, QMC::AccessPrivate, QMetaType::Void),
        // Method 'open'
        QtMocHelpers::MethodData<void()>(10, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'close'
        QtMocHelpers::MethodData<void()>(11, 4, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'anchor'
        QtMocHelpers::PropertyData<PopupAnchor*>(12, 0x80000000 | 13, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'menu'
        QtMocHelpers::PropertyData<qs::menu::QsMenuHandle*>(14, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 2),
        // property 'visible'
        QtMocHelpers::PropertyData<bool>(16, QMetaType::Bool, QMC::DefaultPropertyFlags, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<QsMenuAnchor, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::menu::QsMenuAnchor::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs4menu12QsMenuAnchorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs4menu12QsMenuAnchorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs4menu12QsMenuAnchorE_t>.metaTypes,
    nullptr
} };

void qs::menu::QsMenuAnchor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QsMenuAnchor *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->opened(); break;
        case 1: _t->closed(); break;
        case 2: _t->menuChanged(); break;
        case 3: _t->visibleChanged(); break;
        case 4: _t->onMenuChanged(); break;
        case 5: _t->onMenuDestroyed(); break;
        case 6: _t->open(); break;
        case 7: _t->close(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QsMenuAnchor::*)()>(_a, &QsMenuAnchor::opened, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QsMenuAnchor::*)()>(_a, &QsMenuAnchor::closed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QsMenuAnchor::*)()>(_a, &QsMenuAnchor::menuChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QsMenuAnchor::*)()>(_a, &QsMenuAnchor::visibleChanged, 3))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PopupAnchor* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qs::menu::QsMenuHandle* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<PopupAnchor**>(_v) = _t->anchor(); break;
        case 1: *reinterpret_cast<qs::menu::QsMenuHandle**>(_v) = _t->menu(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isVisible(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setMenu(*reinterpret_cast<qs::menu::QsMenuHandle**>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::menu::QsMenuAnchor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::menu::QsMenuAnchor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs4menu12QsMenuAnchorE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::menu::QsMenuAnchor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void qs::menu::QsMenuAnchor::opened()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::menu::QsMenuAnchor::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::menu::QsMenuAnchor::menuChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::menu::QsMenuAnchor::visibleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
