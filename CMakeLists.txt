cmake_minimum_required(VERSION 3.16.0)


project(soui4js)

include(__cmake/internal_utils.cmake)
include(__cmake/global.cmake)

set(SOUI_INCLUDE ${CMAKE_SOURCE_DIR}/depends/soui4/include)
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
readSettingFile(${SOUI_INCLUDE}/config/build.cfg UNICODE "1" USE_UNICODE)
readSettingFile(${SOUI_INCLUDE}/config/build.cfg WCHAR "1" WCHAR_AS_DEFAULT)
readSettingFile(${SOUI_INCLUDE}/config/build.cfg MT "0" SHARED_CRT)
readSettingFile(${SOUI_INCLUDE}/config/build.cfg SUPPORT_XP "1" XP_TOOLSET)
else()
set(USE_UNICODE 0)
set(WCHAR_AS_DEFAULT 1)
set(SHARED_CRT 1)
endif()

config_compiler_and_linker()


if (CMAKE_SYSTEM_NAME STREQUAL "MSYS")
    message(STATUS "Overriding incorrect Linux detection for MSYS")
    set(CMAKE_SYSTEM_NAME Windows CACHE STRING "Target system" FORCE)
endif()
if (CMAKE_SYSTEM_NAME STREQUAL "Linux" AND MINGW)
    message(STATUS "Overriding incorrect Linux detection for MINGW")
    set(CMAKE_SYSTEM_NAME Windows CACHE STRING "Target system" FORCE)
endif()

set(CMAKE_CONFIGURATION_TYPES Debug Release)
if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE "Release")
endif()

if(NOT CMAKE_SYSTEM_NAME MATCHES "Windows")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH $ORIGIN)
endif()

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
 

if (CMAKE_SYSTEM_NAME MATCHES Windows)
    add_definitions(-DUNICODE -D_UNICODE)
else()
    include_directories(${SOUI_INCLUDE}/swinx/include)
endif()

################################################################################
# Sub-projects
################################################################################
add_subdirectory(qjsbind)
add_subdirectory(soui4js)
add_subdirectory(soui4js-host)
add_subdirectory(utils)
add_subdirectory(copy_files)

option(BUILD_WS_MODULE "build websocket module" ON)

if(BUILD_WS_MODULE)
    if(CMAKE_SYSTEM_NAME MATCHES "Windows")
        if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(platform "x64")
        else()
        set(platform "Win32")
        endif()
        set(LWS_OPENSSL_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/depends/openssl_1.1.1d/${platform}/include)
        set(LWS_OPENSSL_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/depends/openssl_1.1.1d/${platform}/lib/$(Configuration)/libssl.lib;${CMAKE_CURRENT_SOURCE_DIR}/depends/openssl_1.1.1d/${platform}/lib/$(Configuration)/libcrypto.lib")
        set(BUILD_WS ON)
        message("LWS_OPENSSL_LIBRARIES is ${LWS_OPENSSL_LIBRARIES} first")
    else()#CMAKE_SYSTEM_NAME MATCHES "Windows"
        set(BUILD_WS ON)
    endif()

    if(BUILD_WS)
        set(LWS_WITH_MINIMAL_EXAMPLES OFF)
        set(LWS_WITHOUT_TESTAPPS ON)
        set(LWS_WITH_STATIC ON)
        set(LWS_WITH_SHARED OFF)
        set(LWS_STATIC_PIC ON)
        set_property(GLOBAL PROPERTY USE_FOLDERS ON) 
        add_subdirectory(libwebsockets)
        get_property(libwebsocket_targets DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/libwebsockets PROPERTY BUILDSYSTEM_TARGETS)
        foreach(target ${libwebsocket_targets})
            set_target_properties(${target} PROPERTIES FOLDER "libwebsocket")
        endforeach()

        
        if(CMAKE_SYSTEM_NAME MATCHES "Windows")
        set(LIBWS_INST_DIR ${PROJECT_BINARY_DIR}/libwebsockets)
        set(WS_LWS_INCLUDE ${LIBWS_INST_DIR}/include ${LWS_OPENSSL_INCLUDE_DIRS})
        set(WS_LWS_LIB 
            ${LIBWS_INST_DIR}/lib/$(Configuration)/websockets_static.lib 
            ${LWS_OPENSSL_LIBRARIES} 
            Ws2_32.lib
            Crypt32.lib)
        else()
            set(WS_LWS_LIB websockets)
        endif()

        add_subdirectory(ws)
        add_subdirectory(ws4js)
    endif(BUILD_WS)
endif(BUILD_WS_MODULE)