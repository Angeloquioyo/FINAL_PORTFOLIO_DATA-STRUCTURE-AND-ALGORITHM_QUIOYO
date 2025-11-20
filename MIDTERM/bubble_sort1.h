#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <iostream>
#include <algorithm> 

template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    for (size_t i = 0; i < arrSize; ++i) {
        for (size_t j = i + 1; j < arrSize; ++j) {
            if (arr[j] > arr[i]) {
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

#endif 
