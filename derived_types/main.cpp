#include <iostream>

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    };
    std::cout << std::endl;
}

void selectionSort(int* arr, int size) {
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
    selectionSort(a, arraySize);
    printArray(a, arraySize);

    double bigDouble = 200'123'456'789'123'456'789.312'313'232;
    std::cout << "Inserting large double: " << bigDouble << " to int array" << std::endl;
    a[3] = bigDouble;
    printArray(a, arraySize);

    return 0;
}
