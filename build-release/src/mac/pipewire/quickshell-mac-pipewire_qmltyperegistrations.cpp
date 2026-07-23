/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<node.hpp>)
#  include <node.hpp>
#endif
#if __has_include(<service.hpp>)
#  include <service.hpp>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_Quickshell_Services_Pipewire()
{
    qmlRegisterModule("Quickshell.Services.Pipewire", 0, 0);
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<qs::mac::pipewire::Pipewire>("Quickshell.Services.Pipewire", 0);
    qmlRegisterTypesAndRevisions<qs::mac::pipewire::PwAudioChannel>("Quickshell.Services.Pipewire", 0);
    qmlRegisterEnum<qs::mac::pipewire::PwAudioChannel::Enum>("qs::mac::pipewire::PwAudioChannel::Enum");
    qmlRegisterTypesAndRevisions<qs::mac::pipewire::PwNode>("Quickshell.Services.Pipewire", 0);
    qmlRegisterTypesAndRevisions<qs::mac::pipewire::PwNodeAudio>("Quickshell.Services.Pipewire", 0);
    qmlRegisterTypesAndRevisions<qs::mac::pipewire::PwNodeType>("Quickshell.Services.Pipewire", 0);
    qmlRegisterEnum<qs::mac::pipewire::PwNodeType::Flag>("qs::mac::pipewire::PwNodeType::Flag");
    qmlRegisterTypesAndRevisions<qs::mac::pipewire::PwObjectTracker>("Quickshell.Services.Pipewire", 0);
    QT_WARNING_POP
    qmlRegisterModule("Quickshell.Services.Pipewire", 0, 1);
}

static const QQmlModuleRegistration quickshellServicesPipewireRegistration("Quickshell.Services.Pipewire", qml_register_types_Quickshell_Services_Pipewire);
