#ifndef ITERATORSANDALGORITHMS_H
#define ITERATORSANDALGORITHMS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

void runIteratorsAndAlgorithms() {
    std::vector<int> v = {5, 3, 1, 4, 2};

    std::cout << "Sorting Vector:\n";
    std::sort(v.begin(), v.end());
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Reversed Vector:\n";
    std::reverse(v.begin(), v.end());
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Lambda Expression Example:\n";
    std::for_each(v.begin(), v.end(), [](int& x) { x *= x; });
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}

#endif
