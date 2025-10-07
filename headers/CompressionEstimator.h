/**
 * This is C++ code for Homework Group1.
 * 
 * @file CompressionEstimator.h
 * @brief Provides functions to estimate compression statistics using repeated substrings.
 *
 * Simulates basic compression estimation by analyzing repeated substrings in text.
 * It estimates how much space could be saved, the compression ratio, and compressed size
 * using dictionary-style compression logic.
 *
 * Authors: 
 *  - Daniel Karnofel 
 *  - Eric Shandil  
 * Date: 10/07/2025
 */

#ifndef COMPRESSION_ESTIMATOR_H
#define COMPRESSION_ESTIMATOR_H

#include <string>
#include <unordered_map>

/**
 * @struct CompressionStats
 * @brief Stores compression results.
 */
struct CompressionStats {
    int originalSize = 0;
    int compressedSize = 0;
    double ratio = 0.0;
    double savings = 0.0;
};

/**
 * @brief Estimates and displays compression statistics using repeating substrings.
 * @param text Cleaned lowercase-only input text.
 * @param substrMap Map of substrings and their occurrence counts.
 * @param minLen Minimum substring length considered for compression.
 * @param maxLen Maximum substring length considered for compression.
 */
void estimateCompressionStats(const std::string& text,
                              const std::unordered_map<std::string, int>& substrMap,
			      int minLen, int maxLen);

#endif // COMPRESSION_ESTIMATOR_H

