/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<player.hpp>)
#  include <player.hpp>
#endif
#if __has_include(<service.hpp>)
#  include <service.hpp>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_Quickshell_Services_Mpris()
{
    qmlRegisterModule("Quickshell.Services.Mpris", 0, 0);
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<qs::mac::mpris::MprisLoopState>("Quickshell.Services.Mpris", 0);
    qmlRegisterEnum<qs::mac::mpris::MprisLoopState::Enum>("qs::mac::mpris::MprisLoopState::Enum");
    qmlRegisterTypesAndRevisions<qs::mac::mpris::MprisPlaybackState>("Quickshell.Services.Mpris", 0);
    qmlRegisterEnum<qs::mac::mpris::MprisPlaybackState::Enum>("qs::mac::mpris::MprisPlaybackState::Enum");
    qmlRegisterTypesAndRevisions<qs::mac::mpris::MprisPlayer>("Quickshell.Services.Mpris", 0);
    qmlRegisterTypesAndRevisions<qs::mac::mpris::MprisQml>("Quickshell.Services.Mpris", 0);
    QT_WARNING_POP
    qmlRegisterModule("Quickshell.Services.Mpris", 0, 1);
}

static const QQmlModuleRegistration quickshellServicesMprisRegistration("Quickshell.Services.Mpris", qml_register_types_Quickshell_Services_Mpris);
