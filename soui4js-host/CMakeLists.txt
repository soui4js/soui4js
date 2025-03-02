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
################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} WIN32 ${HOST_HEADER} ${HOST_SRC})


################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/qjsbind
    ${CMAKE_SOURCE_DIR}/depends/quickjs/include
    ${CMAKE_SOURCE_DIR}/depends/soui4/include/config
    ${CMAKE_SOURCE_DIR}/depends/soui4/include/utilities/include
    ${CMAKE_SOURCE_DIR}/depends/soui4/include/SOUI/include
    ${CMAKE_SOURCE_DIR}/depends/soui4/include/components
)

if (CMAKE_SYSTEM_NAME MATCHES Windows)
target_link_directories(${PROJECT_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/depends/quickjs/lib_win/$(Platform)
${CMAKE_SOURCE_DIR}/depends/soui4/lib_win/$(Platform)
)
target_link_libraries(${PROJECT_NAME} soui4js soui4 utilities4)
else()
target_link_directories(${PROJECT_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/depends/swinx_1.0/lib_deb/x64
${CMAKE_SOURCE_DIR}/depends/quickjs/lib_deb/x64
${CMAKE_SOURCE_DIR}/depends/soui4/lib_deb/x64
)
target_link_libraries(${PROJECT_NAME} soui4js soui4 swinx utilities4)
endif()

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    soui4js
)

