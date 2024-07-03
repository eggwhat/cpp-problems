#include <iostream>

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    };
    std::cout << std::endl;
}

void insertionSort(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        int min = arr[i];
        for(int j = i + 1; j < size; j++) {
            if (min > arr[j])
                min = arr[j];
        }
        std::swap(arr[i], min);
    }
}

int main() {
    const int arraySize = 5;
    int a[arraySize] = {2, 1, 3, 7, 0};
    printArray(a, arraySize);
    a[4] = 2137;
    insertionSort(a, arraySize);
    printArray(a, arraySize);

    return 0;
}
