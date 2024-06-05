#ifndef POINTERSANDREFERENCES_H
#define POINTERSANDREFERENCES_H

#include <iostream>

void demoPointers() {
    int a = 10;
    int* ptr = &a;
    std::cout << "Value of a: " << a << "\n";
    std::cout << "Address of a: " << ptr << "\n";
    std::cout << "Value at address stored in ptr: " << *ptr << "\n";
}

void demoReferences() {
    int x = 5;
    int& ref = x;
    ref = 10;
    std::cout << "Value of x: " << x << "\n";
}

void functionPointerExample() {
    auto add = [](int a, int b) -> int { return a + b; };
    int (*funcPtr)(int, int) = add;
    std::cout << "Result of function pointer call: " << funcPtr(5, 3) << "\n";
}

void runPointersAndReferences() {
    demoPointers();
    demoReferences();
    functionPointerExample();
}

#endif
