cmake_minimum_required(VERSION 3.16.0)


project(soui4js)


if (CMAKE_SYSTEM_NAME STREQUAL "MSYS")
    message(STATUS "Overriding incorrect Linux detection for MSYS")
    set(CMAKE_SYSTEM_NAME Windows CACHE STRING "Target system" FORCE)
endif()
if (CMAKE_SYSTEM_NAME STREQUAL "Linux" AND MINGW)
    message(STATUS "Overriding incorrect Linux detection for MINGW")
    set(CMAKE_SYSTEM_NAME Windows CACHE STRING "Target system" FORCE)
endif()


set(CMAKE_CXX_STANDARD 11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin64)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin64)


if (NOT CMAKE_SYSTEM_NAME MATCHES Windows)
include_directories(depends/swinx/include)
endif()

################################################################################
# Sub-projects
################################################################################
add_subdirectory(qjsbind)
add_subdirectory(soui4js)
add_subdirectory(soui4js-host)
#add_subdirectory(utils)
#add_subdirectory(ws4js)

