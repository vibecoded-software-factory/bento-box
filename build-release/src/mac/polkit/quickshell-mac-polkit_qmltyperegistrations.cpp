/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<polkit.hpp>)
#  include <polkit.hpp>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_Quickshell_Services_Polkit()
{
    qmlRegisterModule("Quickshell.Services.Polkit", 0, 0);
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<qs::mac::polkit::Polkit>("Quickshell.Services.Polkit", 0);
    qmlRegisterTypesAndRevisions<qs::mac::polkit::PolkitAgent>("Quickshell.Services.Polkit", 0);
    QT_WARNING_POP
    qmlRegisterModule("Quickshell.Services.Polkit", 0, 1);
}

static const QQmlModuleRegistration quickshellServicesPolkitRegistration("Quickshell.Services.Polkit", qml_register_types_Quickshell_Services_Polkit);
