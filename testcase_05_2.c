/*
 * The fourth testcase determines the behaviour of the library when
 * more messages are send then are availablei (defined by 'OSMP_MAX_SLOTS'). 
 */
#include "testsuite.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
int main(int argc, char* argv[]) 
{
    char send_buffer[2 * OSMP_MAX_PAYLOAD_LENGTH] = "";
    char recv_buffer[2 * OSMP_MAX_PAYLOAD_LENGTH] = "";
    int size = 0, rank = 0, dest = 0, src = 0, len = 0, flag = 0;
    OSMP_Datatype dt = OSMP_BYTE;
    OSMP_Request req = NULL;

    TEST_POS(OSMP_Init(&argc, &argv));
    TEST_POS(OSMP_Rank(&rank));
    TEST_POS(OSMP_Size(&size));
    TEST_POS(OSMP_CreateRequest(req));
    for(int i = 0; i < OSMP_MAX_SLOTS; i++)
        TEST_FALSE_POS(OSMP_Send(send_buffer, 1, dt, rank));
    TEST_POS(OSMP_Isend(send_buffer, 1, dt, rank, req));
    TEST_POS(OSMP_Test(req, &flag));
    if(flag == async_trans_complete)
        errval = TEST_FAILED;

    return errval;
}
#pragma GCC diagnostic pop
