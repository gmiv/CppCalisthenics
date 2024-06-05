#ifndef EXCEPTIONHANDLING_H
#define EXCEPTIONHANDLING_H

#include <iostream>       // For input/output operations (std::cout)
#include <stdexcept>      // For standard exception classes (std::exception, std::runtime_error, etc.)
#include <vector>         // To demonstrate an out_of_range exception

//------------------------------------------------------------------------------
// Section 1: Introduction to Exception Handling in C++ (Graceful Error Recovery)
//------------------------------------------------------------------------------

/*
 * What is Exception Handling?
 *  -  A mechanism for dealing with errors or exceptional situations that occur during program execution.
 *  -  Allows you to gracefully handle errors instead of the program crashing abruptly.
 *  -  Essential for writing robust and reliable code that can recover from unexpected problems.
 *
 * Core Components of Exception Handling:
 *  1. try block: Encloses the code that might throw an exception.
 *  2. catch block(s): Handles exceptions thrown within the try block.
 *     - You can have multiple catch blocks to catch different types of exceptions.
 *  3. throw statement: Used to throw an exception object when an error occurs.
 *
 * Exception Handling Benefits:
 *   - Separation of Error Handling:  Keeps your main logic clean and focused.
 *   - Propagating Errors:  Allows errors to be handled at a higher level if not handled locally.
 *   - Resource Management:  Ensures that resources are cleaned up properly even when exceptions occur (RAII).
 *   - Flexible Error Handling:  Provides different strategies for handling different types of errors.
 */


// ----------------------------------------------------------------------------
// Section 2: Custom Exception Class (MyException)
// ----------------------------------------------------------------------------

/*
 *  Custom Exception Class (MyException):
 *    -  A custom exception class allows you to define your own specific type of exception, tailored to the errors your application might encounter.
 *    -  It should inherit from std::exception (or one of its derived classes) to fit into the standard exception hierarchy.
 */
class MyException : public std::exception {  // Inheriting from std::exception
public:
    // Override the virtual what() function to provide a descriptive error message
    const char* what() const noexcept override {
        return "Custom Exception Happened";
    }
};


//------------------------------------------------------------------------------
// Section 3: Function That Throws an Exception (functionThatThrows)
//------------------------------------------------------------------------------

// Function to demonstrate how to throw an exception
void functionThatThrows() {
    // ... some code that might encounter an error ...
    throw MyException();  // Throw a custom exception if an error occurs
}


// ----------------------------------------------------------------------------
// Section 4: Exception Handling Examples (try, catch)
// ----------------------------------------------------------------------------

void runExceptionHandling() {

    std::cout << "\n--- Exception Handling with Custom and Standard Exceptions ---\n";

    // 1. Basic Exception Handling with Custom Exception
    try {
        functionThatThrows();  // Call a function that might throw an exception
    } catch (const MyException& e) {  // Catch the specific MyException type
        std::cerr << "Caught MyException: " << e.what() << std::endl;  // Print the error message
    } catch (const std::exception& e) { // Catch any other standard exceptions
        std::cerr << "Caught std::exception: " << e.what() << std::endl;
    }


    // 2. Example with Standard Library Exception (out_of_range)
    std::cout << "\n--- Exception Handling with std::out_of_range ---\n";
    std::vector<int> numbers = {1, 2, 3};
    try {
        int value = numbers.at(5); // Access an invalid index (out of bounds)
        std::cout << "Value: " << value << std::endl; // This line won't execute if an exception is thrown
    } catch (const std::out_of_range& e) { // Catch the specific std::out_of_range exception
        std::cerr << "Out of range error: " << e.what() << std::endl; // Handle the error gracefully
    }

    // 3. Catch-All Block (catching any type of exception)
    std::cout << "\n--- Catch-All Block for Unknown Exceptions ---\n";
    try {
        throw "Some error occurred"; // Throw a const char* exception
    } catch (...) { // Catch any type of exception (catch-all block)
        std::cerr << "Caught an unknown exception." << std::endl;
    }

    // 4. Exception Handling with Standard Exceptions
    std::cout << "\n--- Exception Handling with Standard Exceptions ---\n";
    try {
        // Attempt to open a file that doesn't exist
        std::ifstream file("nonexistent.txt");
        if (!file) {
            throw std::runtime_error("File not found"); // Throw a runtime_error exception
        }
    } catch (const std::exception& e) { // Catch any standard exception
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // 5. Nested Exception Handling
    std::cout << "\n--- Nested Exception Handling ---\n";
    try {
        try {
            throw std::runtime_error("Inner exception"); // Throw an inner exception
        } catch (const std::exception& e) {
            std::cerr << "Inner exception caught: " << e.what() << std::endl;
            throw; // Re-throw the caught exception to the outer block
        }
    } catch (const std::exception& e) {
        std::cerr << "Outer exception caught: " << e.what() << std::endl;
    }

    // 6. Exception Handling with Multiple Catch Blocks
    std::cout << "\n--- Multiple Catch Blocks for Different Exceptions ---\n";
    try {
        throw std::invalid_argument("Invalid argument"); // Throw an invalid_argument exception
    } catch (const std::invalid_argument& e) { // Catch invalid_argument exceptions
        std::cerr << "Invalid argument exception caught: " << e.what() << std::endl;
    } catch (const std::exception& e) { // Catch any other standard exceptions
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }
}

#endif // EXCEPTIONHANDLING_H
