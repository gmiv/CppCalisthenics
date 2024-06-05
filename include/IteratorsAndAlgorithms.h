#ifndef ITERATORSANDALGORITHMS_H
#define ITERATORSANDALGORITHMS_H

#include <iostream>           // For input/output operations (e.g., printing to console)
#include <vector>             // For using vector containers
#include <algorithm>          // For standard algorithms (sort, reverse, find, for_each, copy, etc.)
#include <iterator>           // For iterator types (e.g., ostream_iterator)
#include <functional>         // For function objects like std::greater

// ----------------------------------------------------------------------------
// Section 1: Introduction to Iterators in the STL (Navigation Made Easy)
// ----------------------------------------------------------------------------
/*
 * What are Iterators?
 * - Iterators are objects that point to elements within STL containers (like vector, list, set, map).
 * - They provide a generic and flexible way to traverse and access container elements.
 * - Different iterator types have different capabilities:
 *   - Input Iterators:  Read elements sequentially (one pass only).
 *   - Output Iterators: Write elements sequentially.
 *   - Forward Iterators: Read/Write elements sequentially, can be incremented.
 *   - Bidirectional Iterators: Like Forward Iterators, but can also be decremented.
 *   - Random Access Iterators: Like Bidirectional Iterators, but support "jumping" to specific positions.
 *
 * Container-Specific Iterators:
 *   - Each STL container has its own set of iterators tailored to its specific needs:
 *     - vector::iterator, list::iterator, set::iterator, etc.
 *   - You obtain iterators using member functions like:
 *     - begin(): Returns an iterator pointing to the first element.
 *     - end(): Returns an iterator pointing past the last element (important for loop termination).
 */


// ----------------------------------------------------------------------------
// Section 2: The Power of Algorithms in the STL (Efficient Operations on Data)
// ----------------------------------------------------------------------------

/*
 * What are STL Algorithms?
 *   - Generic functions that operate on ranges of elements defined by iterators.
 *   - They abstract common operations like sorting, searching, transforming, counting, etc.
 *   - Algorithms work with various container types thanks to the flexibility of iterators.
 *   - This leads to highly reusable and efficient code.
 *
 * Categories of Algorithms:
 *   - Non-modifying algorithms: Don't change the elements of the container (e.g., find, count, for_each).
 *   - Modifying algorithms:  Change the order or values of elements (e.g., sort, reverse, remove, replace).
 *   - Sorting algorithms:  Specialize in ordering elements (e.g., sort, partial_sort, nth_element).
 *   - Numeric algorithms: Operate on numeric data (e.g., accumulate, inner_product, partial_sum).
 *   - And many more!
 */


//------------------------------------------------------------------------------
// Section 3: Demonstrating Iterators and Algorithms (Code Examples)
//------------------------------------------------------------------------------

void runIteratorsAndAlgorithms() {

    // 1. Vector of Integers:
    std::vector<int> v = {5, 3, 1, 4, 2};  // Initialize a vector with elements

    // 2. Sorting (Modifying Algorithm):
    std::cout << "\nSorting Vector (Ascending Order):\n";
    std::sort(v.begin(), v.end());        // Sort the vector in ascending order using the default comparison
    for (int i : v) { std::cout << i << " "; }
    std::cout << "\n";

    // Sorting with a Custom Comparator (Descending Order):
    std::cout << "\nSorting Vector (Descending Order):\n";
    std::sort(v.begin(), v.end(), std::greater<int>()); // Sort in descending order using std::greater
    for (int i : v) { std::cout << i << " "; }
    std::cout << "\n";


    // 3. Reversing (Modifying Algorithm):
    std::cout << "\nReversed Vector:\n";
    std::reverse(v.begin(), v.end()); // Reverse the order of elements in the vector
    for (int i : v) { std::cout << i << " "; }
    std::cout << "\n";

    // 4. Lambda Expression with for_each (Non-Modifying Algorithm):
    std::cout << "\nLambda Expression Example (Squaring Elements):\n";
    std::for_each(v.begin(), v.end(), [](int& x) { x *= x; }); // Square each element in-place using a lambda

    // 5. Using ostream_iterator (Output Iterator) and copy
    std::cout << "\nOutput using ostream_iterator and copy:\n";
    //  - ostream_iterator adapts an output stream (std::cout) to function as an iterator.
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));  // Copy elements to cout, separated by spaces.
    std::cout << "\n";

    // Additional Examples (Uncomment to try):

    // // 6. Finding Elements (Non-Modifying Algorithms):
    // auto it = std::find(v.begin(), v.end(), 25);
    // if (it != v.end()) {
    //     std::cout << "Found 25 at position: " << std::distance(v.begin(), it) << "\n";
    // } else {
    //     std::cout << "25 not found.\n";
    // }

    // // 7. Counting Elements (Non-Modifying Algorithms):
    // int count_of_16 = std::count(v.begin(), v.end(), 16);
    // std::cout << "Count of 16: " << count_of_16 << "\n";

    // // 8. Transforming Elements (Modifying Algorithms):
    // std::transform(v.begin(), v.end(), v.begin(), [](int x) { return x * 2; }); // Double each element
    // std::cout << "Transformed Vector: ";
    // std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << "\n";
}
#endif // ITERATORSANDALGORITHMS_H
