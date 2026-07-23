/****************************************************************************
** Meta object code from reading C++ file 'desktopentry.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/desktopentry.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'desktopentry.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12DesktopEntryE_t {};
} // unnamed namespace

template <> constexpr inline auto DesktopEntry::qt_create_metaobjectdata<qt_meta_tag_ZN12DesktopEntryE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "DesktopEntry",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "DesktopEntry instances must be retrieved from DesktopEntries",
        "nameChanged",
        "",
        "genericNameChanged",
        "startupClassChanged",
        "noDisplayChanged",
        "commentChanged",
        "iconChanged",
        "execStringChanged",
        "commandChanged",
        "workingDirectoryChanged",
        "runInTerminalChanged",
        "categoriesChanged",
        "keywordsChanged",
        "execute",
        "id",
        "name",
        "genericName",
        "startupClass",
        "noDisplay",
        "comment",
        "icon",
        "execString",
        "command",
        "workingDirectory",
        "runInTerminal",
        "categories",
        "keywords",
        "actions",
        "QList<DesktopAction*>"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'nameChanged'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'genericNameChanged'
        QtMocHelpers::SignalData<void()>(9, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'startupClassChanged'
        QtMocHelpers::SignalData<void()>(10, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'noDisplayChanged'
        QtMocHelpers::SignalData<void()>(11, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'commentChanged'
        QtMocHelpers::SignalData<void()>(12, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'iconChanged'
        QtMocHelpers::SignalData<void()>(13, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'execStringChanged'
        QtMocHelpers::SignalData<void()>(14, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'commandChanged'
        QtMocHelpers::SignalData<void()>(15, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'workingDirectoryChanged'
        QtMocHelpers::SignalData<void()>(16, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'runInTerminalChanged'
        QtMocHelpers::SignalData<void()>(17, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'categoriesChanged'
        QtMocHelpers::SignalData<void()>(18, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'keywordsChanged'
        QtMocHelpers::SignalData<void()>(19, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'execute'
        QtMocHelpers::MethodData<void() const>(20, 8, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'id'
        QtMocHelpers::PropertyData<QString>(21, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'name'
        QtMocHelpers::PropertyData<QString>(22, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 0),
        // property 'genericName'
        QtMocHelpers::PropertyData<QString>(23, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 1),
        // property 'startupClass'
        QtMocHelpers::PropertyData<QString>(24, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 2),
        // property 'noDisplay'
        QtMocHelpers::PropertyData<bool>(25, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 3),
        // property 'comment'
        QtMocHelpers::PropertyData<QString>(26, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 4),
        // property 'icon'
        QtMocHelpers::PropertyData<QString>(27, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 5),
        // property 'execString'
        QtMocHelpers::PropertyData<QString>(28, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 6),
        // property 'command'
        QtMocHelpers::PropertyData<QList<QString>>(29, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 7),
        // property 'workingDirectory'
        QtMocHelpers::PropertyData<QString>(30, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 8),
        // property 'runInTerminal'
        QtMocHelpers::PropertyData<bool>(31, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 9),
        // property 'categories'
        QtMocHelpers::PropertyData<QList<QString>>(32, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 10),
        // property 'keywords'
        QtMocHelpers::PropertyData<QList<QString>>(33, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 11),
        // property 'actions'
        QtMocHelpers::PropertyData<QList<DesktopAction*>>(34, 0x80000000 | 35, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<DesktopEntry, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject DesktopEntry::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12DesktopEntryE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12DesktopEntryE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12DesktopEntryE_t>.metaTypes,
    nullptr
} };

void DesktopEntry::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<DesktopEntry *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->nameChanged(); break;
        case 1: _t->genericNameChanged(); break;
        case 2: _t->startupClassChanged(); break;
        case 3: _t->noDisplayChanged(); break;
        case 4: _t->commentChanged(); break;
        case 5: _t->iconChanged(); break;
        case 6: _t->execStringChanged(); break;
        case 7: _t->commandChanged(); break;
        case 8: _t->workingDirectoryChanged(); break;
        case 9: _t->runInTerminalChanged(); break;
        case 10: _t->categoriesChanged(); break;
        case 11: _t->keywordsChanged(); break;
        case 12: _t->execute(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (DesktopEntry::*)()>(_a, &DesktopEntry::nameChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (DesktopEntry::*)()>(_a, &DesktopEntry::genericNameChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (DesktopEntry::*)()>(_a, &DesktopEntry::startupClassChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (DesktopEntry::*)()>(_a, &DesktopEntry::noDisplayChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (DesktopEntry::*)()>(_a, &DesktopEntry::commentChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (DesktopEntry::*)()>(_a, &DesktopEntry::iconChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (DesktopEntry::*)()>(_a, &DesktopEntry::execStringChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (DesktopEntry::*)()>(_a, &DesktopEntry::commandChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (DesktopEntry::*)()>(_a, &DesktopEntry::workingDirectoryChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (DesktopEntry::*)()>(_a, &DesktopEntry::runInTerminalChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (DesktopEntry::*)()>(_a, &DesktopEntry::categoriesChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (DesktopEntry::*)()>(_a, &DesktopEntry::keywordsChanged, 11))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 13:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<DesktopAction*> >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->mId; break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->bindableName().value(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->bindableGenericName().value(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->bindableStartupClass().value(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->bindableNoDisplay().value(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->bindableComment().value(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->bindableIcon().value(); break;
        case 7: *reinterpret_cast<QString*>(_v) = _t->bindableExecString().value(); break;
        case 8: *reinterpret_cast<QList<QString>*>(_v) = _t->bindableCommand().value(); break;
        case 9: *reinterpret_cast<QString*>(_v) = _t->bindableWorkingDirectory().value(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->bindableRunInTerminal().value(); break;
        case 11: *reinterpret_cast<QList<QString>*>(_v) = _t->bindableCategories().value(); break;
        case 12: *reinterpret_cast<QList<QString>*>(_v) = _t->bindableKeywords().value(); break;
        case 13: *reinterpret_cast<QList<DesktopAction*>*>(_v) = _t->actions(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: {
            _t->bindableName().setValue(*reinterpret_cast<QString*>(_v));
            break;
        }
        case 2: {
            _t->bindableGenericName().setValue(*reinterpret_cast<QString*>(_v));
            break;
        }
        case 3: {
            _t->bindableStartupClass().setValue(*reinterpret_cast<QString*>(_v));
            break;
        }
        case 4: {
            _t->bindableNoDisplay().setValue(*reinterpret_cast<bool*>(_v));
            break;
        }
        case 5: {
            _t->bindableComment().setValue(*reinterpret_cast<QString*>(_v));
            break;
        }
        case 6: {
            _t->bindableIcon().setValue(*reinterpret_cast<QString*>(_v));
            break;
        }
        case 7: {
            _t->bindableExecString().setValue(*reinterpret_cast<QString*>(_v));
            break;
        }
        case 8: {
            _t->bindableCommand().setValue(*reinterpret_cast<QList<QString>*>(_v));
            break;
        }
        case 9: {
            _t->bindableWorkingDirectory().setValue(*reinterpret_cast<QString*>(_v));
            break;
        }
        case 10: {
            _t->bindableRunInTerminal().setValue(*reinterpret_cast<bool*>(_v));
            break;
        }
        case 11: {
            _t->bindableCategories().setValue(*reinterpret_cast<QList<QString>*>(_v));
            break;
        }
        case 12: {
            _t->bindableKeywords().setValue(*reinterpret_cast<QList<QString>*>(_v));
            break;
        }
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableName(); break;
        case 2: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableGenericName(); break;
        case 3: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableStartupClass(); break;
        case 4: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableNoDisplay(); break;
        case 5: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableComment(); break;
        case 6: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableIcon(); break;
        case 7: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableExecString(); break;
        case 8: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCommand(); break;
        case 9: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableWorkingDirectory(); break;
        case 10: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableRunInTerminal(); break;
        case 11: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCategories(); break;
        case 12: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableKeywords(); break;
        default: break;
        }
    }
}

const QMetaObject *DesktopEntry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DesktopEntry::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12DesktopEntryE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DesktopEntry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void DesktopEntry::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DesktopEntry::genericNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DesktopEntry::startupClassChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DesktopEntry::noDisplayChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void DesktopEntry::commentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void DesktopEntry::iconChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void DesktopEntry::execStringChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void DesktopEntry::commandChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void DesktopEntry::workingDirectoryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void DesktopEntry::runInTerminalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void DesktopEntry::categoriesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void DesktopEntry::keywordsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}
namespace {
struct qt_meta_tag_ZN13DesktopActionE_t {};
} // unnamed namespace

template <> constexpr inline auto DesktopAction::qt_create_metaobjectdata<qt_meta_tag_ZN13DesktopActionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "DesktopAction",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "DesktopAction instances must be retrieved from a DesktopEntry",
        "nameChanged",
        "",
        "iconChanged",
        "execStringChanged",
        "commandChanged",
        "execute",
        "id",
        "name",
        "icon",
        "execString",
        "command"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'nameChanged'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'iconChanged'
        QtMocHelpers::SignalData<void()>(9, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'execStringChanged'
        QtMocHelpers::SignalData<void()>(10, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'commandChanged'
        QtMocHelpers::SignalData<void()>(11, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'execute'
        QtMocHelpers::MethodData<void() const>(12, 8, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'id'
        QtMocHelpers::PropertyData<QString>(13, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'name'
        QtMocHelpers::PropertyData<QString>(14, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 0),
        // property 'icon'
        QtMocHelpers::PropertyData<QString>(15, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 1),
        // property 'execString'
        QtMocHelpers::PropertyData<QString>(16, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 2),
        // property 'command'
        QtMocHelpers::PropertyData<QList<QString>>(17, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<DesktopAction, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject DesktopAction::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13DesktopActionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13DesktopActionE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13DesktopActionE_t>.metaTypes,
    nullptr
} };

void DesktopAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<DesktopAction *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->nameChanged(); break;
        case 1: _t->iconChanged(); break;
        case 2: _t->execStringChanged(); break;
        case 3: _t->commandChanged(); break;
        case 4: _t->execute(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (DesktopAction::*)()>(_a, &DesktopAction::nameChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (DesktopAction::*)()>(_a, &DesktopAction::iconChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (DesktopAction::*)()>(_a, &DesktopAction::execStringChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (DesktopAction::*)()>(_a, &DesktopAction::commandChanged, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->mId; break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->bindableName().value(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->bindableIcon().value(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->bindableExecString().value(); break;
        case 4: *reinterpret_cast<QList<QString>*>(_v) = _t->bindableCommand().value(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: {
            _t->bindableName().setValue(*reinterpret_cast<QString*>(_v));
            break;
        }
        case 2: {
            _t->bindableIcon().setValue(*reinterpret_cast<QString*>(_v));
            break;
        }
        case 3: {
            _t->bindableExecString().setValue(*reinterpret_cast<QString*>(_v));
            break;
        }
        case 4: {
            _t->bindableCommand().setValue(*reinterpret_cast<QList<QString>*>(_v));
            break;
        }
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableName(); break;
        case 2: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableIcon(); break;
        case 3: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableExecString(); break;
        case 4: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCommand(); break;
        default: break;
        }
    }
}

const QMetaObject *DesktopAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DesktopAction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13DesktopActionE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DesktopAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DesktopAction::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DesktopAction::iconChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DesktopAction::execStringChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DesktopAction::commandChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
namespace {
struct qt_meta_tag_ZN19DesktopEntryManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto DesktopEntryManager::qt_create_metaobjectdata<qt_meta_tag_ZN19DesktopEntryManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "DesktopEntryManager",
        "applicationsChanged",
        "",
        "handleFileChanges",
        "onScanCompleted",
        "QList<ParsedDesktopEntryData>",
        "scanResults"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'applicationsChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'handleFileChanges'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onScanCompleted'
        QtMocHelpers::SlotData<void(const QList<ParsedDesktopEntryData> &)>(4, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<DesktopEntryManager, qt_meta_tag_ZN19DesktopEntryManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject DesktopEntryManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19DesktopEntryManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19DesktopEntryManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19DesktopEntryManagerE_t>.metaTypes,
    nullptr
} };

void DesktopEntryManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<DesktopEntryManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->applicationsChanged(); break;
        case 1: _t->handleFileChanges(); break;
        case 2: _t->onScanCompleted((*reinterpret_cast<std::add_pointer_t<QList<ParsedDesktopEntryData>>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (DesktopEntryManager::*)()>(_a, &DesktopEntryManager::applicationsChanged, 0))
            return;
    }
}

const QMetaObject *DesktopEntryManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DesktopEntryManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19DesktopEntryManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DesktopEntryManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void DesktopEntryManager::applicationsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {
struct qt_meta_tag_ZN14DesktopEntriesE_t {};
} // unnamed namespace

template <> constexpr inline auto DesktopEntries::qt_create_metaobjectdata<qt_meta_tag_ZN14DesktopEntriesE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "DesktopEntries",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "applicationsChanged",
        "",
        "byId",
        "DesktopEntry*",
        "id",
        "heuristicLookup",
        "name",
        "applications",
        "UntypedObjectModel*"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'applicationsChanged'
        QtMocHelpers::SignalData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'byId'
        QtMocHelpers::MethodData<DesktopEntry *(const QString &)>(7, 6, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 9 },
        }}),
        // Method 'heuristicLookup'
        QtMocHelpers::MethodData<DesktopEntry *(const QString &)>(10, 6, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 11 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'applications'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(12, 0x80000000 | 13, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<DesktopEntries, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject DesktopEntries::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14DesktopEntriesE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14DesktopEntriesE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14DesktopEntriesE_t>.metaTypes,
    nullptr
} };

void DesktopEntries::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<DesktopEntries *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->applicationsChanged(); break;
        case 1: { DesktopEntry* _r = _t->byId((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<DesktopEntry**>(_a[0]) = std::move(_r); }  break;
        case 2: { DesktopEntry* _r = _t->heuristicLookup((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<DesktopEntry**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (DesktopEntries::*)()>(_a, &DesktopEntries::applicationsChanged, 0))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< UntypedObjectModel* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->applications(); break;
        default: break;
        }
    }
}

const QMetaObject *DesktopEntries::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DesktopEntries::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14DesktopEntriesE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DesktopEntries::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void DesktopEntries::applicationsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
