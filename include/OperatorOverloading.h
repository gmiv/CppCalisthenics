#ifndef OPERATOROVERLOADING_H  // Include guard: Prevents this header from being included multiple times in a single compilation unit.
#define OPERATOROVERLOADING_H

#include <iostream> // For standard input/output (cout)

// ----------------------------------------------------------------------------
// Section 1: Operator Overloading in C++ (Customizing Operators for Your Classes)
// ----------------------------------------------------------------------------

/*
 * What is Operator Overloading?
 *    -  A powerful feature in C++ that allows you to redefine the behavior of operators (e.g., +, -, *, /, <<, >>) for custom classes.
 *    -  You can make operators work with objects in a way that is intuitive and meaningful within your application's domain.
 *    -  Operator overloading is NOT available for fundamental data types (int, float, etc.) because their behavior is already defined.
 *
 * Why Overload Operators?
 *    - Improves Readability: Code using overloaded operators can be more concise and closer to natural mathematical or logical expressions.
 *    - Consistency: You can define operations on objects that behave like operations on built-in types.
 *    - Domain-Specific Operations:  Create operators that make sense within the context of your custom class (e.g., matrix multiplication).
 *
 * Important Considerations:
 *    - Don't Overdo It:  Overloading operators should enhance clarity, not confuse.  Don't overload operators in ways that are surprising or counterintuitive.
 *    - Precedence and Associativity:  The precedence and associativity of overloaded operators are the same as the built-in operators, so be mindful of how you combine them.
 *    - Member vs. Non-Member Functions:  Some operators (e.g., assignment) must be overloaded as member functions, while others (e.g., stream insertion '<<') are often overloaded as friend functions for symmetry.
 */

//------------------------------------------------------------------------------
// Section 2: Example: Complex Number Class with Operator Overloading
//------------------------------------------------------------------------------

class Complex {
public:
    double real;   // Real part of the complex number
    double imag;   // Imaginary part of the complex number

    // Constructor:
    // - Allows you to create Complex objects with optional initial values for the real and imaginary parts.
    // - Default values are set to 0.0 if no arguments are provided.
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}


    // Overloaded + Operator (Member Function):
    // - This allows you to add two Complex numbers using the + operator.
    Complex operator+(const Complex& other) const {
        // Create a new Complex object by adding the corresponding real and imaginary parts of 'this' object and the 'other' object.
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloaded Assignment (=) Operator (Member Function):
    // - This overloads the assignment operator to correctly copy one Complex object to another.
    Complex& operator=(const Complex& other) {
        if (this != &other) { // Check for self-assignment (e.g., c1 = c1) to avoid unnecessary copying
            real = other.real;
            imag = other.imag;
        }
        return *this;  // Return a reference to the modified object to allow chaining assignments (e.g., c1 = c2 = c3).
    }

    // Overloaded << Operator (Friend Function):
    // - This allows you to insert a Complex object directly into an output stream (e.g., std::cout) using the familiar << operator.
    friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
        out << c.real;            // Output the real part of the complex number

        if (c.imag >= 0) {
            out << "+i" << c.imag;  // If the imaginary part is positive or zero, output "+i" followed by the imaginary part
        } else {
            out << "-i" << -c.imag; // If the imaginary part is negative, output "-i" followed by the absolute value of the imaginary part
        }
        return out;  // Return the output stream reference for chaining output operations.
    }

};
//------------------------------------------------------------------------------
// Section 3: Demonstrating Operator Overloading (runOperatorOverloading)
//------------------------------------------------------------------------------
void runOperatorOverloading() {
    std::cout << "\n--- Operator Overloading Demonstration ---\n";

    Complex c1(1.0, 2.0);  // Create a complex number (1.0 + 2.0i)
    Complex c2(2.0, 3.0);  // Create another complex number (2.0 + 3.0i)
    Complex c3 = c1 + c2;  // Use the overloaded + operator to add the complex numbers

    // Output the result using the overloaded << operator
    std::cout << "Result of complex addition: " << c3 << std::endl;
}

#endif // OPERATOROVERLOADING_H
