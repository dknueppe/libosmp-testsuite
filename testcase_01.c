#include <stdio.h>
#include <stdlib.h>
#include "osmplib.h"

#define TEST(func) \
    if((func) != OSMP_ERROR) { \
        printf("Test %s failed at test %s\n", argv[0], #func); \
        return OSMP_ERROR; }

int main(int argc, char* argv[]) 
{
    char send_buffer[OSMP_MAX_PAYLOAD_LENGTH] = "";
    char recv_buffer[OSMP_MAX_PAYLOAD_LENGTH] = "";
    int size = 0, rank = 0, dest = 0, src = 0, len = 0, flag = 0;
    OSMP_Datatype dt = OSMP_BYTE;
    OSMP_Request req = NULL;

    TEST(OSMP_Size(&size));
    TEST(OSMP_Rank(&rank));
    TEST(OSMP_Send(send_buffer, OSMP_MAX_PAYLOAD_LENGTH, dt, dest));
    TEST(OSMP_Recv(recv_buffer, OSMP_MAX_PAYLOAD_LENGTH, dt, &src, &len));
    TEST(OSMP_CreateRequest(req));
    TEST(OSMP_Isend(send_buffer, OSMP_MAX_PAYLOAD_LENGTH, dt, dest, req));
    TEST(OSMP_Irecv(recv_buffer, OSMP_MAX_PAYLOAD_LENGTH, dt, &src, &len, req));
    TEST(OSMP_Test(req, &flag));
    TEST(OSMP_Wait(req));
    TEST(OSMP_RemoveRequest(req));

    OSMP_Init(&argc, &argv);
    OSMP_Finalize();

    TEST(OSMP_Size(&size));
    TEST(OSMP_Rank(&rank));
    TEST(OSMP_Send(send_buffer, OSMP_MAX_PAYLOAD_LENGTH, dt, dest));
    TEST(OSMP_Recv(recv_buffer, OSMP_MAX_PAYLOAD_LENGTH, dt, &src, &len));
    TEST(OSMP_CreateRequest(req));
    TEST(OSMP_Isend(send_buffer, OSMP_MAX_PAYLOAD_LENGTH, dt, dest, req));
    TEST(OSMP_Irecv(recv_buffer, OSMP_MAX_PAYLOAD_LENGTH, dt, &src, &len, req));
    TEST(OSMP_Test(req, &flag));
    TEST(OSMP_Wait(req));
    TEST(OSMP_RemoveRequest(req));

    printf("%s finished successful!\n", argv[0]);
    return OSMP_SUCCESS;
}