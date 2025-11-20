#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <iostream>
using namespace std;

template <typename T>
void insertionSort(T arr[], const int N) {
    int K = 1, J;
    T temp;

    while (K < N) {
        temp = arr[K];
        J = K - 1;

        while (J >= 0 && temp <= arr[J]) {
            arr[J + 1] = arr[J];
            J--;
        }

        arr[J + 1] = temp;
        K++;
    }
}

#endif
