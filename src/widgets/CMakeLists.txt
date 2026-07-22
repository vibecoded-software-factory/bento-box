qt_add_library(quickshell-widgets STATIC
	cliprect.cpp
	wrapper.cpp
	marginwrapper.cpp
)

qt_add_qml_module(quickshell-widgets
	URI Quickshell.Widgets
	VERSION 0.1
	QML_FILES
		IconImage.qml
		ClippingRectangle.qml
		WrapperItem.qml
		WrapperMouseArea.qml
		WrapperRectangle.qml
		ClippingWrapperRectangle.qml
		ClippingWrapperRectangleInternal.qml
)

# Metal needs the MSL variant baked in: upstream disables it (Wayland/GL
# only), which left every ClippingRectangle on macOS failing pipeline
# creation on each frame ("MSL shader compilation failed") - broken visuals
# plus a per-open render hitch in any shell using it.
if(APPLE)
	set(QS_SHADER_FLAGS NOHLSL BATCHABLE PRECOMPILE OPTIMIZED QUIET)
else()
	set(QS_SHADER_FLAGS NOHLSL NOMSL BATCHABLE PRECOMPILE OPTIMIZED QUIET)
endif()

qt6_add_shaders(quickshell-widgets "widgets-cliprect"
	${QS_SHADER_FLAGS}
	PREFIX "/Quickshell/Widgets"
	FILES shaders/cliprect.frag
	OUTPUTS shaders/cliprect.frag.qsb
)

qt6_add_shaders(quickshell-widgets "widgets-cliprect-ub"
	${QS_SHADER_FLAGS}
	PREFIX "/Quickshell/Widgets"
	FILES shaders/cliprect.frag
	OUTPUTS shaders/cliprect-ub.frag.qsb
	DEFINES CONTENT_UNDER_BORDER
)

install_qml_module(quickshell-widgets)

qs_module_pch(quickshell-widgets)

target_link_libraries(quickshell-widgets PRIVATE Qt::Quick)
target_link_libraries(quickshell PRIVATE quickshell-widgetsplugin)
