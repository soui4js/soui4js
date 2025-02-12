cmake_minimum_required(VERSION 3.10)

set(BUILD_WS OFF)
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
set(WS_OPENSSL_INCLUDE "" CACHE PATH "Path to the openSSL include directory" )
set(WS_LWS_INCLUDE "" CACHE PATH "Path to the libwebsodket include directory " )
set(WS_LWS_LIB CACHE PATH "libs" )

if(NOT EXISTS "${WS_OPENSSL_INCLUDE}")
    message(FATAL_ERROR "path of WS_OPENSSL_INCLUDE = ${WS_OPENSSL_INCLUDE} not found!")
endif()
set(BUILD_WS ON)
else()
find_package(libwebsockets REQUIRED)
# 如果找到libwebsockets，执行后续操作
if(libwebsockets_FOUND)
message("libws dir=${LIBWEBSOCKETS_INCLUDE_DIRS}")
set(WS_LWS_INCLUDE ${LIBWEBSOCKETS_INCLUDE_DIRS})
set(WS_LWS_LIB ${LIBWEBSOCKETS_LIBRARIES})
set(BUILD_WS ON)
endif()
endif()

if(BUILD_WS)
    
include_directories(${WS_LWS_INCLUDE}
${CMAKE_SOURCE_DIR}/depends/soui4/include/config
${CMAKE_SOURCE_DIR}/depends/soui4/include/utilities/include
${CMAKE_SOURCE_DIR}/depends/soui4/include/SOUI/include
${CMAKE_SOURCE_DIR}/depends/soui4/include/components
)
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
include_directories(${WS_OPENSSL_INCLUDE})
else()
include_directories(${CMAKE_SOURCE_DIR}/depends/swinx/include)
endif()
# Building
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

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
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

endif()

