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
source_group("Sources" FILES ${HOST_SRC})

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${HOST_HEADER} ${HOST_SRC})


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

target_link_directories(${PROJECT_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/depends/swinx/lib_deb/x64
${CMAKE_SOURCE_DIR}/depends/quickjs/lib_deb/x64
${CMAKE_SOURCE_DIR}/depends/soui4/lib_deb/x64
)

target_link_libraries(${PROJECT_NAME} soui4js soui4 swinx utilities4)

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    soui4js
)

