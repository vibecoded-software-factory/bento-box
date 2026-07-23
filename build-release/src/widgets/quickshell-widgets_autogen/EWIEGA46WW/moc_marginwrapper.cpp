/****************************************************************************
** Meta object code from reading C++ file 'marginwrapper.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/marginwrapper.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'marginwrapper.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs7widgets20MarginWrapperManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::widgets::MarginWrapperManager::qt_create_metaobjectdata<qt_meta_tag_ZN2qs7widgets20MarginWrapperManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::widgets::MarginWrapperManager",
        "QML.Element",
        "auto",
        "marginChanged",
        "",
        "extraMarginChanged",
        "topMarginChanged",
        "bottomMarginChanged",
        "leftMarginChanged",
        "rightMarginChanged",
        "resizeChildChanged",
        "implicitWidthChanged",
        "implicitHeightChanged",
        "onChildImplicitWidthChanged",
        "onChildImplicitHeightChanged",
        "setWrapperImplicitWidth",
        "setWrapperImplicitHeight",
        "margin",
        "extraMargin",
        "topMargin",
        "bottomMargin",
        "leftMargin",
        "rightMargin",
        "resizeChild",
        "implicitWidth",
        "implicitHeight"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'marginChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'extraMarginChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'topMarginChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'bottomMarginChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'leftMarginChanged'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rightMarginChanged'
        QtMocHelpers::SignalData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'resizeChildChanged'
        QtMocHelpers::SignalData<void()>(10, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'implicitWidthChanged'
        QtMocHelpers::SignalData<void()>(11, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'implicitHeightChanged'
        QtMocHelpers::SignalData<void()>(12, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onChildImplicitWidthChanged'
        QtMocHelpers::SlotData<void()>(13, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onChildImplicitHeightChanged'
        QtMocHelpers::SlotData<void()>(14, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'setWrapperImplicitWidth'
        QtMocHelpers::SlotData<void()>(15, 4, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'setWrapperImplicitHeight'
        QtMocHelpers::SlotData<void()>(16, 4, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'margin'
        QtMocHelpers::PropertyData<qreal>(17, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Final | QMC::Bindable, 0),
        // property 'extraMargin'
        QtMocHelpers::PropertyData<qreal>(18, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Final | QMC::Bindable, 1),
        // property 'topMargin'
        QtMocHelpers::PropertyData<qreal>(19, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet | QMC::Final, 2),
        // property 'bottomMargin'
        QtMocHelpers::PropertyData<qreal>(20, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet | QMC::Final, 3),
        // property 'leftMargin'
        QtMocHelpers::PropertyData<qreal>(21, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet | QMC::Final, 4),
        // property 'rightMargin'
        QtMocHelpers::PropertyData<qreal>(22, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet | QMC::Final, 5),
        // property 'resizeChild'
        QtMocHelpers::PropertyData<bool>(23, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Final | QMC::Bindable, 6),
        // property 'implicitWidth'
        QtMocHelpers::PropertyData<qreal>(24, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet | QMC::Final, 7),
        // property 'implicitHeight'
        QtMocHelpers::PropertyData<qreal>(25, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet | QMC::Final, 8),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<MarginWrapperManager, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::widgets::MarginWrapperManager::staticMetaObject = { {
    QMetaObject::SuperData::link<WrapperManager::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs7widgets20MarginWrapperManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs7widgets20MarginWrapperManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs7widgets20MarginWrapperManagerE_t>.metaTypes,
    nullptr
} };

void qs::widgets::MarginWrapperManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MarginWrapperManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->marginChanged(); break;
        case 1: _t->extraMarginChanged(); break;
        case 2: _t->topMarginChanged(); break;
        case 3: _t->bottomMarginChanged(); break;
        case 4: _t->leftMarginChanged(); break;
        case 5: _t->rightMarginChanged(); break;
        case 6: _t->resizeChildChanged(); break;
        case 7: _t->implicitWidthChanged(); break;
        case 8: _t->implicitHeightChanged(); break;
        case 9: _t->onChildImplicitWidthChanged(); break;
        case 10: _t->onChildImplicitHeightChanged(); break;
        case 11: _t->setWrapperImplicitWidth(); break;
        case 12: _t->setWrapperImplicitHeight(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (MarginWrapperManager::*)()>(_a, &MarginWrapperManager::marginChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (MarginWrapperManager::*)()>(_a, &MarginWrapperManager::extraMarginChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (MarginWrapperManager::*)()>(_a, &MarginWrapperManager::topMarginChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (MarginWrapperManager::*)()>(_a, &MarginWrapperManager::bottomMarginChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (MarginWrapperManager::*)()>(_a, &MarginWrapperManager::leftMarginChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (MarginWrapperManager::*)()>(_a, &MarginWrapperManager::rightMarginChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (MarginWrapperManager::*)()>(_a, &MarginWrapperManager::resizeChildChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (MarginWrapperManager::*)()>(_a, &MarginWrapperManager::implicitWidthChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (MarginWrapperManager::*)()>(_a, &MarginWrapperManager::implicitHeightChanged, 8))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qreal*>(_v) = _t->bindableMargin().value(); break;
        case 1: *reinterpret_cast<qreal*>(_v) = _t->bindableExtraMargin().value(); break;
        case 2: *reinterpret_cast<qreal*>(_v) = _t->topMargin(); break;
        case 3: *reinterpret_cast<qreal*>(_v) = _t->bottomMargin(); break;
        case 4: *reinterpret_cast<qreal*>(_v) = _t->leftMargin(); break;
        case 5: *reinterpret_cast<qreal*>(_v) = _t->rightMargin(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->bindableResizeChild().value(); break;
        case 7: *reinterpret_cast<qreal*>(_v) = _t->implicitWidth(); break;
        case 8: *reinterpret_cast<qreal*>(_v) = _t->implicitHeight(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: {
            _t->bindableMargin().setValue(*reinterpret_cast<qreal*>(_v));
            break;
        }
        case 1: {
            _t->bindableExtraMargin().setValue(*reinterpret_cast<qreal*>(_v));
            break;
        }
        case 2: _t->setTopMargin(*reinterpret_cast<qreal*>(_v)); break;
        case 3: _t->setBottomMargin(*reinterpret_cast<qreal*>(_v)); break;
        case 4: _t->setLeftMargin(*reinterpret_cast<qreal*>(_v)); break;
        case 5: _t->setRightMargin(*reinterpret_cast<qreal*>(_v)); break;
        case 6: {
            _t->bindableResizeChild().setValue(*reinterpret_cast<bool*>(_v));
            break;
        }
        case 7: _t->setImplicitWidth(*reinterpret_cast<qreal*>(_v)); break;
        case 8: _t->setImplicitHeight(*reinterpret_cast<qreal*>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 2: _t->resetTopMargin(); break;
        case 3: _t->resetBottomMargin(); break;
        case 4: _t->resetLeftMargin(); break;
        case 5: _t->resetRightMargin(); break;
        case 7: _t->resetImplicitWidth(); break;
        case 8: _t->resetImplicitHeight(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableMargin(); break;
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableExtraMargin(); break;
        case 6: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableResizeChild(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::widgets::MarginWrapperManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::widgets::MarginWrapperManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs7widgets20MarginWrapperManagerE_t>.strings))
        return static_cast<void*>(this);
    return WrapperManager::qt_metacast(_clname);
}

int qs::widgets::MarginWrapperManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WrapperManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void qs::widgets::MarginWrapperManager::marginChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::widgets::MarginWrapperManager::extraMarginChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qs::widgets::MarginWrapperManager::topMarginChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::widgets::MarginWrapperManager::bottomMarginChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void qs::widgets::MarginWrapperManager::leftMarginChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void qs::widgets::MarginWrapperManager::rightMarginChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void qs::widgets::MarginWrapperManager::resizeChildChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void qs::widgets::MarginWrapperManager::implicitWidthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void qs::widgets::MarginWrapperManager::implicitHeightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
