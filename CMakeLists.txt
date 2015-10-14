cmake_minimum_required(VERSION 3.3)

if(NOT BUILD_EXAMPLE)
    set(BUILD_EXAMPLE OFF)
endif()

if(BUILD_EXAMPLE)
    set(CODE_MESSAGE_ENTRY "${codemsg_demo_SOURCE_DIR}/messages/message_all.h")
endif()

if (NOT CODE_MESSAGE_ENTRY)
    message(FATAL_ERROR "Please specify the message entry header file as varible CODE_MESSAGE_ENTRY.")
endif()

add_subdirectory(src)

if(BUILD_EXAMPLE)
    add_subdirectory(examples)
endif()
