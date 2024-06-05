#ifndef ADVANCEDDATATYPES_H
#define ADVANCEDDATATYPES_H

#include <iostream>

void demoEnums() {
    enum Color { red, green, blue };
    Color c = red;
    std::cout << "Enum value: " << c << "\n";

    enum class NewColor { red, green, blue };
    NewColor nc = NewColor::green;
    std::cout << "Enum class value: " << static_cast<int>(nc) << "\n";
}

void demoStructs() {
    struct Person {
        std::string name;
        int age;
    };
    Person p = {"John", 30};
    std::cout << "Person: " << p.name << ", " << p.age << "\n";
}

void demoUnions() {
    union Data {
        int i;
        float f;
        char str[20];
    };
    Data data;
    data.i = 10;
    std::cout << "Union stored integer: " << data.i << "\n";
    data.f = 220.5;
    std::cout << "Union stored float: " << data.f << "\n";
}

void runAdvancedDataTypes() {
    demoEnums();
    demoStructs();
    demoUnions();
}

#endif
