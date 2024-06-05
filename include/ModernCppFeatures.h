#ifndef MODERNCPPFEATURES_H
#define MODERNCPPFEATURES_H

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

void demonstrateAutoTypeDeduction() {
    auto i = 42; // int
    auto d = 42.5; // double
    auto s = new std::string("hello"); // std::string*
    std::cout << "Auto-deduced types: " << i << ", " << d << ", " << *s << "\n";
    delete s;
}

void demonstrateLambdas() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n * n << " ";
    });
    std::cout << "\n";
}

void demonstrateSmartPointers() {
    std::unique_ptr<int> p1(new int(42));
    std::shared_ptr<int> p2 = std::make_shared<int>(100);
    std::cout << "Unique pointer value: " << *p1 << ", Shared pointer value: " << *p2 << "\n";
}

void demonstrateRangeBasedForLoops() {
    std::vector<double> vec = {1.1, 2.2, 3.3};
    for (auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

void runModernCppFeatures() {
    demonstrateAutoTypeDeduction();
    demonstrateLambdas();
    demonstrateSmartPointers();
    demonstrateRangeBasedForLoops();
}

#endif
