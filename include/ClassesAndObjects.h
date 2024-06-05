#ifndef CLASSESANDOBJECTS_H  // Include guard: Prevents this header from being included multiple times in a single compilation unit.
#define CLASSESANDOBJECTS_H

#include <iostream>  // For standard input/output (cout)

// ----------------------------------------------------------------------------
// Section 1: Classes in C++ (The Blueprint for Objects)
// ----------------------------------------------------------------------------

/*
 * What is a Class?
 *   - A blueprint for creating objects (a particular data structure), providing initial values for
 *     state (member variables or attributes), and implementations of behavior (member functions or methods).
 *   - Classes provide encapsulation, bundling data and the functions that operate on that data into a single unit.
 *   - They promote modularity and code reusability.
 *
 * Class Structure:
 *   class ClassName {
 *   public:  // Members accessible from outside the class
 *       // Constructors, functions, etc.
 *   private: // Members accessible only from within the class
 *       // Member variables, functions, etc.
 *   };
 *
 * Key Concepts in Classes:
 *   - Member Variables: Represent the state or data of an object.
 *   - Member Functions: Define the actions or behaviors an object can perform.
 *   - Constructors: Special functions that initialize an object when it's created.
 *   - Destructors: Special functions that clean up an object when it's destroyed.
 *   - Access Specifiers (public, private, protected): Control how class members can be accessed from outside.
 *   - static members: Members associated with the class itself rather than with individual objects.
 */

// ----------------------------------------------------------------------------
// Section 2: Class Example (Car)
// ----------------------------------------------------------------------------

class Car {
public:  // Public members (accessible from outside the class)

    // Constructors:
    Car() : speed(0) {
        std::cout << "Default constructor: Car created with speed 0.\n";
        Car::count++; // Increment the static count of cars
    }

    //overloaded constructor, parameterized constructor
    Car(int s) : speed(s) {
        std::cout << "Parameterized constructor: Car created with speed " << s << ".\n";
        Car::count++; // Increment the static count of cars
    }

    // Destructor:
    ~Car() {
        std::cout << "Destructor: Car destroyed.\n";
        Car::count--; // Decrement the static count of cars
    }

    // Member Functions:
    void accelerate() {
        speed += 5;
        std::cout << "Accelerate: Speed increased to " << speed << ".\n";
    }

    void decelerate() {
        if (speed >= 5) {
            speed -= 5;
        }
        std::cout << "Decelerate: Speed decreased to " << speed << ".\n";
    }

    // Getter (Accessor): Provides controlled access to the 'speed' member
    int getSpeed() const { return speed; } // const because it does not modify object state

    // Setter (Mutator): Provides controlled modification of the 'speed' member
    void setSpeed(int newSpeed) {
        speed = newSpeed;
    }

    // Static Member (Class-Level Variable): Keeps track of the total number of Car objects created
    static int count;

    // Static Member Function (Class-Level Function): Displays the current count of Car objects
    static void showCount() {
        std::cout << "Static function: Total count of cars: " << count << std::endl;
    }

private:  // Private members (accessible only within the class)
    int speed; // Represents the current speed of the car
};

// Initialize the static member 'count' outside the class definition
int Car::count = 0;  // Starts at 0 because no cars have been created yet


// ----------------------------------------------------------------------------
// Section 3: Friend Function (resetSpeed)
// ----------------------------------------------------------------------------
// Friend Function: Allows a non-member function to access a class's private members
// In this case, we use the setter for speed for proper encapsulation.
void resetSpeed(Car &c) { // Takes a reference to a Car object
    c.setSpeed(0);        // Calls the Car's setSpeed function to reset the speed
    std::cout << "Friend function: Speed reset to 0.\n";
}


//------------------------------------------------------------------------------
// Section 4: Function to Demonstrate Classes and Objects (runClassesAndObjects)
//------------------------------------------------------------------------------

void runClassesAndObjects() {
    std::cout << "\n--- Class and Object Demonstration ---\n";
    Car myCar(50);        // Create a Car object with initial speed 50 using the parameterized constructor

    myCar.accelerate();   // Test the accelerate() member function
    myCar.decelerate();   // Test the decelerate() member function

    // Using the friend function to reset the speed
    resetSpeed(myCar);    // Calls the resetSpeed function to set speed to 0

    Car::showCount();     // Call the static member function to display the car count (should be 1)
}


#endif // CLASSESANDOBJECTS_H
