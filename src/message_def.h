#ifndef MESSAGE_DEF_H_INCLUDED
#define MESSAGE_DEF_H_INCLUDED

#include <message_export.h>

typedef enum {
    #define DEF_MSG(code, msg) code,
    #include "message_def_header.h"
    #include <message_collection.h>
    #include "message_def_footer.h"
    #undef  DEF_MSG
    MSG_NUM
} MSG_CODE;

#ifdef __cplusplus
extern "C" {
#endif

COMMON_MESSAGE_EXPORT const char* get_message(MSG_CODE code);

#ifdef __cplusplus
}
#endif

#define gm(code) get_message(code)

#endif
