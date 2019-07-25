# Makefile for testcases in the operatingsystems module
# at UAS Münster
# Author: Daniel Knüppe (@DanielKnueppe)

BUILD_DIR ?= build
CC ?= gcc
CC_FLAGS ?= -ggdb3 -O3 -Wall -Wextra -pthread -Wpedantic -std=gnu11 $(WERROR)
LD_FLAGS ?= -lpthread -lrt

HEADER = $(dir $(shell find . -name "osmplib.h"))
#LIB = $(shell find . -name "*.a")
#LIB ?= $(shell find . -name "*.o")
LIB = $(BUILD_DIR)/libosmp.a

TESTS = $(basename $(notdir $(shell find testsuite -name "testcase*.c")))

test : $(BUILD_DIR) $(foreach T, $(TESTS), $(BUILD_DIR)/$T)

$(BUILD_DIR)/% : testsuite/%.c $(LIB)
	$(CC) $^ $(LIB) $(CC_FLAGS) $(LD_FLAGS) -Itestsuite -I$(HEADER) -o $@

.PHONY : test
