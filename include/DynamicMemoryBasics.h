#ifndef DYNAMICMEMORYBASICS_H // Include guard to prevent multiple inclusions
#define DYNAMICMEMORYBASICS_H

#include <iostream> // For standard input/output (cout)

//------------------------------------------------------------------------------
// Section 1: Dynamic Memory Allocation in C++ (The Heap)
//------------------------------------------------------------------------------

/*
 * What is Dynamic Memory Allocation?
 * - In C++, memory is divided into two main regions: the stack and the heap.
 * - Stack: Stores function parameters, local variables, and return addresses. It's managed automatically by the compiler.
 * - Heap: A larger pool of memory available for the programmer to allocate and deallocate manually during runtime.
 *
 * Why Use Dynamic Memory Allocation?
 * - Flexibility: You can create objects or arrays whose size is determined at runtime.
 * - Larger Data: The heap can handle larger amounts of data than the stack.
 * - Persistence: Objects on the heap exist beyond the scope of the function that created them.
 *
 * C++ Operators for Dynamic Memory:
 * - new: Used to allocate memory on the heap.
 * - delete: Used to deallocate memory on the heap.
 *   - delete:  Deallocates a single object.
 *   - delete[]: Deallocates an array of objects.
 *
 * Key Points to Remember:
 * - Always pair a `new` with a `delete` and a `new[]` with a `delete[]`.
 * - Failing to deallocate memory can lead to memory leaks.
 * - Deallocating memory twice can lead to undefined behavior (crashes, data corruption).
 */

//------------------------------------------------------------------------------
// Section 2: Demonstrating new and delete Operators
//------------------------------------------------------------------------------

// Function to demonstrate basic dynamic memory allocation and deallocation for a single int.
void demoNewDelete() {
    std::cout << "\n--- Basic Dynamic Memory Allocation (new/delete) ---\n";

    // 1. Allocate memory for a single int on the heap:
    int* pInt = new int(10);
    //   - pInt: A pointer that holds the memory address of the allocated integer.
    //   - new int(10):
    //     - Allocates enough space on the heap to store an integer.
    //     - Initializes that memory location with the value 10.

    // 2. Access and use the dynamically allocated memory:
    std::cout << "Value at pointer pInt: " << *pInt << "\n"; // Dereference pInt to get the actual value (10).

    // 3. Deallocate the memory:
    delete pInt;
    //   - Releases the memory pointed to by pInt back to the heap.
    //   - It's crucial to do this to prevent memory leaks.


    std::cout << "\n--- Dynamic Array Allocation (new[]/delete[]) ---\n";

    // 1. Allocate memory for an array of 5 integers on the heap:
    int* pArray = new int[5] {1, 2, 3, 4, 5}; // Initialize the array
    //   - pArray: Pointer to the first element of the array.
    //   - new int[5]: Allocates enough space for 5 integers.

    // 2. Access and use the elements of the array:
    for (int i = 0; i < 5; ++i) {
        std::cout << pArray[i] << " ";
    }
    std::cout << "\n";

    // 3. Deallocate the array:
    delete[] pArray;
    //   - This is the correct way to deallocate arrays. Using just 'delete pArray' would only deallocate the first element.
}


#endif // DYNAMICMEMORYBASICS_H
