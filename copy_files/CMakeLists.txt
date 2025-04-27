# copy_files/CMakeLists.txt

# 初始化SOURCE_DIRS变量
set(SOURCE_DIRS "")

# 根据系统和架构设置源目录
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(TARGET_DIR "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)")
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        message(STATUS "Copying prebuild files for x64 on Windows platform")
        set(SOURCE_DIRS
            ${CMAKE_SOURCE_DIR}/depends/quickjs/bin/x64
            ${CMAKE_SOURCE_DIR}/depends/soui4/bin/x64/
        )
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
        message(STATUS "Copying prebuild files for Win32 on Windows platform")
        set(SOURCE_DIRS
            ${CMAKE_SOURCE_DIR}/depends/quickjs/bin/Win32
            ${CMAKE_SOURCE_DIR}/depends/soui4/bin/Win32/
        )
    else()
        message(WARNING "Unknown architecture. Pointer size is ${CMAKE_SIZEOF_VOID_P}")
    endif()
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(TARGET_DIR "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        message(STATUS "Copying prebuild files for x64 on Linux platform")
        set(SOURCE_DIRS
            ${CMAKE_SOURCE_DIR}/depends/quickjs/lib_deb/x64
            ${CMAKE_SOURCE_DIR}/depends/soui4/lib_deb/x64
        )
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
        message(STATUS "Copying prebuild files for x86 on Linux platform")
        set(SOURCE_DIRS
            ${CMAKE_SOURCE_DIR}/depends/quickjs/lib_deb/x86
            ${CMAKE_SOURCE_DIR}/depends/soui4/lib_deb/x86
        )
    else()
        message(WARNING "Unknown architecture. Pointer size is ${CMAKE_SIZEOF_VOID_P}")
    endif()
else()
    message(WARNING "Unsupported system: ${CMAKE_SYSTEM_NAME}")
endif()

# 添加自定义目标
add_custom_target(copy_files ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_DIR}
)

add_custom_command(TARGET copy_files PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/copy_files/soui-sys-resource.zip
            ${TARGET_DIR}
    COMMENT "Copying soui-sys-resource.zip to ${TARGET_DIR}"
)

# 遍历每个源目录并复制文件
foreach(SOURCE_DIR IN LISTS SOURCE_DIRS)
    add_custom_command(TARGET copy_files PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${SOURCE_DIR}
                    ${TARGET_DIR}
            COMMENT "Copying ${SOURCE_DIR} to ${TARGET_DIR}"
    )
endforeach()


add_custom_command(TARGET copy_files PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${CMAKE_SOURCE_DIR}/soui4js-host/js
                    ${TARGET_DIR}
            COMMENT "Copying soui4js-host to ${TARGET_DIR}"
        )


add_custom_command(TARGET copy_files PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${CMAKE_SOURCE_DIR}/depends/soui4/Config
                    ${TARGET_DIR}/Config
            COMMENT "Copying uieditor.Config to ${TARGET_DIR}"
        )