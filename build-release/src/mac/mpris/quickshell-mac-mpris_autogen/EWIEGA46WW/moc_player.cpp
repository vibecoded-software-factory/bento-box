/****************************************************************************
** Meta object code from reading C++ file 'player.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/mpris/player.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'player.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs3mac5mpris18MprisPlaybackStateE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::mpris::MprisPlaybackState::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac5mpris18MprisPlaybackStateE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::mpris::MprisPlaybackState",
        "QML.Element",
        "MprisPlaybackState",
        "QML.Singleton",
        "true",
        "toString",
        "",
        "qs::mac::mpris::MprisPlaybackState::Enum",
        "value",
        "Enum",
        "Stopped",
        "Playing",
        "Paused"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'toString'
        QtMocHelpers::MethodData<QString(qs::mac::mpris::MprisPlaybackState::Enum)>(5, 6, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 7, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<enum Enum>(9, 9, QMC::EnumFlags{}).add({
            {   10, Enum::Stopped },
            {   11, Enum::Playing },
            {   12, Enum::Paused },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<MprisPlaybackState, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::mpris::MprisPlaybackState::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac5mpris18MprisPlaybackStateE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac5mpris18MprisPlaybackStateE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac5mpris18MprisPlaybackStateE_t>.metaTypes,
    nullptr
} };

void qs::mac::mpris::MprisPlaybackState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MprisPlaybackState *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = _t->toString((*reinterpret_cast<std::add_pointer_t<qs::mac::mpris::MprisPlaybackState::Enum>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *qs::mac::mpris::MprisPlaybackState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::mpris::MprisPlaybackState::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac5mpris18MprisPlaybackStateE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::mpris::MprisPlaybackState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_tag_ZN2qs3mac5mpris14MprisLoopStateE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::mpris::MprisLoopState::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac5mpris14MprisLoopStateE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::mpris::MprisLoopState",
        "QML.Element",
        "MprisLoopState",
        "QML.Singleton",
        "true",
        "toString",
        "",
        "qs::mac::mpris::MprisLoopState::Enum",
        "value",
        "Enum",
        "None",
        "Track",
        "Playlist"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'toString'
        QtMocHelpers::MethodData<QString(qs::mac::mpris::MprisLoopState::Enum)>(5, 6, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 7, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<enum Enum>(9, 9, QMC::EnumFlags{}).add({
            {   10, Enum::None },
            {   11, Enum::Track },
            {   12, Enum::Playlist },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<MprisLoopState, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::mpris::MprisLoopState::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac5mpris14MprisLoopStateE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac5mpris14MprisLoopStateE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac5mpris14MprisLoopStateE_t>.metaTypes,
    nullptr
} };

void qs::mac::mpris::MprisLoopState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MprisLoopState *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = _t->toString((*reinterpret_cast<std::add_pointer_t<qs::mac::mpris::MprisLoopState::Enum>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *qs::mac::mpris::MprisLoopState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::mpris::MprisLoopState::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac5mpris14MprisLoopStateE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::mpris::MprisLoopState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_tag_ZN2qs3mac5mpris11MprisPlayerE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::mpris::MprisPlayer::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac5mpris11MprisPlayerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::mpris::MprisPlayer",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "MprisPlayers can only be acquired from Mpris.",
        "trackChanged",
        "",
        "identityChanged",
        "desktopEntryChanged",
        "canControlChanged",
        "canPlayChanged",
        "canPauseChanged",
        "canTogglePlayingChanged",
        "canGoNextChanged",
        "canGoPreviousChanged",
        "canSeekChanged",
        "canQuitChanged",
        "canRaiseChanged",
        "playbackStateChanged",
        "positionChanged",
        "positionSupportedChanged",
        "lengthChanged",
        "lengthSupportedChanged",
        "metadataChanged",
        "trackTitleChanged",
        "trackArtistChanged",
        "trackAlbumChanged",
        "trackArtUrlChanged",
        "volumeChanged",
        "volumeSupportedChanged",
        "loopStateChanged",
        "loopSupportedChanged",
        "shuffleChanged",
        "shuffleSupportedChanged",
        "play",
        "pause",
        "stop",
        "togglePlaying",
        "next",
        "previous",
        "seek",
        "raise",
        "quit",
        "identity",
        "desktopEntry",
        "dbusName",
        "canControl",
        "canPlay",
        "canPause",
        "canTogglePlaying",
        "canGoNext",
        "canGoPrevious",
        "canSeek",
        "canQuit",
        "canRaise",
        "playbackState",
        "qs::mac::mpris::MprisPlaybackState::Enum",
        "isPlaying",
        "position",
        "positionSupported",
        "length",
        "lengthSupported",
        "metadata",
        "QVariantMap",
        "trackTitle",
        "trackArtist",
        "trackAlbum",
        "trackArtUrl",
        "volume",
        "volumeSupported",
        "loopState",
        "qs::mac::mpris::MprisLoopState::Enum",
        "loopSupported",
        "shuffle",
        "shuffleSupported"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'trackChanged'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'identityChanged'
        QtMocHelpers::SignalData<void()>(9, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'desktopEntryChanged'
        QtMocHelpers::SignalData<void()>(10, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'canControlChanged'
        QtMocHelpers::SignalData<void()>(11, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'canPlayChanged'
        QtMocHelpers::SignalData<void()>(12, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'canPauseChanged'
        QtMocHelpers::SignalData<void()>(13, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'canTogglePlayingChanged'
        QtMocHelpers::SignalData<void()>(14, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'canGoNextChanged'
        QtMocHelpers::SignalData<void()>(15, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'canGoPreviousChanged'
        QtMocHelpers::SignalData<void()>(16, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'canSeekChanged'
        QtMocHelpers::SignalData<void()>(17, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'canQuitChanged'
        QtMocHelpers::SignalData<void()>(18, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'canRaiseChanged'
        QtMocHelpers::SignalData<void()>(19, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'playbackStateChanged'
        QtMocHelpers::SignalData<void()>(20, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'positionChanged'
        QtMocHelpers::SignalData<void()>(21, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'positionSupportedChanged'
        QtMocHelpers::SignalData<void()>(22, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'lengthChanged'
        QtMocHelpers::SignalData<void()>(23, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'lengthSupportedChanged'
        QtMocHelpers::SignalData<void()>(24, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'metadataChanged'
        QtMocHelpers::SignalData<void()>(25, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'trackTitleChanged'
        QtMocHelpers::SignalData<void()>(26, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'trackArtistChanged'
        QtMocHelpers::SignalData<void()>(27, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'trackAlbumChanged'
        QtMocHelpers::SignalData<void()>(28, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'trackArtUrlChanged'
        QtMocHelpers::SignalData<void()>(29, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'volumeChanged'
        QtMocHelpers::SignalData<void()>(30, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'volumeSupportedChanged'
        QtMocHelpers::SignalData<void()>(31, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'loopStateChanged'
        QtMocHelpers::SignalData<void()>(32, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'loopSupportedChanged'
        QtMocHelpers::SignalData<void()>(33, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'shuffleChanged'
        QtMocHelpers::SignalData<void()>(34, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'shuffleSupportedChanged'
        QtMocHelpers::SignalData<void()>(35, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'play'
        QtMocHelpers::MethodData<void()>(36, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'pause'
        QtMocHelpers::MethodData<void()>(37, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'stop'
        QtMocHelpers::MethodData<void()>(38, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'togglePlaying'
        QtMocHelpers::MethodData<void()>(39, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'next'
        QtMocHelpers::MethodData<void()>(40, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'previous'
        QtMocHelpers::MethodData<void()>(41, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'seek'
        QtMocHelpers::MethodData<void(qreal)>(42, 8, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 8 },
        }}),
        // Method 'raise'
        QtMocHelpers::MethodData<void()>(43, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'quit'
        QtMocHelpers::MethodData<void()>(44, 8, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'identity'
        QtMocHelpers::PropertyData<QString>(45, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Bindable, 1),
        // property 'desktopEntry'
        QtMocHelpers::PropertyData<QString>(46, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Bindable, 2),
        // property 'dbusName'
        QtMocHelpers::PropertyData<QString>(47, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'canControl'
        QtMocHelpers::PropertyData<bool>(48, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 3),
        // property 'canPlay'
        QtMocHelpers::PropertyData<bool>(49, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 4),
        // property 'canPause'
        QtMocHelpers::PropertyData<bool>(50, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 5),
        // property 'canTogglePlaying'
        QtMocHelpers::PropertyData<bool>(51, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 6),
        // property 'canGoNext'
        QtMocHelpers::PropertyData<bool>(52, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 7),
        // property 'canGoPrevious'
        QtMocHelpers::PropertyData<bool>(53, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 8),
        // property 'canSeek'
        QtMocHelpers::PropertyData<bool>(54, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 9),
        // property 'canQuit'
        QtMocHelpers::PropertyData<bool>(55, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 10),
        // property 'canRaise'
        QtMocHelpers::PropertyData<bool>(56, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 11),
        // property 'playbackState'
        QtMocHelpers::PropertyData<qs::mac::mpris::MprisPlaybackState::Enum>(57, 0x80000000 | 58, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Bindable, 12),
        // property 'isPlaying'
        QtMocHelpers::PropertyData<bool>(59, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable, 12),
        // property 'position'
        QtMocHelpers::PropertyData<qreal>(60, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 13),
        // property 'positionSupported'
        QtMocHelpers::PropertyData<bool>(61, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 14),
        // property 'length'
        QtMocHelpers::PropertyData<qreal>(62, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Bindable, 15),
        // property 'lengthSupported'
        QtMocHelpers::PropertyData<bool>(63, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 16),
        // property 'metadata'
        QtMocHelpers::PropertyData<QVariantMap>(64, 0x80000000 | 65, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Bindable, 17),
        // property 'trackTitle'
        QtMocHelpers::PropertyData<QString>(66, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Bindable, 18),
        // property 'trackArtist'
        QtMocHelpers::PropertyData<QString>(67, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Bindable, 19),
        // property 'trackAlbum'
        QtMocHelpers::PropertyData<QString>(68, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Bindable, 20),
        // property 'trackArtUrl'
        QtMocHelpers::PropertyData<QString>(69, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Bindable, 21),
        // property 'volume'
        QtMocHelpers::PropertyData<qreal>(70, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Bindable, 22),
        // property 'volumeSupported'
        QtMocHelpers::PropertyData<bool>(71, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 23),
        // property 'loopState'
        QtMocHelpers::PropertyData<qs::mac::mpris::MprisLoopState::Enum>(72, 0x80000000 | 73, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Bindable, 24),
        // property 'loopSupported'
        QtMocHelpers::PropertyData<bool>(74, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 25),
        // property 'shuffle'
        QtMocHelpers::PropertyData<bool>(75, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 26),
        // property 'shuffleSupported'
        QtMocHelpers::PropertyData<bool>(76, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Bindable, 27),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<MprisPlayer, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN2qs3mac5mpris11MprisPlayerE[] = {
    QMetaObject::SuperData::link<qs::mac::mpris::MprisPlaybackState::staticMetaObject>(),
    QMetaObject::SuperData::link<qs::mac::mpris::MprisLoopState::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject qs::mac::mpris::MprisPlayer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac5mpris11MprisPlayerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac5mpris11MprisPlayerE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN2qs3mac5mpris11MprisPlayerE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac5mpris11MprisPlayerE_t>.metaTypes,
    nullptr
} };

void qs::mac::mpris::MprisPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MprisPlayer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->trackChanged(); break;
        case 1: _t->identityChanged(); break;
        case 2: _t->desktopEntryChanged(); break;
        case 3: _t->canControlChanged(); break;
        case 4: _t->canPlayChanged(); break;
        case 5: _t->canPauseChanged(); break;
        case 6: _t->canTogglePlayingChanged(); break;
        case 7: _t->canGoNextChanged(); break;
        case 8: _t->canGoPreviousChanged(); break;
        case 9: _t->canSeekChanged(); break;
        case 10: _t->canQuitChanged(); break;
        case 11: _t->canRaiseChanged(); break;
        case 12: _t->playbackStateChanged(); break;
        case 13: _t->positionChanged(); break;
        case 14: _t->positionSupportedChanged(); break;
        case 15: _t->lengthChanged(); break;
        case 16: _t->lengthSupportedChanged(); break;
        case 17: _t->metadataChanged(); break;
        case 18: _t->trackTitleChanged(); break;
        case 19: _t->trackArtistChanged(); break;
        case 20: _t->trackAlbumChanged(); break;
        case 21: _t->trackArtUrlChanged(); break;
        case 22: _t->volumeChanged(); break;
        case 23: _t->volumeSupportedChanged(); break;
        case 24: _t->loopStateChanged(); break;
        case 25: _t->loopSupportedChanged(); break;
        case 26: _t->shuffleChanged(); break;
        case 27: _t->shuffleSupportedChanged(); break;
        case 28: _t->play(); break;
        case 29: _t->pause(); break;
        case 30: _t->stop(); break;
        case 31: _t->togglePlaying(); break;
        case 32: _t->next(); break;
        case 33: _t->previous(); break;
        case 34: _t->seek((*reinterpret_cast<std::add_pointer_t<qreal>>(_a[1]))); break;
        case 35: _t->raise(); break;
        case 36: _t->quit(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::trackChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::identityChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::desktopEntryChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::canControlChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::canPlayChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::canPauseChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::canTogglePlayingChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::canGoNextChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::canGoPreviousChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::canSeekChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::canQuitChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::canRaiseChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::playbackStateChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::positionChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::positionSupportedChanged, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::lengthChanged, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::lengthSupportedChanged, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::metadataChanged, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::trackTitleChanged, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::trackArtistChanged, 19))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::trackAlbumChanged, 20))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::trackArtUrlChanged, 21))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::volumeChanged, 22))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::volumeSupportedChanged, 23))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::loopStateChanged, 24))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::loopSupportedChanged, 25))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::shuffleChanged, 26))
            return;
        if (QtMocHelpers::indexOfMethod<void (MprisPlayer::*)()>(_a, &MprisPlayer::shuffleSupportedChanged, 27))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->bindableIdentity().value(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->bindableDesktopEntry().value(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->dbusName(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->bindableCanControl().value(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->bindableCanPlay().value(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->bindableCanPause().value(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->bindableCanTogglePlaying().value(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->bindableCanGoNext().value(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->bindableCanGoPrevious().value(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->bindableCanSeek().value(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->bindableCanQuit().value(); break;
        case 11: *reinterpret_cast<bool*>(_v) = _t->bindableCanRaise().value(); break;
        case 12: *reinterpret_cast<qs::mac::mpris::MprisPlaybackState::Enum*>(_v) = _t->bindablePlaybackState().value(); break;
        case 13: *reinterpret_cast<bool*>(_v) = _t->isPlaying(); break;
        case 14: *reinterpret_cast<qreal*>(_v) = _t->position(); break;
        case 15: *reinterpret_cast<bool*>(_v) = _t->bindablePositionSupported().value(); break;
        case 16: *reinterpret_cast<qreal*>(_v) = _t->bindableLength().value(); break;
        case 17: *reinterpret_cast<bool*>(_v) = _t->bindableLengthSupported().value(); break;
        case 18: *reinterpret_cast<QVariantMap*>(_v) = _t->bindableMetadata().value(); break;
        case 19: *reinterpret_cast<QString*>(_v) = _t->bindableTrackTitle().value(); break;
        case 20: *reinterpret_cast<QString*>(_v) = _t->bindableTrackArtist().value(); break;
        case 21: *reinterpret_cast<QString*>(_v) = _t->bindableTrackAlbum().value(); break;
        case 22: *reinterpret_cast<QString*>(_v) = _t->bindableTrackArtUrl().value(); break;
        case 23: *reinterpret_cast<qreal*>(_v) = _t->bindableVolume().value(); break;
        case 24: *reinterpret_cast<bool*>(_v) = _t->bindableVolumeSupported().value(); break;
        case 25: *reinterpret_cast<qs::mac::mpris::MprisLoopState::Enum*>(_v) = _t->bindableLoopState().value(); break;
        case 26: *reinterpret_cast<bool*>(_v) = _t->bindableLoopSupported().value(); break;
        case 27: *reinterpret_cast<bool*>(_v) = _t->bindableShuffle().value(); break;
        case 28: *reinterpret_cast<bool*>(_v) = _t->bindableShuffleSupported().value(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 12: _t->setPlaybackState(*reinterpret_cast<qs::mac::mpris::MprisPlaybackState::Enum*>(_v)); break;
        case 13: _t->setPlaying(*reinterpret_cast<bool*>(_v)); break;
        case 14: _t->setPosition(*reinterpret_cast<qreal*>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableIdentity(); break;
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableDesktopEntry(); break;
        case 3: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCanControl(); break;
        case 4: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCanPlay(); break;
        case 5: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCanPause(); break;
        case 6: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCanTogglePlaying(); break;
        case 7: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCanGoNext(); break;
        case 8: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCanGoPrevious(); break;
        case 9: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCanSeek(); break;
        case 10: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCanQuit(); break;
        case 11: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCanRaise(); break;
        case 12: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindablePlaybackState(); break;
        case 15: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindablePositionSupported(); break;
        case 16: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableLength(); break;
        case 17: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableLengthSupported(); break;
        case 18: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableMetadata(); break;
        case 19: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableTrackTitle(); break;
        case 20: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableTrackArtist(); break;
        case 21: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableTrackAlbum(); break;
        case 22: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableTrackArtUrl(); break;
        case 23: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableVolume(); break;
        case 24: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableVolumeSupported(); break;
        case 25: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableLoopState(); break;
        case 26: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableLoopSupported(); break;
        case 27: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableShuffle(); break;
        case 28: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableShuffleSupported(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::mpris::MprisPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::mpris::MprisPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac5mpris11MprisPlayerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::mpris::MprisPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 37;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::mpris::MprisPlayer::trackChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::mpris::MprisPlayer::identityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::mac::mpris::MprisPlayer::desktopEntryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::mac::mpris::MprisPlayer::canControlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qs::mac::mpris::MprisPlayer::canPlayChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void qs::mac::mpris::MprisPlayer::canPauseChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void qs::mac::mpris::MprisPlayer::canTogglePlayingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void qs::mac::mpris::MprisPlayer::canGoNextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void qs::mac::mpris::MprisPlayer::canGoPreviousChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void qs::mac::mpris::MprisPlayer::canSeekChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void qs::mac::mpris::MprisPlayer::canQuitChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void qs::mac::mpris::MprisPlayer::canRaiseChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void qs::mac::mpris::MprisPlayer::playbackStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void qs::mac::mpris::MprisPlayer::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void qs::mac::mpris::MprisPlayer::positionSupportedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void qs::mac::mpris::MprisPlayer::lengthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void qs::mac::mpris::MprisPlayer::lengthSupportedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void qs::mac::mpris::MprisPlayer::metadataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void qs::mac::mpris::MprisPlayer::trackTitleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void qs::mac::mpris::MprisPlayer::trackArtistChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void qs::mac::mpris::MprisPlayer::trackAlbumChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void qs::mac::mpris::MprisPlayer::trackArtUrlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void qs::mac::mpris::MprisPlayer::volumeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}

// SIGNAL 23
void qs::mac::mpris::MprisPlayer::volumeSupportedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}

// SIGNAL 24
void qs::mac::mpris::MprisPlayer::loopStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void qs::mac::mpris::MprisPlayer::loopSupportedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void qs::mac::mpris::MprisPlayer::shuffleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}

// SIGNAL 27
void qs::mac::mpris::MprisPlayer::shuffleSupportedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 27, nullptr);
}
QT_WARNING_POP
