#include <stdio.h>
#include <stdlib.h>
#include "osmplib.h"

#define TEST(func) \
    if((func) == OSMP_ERROR) { \
        printf("Test %s failed at test %s\n", argv[0], #func); \
        return OSMP_ERROR; }

int main(int argc, char* argv[]) 
{
    char send_buffer[OSMP_MAX_PAYLOAD_LENGTH] = "";
    char recv_buffer[OSMP_MAX_PAYLOAD_LENGTH] = "";
    int size = 0, rank = 0, dest = 0, src = 0, len = 0, flag = 0;
    OSMP_Datatype dt = OSMP_BYTE;
    OSMP_Request req = NULL;

    TEST(OSMP_Init(&argc, &argv));
    TEST(OSMP_Rank(&rank));
    TEST(OSMP_Size(&size));

    printf("%s finished successful!\n", argv[0]);
    return OSMP_SUCCESS;
}