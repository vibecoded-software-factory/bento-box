/****************************************************************************
** Meta object code from reading C++ file 'processcore.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/io/processcore.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processcore.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs2io7process14ProcessContextE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::io::process::ProcessContext::qt_create_metaobjectdata<qt_meta_tag_ZN2qs2io7process14ProcessContextE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::io::process::ProcessContext",
        "QML.Creatable",
        "true",
        "QML.CreationMethod",
        "structured",
        "QML.Element",
        "processContext",
        "command",
        "environment",
        "QVariantHash",
        "clearEnvironment",
        "workingDirectory",
        "unbindStdout"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'command'
        QtMocHelpers::PropertyData<QList<QString>>(7, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'environment'
        QtMocHelpers::PropertyData<QVariantHash>(8, 0x80000000 | 9, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'clearEnvironment'
        QtMocHelpers::PropertyData<bool>(10, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'workingDirectory'
        QtMocHelpers::PropertyData<QString>(11, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'unbindStdout'
        QtMocHelpers::PropertyData<bool>(12, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
            {    5,    6 },
    });
    return QtMocHelpers::metaObjectData<ProcessContext, void>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::io::process::ProcessContext::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io7process14ProcessContextE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io7process14ProcessContextE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs2io7process14ProcessContextE_t>.metaTypes,
    nullptr
} };

void qs::io::process::ProcessContext::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<ProcessContext *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QList<QString>*>(_v) = _t->command; break;
        case 1: *reinterpret_cast<QVariantHash*>(_v) = _t->environment; break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->clearEnvironment; break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->workingDirectory; break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->unbindStdout; break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCommand(*reinterpret_cast<QList<QString>*>(_v)); break;
        case 1: _t->setEnvironment(*reinterpret_cast<QVariantHash*>(_v)); break;
        case 2: _t->setClearEnvironment(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setWorkingDirectory(*reinterpret_cast<QString*>(_v)); break;
        case 4: _t->setUnbindStdout(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}
QT_WARNING_POP
