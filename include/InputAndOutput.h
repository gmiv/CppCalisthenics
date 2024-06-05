#ifndef INPUTANDOUTPUT_H
#define INPUTANDOUTPUT_H

#include <iostream>
#include <fstream>

void runInputAndOutputExamples() {
    // Standard output
    std::cout << "Hello, C++!\n";

    // File input/output
    std::ofstream outFile("example.txt");
    outFile << "Writing to a file.\n";
    outFile.close();

    std::ifstream inFile("example.txt");
    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << "\n";
    }
    inFile.close();
}

#endif
