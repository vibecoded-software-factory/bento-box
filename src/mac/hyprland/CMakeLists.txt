qt_add_library(quickshell-mac-hyprland STATIC hyprland.cpp)
qt_add_qml_module(quickshell-mac-hyprland
	URI Quickshell.Hyprland
	VERSION 0.1
	DEPENDENCIES QtQuick
)
install_qml_module(quickshell-mac-hyprland)
target_link_libraries(quickshell-mac-hyprland PRIVATE Qt::Quick)
target_link_libraries(quickshell PRIVATE quickshell-mac-hyprlandplugin)
