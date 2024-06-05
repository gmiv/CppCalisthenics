#ifndef OPERATOROVERLOADING_H
#define OPERATOROVERLOADING_H

#include <iostream>

class Complex {
public:
    double real, imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload = operator
    Complex& operator=(const Complex& other) {
        if (this != &other) { // Avoid self-assignment
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }

    // Overload << operator
    friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
        out << c.real << "+i" << c.imag;
        return out;
    }
};

void runOperatorOverloading() {
    Complex c1(1.0, 2.0), c2(2.0, 3.0);
    Complex c3 = c1 + c2;
    std::cout << "Complex addition: " << c3 << "\n";
}

#endif
