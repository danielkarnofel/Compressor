# This is C++ code for Homework Group1.
#
# @file Makefile
# @brief Enhanced build and test automation for FileCompressionHelper project.
#
# Supports:
#   - Building (release and debug)
#   - Formatting
#   - Test file generation
#   - Test execution (insertion/selection sort)
#   - Cleanup
#
# Authors:
#   - Daniel Karnofel
#   - Eric Shandil
# Date: 10/07/2025

# ------------------------------------------------------------------
# Compiler and flags
CXX       = clang++
CXXFLAGS  = -std=c++17 -Wall -Wextra -pedantic -O2 -Iheaders

# ------------------------------------------------------------------
# Directories
SRC_DIR   = src
HDR_DIR   = headers
OBJ_DIR   = build
TEST_DIR  = test_files

# ------------------------------------------------------------------
# Executable
TARGET    = FileCompressionHelper

# ------------------------------------------------------------------
# Source and object files
SRCS      = $(wildcard $(SRC_DIR)/*.cpp)
OBJS      = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# ------------------------------------------------------------------
# Color codes for echo output
GREEN     = \033[0;32m
RED       = \033[0;31m
YELLOW    = \033[1;33m
NC        = \033[0m

# ------------------------------------------------------------------
# Default target: Build release binary and test files
all: $(TARGET) tests

# ------------------------------------------------------------------
# Debug target with symbols and DEBUG flag
debug: CXXFLAGS += -g -DDEBUG
debug: clean all
	@echo -e "$(YELLOW)[INFO]$(NC) Built with debug symbols."

# ------------------------------------------------------------------
# Build executable
$(TARGET): $(OBJS)
	@echo -e "$(GREEN)[LINK]$(NC) Creating binary: $@"
	$(CXX) $(CXXFLAGS) -o $@ $^

# ------------------------------------------------------------------
# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo -e "$(GREEN)[COMP]$(NC) Compiling: $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ------------------------------------------------------------------
# Ensure build directory exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# ------------------------------------------------------------------
# Generate test files
tests: $(TEST_DIR)
	@echo -e "$(YELLOW)[TEST]$(NC) Generating test files..."
	@echo "" > $(TEST_DIR)/empty.txt
	@echo "aaaaaa" > $(TEST_DIR)/uniform.txt
	@echo "AaBbCcDdEeFfGg" > $(TEST_DIR)/mixed_case.txt
	@echo "The quick brown fox jumps over the lazy dog. A fast-moving fox is hard to catch." > $(TEST_DIR)/real_text.txt
	@echo "abcabcabcabc xyzxyzxyz defdef ghi" > $(TEST_DIR)/repeating_patterns.txt
	@echo "loremipsumloremipsumloremipsumabcabcabcabc" > $(TEST_DIR)/longest_sequence.txt
	@echo -e "$(GREEN)[DONE]$(NC) Test files generated in $(TEST_DIR)/"

$(TEST_DIR):
	@mkdir -p $(TEST_DIR)

# ------------------------------------------------------------------
# Run with one test file
run: $(TARGET) tests
	@echo -e "$(YELLOW)[RUN]$(NC) Running with sample test file...\n"
	./$(TARGET) $(TEST_DIR)/repeating_patterns.txt 2 10 5 insertion

# ------------------------------------------------------------------
# Run all tests with insertion sort (continue on error)
run_tests_insertion: $(TARGET) tests
	@echo -e "$(YELLOW)[RUN]$(NC) Running all tests with insertion sort...\n"
	@for file in $(TEST_DIR)/*.txt; do \
		echo "======================================"; \
		echo "Running test on file: $$file"; \
		if ./$(TARGET) "$$file" 2 10 5 insertion; then \
			echo -e "$(GREEN)[PASS]$(NC) $$file"; \
		else \
			echo -e "$(RED)[FAIL]$(NC) $$file"; \
		fi; \
		echo ""; \
	done

# ------------------------------------------------------------------
# Run all tests with selection sort (continue on error)
run_tests_selection: $(TARGET) tests
	@echo -e "$(YELLOW)[RUN]$(NC) Running all tests with selection sort...\n"
	@for file in $(TEST_DIR)/*.txt; do \
		echo "======================================"; \
		echo "Running test on file: $$file"; \
		if ./$(TARGET) "$$file" 2 10 5 selection; then \
			echo -e "$(GREEN)[PASS]$(NC) $$file"; \
		else \
			echo -e "$(RED)[FAIL]$(NC) $$file"; \
		fi; \
		echo ""; \
	done

# ------------------------------------------------------------------
# Code formatting using clang-format (optional)
format:
	@echo -e "$(YELLOW)[FORMAT]$(NC) Formatting all source and header files..."
	@find $(SRC_DIR) $(HDR_DIR) -name "*.cpp" -o -name "*.h" | xargs clang-format -i
	@echo -e "$(GREEN)[DONE]$(NC) Code formatted."

# ------------------------------------------------------------------
# Clean all build and test artifacts
clean:
	@echo -e "$(RED)[CLEAN]$(NC) Removing build files and test files..."
	@rm -rf $(OBJ_DIR) $(TARGET) $(TEST_DIR)

# ------------------------------------------------------------------
# Clean only test files
clean_tests:
	@echo -e "$(RED)[CLEAN]$(NC) Removing test files..."
	@rm -rf $(TEST_DIR)

# ------------------------------------------------------------------
.PHONY: all debug clean clean_tests run run_tests_insertion run_tests_selection tests format

