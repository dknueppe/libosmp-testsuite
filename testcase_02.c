/*
 * The second testcase ensures that the receiver is actually blocked when
 * there is no message available to read. Notice that the program is
 * not supposed to run through successfully but rather get interrupted after
 * a certain time, hence 'return EXIT_FAILURE'.
 */
#include "testsuite.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
int main(int argc, char* argv[]) 
{
    char send_buffer[OSMP_MAX_PAYLOAD_LENGTH] = "";
    char recv_buffer[OSMP_MAX_PAYLOAD_LENGTH] = "";
    int size = 0, rank = 0, dest = 0, src = 0, len = 0, flag = 0;
    OSMP_Datatype dt = OSMP_BYTE;
    OSMP_Request req = NULL;

    TEST_POS(OSMP_Init(&argc, &argv));
    TEST_POS(OSMP_Rank(&rank));
    TEST_POS(OSMP_Size(&size));
    TEST_POS(OSMP_Recv(send_buffer, 1, dt, &src, &len));

    return EXIT_FAILURE;
}
#pragma GCC diagnostic pop