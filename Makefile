# ============================================================
# CS302 Project 4 Makefile
# OS Priority Scheduler (Heap & Priority Queue)
# ============================================================
#
# This Makefile compiles a multi-file C++ project that uses a
# directory layout to keep source, headers, and build artifacts
# separate:
#
#   project_04/
#   ├── include/          <- Header files (.h)
#   ├── src/              <- Source files (.cpp)
#   ├── build/            <- Compiled objects and executable (generated)
#   └── Makefile
#
# HOW IT WORKS
# ------------
# 1. SRCS lists every .cpp file in src/ that needs to be compiled.
#    When you create a new .cpp file, add it to the SRCS list.
#
# 2. The pattern rule (BUILD_DIR/%.o : SRC_DIR/%.cpp) tells make
#    how to compile any .cpp in src/ into a .o in build/.
#    The -Iinclude flag tells the compiler to look in include/
#    when resolving #include "SomeHeader.h" directives.
#
# 3. The link step combines all .o files into the final executable.
#
# 4. `make clean` removes only build artifacts — your source is safe.
#
# NOTE ON TEMPLATES
# -----------------
# ArrayMaxHeap.h, PriorityQueue.h, and heapSort.h are header-only
# templates. They do NOT appear in SRCS because templates are not
# compiled separately — the compiler sees them when they are
# #included by your item type .cpp files or driver.cpp.
#
# TARGETS
# -------
#   make          Build the executable (default)
#   make run      Build and run the program
#   make clean    Remove all compiled files (build/*.o and the executable)
#
# ============================================================

# --- Compiler and flags ---
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Iinclude

# --- Directory layout ---
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# --- Executable name ---
TARGET = project4

# ------------------------------------------------------------
# Source files — list every .cpp that should be compiled.
#
# Process is included by default. Uncomment your two additional
# item types, then add a backslash (\) to the end of every line
# EXCEPT the last.
#
# Example: if you chose NetworkPacket and PrintJob:
#
#   SRCS = $(SRC_DIR)/driver.cpp \
#          $(SRC_DIR)/Process.cpp \
#          $(SRC_DIR)/NetworkPacket.cpp \
#          $(SRC_DIR)/PrintJob.cpp
#
# ------------------------------------------------------------
SRCS = $(SRC_DIR)/driver.cpp \
       $(SRC_DIR)/Process.cpp \
	   $(SRC_DIR)/NetworkPacket.cpp \
	   $(SRC_DIR)/PrintJob.cpp
# 
# TODO: Add your two chosen item types.
#
# To add a type, add a backslash to the line above and uncomment
# the corresponding line below. For example, if you chose
# NetworkPacket and PrintJob:
#
#   SRCS = $(SRC_DIR)/driver.cpp \
#          $(SRC_DIR)/Process.cpp \
#          $(SRC_DIR)/NetworkPacket.cpp \
#          $(SRC_DIR)/PrintJob.cpp
#
#          $(SRC_DIR)/NetworkPacket.cpp
#          $(SRC_DIR)/DiskRequest.cpp
#          $(SRC_DIR)/Interrupt.cpp
#          $(SRC_DIR)/PrintJob.cpp

# --- Derived variables (you should not need to change these) ---

# Converts each src/Foo.cpp path into build/Foo.o
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Full path to the final executable
EXECUTABLE = $(BUILD_DIR)/$(TARGET)

# Phony targets are not files — they always run when requested
.PHONY: all clean run

# Default target: build the executable
all: $(EXECUTABLE)

# Link step: combine all .o files into the executable
$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJS)

# Pattern rule: compile any src/*.cpp into build/*.o
# @mkdir -p $(BUILD_DIR) silently creates build/ if it doesn't exist yet
# $< is the source file (.cpp), $@ is the output file (.o)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove all build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Build (if needed) then run
run: $(EXECUTABLE)
	$(EXECUTABLE)
