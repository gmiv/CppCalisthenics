#ifndef DESIGNPATTERNS_H
#define DESIGNPATTERNS_H

#include <iostream>       // For input/output operations (cout, cerr)
#include <memory>         // For smart pointers (unique_ptr) to manage object ownership
#include <vector>         // For storing a collection of observers
#include <stdexcept>      // For throwing exceptions in the Factory pattern

// ----------------------------------------------------------------------------
// Section 1: Introduction to Design Patterns (Reusable Solutions)
// ----------------------------------------------------------------------------

/*
 * What are Design Patterns?
 *   - Well-proven solutions to common software design problems.
 *   - Not specific code implementations, but rather general templates or ideas that can be applied
 *     in different ways to different situations.
 *   - Help to make your code more flexible, reusable, and maintainable.
 *   - Fall into categories: creational, structural, and behavioral patterns.
 *
 * Benefits of Using Design Patterns:
 *   - Improved code organization and readability.
 *   - Easier to maintain and extend your code.
 *   - Common language for developers to discuss software designs.
 *   - Solutions that have been tested and proven effective in many scenarios.
 *
 * Drawbacks to Consider:
 *   - Might introduce unnecessary complexity in simple cases.
 *   - Important to choose the right pattern for the specific problem.
 *   - Misuse of patterns can lead to over-engineered solutions.
 */

// ----------------------------------------------------------------------------
// Section 2: Singleton Pattern (Guaranteed Unique Instance)
// ----------------------------------------------------------------------------
/*
 * Singleton Pattern:
 *   - Purpose: Ensures a class has only one instance and provides a global point of access to it.
 *   - Applicability: Useful when you need a single, shared resource (like a configuration manager, logger, or connection pool).
 *   - Key Features:
 *     - Private constructor: Prevents clients from directly creating instances.
 *     - Static getInstance() method: Provides the controlled access point to the sole instance.
 */
class Singleton {
public:
    // Public static method to get the singleton instance
    static Singleton& getInstance() {
        // 'static' ensures only one instance is created even if getInstance() is called multiple times
        static Singleton instance; // The single instance is created here.
        return instance;
    }
    void operation() const {
        std::cout << "Singleton operation\n";  // Example operation the Singleton performs.
    }

private:
    Singleton() {} // Private constructor to prevent external instantiation.

    // Deleted copy constructor and assignment operator to prevent copying.
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

//------------------------------------------------------------------------------
// Section 3: Factory Pattern (Abstracting Object Creation)
//------------------------------------------------------------------------------

/*
 * Factory Pattern:
 *    - Purpose: Provides an interface for creating families of related or dependent objects without
 *               specifying their concrete classes.
 *    - Applicability:
 *      - When you want to centralize object creation.
 *      - When you have a system where the exact type of objects to be created may vary at runtime.
 *    - Key Features:
 *      - Abstract Product class: Defines the interface for the objects the factory creates.
 *      - Concrete Product classes: Implement the Product interface.
 *      - Factory class/method: Creates and returns Product objects, often based on some input parameter.
 */

class Product { // Abstract base class
public:
    virtual void operate() = 0; // Pure virtual function (the subclass must implement)
    virtual ~Product() {} // Virtual destructor for proper cleanup of derived classes
};

// Concrete Products
class ConcreteProductA : public Product {
public:
    void operate() override { // Override the base class's virtual function
        std::cout << "ConcreteProductA operation\n";
    }
};

class ConcreteProductB : public Product {
public:
    void operate() override {
        std::cout << "ConcreteProductB operation\n";
    }
};

// Factory Class
class Factory {
public:
    // Static factory method to create products based on a type string
    static std::unique_ptr<Product> createProduct(const std::string& type) {
        if (type == "A") {
            return std::make_unique<ConcreteProductA>();
        } else if (type == "B") {
            return std::make_unique<ConcreteProductB>();
        } else {
            throw std::runtime_error("Unknown product type");
        }
    }
};

// ----------------------------------------------------------------------------
// Section 4: Observer Pattern (Notification Mechanism)
// ----------------------------------------------------------------------------
/*
 * Observer Pattern:
 *   - Purpose: Defines a one-to-many dependency between objects so that when one object changes state,
 *              all its dependents are notified and updated automatically.
 *   - Applicability:
 *      - When changes in one object require corresponding changes in other objects.
 *      - When you want to decouple the objects so that they don't need to know about each other's specific details.
 *   - Key Features:
 *      - Subject: The object that maintains a list of its dependents (observers).
 *      - Observer: An interface for objects that depend on the Subject.
 *      - attach()/detach(): Methods to add/remove observers.
 *      - notify(): Method the Subject calls to inform its observers about changes.
 */

// Forward declaration of Subject (to avoid circular dependency)
class Subject;

class Observer {  // Abstract observer
public:
    virtual void update(Subject* subject) = 0; // Pure virtual function (the subclass must implement)
    virtual ~Observer() {} // Virtual destructor for proper cleanup of derived classes
};

// Concrete Subject
class Subject {
private:
    std::vector<Observer*> observers; // Collection to hold pointers to observers

public:
    // Attach an observer to the subject
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    // Notify all attached observers of a change
    void notify() {
        for (Observer* observer : observers) {
            observer->update(this);
        }
    }
};

// Concrete Observer
class ConcreteObserver : public Observer {
public:
    void update(Subject* subject) override {
        std::cout << "Observer updated by Subject\n";
    }
};

// ----------------------------------------------------------------------------
// Section 5: Running Design Pattern Examples
// ----------------------------------------------------------------------------
void runDesignPatterns() {
    // Singleton Example
    Singleton& singleton = Singleton::getInstance();
    singleton.operation();

    // Factory Example
    auto product = Factory::createProduct("A");
    product->operate();

    // Observer Example
    Subject subject;
    ConcreteObserver observer;
    subject.attach(&observer);
    subject.notify();
}

#endif // DESIGNPATTERNS_H
