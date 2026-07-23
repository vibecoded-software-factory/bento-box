/****************************************************************************
** Meta object code from reading C++ file 'model.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/model.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'model.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18UntypedObjectModelE_t {};
} // unnamed namespace

template <> constexpr inline auto UntypedObjectModel::qt_create_metaobjectdata<qt_meta_tag_ZN18UntypedObjectModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "UntypedObjectModel",
        "QML.Element",
        "ObjectModel",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "ObjectModels cannot be created directly.",
        "valuesChanged",
        "",
        "objectInsertedPre",
        "object",
        "qsizetype",
        "index",
        "objectInsertedPost",
        "objectRemovedPre",
        "objectRemovedPost",
        "indexOf",
        "values",
        "QList<QObject*>"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'valuesChanged'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'objectInsertedPre'
        QtMocHelpers::SignalData<void(QObject *, qsizetype)>(9, 8, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Signal 'objectInsertedPost'
        QtMocHelpers::SignalData<void(QObject *, qsizetype)>(13, 8, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Signal 'objectRemovedPre'
        QtMocHelpers::SignalData<void(QObject *, qsizetype)>(14, 8, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Signal 'objectRemovedPost'
        QtMocHelpers::SignalData<void(QObject *, qsizetype)>(15, 8, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Method 'indexOf'
        QtMocHelpers::MethodData<qsizetype(QObject *) const>(16, 8, QMC::AccessPublic, 0x80000000 | 11, {{
            { QMetaType::QObjectStar, 10 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'values'
        QtMocHelpers::PropertyData<QList<QObject*>>(17, 0x80000000 | 18, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<UntypedObjectModel, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject UntypedObjectModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18UntypedObjectModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18UntypedObjectModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18UntypedObjectModelE_t>.metaTypes,
    nullptr
} };

void UntypedObjectModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<UntypedObjectModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->valuesChanged(); break;
        case 1: _t->objectInsertedPre((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qsizetype>>(_a[2]))); break;
        case 2: _t->objectInsertedPost((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qsizetype>>(_a[2]))); break;
        case 3: _t->objectRemovedPre((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qsizetype>>(_a[2]))); break;
        case 4: _t->objectRemovedPost((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qsizetype>>(_a[2]))); break;
        case 5: { qsizetype _r = _t->indexOf((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<qsizetype*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (UntypedObjectModel::*)()>(_a, &UntypedObjectModel::valuesChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (UntypedObjectModel::*)(QObject * , qsizetype )>(_a, &UntypedObjectModel::objectInsertedPre, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (UntypedObjectModel::*)(QObject * , qsizetype )>(_a, &UntypedObjectModel::objectInsertedPost, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (UntypedObjectModel::*)(QObject * , qsizetype )>(_a, &UntypedObjectModel::objectRemovedPre, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (UntypedObjectModel::*)(QObject * , qsizetype )>(_a, &UntypedObjectModel::objectRemovedPost, 4))
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
        case 0: *reinterpret_cast<QList<QObject*>*>(_v) = _t->values(); break;
        default: break;
        }
    }
}

const QMetaObject *UntypedObjectModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UntypedObjectModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18UntypedObjectModelE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int UntypedObjectModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
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
void UntypedObjectModel::valuesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void UntypedObjectModel::objectInsertedPre(QObject * _t1, qsizetype _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void UntypedObjectModel::objectInsertedPost(QObject * _t1, qsizetype _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void UntypedObjectModel::objectRemovedPre(QObject * _t1, qsizetype _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void UntypedObjectModel::objectRemovedPost(QObject * _t1, qsizetype _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}
QT_WARNING_POP
