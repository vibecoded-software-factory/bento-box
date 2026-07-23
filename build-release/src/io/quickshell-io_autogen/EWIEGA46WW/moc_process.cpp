/****************************************************************************
** Meta object code from reading C++ file 'process.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/io/process.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'process.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7ProcessE_t {};
} // unnamed namespace

template <> constexpr inline auto Process::qt_create_metaobjectdata<qt_meta_tag_ZN7ProcessE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Process",
        "QML.Element",
        "auto",
        "started",
        "",
        "exited",
        "exitCode",
        "QProcess::ExitStatus",
        "exitStatus",
        "runningChanged",
        "processIdChanged",
        "commandChanged",
        "workingDirectoryChanged",
        "environmentChanged",
        "environmentClearChanged",
        "stdoutParserChanged",
        "stderrParserChanged",
        "stdinEnabledChanged",
        "onStarted",
        "onFinished",
        "onErrorOccurred",
        "QProcess::ProcessError",
        "error",
        "onStdoutReadyRead",
        "onStderrReadyRead",
        "onStdoutParserDestroyed",
        "onStderrParserDestroyed",
        "onGlobalWorkingDirectoryChanged",
        "exec",
        "command",
        "qs::io::process::ProcessContext",
        "context",
        "signal",
        "write",
        "data",
        "startDetached",
        "running",
        "processId",
        "QVariant",
        "workingDirectory",
        "environment",
        "QVariantHash",
        "clearEnvironment",
        "stdout",
        "DataStreamParser*",
        "stderr",
        "stdinEnabled"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'started'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'exited'
        QtMocHelpers::SignalData<void(qint32, QProcess::ExitStatus)>(5, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { 0x80000000 | 7, 8 },
        }}),
        // Signal 'runningChanged'
        QtMocHelpers::SignalData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'processIdChanged'
        QtMocHelpers::SignalData<void()>(10, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'commandChanged'
        QtMocHelpers::SignalData<void()>(11, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'workingDirectoryChanged'
        QtMocHelpers::SignalData<void()>(12, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'environmentChanged'
        QtMocHelpers::SignalData<void()>(13, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'environmentClearChanged'
        QtMocHelpers::SignalData<void()>(14, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'stdoutParserChanged'
        QtMocHelpers::SignalData<void()>(15, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'stderrParserChanged'
        QtMocHelpers::SignalData<void()>(16, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'stdinEnabledChanged'
        QtMocHelpers::SignalData<void()>(17, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onStarted'
        QtMocHelpers::SlotData<void()>(18, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onFinished'
        QtMocHelpers::SlotData<void(qint32, QProcess::ExitStatus)>(19, 4, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { 0x80000000 | 7, 8 },
        }}),
        // Slot 'onErrorOccurred'
        QtMocHelpers::SlotData<void(QProcess::ProcessError)>(20, 4, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 21, 22 },
        }}),
        // Slot 'onStdoutReadyRead'
        QtMocHelpers::SlotData<void()>(23, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onStderrReadyRead'
        QtMocHelpers::SlotData<void()>(24, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onStdoutParserDestroyed'
        QtMocHelpers::SlotData<void()>(25, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onStderrParserDestroyed'
        QtMocHelpers::SlotData<void()>(26, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onGlobalWorkingDirectoryChanged'
        QtMocHelpers::SlotData<void()>(27, 4, QMC::AccessPrivate, QMetaType::Void),
        // Method 'exec'
        QtMocHelpers::MethodData<void(QList<QString>)>(28, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 29 },
        }}),
        // Method 'exec'
        QtMocHelpers::MethodData<void(const qs::io::process::ProcessContext &)>(28, 4, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 30, 31 },
        }}),
        // Method 'signal'
        QtMocHelpers::MethodData<void(qint32)>(32, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 32 },
        }}),
        // Method 'write'
        QtMocHelpers::MethodData<void(const QString &)>(33, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 34 },
        }}),
        // Method 'startDetached'
        QtMocHelpers::MethodData<void()>(35, 4, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'running'
        QtMocHelpers::PropertyData<bool>(36, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'processId'
        QtMocHelpers::PropertyData<QVariant>(37, 0x80000000 | 38, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 3),
        // property 'command'
        QtMocHelpers::PropertyData<QList<QString>>(29, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'workingDirectory'
        QtMocHelpers::PropertyData<QString>(39, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'environment'
        QtMocHelpers::PropertyData<QVariantHash>(40, 0x80000000 | 41, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 6),
        // property 'clearEnvironment'
        QtMocHelpers::PropertyData<bool>(42, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable, 7),
        // property 'stdout'
        QtMocHelpers::PropertyData<DataStreamParser*>(43, 0x80000000 | 44, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag, 8),
        // property 'stderr'
        QtMocHelpers::PropertyData<DataStreamParser*>(45, 0x80000000 | 44, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag, 9),
        // property 'stdinEnabled'
        QtMocHelpers::PropertyData<bool>(46, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 10),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<Process, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject Process::staticMetaObject = { {
    QMetaObject::SuperData::link<PostReloadHook::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7ProcessE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7ProcessE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7ProcessE_t>.metaTypes,
    nullptr
} };

void Process::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Process *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->started(); break;
        case 1: _t->exited((*reinterpret_cast<std::add_pointer_t<qint32>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QProcess::ExitStatus>>(_a[2]))); break;
        case 2: _t->runningChanged(); break;
        case 3: _t->processIdChanged(); break;
        case 4: _t->commandChanged(); break;
        case 5: _t->workingDirectoryChanged(); break;
        case 6: _t->environmentChanged(); break;
        case 7: _t->environmentClearChanged(); break;
        case 8: _t->stdoutParserChanged(); break;
        case 9: _t->stderrParserChanged(); break;
        case 10: _t->stdinEnabledChanged(); break;
        case 11: _t->onStarted(); break;
        case 12: _t->onFinished((*reinterpret_cast<std::add_pointer_t<qint32>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QProcess::ExitStatus>>(_a[2]))); break;
        case 13: _t->onErrorOccurred((*reinterpret_cast<std::add_pointer_t<QProcess::ProcessError>>(_a[1]))); break;
        case 14: _t->onStdoutReadyRead(); break;
        case 15: _t->onStderrReadyRead(); break;
        case 16: _t->onStdoutParserDestroyed(); break;
        case 17: _t->onStderrParserDestroyed(); break;
        case 18: _t->onGlobalWorkingDirectoryChanged(); break;
        case 19: _t->exec((*reinterpret_cast<std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 20: _t->exec((*reinterpret_cast<std::add_pointer_t<qs::io::process::ProcessContext>>(_a[1]))); break;
        case 21: _t->signal((*reinterpret_cast<std::add_pointer_t<qint32>>(_a[1]))); break;
        case 22: _t->write((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 23: _t->startDetached(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Process::*)()>(_a, &Process::started, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Process::*)(qint32 , QProcess::ExitStatus )>(_a, &Process::exited, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Process::*)()>(_a, &Process::runningChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Process::*)()>(_a, &Process::processIdChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Process::*)()>(_a, &Process::commandChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (Process::*)()>(_a, &Process::workingDirectoryChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (Process::*)()>(_a, &Process::environmentChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (Process::*)()>(_a, &Process::environmentClearChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (Process::*)()>(_a, &Process::stdoutParserChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (Process::*)()>(_a, &Process::stderrParserChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (Process::*)()>(_a, &Process::stdinEnabledChanged, 10))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
        case 6:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DataStreamParser* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isRunning(); break;
        case 1: *reinterpret_cast<QVariant*>(_v) = _t->processId(); break;
        case 2: *reinterpret_cast<QList<QString>*>(_v) = _t->command(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->workingDirectory(); break;
        case 4: *reinterpret_cast<QVariantHash*>(_v) = _t->environment(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->environmentCleared(); break;
        case 6: *reinterpret_cast<DataStreamParser**>(_v) = _t->stdoutParser(); break;
        case 7: *reinterpret_cast<DataStreamParser**>(_v) = _t->stderrParser(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->stdinEnabled(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRunning(*reinterpret_cast<bool*>(_v)); break;
        case 2: _t->setCommand(*reinterpret_cast<QList<QString>*>(_v)); break;
        case 3: _t->setWorkingDirectory(*reinterpret_cast<QString*>(_v)); break;
        case 4: _t->setEnvironment(*reinterpret_cast<QVariantHash*>(_v)); break;
        case 5: _t->setEnvironmentCleared(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setStdoutParser(*reinterpret_cast<DataStreamParser**>(_v)); break;
        case 7: _t->setStderrParser(*reinterpret_cast<DataStreamParser**>(_v)); break;
        case 8: _t->setStdinEnabled(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *Process::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Process::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7ProcessE_t>.strings))
        return static_cast<void*>(this);
    return PostReloadHook::qt_metacast(_clname);
}

int Process::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PostReloadHook::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 24;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Process::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Process::exited(qint32 _t1, QProcess::ExitStatus _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void Process::runningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Process::processIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Process::commandChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Process::workingDirectoryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Process::environmentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Process::environmentClearChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Process::stdoutParserChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Process::stderrParserChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void Process::stdinEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
