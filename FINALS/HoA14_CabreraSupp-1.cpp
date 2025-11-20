#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>

template <typename T>
void LinearSearch(int arrSize, T data[], T item){
    int i = 0;
    while(i <= arrSize){
        if(item == data[i]){
            std::cout << data[i] << " was found. Searching is successful.\n";
            return;
        }
        i++;
    }
    std::cout << "Searching is unsuccessful.\n";
}

template <typename T>
void BinarySearch(int arrSize, T data[], T item){
    int low = 0, up = arrSize-1, mid;
    while(low <= up){
        mid = (low+up)/2;
        if(item == data[mid]){
            std::cout << "Search element is found!\n";
            return;
        } else if (item < data[mid]){
            up = mid-1;
        } else {
            low = mid+1;
        }
    }
    std::cout << "Search element is not found.\n";
}


const int max_size = 10000;
void randomArr(int arr[]);

int main() {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    int array[max_size];
    randomArr(array);
    int find = 101;
    //BinarySearch(max_size,array,find);
    LinearSearch(max_size,array,find);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Runtime : " << std::chrono::duration_cast<std::chrono::microseconds>
            (end - begin).count() << " micro seconds" << std::endl;

    return 0;
}
void randomArr(int arr[]){
    for(int i = 0; i < max_size; i++){
        arr[i] = rand() % 100;
    }
}