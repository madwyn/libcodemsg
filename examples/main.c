#include <stdio.h>

#include <message_def.h>


MSG_CODE get_my_message(void) {
    return HELLO_YOU;
}

int main() {
    printf(gm(JUST_SAY_HI));
    printf("\n");
    printf(gm(HELLO_WORLD));
    printf("\n");
    printf(gm(get_my_message()));
    printf("\n");
    return 0;
}
