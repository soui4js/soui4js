set(PROJECT_NAME qjsbind)

file(GLOB QJSBIND_HEADERS *.h *.hpp)
file(GLOB QJSBIND_SRCS  *.cpp)

source_group("Header Files" FILES ${QJSBIND_HEADERS})

source_group("Source Files" FILES ${QJSBIND_SRCS})

add_library(${PROJECT_NAME} STATIC ${QJSBIND_SRCS})

target_compile_options(${PROJECT_NAME} PRIVATE -fPIC)

target_include_directories(${PROJECT_NAME}
        PRIVATE ${CMAKE_SOURCE_DIR}/depends/quickjs/include  
)



set(ROOT_NAMESPACE qjsbind)

