#include <stdio.h>

#include <message_def.h>


MSG_CODE get_my_message(void) {
    return HELLO_YOU;
}

int main() {
    printf(get_message(JUST_SAY_HI));
    printf("\n");
    printf(get_message(HELLO_WORLD));
    printf("\n");
    printf(get_message(get_my_message()));
    printf("\n");
    return 0;
}
