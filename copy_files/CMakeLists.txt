# copy_files/CMakeLists.txt

set(SOURCE_DIRS )

if(CMAKE_SYSTEM_NAME MATCHES Windows)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(STATUS "copy prebuild file for x64 on windows platform")
    set(SOURCE_DIRS ${SOURCE_DIRS}
    ${CMAKE_SOURCE_DIR}/depends/quickjs/bin/x64
    ${CMAKE_SOURCE_DIR}/depends/soui4/bin/x64
    ${CMAKE_SOURCE_DIR}/hostjs
    )
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    message(STATUS "Target architecture is x86")
    # 在这里添加 x86 架构相关的设置
    set(SOURCE_DIRS ${SOURCE_DIRS}
    ${CMAKE_SOURCE_DIR}/depends/quickjs/bin/x86
    ${CMAKE_SOURCE_DIR}/depends/soui4/bin/x86
    ${CMAKE_SOURCE_DIR}/hostjs
    )
else()
    message(WARNING "Unknown architecture. Pointer size is ${CMAKE_SIZEOF_VOID_P}")
endif()

else()


if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(STATUS "copy prebuild file for x64 on linux platform")
    set(SOURCE_DIRS ${SOURCE_DIRS}
    ${CMAKE_SOURCE_DIR}/depends/quickjs/lib_deb/x64
    ${CMAKE_SOURCE_DIR}/depends/soui4/lib_deb/x64
    ${CMAKE_SOURCE_DIR}/depends/swinx/lib_deb/x64
    ${CMAKE_SOURCE_DIR}/hostjs
    )
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    message(STATUS "Target architecture is x86")
    # 在这里添加 x86 架构相关的设置
    set(SOURCE_DIRS ${SOURCE_DIRS}
    ${CMAKE_SOURCE_DIR}/depends/quickjs/lib_deb/x86
    ${CMAKE_SOURCE_DIR}/depends/soui4/lib_deb/x86
    ${CMAKE_SOURCE_DIR}/depends/swinx/lib_deb/x86
    ${CMAKE_SOURCE_DIR}/hostjs
    )
else()
    message(WARNING "Unknown architecture. Pointer size is ${CMAKE_SIZEOF_VOID_P}")
endif()

endif()

foreach(SOURCE_DIR IN LISTS SOURCE_DIRS)
file(GLOB FILES_TO_COPY "${SOURCE_DIR}/*")
foreach(FILE IN LISTS FILES_TO_COPY)
    add_custom_command(TARGET copy_files POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${FILE}
                ${TARGET_DIR}
    )
endforeach()
endforeach()
