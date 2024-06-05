#ifndef INHERITANCEANDPOLYMORPHISM_H
#define INHERITANCEANDPOLYMORPHISM_H

#include <iostream> // for standard input and output

//------------------------------------------------------------------------------
// Section 1: Introduction to Object-Oriented Programming (OOP) Concepts
//------------------------------------------------------------------------------

/*
 * OOP Pillars:
 *  1. Encapsulation: Bundling data (attributes) and behaviors (methods) into objects.
 *  2. Inheritance: Creating new classes (derived classes) that inherit properties from existing classes (base classes).
 *  3. Polymorphism: The ability of objects of different classes to be treated as objects of a common base class.
 *
 * Inheritance (Code Reuse and Hierarchy):
 *   - A fundamental OOP concept that allows you to create new classes (derived classes) that inherit
 *     characteristics and behaviors from existing classes (base classes).
 *   - Establishes an "is-a" relationship (e.g., a Car *is a* Vehicle).
 *   - Benefits:
 *     - Promotes code reusability: Avoid rewriting common functionality in each class.
 *     - Establishes a clear hierarchy: Helps organize and structure your code.
 *   - Types of Inheritance:
 *     - Single Inheritance: A derived class inherits from a single base class.
 *     - Multiple Inheritance: A derived class inherits from multiple base classes (can be complex).
 *     - Hierarchical Inheritance: Multiple derived classes inherit from a single base class.
 *
 * Polymorphism (Many Forms):
 *   - Allows objects of different derived classes to be treated as instances of a common base class.
 *   - Achieved through virtual functions in C++.
 *   - Key Mechanisms:
 *     - Overriding: Redefining a virtual function in a derived class.
 *     - Dynamic Dispatch: Calling the correct overridden function at runtime based on the actual object type.
 *   - Benefits:
 *     - Flexible and extensible code.
 *     - Write code that can work with objects of different types without needing to know their exact types.
 *   - Virtual Destructors: Essential for proper cleanup of objects in polymorphic scenarios.
 */


//------------------------------------------------------------------------------
// Section 2: Base Class (Vehicle) - Establishing Common Functionality
//------------------------------------------------------------------------------

class Vehicle {
public:
    Vehicle() { std::cout << "Vehicle constructor: Creating a vehicle.\n"; Vehicle::vehicleCount++; }
    // Virtual Destructor: Crucial for polymorphic object destruction
    virtual ~Vehicle() { std::cout << "Vehicle destructor: Destroying a vehicle.\n"; Vehicle::vehicleCount--;}

    // Virtual Function:  Can be overridden in derived classes
    virtual void startEngine() { std::cout << "Vehicle startEngine(): Generic engine start.\n"; }

    static int vehicleCount; // Static variable to track the number of vehicle objects
};

// Initialize the static member variable
int Vehicle::vehicleCount = 0;


//------------------------------------------------------------------------------
// Section 3: Derived Class (Bike) - Specializing Behavior
//------------------------------------------------------------------------------

// Derived Class: Inherits properties and behaviors from the base class (Vehicle).
class Bike : public Vehicle { // public inheritance: All public members of Vehicle become public in Bike
public:
    Bike() { std::cout << "Bike constructor: Creating a bike.\n"; } // Constructor of the derived class
    ~Bike() { std::cout << "Bike destructor: Destroying a bike.\n"; } // Destructor of the derived class

    // Function Overriding: Redefining the base class's virtual function
    void startEngine() override { // override keyword is optional but good practice
        std::cout << "Bike startEngine(): Engine started with a kick!\n";
    }
};

//------------------------------------------------------------------------------
// Section 4: Function to Demonstrate Polymorphism (runInheritanceAndPolymorphism)
//------------------------------------------------------------------------------

void runInheritanceAndPolymorphism() {
    std::cout << "\n--- Inheritance and Polymorphism Demonstration ---\n";

    // 1. Polymorphic Object Creation:
    Vehicle *v = new Bike();
    //  - v: A pointer of the base class type (Vehicle)
    //  - new Bike(): Creates an object of the derived class (Bike) on the heap

    // 2. Dynamic Dispatch (Calling the Overridden Function):
    v->startEngine();
    //  - Since startEngine() is virtual and the actual object type is Bike, the overridden
    //    function in the Bike class is called.

    // 3. Object Destruction and Virtual Destructor:
    delete v;
    //  - Calls the destructor of Bike first (due to virtual destructor in the base class) and
    //    then the destructor of Vehicle, ensuring proper cleanup.
}


#endif // INHERITANCEANDPOLYMORPHISM_H

