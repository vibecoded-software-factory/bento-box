/****************************************************************************
** Meta object code from reading C++ file 'qsintercept.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/qsintercept.hpp"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsintercept.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN20QsInterceptDataReplyE_t {};
} // unnamed namespace

template <> constexpr inline auto QsInterceptDataReply::qt_create_metaobjectdata<qt_meta_tag_ZN20QsInterceptDataReplyE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QsInterceptDataReply",
        "abort",
        ""
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'abort'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QsInterceptDataReply, qt_meta_tag_ZN20QsInterceptDataReplyE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QsInterceptDataReply::staticMetaObject = { {
    QMetaObject::SuperData::link<QNetworkReply::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QsInterceptDataReplyE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QsInterceptDataReplyE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN20QsInterceptDataReplyE_t>.metaTypes,
    nullptr
} };

void QsInterceptDataReply::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QsInterceptDataReply *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->abort(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *QsInterceptDataReply::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QsInterceptDataReply::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QsInterceptDataReplyE_t>.strings))
        return static_cast<void*>(this);
    return QNetworkReply::qt_metacast(_clname);
}

int QsInterceptDataReply::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNetworkReply::qt_metacall(_c, _id, _a);
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
struct qt_meta_tag_ZN31QsInterceptNetworkAccessManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto QsInterceptNetworkAccessManager::qt_create_metaobjectdata<qt_meta_tag_ZN31QsInterceptNetworkAccessManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QsInterceptNetworkAccessManager"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QsInterceptNetworkAccessManager, qt_meta_tag_ZN31QsInterceptNetworkAccessManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QsInterceptNetworkAccessManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QNetworkAccessManager::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN31QsInterceptNetworkAccessManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN31QsInterceptNetworkAccessManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN31QsInterceptNetworkAccessManagerE_t>.metaTypes,
    nullptr
} };

void QsInterceptNetworkAccessManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QsInterceptNetworkAccessManager *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QsInterceptNetworkAccessManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QsInterceptNetworkAccessManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN31QsInterceptNetworkAccessManagerE_t>.strings))
        return static_cast<void*>(this);
    return QNetworkAccessManager::qt_metacast(_clname);
}

int QsInterceptNetworkAccessManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNetworkAccessManager::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
