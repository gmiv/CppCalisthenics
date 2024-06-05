#ifndef FUNCTIONSANDRECURSION_H
#define FUNCTIONSANDRECURSION_H

#include <iostream>

void simpleFunction(int x) {
    std::cout << "Value: " << x << "\n";
}

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void runFunctionsAndRecursionExamples() {
    simpleFunction(10);
    std::cout << "Factorial of 5: " << factorial(5) << "\n";
}

#endif
