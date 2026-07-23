/****************************************************************************
** Meta object code from reading C++ file 'windowset.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/windowmanager/windowset.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windowset.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs2wm9WindowsetE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::wm::Windowset::qt_create_metaobjectdata<qt_meta_tag_ZN2qs2wm9WindowsetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::wm::Windowset",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "",
        "idChanged",
        "nameChanged",
        "coordinatesChanged",
        "activeChanged",
        "projectionChanged",
        "shouldDisplayChanged",
        "urgentChanged",
        "canActivateChanged",
        "canDeactivateChanged",
        "canRemoveChanged",
        "canSetProjectionChanged",
        "activate",
        "deactivate",
        "remove",
        "setProjection",
        "WindowsetProjection*",
        "projection",
        "id",
        "name",
        "coordinates",
        "QList<qint32>",
        "active",
        "shouldDisplay",
        "urgent",
        "canActivate",
        "canDeactivate",
        "canRemove",
        "canSetProjection"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'idChanged'
        QtMocHelpers::SignalData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'nameChanged'
        QtMocHelpers::SignalData<void()>(8, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'coordinatesChanged'
        QtMocHelpers::SignalData<void()>(9, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'activeChanged'
        QtMocHelpers::SignalData<void()>(10, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'projectionChanged'
        QtMocHelpers::SignalData<void()>(11, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'shouldDisplayChanged'
        QtMocHelpers::SignalData<void()>(12, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'urgentChanged'
        QtMocHelpers::SignalData<void()>(13, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'canActivateChanged'
        QtMocHelpers::SignalData<void()>(14, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'canDeactivateChanged'
        QtMocHelpers::SignalData<void()>(15, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'canRemoveChanged'
        QtMocHelpers::SignalData<void()>(16, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'canSetProjectionChanged'
        QtMocHelpers::SignalData<void()>(17, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'activate'
        QtMocHelpers::MethodData<void()>(18, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'deactivate'
        QtMocHelpers::MethodData<void()>(19, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'remove'
        QtMocHelpers::MethodData<void()>(20, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'setProjection'
        QtMocHelpers::MethodData<void(WindowsetProjection *)>(21, 6, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 22, 23 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'id'
        QtMocHelpers::PropertyData<QString>(24, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Bindable, 0),
        // property 'name'
        QtMocHelpers::PropertyData<QString>(25, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Bindable, 1),
        // property 'coordinates'
        QtMocHelpers::PropertyData<QList<qint32>>(26, 0x80000000 | 27, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Bindable, 2),
        // property 'active'
        QtMocHelpers::PropertyData<bool>(28, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 3),
        // property 'projection'
        QtMocHelpers::PropertyData<WindowsetProjection*>(23, 0x80000000 | 22, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Bindable, 4),
        // property 'shouldDisplay'
        QtMocHelpers::PropertyData<bool>(29, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 5),
        // property 'urgent'
        QtMocHelpers::PropertyData<bool>(30, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 6),
        // property 'canActivate'
        QtMocHelpers::PropertyData<bool>(31, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 7),
        // property 'canDeactivate'
        QtMocHelpers::PropertyData<bool>(32, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 8),
        // property 'canRemove'
        QtMocHelpers::PropertyData<bool>(33, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 9),
        // property 'canSetProjection'
        QtMocHelpers::PropertyData<bool>(34, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 10),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<Windowset, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::wm::Windowset::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2wm9WindowsetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2wm9WindowsetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs2wm9WindowsetE_t>.metaTypes,
    nullptr
} };

void qs::wm::Windowset::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Windowset *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->idChanged(); break;
        case 1: _t->nameChanged(); break;
        case 2: _t->coordinatesChanged(); break;
        case 3: _t->activeChanged(); break;
        case 4: _t->projectionChanged(); break;
        case 5: _t->shouldDisplayChanged(); break;
        case 6: _t->urgentChanged(); break;
        case 7: _t->canActivateChanged(); break;
        case 8: _t->canDeactivateChanged(); break;
        case 9: _t->canRemoveChanged(); break;
        case 10: _t->canSetProjectionChanged(); break;
        case 11: _t->activate(); break;
        case 12: _t->deactivate(); break;
        case 13: _t->remove(); break;
        case 14: _t->setProjection((*reinterpret_cast<std::add_pointer_t<WindowsetProjection*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< WindowsetProjection* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Windowset::*)()>(_a, &Windowset::idChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Windowset::*)()>(_a, &Windowset::nameChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Windowset::*)()>(_a, &Windowset::coordinatesChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Windowset::*)()>(_a, &Windowset::activeChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Windowset::*)()>(_a, &Windowset::projectionChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (Windowset::*)()>(_a, &Windowset::shouldDisplayChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (Windowset::*)()>(_a, &Windowset::urgentChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (Windowset::*)()>(_a, &Windowset::canActivateChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (Windowset::*)()>(_a, &Windowset::canDeactivateChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (Windowset::*)()>(_a, &Windowset::canRemoveChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (Windowset::*)()>(_a, &Windowset::canSetProjectionChanged, 10))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<qint32> >(); break;
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WindowsetProjection* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->bindableId().value(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->bindableName().value(); break;
        case 2: *reinterpret_cast<QList<qint32>*>(_v) = _t->bindableCoordinates().value(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->bindableActive().value(); break;
        case 4: *reinterpret_cast<WindowsetProjection**>(_v) = _t->bindableProjection().value(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->bindableShouldDisplay().value(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->bindableUrgent().value(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->bindableCanActivate().value(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->bindableCanDeactivate().value(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->bindableCanRemove().value(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->bindableCanSetProjection().value(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableId(); break;
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableName(); break;
        case 2: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCoordinates(); break;
        case 3: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableActive(); break;
        case 4: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableProjection(); break;
        case 5: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableShouldDisplay(); break;
        case 6: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableUrgent(); break;
        case 7: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCanActivate(); break;
        case 8: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCanDeactivate(); break;
        case 9: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCanRemove(); break;
        case 10: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCanSetProjection(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::wm::Windowset::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::wm::Windowset::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2wm9WindowsetE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::wm::Windowset::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void qs::wm::Windowset::idChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::wm::Windowset::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::wm::Windowset::coordinatesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::wm::Windowset::activeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qs::wm::Windowset::projectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void qs::wm::Windowset::shouldDisplayChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void qs::wm::Windowset::urgentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void qs::wm::Windowset::canActivateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void qs::wm::Windowset::canDeactivateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void qs::wm::Windowset::canRemoveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void qs::wm::Windowset::canSetProjectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs2wm19WindowsetProjectionE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::wm::WindowsetProjection::qt_create_metaobjectdata<qt_meta_tag_ZN2qs2wm19WindowsetProjectionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::wm::WindowsetProjection",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "",
        "screensChanged",
        "windowsetsChanged",
        "screens",
        "QList<QuickshellScreenInfo*>",
        "windowsets",
        "QList<Windowset*>"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'screensChanged'
        QtMocHelpers::SignalData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'windowsetsChanged'
        QtMocHelpers::SignalData<void()>(8, 6, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'screens'
        QtMocHelpers::PropertyData<QList<QuickshellScreenInfo*>>(9, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
        // property 'windowsets'
        QtMocHelpers::PropertyData<QList<Windowset*>>(11, 0x80000000 | 12, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Bindable, 1),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<WindowsetProjection, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::wm::WindowsetProjection::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2wm19WindowsetProjectionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2wm19WindowsetProjectionE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs2wm19WindowsetProjectionE_t>.metaTypes,
    nullptr
} };

void qs::wm::WindowsetProjection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<WindowsetProjection *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->screensChanged(); break;
        case 1: _t->windowsetsChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (WindowsetProjection::*)()>(_a, &WindowsetProjection::screensChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (WindowsetProjection::*)()>(_a, &WindowsetProjection::windowsetsChanged, 1))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Windowset*> >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QList<QuickshellScreenInfo*>*>(_v) = _t->screens(); break;
        case 1: *reinterpret_cast<QList<Windowset*>*>(_v) = _t->bindableWindowsets().value(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableWindowsets(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::wm::WindowsetProjection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::wm::WindowsetProjection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2wm19WindowsetProjectionE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::wm::WindowsetProjection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void qs::wm::WindowsetProjection::screensChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::wm::WindowsetProjection::windowsetsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
