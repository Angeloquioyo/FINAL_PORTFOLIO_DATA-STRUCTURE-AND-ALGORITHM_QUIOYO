#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#include <iostream>
#include <iomanip>
using namespace std;

void doShellSort(int nums[], int length) {
    for (int step = length / 2; step > 0; step /= 2) {
        for (int i = step; i < length; i++) {
            int current = nums[i];
            int j = i;
            // shifting elements
            while (j >= step && nums[j - step] > current) {
                nums[j] = nums[j - step];
                j -= step;
            }
            nums[j] = current;
        }
    }
}

void showArray(int nums[], int length) {
    cout << "\nIdx  | Elem\n";
    cout << "--------------\n";
    for (int i = 0; i < length; i++) {
        cout << setw(4) << i << " | " << setw(4) << nums[i] << endl;
    }
    cout << endl;
}

#endif
