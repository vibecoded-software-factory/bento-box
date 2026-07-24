qt_add_library(quickshell-mac-pipewire STATIC
	coreaudio.cpp
	node.cpp
	service.cpp
	link.cpp
)

qt_add_qml_module(quickshell-mac-pipewire
	URI Quickshell.Services.Pipewire
	VERSION 0.1
	DEPENDENCIES QtQuick
)

install_qml_module(quickshell-mac-pipewire)

# CoreAudio for device/volume access, CoreFoundation for the CF string values.
target_link_libraries(quickshell-mac-pipewire PRIVATE
	Qt::Quick
	"-framework CoreAudio"
	"-framework CoreFoundation"
)

target_link_libraries(quickshell PRIVATE quickshell-mac-pipewireplugin)
