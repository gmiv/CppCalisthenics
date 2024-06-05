#ifndef DESIGNPATTERNS_H
#define DESIGNPATTERNS_H

#include <iostream>
#include <memory>
#include <vector>

// Singleton Pattern
class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
    void operation() const {
        std::cout << "Singleton operation\n";
    }
private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

// Factory Pattern
class Product {
public:
    virtual void operate() = 0;
    virtual ~Product() {}
};

class ConcreteProductA : public Product {
public:
    void operate() override {
        std::cout << "ConcreteProductA operation\n";
    }
};

class ConcreteProductB : public Product {
public:
    void operate() override {
        std::cout << "ConcreteProductB operation\n";
    }
};

class Factory {
public:
    static std::unique_ptr<Product> createProduct(const std::string& type) {
        if (type == "A") return std::make_unique<ConcreteProductA>();
        if (type == "B") return std::make_unique<ConcreteProductB>();
        throw std::runtime_error("Unknown product type");
    }
};

// Observer Pattern
class Subject;
class Observer {
public:
    virtual void update(Subject* subject) = 0;
    virtual ~Observer() {}
};

class Subject {
    std::vector<Observer*> observers;
public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }
    void notify() {
        for (Observer* observer : observers) {
            observer->update(this);
        }
    }
};

class ConcreteObserver : public Observer {
public:
    void update(Subject* subject) override {
        std::cout << "Observer updated by Subject\n";
    }
};

void runDesignPatterns() {
    // Singleton
    Singleton& singleton = Singleton::getInstance();
    singleton.operation();

    // Factory
    auto product = Factory::createProduct("A");
    product->operate();

    // Observer
    Subject subject;
    ConcreteObserver observer;
    subject.attach(&observer);
    subject.notify();
}

#endif
