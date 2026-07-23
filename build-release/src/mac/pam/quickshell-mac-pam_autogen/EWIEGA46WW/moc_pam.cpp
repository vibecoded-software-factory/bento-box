/****************************************************************************
** Meta object code from reading C++ file 'pam.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/pam/pam.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pam.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs3mac3pam10PamContextE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::pam::PamContext::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac3pam10PamContextE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::pam::PamContext",
        "QML.Element",
        "auto",
        "activeChanged",
        "",
        "userChanged",
        "configChanged",
        "messageChanged",
        "responseRequiredChanged",
        "completed",
        "qs::mac::pam::PamResult::Enum",
        "result",
        "pamMessage",
        "message",
        "isError",
        "responseRequired",
        "responseVisible",
        "start",
        "abort",
        "respond",
        "active",
        "user",
        "config",
        "configDirectory",
        "messageIsError"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'activeChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'userChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'configChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'messageChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'responseRequiredChanged'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'completed'
        QtMocHelpers::SignalData<void(qs::mac::pam::PamResult::Enum)>(9, 4, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
        // Signal 'pamMessage'
        QtMocHelpers::SignalData<void(const QString &, bool, bool, bool)>(12, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 13 }, { QMetaType::Bool, 14 }, { QMetaType::Bool, 15 }, { QMetaType::Bool, 16 },
        }}),
        // Method 'start'
        QtMocHelpers::MethodData<bool()>(17, 4, QMC::AccessPublic, QMetaType::Bool),
        // Method 'abort'
        QtMocHelpers::MethodData<void()>(18, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'respond'
        QtMocHelpers::MethodData<void(const QString &)>(19, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Method 'respond'
        QtMocHelpers::MethodData<void()>(19, 4, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'active'
        QtMocHelpers::PropertyData<bool>(20, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
        // property 'user'
        QtMocHelpers::PropertyData<QString>(21, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'config'
        QtMocHelpers::PropertyData<QString>(22, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'configDirectory'
        QtMocHelpers::PropertyData<QString>(23, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable, 2),
        // property 'message'
        QtMocHelpers::PropertyData<QString>(13, QMetaType::QString, QMC::DefaultPropertyFlags, 3),
        // property 'messageIsError'
        QtMocHelpers::PropertyData<bool>(24, QMetaType::Bool, QMC::DefaultPropertyFlags, 3),
        // property 'responseRequired'
        QtMocHelpers::PropertyData<bool>(15, QMetaType::Bool, QMC::DefaultPropertyFlags, 4),
        // property 'responseVisible'
        QtMocHelpers::PropertyData<bool>(16, QMetaType::Bool, QMC::DefaultPropertyFlags, 4),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<PamContext, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::pam::PamContext::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac3pam10PamContextE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac3pam10PamContextE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac3pam10PamContextE_t>.metaTypes,
    nullptr
} };

void qs::mac::pam::PamContext::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PamContext *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->activeChanged(); break;
        case 1: _t->userChanged(); break;
        case 2: _t->configChanged(); break;
        case 3: _t->messageChanged(); break;
        case 4: _t->responseRequiredChanged(); break;
        case 5: _t->completed((*reinterpret_cast<std::add_pointer_t<qs::mac::pam::PamResult::Enum>>(_a[1]))); break;
        case 6: _t->pamMessage((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[4]))); break;
        case 7: { bool _r = _t->start();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->abort(); break;
        case 9: _t->respond((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->respond(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (PamContext::*)()>(_a, &PamContext::activeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (PamContext::*)()>(_a, &PamContext::userChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (PamContext::*)()>(_a, &PamContext::configChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (PamContext::*)()>(_a, &PamContext::messageChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (PamContext::*)()>(_a, &PamContext::responseRequiredChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (PamContext::*)(qs::mac::pam::PamResult::Enum )>(_a, &PamContext::completed, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (PamContext::*)(const QString & , bool , bool , bool )>(_a, &PamContext::pamMessage, 6))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->active(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->user(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->config(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->configDir(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->message(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->messageIsError(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->responseRequired(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->responseVisible(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setUser(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setConfig(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->setConfigDir(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::pam::PamContext::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::pam::PamContext::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac3pam10PamContextE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::pam::PamContext::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void qs::mac::pam::PamContext::activeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::mac::pam::PamContext::userChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::mac::pam::PamContext::configChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::mac::pam::PamContext::messageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qs::mac::pam::PamContext::responseRequiredChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void qs::mac::pam::PamContext::completed(qs::mac::pam::PamResult::Enum _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void qs::mac::pam::PamContext::pamMessage(const QString & _t1, bool _t2, bool _t3, bool _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2, _t3, _t4);
}
namespace {
struct qt_meta_tag_ZN2qs3mac3pam9PamResultE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::pam::PamResult::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac3pam9PamResultE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::pam::PamResult",
        "QML.Element",
        "auto",
        "Enum",
        "Success",
        "Failed",
        "Error",
        "MaxTries"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<Enum>(3, 3, QMC::EnumFlags{}).add({
            {    4, Enum::Success },
            {    5, Enum::Failed },
            {    6, Enum::Error },
            {    7, Enum::MaxTries },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN2qs3mac3pam9PamResultE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}

static constexpr auto qt_staticMetaObjectContent_ZN2qs3mac3pam9PamResultE =
    qs::mac::pam::PamResult::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac3pam9PamResultE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN2qs3mac3pam9PamResultE =
    qt_staticMetaObjectContent_ZN2qs3mac3pam9PamResultE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN2qs3mac3pam9PamResultE =
    qt_staticMetaObjectContent_ZN2qs3mac3pam9PamResultE.relocatingData;

Q_CONSTINIT const QMetaObject qs::mac::pam::PamResult::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN2qs3mac3pam9PamResultE.stringdata,
    qt_staticMetaObjectStaticContent_ZN2qs3mac3pam9PamResultE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN2qs3mac3pam9PamResultE.metaTypes,
    nullptr
} };

QT_WARNING_POP
