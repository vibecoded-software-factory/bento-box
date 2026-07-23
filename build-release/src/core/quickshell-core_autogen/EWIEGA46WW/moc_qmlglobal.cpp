/****************************************************************************
** Meta object code from reading C++ file 'qmlglobal.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/qmlglobal.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmlglobal.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18QuickshellSettingsE_t {};
} // unnamed namespace

template <> constexpr inline auto QuickshellSettings::qt_create_metaobjectdata<qt_meta_tag_ZN18QuickshellSettingsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QuickshellSettings",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "singleton",
        "lastWindowClosed",
        "",
        "workingDirectoryChanged",
        "watchFilesChanged",
        "workingDirectory",
        "watchFiles"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'lastWindowClosed'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'workingDirectoryChanged'
        QtMocHelpers::SignalData<void()>(9, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'watchFilesChanged'
        QtMocHelpers::SignalData<void()>(10, 8, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'workingDirectory'
        QtMocHelpers::PropertyData<QString>(11, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'watchFiles'
        QtMocHelpers::PropertyData<bool>(12, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<QuickshellSettings, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject QuickshellSettings::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QuickshellSettingsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QuickshellSettingsE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18QuickshellSettingsE_t>.metaTypes,
    nullptr
} };

void QuickshellSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QuickshellSettings *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->lastWindowClosed(); break;
        case 1: _t->workingDirectoryChanged(); break;
        case 2: _t->watchFilesChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QuickshellSettings::*)()>(_a, &QuickshellSettings::lastWindowClosed, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QuickshellSettings::*)()>(_a, &QuickshellSettings::workingDirectoryChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QuickshellSettings::*)()>(_a, &QuickshellSettings::watchFilesChanged, 2))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->workingDirectory(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->watchFiles(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setWorkingDirectory(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setWatchFiles(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QuickshellSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuickshellSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QuickshellSettingsE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QuickshellSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QuickshellSettings::lastWindowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QuickshellSettings::workingDirectoryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QuickshellSettings::watchFilesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
namespace {
struct qt_meta_tag_ZN17QuickshellTrackedE_t {};
} // unnamed namespace

template <> constexpr inline auto QuickshellTracked::qt_create_metaobjectdata<qt_meta_tag_ZN17QuickshellTrackedE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QuickshellTracked",
        "screensChanged",
        "",
        "updateScreens"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'screensChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'updateScreens'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QuickshellTracked, qt_meta_tag_ZN17QuickshellTrackedE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QuickshellTracked::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QuickshellTrackedE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QuickshellTrackedE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QuickshellTrackedE_t>.metaTypes,
    nullptr
} };

void QuickshellTracked::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QuickshellTracked *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->screensChanged(); break;
        case 1: _t->updateScreens(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QuickshellTracked::*)()>(_a, &QuickshellTracked::screensChanged, 0))
            return;
    }
}

const QMetaObject *QuickshellTracked::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuickshellTracked::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QuickshellTrackedE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QuickshellTracked::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void QuickshellTracked::screensChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {
struct qt_meta_tag_ZN16QuickshellGlobalE_t {};
} // unnamed namespace

template <> constexpr inline auto QuickshellGlobal::qt_create_metaobjectdata<qt_meta_tag_ZN16QuickshellGlobalE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QuickshellGlobal",
        "QML.Singleton",
        "true",
        "QML.Element",
        "Quickshell",
        "lastWindowClosed",
        "",
        "reloadCompleted",
        "reloadFailed",
        "errorString",
        "screensChanged",
        "workingDirectoryChanged",
        "watchFilesChanged",
        "clipboardTextChanged",
        "onClipboardChanged",
        "QClipboard::Mode",
        "mode",
        "reload",
        "hard",
        "env",
        "QVariant",
        "variable",
        "execDetached",
        "command",
        "qs::io::process::ProcessContext",
        "context",
        "iconPath",
        "icon",
        "check",
        "fallback",
        "hasThemeIcon",
        "shellPath",
        "path",
        "configPath",
        "dataPath",
        "statePath",
        "cachePath",
        "inhibitReloadPopup",
        "hasVersion",
        "major",
        "minor",
        "features",
        "hasQtVersion",
        "processId",
        "instanceId",
        "shellId",
        "appId",
        "launchTime",
        "screens",
        "QQmlListProperty<QuickshellScreenInfo>",
        "shellDir",
        "configDir",
        "shellRoot",
        "workingDirectory",
        "watchFiles",
        "clipboardText",
        "dataDir",
        "stateDir",
        "cacheDir"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'lastWindowClosed'
        QtMocHelpers::SignalData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'reloadCompleted'
        QtMocHelpers::SignalData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'reloadFailed'
        QtMocHelpers::SignalData<void(QString)>(8, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Signal 'screensChanged'
        QtMocHelpers::SignalData<void()>(10, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'workingDirectoryChanged'
        QtMocHelpers::SignalData<void()>(11, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'watchFilesChanged'
        QtMocHelpers::SignalData<void()>(12, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'clipboardTextChanged'
        QtMocHelpers::SignalData<void()>(13, 6, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onClipboardChanged'
        QtMocHelpers::SlotData<void(QClipboard::Mode)>(14, 6, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 15, 16 },
        }}),
        // Method 'reload'
        QtMocHelpers::MethodData<void(bool)>(17, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 18 },
        }}),
        // Method 'env'
        QtMocHelpers::MethodData<QVariant(const QString &)>(19, 6, QMC::AccessPublic, 0x80000000 | 20, {{
            { QMetaType::QString, 21 },
        }}),
        // Method 'execDetached'
        QtMocHelpers::MethodData<void(QList<QString>)>(22, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 23 },
        }}),
        // Method 'execDetached'
        QtMocHelpers::MethodData<void(const qs::io::process::ProcessContext &)>(22, 6, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 24, 25 },
        }}),
        // Method 'iconPath'
        QtMocHelpers::MethodData<QString(const QString &)>(26, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 27 },
        }}),
        // Method 'iconPath'
        QtMocHelpers::MethodData<QString(const QString &, bool)>(26, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 27 }, { QMetaType::Bool, 28 },
        }}),
        // Method 'iconPath'
        QtMocHelpers::MethodData<QString(const QString &, const QString &)>(26, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 27 }, { QMetaType::QString, 29 },
        }}),
        // Method 'hasThemeIcon'
        QtMocHelpers::MethodData<bool(const QString &)>(30, 6, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 27 },
        }}),
        // Method 'shellPath'
        QtMocHelpers::MethodData<QString(const QString &) const>(31, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 32 },
        }}),
        // Method 'configPath'
        QtMocHelpers::MethodData<QString(const QString &) const>(33, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 32 },
        }}),
        // Method 'dataPath'
        QtMocHelpers::MethodData<QString(const QString &) const>(34, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 32 },
        }}),
        // Method 'statePath'
        QtMocHelpers::MethodData<QString(const QString &) const>(35, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 32 },
        }}),
        // Method 'cachePath'
        QtMocHelpers::MethodData<QString(const QString &) const>(36, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 32 },
        }}),
        // Method 'inhibitReloadPopup'
        QtMocHelpers::MethodData<void()>(37, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'hasVersion'
        QtMocHelpers::MethodData<bool(qint32, qint32, const QStringList &)>(38, 6, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 39 }, { QMetaType::Int, 40 }, { QMetaType::QStringList, 41 },
        }}),
        // Method 'hasVersion'
        QtMocHelpers::MethodData<bool(qint32, qint32)>(38, 6, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 39 }, { QMetaType::Int, 40 },
        }}),
        // Method 'hasQtVersion'
        QtMocHelpers::MethodData<bool(qint32, qint32)>(42, 6, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 39 }, { QMetaType::Int, 40 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'processId'
        QtMocHelpers::PropertyData<qint32>(43, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'instanceId'
        QtMocHelpers::PropertyData<QString>(44, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'shellId'
        QtMocHelpers::PropertyData<QString>(45, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'appId'
        QtMocHelpers::PropertyData<QString>(46, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'launchTime'
        QtMocHelpers::PropertyData<QDateTime>(47, QMetaType::QDateTime, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'screens'
        QtMocHelpers::PropertyData<QQmlListProperty<QuickshellScreenInfo>>(48, 0x80000000 | 49, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 3),
        // property 'shellDir'
        QtMocHelpers::PropertyData<QString>(50, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'configDir'
        QtMocHelpers::PropertyData<QString>(51, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'shellRoot'
        QtMocHelpers::PropertyData<QString>(52, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'workingDirectory'
        QtMocHelpers::PropertyData<QString>(53, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'watchFiles'
        QtMocHelpers::PropertyData<bool>(54, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'clipboardText'
        QtMocHelpers::PropertyData<QString>(55, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'dataDir'
        QtMocHelpers::PropertyData<QString>(56, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'stateDir'
        QtMocHelpers::PropertyData<QString>(57, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'cacheDir'
        QtMocHelpers::PropertyData<QString>(58, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<QuickshellGlobal, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject QuickshellGlobal::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QuickshellGlobalE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QuickshellGlobalE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16QuickshellGlobalE_t>.metaTypes,
    nullptr
} };

void QuickshellGlobal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QuickshellGlobal *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->lastWindowClosed(); break;
        case 1: _t->reloadCompleted(); break;
        case 2: _t->reloadFailed((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->screensChanged(); break;
        case 4: _t->workingDirectoryChanged(); break;
        case 5: _t->watchFilesChanged(); break;
        case 6: _t->clipboardTextChanged(); break;
        case 7: _t->onClipboardChanged((*reinterpret_cast<std::add_pointer_t<QClipboard::Mode>>(_a[1]))); break;
        case 8: _t->reload((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: { QVariant _r = _t->env((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QVariant*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->execDetached((*reinterpret_cast<std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 11: _t->execDetached((*reinterpret_cast<std::add_pointer_t<qs::io::process::ProcessContext>>(_a[1]))); break;
        case 12: { QString _r = _t->iconPath((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->iconPath((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 14: { QString _r = _t->iconPath((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->hasThemeIcon((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { QString _r = _t->shellPath((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 17: { QString _r = _t->configPath((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 18: { QString _r = _t->dataPath((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 19: { QString _r = _t->statePath((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 20: { QString _r = _t->cachePath((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 21: _t->inhibitReloadPopup(); break;
        case 22: { bool _r = _t->hasVersion((*reinterpret_cast<std::add_pointer_t<qint32>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qint32>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[3])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 23: { bool _r = _t->hasVersion((*reinterpret_cast<std::add_pointer_t<qint32>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qint32>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 24: { bool _r = _t->hasQtVersion((*reinterpret_cast<std::add_pointer_t<qint32>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qint32>>(_a[2])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QuickshellGlobal::*)()>(_a, &QuickshellGlobal::lastWindowClosed, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QuickshellGlobal::*)()>(_a, &QuickshellGlobal::reloadCompleted, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QuickshellGlobal::*)(QString )>(_a, &QuickshellGlobal::reloadFailed, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QuickshellGlobal::*)()>(_a, &QuickshellGlobal::screensChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QuickshellGlobal::*)()>(_a, &QuickshellGlobal::workingDirectoryChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QuickshellGlobal::*)()>(_a, &QuickshellGlobal::watchFilesChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QuickshellGlobal::*)()>(_a, &QuickshellGlobal::clipboardTextChanged, 6))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qint32*>(_v) = _t->processId(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->instanceId(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->shellId(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->appId(); break;
        case 4: *reinterpret_cast<QDateTime*>(_v) = _t->launchTime(); break;
        case 5: *reinterpret_cast<QQmlListProperty<QuickshellScreenInfo>*>(_v) = _t->screens(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->shellDir(); break;
        case 7: *reinterpret_cast<QString*>(_v) = _t->configDir(); break;
        case 8: *reinterpret_cast<QString*>(_v) = _t->shellRoot(); break;
        case 9: *reinterpret_cast<QString*>(_v) = _t->workingDirectory(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->watchFiles(); break;
        case 11: *reinterpret_cast<QString*>(_v) = _t->clipboardText(); break;
        case 12: *reinterpret_cast<QString*>(_v) = _t->dataDir(); break;
        case 13: *reinterpret_cast<QString*>(_v) = _t->stateDir(); break;
        case 14: *reinterpret_cast<QString*>(_v) = _t->cacheDir(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 9: _t->setWorkingDirectory(*reinterpret_cast<QString*>(_v)); break;
        case 10: _t->setWatchFiles(*reinterpret_cast<bool*>(_v)); break;
        case 11: _t->setClipboardText(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QuickshellGlobal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuickshellGlobal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QuickshellGlobalE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QuickshellGlobal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 25;
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
void QuickshellGlobal::lastWindowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QuickshellGlobal::reloadCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QuickshellGlobal::reloadFailed(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QuickshellGlobal::screensChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QuickshellGlobal::workingDirectoryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QuickshellGlobal::watchFilesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QuickshellGlobal::clipboardTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
