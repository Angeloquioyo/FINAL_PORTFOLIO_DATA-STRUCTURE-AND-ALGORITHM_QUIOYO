#include <iostream>
#include <time.h>
#include <chrono>

const int max_size = 10000;

void randomArr(int *arr);
void displayArr(int *arr);

void merge(int *subArr, int first, int mid, int last);
void mergeSort(int *arr, int first, int last){
    if(first == last) return;

    if(first < last){
        int middle = (first+last)/2;
        mergeSort(arr, first, middle);
        mergeSort(arr, middle+1, last);
        merge(arr, first, middle, last);
    }
}

void merge(int *subArr, int first, int mid, int last){
    int temp[last+1], indexLeft = first, indexRight = mid+1;
    int i;

    for(i = first; indexLeft <= mid && indexRight <= last; i ++){
        if(subArr[indexLeft] < subArr[indexRight]){
            temp[i] = subArr[indexLeft];
            indexLeft++;
        } else {
            temp[i] = subArr[indexRight];
            indexRight++;
        }
    }

    while(indexLeft <= mid){
        temp[i] = subArr[indexLeft];
        i++; indexLeft++;
    }

    while(indexRight <= last){
        temp[i] = subArr[indexRight];
        i++; indexRight++;
    }

    for(int j = first; j < i; j++){
        subArr[j] = temp[j];
    }
}

int main() {
    int unsortedList[max_size];

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    randomArr(unsortedList);
    mergeSort(unsortedList, 0, max_size-1);
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