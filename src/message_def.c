#include "message_def.h"

static const char* _g_messages[MSG_NUM] = {
    #define DEF_MSG(code, msg) msg,
    #include "message_def_header.h"
    #include "message_collection.h"
    #include "message_def_footer.h"
    #undef  DEF_MSG
};

const char* get_message(MSG_CODE code) {
    if (code < MSG_NUM)
        return _g_messages[code];

    return "No such message code: " + code;
}
