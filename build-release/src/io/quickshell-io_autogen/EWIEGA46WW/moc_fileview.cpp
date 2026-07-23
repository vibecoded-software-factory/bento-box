/****************************************************************************
** Meta object code from reading C++ file 'fileview.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/io/fileview.hpp"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fileview.hpp' doesn't include <QObject>."
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
struct qt_meta_tag_ZN2qs2io13FileViewErrorE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::io::FileViewError::qt_create_metaobjectdata<qt_meta_tag_ZN2qs2io13FileViewErrorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::io::FileViewError",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "toString",
        "",
        "qs::io::FileViewError::Enum",
        "value",
        "Enum",
        "Success",
        "Unknown",
        "FileNotFound",
        "PermissionDenied",
        "NotAFile"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'toString'
        QtMocHelpers::MethodData<QString(qs::io::FileViewError::Enum)>(5, 6, QMC::AccessPublic, QMetaType::QString, {{
            { 0x80000000 | 7, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Enum'
        QtMocHelpers::EnumData<enum Enum>(9, 9, QMC::EnumFlags{}).add({
            {   10, Enum::Success },
            {   11, Enum::Unknown },
            {   12, Enum::FileNotFound },
            {   13, Enum::PermissionDenied },
            {   14, Enum::NotAFile },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<FileViewError, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::io::FileViewError::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io13FileViewErrorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io13FileViewErrorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs2io13FileViewErrorE_t>.metaTypes,
    nullptr
} };

void qs::io::FileViewError::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<FileViewError *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = _t->toString((*reinterpret_cast<std::add_pointer_t<qs::io::FileViewError::Enum>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *qs::io::FileViewError::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::io::FileViewError::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io13FileViewErrorE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::io::FileViewError::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
struct qt_meta_tag_ZN2qs2io17FileViewOperationE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::io::FileViewOperation::qt_create_metaobjectdata<qt_meta_tag_ZN2qs2io17FileViewOperationE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::io::FileViewOperation",
        "done",
        "",
        "finished"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'done'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'finished'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<FileViewOperation, qt_meta_tag_ZN2qs2io17FileViewOperationE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject qs::io::FileViewOperation::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io17FileViewOperationE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io17FileViewOperationE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs2io17FileViewOperationE_t>.metaTypes,
    nullptr
} };

void qs::io::FileViewOperation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<FileViewOperation *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->done(); break;
        case 1: _t->finished(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (FileViewOperation::*)()>(_a, &FileViewOperation::done, 0))
            return;
    }
}

const QMetaObject *qs::io::FileViewOperation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::io::FileViewOperation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io17FileViewOperationE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QRunnable"))
        return static_cast< QRunnable*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::io::FileViewOperation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void qs::io::FileViewOperation::done()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs2io8FileViewE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::io::FileView::qt_create_metaobjectdata<qt_meta_tag_ZN2qs2io8FileViewE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::io::FileView",
        "DefaultProperty",
        "adapter",
        "QML.Element",
        "FileViewInternal",
        "loaded",
        "",
        "loadFailed",
        "qs::io::FileViewError::Enum",
        "error",
        "saved",
        "saveFailed",
        "fileChanged",
        "adapterUpdated",
        "pathChanged",
        "internalTextChanged",
        "internalDataChanged",
        "textChanged",
        "dataChanged",
        "preloadChanged",
        "loadedOrAsyncChanged",
        "blockLoadingChanged",
        "blockAllReadsChanged",
        "blockWritesChanged",
        "atomicWritesChanged",
        "printErrorsChanged",
        "watchChangesChanged",
        "adapterChanged",
        "operationFinished",
        "onAdapterDestroyed",
        "waitForJob",
        "reload",
        "writeAdapter",
        "setData",
        "data",
        "setText",
        "text",
        "blockWrites",
        "atomicWrites",
        "watchChanges",
        "FileViewAdapter*",
        "__path",
        "__text",
        "__data",
        "__preload",
        "__blockLoading",
        "__blockAllReads",
        "__printErrors"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'loaded'
        QtMocHelpers::SignalData<void()>(5, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'loadFailed'
        QtMocHelpers::SignalData<void(qs::io::FileViewError::Enum)>(7, 6, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Signal 'saved'
        QtMocHelpers::SignalData<void()>(10, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'saveFailed'
        QtMocHelpers::SignalData<void(qs::io::FileViewError::Enum)>(11, 6, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Signal 'fileChanged'
        QtMocHelpers::SignalData<void()>(12, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'adapterUpdated'
        QtMocHelpers::SignalData<void()>(13, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'pathChanged'
        QtMocHelpers::SignalData<void()>(14, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'internalTextChanged'
        QtMocHelpers::SignalData<void()>(15, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'internalDataChanged'
        QtMocHelpers::SignalData<void()>(16, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'textChanged'
        QtMocHelpers::SignalData<void()>(17, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'dataChanged'
        QtMocHelpers::SignalData<void()>(18, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'preloadChanged'
        QtMocHelpers::SignalData<void()>(19, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'loadedOrAsyncChanged'
        QtMocHelpers::SignalData<void()>(20, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'blockLoadingChanged'
        QtMocHelpers::SignalData<void()>(21, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'blockAllReadsChanged'
        QtMocHelpers::SignalData<void()>(22, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'blockWritesChanged'
        QtMocHelpers::SignalData<void()>(23, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'atomicWritesChanged'
        QtMocHelpers::SignalData<void()>(24, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'printErrorsChanged'
        QtMocHelpers::SignalData<void()>(25, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'watchChangesChanged'
        QtMocHelpers::SignalData<void()>(26, 6, QMC::AccessPublic, QMetaType::Void),
        // Signal 'adapterChanged'
        QtMocHelpers::SignalData<void()>(27, 6, QMC::AccessPublic, QMetaType::Void),
        // Slot 'operationFinished'
        QtMocHelpers::SlotData<void()>(28, 6, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onAdapterDestroyed'
        QtMocHelpers::SlotData<void()>(29, 6, QMC::AccessPrivate, QMetaType::Void),
        // Method 'waitForJob'
        QtMocHelpers::MethodData<bool()>(30, 6, QMC::AccessPublic, QMetaType::Bool),
        // Method 'reload'
        QtMocHelpers::MethodData<void()>(31, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'writeAdapter'
        QtMocHelpers::MethodData<void()>(32, 6, QMC::AccessPublic, QMetaType::Void),
        // Method 'setData'
        QtMocHelpers::MethodData<void(const QByteArray &)>(33, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 34 },
        }}),
        // Method 'setText'
        QtMocHelpers::MethodData<void(const QString &)>(35, 6, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 36 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'blockWrites'
        QtMocHelpers::PropertyData<bool>(37, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 15),
        // property 'atomicWrites'
        QtMocHelpers::PropertyData<bool>(38, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 16),
        // property 'watchChanges'
        QtMocHelpers::PropertyData<bool>(39, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 18),
        // property 'adapter'
        QtMocHelpers::PropertyData<FileViewAdapter*>(2, 0x80000000 | 40, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 19),
        // property '__path'
        QtMocHelpers::PropertyData<QString>(41, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable, 6),
        // property '__text'
        QtMocHelpers::PropertyData<QString>(42, QMetaType::QString, QMC::DefaultPropertyFlags, 7),
        // property '__data'
        QtMocHelpers::PropertyData<QByteArray>(43, QMetaType::QByteArray, QMC::DefaultPropertyFlags, 8),
        // property '__preload'
        QtMocHelpers::PropertyData<bool>(44, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable, 11),
        // property 'loaded'
        QtMocHelpers::PropertyData<bool>(5, QMetaType::Bool, QMC::DefaultPropertyFlags, 12),
        // property '__blockLoading'
        QtMocHelpers::PropertyData<bool>(45, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable, 13),
        // property '__blockAllReads'
        QtMocHelpers::PropertyData<bool>(46, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable, 14),
        // property '__printErrors'
        QtMocHelpers::PropertyData<bool>(47, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 17),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<FileView, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::io::FileView::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io8FileViewE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io8FileViewE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs2io8FileViewE_t>.metaTypes,
    nullptr
} };

void qs::io::FileView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<FileView *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->loaded(); break;
        case 1: _t->loadFailed((*reinterpret_cast<std::add_pointer_t<qs::io::FileViewError::Enum>>(_a[1]))); break;
        case 2: _t->saved(); break;
        case 3: _t->saveFailed((*reinterpret_cast<std::add_pointer_t<qs::io::FileViewError::Enum>>(_a[1]))); break;
        case 4: _t->fileChanged(); break;
        case 5: _t->adapterUpdated(); break;
        case 6: _t->pathChanged(); break;
        case 7: _t->internalTextChanged(); break;
        case 8: _t->internalDataChanged(); break;
        case 9: _t->textChanged(); break;
        case 10: _t->dataChanged(); break;
        case 11: _t->preloadChanged(); break;
        case 12: _t->loadedOrAsyncChanged(); break;
        case 13: _t->blockLoadingChanged(); break;
        case 14: _t->blockAllReadsChanged(); break;
        case 15: _t->blockWritesChanged(); break;
        case 16: _t->atomicWritesChanged(); break;
        case 17: _t->printErrorsChanged(); break;
        case 18: _t->watchChangesChanged(); break;
        case 19: _t->adapterChanged(); break;
        case 20: _t->operationFinished(); break;
        case 21: _t->onAdapterDestroyed(); break;
        case 22: { bool _r = _t->waitForJob();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->reload(); break;
        case 24: _t->writeAdapter(); break;
        case 25: _t->setData((*reinterpret_cast<std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 26: _t->setText((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::loaded, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)(qs::io::FileViewError::Enum )>(_a, &FileView::loadFailed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::saved, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)(qs::io::FileViewError::Enum )>(_a, &FileView::saveFailed, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::fileChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::adapterUpdated, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::pathChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::internalTextChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::internalDataChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::textChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::dataChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::preloadChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::loadedOrAsyncChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::blockLoadingChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::blockAllReadsChanged, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::blockWritesChanged, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::atomicWritesChanged, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::printErrorsChanged, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::watchChangesChanged, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (FileView::*)()>(_a, &FileView::adapterChanged, 19))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FileViewAdapter* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->bindableBlockWrites().value(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->bindableAtomicWrites().value(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->bindableWatchChanges().value(); break;
        case 3: *reinterpret_cast<FileViewAdapter**>(_v) = _t->adapter(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->path(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->text(); break;
        case 6: *reinterpret_cast<QByteArray*>(_v) = _t->data(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->shouldPreload(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->isLoadedOrAsync(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->blockLoading(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->blockAllReads(); break;
        case 11: *reinterpret_cast<bool*>(_v) = _t->bindablePrintErrors().value(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: {
            _t->bindableBlockWrites().setValue(*reinterpret_cast<bool*>(_v));
            break;
        }
        case 1: {
            _t->bindableAtomicWrites().setValue(*reinterpret_cast<bool*>(_v));
            break;
        }
        case 2: {
            _t->bindableWatchChanges().setValue(*reinterpret_cast<bool*>(_v));
            break;
        }
        case 3: _t->setAdapter(*reinterpret_cast<FileViewAdapter**>(_v)); break;
        case 4: _t->setPath(*reinterpret_cast<QString*>(_v)); break;
        case 7: _t->setPreload(*reinterpret_cast<bool*>(_v)); break;
        case 9: _t->setBlockLoading(*reinterpret_cast<bool*>(_v)); break;
        case 10: _t->setBlockAllReads(*reinterpret_cast<bool*>(_v)); break;
        case 11: {
            _t->bindablePrintErrors().setValue(*reinterpret_cast<bool*>(_v));
            break;
        }
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableBlockWrites(); break;
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableAtomicWrites(); break;
        case 2: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableWatchChanges(); break;
        case 11: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindablePrintErrors(); break;
        default: break;
        }
    }
}

const QMetaObject *qs::io::FileView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::io::FileView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io8FileViewE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::io::FileView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 27;
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
void qs::io::FileView::loaded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qs::io::FileView::loadFailed(qs::io::FileViewError::Enum _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void qs::io::FileView::saved()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void qs::io::FileView::saveFailed(qs::io::FileViewError::Enum _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void qs::io::FileView::fileChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void qs::io::FileView::adapterUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void qs::io::FileView::pathChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void qs::io::FileView::internalTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void qs::io::FileView::internalDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void qs::io::FileView::textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void qs::io::FileView::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void qs::io::FileView::preloadChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void qs::io::FileView::loadedOrAsyncChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void qs::io::FileView::blockLoadingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void qs::io::FileView::blockAllReadsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void qs::io::FileView::blockWritesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void qs::io::FileView::atomicWritesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void qs::io::FileView::printErrorsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void qs::io::FileView::watchChangesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void qs::io::FileView::adapterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}
namespace {
struct qt_meta_tag_ZN2qs2io15FileViewAdapterE_t {};
} // unnamed namespace

template <> constexpr inline auto qs::io::FileViewAdapter::qt_create_metaobjectdata<qt_meta_tag_ZN2qs2io15FileViewAdapterE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qs::io::FileViewAdapter",
        "QML.Element",
        "auto",
        "QML.Creatable",
        "false",
        "QML.UncreatableReason",
        "",
        "adapterUpdated",
        "onDataChanged"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'adapterUpdated'
        QtMocHelpers::SignalData<void()>(7, 6, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onDataChanged'
        QtMocHelpers::SlotData<void()>(8, 6, QMC::AccessPrivate, QMetaType::Void),
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
    return QtMocHelpers::metaObjectData<FileViewAdapter, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject qs::io::FileViewAdapter::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io15FileViewAdapterE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io15FileViewAdapterE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2qs2io15FileViewAdapterE_t>.metaTypes,
    nullptr
} };

void qs::io::FileViewAdapter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<FileViewAdapter *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->adapterUpdated(); break;
        case 1: _t->onDataChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (FileViewAdapter::*)()>(_a, &FileViewAdapter::adapterUpdated, 0))
            return;
    }
}

const QMetaObject *qs::io::FileViewAdapter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qs::io::FileViewAdapter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2qs2io15FileViewAdapterE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qs::io::FileViewAdapter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void qs::io::FileViewAdapter::adapterUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
