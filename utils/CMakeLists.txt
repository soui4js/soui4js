set(PROJECT_NAME utils)

################################################################################
# Source groups
################################################################################
set(Headers
    "base64.h"
    "exp_base64.h"
    "exp_md5.h"
    "exp_utils.h"
    "fileop.h"
    "md5.h"
    "resource.h"
    "stdafx.h"
    "sysapi.h"
    "TextDecoder.h"
    "urlcode.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "base64.c"
    "fileop.cpp"
    "md5.cpp"
    "stdafx.cpp"
    "sysapi.cpp"
    "TextDecoder.cpp"
    "urlcode.cpp"
    "utils.cpp"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${Headers}
    ${Sources}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/qjsbind
    ${CMAKE_SOURCE_DIR}/depends/quickjs/include
    ${CMAKE_SOURCE_DIR}/depends/soui4/include/config
    ${CMAKE_SOURCE_DIR}/depends/soui4/include/utilities/include
    ${CMAKE_SOURCE_DIR}/depends/soui4/include/SOUI/include
    ${CMAKE_SOURCE_DIR}/depends/soui4/include/components
)

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    soui4js
)

if (CMAKE_SYSTEM_NAME MATCHES Windows)
target_link_directories(${PROJECT_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/depends/quickjs/lib_win/$(Platform)
${CMAKE_SOURCE_DIR}/depends/soui4/lib_win/$(Platform)
)
target_link_libraries(${PROJECT_NAME} soui4js qjsbind libquickjs soui4 utilities4)
else()
target_link_directories(${PROJECT_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/depends/quickjs/lib_deb/x64
${CMAKE_SOURCE_DIR}/depends/soui4/lib_deb/x64
)
target_link_libraries(${PROJECT_NAME} soui4js qjsbind quickjs soui4 utilities4)
endif()
