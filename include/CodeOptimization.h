#ifndef CODEOPTIMIZATION_H
#define CODEOPTIMIZATION_H

#include <iostream>
#include <vector>

void optimizeVectorAccess(std::vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        v[i] += 10;
    }
}

void optimizeConstUsage() {
    const int iterations = 1000;
    for (int i = 0; i < iterations; ++i) {
        std::cout << "Iteration " << i << "\n";
    }
}

void runCodeOptimization() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    optimizeVectorAccess(data);
    for (int d : data) {
        std::cout << d << " ";
    }
    std::cout << "\n";
    optimizeConstUsage();
}

#endif
