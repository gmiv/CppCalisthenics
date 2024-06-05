#ifndef CONCURRENTPROGRAMMING_H  // Include guard: Prevents this header from being included multiple times in a single compilation unit.
#define CONCURRENTPROGRAMMING_H

#include <iostream>       // For input/output operations, primarily printing to the console using std::cout.
#include <thread>         // The core threading library in C++, providing classes and functions to create and manage threads.
#include <mutex>          // For mutual exclusion to synchronize access to shared resources like std::cout.
#include <vector>         // A dynamic array for storing a collection of thread objects.
#include <future>         // For asynchronous tasks and retrieving their results.
#include <cmath>          // For mathematical operations like square root, sine, and cosine, used in the workload simulation.
#include <chrono>         // For high-resolution time measurement to assess performance.
#include <random>         // For generating random numbers used in the workload simulation.

// Global Mutex for Synchronization (std::mutex):
/*
* A mutex (mutual exclusion) is like a lock. Only one thread can hold the lock at a time.
* This prevents multiple threads from accessing and modifying a shared resource simultaneously, avoiding race conditions and ensuring data integrity.
* In this example, the `mtx2` mutex is used to protect the `std::cout` object, which is a shared resource among all threads.
*/
std::mutex mtx2;

// Function to Simulate Workload (void simulateWork):
/*
* Purpose: This function simulates a computationally intensive task to create a realistic workload for each thread.
* Parameters:
*  - threadId (int): An identifier for the thread to distinguish its output.
*  - workload (int): The amount of work to be simulated, determining the intensity of the computation.
* Workload Simulation:
*  - A random number generator is initialized using std::random_device and std::mt19937 to produce non-deterministic sequences.
*  - A loop iterates 'workload' times, and in each iteration:
*     - Random numbers between 0.0 and 1.0 are generated using std::uniform_real_distribution.
*     - These numbers are used in trigonometric calculations (sin, cos) and a square root operation, simulating CPU-intensive work.
*     - A small delay (100 microseconds) is introduced using std::this_thread::sleep_for to represent real-world scenarios where tasks might have short pauses.
* Synchronization:
*  - The std::lock_guard<std::mutex> object `lock(mtx2)` acquires a lock on the mutex `mtx2`.
*  - This lock ensures that only one thread can access and print to std::cout at a time, preventing jumbled output.
*  - Once the thread's execution leaves the scope of the lock_guard, the lock is automatically released.
* Output:
*  - The thread prints a message indicating its completion after finishing its workload.
*/
void simulateWork(int threadId, int workload) {
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0.0, 1.0);

    for (int i = 0; i < workload; ++i) {
        // Simulate work with a random calculation
        double result = std::sqrt(std::sin(dist(gen)) * std::cos(dist(gen)));

        // Briefly pause the thread (100 microseconds)
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }

    // Safely print the completion message (protected by the mutex)
    std::lock_guard<std::mutex> lock(mtx2);
    std::cout << "Thread " << threadId << " finished work\n";
}

// Main Function for Running Concurrent Programming (void runConcurrentProgramming):
/*
* Purpose: This is the main function that orchestrates the concurrent execution of multiple threads.
* Performance Measurement:
*  - Records the starting time using std::chrono::high_resolution_clock::now() for later performance analysis.
* Thread Management:
*  - Determines the number of threads to create based on the system's hardware concurrency.
*  - Initializes a vector to store the thread objects.
*  - A loop creates and launches multiple threads:
*     - Each thread executes the simulateWork function with a unique thread ID and the same workload.
*     - The created thread objects are added to the vector.
* Joining Threads:
*  - Waits for each thread in the vector to finish by calling the join() method.
*  - This ensures the main thread doesn't end before all worker threads have completed their tasks.
* Performance Output:
*  - Records the end time using std::chrono::high_resolution_clock::now().
*  - Calculates the total time taken by subtracting the start time from the end time.
*  - Prints the calculated execution time to the console.
*/
void runConcurrentProgramming() {
    // Start the performance timer
    const auto startTime = std::chrono::high_resolution_clock::now();

    // Determine the optimal number of threads based on the available hardware threads (cores)
    const int numThreads = std::thread::hardware_concurrency();

    // Define the workload each thread will execute (adjust this for varying intensity)
    const int workloadPerThread = 10000000;

    // Create a vector to store the thread objects for later management
    std::vector<std::thread> threads;

    // Launch multiple threads to perform the work concurrently
    for (int i = 0; i < numThreads; ++i) {
        // Create a new thread and pass the simulateWork function with its arguments
        threads.emplace_back(simulateWork, i, workloadPerThread);
    }

    // Wait for all threads to finish their work before continuing
    for (auto& th : threads) {
        th.join();
    }

    // Stop the performance timer and calculate the elapsed time
    const auto endTime = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    std::cout << "Time taken: " << duration.count() << " microseconds\n";
}

#endif // CONCURRENTPROGRAMMING_H
