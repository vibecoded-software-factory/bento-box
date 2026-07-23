/****************************************************************************
** Meta object code from reading C++ file 'notifications.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/notifications/notifications.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notifications.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs3mac13notifications19NotificationUrgencyE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::notifications::NotificationUrgency::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac13notifications19NotificationUrgencyE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::notifications::NotificationUrgency",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "toString",
        "",
        "qs::mac::notifications::NotificationUrgency::Enum",
        "value",
        "Enum",
        "Low",
        "Normal",
        "Critical"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'toString'
        QtMocHelpers::MethodData<QString(qs::mac::notifications::NotificationUrgency::Enum)>(5, 6, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 7, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<enum Enum>(9, 9, QMC::EnumFlags{}).add({
            {   10, Enum::Low },
            {   11, Enum::Normal },
            {   12, Enum::Critical },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<NotificationUrgency, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::notifications::NotificationUrgency::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac13notifications19NotificationUrgencyE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac13notifications19NotificationUrgencyE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac13notifications19NotificationUrgencyE_t>.metaTypes,
    nullptr
} };

void qs::mac::notifications::NotificationUrgency::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NotificationUrgency *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = _t->toString((*reinterpret_cast<std::add_pointer_t<qs::mac::notifications::NotificationUrgency::Enum>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *qs::mac::notifications::NotificationUrgency::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::notifications::NotificationUrgency::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac13notifications19NotificationUrgencyE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::notifications::NotificationUrgency::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_tag_ZN2qs3mac13notifications23NotificationCloseReasonE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::notifications::NotificationCloseReason::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac13notifications23NotificationCloseReasonE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::notifications::NotificationCloseReason",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "toString",
        "",
        "qs::mac::notifications::NotificationCloseReason::Enum",
        "value",
        "Enum",
        "Expired",
        "Dismissed",
        "CloseRequested"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'toString'
        QtMocHelpers::MethodData<QString(qs::mac::notifications::NotificationCloseReason::Enum)>(5, 6, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 7, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<enum Enum>(9, 9, QMC::EnumFlags{}).add({
            {   10, Enum::Expired },
            {   11, Enum::Dismissed },
            {   12, Enum::CloseRequested },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<NotificationCloseReason, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::notifications::NotificationCloseReason::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac13notifications23NotificationCloseReasonE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac13notifications23NotificationCloseReasonE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac13notifications23NotificationCloseReasonE_t>.metaTypes,
    nullptr
} };

void qs::mac::notifications::NotificationCloseReason::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NotificationCloseReason *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = _t->toString((*reinterpret_cast<std::add_pointer_t<qs::mac::notifications::NotificationCloseReason::Enum>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *qs::mac::notifications::NotificationCloseReason::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::notifications::NotificationCloseReason::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac13notifications23NotificationCloseReasonE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::notifications::NotificationCloseReason::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_tag_ZN2qs3mac13notifications18NotificationActionE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::notifications::NotificationAction::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac13notifications18NotificationActionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::notifications::NotificationAction",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "NotificationActions must be acquired from a Notification",
        "textChanged",
        "",
        "invoke",
        "identifier",
        "text"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'textChanged'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'invoke'
        QtMocHelpers::MethodData<void()>(9, 8, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'identifier'
        QtMocHelpers::PropertyData<QString>(10, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'text'
        QtMocHelpers::PropertyData<QString>(11, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<NotificationAction, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::notifications::NotificationAction::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac13notifications18NotificationActionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac13notifications18NotificationActionE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac13notifications18NotificationActionE_t>.metaTypes,
    nullptr
} };

void qs::mac::notifications::NotificationAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NotificationAction *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->textChanged(); break;
        case 1: _t->invoke(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (NotificationAction::*)()>(_a, &NotificationAction::textChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->identifier(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->text(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::notifications::NotificationAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::notifications::NotificationAction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac13notifications18NotificationActionE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::notifications::NotificationAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void qs::mac::notifications::NotificationAction::textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac13notifications12NotificationE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::notifications::Notification::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac13notifications12NotificationE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::notifications::Notification",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "Notifications must be acquired from a NotificationServer",
        "trackedChanged",
        "",
        "expireTimeoutChanged",
        "appNameChanged",
        "appIconChanged",
        "summaryChanged",
        "bodyChanged",
        "urgencyChanged",
        "actionsChanged",
        "hasActionIconsChanged",
        "residentChanged",
        "transientChanged",
        "desktopEntryChanged",
        "imageChanged",
        "hasInlineReplyChanged",
        "inlineReplyPlaceholderChanged",
        "hintsChanged",
        "expire",
        "dismiss",
        "sendInlineReply",
        "id",
        "tracked",
        "lastGeneration",
        "expireTimeout",
        "appName",
        "appIcon",
        "summary",
        "body",
        "urgency",
        "qs::mac::notifications::NotificationUrgency::Enum",
        "actions",
        "QList<qs::mac::notifications::NotificationAction*>",
        "hasActionIcons",
        "resident",
        "transient",
        "desktopEntry",
        "image",
        "hasInlineReply",
        "inlineReplyPlaceholder",
        "hints",
        "QVariantMap"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'trackedChanged'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'expireTimeoutChanged'
        QtMocHelpers::SignalData<void()>(9, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'appNameChanged'
        QtMocHelpers::SignalData<void()>(10, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'appIconChanged'
        QtMocHelpers::SignalData<void()>(11, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'summaryChanged'
        QtMocHelpers::SignalData<void()>(12, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'bodyChanged'
        QtMocHelpers::SignalData<void()>(13, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'urgencyChanged'
        QtMocHelpers::SignalData<void()>(14, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'actionsChanged'
        QtMocHelpers::SignalData<void()>(15, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'hasActionIconsChanged'
        QtMocHelpers::SignalData<void()>(16, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'residentChanged'
        QtMocHelpers::SignalData<void()>(17, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'transientChanged'
        QtMocHelpers::SignalData<void()>(18, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'desktopEntryChanged'
        QtMocHelpers::SignalData<void()>(19, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'imageChanged'
        QtMocHelpers::SignalData<void()>(20, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'hasInlineReplyChanged'
        QtMocHelpers::SignalData<void()>(21, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'inlineReplyPlaceholderChanged'
        QtMocHelpers::SignalData<void()>(22, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'hintsChanged'
        QtMocHelpers::SignalData<void()>(23, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'expire'
        QtMocHelpers::MethodData<void()>(24, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'dismiss'
        QtMocHelpers::MethodData<void()>(25, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'sendInlineReply'
        QtMocHelpers::MethodData<void(const QString &)>(26, 8, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'id'
        QtMocHelpers::PropertyData<quint32>(27, QMetaType::UInt, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'tracked'
        QtMocHelpers::PropertyData<bool>(28, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'lastGeneration'
        QtMocHelpers::PropertyData<bool>(29, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'expireTimeout'
        QtMocHelpers::PropertyData<qreal>(30, QMetaType::QReal, QMC::DefaultPropertyFlags, 1),
        // property 'appName'
        QtMocHelpers::PropertyData<QString>(31, QMetaType::QString, QMC::DefaultPropertyFlags, 2),
        // property 'appIcon'
        QtMocHelpers::PropertyData<QString>(32, QMetaType::QString, QMC::DefaultPropertyFlags, 3),
        // property 'summary'
        QtMocHelpers::PropertyData<QString>(33, QMetaType::QString, QMC::DefaultPropertyFlags, 4),
        // property 'body'
        QtMocHelpers::PropertyData<QString>(34, QMetaType::QString, QMC::DefaultPropertyFlags, 5),
        // property 'urgency'
        QtMocHelpers::PropertyData<qs::mac::notifications::NotificationUrgency::Enum>(35, 0x80000000 | 36, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 6),
        // property 'actions'
        QtMocHelpers::PropertyData<QList<qs::mac::notifications::NotificationAction*>>(37, 0x80000000 | 38, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 7),
        // property 'hasActionIcons'
        QtMocHelpers::PropertyData<bool>(39, QMetaType::Bool, QMC::DefaultPropertyFlags, 8),
        // property 'resident'
        QtMocHelpers::PropertyData<bool>(40, QMetaType::Bool, QMC::DefaultPropertyFlags, 9),
        // property 'transient'
        QtMocHelpers::PropertyData<bool>(41, QMetaType::Bool, QMC::DefaultPropertyFlags, 10),
        // property 'desktopEntry'
        QtMocHelpers::PropertyData<QString>(42, QMetaType::QString, QMC::DefaultPropertyFlags, 11),
        // property 'image'
        QtMocHelpers::PropertyData<QString>(43, QMetaType::QString, QMC::DefaultPropertyFlags, 12),
        // property 'hasInlineReply'
        QtMocHelpers::PropertyData<bool>(44, QMetaType::Bool, QMC::DefaultPropertyFlags, 13),
        // property 'inlineReplyPlaceholder'
        QtMocHelpers::PropertyData<QString>(45, QMetaType::QString, QMC::DefaultPropertyFlags, 14),
        // property 'hints'
        QtMocHelpers::PropertyData<QVariantMap>(46, 0x80000000 | 47, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 15),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<Notification, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN2qs3mac13notifications12NotificationE[] = {
    QMetaObject::SuperData::link<qs::mac::notifications::NotificationUrgency::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject qs::mac::notifications::Notification::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac13notifications12NotificationE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac13notifications12NotificationE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN2qs3mac13notifications12NotificationE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac13notifications12NotificationE_t>.metaTypes,
    nullptr
} };

void qs::mac::notifications::Notification::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Notification *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->trackedChanged(); break;
        case 1: _t->expireTimeoutChanged(); break;
        case 2: _t->appNameChanged(); break;
        case 3: _t->appIconChanged(); break;
        case 4: _t->summaryChanged(); break;
        case 5: _t->bodyChanged(); break;
        case 6: _t->urgencyChanged(); break;
        case 7: _t->actionsChanged(); break;
        case 8: _t->hasActionIconsChanged(); break;
        case 9: _t->residentChanged(); break;
        case 10: _t->transientChanged(); break;
        case 11: _t->desktopEntryChanged(); break;
        case 12: _t->imageChanged(); break;
        case 13: _t->hasInlineReplyChanged(); break;
        case 14: _t->inlineReplyPlaceholderChanged(); break;
        case 15: _t->hintsChanged(); break;
        case 16: _t->expire(); break;
        case 17: _t->dismiss(); break;
        case 18: _t->sendInlineReply((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Notification::*)()>(_a, &Notification::trackedChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Notification::*)()>(_a, &Notification::expireTimeoutChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Notification::*)()>(_a, &Notification::appNameChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Notification::*)()>(_a, &Notification::appIconChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Notification::*)()>(_a, &Notification::summaryChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (Notification::*)()>(_a, &Notification::bodyChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (Notification::*)()>(_a, &Notification::urgencyChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (Notification::*)()>(_a, &Notification::actionsChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (Notification::*)()>(_a, &Notification::hasActionIconsChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (Notification::*)()>(_a, &Notification::residentChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (Notification::*)()>(_a, &Notification::transientChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (Notification::*)()>(_a, &Notification::desktopEntryChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (Notification::*)()>(_a, &Notification::imageChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (Notification::*)()>(_a, &Notification::hasInlineReplyChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (Notification::*)()>(_a, &Notification::inlineReplyPlaceholderChanged, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (Notification::*)()>(_a, &Notification::hintsChanged, 15))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<qs::mac::notifications::NotificationAction*> >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<quint32*>(_v) = _t->id(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isTracked(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isLastGeneration(); break;
        case 3: *reinterpret_cast<qreal*>(_v) = _t->expireTimeout(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->appName(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->appIcon(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->summary(); break;
        case 7: *reinterpret_cast<QString*>(_v) = _t->body(); break;
        case 8: *reinterpret_cast<qs::mac::notifications::NotificationUrgency::Enum*>(_v) = _t->urgency(); break;
        case 9: *reinterpret_cast<QList<qs::mac::notifications::NotificationAction*>*>(_v) = _t->actions(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->hasActionIcons(); break;
        case 11: *reinterpret_cast<bool*>(_v) = _t->resident(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->isTransient(); break;
        case 13: *reinterpret_cast<QString*>(_v) = _t->desktopEntry(); break;
        case 14: *reinterpret_cast<QString*>(_v) = _t->image(); break;
        case 15: *reinterpret_cast<bool*>(_v) = _t->hasInlineReply(); break;
        case 16: *reinterpret_cast<QString*>(_v) = _t->inlineReplyPlaceholder(); break;
        case 17: *reinterpret_cast<QVariantMap*>(_v) = _t->hints(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setTracked(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::notifications::Notification::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::notifications::Notification::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac13notifications12NotificationE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::notifications::Notification::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::notifications::Notification::trackedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::notifications::Notification::expireTimeoutChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::mac::notifications::Notification::appNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::mac::notifications::Notification::appIconChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qs::mac::notifications::Notification::summaryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void qs::mac::notifications::Notification::bodyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void qs::mac::notifications::Notification::urgencyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void qs::mac::notifications::Notification::actionsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void qs::mac::notifications::Notification::hasActionIconsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void qs::mac::notifications::Notification::residentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void qs::mac::notifications::Notification::transientChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void qs::mac::notifications::Notification::desktopEntryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void qs::mac::notifications::Notification::imageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void qs::mac::notifications::Notification::hasInlineReplyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void qs::mac::notifications::Notification::inlineReplyPlaceholderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void qs::mac::notifications::Notification::hintsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs3mac13notifications18NotificationServerE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::notifications::NotificationServer::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac13notifications18NotificationServerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::notifications::NotificationServer",
        "QML.Element",
        "NotificationServer",
        "notification",
        "",
        "qs::mac::notifications::Notification*",
        "keepOnReloadChanged",
        "persistenceSupportedChanged",
        "bodySupportedChanged",
        "bodyMarkupSupportedChanged",
        "bodyHyperlinksSupportedChanged",
        "bodyImagesSupportedChanged",
        "actionsSupportedChanged",
        "actionIconsSupportedChanged",
        "imageSupportedChanged",
        "inlineReplySupportedChanged",
        "trackedNotificationsChanged",
        "extraHintsChanged",
        "keepOnReload",
        "persistenceSupported",
        "bodySupported",
        "bodyMarkupSupported",
        "bodyHyperlinksSupported",
        "bodyImagesSupported",
        "actionsSupported",
        "actionIconsSupported",
        "imageSupported",
        "inlineReplySupported",
        "trackedNotifications",
        "UntypedObjectModel*",
        "extraHints"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'notification'
        QtMocHelpers::SignalData<void(qs::mac::notifications::Notification *)>(3, 4, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 3 },
        }}),
        // Signal 'keepOnReloadChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'persistenceSupportedChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'bodySupportedChanged'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'bodyMarkupSupportedChanged'
        QtMocHelpers::SignalData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'bodyHyperlinksSupportedChanged'
        QtMocHelpers::SignalData<void()>(10, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'bodyImagesSupportedChanged'
        QtMocHelpers::SignalData<void()>(11, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'actionsSupportedChanged'
        QtMocHelpers::SignalData<void()>(12, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'actionIconsSupportedChanged'
        QtMocHelpers::SignalData<void()>(13, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'imageSupportedChanged'
        QtMocHelpers::SignalData<void()>(14, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'inlineReplySupportedChanged'
        QtMocHelpers::SignalData<void()>(15, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'trackedNotificationsChanged'
        QtMocHelpers::SignalData<void()>(16, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'extraHintsChanged'
        QtMocHelpers::SignalData<void()>(17, 4, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'keepOnReload'
        QtMocHelpers::PropertyData<bool>(18, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'persistenceSupported'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'bodySupported'
        QtMocHelpers::PropertyData<bool>(20, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'bodyMarkupSupported'
        QtMocHelpers::PropertyData<bool>(21, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'bodyHyperlinksSupported'
        QtMocHelpers::PropertyData<bool>(22, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'bodyImagesSupported'
        QtMocHelpers::PropertyData<bool>(23, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'actionsSupported'
        QtMocHelpers::PropertyData<bool>(24, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'actionIconsSupported'
        QtMocHelpers::PropertyData<bool>(25, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 8),
        // property 'imageSupported'
        QtMocHelpers::PropertyData<bool>(26, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 9),
        // property 'inlineReplySupported'
        QtMocHelpers::PropertyData<bool>(27, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 10),
        // property 'trackedNotifications'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(28, 0x80000000 | 29, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 11),
        // property 'extraHints'
        QtMocHelpers::PropertyData<QList<QString>>(30, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 12),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<NotificationServer, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::notifications::NotificationServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac13notifications18NotificationServerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac13notifications18NotificationServerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac13notifications18NotificationServerE_t>.metaTypes,
    nullptr
} };

void qs::mac::notifications::NotificationServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NotificationServer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->notification((*reinterpret_cast<std::add_pointer_t<qs::mac::notifications::Notification*>>(_a[1]))); break;
        case 1: _t->keepOnReloadChanged(); break;
        case 2: _t->persistenceSupportedChanged(); break;
        case 3: _t->bodySupportedChanged(); break;
        case 4: _t->bodyMarkupSupportedChanged(); break;
        case 5: _t->bodyHyperlinksSupportedChanged(); break;
        case 6: _t->bodyImagesSupportedChanged(); break;
        case 7: _t->actionsSupportedChanged(); break;
        case 8: _t->actionIconsSupportedChanged(); break;
        case 9: _t->imageSupportedChanged(); break;
        case 10: _t->inlineReplySupportedChanged(); break;
        case 11: _t->trackedNotificationsChanged(); break;
        case 12: _t->extraHintsChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< qs::mac::notifications::Notification* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (NotificationServer::*)(qs::mac::notifications::Notification * )>(_a, &NotificationServer::notification, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotificationServer::*)()>(_a, &NotificationServer::keepOnReloadChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotificationServer::*)()>(_a, &NotificationServer::persistenceSupportedChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotificationServer::*)()>(_a, &NotificationServer::bodySupportedChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotificationServer::*)()>(_a, &NotificationServer::bodyMarkupSupportedChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotificationServer::*)()>(_a, &NotificationServer::bodyHyperlinksSupportedChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotificationServer::*)()>(_a, &NotificationServer::bodyImagesSupportedChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotificationServer::*)()>(_a, &NotificationServer::actionsSupportedChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotificationServer::*)()>(_a, &NotificationServer::actionIconsSupportedChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotificationServer::*)()>(_a, &NotificationServer::imageSupportedChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotificationServer::*)()>(_a, &NotificationServer::inlineReplySupportedChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotificationServer::*)()>(_a, &NotificationServer::trackedNotificationsChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (NotificationServer::*)()>(_a, &NotificationServer::extraHintsChanged, 12))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< UntypedObjectModel* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->keepOnReload(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->persistenceSupported(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->bodySupported(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->bodyMarkupSupported(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->bodyHyperlinksSupported(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->bodyImagesSupported(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->actionsSupported(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->actionIconsSupported(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->imageSupported(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->inlineReplySupported(); break;
        case 10: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->trackedNotifications(); break;
        case 11: *reinterpret_cast<QList<QString>*>(_v) = _t->extraHints(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setKeepOnReload(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setPersistenceSupported(*reinterpret_cast<bool*>(_v)); break;
        case 2: _t->setBodySupported(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setBodyMarkupSupported(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setBodyHyperlinksSupported(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setBodyImagesSupported(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setActionsSupported(*reinterpret_cast<bool*>(_v)); break;
        case 7: _t->setActionIconsSupported(*reinterpret_cast<bool*>(_v)); break;
        case 8: _t->setImageSupported(*reinterpret_cast<bool*>(_v)); break;
        case 9: _t->setInlineReplySupported(*reinterpret_cast<bool*>(_v)); break;
        case 11: _t->setExtraHints(*reinterpret_cast<QList<QString>*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::notifications::NotificationServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::notifications::NotificationServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac13notifications18NotificationServerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::notifications::NotificationServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::notifications::NotificationServer::notification(qs::mac::notifications::Notification * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void qs::mac::notifications::NotificationServer::keepOnReloadChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::mac::notifications::NotificationServer::persistenceSupportedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::mac::notifications::NotificationServer::bodySupportedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qs::mac::notifications::NotificationServer::bodyMarkupSupportedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void qs::mac::notifications::NotificationServer::bodyHyperlinksSupportedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void qs::mac::notifications::NotificationServer::bodyImagesSupportedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void qs::mac::notifications::NotificationServer::actionsSupportedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void qs::mac::notifications::NotificationServer::actionIconsSupportedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void qs::mac::notifications::NotificationServer::imageSupportedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void qs::mac::notifications::NotificationServer::inlineReplySupportedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void qs::mac::notifications::NotificationServer::trackedNotificationsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void qs::mac::notifications::NotificationServer::extraHintsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}
QT_WARNING_POP
