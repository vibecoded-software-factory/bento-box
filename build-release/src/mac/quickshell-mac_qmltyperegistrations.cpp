/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<desktop.hpp>)
#  include <desktop.hpp>
#endif
#if __has_include(<panel_window.hpp>)
#  include <panel_window.hpp>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_Quickshell_Mac()
{
    qmlRegisterModule("Quickshell.Mac", 0, 0);
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<qs::mac::MacDesktop>("Quickshell.Mac", 0);
    qmlRegisterTypesAndRevisions<qs::mac::MacPanelWindow>("Quickshell.Mac", 0);
    QT_WARNING_POP
    qmlRegisterModule("Quickshell.Mac", 0, 1);
}

static const QQmlModuleRegistration quickshellMacRegistration("Quickshell.Mac", qml_register_types_Quickshell_Mac);
