#ifndef CLASSESANDOBJECTS_H
#define CLASSESANDOBJECTS_H

#include <iostream>

class Car {
public:
    Car() : speed(0) { std::cout << "Car constructed.\n"; Car::count++; }  // Default constructor
    Car(int s) : speed(s) { std::cout << "Car constructed.\n";  Car::count++;} // Parameterized constructor
    ~Car() { std::cout << "Car destroyed.\n"; Car::count--; } // Destructor

    void accelerate() {
        speed += 5;
        std::cout << "Speed increased to " << speed << ".\n";
    }
    void decelerate() {
        if (speed >= 5) speed -= 5;
        std::cout << "Speed decreased to " << speed << ".\n";
    }

    // Getter and Setter for speed
    int getSpeed() const { return speed; }
    void setSpeed(int newSpeed) { speed = newSpeed; }

    static int count;
    static void showCount() { std::cout << "Count of cars: " << count << ".\n"; }

private:
    int speed;
};

int Car::count = 0;

// resetSpeed now uses the setter
void resetSpeed(Car &c) {
    c.setSpeed(0);
    std::cout << "Speed reset to 0.\n";
}

void runClassesAndObjects() {
    Car myCar(50);
    myCar.accelerate();
    myCar.decelerate();
    resetSpeed(myCar);
    Car::showCount();
}

#endif // CLASSESANDOBJECTS_H
