# Makefile for your C++ project

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Directories
SRC_DIR = src
INCLUDE_DIR = headers
BUILD_DIR = build
TARGET = my_program

# List of source files
SOURCES = $(shell find $(SRC_DIR) -name '*.cpp')

# List of object files
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Dependency files
DEPS = $(OBJECTS:.o=.d)

# Default target
all: $(TARGET)

# Build the target executable
$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for creating object files from source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -MMD -MP -c $< -o $@

# Include dependency files
-include $(DEPS)

# Clean up
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# PHONY targets (targets that don't correspond to actual files)
.PHONY: all clean

# Order-only prerequisite for directory creation
$(BUILD_DIR):
	mkdir -p $@
