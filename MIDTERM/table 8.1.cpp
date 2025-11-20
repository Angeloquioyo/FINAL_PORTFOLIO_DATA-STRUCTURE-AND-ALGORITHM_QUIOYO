#include <iostream>
#include <cstdlib>
#include <ctime>
#include "table 8.1.h"   
using namespace std;

const int SIZE = 20;   

void display(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));

    int arr[SIZE];
    for (int i=0; i<SIZE; i++) {
        arr[i] = rand() % 100 + 1;
    }

    cout << "Original Array:\n";
    display(arr, SIZE);

    int arrShell[SIZE], arrMerge[SIZE], arrQuick[SIZE];
    for (int i=0; i<SIZE; i++) {
        arrShell[i] = arr[i];
        arrMerge[i] = arr[i];
        arrQuick[i] = arr[i];
    }

    shellSort(arrShell, SIZE);
    mergeSort(arrMerge, 0, SIZE-1);
    quickSort(arrQuick, 0, SIZE-1);

    // show results
    cout << "\nSorted using Shell Sort:\n";
    display(arrShell, SIZE);

    cout << "\nSorted using Merge Sort:\n";
    display(arrMerge, SIZE);

    cout << "\nSorted using Quick Sort:\n";
    display(arrQuick, SIZE);

    return 0;
}
