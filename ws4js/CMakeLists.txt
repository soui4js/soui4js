set(PROJECT_NAME ws4js)

################################################################################
# Source groups
################################################################################
set(Headers
    "exp_ws.h"
    "resource.h"
    "stdafx.h"
    "WsClient.h"
    "WsLoader.h"
    "WsSever.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "dllmain.cpp"
    "stdafx.cpp"
    "ws4js.cpp"
    "WsClient.cpp"
    "WsLoader.cpp"
    "WsSever.cpp"
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

target_precompile_headers(${PROJECT_NAME} PRIVATE
    "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/stdafx.h>"
)

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")

set(ROOT_NAMESPACE ws4js)

target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/."
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/quickjs/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/../qjsbind"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/config"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/components"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/soui/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/utilities/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/ws/include"
        PRIVATE 
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/swinx/include"

    )
################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    qjsbind
)


    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "libquickjs.a;"
        "qjsbind;"
        "utilities4;"
        "soui4"
    )

target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

target_link_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/lib/x64;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/quickjs/bin/x64;"
        "${OUTPUT_DIRECTORY}"
    )

