CXX := g++
CXXFLAGS := $(shell sdl2-config --cflags) -std=c++14 
LDFLAGS := $(shell sdl2-config --libs) -lSDL2_ttf -lSDL2_image

BUILD_DIRECTORY = build
TESTS_DIRECTORY = tests

SOURCES := $(shell find src/* -name *.cpp)
OBJECTS := $(SOURCES:%.cpp=$(BUILD_DIRECTORY)/%.o)
TESTS_SOURCES := $(shell find $(TESTS_DIRECTORY)/* -name *.cpp)
TESTS_OBJECTS := $(TESTS_SOURCES:%.cpp=$(BUILD_DIRECTORY)/%.o)

all: build

$(BUILD_DIRECTORY)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo ┆ CXX ┆ $@
	@$(CXX) -c $(CXXFLAGS) $< -o $@

build: $(OBJECTS)
	@mkdir -p $(dir $@)
	@echo "┆ LD  ┆ Linking..."
	@$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) -o main

tests: $(OBJECTS) $(TESTS_OBJECTS)
	@mkdir -p $(dir $@)
	@echo "┆ LD  ┆ Linking..."
	@$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) $(TESTS_OBJECTS) -o run_tests -lgtest -lgtest_main
	@echo ┆ RUN ┆ Running tests...
	@./run_tests

run: build
	@echo ┆ RUN ┆ Running main...
	@./main

clean:
	rm -rf main $(BUILD_DIRECTORY)
