project(codemsg_demo)

include_directories(
        ${libcodemsg_SOURCE_DIR}
        ${libcodemsg_BINARY_DIR}
)

set(SOURCE_FILES main.c)

add_executable(codemsg_demo ${SOURCE_FILES})


target_link_libraries(codemsg_demo
        libcodemsg
        )