/****************************************************************************
** Meta object code from reading C++ file 'qmlscreen.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/qmlscreen.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmlscreen.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN20QuickshellScreenInfoE_t {};
} // unnamed namespace

template <> constexpr inline auto QuickshellScreenInfo::qt_create_metaobjectdata<qt_meta_tag_ZN20QuickshellScreenInfoE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QuickshellScreenInfo",
        "QML.Element",
        "ShellScreen",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "ShellScreen can only be obtained via Quickshell.screens",
        "geometryChanged",
        "",
        "physicalPixelDensityChanged",
        "logicalPixelDensityChanged",
        "orientationChanged",
        "primaryOrientationChanged",
        "screenDestroyed",
        "toString",
        "name",
        "model",
        "serialNumber",
        "x",
        "y",
        "width",
        "height",
        "physicalPixelDensity",
        "logicalPixelDensity",
        "devicePixelRatio",
        "orientation",
        "Qt::ScreenOrientation",
        "primaryOrientation"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'geometryChanged'
        QtMocHelpers::SignalData<void()>(7, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'physicalPixelDensityChanged'
        QtMocHelpers::SignalData<void()>(9, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'logicalPixelDensityChanged'
        QtMocHelpers::SignalData<void()>(10, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'orientationChanged'
        QtMocHelpers::SignalData<void()>(11, 8, QMC::AccessPublic, QMetaType::Void),
        // Signal 'primaryOrientationChanged'
        QtMocHelpers::SignalData<void()>(12, 8, QMC::AccessPublic, QMetaType::Void),
        // Slot 'screenDestroyed'
        QtMocHelpers::SlotData<void()>(13, 8, QMC::AccessPrivate, QMetaType::Void),
        // Method 'toString'
        QtMocHelpers::MethodData<QString() const>(14, 8, QMC::AccessPublic, QMetaType::QString),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'name'
        QtMocHelpers::PropertyData<QString>(15, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'model'
        QtMocHelpers::PropertyData<QString>(16, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'serialNumber'
        QtMocHelpers::PropertyData<QString>(17, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'x'
        QtMocHelpers::PropertyData<qint32>(18, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'y'
        QtMocHelpers::PropertyData<qint32>(19, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'width'
        QtMocHelpers::PropertyData<qint32>(20, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'height'
        QtMocHelpers::PropertyData<qint32>(21, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'physicalPixelDensity'
        QtMocHelpers::PropertyData<qreal>(22, QMetaType::QReal, QMC::DefaultPropertyFlags, 1),
        // property 'logicalPixelDensity'
        QtMocHelpers::PropertyData<qreal>(23, QMetaType::QReal, QMC::DefaultPropertyFlags, 2),
        // property 'devicePixelRatio'
        QtMocHelpers::PropertyData<qreal>(24, QMetaType::QReal, QMC::DefaultPropertyFlags, 1),
        // property 'orientation'
        QtMocHelpers::PropertyData<Qt::ScreenOrientation>(25, 0x80000000 | 26, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 3),
        // property 'primaryOrientation'
        QtMocHelpers::PropertyData<Qt::ScreenOrientation>(27, 0x80000000 | 26, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 4),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<QuickshellScreenInfo, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject QuickshellScreenInfo::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QuickshellScreenInfoE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QuickshellScreenInfoE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN20QuickshellScreenInfoE_t>.metaTypes,
    nullptr
} };

void QuickshellScreenInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QuickshellScreenInfo *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->geometryChanged(); break;
        case 1: _t->physicalPixelDensityChanged(); break;
        case 2: _t->logicalPixelDensityChanged(); break;
        case 3: _t->orientationChanged(); break;
        case 4: _t->primaryOrientationChanged(); break;
        case 5: _t->screenDestroyed(); break;
        case 6: { QString _r = _t->toString();
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QuickshellScreenInfo::*)()>(_a, &QuickshellScreenInfo::geometryChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QuickshellScreenInfo::*)()>(_a, &QuickshellScreenInfo::physicalPixelDensityChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QuickshellScreenInfo::*)()>(_a, &QuickshellScreenInfo::logicalPixelDensityChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QuickshellScreenInfo::*)()>(_a, &QuickshellScreenInfo::orientationChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QuickshellScreenInfo::*)()>(_a, &QuickshellScreenInfo::primaryOrientationChanged, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->name(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->model(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->serialNumber(); break;
        case 3: *reinterpret_cast<qint32*>(_v) = _t->x(); break;
        case 4: *reinterpret_cast<qint32*>(_v) = _t->y(); break;
        case 5: *reinterpret_cast<qint32*>(_v) = _t->width(); break;
        case 6: *reinterpret_cast<qint32*>(_v) = _t->height(); break;
        case 7: *reinterpret_cast<qreal*>(_v) = _t->physicalPixelDensity(); break;
        case 8: *reinterpret_cast<qreal*>(_v) = _t->logicalPixelDensity(); break;
        case 9: *reinterpret_cast<qreal*>(_v) = _t->devicePixelRatio(); break;
        case 10: *reinterpret_cast<Qt::ScreenOrientation*>(_v) = _t->orientation(); break;
        case 11: *reinterpret_cast<Qt::ScreenOrientation*>(_v) = _t->primaryOrientation(); break;
        default: break;
        }
    }
}

const QMetaObject *QuickshellScreenInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuickshellScreenInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QuickshellScreenInfoE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QuickshellScreenInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
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
void QuickshellScreenInfo::geometryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QuickshellScreenInfo::physicalPixelDensityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QuickshellScreenInfo::logicalPixelDensityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QuickshellScreenInfo::orientationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QuickshellScreenInfo::primaryOrientationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
