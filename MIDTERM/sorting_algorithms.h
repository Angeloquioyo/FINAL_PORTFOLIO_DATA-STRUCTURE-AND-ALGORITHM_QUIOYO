#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <iostream>
using namespace std;

// Selection Sort
void selectionSort(int arr[], int size) {
    for(int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for(int j = i + 1; j < size; ++j) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Bubble Sort
void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size - 1; ++i) {
        for(int j = 0; j < size - i - 1; ++j) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int size) {
    for(int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Merge function used by Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int* L = new int[size1];
    int* R = new int[size2];

    for(int i = 0; i < size1; ++i)
        L[i] = arr[left + i];
    for(int j = 0; j < size2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < size1 && j < size2) {
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while(i < size1)
        arr[k++] = L[i++];
    while(j < size2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

// Merge Sort
void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Print Array
void printArray(const int arr[], int size) {
    for(int i = 0; i < size; ++i) {
        cout << arr[i] << (i < size - 1 ? ", " : "\n");
    }
}

#endif // SORTING_ALGORITHMS_H
