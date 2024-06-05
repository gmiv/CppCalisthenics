#ifndef FLOWCONTROL_H
#define FLOWCONTROL_H

#include <iostream>

void runFlowControlExamples() {
    // If-else example
    int score = 85;
    if (score > 90) {
        std::cout << "Great!\n";
    } else if (score > 75) {
        std::cout << "Good!\n";
    } else {
        std::cout << "Try harder!\n";
    }

    // While loop example
    int count = 0;
    while (count < 5) {
        std::cout << "Count: " << count << "\n";
        ++count;
    }
}

#endif
