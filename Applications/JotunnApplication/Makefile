CXX      := -g++
CXXFLAGS := -pedantic-errors -Wall -Wextra

RPATH_LINKAGE := -Wl,-rpath,$(CURDIR)/../../Jotunn/JotunnLib/build/lib/,-rpath,$(CURDIR)/../../Jotunn/Engine/build/lib/

LDFLAGS  := -L/usr/lib -lstdc++ -lm -lpthread -lfmt -L$(CURDIR)/../../Jotunn/Engine/build/lib/ -ljotunn $(RPATH_LINKAGE)

BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := JotunnApplication
INCLUDE  := 					 		            \
	-I./include/ 				 		            \
	-I$(CURDIR)/../../Jotunn/Engine/include/ 	    \
	-I$(CURDIR)/../../Jotunn/JotunnLib/include/ 	\
	-I$(CURDIR)/../../Jotunn/vendor/IMGUI/  		\

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