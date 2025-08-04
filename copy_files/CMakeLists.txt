# copy_files/CMakeLists.txt

# 初始化SOURCE_DIRS变量
set(SOURCE_DIRS "")

# 根据系统和架构设置源目录
if(CMAKE_SYSTEM_NAME MATCHES Windows)
    message(STATUS "Copying prebuild files on Windows platform ${CMAKE_SOURCE_DIR}/depends/soui4/bin/${PLATFORM_ARCH}")
    if(MSVC)
        set(TARGET_DIR "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)")
    else()
        set(TARGET_DIR "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
    endif()
    set(SOURCE_DIRS
            ${CMAKE_SOURCE_DIR}/depends/quickjs/bin/${PLATFORM_ARCH}
            ${CMAKE_SOURCE_DIR}/depends/soui4/bin/${PLATFORM_ARCH}
        )
elseif(CMAKE_SYSTEM_NAME MATCHES Linux)
    message(STATUS "Copying prebuild files on Linux platform")
    set(TARGET_DIR "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
    set(SOURCE_DIRS
        ${CMAKE_SOURCE_DIR}/depends/quickjs/lib_deb/${PLATFORM_ARCH}
        ${CMAKE_SOURCE_DIR}/depends/soui4/lib_deb/${PLATFORM_ARCH}
    )
elseif(CMAKE_SYSTEM_NAME MATCHES Darwin)
    message(STATUS "Copying prebuild files on macos platform")
    set(TARGET_DIR "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
    set(SOURCE_DIRS
        ${CMAKE_SOURCE_DIR}/depends/quickjs/lib_mac/${PLATFORM_ARCH}
        ${CMAKE_SOURCE_DIR}/depends/soui4/lib_mac/${PLATFORM_ARCH}
    )
else()
    message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif()

# 添加自定义目标
add_custom_target(copy_files ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_DIR}
)

add_custom_command(TARGET copy_files PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/copy_files/soui-sys-resource.zip
            ${CMAKE_SOURCE_DIR}/copy_files/simsun.ttc
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