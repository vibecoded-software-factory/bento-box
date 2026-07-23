qt_add_library(quickshell-mac-bluetooth STATIC
	bluetooth.mm
)

qt_add_qml_module(quickshell-mac-bluetooth
	URI Quickshell.Bluetooth
	VERSION 0.1
	DEPENDENCIES QtQuick
)

install_qml_module(quickshell-mac-bluetooth)

# ObjC++ with ARC for the IOBluetooth bridging. No shared PCH (C++-only).
set_source_files_properties(bluetooth.mm PROPERTIES COMPILE_OPTIONS "-fobjc-arc")

target_link_libraries(quickshell-mac-bluetooth PRIVATE
	Qt::Quick
	"-framework IOBluetooth"
	"-framework IOKit"
	"-framework Foundation"
)

target_link_libraries(quickshell PRIVATE quickshell-mac-bluetoothplugin)
