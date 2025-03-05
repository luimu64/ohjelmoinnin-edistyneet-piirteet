#include <iostream>

void addEachIndex(int* arr, int* newArr) {
    for (int i = 0; i < 10; i++) {
        newArr[i] = arr[i] + 1;
    }
}

void addEachArithmetic(int* arr, int* newArr) {
    for (int i = 0; i < 10; i++) {
        *(newArr + i) = *(arr + i) + 1;
    }
}

void printArray(int* arr) {
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    };
    std::cout << std::endl;
}

int main(void) {
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int newArr1[10];
    int newArr2[10];

    std::cout << "alkuperäinen :" << std::endl;
    printArray(arr);
    std::cout << std::endl;

    std::cout << "indekseilä :" << std::endl;
    addEachIndex(arr, newArr1);
    printArray(newArr1);
    std::cout << std::endl;

    std::cout << "aritmetiikalla :" << std::endl;
    addEachArithmetic(arr, newArr2);
    printArray(newArr2);
    std::cout << std::endl;

    return 0;
}
