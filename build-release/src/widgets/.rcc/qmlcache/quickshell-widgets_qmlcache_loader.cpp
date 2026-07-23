#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>
#include <QtCore/qhash.h>
#include <QtCore/qstring.h>

namespace QmlCacheGeneratedCode {
namespace _qt_qml_Quickshell_Widgets_IconImage_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_Quickshell_Widgets_ClippingRectangle_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_Quickshell_Widgets_WrapperItem_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_Quickshell_Widgets_WrapperMouseArea_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_Quickshell_Widgets_WrapperRectangle_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_Quickshell_Widgets_ClippingWrapperRectangle_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_Quickshell_Widgets_ClippingWrapperRectangleInternal_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/Quickshell/Widgets/IconImage.qml"), &QmlCacheGeneratedCode::_qt_qml_Quickshell_Widgets_IconImage_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/Quickshell/Widgets/ClippingRectangle.qml"), &QmlCacheGeneratedCode::_qt_qml_Quickshell_Widgets_ClippingRectangle_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/Quickshell/Widgets/WrapperItem.qml"), &QmlCacheGeneratedCode::_qt_qml_Quickshell_Widgets_WrapperItem_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/Quickshell/Widgets/WrapperMouseArea.qml"), &QmlCacheGeneratedCode::_qt_qml_Quickshell_Widgets_WrapperMouseArea_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/Quickshell/Widgets/WrapperRectangle.qml"), &QmlCacheGeneratedCode::_qt_qml_Quickshell_Widgets_WrapperRectangle_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/Quickshell/Widgets/ClippingWrapperRectangle.qml"), &QmlCacheGeneratedCode::_qt_qml_Quickshell_Widgets_ClippingWrapperRectangle_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/Quickshell/Widgets/ClippingWrapperRectangleInternal.qml"), &QmlCacheGeneratedCode::_qt_qml_Quickshell_Widgets_ClippingWrapperRectangleInternal_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.structVersion = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qmlcache_quickshell_widgets)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qmlcache_quickshell_widgets))
int QT_MANGLE_NAMESPACE(qCleanupResources_qmlcache_quickshell_widgets)() {
    return 1;
}
