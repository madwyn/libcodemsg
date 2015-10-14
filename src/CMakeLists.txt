project(libcodemsg)

set(libcodemsg_SRCS
        message_def.c
        )

include_directories(
    ${libcodemsg_SOURCE_DIR}      # for message_collection.h in binary directory to access message_inc.h
    ${libcodemsg_BINARY_DIR}      # for the dll header
)

include(GenerateExportHeader)

# set lib
add_library(libcodemsg
    ${libcodemsg_SRCS}
)

if(NOT CODE_MESSAGE_ENTRY)
    set(CODE_MESSAGE_ENTRY "${libcodemsg_SOURCE_DIR}/message_all.h")
endif()

configure_file(message_collection.h.in message_collection.h)

if(NOT BUILD_SHARED_LIBS)
add_definitions(-DCOMMON_MESSAGE_BUILT_AS_STATIC)
endif()

GENERATE_EXPORT_HEADER(libcodemsg
    BASE_NAME         COMMON_MESSAGE
    EXPORT_MACRO_NAME COMMON_MESSAGE_EXPORT
    EXPORT_FILE_NAME  message_export.h
    STATIC_DEFINE     COMMON_MESSAGE_BUILT_AS_STATIC
)

set(INS_TARGETS
        libcodemsg
)

# Install
install(TARGETS ${INS_TARGETS}
    RUNTIME DESTINATION bin COMPONENT applications
    LIBRARY DESTINATION lib COMPONENT libraries
    ARCHIVE DESTINATION lib COMPONENT libraries
)
