#include "../include/bubble_sort.h"
#include <algorithm>

template <typename T>
void bubbleSort(std::vector<T>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template void bubbleSort<int>(std::vector<int>&);
template void bubbleSort<double>(std::vector<double>&);
