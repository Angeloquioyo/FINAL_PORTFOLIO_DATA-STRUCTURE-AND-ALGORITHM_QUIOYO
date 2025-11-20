#include <iostream>
#include <time.h>
#include <chrono>

const int max_size = 10000;

void randomArr(int *arr);
void displayArr(int *arr);

int partition(int *arr, int low, int high);
void quickSort(int *arr, int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int partition(int *arr, int low, int high){
    int middle = (low+high)/2;

    int temp = arr[middle];
    arr[middle] = arr[high];
    arr[high] = temp;

    int left = low, right = high-1;

    while(arr[left] < arr[high]){
        left++;
    }

    while(right > left){
        if(arr[right] < arr[left]){
            temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
            while(arr[left] < arr[high]){
                left++;
            }
        }
        right--;
    }

    temp = arr[left];
    arr[left] = arr[high];
    arr[high] = temp;
    return left;
}

int main() {
    int unsortedList[max_size];

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    randomArr(unsortedList);
    quickSort(unsortedList, 0, max_size-1);
    displayArr(unsortedList);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Runtime : " << std::chrono::duration_cast<std::chrono::microseconds>
            (end - begin).count() << " micro seconds" << std::endl;
    return 0;
}

void randomArr(int *arr){
    for(int i = 0; i < max_size; i++){
        arr[i] = rand() % 100;
    }
}

void displayArr(int *arr){
    for(int i = 0; i < max_size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}