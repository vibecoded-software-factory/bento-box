qt_add_library(quickshell-mac STATIC
	panel_window.cpp
	compositor.cpp
	bridge.mm
	desktop.mm
)

qt_add_qml_module(quickshell-mac
	URI Quickshell.Mac
	VERSION 0.1
	DEPENDENCIES QtQuick
)

install_qml_module(quickshell-mac)

add_library(quickshell-mac-init OBJECT init.cpp)

# QuartzCore: the background blur masks its NSVisualEffectView with a
# CAShapeLayer built from the blur region (bridge.mm).
target_link_libraries(quickshell-mac PRIVATE Qt::Quick "-framework AppKit" "-framework QuartzCore")
target_link_libraries(quickshell-mac-init PRIVATE Qt::Quick Qt::Qml quickshell-mac-wayland)

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

# Quickshell.Services.Notifications on macOS: an API-compatible stub. macOS has
# no public way to receive other apps' notifications, so the tracked list is
# always empty.
add_subdirectory(notifications)

# Quickshell.Wayland shim: shells reach for wlroots layer-shell directly
# (WlrLayershell attached object); on macOS it forwards onto the AppKit
# PanelWindow. WlSessionLock is inert (the system owns the lock screen).
add_subdirectory(wayland)

# Quickshell.Hyprland stub: multi-compositor shells import it unconditionally;
# inert on macOS, where nigiri is the compositor (see Quickshell.Nigiri).
add_subdirectory(hyprland)

# Multi-compositor / Linux-auth module stubs DMS imports unconditionally, inert
# on macOS: sway/i3 IPC, toplevel window sets, PAM and polkit.
add_subdirectory(i3)
add_subdirectory(pam)
add_subdirectory(polkit)
