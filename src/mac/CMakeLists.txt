qt_add_library(quickshell-mac STATIC
	panel_window.cpp
	compositor.cpp
	bridge.mm
)

qt_add_qml_module(quickshell-mac
	URI Quickshell.Mac
	VERSION 0.1
	DEPENDENCIES QtQuick
)

install_qml_module(quickshell-mac)

add_library(quickshell-mac-init OBJECT init.cpp)

target_link_libraries(quickshell-mac PRIVATE Qt::Quick "-framework AppKit")
target_link_libraries(quickshell-mac-init PRIVATE Qt::Quick Qt::Qml)

# No qs_module_pch here: the shared "large" PCH is C++-only, and this target has
# an Objective-C++ translation unit (bridge.mm) whose PCH variant does not
# exist. The module is small enough that skipping the PCH costs nothing.

target_link_libraries(quickshell PRIVATE quickshell-macplugin quickshell-mac-init)

# The nigiri integration module (Quickshell.Nigiri): the macOS compositor
# integration, in the place Quickshell.Hyprland occupies on Linux.
add_subdirectory(nigiri)

# Quickshell.Services.Mpris on macOS, backed by MediaRemote through an entitled
# perl-hosted compiled adapter (the D-Bus MPRIS service is Linux-only).
add_subdirectory(mpris)

# Quickshell.Services.UPower on macOS, backed by IOKit power sources (the D-Bus
# UPower service is Linux-only).
add_subdirectory(upower)

# Quickshell.Services.Pipewire on macOS, backed by CoreAudio (the real Pipewire
# service is Linux-only). Audio nodes + volumes only; no link graph.
add_subdirectory(pipewire)

# Quickshell.Services.SystemTray on macOS: an API-compatible stub. macOS has no
# public way to enumerate other apps' tray items, so items is always empty.
add_subdirectory(systemtray)

# Quickshell.Bluetooth on macOS, backed by IOBluetooth (the BlueZ service is
# Linux-only). Paired devices, connection state and adapter power.
add_subdirectory(bluetooth)
