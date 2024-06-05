#ifndef ADDITIONALUTILITIES_H
#define ADDITIONALUTILITIES_H

#include <iostream>
#include <filesystem>
#include <optional>
#include <variant>

void demoFilesystem() {
    std::filesystem::path p = "example.txt";
    if (std::filesystem::exists(p)) {
        std::cout << "File exists.\n";
    } else {
        std::cout << "File does not exist.\n";
    }
}

void demoOptionalVariant() {
    std::optional<int> opt = 5;
    if (opt.has_value()) {
        std::cout << "Optional value: " << opt.value() << "\n";
    }

    std::variant<int, float, std::string> v = "Hello";
    std::cout << "Variant holds string: " << std::get<std::string>(v) << "\n";
}

void runAdditionalUtilities() {
    demoFilesystem();
    demoOptionalVariant();
}

#endif
