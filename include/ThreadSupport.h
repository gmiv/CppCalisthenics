#ifndef THREADSUPPORT_H
#define THREADSUPPORT_H

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

void basicThreadFunction(int n) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * n));
    std::cout << "Finished thread " << n << "\n";
}

void runThreadSupport() {
    std::vector<std::thread> threads;
    for (int i = 1; i <= 5; ++i) {
        threads.emplace_back(basicThreadFunction, i);
    }
    for (auto& t : threads) {
        t.join();
    }
}

#endif
