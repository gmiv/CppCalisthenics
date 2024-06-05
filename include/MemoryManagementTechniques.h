#ifndef MEMORYMANAGEMENTTECHNIQUES_H
#define MEMORYMANAGEMENTTECHNIQUES_H

#include <iostream>
#include <memory>     // For smart pointers (unique_ptr, shared_ptr, weak_ptr)
#include <vector>      // For demonstrating smart pointers with containers

//------------------------------------------------------------------------------
// Section 1: Memory Management in C++ (RAII and Smart Pointers)
//------------------------------------------------------------------------------

/*
 * The Importance of Proper Memory Management:
 *   - Manual memory management with `new` and `delete` (as seen in DynamicMemoryBasics.h)
 *     is error-prone, leading to:
 *       - Memory Leaks: If you forget to deallocate memory, your program will gradually consume more and more resources.
 *       - Dangling Pointers: If you deallocate memory but continue to use the pointer, you'll access invalid data.
 *       - Double Deletion: Deallocating the same memory twice can crash your program.
 *   - C++ offers a better way: RAII (Resource Acquisition Is Initialization).
 */

/*
 * RAII (Resource Acquisition Is Initialization):
 *   - A core principle of C++.
 *   - The idea is that resource ownership is tied to the lifetime of objects.
 *   - When an object is created, it acquires the necessary resources.
 *   - When the object is destroyed, the resources are automatically released.
 *   - This eliminates the need for manual resource management in most cases.
 *
 * Smart Pointers (Implementing RAII for Dynamic Memory):
 *   - Special classes that act like pointers but manage the lifetime of the objects they point to.
 *   - Three main types:
 *     - unique_ptr: Exclusive ownership of a resource (like a single owner of a car).
 *     - shared_ptr: Shared ownership of a resource (like multiple people owning shares in a company).
 *     - weak_ptr: Observes a resource managed by shared_ptr without affecting its lifetime (like a non-voting shareholder).
 */


//------------------------------------------------------------------------------
// Section 2: Demonstrating Smart Pointers (unique_ptr and shared_ptr)
//------------------------------------------------------------------------------

void demoSmartPointers() {
    std::cout << "\n--- unique_ptr: Exclusive Ownership ---\n";

    // 1. Create a unique_ptr to dynamically allocate an integer:
    std::unique_ptr<int> uPtr(new int(10));
    //   - uPtr: A unique_ptr object that manages the lifetime of the int on the heap.
    //   - new int(10): Allocates memory on the heap for the int and initializes it with the value 10.

    // 2. Access and use the unique_ptr:
    std::cout << "Unique Pointer: " << *uPtr << "\n"; // Dereference uPtr to get the int's value.

    // 3. Note: unique_ptrs cannot be copied, only moved. This enforces exclusive ownership.
    // std::unique_ptr<int> uPtrCopy = uPtr;  // This would be an error (copy not allowed)
    // std::unique_ptr<int> uPtrMoved = std::move(uPtr); // This is how you transfer ownership

    std::cout << "\n--- shared_ptr: Shared Ownership ---\n";

    // 1. Create a shared_ptr: (Recommended: Use make_shared for exception safety)
    std::shared_ptr<int> sPtr = std::make_shared<int>(20);
    //   - sPtr: A shared_ptr that shares ownership of the int with other shared_ptrs.

    // 2. Create another shared_ptr pointing to the same object:
    std::shared_ptr<int> sPtr2 = sPtr;
    //  - Both sPtr and sPtr2 now point to the same int.

    // 3. Access and use the shared_ptr:
    std::cout << "Shared Pointer: " << *sPtr << "\n"; // Dereference sPtr to get the int's value.

    // 4. Check the reference count (number of shared_ptrs managing the object):
    std::cout << "Shared Pointer Count: " << sPtr.use_count() << "\n"; // Should be 2


    std::cout << "\n--- weak_ptr: Non-Owning Observer ---\n";

    // 1. Create a weak_ptr from a shared_ptr:
    std::weak_ptr<int> wPtr = sPtr;
    //   - wPtr observes the object managed by sPtr but doesn't own it (no effect on reference count).
    //   - You cannot dereference a weak_ptr directly because it might be pointing to an object that has already been deleted.

    // 2. Check if the object is still valid (not deleted):
    if (auto shared = wPtr.lock()) {  // Try to acquire a shared_ptr to the object
        std::cout << "Weak pointer: " << *shared << "\n"; // Use the acquired shared_ptr
    } else {
        std::cout << "The object is gone!\n";
    }

    // 3. Now, reset the original shared_ptr
    sPtr.reset(); // release ownership, count is now 1
    std::cout << "sPtr has been reset. Shared Pointer Count: " << sPtr2.use_count() << "\n";

    // Check if the object is still valid (not deleted):
    if (auto shared = wPtr.lock()) {  // Try to acquire a shared_ptr to the object
        std::cout << "Weak pointer: " << *shared << "\n"; // Use the acquired shared_ptr
    } else {
        std::cout << "The object is gone!\n"; // This will now be true
    }

}

#endif // MEMORYMANAGEMENTTECHNIQUES_H
