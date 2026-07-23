/****************************************************************************
** Meta object code from reading C++ file 'elapsedtimer.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/elapsedtimer.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'elapsedtimer.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12ElapsedTimerE_t {};
} // unnamed namespace

template <> constexpr inline auto ElapsedTimer::qt_create_metaobjectdata<qt_meta_tag_ZN12ElapsedTimerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ElapsedTimer",
        "QML.Element",
        "auto",
        "elapsed",
        "",
        "restart",
        "elapsedMs",
        "restartMs",
        "elapsedNs",
        "restartNs"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'elapsed'
        QtMocHelpers::MethodData<qreal()>(3, 4, QMC::AccessPublic, QMetaType::QReal),
        // Method 'restart'
        QtMocHelpers::MethodData<qreal()>(5, 4, QMC::AccessPublic, QMetaType::QReal),
        // Method 'elapsedMs'
        QtMocHelpers::MethodData<qint64()>(6, 4, QMC::AccessPublic, QMetaType::LongLong),
        // Method 'restartMs'
        QtMocHelpers::MethodData<qint64()>(7, 4, QMC::AccessPublic, QMetaType::LongLong),
        // Method 'elapsedNs'
        QtMocHelpers::MethodData<qint64()>(8, 4, QMC::AccessPublic, QMetaType::LongLong),
        // Method 'restartNs'
        QtMocHelpers::MethodData<qint64()>(9, 4, QMC::AccessPublic, QMetaType::LongLong),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<ElapsedTimer, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject ElapsedTimer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ElapsedTimerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ElapsedTimerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12ElapsedTimerE_t>.metaTypes,
    nullptr
} };

void ElapsedTimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ElapsedTimer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { qreal _r = _t->elapsed();
            if (_a[0]) *reinterpret_cast<qreal*>(_a[0]) = std::move(_r); }  break;
        case 1: { qreal _r = _t->restart();
            if (_a[0]) *reinterpret_cast<qreal*>(_a[0]) = std::move(_r); }  break;
        case 2: { qint64 _r = _t->elapsedMs();
            if (_a[0]) *reinterpret_cast<qint64*>(_a[0]) = std::move(_r); }  break;
        case 3: { qint64 _r = _t->restartMs();
            if (_a[0]) *reinterpret_cast<qint64*>(_a[0]) = std::move(_r); }  break;
        case 4: { qint64 _r = _t->elapsedNs();
            if (_a[0]) *reinterpret_cast<qint64*>(_a[0]) = std::move(_r); }  break;
        case 5: { qint64 _r = _t->restartNs();
            if (_a[0]) *reinterpret_cast<qint64*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *ElapsedTimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ElapsedTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12ElapsedTimerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ElapsedTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
