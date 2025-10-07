/**
 * This is C++ code for Homework Group1.
 * 
 * @file FrequencyAnalyzer.cpp
 * @brief Implements letter frequency analysis and histogram display.
 *
 * Counts and sorts letter frequencies from 'a' to 'z' and presents
 * the results in a readable histogram format.
 *
 * Authors: 
 *  - Daniel Karnofel
 *  - Eric Shandil
 * Date: 10/07/2025
 */

#include "FrequencyAnalyzer.h"
#include <iostream>
#include <iomanip>

void countLetterFrequencies(const std::string& text, LetterFreq freq[ALPHABET_SIZE]) {
    // Initialize frequency array
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        freq[i].letter = 'a' + i;
        freq[i].count = 0;
        freq[i].percentage = 0.0;
    }

    // Count letter frequencies
    for (char ch : text) {
        if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a'].count++;
        }
    }

    // Calculate percentages
    int total = text.length();
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        freq[i].percentage = 100.0 * freq[i].count / total;
    }
}

void insertionSort(LetterFreq arr[], int size) {
    for (int i = 1; i < size; ++i) {
        LetterFreq key = arr[i];
        int j = i - 1;

        // Move elements greater than key to the right
        while (j >= 0 && arr[j].count < key.count) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(LetterFreq arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int maxIdx = i;

        // Find the maximum element in the rest of array
        for (int j = i + 1; j < size; ++j) {
            if (arr[j].count > arr[maxIdx].count) {
                maxIdx = j;
            }
        }

        // Swap with the first unsorted element
        if (maxIdx != i) {
            std::swap(arr[i], arr[maxIdx]);
        }
    }
}

void displayFrequencies(const LetterFreq arr[], int size) {
    std::cout << "\n--- Letter Frequency Histogram ---\n";

    // Find max count for scaling
    int maxCount = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i].count > maxCount) maxCount = arr[i].count;
    }

    const int maxBarWidth = 50; // max characters per bar

    for (int i = 0; i < size; ++i) {
        if (arr[i].count > 0) {
            // Scale bar length to maxBarWidth
            int barLength = static_cast<int>((double)arr[i].count / maxCount * maxBarWidth);

            std::cout << arr[i].letter << " (" << arr[i].count << ", "
                      << std::fixed << std::setprecision(2)
                      << arr[i].percentage << "%): ";

            for (int j = 0; j < barLength; ++j) {
                std::cout << "#";
            }
            std::cout << "\n";
        }
    }
}

