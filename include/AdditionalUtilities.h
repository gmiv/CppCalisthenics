#ifndef ADDITIONALUTILITIES_H
#define ADDITIONALUTILITIES_H

#include <iostream>          // For standard input/output operations (cout, cerr)
#include <filesystem>        // C++17 library for working with files and directories (cross-platform)
#include <optional>          // C++17 library for representing optional values (avoiding null pointers)
#include <variant>           // C++17 library for type-safe union types

// ----------------------------------------------------------------------------
// Section 1: Filesystem Operations with std::filesystem (C++17)
// ----------------------------------------------------------------------------

/*
 * std::filesystem (Modern C++ File Handling):
 *   - Replaces the older, less portable <cstdio> and <dirent.h> libraries for file system operations.
 *   - Provides a clean and consistent interface for working with files, directories, and paths.
 *
 * Key Classes and Functions:
 *   - std::filesystem::path:  Represents a file or directory path in a portable way.
 *   - std::filesystem::exists(path): Checks if a path exists.
 *   - std::filesystem::is_directory(path): Checks if a path is a directory.
 *   - std::filesystem::is_regular_file(path): Checks if a path is a regular file.
 *   - std::filesystem::create_directory(path): Creates a directory.
 *   - std::filesystem::remove(path): Removes a file or directory.
 *   - std::filesystem::copy(source, destination): Copies files or directories.
 *   - std::filesystem::rename(old_path, new_path): Renames a file or directory.
 *   - std::filesystem::file_size(path): Gets the size of a file in bytes.
 *   - ...and many more!
 */

// Function to demonstrate basic filesystem operations
void demoFilesystem() {
    std::cout << "\n--- Filesystem Operations ---\n";

    // 1. Create a Path Object:
    std::filesystem::path p = "example.txt";
    // - Represents the path "example.txt" in your file system.
    // - Automatically handles differences between Windows and Unix-style paths.

    // 2. Check if the File Exists:
    if (std::filesystem::exists(p)) {
        std::cout << "File 'example.txt' exists.\n";
    } else {
        std::cout << "File 'example.txt' does not exist.\n";
    }

    // Uncomment to try other file system operations:
    // std::filesystem::path dir = "my_directory";
    // if (!std::filesystem::exists(dir)) {
    //     std::filesystem::create_directory(dir); // Create a directory
    //     std::cout << "Directory 'my_directory' created.\n";
    // }
}

// ----------------------------------------------------------------------------
// Section 2: Optional Values (std::optional)
// ----------------------------------------------------------------------------

/*
 * std::optional (Nullable Types):
 *   - A template class that represents a value that may or may not exist.
 *   - Safer alternative to using null pointers (nullptr) to indicate the absence of a value.
 *   - Provides a clear way to check if a value is present and access it safely.
 *
 * Key Member Functions:
 *   - has_value(): Returns true if the optional object contains a value.
 *   - value(): Returns the contained value (throws an exception if there's no value).
 *   - value_or(default): Returns the contained value or a default value if there's no value.
 */

// Function to demonstrate std::optional usage
void demoOptionalVariant() {

    std::cout << "\n--- std::optional Demonstration ---\n";

    // 1. Create an optional with a value:
    std::optional<int> opt = 5;
    if (opt.has_value()) { // Check if it has a value
        std::cout << "Optional value: " << opt.value() << "\n"; // Safely access the value
    }

    // 2. Create an empty optional:
    std::optional<int> emptyOpt;
    if (emptyOpt.has_value()) {
        std::cout << "Empty optional has a value!\n"; // This will not be printed
    } else {
        std::cout << "Empty optional has no value.\n";
    }

    // 3. Using value_or():
    std::cout << "Value or default: " << emptyOpt.value_or(0) << std::endl; // Prints 0 (the default)


    std::cout << "\n--- std::variant Demonstration ---\n";
    //------------------------------------------------------------------------------
    // Section 3: Variant Types (std::variant)
    //------------------------------------------------------------------------------

    /*
     * std::variant (Type-Safe Unions):
     *  - Can hold a value of one of several specified types.
     *  - Safer than traditional unions (which lack type safety).
     *  - Use cases:
     *    - Representing values that can be of different types (e.g., an error code that could be an int or a string).
     *    - Implementing state machines where the state can be of different types.
     *
     * Key Member Functions:
     *  - holds_alternative<T>(v): Checks if the variant 'v' currently holds a value of type 'T'.
     *  - get<T>(v): Gets the value of type 'T' from the variant 'v' (throws an exception if the type is incorrect).
     *  - get_if<T>(&v):  Returns a pointer to the value if it's of type 'T', nullptr otherwise.
     */
    std::variant<int, float, std::string> v = "Hello"; // A variant that can hold an int, float, or string

    // Checking the Type:
    if (std::holds_alternative<std::string>(v)) {
        std::cout << "Variant holds a string: " << std::get<std::string>(v) << std::endl;
    }

    // Changing the Value:
    v = 42; // Now it holds an integer
    std::cout << "Variant now holds an int: " << std::get<int>(v) << std::endl;

    try {
        std::get<float>(v); // This will throw an exception because v holds an int, not a float
    } catch (const std::bad_variant_access& e) {
        std::cerr << "Error accessing variant: " << e.what() << std::endl;
    }
}


// Main Function to Run Examples:
void runAdditionalUtilities() {
    demoFilesystem();
    demoOptionalVariant();
}

#endif // ADDITIONALUTILITIES_H
