#ifndef THREADSUPPORT_H    // Include Guard
#define THREADSUPPORT_H

#include <iostream>       // For input/output operations (cout)
#include <thread>         // The core C++ threading library
#include <mutex>          // For mutual exclusion to synchronize access to shared resources
#include <vector>         // For storing a dynamic collection of threads
#include <chrono>         // For working with time durations (sleep)

//------------------------------------------------------------------------------
// Section 1: Threads in C++ (Concurrent Execution)
//------------------------------------------------------------------------------

/*
 * What are Threads?
 *   - Independent sequences of execution within a single process.
 *   - They share the same address space and can access the same data.
 *   - Allow you to achieve concurrency (running multiple tasks seemingly simultaneously) on modern multi-core CPUs.
 *
 * Why Use Threads?
 *   - Improved Responsiveness: Keep your application responsive while doing background work.
 *   - Parallelism: Speed up computations by dividing tasks across multiple cores.
 *   - Resource Utilization: Make efficient use of hardware by utilizing idle CPU cores.
 *   - Asynchronous Operations:  Perform tasks (e.g., network requests, file I/O) concurrently without blocking the main thread.
 *
 * Thread Concepts:
 *   - Thread Creation:  Done using `std::thread` objects.
 *   - Thread Function:  The code each thread executes.
 *   - Joining Threads: Waiting for a thread to finish using `join()`.
 *   - Thread Safety:  Ensuring that shared data is accessed correctly using synchronization tools like mutexes.
 */

//------------------------------------------------------------------------------
// Section 2: Simple Thread Function Example (basicThreadFunction)
//------------------------------------------------------------------------------

/*
 * Function: basicThreadFunction()
 * Purpose: A simple function that simulates some work by sleeping for a certain duration.
 * Parameters:
 *    - n: A unique number to identify each thread in the output.
 */
void basicThreadFunction(int n) {

    // Simulate work (by sleeping)
    // `std::this_thread::sleep_for`: Pauses the current thread's execution for a specified duration.
    // In this case, the duration is calculated based on the thread's ID (`n`) multiplied by 100 milliseconds.
    // This helps illustrate threads running at different speeds and finishing at different times.
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * n));

    // Safe Printing: Use a mutex to avoid garbled output from multiple threads writing to the console at the same time.
    // Explanation below in 'runThreadSupport' function.
    std::cout << "Finished thread " << n << "\n";  // Output the thread's ID upon completion
}


//------------------------------------------------------------------------------
// Section 3: Demonstrating Thread Creation and Management (runThreadSupport)
//------------------------------------------------------------------------------

/*
 * Function: runThreadSupport()
 * Purpose: This function demonstrates the creation, management, and joining of threads in C++.
 */
void runThreadSupport() {
    std::cout << "\n--- Threading Demonstration ---\n";

    // 1. Create a vector to store thread objects:
    std::vector<std::thread> threads; // Dynamically resizable array of std::thread objects

    // 2. Launch 5 threads:
    for (int i = 1; i <= 5; ++i) {
        // Each thread is created with:
        // - The function 'basicThreadFunction' as the entry point for execution.
        // - The loop counter 'i' as an argument to the function (to uniquely identify each thread).
        threads.emplace_back(basicThreadFunction, i);
        // Note: 'emplace_back' is an efficient way to construct an object in place within the vector
    }

    // 3. Join all threads:
    // - The main thread will wait here until all the threads in the 'threads' vector have finished executing.
    // - This is important to ensure that the program doesn't terminate before all threads complete their work.
    for (auto& t : threads) {
        t.join(); // Join each thread, blocks the main thread until the joined thread finishes
    }

    std::cout << "All threads completed.\n";
}

#endif // THREADSUPPORT_H
