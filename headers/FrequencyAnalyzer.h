/**
 * This is C++ code for Homework Group1.
 * 
 * @file FrequencyAnalyzer.h
 * @brief Declares functions for analyzing letter frequencies in text.
 *
 * Provides a struct to store letter statistics, and functions to
 * count, sort, and display letter frequency with histogram output.
 *
 * Authors: 
 *  - Daniel Karnofel
 *  - Eric Shandil  
 * Date: 10/07/2025
 */

#ifndef FREQUENCY_ANALYZER_H
#define FREQUENCY_ANALYZER_H

#include <string>

#define ALPHABET_SIZE 26

/**
 * @struct LetterFreq
 * @brief Holds frequency data for a single letter.
 */
struct LetterFreq {
    char letter = '\0';        ///< 'a' to 'z'
    int count = 0;             ///< Total occurrences
    double percentage = 0.0;   ///< Relative frequency in percentage
};

/**
 * @brief Counts the frequencies of letters 'a' to 'z' in the given text.
 * @param text Input text string (assumed lowercase).
 * @param freq Array of LetterFreq structs of size ALPHABET_SIZE to populate.
 */
void countLetterFrequencies(const std::string& text, LetterFreq freq[ALPHABET_SIZE]);

/**
 * @brief Sorts the frequency array in descending order using insertion sort.
 * @param arr Array of LetterFreq structs to sort.
 * @param size Size of the array.
 */
void insertionSort(LetterFreq arr[], int size);

/**
 * @brief Sorts the frequency array in descending order using selection sort.
 * @param arr Array of LetterFreq structs to sort.
 * @param size Size of the array.
 */
void selectionSort(LetterFreq arr[], int size);

/**
 * @brief Displays the letter frequencies and a histogram.
 * @param arr Array of sorted LetterFreq structs.
 * @param size Size of the array.
 */
void displayFrequencies(const LetterFreq arr[], int size);

#endif // FREQUENCY_ANALYZER_H

