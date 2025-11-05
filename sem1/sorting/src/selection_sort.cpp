#include "../include/selection_sort.h"
#include <algorithm>

template <typename T>
void selectionSort(std::vector<T>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

template void selectionSort<int>(std::vector<int>&);
template void selectionSort<double>(std::vector<double>&);
