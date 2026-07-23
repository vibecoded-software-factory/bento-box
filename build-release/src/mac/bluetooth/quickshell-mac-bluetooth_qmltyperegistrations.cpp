/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<bluetooth.hpp>)
#  include <bluetooth.hpp>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_Quickshell_Bluetooth()
{
    qmlRegisterModule("Quickshell.Bluetooth", 0, 0);
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<qs::mac::bluetooth::Bluetooth>("Quickshell.Bluetooth", 0);
    qmlRegisterTypesAndRevisions<qs::mac::bluetooth::BluetoothAdapter>("Quickshell.Bluetooth", 0);
    qmlRegisterTypesAndRevisions<qs::mac::bluetooth::BluetoothAdapterState>("Quickshell.Bluetooth", 0);
    qmlRegisterEnum<qs::mac::bluetooth::BluetoothAdapterState::Enum>("qs::mac::bluetooth::BluetoothAdapterState::Enum");
    qmlRegisterTypesAndRevisions<qs::mac::bluetooth::BluetoothDevice>("Quickshell.Bluetooth", 0);
    qmlRegisterTypesAndRevisions<qs::mac::bluetooth::BluetoothDeviceState>("Quickshell.Bluetooth", 0);
    qmlRegisterEnum<qs::mac::bluetooth::BluetoothDeviceState::Enum>("qs::mac::bluetooth::BluetoothDeviceState::Enum");
    QT_WARNING_POP
    qmlRegisterModule("Quickshell.Bluetooth", 0, 1);
}

static const QQmlModuleRegistration quickshellBluetoothRegistration("Quickshell.Bluetooth", qml_register_types_Quickshell_Bluetooth);
