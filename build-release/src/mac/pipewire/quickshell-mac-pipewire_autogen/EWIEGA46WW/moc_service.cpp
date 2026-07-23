/****************************************************************************
** Meta object code from reading C++ file 'service.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/pipewire/service.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'service.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs3mac8pipewire8PipewireE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::pipewire::Pipewire::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac8pipewire8PipewireE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::pipewire::Pipewire",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "defaultAudioSinkChanged",
        "",
        "defaultAudioSourceChanged",
        "readyChanged",
        "nodes",
        "UntypedObjectModel*",
        "links",
        "linkGroups",
        "defaultAudioSink",
        "qs::mac::pipewire::PwNode*",
        "defaultAudioSource",
        "preferredDefaultAudioSink",
        "preferredDefaultAudioSource",
        "ready"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'defaultAudioSinkChanged'
        QtMocHelpers::SignalData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'defaultAudioSourceChanged'
        QtMocHelpers::SignalData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'readyChanged'
        QtMocHelpers::SignalData<void()>(8, 6, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'nodes'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(9, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'links'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(11, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'linkGroups'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(12, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'defaultAudioSink'
        QtMocHelpers::PropertyData<qs::mac::pipewire::PwNode*>(13, 0x80000000 | 14, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
        // property 'defaultAudioSource'
        QtMocHelpers::PropertyData<qs::mac::pipewire::PwNode*>(15, 0x80000000 | 14, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 1),
        // property 'preferredDefaultAudioSink'
        QtMocHelpers::PropertyData<qs::mac::pipewire::PwNode*>(16, 0x80000000 | 14, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 0),
        // property 'preferredDefaultAudioSource'
        QtMocHelpers::PropertyData<qs::mac::pipewire::PwNode*>(17, 0x80000000 | 14, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 1),
        // property 'ready'
        QtMocHelpers::PropertyData<bool>(18, QMetaType::Bool, QMC::DefaultPropertyFlags, 2),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<Pipewire, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::pipewire::Pipewire::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire8PipewireE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire8PipewireE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac8pipewire8PipewireE_t>.metaTypes,
    nullptr
} };

void qs::mac::pipewire::Pipewire::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Pipewire *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->defaultAudioSinkChanged(); break;
        case 1: _t->defaultAudioSourceChanged(); break;
        case 2: _t->readyChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Pipewire::*)()>(_a, &Pipewire::defaultAudioSinkChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Pipewire::*)()>(_a, &Pipewire::defaultAudioSourceChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Pipewire::*)()>(_a, &Pipewire::readyChanged, 2))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< UntypedObjectModel* >(); break;
        case 6:
        case 5:
        case 4:
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qs::mac::pipewire::PwNode* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->nodes(); break;
        case 1: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->links(); break;
        case 2: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->linkGroups(); break;
        case 3: *reinterpret_cast<qs::mac::pipewire::PwNode**>(_v) = _t->defaultAudioSink(); break;
        case 4: *reinterpret_cast<qs::mac::pipewire::PwNode**>(_v) = _t->defaultAudioSource(); break;
        case 5: *reinterpret_cast<qs::mac::pipewire::PwNode**>(_v) = _t->defaultAudioSink(); break;
        case 6: *reinterpret_cast<qs::mac::pipewire::PwNode**>(_v) = _t->defaultAudioSource(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->isReady(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 5: _t->setPreferredDefaultAudioSink(*reinterpret_cast<qs::mac::pipewire::PwNode**>(_v)); break;
        case 6: _t->setPreferredDefaultAudioSource(*reinterpret_cast<qs::mac::pipewire::PwNode**>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::pipewire::Pipewire::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::pipewire::Pipewire::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire8PipewireE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::pipewire::Pipewire::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::pipewire::Pipewire::defaultAudioSinkChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::pipewire::Pipewire::defaultAudioSourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::mac::pipewire::Pipewire::readyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac8pipewire15PwObjectTrackerE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::pipewire::PwObjectTracker::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac8pipewire15PwObjectTrackerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::pipewire::PwObjectTracker",
        "QML.Element",
        "auto",
        "objectsChanged",
        "",
        "objects",
        "QList<QObject*>"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'objectsChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'objects'
        QtMocHelpers::PropertyData<QList<QObject*>>(5, 0x80000000 | 6, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<PwObjectTracker, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::pipewire::PwObjectTracker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire15PwObjectTrackerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire15PwObjectTrackerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac8pipewire15PwObjectTrackerE_t>.metaTypes,
    nullptr
} };

void qs::mac::pipewire::PwObjectTracker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PwObjectTracker *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->objectsChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (PwObjectTracker::*)()>(_a, &PwObjectTracker::objectsChanged, 0))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QList<QObject*>*>(_v) = _t->objects(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setObjects(*reinterpret_cast<QList<QObject*>*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::pipewire::PwObjectTracker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::pipewire::PwObjectTracker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire15PwObjectTrackerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::pipewire::PwObjectTracker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::pipewire::PwObjectTracker::objectsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
