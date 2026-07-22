qt_add_library(quickshell-mac-upower STATIC
	device.cpp
	service.cpp
)

qt_add_qml_module(quickshell-mac-upower
	URI Quickshell.Services.UPower
	VERSION 0.1
	DEPENDENCIES QtQuick
)

install_qml_module(quickshell-mac-upower)

# IOKit power sources (battery) + CoreFoundation for the dictionaries.
target_link_libraries(quickshell-mac-upower PRIVATE
	Qt::Quick
	"-framework IOKit"
	"-framework CoreFoundation"
)

target_link_libraries(quickshell PRIVATE quickshell-mac-upowerplugin)
