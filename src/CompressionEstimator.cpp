/**
 * This is C++ code for Homework Group1.
 * 
 * @file CompressionEstimator.cpp
 * @brief Implements logic to estimate compression using repeated substrings.
 *
 * Simulates dictionary-style compression and calculates how much space
 * could be saved using the most repeated substrings in a given text.
 *
 * Authors: 
 *  - Daniel Karnofel
 *  - Eric Shandil
 * Date: 10/07/2025
 */

#include "CompressionEstimator.h"
#include <iostream>
#include <vector>
#include <algorithm>

void estimateCompressionStats(const std::string& text,
                              const std::unordered_map<std::string, int>& substrMap,
                              int minLen, int maxLen) {
    int originalSize = text.length();
    int compressedSize = originalSize;

    // Convert map to vector for sorting, filtering by minLen and maxLen
    std::vector<std::pair<std::string, int>> substrVec;
    for (const auto& pair : substrMap) {
        int len = pair.first.length();
        if (len >= minLen && len <= maxLen) {
            substrVec.push_back(pair);
        }
    }

    // Sort substrings by space saved: length * (count - 1)
    std::sort(substrVec.begin(), substrVec.end(), [](const auto& a, const auto& b) {
        int savingA = a.first.length() * (a.second - 1);
        int savingB = b.first.length() * (b.second - 1);
        return savingA > savingB;
    });

    std::vector<std::string> dictionary;
    const int maxDictSize = 10;

    for (const auto& pair : substrVec) {
        const std::string& substr = pair.first;
        int count = pair.second;

        if (dictionary.size() >= maxDictSize || count <= 1) break;

        // Avoid overlapping or nested substrings
        bool alreadyHandled = false;
        for (const std::string& d : dictionary) {
            if (d.find(substr) != std::string::npos || substr.find(d) != std::string::npos) {
                alreadyHandled = true;
                break;
            }
        }

        if (!alreadyHandled) {
            dictionary.push_back(substr);

            // Save: len * (count - 1) - count (each replaced by 1-byte index)
            int saving = substr.length() * (count - 1) - count;
            compressedSize = std::max(1, compressedSize - saving);
        }
    }

    CompressionStats stats;
    stats.originalSize = originalSize;
    stats.compressedSize = compressedSize;
    stats.ratio = static_cast<double>(compressedSize) / originalSize;
    stats.savings = 100.0 * (originalSize - compressedSize) / originalSize;

    std::cout << "\n--- Compression Estimation ---\n";
    std::cout << "Original Size     : " << stats.originalSize << " bytes\n";
    std::cout << "Compressed Size   : " << stats.compressedSize << " bytes\n";
    std::cout << "Compression Ratio : " << stats.ratio << "\n";
    std::cout << "Space Saved       : " << stats.savings << " %\n";
}

