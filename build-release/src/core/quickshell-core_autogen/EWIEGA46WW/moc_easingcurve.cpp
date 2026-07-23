/****************************************************************************
** Meta object code from reading C++ file 'easingcurve.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/easingcurve.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'easingcurve.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11EasingCurveE_t {};
} // unnamed namespace

template <> constexpr inline auto EasingCurve::qt_create_metaobjectdata<qt_meta_tag_ZN11EasingCurveE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "EasingCurve",
        "QML.Element",
        "auto",
        "curveChanged",
        "",
        "valueAt",
        "x",
        "interpolate",
        "a",
        "b",
        "QPointF",
        "QRectF",
        "curve",
        "QEasingCurve"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'curveChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'valueAt'
        QtMocHelpers::MethodData<qreal(qreal) const>(5, 4, QMC::AccessPublic, QMetaType::QReal, {{
            { QMetaType::QReal, 6 },
        }}),
        // Method 'interpolate'
        QtMocHelpers::MethodData<qreal(qreal, qreal, qreal) const>(7, 4, QMC::AccessPublic, QMetaType::QReal, {{
            { QMetaType::QReal, 6 }, { QMetaType::QReal, 8 }, { QMetaType::QReal, 9 },
        }}),
        // Method 'interpolate'
        QtMocHelpers::MethodData<QPointF(qreal, const QPointF &, const QPointF &) const>(7, 4, QMC::AccessPublic, 0x80000000 | 10, {{
            { QMetaType::QReal, 6 }, { 0x80000000 | 10, 8 }, { 0x80000000 | 10, 9 },
        }}),
        // Method 'interpolate'
        QtMocHelpers::MethodData<QRectF(qreal, const QRectF &, const QRectF &) const>(7, 4, QMC::AccessPublic, 0x80000000 | 11, {{
            { QMetaType::QReal, 6 }, { 0x80000000 | 11, 8 }, { 0x80000000 | 11, 9 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'curve'
        QtMocHelpers::PropertyData<QEasingCurve>(12, 0x80000000 | 13, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<EasingCurve, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject EasingCurve::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11EasingCurveE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11EasingCurveE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11EasingCurveE_t>.metaTypes,
    nullptr
} };

void EasingCurve::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<EasingCurve *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->curveChanged(); break;
        case 1: { qreal _r = _t->valueAt((*reinterpret_cast<std::add_pointer_t<qreal>>(_a[1])));
            if (_a[0]) *reinterpret_cast<qreal*>(_a[0]) = std::move(_r); }  break;
        case 2: { qreal _r = _t->interpolate((*reinterpret_cast<std::add_pointer_t<qreal>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<qreal>>(_a[3])));
            if (_a[0]) *reinterpret_cast<qreal*>(_a[0]) = std::move(_r); }  break;
        case 3: { QPointF _r = _t->interpolate((*reinterpret_cast<std::add_pointer_t<qreal>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QPointF>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QPointF>>(_a[3])));
            if (_a[0]) *reinterpret_cast<QPointF*>(_a[0]) = std::move(_r); }  break;
        case 4: { QRectF _r = _t->interpolate((*reinterpret_cast<std::add_pointer_t<qreal>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QRectF>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<QRectF>>(_a[3])));
            if (_a[0]) *reinterpret_cast<QRectF*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (EasingCurve::*)()>(_a, &EasingCurve::curveChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QEasingCurve*>(_v) = _t->curve(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurve(*reinterpret_cast<QEasingCurve*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *EasingCurve::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EasingCurve::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11EasingCurveE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EasingCurve::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
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
void EasingCurve::curveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
