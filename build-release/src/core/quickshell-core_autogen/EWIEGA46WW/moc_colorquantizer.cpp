/****************************************************************************
** Meta object code from reading C++ file 'colorquantizer.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/core/colorquantizer.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colorquantizer.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN23ColorQuantizerOperationE_t {};
} // unnamed namespace

template <> constexpr inline auto ColorQuantizerOperation::qt_create_metaobjectdata<qt_meta_tag_ZN23ColorQuantizerOperationE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ColorQuantizerOperation",
        "done",
        "",
        "QList<QColor>",
        "colors",
        "finished"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'done'
        QtMocHelpers::SignalData<void(QList<QColor>)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'finished'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ColorQuantizerOperation, qt_meta_tag_ZN23ColorQuantizerOperationE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ColorQuantizerOperation::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23ColorQuantizerOperationE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23ColorQuantizerOperationE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN23ColorQuantizerOperationE_t>.metaTypes,
    nullptr
} };

void ColorQuantizerOperation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ColorQuantizerOperation *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->done((*reinterpret_cast<std::add_pointer_t<QList<QColor>>>(_a[1]))); break;
        case 1: _t->finished(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ColorQuantizerOperation::*)(QList<QColor> )>(_a, &ColorQuantizerOperation::done, 0))
            return;
    }
}

const QMetaObject *ColorQuantizerOperation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorQuantizerOperation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23ColorQuantizerOperationE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QRunnable"))
        return static_cast< QRunnable*>(this);
    return QObject::qt_metacast(_clname);
}

int ColorQuantizerOperation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void ColorQuantizerOperation::done(QList<QColor> _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN14ColorQuantizerE_t {};
} // unnamed namespace

template <> constexpr inline auto ColorQuantizer::qt_create_metaobjectdata<qt_meta_tag_ZN14ColorQuantizerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ColorQuantizer",
        "QML.Element",
        "auto",
        "colorsChanged",
        "",
        "sourceChanged",
        "depthChanged",
        "imageRectChanged",
        "rescaleSizeChanged",
        "operationFinished",
        "QList<QColor>",
        "result",
        "colors",
        "source",
        "QUrl",
        "depth",
        "imageRect",
        "QRect",
        "rescaleSize"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'colorsChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sourceChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'depthChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'imageRectChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rescaleSizeChanged'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Slot 'operationFinished'
        QtMocHelpers::SlotData<void(const QList<QColor> &)>(9, 4, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'colors'
        QtMocHelpers::PropertyData<QList<QColor>>(12, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Bindable, 0),
        // property 'source'
        QtMocHelpers::PropertyData<QUrl>(13, 0x80000000 | 14, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 1),
        // property 'depth'
        QtMocHelpers::PropertyData<qreal>(15, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'imageRect'
        QtMocHelpers::PropertyData<QRect>(16, 0x80000000 | 17, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::EnumOrFlag | QMC::StdCppSet, 3),
        // property 'rescaleSize'
        QtMocHelpers::PropertyData<qreal>(18, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<ColorQuantizer, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject ColorQuantizer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14ColorQuantizerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14ColorQuantizerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14ColorQuantizerE_t>.metaTypes,
    nullptr
} };

void ColorQuantizer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ColorQuantizer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->colorsChanged(); break;
        case 1: _t->sourceChanged(); break;
        case 2: _t->depthChanged(); break;
        case 3: _t->imageRectChanged(); break;
        case 4: _t->rescaleSizeChanged(); break;
        case 5: _t->operationFinished((*reinterpret_cast<std::add_pointer_t<QList<QColor>>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ColorQuantizer::*)()>(_a, &ColorQuantizer::colorsChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ColorQuantizer::*)()>(_a, &ColorQuantizer::sourceChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ColorQuantizer::*)()>(_a, &ColorQuantizer::depthChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ColorQuantizer::*)()>(_a, &ColorQuantizer::imageRectChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ColorQuantizer::*)()>(_a, &ColorQuantizer::rescaleSizeChanged, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QList<QColor>*>(_v) = _t->bindableColors().value(); break;
        case 1: *reinterpret_cast<QUrl*>(_v) = _t->source(); break;
        case 2: *reinterpret_cast<qreal*>(_v) = _t->depth(); break;
        case 3: *reinterpret_cast<QRect*>(_v) = _t->imageRect(); break;
        case 4: *reinterpret_cast<qreal*>(_v) = _t->rescaleSize(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setSource(*reinterpret_cast<QUrl*>(_v)); break;
        case 2: _t->setDepth(*reinterpret_cast<qreal*>(_v)); break;
        case 3: _t->setImageRect(*reinterpret_cast<QRect*>(_v)); break;
        case 4: _t->setRescaleSize(*reinterpret_cast<qreal*>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 3: _t->resetImageRect(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableColors(); break;
        default: break;
        }
    }
}

const QMetaObject *ColorQuantizer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorQuantizer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14ColorQuantizerE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QQmlParserStatus"))
        return static_cast< QQmlParserStatus*>(this);
    if (!strcmp(_clname, "org.qt-project.Qt.QQmlParserStatus"))
        return static_cast< QQmlParserStatus*>(this);
    return QObject::qt_metacast(_clname);
}

int ColorQuantizer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ColorQuantizer::colorsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ColorQuantizer::sourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ColorQuantizer::depthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ColorQuantizer::imageRectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ColorQuantizer::rescaleSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
