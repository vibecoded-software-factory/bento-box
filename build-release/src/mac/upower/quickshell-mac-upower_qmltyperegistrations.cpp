/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<device.hpp>)
#  include <device.hpp>
#endif
#if __has_include(<service.hpp>)
#  include <service.hpp>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_Quickshell_Services_UPower()
{
    qmlRegisterModule("Quickshell.Services.UPower", 0, 0);
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<qs::mac::upower::UPowerDevice>("Quickshell.Services.UPower", 0);
    qmlRegisterTypesAndRevisions<qs::mac::upower::UPowerDeviceState>("Quickshell.Services.UPower", 0);
    qmlRegisterEnum<qs::mac::upower::UPowerDeviceState::Enum>("qs::mac::upower::UPowerDeviceState::Enum");
    qmlRegisterTypesAndRevisions<qs::mac::upower::UPowerDeviceType>("Quickshell.Services.UPower", 0);
    qmlRegisterEnum<qs::mac::upower::UPowerDeviceType::Enum>("qs::mac::upower::UPowerDeviceType::Enum");
    qmlRegisterTypesAndRevisions<qs::mac::upower::UPowerQml>("Quickshell.Services.UPower", 0);
    QT_WARNING_POP
    qmlRegisterModule("Quickshell.Services.UPower", 0, 1);
}

static const QQmlModuleRegistration quickshellServicesUPowerRegistration("Quickshell.Services.UPower", qml_register_types_Quickshell_Services_UPower);
