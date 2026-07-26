# MediaRemoteAdapter.framework: the compiled MediaRemote bridge, loaded at
# runtime by the entitled system perl (vendored - see the adapter's own
# CMakeLists for its origin and what was taken).
add_subdirectory(mediaremote-adapter)

qt_add_library(quickshell-mac-mpris STATIC
	player.cpp
	service.cpp
	identity.mm
)

# The perl loader for the adapter framework, embedded so it ships inside the
# binary and is extracted to a temp file at runtime.
qt_add_resources(quickshell-mac-mpris "mac-mpris-helper"
	PREFIX "/mac/mpris"
	BASE mediaremote-adapter/bin
	FILES mediaremote-adapter/bin/mediaremote-adapter.pl
)

qt_add_qml_module(quickshell-mac-mpris
	URI Quickshell.Services.Mpris
	VERSION 0.1
	DEPENDENCIES QtQuick
)

install_qml_module(quickshell-mac-mpris)

# The service needs the built framework bundle at runtime; hand it the path at
# compile time (overridable at runtime with $BENTO_MRA_FRAMEWORK). Building the
# framework is a hard dependency of the service.
add_dependencies(quickshell-mac-mpris MediaRemoteAdapter)
target_compile_definitions(quickshell-mac-mpris PRIVATE
	BENTO_MRA_FRAMEWORK_PATH="$<TARGET_BUNDLE_DIR:MediaRemoteAdapter>"
)

target_link_libraries(quickshell-mac-mpris PRIVATE
	Qt::Quick
	"-framework AppKit"
	"-framework Foundation"
)

target_link_libraries(quickshell PRIVATE quickshell-mac-mprisplugin)
