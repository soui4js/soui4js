set(PROJECT_NAME utils)

################################################################################
# Source groups
################################################################################
set(no_group_source_files
    "readme.txt"
)
source_group("" FILES ${no_group_source_files})

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
    ${no_group_source_files}
    ${Headers}
    ${Sources}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${ALL_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/swinx/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/quickjs/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../qjsbind;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/config;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/components;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/soui/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/utilities/include"
    )

    

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    soui4js
)


    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "libquickjs.a;"
        "qjsbind;"
        "utilities4;"
        "soui4"
    )

target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_link_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/lib/x64;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/quickjs/bin/x64;"
        "${OUTPUT_DIRECTORY}"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_link_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/lib/x86;"
        "${OUTPUT_DIRECTORY};"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/quickjs/bin/x86"
    )
endif()

