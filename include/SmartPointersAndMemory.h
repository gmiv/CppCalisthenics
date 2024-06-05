#ifndef SMARTPOINTERSANDMEMORY_H
#define SMARTPOINTERSANDMEMORY_H

#include <iostream>       // For input/output operations (e.g., printing to the console)
#include <memory>         // For smart pointer classes (unique_ptr, shared_ptr, weak_ptr)
#include <vector>         // For demonstrating smart pointers in a container scenario


//------------------------------------------------------------------------------
// Section 1: Smart Pointers in C++ (RAII and Automated Resource Management)
//------------------------------------------------------------------------------

/*
 * Smart Pointers: A Modern Approach to Memory Management
 *
 * - Traditional C++ memory management with new/delete (as seen in DynamicMemoryBasics.h)
 *   is error-prone, often leading to:
 *     - Memory Leaks: Failure to deallocate memory, causing resource wastage.
 *     - Dangling Pointers:  Pointers that point to deallocated memory, leading to undefined behavior.
 *     - Double Deletion:  Deallocating memory multiple times, which can crash your program.
 *
 * - Smart pointers are C++ classes designed to address these issues by automatically managing
 *   the lifetime of the objects they point to.
 * - They leverage RAII (Resource Acquisition Is Initialization), a principle that ties the
 *   lifetime of a resource to the lifetime of an object.
 *
 * Key Smart Pointer Types:
 *
 * 1. unique_ptr (Exclusive Ownership):
 *    - Allows only one smart pointer to manage a resource at a time.
 *    - When the unique_ptr goes out of scope or is reset, the owned resource is automatically deleted.
 *    - Supports move semantics for transferring ownership to another unique_ptr.
 *    - Ideal for situations where a resource has a single clear owner.
 *
 * 2. shared_ptr (Shared Ownership):
 *    - Allows multiple smart pointers to share ownership of a resource.
 *    - Uses reference counting to keep track of how many shared_ptrs point to the same resource.
 *    - The resource is deleted when the last shared_ptr pointing to it is destroyed or reset.
 *    - Great for situations where ownership is shared among multiple parts of your code.
 *
 * 3. weak_ptr (Non-Owning Observer):
 *    - A weak reference to an object managed by a shared_ptr.
 *    - Does not affect the reference count of the shared_ptr.
 *    - Used to prevent circular dependencies and to check if the shared resource is still alive.
 */

//------------------------------------------------------------------------------
// Section 2: Class to Demonstrate Resource Management (MyClass)
//------------------------------------------------------------------------------

/*
 * Class: MyClass
 *
 * Purpose: A simple class that prints messages when it's created and destroyed.
 *          Used to showcase how smart pointers manage object lifetimes.
 */
class MyClass {
public:
    MyClass() { std::cout << "MyClass object created\n"; } // Constructor: Prints message on creation
    ~MyClass() { std::cout << "MyClass object destroyed\n"; } // Destructor: Prints message on destruction
    void greet() { std::cout << "Hello from MyClass\n"; } // Member function to print a greeting
};


//------------------------------------------------------------------------------
// Section 3: Demonstrating Smart Pointers (unique_ptr, shared_ptr, weak_ptr)
//------------------------------------------------------------------------------
void runSmartPointersAndMemory() {

    std::cout << "\n--- unique_ptr Example ---\n";
    // Unique Pointer Example
    std::unique_ptr<MyClass> uptr(new MyClass()); // Create a unique_ptr, allocating a MyClass object on the heap
    uptr->greet(); // Call the greet() function of the MyClass object owned by uptr

    // At this point, the unique_ptr goes out of scope (the function ends), and the MyClass object is automatically destroyed.

    std::cout << "\n--- shared_ptr Example ---\n";
    // Shared Pointer Example
    std::shared_ptr<MyClass> sptr1 = std::make_shared<MyClass>();
    std::shared_ptr<MyClass> sptr2 = sptr1;  // Create another shared_ptr, both pointing to the same MyClass object

    sptr1->greet();

    std::cout << "\n--- weak_ptr Example ---\n";
    // Weak Pointer Example
    std::weak_ptr<MyClass> wptr = sptr1;   // Create a weak_ptr from sptr1. It observes the object, but doesn't own it.
    if (auto spt = wptr.lock()) {         // Check if the object still exists before using it
        spt->greet();                    // If it does, use the temporarily acquired shared_ptr
    } else {
        std::cout << "Resource is no longer available.\n";
    }

    // Demonstrate resource lifetime control with shared_ptr:
    std::cout << "\nThe object is shared by " << sptr1.use_count() << " shared_ptr(s).\n";

    sptr1.reset(); // Release sptr1's ownership, but object still lives due to sptr2

    std::cout << "After sptr1.reset(), the object is shared by " << sptr2.use_count() << " shared_ptr(s).\n";

    sptr2.reset(); // Last shared_ptr releases ownership, the object is now destroyed.
}

#endif // SMARTPOINTERSANDMEMORY_H

