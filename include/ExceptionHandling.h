#ifndef EXCEPTIONHANDLING_H
#define EXCEPTIONHANDLING_H

#include <iostream>
#include <stdexcept>

class MyException : public std::exception {
public:
    const char* what() const throw() {
        return "Custom Exception Happened";
    }
};

void functionThatThrows() {
    throw MyException();
}

void runExceptionHandling() {
    try {
        functionThatThrows();
    } catch (const MyException& e) {
        std::cout << "Caught MyException: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Caught std::exception: " << e.what() << "\n";
    }
}

#endif
