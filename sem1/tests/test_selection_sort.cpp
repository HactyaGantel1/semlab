#include "catch2/catch_amalgamated.hpp"
#include "../sorting/include/selection_sort.h"

TEST_CASE("Selection Sort - Basic functionality") {
    std::vector<int> arr = {5, 14, 2, 18, 0, 6, 12, 9};
    std::vector<int> expected = {0, 2, 5, 6, 9, 12, 14, 18};
    
    selectionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Selection Sort - Empty array") {
    std::vector<int> arr = {};
    std::vector<int> expected = {};
    
    selectionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Selection Sort - Single element") {
    std::vector<int> arr = {5};
    std::vector<int> expected = {5};
    
    selectionSort(arr);
    REQUIRE(arr == expected);
}

TEST_CASE("Selection Sort - Already sorted") {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    
    selectionSort(arr);
    REQUIRE(arr == expected);
}
