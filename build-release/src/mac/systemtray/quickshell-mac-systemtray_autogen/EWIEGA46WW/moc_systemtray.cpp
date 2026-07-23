/****************************************************************************
** Meta object code from reading C++ file 'systemtray.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/mac/systemtray/systemtray.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'systemtray.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs3mac10systemtray14SystemTrayItemE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::systemtray::SystemTrayItem::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac10systemtray14SystemTrayItemE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::systemtray::SystemTrayItem",
        "QML.Element",
        "SystemTrayItem",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "SystemTrayItems can only be acquired from SystemTray",
        "activate",
        "",
        "secondaryActivate",
        "scroll",
        "delta",
        "horizontal",
        "display",
        "parentWindow",
        "relativeX",
        "relativeY",
        "id",
        "title",
        "status",
        "qs::mac::systemtray::Status::Enum",
        "category",
        "qs::mac::systemtray::Category::Enum",
        "icon",
        "tooltipTitle",
        "tooltipDescription",
        "hasMenu",
        "onlyMenu",
        "menu"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'activate'
        QtMocHelpers::MethodData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'secondaryActivate'
        QtMocHelpers::MethodData<void()>(9, 8, QMC::AccessPublic, QMetaType::Void),
        // Method 'scroll'
        QtMocHelpers::MethodData<void(qint32, bool) const>(10, 8, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 11 }, { QMetaType::Bool, 12 },
        }}),
        // Method 'display'
        QtMocHelpers::MethodData<void(QObject *, qint32, qint32)>(13, 8, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 14 }, { QMetaType::Int, 15 }, { QMetaType::Int, 16 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'id'
        QtMocHelpers::PropertyData<QString>(17, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'title'
        QtMocHelpers::PropertyData<QString>(18, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'status'
        QtMocHelpers::PropertyData<qs::mac::systemtray::Status::Enum>(19, 0x80000000 | 20, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'category'
        QtMocHelpers::PropertyData<qs::mac::systemtray::Category::Enum>(21, 0x80000000 | 22, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'icon'
        QtMocHelpers::PropertyData<QString>(23, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'tooltipTitle'
        QtMocHelpers::PropertyData<QString>(24, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'tooltipDescription'
        QtMocHelpers::PropertyData<QString>(25, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'hasMenu'
        QtMocHelpers::PropertyData<bool>(26, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'onlyMenu'
        QtMocHelpers::PropertyData<bool>(27, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'menu'
        QtMocHelpers::PropertyData<QObject*>(28, QMetaType::QObjectStar, QMC::DefaultPropertyFlags | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<SystemTrayItem, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN2qs3mac10systemtray14SystemTrayItemE[] = {
    QMetaObject::SuperData::link<qs::mac::systemtray::Status::staticMetaObject>(),
    QMetaObject::SuperData::link<qs::mac::systemtray::Category::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject qs::mac::systemtray::SystemTrayItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac10systemtray14SystemTrayItemE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac10systemtray14SystemTrayItemE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN2qs3mac10systemtray14SystemTrayItemE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac10systemtray14SystemTrayItemE_t>.metaTypes,
    nullptr
} };

void qs::mac::systemtray::SystemTrayItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SystemTrayItem *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->activate(); break;
        case 1: _t->secondaryActivate(); break;
        case 2: _t->scroll((*reinterpret_cast<std::add_pointer_t<qint32>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<bool>>(_a[2]))); break;
        case 3: _t->display((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qint32>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<qint32>>(_a[3]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->id(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->title(); break;
        case 2: *reinterpret_cast<qs::mac::systemtray::Status::Enum*>(_v) = _t->status(); break;
        case 3: *reinterpret_cast<qs::mac::systemtray::Category::Enum*>(_v) = _t->category(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->icon(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->tooltipTitle(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->tooltipDescription(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->hasMenu(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->onlyMenu(); break;
        case 9: *reinterpret_cast<QObject**>(_v) = _t->menu(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::systemtray::SystemTrayItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::systemtray::SystemTrayItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac10systemtray14SystemTrayItemE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::systemtray::SystemTrayItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN2qs3mac10systemtray10SystemTrayE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::systemtray::SystemTray::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac10systemtray10SystemTrayE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::systemtray::SystemTray",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "items",
        "UntypedObjectModel*"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'items'
        QtMocHelpers::PropertyData<UntypedObjectModel*>(5, 0x80000000 | 6, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<SystemTray, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::mac::systemtray::SystemTray::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac10systemtray10SystemTrayE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac10systemtray10SystemTrayE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs3mac10systemtray10SystemTrayE_t>.metaTypes,
    nullptr
} };

void qs::mac::systemtray::SystemTray::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SystemTray *>(_o);
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
        case 0: *reinterpret_cast<UntypedObjectModel**>(_v) = _t->items(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::mac::systemtray::SystemTray::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::mac::systemtray::SystemTray::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs3mac10systemtray10SystemTrayE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::mac::systemtray::SystemTray::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN2qs3mac10systemtray6StatusE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::systemtray::Status::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac10systemtray6StatusE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::systemtray::Status",
        "QML.Element",
        "auto",
        "Enum",
        "Passive",
        "Active",
        "NeedsAttention"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<Enum>(3, 3, QMC::EnumFlags{}).add({
            {    4, Enum::Passive },
            {    5, Enum::Active },
            {    6, Enum::NeedsAttention },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN2qs3mac10systemtray6StatusE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}

static constexpr auto qt_staticMetaObjectContent_ZN2qs3mac10systemtray6StatusE =
    qs::mac::systemtray::Status::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac10systemtray6StatusE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN2qs3mac10systemtray6StatusE =
    qt_staticMetaObjectContent_ZN2qs3mac10systemtray6StatusE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN2qs3mac10systemtray6StatusE =
    qt_staticMetaObjectContent_ZN2qs3mac10systemtray6StatusE.relocatingData;

Q_CONSTINIT const QMetaObject qs::mac::systemtray::Status::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN2qs3mac10systemtray6StatusE.stringdata,
    qt_staticMetaObjectStaticContent_ZN2qs3mac10systemtray6StatusE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN2qs3mac10systemtray6StatusE.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN2qs3mac10systemtray8CategoryE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::mac::systemtray::Category::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac10systemtray8CategoryE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::mac::systemtray::Category",
        "QML.Element",
        "auto",
        "Enum",
        "Hardware",
        "SystemServices",
        "ApplicationStatus",
        "Communications"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<Enum>(3, 3, QMC::EnumFlags{}).add({
            {    4, Enum::Hardware },
            {    5, Enum::SystemServices },
            {    6, Enum::ApplicationStatus },
            {    7, Enum::Communications },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN2qs3mac10systemtray8CategoryE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}

static constexpr auto qt_staticMetaObjectContent_ZN2qs3mac10systemtray8CategoryE =
    qs::mac::systemtray::Category::qt_create_metaobjectdata<qt_meta_tag_ZN2qs3mac10systemtray8CategoryE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN2qs3mac10systemtray8CategoryE =
    qt_staticMetaObjectContent_ZN2qs3mac10systemtray8CategoryE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN2qs3mac10systemtray8CategoryE =
    qt_staticMetaObjectContent_ZN2qs3mac10systemtray8CategoryE.relocatingData;

Q_CONSTINIT const QMetaObject qs::mac::systemtray::Category::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN2qs3mac10systemtray8CategoryE.stringdata,
    qt_staticMetaObjectStaticContent_ZN2qs3mac10systemtray8CategoryE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN2qs3mac10systemtray8CategoryE.metaTypes,
    nullptr
} };

QT_WARNING_POP
