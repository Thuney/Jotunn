# C++ Compiler
CXX      := -g++
# Compiler Flags
CXXFLAGS := -pedantic-errors -Wall -Wextra -std=c++17 -fPIC -shared

# Vendor linkages
LDVENDORFLAGS :=                                   \
	-L$(CURDIR)/../vendor/IMGUI/ 			       \
	-L$(CURDIR)/../JotunnLib/build/lib -ljotunnlib \

# Linking flags
LDFLAGS  := -L/usr/lib -lstdc++ -lm -lpthread -lGL -lglfw -lGLEW -lassimp -lfmt $(LDVENDORFLAGS)

BUILD    	:= ./build
OBJ_DIR  	:= $(BUILD)/objects
LIB_DIR  	:= $(BUILD)/lib
TARGET_LIB  := libjotunn.so

# Includes
INCLUDE  	:= 			                  \
	-I./include/                  		  \
	-I$(CURDIR)/../JotunnLib/include/     \
	-I$(CURDIR)/../vendor/IMGUI/          \

# Headers
HDRS     :=                          	              \
	$(wildcard include/Core/Engine/*.h)               \
	$(wildcard include/Core/Event/*.h)                \
	$(wildcard include/Core/*.h)                      \
													  \
	$(wildcard include/Graphics/MeshFactory/*.h)      \
	$(wildcard include/Graphics/*.h)                  \
                                                      \
	$(wildcard include/Platform/Graphics/*.h)         \
	$(wildcard include/Platform/Windowing/GLFW/*.h)   \

# Sources
SRC      :=                           			      \
	$(wildcard src/Core/Engine/*.cpp)                 \
	$(wildcard src/Core/Event/*.cpp)                  \
	$(wildcard src/Core/*.cpp)                        \
                                                      \
	$(wildcard src/Graphics/MeshFactory/*.cpp)        \
	$(wildcard src/Graphics/*.cpp)                    \
                                                      \
	$(wildcard src/Platform/Graphics/*.cpp)           \
	$(wildcard src/Platform/Windowing/GLFW/*.cpp)     \
                                                      \
	$(wildcard $(CURDIR)/../vendor/IMGUI/*.cpp)                    \
	$(CURDIR)/../vendor/IMGUI/examples/imgui_impl_glfw.cpp         \
	$(CURDIR)/../vendor/IMGUI/examples/imgui_impl_opengl3.cpp      \

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
