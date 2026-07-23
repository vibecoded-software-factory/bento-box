/****************************************************************************
** Meta object code from reading C++ file 'node.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/pipewire/node.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'node.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs3mac8pipewire14PwAudioChannelE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::pipewire::PwAudioChannel::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac8pipewire14PwAudioChannelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::pipewire::PwAudioChannel",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "toString",
        "",
        "qs::mac::pipewire::PwAudioChannel::Enum",
        "channel",
        "Enum",
        "Unknown",
        "NA",
        "Mono",
        "FrontLeft",
        "FrontRight",
        "FrontCenter",
        "LowFrequencyEffects",
        "SideLeft",
        "SideRight"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'toString'
        QtMocHelpers::MethodData<QString(qs::mac::pipewire::PwAudioChannel::Enum)>(5, 6, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 7, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<enum Enum>(9, 9, QMC::EnumFlags{}).add({
            {   10, Enum::Unknown },
            {   11, Enum::NA },
            {   12, Enum::Mono },
            {   13, Enum::FrontLeft },
            {   14, Enum::FrontRight },
            {   15, Enum::FrontCenter },
            {   16, Enum::LowFrequencyEffects },
            {   17, Enum::SideLeft },
            {   18, Enum::SideRight },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<PwAudioChannel, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::pipewire::PwAudioChannel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire14PwAudioChannelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire14PwAudioChannelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac8pipewire14PwAudioChannelE_t>.metaTypes,
    nullptr
} };

void qs::mac::pipewire::PwAudioChannel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PwAudioChannel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = _t->toString((*reinterpret_cast<std::add_pointer_t<qs::mac::pipewire::PwAudioChannel::Enum>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *qs::mac::pipewire::PwAudioChannel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::pipewire::PwAudioChannel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire14PwAudioChannelE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::pipewire::PwAudioChannel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_tag_ZN2qs3mac8pipewire10PwNodeTypeE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::pipewire::PwNodeType::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac8pipewire10PwNodeTypeE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::pipewire::PwNodeType",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "toString",
        "",
        "qs::mac::pipewire::PwNodeType::Flags",
        "type",
        "Flag",
        "Untracked",
        "Audio",
        "Video",
        "Stream",
        "Source",
        "Sink",
        "AudioSink",
        "AudioSource",
        "AudioDuplex",
        "AudioOutStream",
        "AudioInStream",
        "VideoSource",
        "VideoSink"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'toString'
        QtMocHelpers::MethodData<QString(qs::mac::pipewire::PwNodeType::Flags)>(5, 6, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 7, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Flag'
        QtMocHelpers::EnumData<enum Flag>(9, 9, QMC::EnumFlags{}).add({
            {   10, Flag::Untracked },
            {   11, Flag::Audio },
            {   12, Flag::Video },
            {   13, Flag::Stream },
            {   14, Flag::Source },
            {   15, Flag::Sink },
            {   16, Flag::AudioSink },
            {   17, Flag::AudioSource },
            {   18, Flag::AudioDuplex },
            {   19, Flag::AudioOutStream },
            {   20, Flag::AudioInStream },
            {   21, Flag::VideoSource },
            {   22, Flag::VideoSink },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<PwNodeType, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::pipewire::PwNodeType::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire10PwNodeTypeE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire10PwNodeTypeE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac8pipewire10PwNodeTypeE_t>.metaTypes,
    nullptr
} };

void qs::mac::pipewire::PwNodeType::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PwNodeType *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = _t->toString((*reinterpret_cast<std::add_pointer_t<qs::mac::pipewire::PwNodeType::Flags>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *qs::mac::pipewire::PwNodeType::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::pipewire::PwNodeType::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire10PwNodeTypeE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::pipewire::PwNodeType::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_tag_ZN2qs3mac8pipewire11PwNodeAudioE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::pipewire::PwNodeAudio::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac8pipewire11PwNodeAudioE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::pipewire::PwNodeAudio",
        "QML.Element",
        "PwNodeAudio",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "PwNodeAudio cannot be created directly",
        "mutedChanged",
        "",
        "channelsChanged",
        "volumesChanged",
        "muted",
        "volume",
        "channels",
        "QList<qs::mac::pipewire::PwAudioChannel::Enum>",
        "volumes",
        "QList<float>"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'mutedChanged'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'channelsChanged'
        QtMocHelpers::SignalData<void()>(9, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'volumesChanged'
        QtMocHelpers::SignalData<void()>(10, 8, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'muted'
        QtMocHelpers::PropertyData<bool>(11, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'volume'
        QtMocHelpers::PropertyData<float>(12, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable, 2),
        // property 'channels'
        QtMocHelpers::PropertyData<QList<qs::mac::pipewire::PwAudioChannel::Enum>>(13, 0x80000000 | 14, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 1),
        // property 'volumes'
        QtMocHelpers::PropertyData<QList<float>>(15, 0x80000000 | 16, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 2),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<PwNodeAudio, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::pipewire::PwNodeAudio::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire11PwNodeAudioE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire11PwNodeAudioE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac8pipewire11PwNodeAudioE_t>.metaTypes,
    nullptr
} };

void qs::mac::pipewire::PwNodeAudio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PwNodeAudio *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->mutedChanged(); break;
        case 1: _t->channelsChanged(); break;
        case 2: _t->volumesChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (PwNodeAudio::*)()>(_a, &PwNodeAudio::mutedChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (PwNodeAudio::*)()>(_a, &PwNodeAudio::channelsChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (PwNodeAudio::*)()>(_a, &PwNodeAudio::volumesChanged, 2))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<float> >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isMuted(); break;
        case 1: *reinterpret_cast<float*>(_v) = _t->averageVolume(); break;
        case 2: *reinterpret_cast<QList<qs::mac::pipewire::PwAudioChannel::Enum>*>(_v) = _t->channels(); break;
        case 3: *reinterpret_cast<QList<float>*>(_v) = _t->volumes(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMuted(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setAverageVolume(*reinterpret_cast<float*>(_v)); break;
        case 3: _t->setVolumes(*reinterpret_cast<QList<float>*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::pipewire::PwNodeAudio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::pipewire::PwNodeAudio::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire11PwNodeAudioE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::pipewire::PwNodeAudio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::pipewire::PwNodeAudio::mutedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::pipewire::PwNodeAudio::channelsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::mac::pipewire::PwNodeAudio::volumesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac8pipewire6PwNodeE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::pipewire::PwNode::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac8pipewire6PwNodeE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::pipewire::PwNode",
        "QML.Element",
        "PwNode",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "PwNodes cannot be created directly",
        "readyChanged",
        "",
        "id",
        "name",
        "description",
        "nickname",
        "isSink",
        "isStream",
        "type",
        "qs::mac::pipewire::PwNodeType::Flags",
        "properties",
        "QVariantMap",
        "audio",
        "qs::mac::pipewire::PwNodeAudio*",
        "ready"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'readyChanged'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'id'
        QtMocHelpers::PropertyData<quint32>(9, QMetaType::UInt, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'name'
        QtMocHelpers::PropertyData<QString>(10, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'description'
        QtMocHelpers::PropertyData<QString>(11, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'nickname'
        QtMocHelpers::PropertyData<QString>(12, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'isSink'
        QtMocHelpers::PropertyData<bool>(13, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'isStream'
        QtMocHelpers::PropertyData<bool>(14, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'type'
        QtMocHelpers::PropertyData<qs::mac::pipewire::PwNodeType::Flags>(15, 0x80000000 | 16, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'properties'
        QtMocHelpers::PropertyData<QVariantMap>(17, 0x80000000 | 18, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'audio'
        QtMocHelpers::PropertyData<qs::mac::pipewire::PwNodeAudio*>(19, 0x80000000 | 20, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'ready'
        QtMocHelpers::PropertyData<bool>(21, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<PwNode, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN2qs3mac8pipewire6PwNodeE[] = {
    QMetaObject::SuperData::link<qs::mac::pipewire::PwNodeType::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject qs::mac::pipewire::PwNode::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire6PwNodeE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire6PwNodeE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN2qs3mac8pipewire6PwNodeE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac8pipewire6PwNodeE_t>.metaTypes,
    nullptr
} };

void qs::mac::pipewire::PwNode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PwNode *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->readyChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (PwNode::*)()>(_a, &PwNode::readyChanged, 0))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< qs::mac::pipewire::PwNodeAudio* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<quint32*>(_v) = _t->id(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->name(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->description(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->nickname(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isSink(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->isStream(); break;
        case 6: *reinterpret_cast<qs::mac::pipewire::PwNodeType::Flags*>(_v) = _t->type(); break;
        case 7: *reinterpret_cast<QVariantMap*>(_v) = _t->properties(); break;
        case 8: *reinterpret_cast<qs::mac::pipewire::PwNodeAudio**>(_v) = _t->audio(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->isReady(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::pipewire::PwNode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::pipewire::PwNode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac8pipewire6PwNodeE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::pipewire::PwNode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::pipewire::PwNode::readyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
