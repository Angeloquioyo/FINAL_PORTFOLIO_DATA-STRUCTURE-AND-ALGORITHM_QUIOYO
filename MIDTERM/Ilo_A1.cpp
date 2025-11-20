#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>  
#include "sorting_algorithms.h"

using namespace std;

const int SIZE = 100;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int originalArray[SIZE];

    for(int i = 0; i < SIZE; ++i) {
        originalArray[i] = rand() % 1000;  
    }

    cout << "Original Array:\n";
    printArray(originalArray, SIZE);

    int selectionArray[SIZE];
    int bubbleArray[SIZE];
    int insertionArray[SIZE];
    int mergeArray[SIZE];

    copy(begin(originalArray), end(originalArray), begin(selectionArray));
    copy(begin(originalArray), end(originalArray), begin(bubbleArray));
    copy(begin(originalArray), end(originalArray), begin(insertionArray));
    copy(begin(originalArray), end(originalArray), begin(mergeArray));

    selectionSort(selectionArray, SIZE);
    cout << "\nSelection Sort:\n";
    printArray(selectionArray, SIZE);

    bubbleSort(bubbleArray, SIZE);
    cout << "\nBubble Sort:\n";
    printArray(bubbleArray, SIZE);

    insertionSort(insertionArray, SIZE);
    cout << "\nInsertion Sort:\n";
    printArray(insertionArray, SIZE);

    mergeSort(mergeArray, 0, SIZE - 1);
    cout << "\nMerge Sort:\n";
    printArray(mergeArray, SIZE);

    return 0;
}
