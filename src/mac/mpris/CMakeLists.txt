qt_add_library(quickshell-mac-mpris STATIC
	player.cpp
	service.cpp
)

# The entitled osascript helper, embedded so it ships inside the binary and is
# extracted to a temp file at runtime.
qt_add_resources(quickshell-mac-mpris "mac-mpris-helper"
	PREFIX "/mac/mpris"
	FILES nowplaying.js
)

qt_add_qml_module(quickshell-mac-mpris
	URI Quickshell.Services.Mpris
	VERSION 0.1
	DEPENDENCIES QtQuick
)

install_qml_module(quickshell-mac-mpris)

target_link_libraries(quickshell-mac-mpris PRIVATE Qt::Quick)

target_link_libraries(quickshell PRIVATE quickshell-mac-mprisplugin)
