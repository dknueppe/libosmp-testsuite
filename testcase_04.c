#include "testsuite.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
int main(int argc, char* argv[]) 
{
    char send_buffer[2 * OSMP_MAX_PAYLOAD_LENGTH] = "";
    char recv_buffer[2 * OSMP_MAX_PAYLOAD_LENGTH] = "";
    int size = 0, rank = 0, dest = 0, src = 0, len = 0, flag = 0;
    OSMP_Datatype dt = OSMP_BYTE;
    OSMP_Request req = NULL;

    TEST(OSMP_Init(&argc, &argv));
    TEST(OSMP_Rank(&rank));
    TEST(OSMP_Size(&size));

    printf("%s finished successful!\n", argv[0]);
    return OSMP_SUCCESS;
}
#pragma GCC diagnostic pop
