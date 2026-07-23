/****************************************************************************
** Meta object code from reading C++ file 'screenprojection.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/windowmanager/screenprojection.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'screenprojection.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs2wm16ScreenProjectionE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::wm::ScreenProjection::qt_create_metaobjectdata<qt_meta_tag_ZN2qs2wm16ScreenProjectionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::wm::ScreenProjection",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        ""
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<ScreenProjection, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::wm::ScreenProjection::staticMetaObject = { {
    QMetaObject::SuperData::link<WindowsetProjection::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2wm16ScreenProjectionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2wm16ScreenProjectionE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs2wm16ScreenProjectionE_t>.metaTypes,
    nullptr
} };

void qs::wm::ScreenProjection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ScreenProjection *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *qs::wm::ScreenProjection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::wm::ScreenProjection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2wm16ScreenProjectionE_t>.strings))
        return static_cast<void*>(this);
    return WindowsetProjection::qt_metacast(_clname);
}

int qs::wm::ScreenProjection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WindowsetProjection::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
