#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "osmplib.h"

#define TEST(func) \
    if((func) == OSMP_ERROR) \
        printf("Error in File %s at line %d\n ", __FILE__, __LINE__); \
        fflush(NULL); \
        return(EXIT_FAILURE);

#define TEST_NEG(func) \
    if((func) != OSMP_ERROR) { \
        printf("Error in File %s at line %d\n ", __FILE__, __LINE__); \
        fflush(NULL); \
        return(EXIT_FAILURE); }