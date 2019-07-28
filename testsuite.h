#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "osmplib.h"
#include "datastructs.h"
#include "nonblocking.h"

#define TEST_FAILED 1

int errval = EXIT_SUCCESS;
int retval;

#define _error { \
        printf("Error in File %s at line %d\n", __FILE__, __LINE__); \
        printf("\t caused by #func returning %d\n", retval); \
        fflush(NULL); \
        errval = TEST_FAILED; }

#define TEST_POS(func) \
    if((retval = func) == OSMP_ERROR) \
        _error

#define TEST_NEG(func) \
    if((retval = func) == OSMP_SUCCESS) \
        _error

#define TEST_FALSE_POS(func) \
    if((retval = func) != OSMP_SUCCESS) \
        _error

#define TEST_FALSE_NEG(func) \
    if((retval = func) != OSMP_ERROR) \
        _error
