#ifndef INHERITANCEANDPOLYMORPHISM_H
#define INHERITANCEANDPOLYMORPHISM_H

#include <iostream>

// Base class
class Vehicle {
public:
    Vehicle() { std::cout << "Vehicle constructed.\n"; }
    virtual ~Vehicle() { std::cout << "Vehicle destroyed.\n"; } // Virtual destructor

    virtual void startEngine() { std::cout << "Vehicle engine started.\n"; }
    static int vehicleCount;
};

int Vehicle::vehicleCount = 0;

// Derived class
class Bike : public Vehicle {
public:
    Bike() { std::cout << "Bike constructed.\n"; }
    ~Bike() { std::cout << "Bike destroyed.\n"; }

    void startEngine() override { std::cout << "Bike engine started with style!\n"; }
};

void runInheritanceAndPolymorphism() {
    Vehicle *v = new Bike();
    v->startEngine();
    delete v; // Calls ~Bike(), then ~Vehicle() because of virtual destructor
}

#endif
