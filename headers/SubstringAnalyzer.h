/**
 * This is C++ code for Homework Group1.
 * 
 * @file SubstringAnalyzer.h
 * @brief Declares functions to detect and analyze repeating substrings in text.
 *
 * Enables detection of recurring substrings (patterns), identifies the longest
 * repeated sequence, and displays most frequent patterns.
 *
 * Authors: 
 *  - Daniel Karnofel
 *  - Eric Shandil  
 * Date: 10/07/2025
 */

#ifndef SUBSTRING_ANALYZER_H
#define SUBSTRING_ANALYZER_H

#include <string>
#include <unordered_map>

/**
 * @brief Finds all repeating substrings in the given text within the specified length range.
 * @param text Cleaned lowercase-only input text.
 * @param minLen Minimum length of substrings to consider.
 * @param maxLen Maximum length of substrings to consider.
 * @return Map of substrings to their occurrence counts (only count > 1 included).
 */
std::unordered_map<std::string, int> findRepeatingSubstrings(const std::string& text, int minLen, int maxLen);

/**
 * @brief Displays the top N most frequent repeated substrings.
 * @param substrMap Map of substrings to their occurrence counts.
 * @param topN Number of top substrings to display.
 */
void displayTopNSubstrings(const std::unordered_map<std::string, int>& substrMap, int topN);

/**
 * @brief Finds the longest substring that repeats more than once.
 * @param substrMap Map of substrings and their counts.
 * @return Longest repeating substring, or empty string if none found.
 */
std::string findLongestRepeatingSubstring(const std::unordered_map<std::string, int>& substrMap);

#endif // SUBSTRING_ANALYZER_H

