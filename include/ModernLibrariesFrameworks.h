#ifndef MODERNLIBRARIESFRAMEWORKS_H
#define MODERNLIBRARIESFRAMEWORKS_H

#include <iostream>
#include <boost/lexical_cast.hpp>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>

void demonstrateBoost() {
    try {
        int i = boost::lexical_cast<int>("123");
        std::cout << "Boost casted int: " << i << "\n";
    } catch (const boost::bad_lexical_cast& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }
}

void createQtGuiApplication(int argc, char** argv) {
    QApplication app(argc, argv);
    QPushButton button("Hello, Qt!");
    button.show();
    // Uncomment below to run the Qt application
    // app.exec();
}

void runModernLibrariesFrameworks(int argc, char** argv) {
    demonstrateBoost();
    createQtGuiApplication(argc, argv);
}

#endif
