#ifndef BYTESTREAMING_H
#define BYTESTREAMING_H

#include <iostream>       // For standard input/output operations (cout, cerr)
#include <fstream>        // For working with files (reading and writing binary data)
#include <vector>         // For demonstrating serialization/deserialization of data containers
#include <cstring>        // For memcpy used in serialization/deserialization

//------------------------------------------------------------------------------
// Section 1: Introduction to Byte Streams (Binary Data)
//------------------------------------------------------------------------------

/*
 * What are Byte Streams?
 * - Byte streams are a way to work with data at its most fundamental level: as a sequence of raw bytes.
 * - Unlike text streams, which interpret characters and formatting, byte streams treat everything as binary data.
 * - This is crucial for:
 *      - Storing data efficiently (no text formatting overhead)
 *      - Working with non-textual data (images, audio, custom file formats)
 *      - Transferring data across networks or systems
 *
 * C++ Tools for Byte Streams:
 * - ofstream (output file stream): For writing byte data to files.
 * - ifstream (input file stream): For reading byte data from files.
 * - read() and write() functions: The core functions for interacting with byte streams.
 * - reinterpret_cast<char*>: Converts data to raw bytes for writing/reading.
 */

//------------------------------------------------------------------------------
// Section 2: Example - Reading and Writing Binary Files
//------------------------------------------------------------------------------

/*
 * Function: binaryReadWrite()
 *
 * Purpose: Demonstrates how to write binary data to a file and read it back.
 */
void binaryReadWrite() {
    // Filename:
    const char* filename = "example.bin"; // Name of the binary file to be created.

    std::cout << "\n--- Binary File I/O ---\n";

    // Writing Binary Data:
    std::ofstream outFile(filename, std::ios::binary);
    // - Opens the file `example.bin` in binary mode (`std::ios::binary`).
    // - This mode is essential for writing raw bytes without text formatting.

    // Error Handling:
    if (!outFile) {  // Check if the file opened successfully
        std::cerr << "Error: Cannot open file '" << filename << "' for writing.\n"; // Print error to standard error stream.
        return;       // Exit the function if there's an error.
    }

    int writeData = 1234; // Example data to write.

    // Write the Data:
    outFile.write(reinterpret_cast<const char*>(&writeData), sizeof(writeData));
    // - reinterpret_cast<const char*>(&writeData):  Treats the address of the integer as a pointer to a constant char array (raw bytes).
    // - sizeof(writeData):  Determines the size of the integer (usually 4 bytes), ensuring we write the correct number of bytes.

    outFile.close(); // Close the output file stream.

    // Reading Binary Data:
    std::ifstream inFile(filename, std::ios::binary); // Open the file in binary mode for reading.

    // Error Handling:
    if (!inFile) {
        std::cerr << "Error: Cannot open file '" << filename << "' for reading.\n";
        return;
    }

    int readData = 0; // Initialize a variable to store the read integer.

    // Read the Data:
    inFile.read(reinterpret_cast<char*>(&readData), sizeof(readData));
    // - Reads the raw bytes from the file and interprets them as an integer.

    std::cout << "Read integer from file '" << filename << "': " << readData << std::endl; // Print the read integer to standard output.

    inFile.close(); // Close the input file stream.
}


//------------------------------------------------------------------------------
// Section 3: Serialization and Deserialization (Object Persistence)
//------------------------------------------------------------------------------

/*
 * What is Serialization?
 *   - The process of converting an object's state into a format (usually byte stream)
 *     that can be stored in a file or transmitted over a network.
 *   - This allows you to save and later restore the object's data.
 *
 * What is Deserialization?
 *   - The reverse of serialization. It's the process of reconstructing an object
 *     from the stored or transmitted data.
 *
 * Example Class (MyData):
 *   - A simple struct to represent the data we'll serialize and deserialize.
 */
class MyData {
public:
    int id;        // Data member to hold an integer ID.
    double value;  // Data member to hold a floating-point value.

    MyData(int id, double value) : id(id), value(value) {} // Constructor
};

// Function to demonstrate serialization:
void serializeData() {
    std::cout << "\n--- Object Serialization ---\n";

    MyData data(1, 3.14159); // Create a sample MyData object.

    std::ofstream ofs("data.bin", std::ios::binary); // Open file "data.bin" in binary mode for writing.

    // Write the Object to the File:
    ofs.write(reinterpret_cast<const char*>(&data), sizeof(data)); // Write the raw bytes of the object to the file.

    ofs.close();
}

// Function to demonstrate deserialization:
void deserializeData() {
    std::cout << "\n--- Object Deserialization ---\n";

    MyData data(0, 0.0); // Create a MyData object to hold the deserialized data.

    std::ifstream ifs("data.bin", std::ios::binary); // Open the file in binary mode for reading.

    // Read the Object from the File:
    ifs.read(reinterpret_cast<char*>(&data), sizeof(data)); // Read the raw bytes from the file into the object.

    std::cout << "Deserialized Data - ID: " << data.id << ", Value: " << data.value << std::endl;

    ifs.close();
}

void runByteStreamingExamples() {
    binaryReadWrite(); // Demonstrate basic binary file I/O
    serializeData();  // Demonstrate object serialization
    deserializeData(); // Demonstrate object deserialization
}

#endif // BYTESTREAMING_H
