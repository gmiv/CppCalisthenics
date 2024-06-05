#ifndef STLCONTAINERS_H
#define STLCONTAINERS_H

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional> // For greater function

void runSTLContainers() {
    std::cout << "Vector Example:\n";
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << "\n";

    std::cout << "Deque Example:\n";
    std::deque<double> deq = {1.1, 2.2, 3.3};
    deq.push_front(0.1);
    deq.push_back(4.4);
    for (double d : deq) {
        std::cout << d << " ";
    }
    std::cout << "\n";

    std::cout << "List Example:\n";
    std::list<std::string> lst = {"Alpha", "Beta", "Gamma"};
    lst.push_front("Omega");
    for (const auto& s : lst) {
        std::cout << s << " ";
    }
    std::cout << "\n";

    std::cout << "Set Example:\n";
    std::set<int, std::greater<int>> myset = {5, 2, 5, 3, 2, 1};
    for (int s : myset) {
        std::cout << s << " ";
    }
    std::cout << "\n";

    std::cout << "Map Example:\n";
    std::map<std::string, int> mymap;
    mymap["one"] = 1;
    mymap["two"] = 2;
    mymap["three"] = 3;
    for (const auto& m : mymap) {
        std::cout << m.first << ": " << m.second << "\n";
    }

    std::cout << "Unordered Set Example:\n";
    std::unordered_set<int> uset = {10, 20, 30, 40};
    uset.insert(50);
    for (int u : uset) {
        std::cout << u << " ";
    }
    std::cout << "\n";
}

#endif
