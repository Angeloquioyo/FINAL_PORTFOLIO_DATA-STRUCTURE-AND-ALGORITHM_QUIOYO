#include <iostream>

int sumRecursive(int numbers[], int size) {
    if (size <= 0) {
        return 0; // Base case: empty array
    }
    return numbers[size - 1] + sumRecursive(numbers, size - 1);
}

int main() {
    int myNumbers[] = {1, 2, 3, 4, 5};
    int arraySize = 5;
    int totalSum = sumRecursive(myNumbers, arraySize);
    std::cout << "The sum is: " << totalSum << std::endl;
    return 0;
}