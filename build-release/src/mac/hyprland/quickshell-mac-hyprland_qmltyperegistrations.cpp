/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<hyprland.hpp>)
#  include <hyprland.hpp>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_Quickshell_Hyprland()
{
    qmlRegisterModule("Quickshell.Hyprland", 0, 0);
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<qs::mac::hyprland::Hyprland>("Quickshell.Hyprland", 0);
    qmlRegisterTypesAndRevisions<qs::mac::hyprland::HyprlandFocusGrab>("Quickshell.Hyprland", 0);
    qmlRegisterTypesAndRevisions<qs::mac::hyprland::HyprlandMonitor>("Quickshell.Hyprland", 0);
    qmlRegisterTypesAndRevisions<qs::mac::hyprland::HyprlandToplevel>("Quickshell.Hyprland", 0);
    qmlRegisterTypesAndRevisions<qs::mac::hyprland::HyprlandWorkspace>("Quickshell.Hyprland", 0);
    QT_WARNING_POP
    qmlRegisterModule("Quickshell.Hyprland", 0, 1);
}

static const QQmlModuleRegistration quickshellHyprlandRegistration("Quickshell.Hyprland", qml_register_types_Quickshell_Hyprland);
