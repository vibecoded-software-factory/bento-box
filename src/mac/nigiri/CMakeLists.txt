qt_add_library(quickshell-mac-nigiri STATIC
	connection.cpp
	workspace.cpp
	window.cpp
	qml.cpp
)

qt_add_qml_module(quickshell-mac-nigiri
	URI Quickshell.Nigiri
	VERSION 0.1
	DEPENDENCIES QtQuick
)

install_qml_module(quickshell-mac-nigiri)

target_link_libraries(quickshell-mac-nigiri PRIVATE Qt::Quick Qt::Network)

target_link_libraries(quickshell PRIVATE quickshell-mac-nigiriplugin)
