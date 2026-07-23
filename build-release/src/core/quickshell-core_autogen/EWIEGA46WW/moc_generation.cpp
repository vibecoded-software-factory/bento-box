/****************************************************************************
** Meta object code from reading C++ file 'generation.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/generation.hpp"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'generation.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN16EngineGenerationE_t {};
} // unnamed namespace

template <> constexpr inline auto EngineGeneration::qt_create_metaobjectdata<qt_meta_tag_ZN16EngineGenerationE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "EngineGeneration",
        "filesChanged",
        "",
        "reloadFinished",
        "firePostReload",
        "quit",
        "exit",
        "code",
        "onFileChanged",
        "name",
        "onDirectoryChanged",
        "onTrackedWindowDestroyed",
        "object",
        "onEngineWarnings",
        "QList<QQmlError>",
        "warnings"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'filesChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'reloadFinished'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'firePostReload'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'quit'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'exit'
        QtMocHelpers::SlotData<void(int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'onFileChanged'
        QtMocHelpers::SlotData<void(const QString &)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'onDirectoryChanged'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onTrackedWindowDestroyed'
        QtMocHelpers::SlotData<void(QObject *)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QObjectStar, 12 },
        }}),
        // Slot 'onEngineWarnings'
        QtMocHelpers::SlotData<void(const QList<QQmlError> &)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 14, 15 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<EngineGeneration, qt_meta_tag_ZN16EngineGenerationE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject EngineGeneration::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16EngineGenerationE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16EngineGenerationE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16EngineGenerationE_t>.metaTypes,
    nullptr
} };

void EngineGeneration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<EngineGeneration *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->filesChanged(); break;
        case 1: _t->reloadFinished(); break;
        case 2: _t->firePostReload(); break;
        case 3: _t->quit(); break;
        case 4: _t->exit((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->onFileChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->onDirectoryChanged(); break;
        case 7: _t->onTrackedWindowDestroyed((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1]))); break;
        case 8: _t->onEngineWarnings((*reinterpret_cast<std::add_pointer_t<QList<QQmlError>>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (EngineGeneration::*)()>(_a, &EngineGeneration::filesChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (EngineGeneration::*)()>(_a, &EngineGeneration::reloadFinished, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (EngineGeneration::*)()>(_a, &EngineGeneration::firePostReload, 2))
            return;
    }
}

const QMetaObject *EngineGeneration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EngineGeneration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16EngineGenerationE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EngineGeneration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void EngineGeneration::filesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void EngineGeneration::reloadFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void EngineGeneration::firePostReload()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
