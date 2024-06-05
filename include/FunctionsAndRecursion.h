#ifndef FUNCTIONSANDRECURSION_H   // Include guard to prevent multiple inclusions
#define FUNCTIONSANDRECURSION_H

#include <iostream>   // For input/output operations (printing to the console)

//------------------------------------------------------------------------------
// Section 1: Functions (The Building Blocks of C++ Programs)
//------------------------------------------------------------------------------

/*
 *  What are Functions?
 *      - Reusable blocks of code that perform a specific task.
 *      - Help organize code, making it easier to read and maintain.
 *      - Can take input parameters and return a value.
 *
 *  Function Anatomy:
 *      return_type function_name (parameter_list) {
 *          // Body of the function
 *      }
 *
 *  Example:
 */
void simpleFunction(int x) { // Takes an integer parameter 'x' and doesn't return a value (void)
    std::cout << "Value: " << x << "\n"; // Prints the value of 'x' to the console
}

// Another example: Function that adds two numbers and returns the result
int addNumbers(int a, int b) {
    int sum = a + b;
    return sum;
}

//------------------------------------------------------------------------------
// Section 2: Recursion (Functions That Call Themselves)
//------------------------------------------------------------------------------

/*
 *  What is Recursion?
 *      - A programming technique where a function solves a problem by calling itself with a smaller
 *        version of the same problem.
 *      - Has a base case (simplest solution) to prevent infinite loops.
 *
 *  Why Use Recursion?
 *      - Elegant for problems with a self-similar structure (e.g., factorials, Fibonacci sequence, tree traversal).
 *      - Sometimes more concise than iterative solutions.
 *
 *  Caution:
 *      - Can be less efficient than iteration due to function call overhead.
 *      - Use with care to avoid excessive memory usage (stack overflow).
 */

// Example: Recursive function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {         // Base case: Factorial of 0 is 1
        return 1;
    } else {            // Recursive case: Calculate factorial of n-1 and multiply by n
        return n * factorial(n - 1);
    }
}

// Example: Recursive function to print a countdown
void countdown(int n) {
    if (n == 0) {
        std::cout << "Blastoff!\n";
    } else {
        std::cout << n << "...\n";
        countdown(n - 1);
    }
}

//------------------------------------------------------------------------------
// Section 3: Running the Examples
//------------------------------------------------------------------------------

void runFunctionsAndRecursionExamples() {
    std::cout << "\n--- Function Examples ---\n";

    simpleFunction(10);

    int result = addNumbers(5, 7);
    std::cout << "Result of adding 5 and 7: " << result << "\n";

    std::cout << "\n--- Recursion Examples ---\n";

    std::cout << "Factorial of 5: " << factorial(5) << "\n";

    countdown(10);
}

#endif // FUNCTIONSANDRECURSION_H
