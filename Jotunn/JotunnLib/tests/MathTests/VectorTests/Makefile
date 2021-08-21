# C++ Compiler
CXX      := -g++
# Compiler Flags
CXXFLAGS := -pedantic-errors -Wall -Wextra -std=c++17

RPATH_LINKAGE := -Wl,-rpath,$(CURDIR)/../../../vendor/ASSIMP/lib,-rpath,$(CURDIR)/../../../build/lib/

LDFLAGS  := -L/usr/lib -lstdc++ -lboost_unit_test_framework -lm -lpthread -L$(CURDIR)/../../../build/lib/ -ljotunn $(RPATH_LINKAGE)

BUILD    	:= ./build
TEST_DIR  	:= $(BUILD)/test
TARGET_TEST := vector_tests

# Includes
INCLUDE  	:= -I../../../include/ -I../../../vendor/SPDLOG/include/

INCLUDE  := 					 	  \
	-I../../../include/ 			  \
	-I../../../vendor/GLM/    	      \
	-I../../../vendor/IMGUI/  		  \
	-I../../../vendor/SPDLOG/include/ \

# Unit Test Files
TEST_FILE := ./VectorTests.cpp

all: build

.PHONY: all build clean debug release

build:
	@mkdir -p $(TEST_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(TEST_DIR)/$(TARGET_TEST) $(TEST_FILE)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(TEST_DIR)/*
