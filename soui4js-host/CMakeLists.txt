set(PROJECT_NAME soui4js-host)

################################################################################
# Source groups
################################################################################

source_group("" FILES ${no_group_source_files})

set(HOST_HEADER
    "resource.h"
    "stdafx.h"
)
source_group("Headers" FILES ${HOST_HEADER})

set(HOST_SRC
    "soui4js-host.cpp"
    "stdafx.cpp"
)

file(GLOB_RECURSE HOST_JS  js/*.*)

if (CMAKE_SYSTEM_NAME MATCHES Windows)
set(HOST_SRC
    ${HOST_SRC}
    "soui4js-host.rc"
)
endif()

source_group("Sources" FILES ${HOST_SRC})
source_group("Js" FILES ${HOST_JS})

include(${CMAKE_SOURCE_DIR}/__cmake/global.cmake)

################################################################################
# Target
################################################################################

set(MACOSX_BUNDLE_HIGH_RESOLUTION_CAPABLE "true")
set(MACOSX_BUNDLE_GUI_IDENTIFIER "com.soui.soui4js-host")
add_soui_exe(${PROJECT_NAME} ${HOST_HEADER} ${HOST_SRC})
set(HOST_TARGET_LIST
    soui4js
    utils
)
if(BUILD_WS_MODULE)
set(HOST_TARGET_LIST
    ${HOST_TARGET_LIST}
    ws4js
    ws
)
endif()
add_dependencies(${PROJECT_NAME} ${HOST_TARGET_LIST})

if(CMAKE_SYSTEM_NAME MATCHES Darwin)
# 准备要复制的目标列表

if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
file(GLOB_RECURSE DYLIB_SOUI  ${CMAKE_SOURCE_DIR}/depends/soui4/lib_mac/arm64/*.dylib)
file(GLOB_RECURSE DYLIB_QJS  ${CMAKE_SOURCE_DIR}/depends/quickjs/lib_mac/arm64/*.dylib)
else()
file(GLOB_RECURSE DYLIB_SOUI  ${CMAKE_SOURCE_DIR}/depends/soui4/lib_mac/x64/*.dylib)
file(GLOB_RECURSE DYLIB_QJS  ${CMAKE_SOURCE_DIR}/depends/quickjs/lib_mac/x64/*.dylib)
endif()

set(HOST_DYLIB_LIST ${DYLIB_SOUI} ${DYLIB_QJS})
copy_frameworks_to_bundle(${PROJECT_NAME} "${HOST_DYLIB_LIST}")

copy_targets_to_bundle(${PROJECT_NAME} "${HOST_TARGET_LIST}")

add_macos_res_folder(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/js data)
add_macos_res_file(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/copy_files/soui-sys-resource.zip data) 
add_macos_res_file(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/copy_files/simsun.ttc fonts) 
set_macos_icon(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/res/soui4js-host.icns)
set(MACOSX_BUNDLE_BUNDLE_NAME "soui4js-host")
endif()

################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/qjsbind
    ${CMAKE_SOURCE_DIR}/depends/quickjs/include
    ${SOUI_INCLUDE}/config
    ${SOUI_INCLUDE}/utilities/include
    ${SOUI_INCLUDE}/SOUI/include
    ${SOUI_INCLUDE}/components
)

if (CMAKE_SYSTEM_NAME MATCHES Windows)
target_link_directories(${PROJECT_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/depends/quickjs/lib_win/${PLATFORM_ARCH}
${CMAKE_SOURCE_DIR}/depends/soui4/lib_win/${PLATFORM_ARCH}
)
target_link_libraries(${PROJECT_NAME} soui4js soui4 utilities4)
elseif(CMAKE_SYSTEM_NAME MATCHES Linux)
target_link_directories(${PROJECT_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/depends/quickjs/lib_deb/x64
${CMAKE_SOURCE_DIR}/depends/soui4/lib_deb/x64
)
target_link_libraries(${PROJECT_NAME} soui4js swinx soui4 swinx utilities4)
elseif(CMAKE_SYSTEM_NAME MATCHES Darwin)
if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
message(STATUS "build soui4js macos arm64")
target_link_directories(${PROJECT_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/depends/quickjs/lib_mac/arm64
${CMAKE_SOURCE_DIR}/depends/soui4/lib_mac/arm64
)
else()
message(STATUS "build soui4js macos x64")
target_link_directories(${PROJECT_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/depends/quickjs/lib_mac/x64
${CMAKE_SOURCE_DIR}/depends/soui4/lib_mac/x64
)
endif()
target_link_libraries(${PROJECT_NAME} soui4js swinx soui4 swinx utilities4)
endif()

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    soui4js
)

