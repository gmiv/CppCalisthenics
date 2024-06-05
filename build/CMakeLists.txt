cmake_minimum_required(VERSION 3.10)
project(CppCalisthenics)

# Add include directory
include_directories(../include)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(CppCalisthenics ../src/main.cpp
        ../include/MultithreadingAndConcurrency.h
        ../include/NetworkProgramming.h
        ../include/DesignPatterns.h
        ../include/CodeOptimization.h
        ../include/CompilerOptimizations.h
        ../include/ModernCppFeatures.h
        ../include/ModernLibrariesFrameworks.h
        ../include/PointersAndReferences.h
        ../include/AdvancedDataTypes.h
        ../include/ThreadSupport.h
        ../include/RegexExamples.h
        ../include/AdditionalUtilities.h)

# If you have other source files, list them here
# add_executable(CppCalisthenics src/main.cpp src/OtherFile.cpp)
