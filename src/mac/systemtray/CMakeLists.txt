qt_add_library(quickshell-mac-systemtray STATIC
	systemtray.cpp
)

qt_add_qml_module(quickshell-mac-systemtray
	URI Quickshell.Services.SystemTray
	VERSION 0.1
	DEPENDENCIES QtQuick
)

install_qml_module(quickshell-mac-systemtray)

target_link_libraries(quickshell-mac-systemtray PRIVATE Qt::Quick)

target_link_libraries(quickshell PRIVATE quickshell-mac-systemtrayplugin)
