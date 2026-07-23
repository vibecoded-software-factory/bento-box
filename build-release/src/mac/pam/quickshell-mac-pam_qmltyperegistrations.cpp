/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<pam.hpp>)
#  include <pam.hpp>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_Quickshell_Services_Pam()
{
    qmlRegisterModule("Quickshell.Services.Pam", 0, 0);
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<qs::mac::pam::PamContext>("Quickshell.Services.Pam", 0);
    {
        Q_CONSTINIT static auto metaType = QQmlPrivate::metaTypeForNamespace(
            [](const QtPrivate::QMetaTypeInterface *) {return &qs::mac::pam::PamResult::staticMetaObject;},
            "qs::mac::pam::PamResult");
        QMetaType(&metaType).id();
    }
    qmlRegisterNamespaceAndRevisions(&qs::mac::pam::PamResult::staticMetaObject, "Quickshell.Services.Pam", 0, nullptr, &qs::mac::pam::PamResult::staticMetaObject, nullptr);
    qmlRegisterEnum<qs::mac::pam::PamResult::Enum>("qs::mac::pam::PamResult::Enum");
    QT_WARNING_POP
    qmlRegisterModule("Quickshell.Services.Pam", 0, 1);
}

static const QQmlModuleRegistration quickshellServicesPamRegistration("Quickshell.Services.Pam", qml_register_types_Quickshell_Services_Pam);
