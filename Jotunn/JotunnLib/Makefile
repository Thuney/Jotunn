# C++ Compiler
CXX      := -g++
# Compiler Flags
CXXFLAGS := -pedantic-errors -Wall -Wextra -std=c++17 -fPIC -shared

# Linking flags
LDFLAGS  := -L/usr/lib -lstdc++ -lm -lpthread -lfmt

BUILD    	:= ./build
OBJ_DIR  	:= $(BUILD)/objects
LIB_DIR  	:= $(BUILD)/lib
TARGET_LIB  := libjotunnlib.so

# Includes
INCLUDE  	:= 			        \
	-I./include/                \

# Headers
HDRS     :=                          	         \
	$(wildcard include/Debugging/Logging/*.h)    \
	$(wildcard include/Util/*.h)                 \
	$(wildcard include/Math/*.h)                 \

# Sources
SRC      :=                           			 \
	$(wildcard src/Debugging/Logging/*.cpp)      \
	$(wildcard src/Util/*.cpp)                   \
	$(wildcard src/Math/*.cpp)                   \

# Derive names of object files from our source files
OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(LIB_DIR)/$(TARGET_LIB)

# Compile our object files
$(OBJ_DIR)/%.o: %.cpp $(HDRS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

# Compile our library
$(LIB_DIR)/$(TARGET_LIB): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(LIB_DIR)/$(TARGET_LIB) $(OBJECTS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(LIB_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(LIB_DIR)/*
