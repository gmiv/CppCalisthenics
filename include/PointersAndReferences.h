#ifndef TEMPLATESANDGENERICS_H  // Include guard: Prevents this header from being included multiple times.
#define TEMPLATESANDGENERICS_H

#include <iostream>   // For standard input/output (cout)
#include <vector>     // For demonstrating templates with containers
#include <algorithm>  // For std::sort (demonstration of templated algorithms)

// ----------------------------------------------------------------------------
// Section 1: Introduction to Templates in C++ (Generic Programming)
// ----------------------------------------------------------------------------

/*
 * What are Templates?
 *  - Templates are a powerful feature of C++ that enable generic programming.
 *  - They allow you to write code that works with various data types without having to rewrite the code for each specific type.
 *  - Templates provide a blueprint for creating functions or classes that can operate on different types,
 *    promoting code reusability and avoiding redundancy.
 *
 * Two Types of Templates:
 *  1. Function Templates:
 *      - Generalized functions that can work with multiple data types.
 *      - They accept parameters that can be of any type (e.g., int, double, custom classes).
 *      - The compiler generates specialized versions of the function for each type used.
 *
 *  2. Class Templates:
 *      - Generalized classes that can store and manipulate objects of different data types.
 *      - They can have member variables and functions that operate on the template type parameter.
 *      - Similar to function templates, the compiler generates specialized class versions for each type.
 */


//------------------------------------------------------------------------------
// Section 2: Function Templates
//------------------------------------------------------------------------------

/*
 * Function Template Example:
 */

//  Template declaration:
//      - template <typename T>  declares a template with a type parameter 'T'
//      - T is a placeholder for any data type (e.g., int, double, std::string, custom classes).
template <typename T>
// Function definition:
//      - T a and T b are parameters of type 'T'.
T add(T a, T b) {
    return a + b; // Returns the sum of 'a' and 'b'.
    // This assumes that the '+' operator is defined for the type T.
}

//------------------------------------------------------------------------------
// Section 3: Class Templates
//------------------------------------------------------------------------------

/*
 * Class Template Example:
 */
template <typename T>
class Box {
public:
    T content; // Member variable to store the content of the box (can be of any type 'T')
    void setContent(T newContent) { content = newContent; } // Function to set the content
    T getContent() { return content; } // Function to get the content
};



//------------------------------------------------------------------------------
// Section 4: Template Specialization (Customizing Behavior for Specific Types)
//------------------------------------------------------------------------------

/*
 * Template Specialization Example:
 *   - Specializations allow you to provide a specific implementation of a template for a particular data type.
 *   - This gives you the flexibility to tailor the behavior for certain types while using a generic template for others.
 */

// Template specialization for the 'double' type.
// We change the behavior of 'getContent()' for 'double'.
template <> // This means we're specializing the 'Box' template for 'double'
class Box<double> {
public:
    double content;
    void setContent(double newContent) {
        content = newContent;
    }
    double getContent() {
        return content * 2;  // For doubles, we double the content before returning it
    }
};



//------------------------------------------------------------------------------
// Section 5: Variadic Templates (C++11 and Later)
//------------------------------------------------------------------------------

/*
 * Variadic Templates:
 *    - These are templates that can accept a variable number of arguments.
 *    - They are denoted by an ellipsis (...) after the template parameter pack.
 *    - This is very useful when you don't know the number or types of arguments at compile time.
 */

// Example: A function that prints all its arguments
template <typename T, typename... Args> // Parameter pack Args... can hold any number of additional arguments
void print(T first, Args... args) {
    std::cout << first << " "; // Print the first argument
    if constexpr (sizeof...(args) > 0) { // Check if there are more arguments
        print(args...);  // Recursively call 'print' with the remaining arguments
    } else {
        std::cout << "\n"; // If no more arguments, print a newline
    }
}


//------------------------------------------------------------------------------
// Section 6: Demonstrating Templates and Generics
//------------------------------------------------------------------------------
void runTemplatesAndGenerics() {
    std::cout << "Add int: " << add(5, 3) << "\n";  // Calls the add function for integers
    std::cout << "Add double: " << add(2.5, 3.5) << "\n"; // Calls the add function for doubles

    Box<int> intBox;   // Creates a Box object to hold integers
    intBox.setContent(123);
    std::cout << "Box content (int): " << intBox.getContent() << "\n";

    Box<double> doubleBox;  // Creates a Box object to hold doubles (uses the specialization)
    doubleBox.setContent(3.14);
    std::cout << "Box content (double): " << doubleBox.getContent() << "\n"; // Output is 6.28

    print("Mixing", "types", 123, 4.56); // Demonstrate variadic template
}

#endif // TEMPLATESANDGENERICS_H
