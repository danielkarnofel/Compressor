/**
 * This is C++ code for Homework Group1.
 * 
 * @file FileReader.h
 * @brief Declares function for reading and cleaning text from a file.
 *
 * Reads plain text from a file, removes non-alphabetic characters,
 * and converts all letters to lowercase for uniform analysis.
 *
 * Authors: 
 *  - Daniel Karnofel 
 *  - Eric Shandil  
 * Date: 10/07/2025
 */

#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>

/**
 * @brief Reads and cleans text from a file by removing non-letter characters and converting to lowercase.
 * @param filename Path to the input text file.
 * @return Cleaned lowercase-only string, or empty string on error.
 */
std::string readCleanedTextFromFile(const std::string& filename);

#endif // FILEREADER_H

