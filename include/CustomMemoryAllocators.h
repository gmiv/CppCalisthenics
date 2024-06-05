#ifndef CUSTOMMEMORYALLOCATORS_H  // Include guard to prevent multiple inclusions
#define CUSTOMMEMORYALLOCATORS_H

#include <iostream>     // For input/output (cout)
#include <memory>       // For std::allocator (and for showcasing smart pointer use later)

// ----------------------------------------------------------------------------
// Section 1: Custom Memory Allocators (Beyond new/delete)
// ----------------------------------------------------------------------------

/*
 * What are Custom Memory Allocators?
 * - In C++, you're not limited to the standard `new` and `delete` operators for memory management.
 * - Custom allocators give you fine-grained control over how memory is allocated and deallocated for objects.
 * - They're often used for performance optimization, memory usage optimization, or to meet special requirements of specific applications.
 *
 * Why Use Custom Allocators?
 * - Performance: Specialized allocators can be faster than the general-purpose new/delete for certain scenarios.
 * - Memory Usage: You can create allocators that minimize fragmentation or use memory pools for efficient reuse.
 * - Debugging: Custom allocators can help you track memory usage and detect errors like memory leaks.
 * - Special Cases: If you're working with embedded systems, real-time applications, or have unique memory constraints, you can tailor allocators to fit your needs.
 *
 * How They Work:
 * - You typically derive your allocator class from std::allocator or create your own interface from scratch.
 * - You implement the member functions:
 *   - allocate: Reserves a block of raw memory.
 *   - construct: Constructs objects in the allocated memory.
 *   - destroy: Destructs objects in the allocated memory.
 *   - deallocate: Releases the raw memory back to the system.
 */

//------------------------------------------------------------------------------
// Section 2: Simple Allocator Example (Inheriting from std::allocator)
//------------------------------------------------------------------------------

/*
 * Class: SimpleAllocator<T>
 *
 * Description: A basic custom allocator that inherits from the standard `std::allocator<T>`.
 *              It overrides the `allocate` and `deallocate` functions to add logging messages.
 *              This provides a way to track the allocation/deallocation process for debugging or monitoring purposes.
 */
template <typename T>
class SimpleAllocator : public std::allocator<T> { // Inherit from the standard allocator
public:
    // Override the allocate function
    T* allocate(size_t numObjects) {
        std::cout << "Allocating " << numObjects << " object(s) of type " << typeid(T).name() << "\n"; // Print allocation info
        return std::allocator<T>::allocate(numObjects); // Call the base class allocator
    }

    // Override the deallocate function
    void deallocate(T* p, size_t numObjects) {
        std::cout << "Deallocating " << numObjects << " object(s) of type " << typeid(T).name() << "\n"; // Print deallocation info
        std::allocator<T>::deallocate(p, numObjects); // Call the base class deallocator
    }
};


//------------------------------------------------------------------------------
// Section 3: Demonstrating the SimpleAllocator
//------------------------------------------------------------------------------

void demoCustomAllocator() {
    std::cout << "\n--- Demonstration of Custom Allocator ---\n";

    // 1. Create an instance of the custom allocator:
    SimpleAllocator<int> allocator; // Create an allocator for integers


    // 2. Allocate memory for 3 integers:
    int* arr = allocator.allocate(3);

    // 3. Construct integers in the allocated memory:
    // The std::allocator::construct function is used to create objects of type T
    // in uninitialized, raw storage.
    for (int i = 0; i < 3; i++) {
        allocator.construct(arr + i, i + 1); // Construct object at location arr + i
    }

    // 4. Use the allocated array:
    for (int i = 0; i < 3; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    // 5. Destroy the objects in the allocated memory:
    for (int i = 0; i < 3; i++) {
        allocator.destroy(arr + i); // Destroy the objects at location arr + i
    }

    // 6. Deallocate the memory:
    allocator.deallocate(arr, 3);
}

#endif // CUSTOMMEMORYALLOCATORS_H
