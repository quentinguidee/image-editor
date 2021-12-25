CXX := g++
CXXFLAGS := $(shell sdl2-config --cflags) -std=c++14 
LDFLAGS := $(shell sdl2-config --libs) -lSDL2_ttf -lSDL2_image

BUILD_DIRECTORY = build
TESTS_DIRECTORY = tests

SOURCES := $(shell find src/* -mindepth 1 -name *.cpp)
OBJECTS := $(SOURCES:%.cpp=$(BUILD_DIRECTORY)/%.o)
TESTS_SOURCES := $(shell find $(TESTS_DIRECTORY)/* -name *.cpp)
TESTS_OBJECTS := $(TESTS_SOURCES:%.cpp=$(BUILD_DIRECTORY)/%.o)

all: main

$(BUILD_DIRECTORY)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) -c $(CXXFLAGS) $< -o $@
	@echo [CXX] $@

main: $(OBJECTS) src/main.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) src/main.cpp -o main
	@echo [CXX] main.cpp

.PHONY: tests
tests: $(OBJECTS) $(TESTS_OBJECTS)
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) $(TESTS_OBJECTS) -o run_tests -lgtest -lgtest_main
	@echo [CXX] tests.cpp
	@echo [TESTS] Running tests...
	@./run_tests

run: main
	@./main

.PHONY: clean
clean:
	rm -rf main $(BUILD_DIRECTORY)
