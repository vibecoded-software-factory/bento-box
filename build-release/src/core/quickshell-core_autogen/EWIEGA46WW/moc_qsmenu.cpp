/****************************************************************************
** Meta object code from reading C++ file 'qsmenu.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/qsmenu.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsmenu.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs4menu16QsMenuButtonTypeE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::menu::QsMenuButtonType::qt_create_metaobjectdata<qt_meta_tag_ZN2qs4menu16QsMenuButtonTypeE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::menu::QsMenuButtonType",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "toString",
        "",
        "qs::menu::QsMenuButtonType::Enum",
        "value",
        "Enum",
        "None",
        "CheckBox",
        "RadioButton"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'toString'
        QtMocHelpers::MethodData<QString(qs::menu::QsMenuButtonType::Enum)>(5, 6, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 7, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<enum Enum>(9, 9, QMC::EnumFlags{}).add({
            {   10, Enum::None },
            {   11, Enum::CheckBox },
            {   12, Enum::RadioButton },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<QsMenuButtonType, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::menu::QsMenuButtonType::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs4menu16QsMenuButtonTypeE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs4menu16QsMenuButtonTypeE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs4menu16QsMenuButtonTypeE_t>.metaTypes,
    nullptr
} };

void qs::menu::QsMenuButtonType::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QsMenuButtonType *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = _t->toString((*reinterpret_cast<std::add_pointer_t<qs::menu::QsMenuButtonType::Enum>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *qs::menu::QsMenuButtonType::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::menu::QsMenuButtonType::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs4menu16QsMenuButtonTypeE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::menu::QsMenuButtonType::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN2qs4menu12QsMenuHandleE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::menu::QsMenuHandle::qt_create_metaobjectdata<qt_meta_tag_ZN2qs4menu12QsMenuHandleE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::menu::QsMenuHandle",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "",
        "menuChanged"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'menuChanged'
        QtMocHelpers::SignalData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<QsMenuHandle, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::menu::QsMenuHandle::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs4menu12QsMenuHandleE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs4menu12QsMenuHandleE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs4menu12QsMenuHandleE_t>.metaTypes,
    nullptr
} };

void qs::menu::QsMenuHandle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QsMenuHandle *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->menuChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QsMenuHandle::*)()>(_a, &QsMenuHandle::menuChanged, 0))
            return;
    }
}

const QMetaObject *qs::menu::QsMenuHandle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::menu::QsMenuHandle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs4menu12QsMenuHandleE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::menu::QsMenuHandle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void qs::menu::QsMenuHandle::menuChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs4menu11QsMenuEntryE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::menu::QsMenuEntry::qt_create_metaobjectdata<qt_meta_tag_ZN2qs4menu11QsMenuEntryE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::menu::QsMenuEntry",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "QsMenuEntry cannot be directly created",
        "triggered",
        "",
        "opened",
        "closed",
        "isSeparatorChanged",
        "enabledChanged",
        "textChanged",
        "iconChanged",
        "buttonTypeChanged",
        "checkStateChanged",
        "hasChildrenChanged",
        "display",
        "parentWindow",
        "relativeX",
        "relativeY",
        "isSeparator",
        "enabled",
        "text",
        "icon",
        "buttonType",
        "qs::menu::QsMenuButtonType::Enum",
        "checkState",
        "Qt::CheckState",
        "hasChildren"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'triggered'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'opened'
        QtMocHelpers::SignalData<void()>(9, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'closed'
        QtMocHelpers::SignalData<void()>(10, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isSeparatorChanged'
        QtMocHelpers::SignalData<void()>(11, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'enabledChanged'
        QtMocHelpers::SignalData<void()>(12, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'textChanged'
        QtMocHelpers::SignalData<void()>(13, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'iconChanged'
        QtMocHelpers::SignalData<void()>(14, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'buttonTypeChanged'
        QtMocHelpers::SignalData<void()>(15, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'checkStateChanged'
        QtMocHelpers::SignalData<void()>(16, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'hasChildrenChanged'
        QtMocHelpers::SignalData<void()>(17, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'display'
        QtMocHelpers::MethodData<void(QObject *, qint32, qint32)>(18, 8, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 19 }, { QMetaType::Int, 20 }, { QMetaType::Int, 21 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'isSeparator'
        QtMocHelpers::PropertyData<bool>(22, QMetaType::Bool, QMC::DefaultPropertyFlags, 3),
        // property 'enabled'
        QtMocHelpers::PropertyData<bool>(23, QMetaType::Bool, QMC::DefaultPropertyFlags, 4),
        // property 'text'
        QtMocHelpers::PropertyData<QString>(24, QMetaType::QString, QMC::DefaultPropertyFlags, 5),
        // property 'icon'
        QtMocHelpers::PropertyData<QString>(25, QMetaType::QString, QMC::DefaultPropertyFlags, 6),
        // property 'buttonType'
        QtMocHelpers::PropertyData<qs::menu::QsMenuButtonType::Enum>(26, 0x80000000 | 27, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 7),
        // property 'checkState'
        QtMocHelpers::PropertyData<Qt::CheckState>(28, 0x80000000 | 29, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 8),
        // property 'hasChildren'
        QtMocHelpers::PropertyData<bool>(30, QMetaType::Bool, QMC::DefaultPropertyFlags, 9),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<QsMenuEntry, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN2qs4menu11QsMenuEntryE[] = {
    QMetaObject::SuperData::link<qs::menu::QsMenuButtonType::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject qs::menu::QsMenuEntry::staticMetaObject = { {
    QMetaObject::SuperData::link<QsMenuHandle::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs4menu11QsMenuEntryE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs4menu11QsMenuEntryE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN2qs4menu11QsMenuEntryE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs4menu11QsMenuEntryE_t>.metaTypes,
    nullptr
} };

void qs::menu::QsMenuEntry::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QsMenuEntry *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->triggered(); break;
        case 1: _t->opened(); break;
        case 2: _t->closed(); break;
        case 3: _t->isSeparatorChanged(); break;
        case 4: _t->enabledChanged(); break;
        case 5: _t->textChanged(); break;
        case 6: _t->iconChanged(); break;
        case 7: _t->buttonTypeChanged(); break;
        case 8: _t->checkStateChanged(); break;
        case 9: _t->hasChildrenChanged(); break;
        case 10: _t->display((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qint32>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<qint32>>(_a[3]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QsMenuEntry::*)()>(_a, &QsMenuEntry::triggered, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QsMenuEntry::*)()>(_a, &QsMenuEntry::opened, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QsMenuEntry::*)()>(_a, &QsMenuEntry::closed, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QsMenuEntry::*)()>(_a, &QsMenuEntry::isSeparatorChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QsMenuEntry::*)()>(_a, &QsMenuEntry::enabledChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QsMenuEntry::*)()>(_a, &QsMenuEntry::textChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QsMenuEntry::*)()>(_a, &QsMenuEntry::iconChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QsMenuEntry::*)()>(_a, &QsMenuEntry::buttonTypeChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QsMenuEntry::*)()>(_a, &QsMenuEntry::checkStateChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QsMenuEntry::*)()>(_a, &QsMenuEntry::hasChildrenChanged, 9))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isSeparator(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->enabled(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->text(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->icon(); break;
        case 4: *reinterpret_cast<qs::menu::QsMenuButtonType::Enum*>(_v) = _t->buttonType(); break;
        case 5: *reinterpret_cast<Qt::CheckState*>(_v) = _t->checkState(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->hasChildren(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::menu::QsMenuEntry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::menu::QsMenuEntry::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs4menu11QsMenuEntryE_t>.strings))
        return static_cast<void*>(this);
    return QsMenuHandle::qt_metacast(_clname);
}

int qs::menu::QsMenuEntry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QsMenuHandle::qt_metacall(_c, _id, _a);
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
void qs::menu::QsMenuEntry::triggered()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::menu::QsMenuEntry::opened()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::menu::QsMenuEntry::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::menu::QsMenuEntry::isSeparatorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qs::menu::QsMenuEntry::enabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void qs::menu::QsMenuEntry::textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void qs::menu::QsMenuEntry::iconChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void qs::menu::QsMenuEntry::buttonTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void qs::menu::QsMenuEntry::checkStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void qs::menu::QsMenuEntry::hasChildrenChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs4menu12QsMenuOpenerE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::menu::QsMenuOpener::qt_create_metaobjectdata<qt_meta_tag_ZN2qs4menu12QsMenuOpenerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::menu::QsMenuOpener",
        "QML.Element",
        "auto",
        "menuChanged",
        "",
        "childrenChanged",
        "onMenuDestroyed",
        "menu",
        "qs::menu::QsMenuHandle*",
        "children",
        "UntypedObjectModel*"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'menuChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'childrenChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onMenuDestroyed'
        QtMocHelpers::SlotData<void()>(6, 4, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'menu'
        QtMocHelpers::PropertyData<qs::menu::QsMenuHandle*>(7, 0x80000000 | 8, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 0),
        // property 'children'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(9, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 1),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<QsMenuOpener, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::menu::QsMenuOpener::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs4menu12QsMenuOpenerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs4menu12QsMenuOpenerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs4menu12QsMenuOpenerE_t>.metaTypes,
    nullptr
} };

void qs::menu::QsMenuOpener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QsMenuOpener *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->menuChanged(); break;
        case 1: _t->childrenChanged(); break;
        case 2: _t->onMenuDestroyed(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QsMenuOpener::*)()>(_a, &QsMenuOpener::menuChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QsMenuOpener::*)()>(_a, &QsMenuOpener::childrenChanged, 1))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< UntypedObjectModel* >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qs::menu::QsMenuHandle* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qs::menu::QsMenuHandle**>(_v) = _t->menu(); break;
        case 1: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->children(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMenu(*reinterpret_cast<qs::menu::QsMenuHandle**>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::menu::QsMenuOpener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::menu::QsMenuOpener::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs4menu12QsMenuOpenerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::menu::QsMenuOpener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
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
void qs::menu::QsMenuOpener::menuChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::menu::QsMenuOpener::childrenChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
