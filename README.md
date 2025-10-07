# File Compression Helper

## Overview

**File Compression Helper** is a C++ program that simulates components of file compression by analyzing text files. It counts and sorts letter frequencies and detects repeating letter sequences (substrings) within the text. This mimics key parts of real-world compression techniques such as Huffman Coding and LZ77.

---

## Features

- Reads an input text file (case-insensitive)
- Counts frequency of each letter (A-Z)
- Sorts the frequencies using **Selection Sort** or **Insertion Sort**
- Displays a frequency table with percentages and histograms
- Detects repeating substrings within a configurable length range
- Outputs the **top-N most frequent** repeating substrings
- Identifies the **longest** repeating substring
- Estimates a compression ratio and space savings
- Modular codebase for readability and maintainability

---

## Project Structure

```
./
 |- Makefile 
 |- README.md 
 |- src/ # Source files
 |  |- main.cpp
 |  |- FileReader.cpp
 |  |- FrequencyAnalyzer.cpp
 |  |- SubstringAnalyzer.cpp
 |  |- CompressionEstimator.cpp
 |- headers/ # Header files
 |  |- FileReader.h
 |  |- FrequencyAnalyzer.h
 |  |- SubstringAnalyzer.h
 |  |- CompressionEstimator.h
 |- build/ # Compiled object files
 |- test_files/ # Automatically generated test inputs
 |  |- empty.txt
 |  |- uniform.txt
 |  |- mixed_case.txt
 |  |- real_text.txt
 |  |- repeating_patterns.txt
 |  |- longest_sequence.txt

```

---

## Getting Started

### Prerequisites

- C++ compiler supporting C++17 (e.g., `clang++`, `g++`)
- `make` utility

### Building the Project

To compile the project and generate test files, run:

``` 
make 
```

This will:
- Compile all .cpp files using clang++
- Create the test_files/ directory (if missing)
- Populate test files for various edge cases

### Running the Program

To run the program on a specific file:
./FileCompressionHelper <filename> <minLen> <maxLen> <topN> <insertion|selection>

**Parameters:**
- filename: Path to the input text file
- minLen: Minimum substring length (e.g., 2)
- maxLen: Maximum substring length (e.g., 10)
- topN: Number of top repeating substrings to display
- insertion|selection: Sorting algorithm to use for frequency analysis

**Example**
./FileCompressionHelper test_files/repeating_patterns.txt 2 10 5 insertion

### Run All Tests
To run the program on all test files using **insertion sort**:
```
make run_tests_insertion
```

To run the program on all test files using **selection sort**:
```
make run_tests_selection
```

### Cleaning Up

To remove compiled objects, the executable, and test files:
```
make clean
```

To remove only the test files:
```
make clean_tests
```

---

## Algorithms and Concepts
 - **Letter Frequency Counting:** Case-insensitive counting of characters A–Z
 - **Sorting:** Implements Selection Sort and Insertion Sort
 - **Substring Detection:** Finds repeating substrings using sliding windows
 - **Compression Estimation:** Computes potential space savings from repeated substrings

---

## Real-World Context
This project demonstrates core concepts from real-world compression algorithms:
 - **Huffman Coding:** Compresses more frequent letters with shorter codes
 - **LZ77-style Compression:** Replaces repeated substrings with references

---
