CXX := g++
CXXFLAGS := -std=c++11 -I/usr/local/include/SDL2
LDFLAGS := -L/usr/local/lib -lSDL2 -lSDL2_ttf

BUILD_DIRECTORY = build

SOURCES := $(shell find src/* -mindepth 1 -name *.cpp)
OBJECTS := $(SOURCES:%.cpp=$(BUILD_DIRECTORY)/%.o)

all: main

$(BUILD_DIRECTORY)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) -c $(CXXFLAGS) $< -o $@
	@echo [CXX] $@

main: $(OBJECTS) src/main.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) src/main.cpp -o main
	@echo [CXX] main.cpp

run: main
	@./main

.PHONY: clean
clean:
	rm -rf main $(BUILD_DIRECTORY)
