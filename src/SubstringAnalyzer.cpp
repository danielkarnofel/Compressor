/**
 * This is C++ code for Homework Group1.
 * 
 * @file SubstringAnalyzer.cpp
 * @brief Implements functions to find and display repeated substrings.
 *
 * Identifies recurring substrings of specified lengths and analyzes
 * their frequency, allowing detection of repeating patterns in text.
 *
 * Authors: 
 *  - Daniel Karnofel
 *  - Eric Shandil
 * Date: 10/07/2025
 */

#include "SubstringAnalyzer.h"
#include <iostream>
#include <vector>
#include <algorithm>

std::unordered_map<std::string, int> findRepeatingSubstrings(const std::string& text, int minLen, int maxLen) {
    std::unordered_map<std::string, int> substrMap;

    // Slide window for each length from min to max
    for (int len = minLen; len <= maxLen; ++len) {
        for (size_t i = 0; i + len <= text.length(); ++i) {
            std::string substr = text.substr(i, len);
            substrMap[substr]++;
        }
    }

    // Remove substrings that appear only once
    for (auto it = substrMap.begin(); it != substrMap.end(); ) {
        if (it->second <= 1) {
            it = substrMap.erase(it);
        } else {
            ++it;
        }
    }

    return substrMap;
}

/**
 * @brief Displays the top N most frequently repeated substrings.
 * 
 * @param substrMap Map of substrings and their counts.
 * @param topN Number of top substrings to display.
 * 
 * If no repeated substrings are found, outputs an appropriate message.
 */
void displayTopNSubstrings(const std::unordered_map<std::string, int>& substrMap, int topN) {
    // Filter substrings repeated more than once
    std::vector<std::pair<std::string, int>> repeated;
    for (const auto& pair : substrMap) {
        if (pair.second > 1) {
            repeated.push_back(pair);
        }
    }

    if (repeated.empty()) {
        std::cout << "\nNo repeating substrings found.\n";
        return;
    }

    // Sort by frequency descending
    std::sort(repeated.begin(), repeated.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    std::cout << "\nTop " << topN << " Repeating Substrings:\n";
    std::cout << "Substring\tCount\n";

    // Output topN or fewer if less available
    for (int i = 0; i < std::min(topN, static_cast<int>(repeated.size())); ++i) {
        std::cout << repeated[i].first << "\t\t" << repeated[i].second << "\n";
    }
}

/**
 * @brief Finds the longest substring repeated more than once.
 * 
 * @param substrMap Map of substrings and their counts.
 * @return std::string The longest repeating substring, or empty if none found.
 */
std::string findLongestRepeatingSubstring(const std::unordered_map<std::string, int>& substrMap) {
    std::string longest;
    for (const auto& [substr, count] : substrMap) {
        if (count > 1 && static_cast<int>(substr.length()) > static_cast<int>(longest.length())) {
            longest = substr;
        }
    }
    return longest;
}
