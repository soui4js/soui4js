set(PROJECT_NAME qjsbind)

file(GLOB CURRENT_HEADERS *.h *.hpp)
file(GLOB QJSBIND_SRCS  *.cpp)

source_group("Header Files" FILES ${CURRENT_HEADERS})

source_group("Source Files" FILES ${QJSBIND_SRCS})

add_library(${PROJECT_NAME} STATIC ${QJSBIND_SRCS})

target_include_directories(${PROJECT_NAME}
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/swinx/include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../depends/quickjs/include  
)

set(ROOT_NAMESPACE qjsbind)

