#ifndef FLOWCONTROL_H  // Include guard to prevent multiple inclusions
#define FLOWCONTROL_H

#include <iostream>  // For input/output operations (e.g., printing to the console)

// Function to demonstrate various flow control structures
void runFlowControlExamples() {

    std::cout << "\n--- Conditional Statements (If-Else) ---\n";
    // Conditional Statements (If-Else)
    // These statements control the execution of code based on whether certain conditions are true or false.

    // Example 1: Grading a score
    int score = 85;
    if (score > 90) {                 // Check if score is above 90
        std::cout << "Great!\n";     // Execute if true
    } else if (score > 75) {         // Check if score is above 75 (only if the previous condition was false)
        std::cout << "Good!\n";      // Execute if true
    } else {                        // If neither of the above conditions are true
        std::cout << "Try harder!\n"; // Execute this block
    }

    // Example 2: Checking for even or odd number
    int num = 7;
    if (num % 2 == 0) {           // % is the modulo operator (returns the remainder of division)
        std::cout << num << " is even\n";
    } else {
        std::cout << num << " is odd\n";
    }

    std::cout << "\n--- Iteration Statements (Loops) ---\n";

    // Iteration Statements (Loops)
    // Loops repeatedly execute a block of code until a specific condition is met.

    // 1. While Loop
    // Executes as long as the condition in the parentheses remains true.
    std::cout << "\nWhile loop:\n";
    int count = 0;
    while (count < 5) {          // Loop condition
        std::cout << "Count: " << count << "\n";
        ++count;                 // Increment count (important to avoid infinite loops!)
    }

    // 2. Do-While Loop (At Least Once Execution)
    // Guarantees the loop body executes at least once, then checks the condition.
    std::cout << "\nDo-while loop:\n";
    int i = 5;
    do {
        std::cout << "i: " << i << "\n";
        --i;
    } while (i > 0);

    // 3. For Loop (Counter-Controlled)
    // Ideal for iterating a known number of times.
    std::cout << "\nFor loop:\n";
    for (int j = 0; j < 3; j++) {  // Initialization; Condition; Update
        std::cout << "j: " << j << "\n";
    }

    // 4. Range-Based For Loop (C++11 and later)
    // Convenient way to iterate over elements in containers like vectors or arrays.
    std::cout << "\nRange-based for loop:\n";
    std::vector<std::string> names = {"Alice", "Bob", "Charlie"};
    for (const std::string& name : names) {
        std::cout << name << " ";
    }
    std::cout << "\n";

    std::cout << "\n--- Jump Statements ---\n";

    // Jump Statements (Breaking and Continuing)
    // These statements allow you to alter the normal flow of loops.

    // 1. Break Statement (Exit Loop)
    std::cout << "\nBreak statement:\n";
    for (int k = 0; k < 10; k++) {
        if (k == 5) {
            break;  // Exit the loop immediately when k reaches 5
        }
        std::cout << k << " ";
    }
    std::cout << "\n";

    // 2. Continue Statement (Skip to Next Iteration)
    std::cout << "\nContinue statement:\n";
    for (int l = 0; l < 10; l++) {
        if (l % 2 == 0) {
            continue;  // Skip even numbers
        }
        std::cout << l << " ";
    }
    std::cout << "\n";
}

#endif // FLOWCONTROL_H
