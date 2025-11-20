#include <iostream>
#include <cstdlib>
#include <ctime>
#include "selection_sort.h"

using namespace std;

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << (i < size - 1 ? ", " : "\n");
    }
}

int main() {
    const int SIZE = 10;
    int arr[SIZE];

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100;
    }

    cout << "Original Array:\n";
    printArray(arr, SIZE);

    selectionSort(arr, SIZE);

    cout << "\nSorted Array (Ascending - Selection Sort):\n";
    printArray(arr, SIZE);

    return 0;
}
