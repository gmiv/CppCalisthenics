#ifndef REGEXEXAMPLES_H    // Include Guard: Prevents multiple inclusions of the header file.
#define REGEXEXAMPLES_H

#include <iostream>      // For standard input/output operations (std::cout)
#include <regex>         // The core C++ regular expression library
#include <string>        // For working with strings

//------------------------------------------------------------------------------
// Section 1: Regular Expressions (Powerful Pattern Matching)
//------------------------------------------------------------------------------

/*
 * What are Regular Expressions?
 *   - A sequence of characters defining a search pattern.
 *   - Used to match or find patterns in text strings.
 *   - Extremely powerful for:
 *     - Validating input (email addresses, phone numbers, etc.)
 *     - Searching and replacing text
 *     - Parsing structured data (log files, configuration files)
 *     - And much more!
 *
 * C++ Regular Expression Library (std::regex):
 *   - A rich library for working with regular expressions.
 *   - Provides classes and functions for:
 *     - Creating regex patterns
 *     - Searching for matches in strings
 *     - Extracting matched parts
 *     - Replacing matched parts
 *
 * Key Classes and Functions:
 *   - std::regex: Represents a regular expression pattern.
 *   - std::smatch: Stores the results of a regular expression match.
 *   - std::regex_search:  Searches for the first match of a pattern in a string.
 *   - std::regex_match:  Checks if a string fully matches a pattern.
 *   - std::regex_replace: Replaces all occurrences of a pattern in a string.
 *
 * Syntax:
 *   - Regular expressions have a concise but powerful syntax with special characters and quantifiers.
 *   - Some basic examples:
 *      - \w: Matches any word character (letter, number, or underscore).
 *      - \d: Matches any digit.
 *      - +: Matches one or more of the preceding element.
 *      - *: Matches zero or more of the preceding element.
 *      - ?: Matches zero or one of the preceding element.
 *      - .: Matches any character except a newline.
 *      - []:..: Matches a range of characters (e.g., [a-z] matches lowercase letters).
 *      - ^: Matches the beginning of a line.
 *      - $: Matches the end of a line.
 *      - (...): Groups a pattern together for backreferencing or capturing.
 *   - For more details, refer to the C++ regex documentation and tutorials.
 */


//------------------------------------------------------------------------------
// Section 2: Function to Demonstrate Regular Expression Search (demoRegexSearch)
//------------------------------------------------------------------------------

/*
 * Function: demoRegexSearch
 * Purpose: Demonstrates how to use std::regex_search to find a pattern (email address) in a string.
 * Parameters:
 *   - text: The string to be searched.
 */
void demoRegexSearch(const std::string& text) {
    std::cout << "\n--- Regular Expression Search Demonstration ---\n";
    // Regex Pattern (Raw String Literal):
    //   - R"(\w+@\w+\.\w+)"
    //     - \w+: One or more word characters (for username)
    //     - @: The literal "@" symbol
    //     - \w+: One or more word characters (for domain name)
    //     - \.: The literal "." (dot) symbol
    //     - \w+: One or more word characters (for top-level domain)
    //   - The raw string literal R"(...)" is used to avoid having to escape backslashes in the pattern.
    std::regex pattern(R"(\w+@\w+\.\w+)");

    // Match Results (smatch):
    std::smatch matches;  // Stores the results of the match (if any)

    // Search for Matches:
    if (std::regex_search(text, matches, pattern)) {  // Search the 'text' for the first match of the 'pattern'
        std::cout << "Found email: " << matches[0] << std::endl; // Print the first match (the entire email address)
        // You can access other submatches (captures) using matches[1], matches[2], etc.
    } else {
        std::cout << "No email address found in the text.\n";
    }
}


//------------------------------------------------------------------------------
// Section 3: Running the Examples (runRegexExamples)
//------------------------------------------------------------------------------

// Function to execute the regex demonstrations
void runRegexExamples() {
    std::string sampleText = "Please contact us at info@example.com."; // Example text containing an email
    demoRegexSearch(sampleText);  // Demonstrate finding the email with regex_search
}

#endif // REGEXEXAMPLES_H
