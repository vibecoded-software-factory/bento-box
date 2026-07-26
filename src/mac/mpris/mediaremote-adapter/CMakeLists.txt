# Builds MediaRemoteAdapter.framework from vendored sources.
#
#   Source:   https://github.com/ungive/mediaremote-adapter
#   Revision: 3ac3d4bdf862c7b5399b4fba4df5689f5c38609a
#   License:  BSD 3-Clause - see LICENSE in this directory (kept verbatim)
#
# Only the framework sources, the public header and the perl loader (bin/) are
# vendored; upstream's test client and build files are dropped in favour of
# this slim file, which builds the framework target alone.
#
# The framework is loaded at runtime by the entitled system perl, which is what
# lets it reach Apple's restricted MediaRemote framework and, unlike the
# osascript path, call the block-based API that carries album artwork.

set(ADAPTER_SOURCES
	src/adapter/env.m
	src/adapter/get.m
	src/adapter/globals.m
	src/adapter/keys.m
	src/adapter/now_playing.m
	src/adapter/repeat.m
	src/adapter/seek.m
	src/adapter/send.m
	src/adapter/shuffle.m
	src/adapter/speed.m
	src/adapter/stream.m
	src/private/MediaRemote.m
	src/utility/Debounce.m
	src/utility/helpers.m
)

# Compile as Objective-C, NOT Objective-C++: the perl loader resolves the
# framework's entry points by their plain C names (adapter_stream_env, ...), and
# C++ would mangle them out of reach. (bento's build otherwise defaults these
# .m files to objective-c++.)
enable_language(OBJC)
set_source_files_properties(${ADAPTER_SOURCES} PROPERTIES LANGUAGE OBJC)

add_library(MediaRemoteAdapter SHARED ${ADAPTER_SOURCES})
set_target_properties(MediaRemoteAdapter PROPERTIES
	FRAMEWORK TRUE
	FRAMEWORK_VERSION A
	MACOSX_FRAMEWORK_IDENTIFIER "com.vandenbe.MediaRemoteAdapter"
	MACOSX_FRAMEWORK_BUNDLE_NAME "MediaRemoteAdapter"
	PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/include/MediaRemoteAdapter.h"
	OUTPUT_NAME "MediaRemoteAdapter"
)

target_link_libraries(MediaRemoteAdapter "-framework Foundation" "-framework AppKit")
find_library(UT_FRAMEWORK UniformTypeIdentifiers)
if(UT_FRAMEWORK)
	target_link_libraries(MediaRemoteAdapter ${UT_FRAMEWORK})
endif()

target_include_directories(MediaRemoteAdapter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(MediaRemoteAdapter PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# ARC, and default symbol visibility so the perl loader can resolve the
# exported adapter_* entry points via DynaLoader.
target_compile_options(MediaRemoteAdapter PRIVATE -fobjc-arc -fvisibility=default)

# The entitled perl only loads an ad-hoc signed framework.
add_custom_command(
	TARGET MediaRemoteAdapter POST_BUILD
	COMMAND codesign --force --deep --sign - $<TARGET_BUNDLE_DIR:MediaRemoteAdapter>
	COMMENT "Ad-hoc signing MediaRemoteAdapter.framework"
)
