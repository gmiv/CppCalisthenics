#ifndef STLCONTAINERS_H   // Include guard to prevent multiple inclusions
#define STLCONTAINERS_H

#include <iostream>           // For input/output operations (cout)
#include <vector>             // Dynamic array (sequence container)
#include <deque>              // Double-ended queue (sequence container)
#include <list>               // Doubly-linked list (sequence container)
#include <set>                // Sorted collection of unique elements (associative container)
#include <map>                // Sorted collection of key-value pairs (associative container)
#include <unordered_set>      // Unsorted collection of unique elements (hashed container)
#include <unordered_map>      // Unsorted collection of key-value pairs (hashed container)
#include <stack>              // LIFO (Last In, First Out) container adapter
#include <queue>              // FIFO (First In, First Out) container adapter
#include <algorithm>          // For standard algorithms (e.g., sorting, searching)
#include <functional>         // For custom comparators (e.g., std::greater)
#include <string>             // For string operations
#include <utility>            // For std::pair (used in std::map)


// ----------------------------------------------------------------------------
// Section 1: Introduction to STL Containers (C++'s Power Tools)
// ----------------------------------------------------------------------------

/*
 * What are STL Containers?
 * - The Standard Template Library (STL) is a rich collection of C++ template classes
 *   that provide pre-built data structures and algorithms.
 * - Containers are fundamental to the STL and offer versatile ways to store and manage data.
 * - They are generic, meaning they can hold elements of any data type.
 *
 * Types of STL Containers:
 *   1. Sequence Containers: Store elements in a linear order.
 *      - vector: Dynamic array, fast random access.
 *      - deque: Double-ended queue, efficient insertion/deletion at both ends.
 *      - list: Doubly-linked list, efficient insertion/deletion anywhere.
 *      - array (C++11): Fixed-size array, more type-safe than C-style arrays.
 *      - forward_list (C++11): Singly-linked list.
 *
 *   2. Associative Containers: Store elements sorted by keys for fast lookup.
 *      - set: Collection of unique elements, sorted by a comparison function.
 *      - map: Collection of key-value pairs, sorted by keys, unique keys.
 *      - multiset: Like set, but allows duplicate elements.
 *      - multimap: Like map, but allows duplicate keys.
 *
 *   3. Unordered Associative Containers (C++11): Store elements in a hash table for fast average-case lookup.
 *      - unordered_set: Unsorted set, uses hashing for fast lookup.
 *      - unordered_map: Unsorted map, uses hashing for fast lookup.
 *      - unordered_multiset: Unsorted multiset, uses hashing.
 *      - unordered_multimap: Unsorted multimap, uses hashing.
 *
 *   4. Container Adapters: Provide a restricted interface to underlying sequence containers,
 *      offering specific behavior like stacks, queues, and priority queues.
 *      - stack: LIFO (Last In, First Out)
 *      - queue: FIFO (First In, First Out)
 *      - priority_queue: Elements are sorted by priority, highest priority is always at the front.
 */

//------------------------------------------------------------------------------
// Section 2: Demonstrating STL Containers (Examples)
//------------------------------------------------------------------------------

void runSTLContainers() {
    std::cout << "\n--- Sequence Containers ---\n";

    // 1. Vector
    std::vector<int> vec = {1, 2, 3, 4, 5}; // Initialize a vector with elements 1-5
    std::cout << "Vector elements: ";
    for (int v : vec) { std::cout << v << " "; } // Range-based for loop to print elements
    std::cout << std::endl;


    // 2. Deque (Double-ended queue)
    std::deque<double> deq = {1.1, 2.2, 3.3}; // Initialize a deque
    deq.push_front(0.1);       // Add 0.1 at the beginning (front)
    deq.push_back(4.4);        // Add 4.4 at the end (back)
    std::cout << "Deque elements: ";
    for (double d : deq) { std::cout << d << " "; }
    std::cout << std::endl;


    // 3. List
    std::list<std::string> lst = {"Alpha", "Beta", "Gamma"}; // Initialize a list of strings
    lst.push_front("Omega");   // Add "Omega" at the beginning
    std::cout << "List elements: ";
    for (const auto& s : lst) { std::cout << s << " "; }
    std::cout << std::endl;

    std::cout << "\n--- Associative Containers ---\n";

    // 4. Set (with Custom Comparator for Descending Order)
    std::set<int, std::greater<int>> myset = {5, 2, 5, 3, 2, 1};
    std::cout << "Set elements in descending order: ";
    for (int s : myset) { std::cout << s << " "; } // Unique and sorted in descending order
    std::cout << std::endl;

    // 5. Map
    std::map<std::string, int> mymap;     // Create an empty map
    mymap["one"] = 1;                    // Insert key-value pairs
    mymap["two"] = 2;
    mymap["three"] = 3;
    std::cout << "Map elements: \n";
    for (const auto& pair : mymap) {
        std::cout << pair.first << ": " << pair.second << std::endl; // Print key-value pairs
    }

    std::cout << "\n--- Unordered Associative Containers ---\n";

    // 6. Unordered Set
    std::unordered_set<int> uset = {10, 20, 30, 40};
    uset.insert(50);
    std::cout << "Unordered set elements: ";
    for (int u : uset) { std::cout << u << " "; }
    std::cout << std::endl;

    std::cout << "\n--- Container Adapters ---\n";

    // 7. Stack (LIFO)
    std::stack<int> st;
    st.push(1); // 1 will be at top of stack
    st.push(2);
    st.push(3);
    std::cout << "Top element of stack: " << st.top() << std::endl;
    st.pop(); // remove top 3
    std::cout << "Top element after pop: " << st.top() << std::endl;

    // 8. Queue (FIFO)
    std::queue<std::string> q;
    q.push("Alice"); // Alice will be at the front of the queue.
    q.push("Bob");
    q.push("Charlie");
    std::cout << "Front element of queue: " << q.front() << std::endl;
    q.pop(); // Remove Alice
    std::cout << "Front element of queue after pop: " << q.front() << std::endl;


    // 9. Priority Queue (max heap, by default)
    std::priority_queue<int> pq; // The first element is always the greatest
    pq.push(5);
    pq.push(10);
    pq.push(1);
    std::cout << "Top element of priority queue: " << pq.top() << std::endl;
    pq.pop(); // Remove the top (10)
    std::cout << "Top element after pop: " << pq.top() << std::endl;

}

#endif // STLCONTAINERS_H
