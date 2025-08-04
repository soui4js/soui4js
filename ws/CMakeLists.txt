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
if (CMAKE_SYSTEM_NAME MATCHES Linux)
link_directories(${CMAKE_SOURCE_DIR}/depends/soui4/lib_deb/x64)
set(LIBS ${LIBS} swinx)
elseif(CMAKE_SYSTEM_NAME MATCHES Darwin)
if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
message(STATUS "build soui4js macos arm64")
link_directories(${CMAKE_SOURCE_DIR}/depends/soui4/lib_mac/arm64)

else()
message(STATUS "build soui4js macos x64")
link_directories(${CMAKE_SOURCE_DIR}/depends/soui4/lib_mac/x64)

endif()
set(LIBS ${LIBS} swinx)
endif()

include_directories(${WS_LWS_INCLUDE}
${CMAKE_SOURCE_DIR}/depends/soui4/include/config
${CMAKE_SOURCE_DIR}/depends/soui4/include/utilities/include
${CMAKE_CURRENT_SOURCE_DIR}/include
)
add_library(${PROJECT_NAME} SHARED ${SOURCES})
add_dependencies(${PROJECT_NAME} websockets)
target_link_libraries(${PROJECT_NAME} ${LIBS})

if(0)
project(ServerTest)
add_executable(${PROJECT_NAME} test/ServerTest.cpp)
target_link_libraries(${PROJECT_NAME} ws)

project(ClientTest)
add_executable(${PROJECT_NAME} test/ClientTest.cpp)
target_link_libraries(${PROJECT_NAME} ws)
endif()


