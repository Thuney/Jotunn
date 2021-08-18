CXX      := -g++
CXXFLAGS := -pedantic-errors -Wall -Wextra

RPATH_LINKAGE := -Wl,-rpath,$(CURDIR)/../../Jotunn/vendor/ASSIMP/lib,-rpath,$(CURDIR)/../../Jotunn/build/lib/

LDFLAGS  := -L/usr/lib -lstdc++ -lm -lpthread -L$(CURDIR)/../../Jotunn/build/lib/ -ljotunn $(RPATH_LINKAGE)

BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := JotunnApplication
INCLUDE  := 					 		  \
	-I./include/ 				 		  \
	-I../../Jotunn/include/ 	  		  \
	-I../../Jotunn/vendor/GLM/    	      \
	-I../../Jotunn/vendor/IMGUI/  		  \
	-I../../Jotunn/vendor/SPDLOG/include/ \


HDRS     :=                           \
			$(wildcard include/*.h)   \

SRC      :=                           \
			$(wildcard src/*.cpp)     \

OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp $(HDRS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(APP_DIR)/$(TARGET) $(OBJECTS) $(LDFLAGS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*