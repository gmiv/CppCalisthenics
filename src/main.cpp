#include <iostream>

#include "VariablesAndTypes.h"
#include "FlowControl.h"
#include "FunctionsAndRecursion.h"
#include "InputAndOutput.h"

#include "ClassesAndObjects.h"
#include "InheritanceAndPolymorphism.h"
#include "OperatorOverloading.h"

#include "STLContainers.h"
#include "IteratorsAndAlgorithms.h"
#include "SmartPointersAndMemory.h"

#include "TemplatesAndGenerics.h"
#include "ExceptionHandling.h"
#include "ConcurrentProgramming.h"

#include "MultithreadingAndConcurrency.h"
//#include "NetworkProgramming.h"

#include "DesignPatterns.h"
#include "CodeOptimization.h"
#include "CompilerOptimizations.h"

#include "ModernCppFeatures.h"
//#include "ModernLibrariesFrameworks.h"

// Include the headers for each chapter's main functions
extern void runVariablesAndTypesExamples();
extern void runFlowControlExamples();
extern void runFunctionsAndRecursionExamples();
extern void runInputAndOutputExamples();
extern void runClassesAndObjects();
extern void runInheritanceAndPolymorphism();
extern void runOperatorOverloading();
extern void runSTLContainers();
extern void runIteratorsAndAlgorithms();
extern void runSmartPointersAndMemory();
extern void runTemplatesAndGenerics();
extern void runExceptionHandling();
extern void runConcurrentProgramming();
extern void runMultithreadingAndConcurrency();
extern void runNetworkProgramming();
extern void runDesignPatterns();
extern void runCodeOptimization();
extern void runCompilerOptimizations();
extern void runModernCppFeatures();
extern void runModernLibrariesFrameworks();

void printSpacer() {
    std::cout << "----------------------------------------\n";
}

void runSelectedChapter(int choice) {
    switch(choice) {
        case 1:
            runVariablesAndTypesExamples();
            printSpacer();
            runFlowControlExamples();
            printSpacer();
            runFunctionsAndRecursionExamples();
            printSpacer();
            runInputAndOutputExamples();
            printSpacer();
            break;
        case 2:
            runClassesAndObjects();
            printSpacer();
            runInheritanceAndPolymorphism();
            printSpacer();
            runOperatorOverloading();
            printSpacer();
            break;
        case 3:
            runSTLContainers();
            printSpacer();
            runIteratorsAndAlgorithms();
            printSpacer();
            runSmartPointersAndMemory();
            printSpacer();
            break;
        case 4:
            runTemplatesAndGenerics();
            printSpacer();
            runExceptionHandling();
            printSpacer();
            runConcurrentProgramming();
            printSpacer();
            break;
        case 5:
            runMultithreadingAndConcurrency();
            printSpacer();
//            runNetworkProgramming();
            printSpacer();
            break;
        case 6:
            runDesignPatterns();
            runCodeOptimization();
            runCompilerOptimizations();
            break;
        case 7:
            runModernCppFeatures();
//            runModernLibrariesFrameworks(argc, argv);
        default:
            std::cout << "Invalid choice. Please select a valid chapter number.\n";
    }
}



int main() {
    int choice;
    std::cout << "Select a chapter to run its examples:\n";
    std::cout << "1. Chapter 1 - Basic Concepts\n";
    std::cout << "2. Chapter 2 - Object-Oriented Programming\n";
    std::cout << "3. Chapter 3 - Standard Library\n";
    std::cout << "4. Chapter 7 - Modern C++ Features and Libraries\n";
    std::cout << "5. Chapter 8 - Building Projects from Scratch\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << "\n";
    printSpacer();
    runSelectedChapter(choice);

    return 0;
}
