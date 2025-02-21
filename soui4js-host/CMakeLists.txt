set(PROJECT_NAME soui4js-host)

################################################################################
# Source groups
################################################################################
set(no_group_source_files
    "readme.txt"
)
source_group("" FILES ${no_group_source_files})

set(Headers
    "resource.h"
    "stdafx.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "soui4js-host.cpp"
    "stdafx.cpp"
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
add_executable(${PROJECT_NAME} ${ALL_FILES})

target_precompile_headers(${PROJECT_NAME} PRIVATE
    "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/stdafx.h>"
)

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")


################################################################################
# Include directories
################################################################################

    target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/swinx/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/config;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/components;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/soui;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/soui/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/utilities/include"
    )

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    soui4js
)

    set(ADDITIONAL_LIBRARY_DEPENDENCIES
    "swinx"
        "utilities4;"
        "soui4"
    )

target_link_libraries(${PROJECT_NAME} PRIVATE "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_link_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/lib/x64;"
        "${OUTPUT_DIRECTORY}"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_link_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/lib/x86;"
        "${OUTPUT_DIRECTORY}"
    )
endif()

