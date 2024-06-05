#ifndef MODERNCPPFEATURES_H  // Include guard to prevent multiple inclusions of this header file.
#define MODERNCPPFEATURES_H

#include <iostream>       // For input/output operations (e.g., printing to the console)
#include <memory>         // For smart pointers (unique_ptr, shared_ptr)
#include <vector>         // For dynamic arrays that can grow/shrink
#include <algorithm>      // For standard algorithms (e.g., for_each)

// Function to showcase the use of auto for automatic type deduction
void demonstrateAutoTypeDeduction() {
    // Type Deduction with 'auto'
    // The 'auto' keyword lets the compiler deduce the type based on the assigned value.
    // This enhances code readability and reduces the need for explicit type declarations.

    auto i = 42;          // Compiler deduces 'i' as an int
    auto d = 42.5;        // Compiler deduces 'd' as a double
    auto s = new std::string("hello");  // Compiler deduces 's' as a std::string* (pointer to a string)

    std::cout << "Auto-deduced types: " << i << ", " << d << ", " << *s << "\n"; // Dereference 's' to print string

    delete s;  // Manual memory deallocation because we used 'new'
}


// Function to demonstrate the use of lambda expressions
void demonstrateLambdas() {
    // Lambda Expressions (Anonymous Functions)
    // Lambdas are compact, inline functions defined at the point of use.
    // They're great for short tasks and provide a functional programming style.

    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::for_each(numbers.begin(), numbers.end(), [](int n) {  // Lambda function as the third argument
        std::cout << n * n << " ";  // Square each number and print it
    });
    std::cout << "\n";
}

// Function to demonstrate the use of smart pointers
void demonstrateSmartPointers() {
    // Smart Pointers (Automatic Memory Management)
    // These pointers help prevent memory leaks by automatically managing the lifetime of objects they point to.

    // Unique Pointer (Exclusive Ownership)
    // Only one unique_ptr can own a resource.  The resource is deleted when the unique_ptr goes out of scope.
    std::unique_ptr<int> p1(new int(42));

    // Shared Pointer (Shared Ownership)
    // Multiple shared_ptrs can manage the same resource.  The resource is deleted when the last shared_ptr is destroyed.
    std::shared_ptr<int> p2 = std::make_shared<int>(100); // Recommended way to create shared_ptr

    std::cout << "Unique pointer value: " << *p1 << ", Shared pointer value: " << *p2 << "\n";
}

// Function to showcase range-based for loops, a simplified way to iterate over containers
void demonstrateRangeBasedForLoops() {
    // Range-Based For Loops (Easy Iteration)
    // This C++11 feature makes it much simpler to loop through elements in containers like vectors or arrays.

    std::vector<double> vec = {1.1, 2.2, 3.3};

    // Loop through each 'val' in 'vec'
    for (auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}


// Main function to run all demonstrations in this header file7
void runModernCppFeatures() {
    demonstrateAutoTypeDeduction();
    demonstrateLambdas();
    demonstrateSmartPointers();
    demonstrateRangeBasedForLoops();
}

#endif // MODERNCPPFEATURES_H
