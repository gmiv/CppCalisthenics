//
// Created by gmora on 6/4/2024.
//

#ifndef VARIABLESANDTYPES_H
#define VARIABLESANDTYPES_H

#include <iostream>

void runVariablesAndTypesExamples() {
    // Example of variable declarations
    int a = 5;
    char b = 'x';
    float c = 3.14f;
    double d = 2.71828;
    bool e = true;

    // Using auto
    auto f = 1.0; // automatically deduces double

    // Printing values
    std::cout << "Integer: " << a << "\n";
    std::cout << "Character: " << b << "\n";
    std::cout << "Float: " << c << "\n";
    std::cout << "Double: " << d << "\n";
    std::cout << "Boolean: " << e << "\n";
    std::cout << "Auto: " << f << "\n";
}

#endif
