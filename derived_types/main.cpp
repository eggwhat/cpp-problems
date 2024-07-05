#include <iostream>

void printArray(int arr[], int const size) {
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    };
    std::cout << std::endl;
}

void selectionSort(int* arr, int const size) {
    for(int i = 0; i < size; i++) {
        int min = arr[i];
        for(int j = i + 1; j < size; j++) {
            if (min > arr[j])
                min = arr[j];
        }
        std::swap(arr[i], min);
    }
}

struct Complex {
    double real;
    double imaginary;
};

struct Point {
    int x;
    int y;
};

struct Rectangle {
    Point p1;
    Point p2;
    Point p3;
    Point p4;
};

enum StructureType { complex, point, rectangle };

void magicFunction(void* unknownStruct, StructureType const structureType) {
    switch(structureType) {
        case StructureType::complex: {
            auto complex = static_cast<Complex*>(unknownStruct);
            std::cout << "Complex number: " << complex->real << " + i" << complex->imaginary << std::endl;
            break;
        }
        case StructureType::point: {
            auto point = static_cast<Point*>(unknownStruct);
            std::cout << "Point x=" << point->x << " y=" << point->y << std::endl;
            break;
        }
        case StructureType::rectangle: {
            auto rectangle = static_cast<Rectangle*>(unknownStruct);
            std::cout << "Rectangle: " <<
                "(" << rectangle->p1.x << "," << rectangle->p1.y << ") " <<
                "(" << rectangle->p2.x << "," << rectangle->p2.y << ") " <<
                "(" << rectangle->p3.x << "," << rectangle->p3.y << ") " <<
                "(" << rectangle->p4.x << "," << rectangle->p4.y << ") ";
            break;
        }
        default:
            std::cout << "Unknown object!" << std::endl;
            break;
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

    auto complex = new Complex {1,2};
    auto point = new Point {4, 20};
    auto rectangle = new Rectangle { {1,2}, {2,2}, {2, 4}, {1, 4} };

    magicFunction(complex, StructureType::complex);
    magicFunction(point, StructureType::point);
    magicFunction(rectangle, StructureType::rectangle);

    delete complex;
    delete point;
    delete rectangle;

    return 0;
}
