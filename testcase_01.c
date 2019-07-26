#include "testsuite.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
int main(int argc, char* argv[]) 
{
    char send_buffer[OSMP_MAX_PAYLOAD_LENGTH] = "";
    char recv_buffer[OSMP_MAX_PAYLOAD_LENGTH] = "";
    int size = 0, rank = 0, dest = 0, src = 0, len = 0, flag = 0;
    OSMP_Datatype dt = OSMP_BYTE;
    OSMP_Request req = NULL;

    TEST_NEG(OSMP_Size(&size));
    TEST_NEG(OSMP_Rank(&rank));
    TEST_NEG(OSMP_Send(send_buffer, OSMP_MAX_PAYLOAD_LENGTH, dt, dest));
    TEST_NEG(OSMP_Recv(recv_buffer, OSMP_MAX_PAYLOAD_LENGTH, dt, &src, &len));
    TEST_NEG(OSMP_CreateRequest(req));
    TEST_NEG(OSMP_Isend(send_buffer, OSMP_MAX_PAYLOAD_LENGTH, dt, dest, req));
    TEST_NEG(OSMP_Irecv(recv_buffer, OSMP_MAX_PAYLOAD_LENGTH, dt, &src, &len, req));
    TEST_NEG(OSMP_Test(req, &flag));
    TEST_NEG(OSMP_Wait(req));
    TEST_NEG(OSMP_RemoveRequest(req));

    OSMP_Init(&argc, &argv);
    OSMP_Finalize();

    TEST_NEG(OSMP_Size(&size));
    TEST_NEG(OSMP_Rank(&rank));
    TEST_NEG(OSMP_Send(send_buffer, OSMP_MAX_PAYLOAD_LENGTH, dt, dest));
    TEST_NEG(OSMP_Recv(recv_buffer, OSMP_MAX_PAYLOAD_LENGTH, dt, &src, &len));
    TEST_NEG(OSMP_CreateRequest(req));
    TEST_NEG(OSMP_Isend(send_buffer, OSMP_MAX_PAYLOAD_LENGTH, dt, dest, req));
    TEST_NEG(OSMP_Irecv(recv_buffer, OSMP_MAX_PAYLOAD_LENGTH, dt, &src, &len, req));
    TEST_NEG(OSMP_Test(req, &flag));
    TEST_NEG(OSMP_Wait(req));
    TEST_NEG(OSMP_RemoveRequest(req));

    printf("%s finished successful!\n", argv[0]);
    return OSMP_SUCCESS;
}
#pragma GCC diagnostic pop
