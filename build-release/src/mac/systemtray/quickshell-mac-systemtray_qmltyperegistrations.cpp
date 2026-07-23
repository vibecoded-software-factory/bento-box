/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<systemtray.hpp>)
#  include <systemtray.hpp>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_Quickshell_Services_SystemTray()
{
    qmlRegisterModule("Quickshell.Services.SystemTray", 0, 0);
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    {
        Q_CONSTINIT static auto metaType = QQmlPrivate::metaTypeForNamespace(
            [](const QtPrivate::QMetaTypeInterface *) {return &qs::mac::systemtray::Category::staticMetaObject;},
            "qs::mac::systemtray::Category");
        QMetaType(&metaType).id();
    }
    qmlRegisterNamespaceAndRevisions(&qs::mac::systemtray::Category::staticMetaObject, "Quickshell.Services.SystemTray", 0, nullptr, &qs::mac::systemtray::Category::staticMetaObject, nullptr);
    qmlRegisterEnum<qs::mac::systemtray::Category::Enum>("qs::mac::systemtray::Category::Enum");
    {
        Q_CONSTINIT static auto metaType = QQmlPrivate::metaTypeForNamespace(
            [](const QtPrivate::QMetaTypeInterface *) {return &qs::mac::systemtray::Status::staticMetaObject;},
            "qs::mac::systemtray::Status");
        QMetaType(&metaType).id();
    }
    qmlRegisterNamespaceAndRevisions(&qs::mac::systemtray::Status::staticMetaObject, "Quickshell.Services.SystemTray", 0, nullptr, &qs::mac::systemtray::Status::staticMetaObject, nullptr);
    qmlRegisterEnum<qs::mac::systemtray::Status::Enum>("qs::mac::systemtray::Status::Enum");
    qmlRegisterTypesAndRevisions<qs::mac::systemtray::SystemTray>("Quickshell.Services.SystemTray", 0);
    qmlRegisterTypesAndRevisions<qs::mac::systemtray::SystemTrayItem>("Quickshell.Services.SystemTray", 0);
    QT_WARNING_POP
    qmlRegisterModule("Quickshell.Services.SystemTray", 0, 1);
}

static const QQmlModuleRegistration quickshellServicesSystemTrayRegistration("Quickshell.Services.SystemTray", qml_register_types_Quickshell_Services_SystemTray);
