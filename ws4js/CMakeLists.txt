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

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    qjsbind
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/qjsbind
    ${CMAKE_SOURCE_DIR}/depends/quickjs/include
    ${CMAKE_SOURCE_DIR}/depends/soui4/include/config
    ${CMAKE_SOURCE_DIR}/depends/soui4/include/utilities/include
    ${CMAKE_SOURCE_DIR}/depends/soui4/include/SOUI/include
    ${CMAKE_SOURCE_DIR}/depends/soui4/include/components
    ${CMAKE_SOURCE_DIR}/depends/ws/include
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


