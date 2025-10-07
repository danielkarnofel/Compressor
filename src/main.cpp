/**
 * This is C++ code for Homework Group1.
 * 
 * @file main.cpp
 * @brief Entry point for the FileCompressionHelper program.
 *
 * This program orchestrates the process of reading and cleaning a text file,
 * analyzing letter frequencies, detecting repeated substrings within user-defined
 * length ranges, displaying frequency and substring statistics, and estimating
 * compression savings based on repeated substrings.
 *
 * Usage:
 *   ./FileCompressionHelper <filename> <minLen> <maxLen> <topN> <insertion|selection>
 *
 * Authors:
 *  - Daniel Karnofel
 *  - Eric Shandil
 * Date: 10/07/2025
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "FileReader.h"
#include "FrequencyAnalyzer.h"
#include "SubstringAnalyzer.h"
#include "CompressionEstimator.h"

struct ProgramOptions {
    std::string filename;
    int minLen;
    int maxLen;
    int topN;
    std::string sortChoice;
};

void printUsage() {
    std::cout << "Usage: ./FileCompressionHelper <filename> <minLen> <maxLen> <topN> <insertion|selection>\n"
              << "  filename   - Path to the input text file.\n"
              << "  minLen     - Minimum substring length (integer > 0).\n"
              << "  maxLen     - Maximum substring length (integer >= minLen).\n"
              << "  topN       - Number of top repeated substrings to display.\n"
              << "  insertion|selection - Sorting algorithm choice for frequency analysis.\n";
}

bool parseArguments(int argc, char* argv[], ProgramOptions& options) {
    if (argc < 6) {
        printUsage();
        return false;
    }

    try {
        options.filename = argv[1];
        options.minLen = std::stoi(argv[2]);
        options.maxLen = std::stoi(argv[3]);
        options.topN = std::stoi(argv[4]);
        options.sortChoice = argv[5];

        if (options.minLen <= 0) {
            std::cerr << "Error: minLen must be greater than 0.\n";
            return false;
        }
        if (options.maxLen < options.minLen) {
            std::cerr << "Error: maxLen must be greater than or equal to minLen.\n";
            return false;
        }
        if (options.topN <= 0) {
            std::cerr << "Error: topN must be greater than 0.\n";
            return false;
        }
        if (options.sortChoice != "insertion" && options.sortChoice != "selection") {
            std::cerr << "Error: sortChoice must be either 'insertion' or 'selection'.\n";
            return false;
        }
    } catch (const std::invalid_argument&) {
        std::cerr << "Error: Invalid argument type. Expected integers for minLen, maxLen, and topN.\n";
        return false;
    } catch (const std::out_of_range&) {
        std::cerr << "Error: Argument out of range.\n";
        return false;
    }

    return true;
}

int main(int argc, char* argv[]) {
    ProgramOptions options;

    if (!parseArguments(argc, argv, options)) {
        return 1;
    }

    // Step 2: Read and clean file
    std::string cleanText = readCleanedTextFromFile(options.filename);
    if (cleanText.empty()) {
        std::cerr << "Error: File is empty or contains no valid letters.\n";
        return 1;
    }

    // Step 3: Count frequencies
    LetterFreq freq[26] = {};
    countLetterFrequencies(cleanText, freq);

    // Step 4: Sort
    if (options.sortChoice == "insertion") {
        insertionSort(freq, 26);
    } else { // selection
        selectionSort(freq, 26);
    }

    // Step 5: Display frequencies
    displayFrequencies(freq, 26);

    // Step 6–8: Substring analysis
    auto substrMap = findRepeatingSubstrings(cleanText, options.minLen, options.maxLen);
    displayTopNSubstrings(substrMap, options.topN);
    std::string longest = findLongestRepeatingSubstring(substrMap);

    if (!longest.empty()) {
        std::cout << "\nLongest Repeating Substring: " << longest << "\n";
    } else {
        std::cout << "\nNo repeating substrings found.\n";
    }

    // Step 9: Compression stats
    estimateCompressionStats(cleanText, substrMap, options.minLen, options.maxLen);

    return 0;
}

