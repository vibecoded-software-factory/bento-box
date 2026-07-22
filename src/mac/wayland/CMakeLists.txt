qt_add_library(quickshell-mac-wayland STATIC
	wayland.cpp
)

qt_add_qml_module(quickshell-mac-wayland
	URI Quickshell.Wayland
	VERSION 0.1
	DEPENDENCIES QtQuick
)

install_qml_module(quickshell-mac-wayland)

target_link_libraries(quickshell-mac-wayland PRIVATE Qt::Quick)

target_link_libraries(quickshell PRIVATE quickshell-mac-waylandplugin)
