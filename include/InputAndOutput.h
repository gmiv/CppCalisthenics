#ifndef INPUTANDOUTPUT_H  // Include guard to prevent multiple inclusions
#define INPUTANDOUTPUT_H

#include <iostream>      // Provides standard input/output stream objects
#include <fstream>       // Provides file stream objects for working with files
#include <sstream>       // Provides string stream objects for in-memory I/O
#include <iomanip>       // For manipulating output formatting (width, precision, etc.)

// Function to demonstrate input/output operations in C++
void runInputAndOutputExamples() {

    std::cout << "\n--- Standard Output (cout) ---\n";
    // Standard Output (cout)
    /*
     * The 'std::cout' object is used for printing text and data to the standard output stream (typically the console).
     * You use the insertion operator '<<' to send data to cout.
     */

    std::cout << "Hello, C++ World!\n";         // Print a string followed by a newline
    std::cout << "The answer is: " << 42 << "\n"; // Print a string and an integer

    int num = 123;
    double price = 19.99;
    std::cout << "Number: " << num << ", Price: " << price << std::endl; // 'std::endl' also ends the line

    std::cout << "\n--- Output Formatting ---\n";
    // Output Formatting (using manipulators)
    // Manipulators from <iomanip> can be used to control the appearance of output.

    std::cout << std::fixed << std::setprecision(2);  // Set fixed-point notation with 2 decimal places
    std::cout << "Formatted price: $" << price << std::endl;

    std::cout << std::setw(10) << "Left" << std::setw(10) << "Right" << std::endl;  // Set width for columns


    std::cout << "\n--- Standard Input (cin) ---\n";
    // Standard Input (cin)
    /*
     * The 'std::cin' object is used for reading input from the standard input stream (typically the keyboard).
     * You use the extraction operator '>>' to get data from cin.
     */

    std::string userName;
    int userAge;

    std::cout << "Enter your name: ";
    std::getline(std::cin, userName);     // Read a whole line of text, including spaces

    std::cout << "Enter your age: ";
    std::cin >> userAge;                  // Read an integer

    std::cout << "Hello, " << userName << "! You are " << userAge << " years old.\n";



    std::cout << "\n--- File Output (ofstream) ---\n";
    // File Output (ofstream)
    /*
     * The 'std::ofstream' class represents an output file stream. It allows you to write data to files.
     */

    std::ofstream outFile("output.txt"); // Create an output file stream and open the file "output.txt"
    if (outFile.is_open()) {            // Check if the file is opened successfully
        outFile << "Writing to a file.\n"; // Write data to the file
        outFile << "This is another line.\n";
        outFile.close();                // Close the file
    } else {
        std::cerr << "Error opening file for writing!\n"; // Print error to standard error stream (cerr)
    }



    std::cout << "\n--- File Input (ifstream) ---\n";
    // File Input (ifstream)
    /*
     * The 'std::ifstream' class represents an input file stream. It allows you to read data from files.
     */

    std::ifstream inFile("output.txt");  // Create an input file stream and open the file "output.txt"

    if (inFile.is_open()) {             // Check if the file is opened successfully
        std::string line;               // Create a string to store each line read from the file

        // Read the file line by line until the end of file (eof) is reached
        while (std::getline(inFile, line)) {
            std::cout << line << "\n"; // Print each line to the console
        }

        inFile.close();                  // Close the file
    } else {
        std::cerr << "Error opening file for reading!\n";
    }


    std::cout << "\n--- String Streams (stringstream) ---\n";
    // String Streams (stringstream)
    /*
     * 'std::stringstream' objects are used for input and output operations on strings in memory, similar to how
     * you would work with files. This is useful for manipulating strings without directly dealing with file I/O.
     */

    std::stringstream ss;  // Create a stringstream object
    ss << "Hello, ";       // Write data to the stringstream
    ss << "stringstream!";

    std::string result;
    ss >> result;          // Read data from the stringstream into 'result'

    std::cout << result << std::endl; // Output the extracted string
}

#endif // INPUTANDOUTPUT_H
