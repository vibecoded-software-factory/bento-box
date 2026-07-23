qt_add_library(quickshell-mac-wayland STATIC
	wayland.cpp
	toplevel.cpp
	screencopy.mm
)

qt_add_qml_module(quickshell-mac-wayland
	URI Quickshell.Wayland
	VERSION 0.1
	DEPENDENCIES QtQuick
)

install_qml_module(quickshell-mac-wayland)

# The toplevel bridge consumes the compositor IPC's window model; the
# screencopy view captures via ScreenCaptureKit.
target_link_libraries(quickshell-mac-wayland PRIVATE
	Qt::Quick
	quickshell-mac-nigiri
	"-framework ScreenCaptureKit"
	"-framework IOKit"
	"-framework CoreGraphics"
)

target_link_libraries(quickshell PRIVATE quickshell-mac-waylandplugin)
