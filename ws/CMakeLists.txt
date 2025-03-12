cmake_minimum_required(VERSION 3.10)

project(ws)

set(SOURCES
        include/ws-i.h
        src/Connection.h
        src/Connection.cpp
        src/wsServer.h
        src/wsServer.cpp
        src/wsClient.h
        src/wsClient.cpp
        src/ws.cpp
)

set(LIBS ${WS_LWS_LIB})

if (NOT CMAKE_SYSTEM_NAME MATCHES Windows)
link_directories(${CMAKE_SOURCE_DIR}/depends/swinx_1.0/lib_deb/x64
)
set(LIBS ${LIBS} swinx)
endif()

include_directories(${WS_LWS_INCLUDE}
${CMAKE_SOURCE_DIR}/depends/soui4/include/config
${CMAKE_SOURCE_DIR}/depends/soui4/include/utilities/include
${CMAKE_CURRENT_SOURCE_DIR}/include
)
add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBS})

if(0)
project(ServerTest)
add_executable(${PROJECT_NAME} test/ServerTest.cpp)
target_link_libraries(${PROJECT_NAME} ws)

project(ClientTest)
add_executable(${PROJECT_NAME} test/ClientTest.cpp)
target_link_libraries(${PROJECT_NAME} ws)
endif()


