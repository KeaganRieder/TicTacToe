# Makefile for  missionaries and cannibals problem solver program 

# programs and their associated classes
PROGRAM_NAME = TicTacToe


INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj

SOURCE_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECT_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCE_FILES))

LIBS = # Add necessary libraries here, e.g., -lm, -lGL, etc.

################################################################################
# Compiler setup
################################################################################

# Compiler info
CC = g++
CC_VERSION = -std=c++11
INCLUDE = -I$(INCLUDE_DIR) 
CC_FLAGS = $(CC_VERSION) $(INCLUDE) -static

OS_NAME := $(shell uname -s || echo Windows_NT)

# If operating system is Linux
ifeq ($(OS_NAME), Linux)
    BUILD_TARGET = Compile_Project
    CLEANTARGET = linux_clean

# If operating system is Windows / MINGW64
else ifeq ($(OS_NAME), Windows_NT)
    BUILD_TARGET = Compile_Project
    CLEANTARGET = win_clean

# Operating system is unknown/not set up for building
else
    CC_FLAGS += -DUNKNOWN
    BUILD_TARGET = unknown_build
    CLEANTARGET = unknown_clean

endif

################################################################################
# Build targets
################################################################################

# Default Goal
.DEFAULT_GOAL := All
.PHONY: All clean linux_clean win_clean unknown_clean

################################################################################
# Compilation targets
################################################################################

All: $(BUILD_TARGET)

# Build for Linux or Windows systems 
Compile_Project: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJECT_FILES) $(PROGRAM_NAME).cpp
	$(CC) $(CC_FLAGS) -o $@ $^ $(LIBS)

# Rule to compile .o files from .cpp files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/*.h | $(OBJ_DIR)
	$(CC) $(CC_FLAGS) -c $< -o $@

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Build for unknown or unconfigured system
unknown_build:
	@echo "Can't build. $(OS_NAME) is unknown or not configured."

################################################################################
# Clean-up targets
################################################################################

clean: $(CLEANTARGET)

win_clean:
	rmdir /S /Q $(OBJ_DIR) || true
	del *.o *.exe || true

linux_clean:
	rm -rf $(OBJ_DIR) *.o *.exe

unknown_clean:
	@echo "No clean-up for unknown system."

	
