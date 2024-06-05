#ifndef CONCURRENTPROGRAMMING_H  // Include guard to prevent multiple inclusions
#define CONCURRENTPROGRAMMING_H

#include <iostream>       // For input/output operations (printing to the console)
#include <thread>         // For creating and managing threads
#include <mutex>          // For mutual exclusion (protecting shared data)
#include <vector>         // For storing a collection of threads
#include <future>         // For asynchronous operations and obtaining results
#include <cmath>          // For mathematical functions (square root, sine, cosine)
#include <chrono>         // For time measurement
#include <random>         // For generating random numbers

// Global mutex to protect the shared output (cout)
std::mutex mtx2;

// Function to simulate a workload for a thread
void simulateWork(int threadId, int workload) {

    // Initialize random number generator
    std::random_device rd;  // Obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard Mersenne Twister 19937 generator
    std::uniform_real_distribution<> dist(0.0, 1.0); // Distribution to generate numbers between 0 and 1

    for (int i = 0; i < workload; ++i) {
        // Perform a series of mathematical calculations
        double result = std::sqrt(std::sin(dist(gen)) * std::cos(dist(gen)));

        // Briefly pause the thread (100 microseconds)
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }

    // Acquire a lock on the mutex to safely print to the console
    std::lock_guard<std::mutex> lock(mtx2);

    // Print a message when the thread completes its work
    std::cout << "Thread " << threadId << " finished work\n";
}

// Main function to demonstrate concurrent programming
void runConcurrentProgramming() {

    // Record the start time for measuring performance
    const auto startTime = std::chrono::high_resolution_clock::now();

    // Determine the optimal number of threads based on the hardware
    const int numThreads = std::thread::hardware_concurrency();

    // Define a large workload for each thread
    const int workloadPerThread = 10000000;

    // Create a vector to hold thread objects
    std::vector<std::thread> threads;

    // Launch multiple threads to perform the work concurrently
    for (int i = 0; i < numThreads; ++i) {
        // Create a thread and add it to the vector
        threads.emplace_back(simulateWork, i, workloadPerThread);
    }

    // Wait for all threads to complete their work
    for (auto& th : threads) {
        th.join();
    }

    // Record the end time
    const auto endTime = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    std::cout << "Time taken: " << duration.count() << " microseconds\n";
}

#endif // CONCURRENTPROGRAMMING_H
