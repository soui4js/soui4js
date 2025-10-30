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

set(CMAKE_CONFIGURATION_TYPES Debug Release)
if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE "Release")
endif()

if(NOT CMAKE_SYSTEM_NAME MATCHES "Windows")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

if(NOT CMAKE_SYSTEM_NAME MATCHES Darwin)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
else()
add_compile_options(-Wno-inconsistent-missing-override)
endif()
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH $ORIGIN)
endif()

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
 
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    # Check if ARM64 architecture
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(aarch64|arm64|ARM64)$")
        set(PLATFORM_ARCH "arm64")
    else()
        set(PLATFORM_ARCH "x64")
    endif()
else()
    set(PLATFORM_ARCH "x86")
endif()

if (CMAKE_SYSTEM_NAME MATCHES Windows)
    # Determine platform architecture for library paths
    add_definitions(-DUNICODE -D_UNICODE)
else()
    include_directories(${SOUI_INCLUDE}/swinx/include)
endif()

################################################################################
# Sub-projects
################################################################################
add_subdirectory(qjsbind)
add_subdirectory(soui4js)
add_subdirectory(utils)
add_subdirectory(ws4js)
if(NOT CMAKE_SYSTEM_NAME MATCHES Darwin)
add_subdirectory(copy_files)
endif()

add_subdirectory(soui4js-host)