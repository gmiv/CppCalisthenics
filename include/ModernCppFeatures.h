#ifndef MODERNCPPFEATURES_H  // Include guard to prevent multiple inclusions
#define MODERNCPPFEATURES_H

#include <iostream>       // For input/output operations (e.g., std::cout)
#include <memory>         // For smart pointers (std::unique_ptr, std::shared_ptr)
#include <vector>         // For dynamic arrays (std::vector)
#include <algorithm>      // For standard algorithms (e.g., std::for_each)
#include <functional>     // For std::function (used with lambdas)
#include <string_view>    // Lightweight string representation for better performance

// ----------------------------------------------------------------------------
// Section 1: Type Inference with 'auto' (C++11)
// ----------------------------------------------------------------------------

/*
 * auto Keyword:
 *  -  Lets the compiler automatically deduce the type of a variable based on its initializer.
 *  -  Reduces verbosity and makes code more concise, especially with complex types.
 *  -  Improves readability when the type is obvious from the initialization.
 *  -  Important: Use `auto` judiciously to maintain clarity, especially in complex expressions.
 *
 *  Example:
 */

void demonstrateAutoTypeDeduction() {
    std::cout << "\n--- Auto Type Deduction ---\n";
    auto i = 42;           // int
    auto d = 42.5;         // double
    auto s = std::string("hello");  // std::string (not a pointer, std::string is already allocated on heap)

    std::cout << "Auto-deduced types: " << i << " (" << typeid(i).name() << "), "
              << d << " (" << typeid(d).name() << "), "
              << s << " (" << typeid(s).name() << ")\n";
}


// ----------------------------------------------------------------------------
// Section 2: Lambda Expressions (C++11)
// ----------------------------------------------------------------------------
/*
 * Lambda Expressions (Anonymous Functions):
 *   -  Small, self-contained function objects defined inline, often used as arguments to other functions.
 *   -  Syntax: [capture_list] (parameters) -> return_type { function_body }
 *      - capture_list:  Variables from the surrounding scope to capture (by value or reference).
 *      - parameters:  Input parameters to the lambda (optional).
 *      - return_type: The return type of the lambda (optional, inferred if not specified).
 *      - function_body: The code to be executed by the lambda.
 *
 * Use Cases:
 *   - Algorithms:  Passing small functions to algorithms like `std::sort`, `std::find_if`, etc.
 *   - Callbacks: Implementing custom behavior for asynchronous operations or events.
 *   - Functional Programming:  Enables a more functional style of coding.
 */
void demonstrateLambdas() {
    std::cout << "\n--- Lambda Expressions ---\n";
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Lambda without captures
    std::cout << "Squaring each number: ";
    std::for_each(numbers.begin(), numbers.end(), [](int n) { // Lambda to square each element
        std::cout << n * n << " ";
    });
    std::cout << std::endl;

    // Lambda with capture by value
    int factor = 3;
    std::cout << "Multiplying by " << factor << ": ";
    std::for_each(numbers.begin(), numbers.end(), [factor](int n) {  // Captures 'factor' by value
        std::cout << n * factor << " ";
    });
    std::cout << std::endl;

    // Lambda with capture by reference (modifiable)
    int sum = 0;
    std::cout << "Calculating sum: ";
    std::for_each(numbers.begin(), numbers.end(), [&sum](int n) { // Captures 'sum' by reference
        sum += n;
    });
    std::cout << sum << std::endl;
}



// ----------------------------------------------------------------------------
// Section 3: Smart Pointers (unique_ptr, shared_ptr)
// ----------------------------------------------------------------------------
/*
 * Smart Pointers (Automatic Memory Management):
 *   - Shared Pointers (shared_ptr):  Allow multiple owners of a resource (reference counted).
 *     Resource is deleted when the last shared_ptr pointing to it is destroyed.
 *     std::make_shared is preferred for creating shared_ptrs due to exception safety.
 *
 *   - Unique Pointers (unique_ptr): Only one unique_ptr can own a resource.
 *     The resource is deleted when the unique_ptr goes out of scope.
 *     Excellent for exclusive ownership scenarios.
 *
 *   - Weak Pointers (weak_ptr): A non-owning observer of a resource managed by shared_ptr.
 *     Helps break cyclic dependencies and check object lifetime.
 */
void demonstrateSmartPointers() {
    std::cout << "\n--- Smart Pointers ---\n";
    std::unique_ptr<MyClass> uniquePtr(new MyClass()); // create a unique pointer
    uniquePtr->greet();

    std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>(); // create a shared pointer
    sharedPtr1->greet();

    std::shared_ptr<MyClass> sharedPtr2 = sharedPtr1;  // Both pointers manage the same object
    std::cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << std::endl; // prints 2

    sharedPtr1.reset();
    std::cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << std::endl; // prints 0, but object still lives due to sharedPtr2
    std::cout << "sharedPtr2.use_count(): " << sharedPtr2.use_count() << std::endl; // prints 1

    sharedPtr2.reset();
    // The object pointed to by sharedPtr1 and sharedPtr2 is now deleted.

    std::weak_ptr<MyClass> weakPtr = sharedPtr2; // create a weak pointer
    if (auto shared = weakPtr.lock()) {         // Check if the object still exists before using it
        shared->greet();                    // If it does, use the temporarily acquired shared_ptr
    } else {
        std::cout << "Object is no longer available.\n";
    }
}


// ----------------------------------------------------------------------------
// Section 4: Range-based for loops (C++11)
// ----------------------------------------------------------------------------
/*
 * Range-Based For Loops (Easy Iteration):
 *  -  A simplified way to iterate over elements in containers like vectors, arrays, and more.
 *  -  Syntax: for ( element_declaration : container ) { loop_statement }
 *      - element_declaration:  Declares a variable that will hold each element from the container in turn.
 *      - container: The container you want to iterate over.
 *  -  Benefits:
 *      - More concise and readable than traditional for loops with iterators.
 *      - Works seamlessly with different container types.
 */
void demonstrateRangeBasedForLoops() {
    std::cout << "\n--- Range-Based For Loops ---\n";
    std::vector<double> vec = {1.1, 2.2, 3.3};
    for (const auto& val : vec) { // Use 'const auto&' for efficiency and to avoid copying elements
        std::cout << val << " ";
    }
    std::cout << std::endl;
}


// ----------------------------------------------------------------------------
// Section 5: Main Runner Function
// ----------------------------------------------------------------------------
void runModernCppFeatures() {
    demonstrateAutoTypeDeduction();
    demonstrateLambdas();
    demonstrateSmartPointers();
    demonstrateRangeBasedForLoops();
}


#endif // MODERNCPPFEATURES_H
