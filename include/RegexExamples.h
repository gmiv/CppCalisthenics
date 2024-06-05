#ifndef REGEXEXAMPLES_H
#define REGEXEXAMPLES_H

#include <iostream>
#include <regex>
#include <string>

void demoRegexSearch(const std::string& text) {
    std::regex pattern(R"(\w+@\w+\.\w+)");
    std::smatch matches;
    if (std::regex_search(text, matches, pattern)) {
        std::cout << "Found email: " << matches[0] << "\n";
    }
}

void runRegexExamples() {
    std::string sampleText = "Please contact us at info@example.com.";
    demoRegexSearch(sampleText);
}

#endif
