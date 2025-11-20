#include "msort.h"

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nOriginal Array (Table View):\n";
    printTable(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array (Table View):\n";
    printTable(arr, n);

    return 0;
}
