#ifndef VARIABLESANDTYPES_H
#define VARIABLESANDTYPES_H

#include <iostream>       // For input/output operations
#include <string>         // For working with strings
#include <vector>         // For dynamic arrays (vectors)
#include <array>          // For fixed-size arrays
#include <map>            // For key-value pairs (maps)
#include <set>            // For unique elements (sets)
#include <tuple>          // For fixed-size groups of different types (tuples)
#include <cstdint>       // For fixed-width integer types
#include <limits>        // For numerical limits of types
#include <typeinfo>       // For runtime type information

void runVariablesAndTypesExamples() {

    std::cout << "\n--- Basic Types ---\n";

    // 1. Fundamental Integral Types (Integers)
    int age = 30;            // Signed integer (can hold positive and negative values)
    unsigned int numItems = 5; // Unsigned integer (only positive values)
    short shortVar = 100;    // Smaller integer (2 bytes on most systems)
    long long bigNumber = 1e18; // Larger integer (8 bytes on most systems)

    std::cout << "age: " << age << " (int)\n";
    std::cout << "numItems: " << numItems << " (unsigned int)\n";
    std::cout << "shortVar: " << shortVar << " (short)\n";
    std::cout << "bigNumber: " << bigNumber << " (long long)\n";

    // 2. Floating-Point Types (Decimals)
    float pi = 3.14159f;       // Single-precision floating-point (4 bytes)
    double morePrecisePi = 3.14159265359; // Double-precision floating-point (8 bytes)

    std::cout << "pi: " << pi << " (float)\n";
    std::cout << "morePrecisePi: " << morePrecisePi << " (double)\n";

    // 3. Characters and Strings
    char initial = 'G';        // Single character
    std::string name = "Gabriela";   // Sequence of characters (string)

    std::cout << "initial: " << initial << " (char)\n";
    std::cout << "name: " << name << " (string)\n";

    // 4. Boolean
    bool isValid = true;        // True or false value

    std::cout << "isValid: " << isValid << " (bool)\n";

    std::cout << "\n--- Fixed-Width Integers (from <cstdint>) ---\n";

    // Ensure exact sizes across platforms
    int8_t tinyInt = -128;          // 8-bit signed integer
    uint32_t mediumInt = 4294967295; // 32-bit unsigned integer

    std::cout << "tinyInt: " << tinyInt << " (int8_t)\n";
    std::cout << "mediumInt: " << mediumInt << " (uint32_t)\n";

    std::cout << "\n--- STL Containers ---\n";

    // Vector
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "numbers[2]: " << numbers[2] << std::endl;

    // Array
    std::array<char, 5> letters {'H', 'e', 'l', 'l', 'o'};
    std::cout << "letters[0]: " << letters[0] << std::endl;

    // Map
    std::map<std::string, int> ages = {{"Alice", 25}, {"Bob", 30}};
    std::cout << "Alice's age: " << ages["Alice"] << std::endl;

    // Set (Unordered)
    std::set<int> uniqueNums = {3, 1, 4, 1, 5, 9};

    // Iterate through set elements and print them
    std::cout << "Unique numbers in set: ";
    for (const int& num : uniqueNums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    // 5. Tuple (Fixed-Size Collection of Different Types)
    std::tuple<std::string, int, double> person("Bob", 35, 1.85);

    std::cout << "\n--- Tuples ---\n";
    std::cout << "Name: " << std::get<0>(person) << std::endl;
    std::cout << "Age: " << std::get<1>(person) << std::endl;
    std::cout << "Height: " << std::get<2>(person) << std::endl;

    std::cout << "\n--- Type Information (Runtime) ---\n";

    // Type identification at runtime
    std::cout << "Type of age: " << typeid(age).name() << std::endl;
    std::cout << "Type of name: " << typeid(name).name() << std::endl;

}

#endif // VARIABLESANDTYPES_H
