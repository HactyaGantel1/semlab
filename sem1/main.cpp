#include <iostream>
#include <vector>
#include "sorting/include/insertion_sort.h"
#include "sorting/include/selection_sort.h"
#include "sorting/include/exchange_sort.h"
#include "sorting/include/bubble_sort.h"
#include "sorting/include/optimized_bubble_sort.h"

template<typename T>
void printArray(const std::vector<T>& arr, const std::string& algorithmName) {
    std::cout << algorithmName << ": ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> original = {5, 14, 2, 18, 0, 6, 12, 9};
    
    std::cout << "=== Сравнение алгоритмов сортировки ===" << std::endl;
    std::cout << "Исходный массив: ";
    for (const auto& elem : original) {
        std::cout << elem << " ";
    }
    std::cout << std::endl << std::endl;

    std::vector<int> arr1 = original;
    insertionSort(arr1);
    printArray(arr1, "Insertion Sort");

    std::vector<int> arr2 = original;
    selectionSort(arr2);
    printArray(arr2, "Selection Sort");

    std::vector<int> arr3 = original;
    exchangeSort(arr3);
    printArray(arr3, "Exchange Sort ");

    std::vector<int> arr4 = original;
    bubbleSort(arr4);
    printArray(arr4, "Bubble Sort   ");

    std::vector<int> arr5 = original;
    optimizedBubbleSort(arr5);
    printArray(arr5, "Opt Bubble Sort");
    
    std::cout << std::endl << "Ожидаемый результат: 0 2 5 6 9 12 14 18" << std::endl;
    
    return 0;
}
