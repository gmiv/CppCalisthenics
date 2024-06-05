#ifndef TEMPLATESANDGENERICS_H
#define TEMPLATESANDGENERICS_H

#include <iostream>
#include <vector>
#include <algorithm>

// Function template
template<typename T>
T add(T a, T b) {
    return a + b;
}

// Class template
template<typename T>
class Box {
public:
    T content;
    void setContent(T newContent) {
        content = newContent;
    }
    T getContent() {
        return content;
    }
};

// Template specialization for double type
template<>
class Box<double> {
public:
    double content;
    void setContent(double newContent) {
        content = newContent;
    }
    double getContent() {
        return content * 2; // Just an example of modifying behavior
    }
};

// Variadic template
template<typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << " ";
    if constexpr (sizeof...(args) > 0) {
        print(args...);
    } else {
        std::cout << "\n";
    }
}

void runTemplatesAndGenerics() {
    std::cout << "Add int: " << add(5, 3) << "\n";
    std::cout << "Add double: " << add(2.5, 3.5) << "\n";

    Box<int> intBox;
    intBox.setContent(123);
    std::cout << "Box content (int): " << intBox.getContent() << "\n";

    Box<double> doubleBox;
    doubleBox.setContent(3.14);
    std::cout << "Box content (double): " << doubleBox.getContent() << "\n";

    print("Mixing", "types", 123, 4.56);
}

#endif
