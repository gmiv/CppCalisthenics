#ifndef SMARTPOINTERSANDMEMORY_H
#define SMARTPOINTERSANDMEMORY_H

#include <iostream>
#include <memory>
#include <vector>

class MyClass {
public:
    MyClass() { std::cout << "MyClass created\n"; }
    ~MyClass() { std::cout << "MyClass destroyed\n"; }
    void greet() { std::cout << "Hello from MyClass\n"; }
};

void runSmartPointersAndMemory() {
    std::cout << "Unique Pointer Example:\n";
    std::unique_ptr<MyClass> uptr(new MyClass());
    uptr->greet();

    std::cout << "Shared Pointer Example:\n";
    std::shared_ptr<MyClass> sptr1 = std::make_shared<MyClass>();
    std::shared_ptr<MyClass> sptr2 = sptr1; // Reference count is now 2
    sptr1->greet();

    std::cout << "Weak Pointer Example:\n";
    std::weak_ptr<MyClass> wptr = sptr1;
    if (auto spt = wptr.lock()) { // Converts weak_ptr to shared_ptr
        spt->greet();
    } else {
        std::cout << "Resource is no longer available.\n";
    }
}

#endif
