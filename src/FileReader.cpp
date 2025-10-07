/**
 * This is C++ code for Homework Group1.
 * 
 * @file FileReader.cpp
 * @brief Implements text file reading and cleaning.
 *
 * Reads file content and sanitizes it by keeping only lowercase letters
 * to facilitate frequency and pattern analysis.
 *
 * Authors: 
 *  - Daniel Karnofel
 *  - Eric Shandil
 * Date: 10/07/2025
 */

#include "FileReader.h"
#include <fstream>
#include <cctype>

std::string readCleanedTextFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return "";  // Return empty string on failure
    }

    std::string result;
    char ch;
    while (file.get(ch)) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            // Convert to lowercase and append
            result += std::tolower(ch);
        }
    }

    file.close();
    return result;
}

