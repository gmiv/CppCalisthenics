#ifndef COMPILEROPTIMIZATIONS_H
#define COMPILEROPTIMIZATIONS_H

#include <iostream>

void loopUnrollingExample() {
    for (int i = 0; i < 1000; i += 5) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void cacheFriendlyCode() {
    int array[1000];
    for (int i = 0; i < 1000; i++) {
        array[i] = i;
    }
    for (int i = 0; i < 1000; i += 10) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

void runCompilerOptimizations() {
    loopUnrollingExample();
    cacheFriendlyCode();
}

#endif
