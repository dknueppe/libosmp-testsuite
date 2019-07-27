#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "osmplib.h"

#define TEST_FAILED 1

int errval;

#define _error { \
        printf("Error in File %s at line %d\n ", __FILE__, __LINE__); \
        fflush(NULL); \
        errval = TEST_FAILED; }


#define TEST_POS(func) \
    if((func) == OSMP_SUCCESS) \
        _error

#define TEST_NEG(func) \
    if((func) == OSMP_ERROR) \
        _error

#define TEST_FALSE_POS(func) \
    if((func) != OSMP_ERROR) \
        _error

#define TEST_FALSE_NEG(func) \
    if((func) != OSMP_SUCCESS) \
        _error
