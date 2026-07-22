qt_add_library(quickshell-mac-notifications STATIC
	notifications.cpp
)

qt_add_qml_module(quickshell-mac-notifications
	URI Quickshell.Services.Notifications
	VERSION 0.1
	DEPENDENCIES QtQuick
)

install_qml_module(quickshell-mac-notifications)

target_link_libraries(quickshell-mac-notifications PRIVATE Qt::Quick)

target_link_libraries(quickshell PRIVATE quickshell-mac-notificationsplugin)
