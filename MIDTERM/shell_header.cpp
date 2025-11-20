#include "shell_header.h"

int main() {
    int numbers[] = {29, 14, 56, 8, 42, 73, 19};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Unsorted List:\n";
    showArray(numbers, n);

    doShellSort(numbers, n);

    cout << "Sorted List using Shell Sort:\n";
    showArray(numbers, n);

    return 0;
}
