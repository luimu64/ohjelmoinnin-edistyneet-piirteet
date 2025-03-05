#include <iostream>

void swap(int& c, int& d) {
    int temp = c;
    c = d;
    d = temp;
}

void printArray(int* arr) {
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    };
    std::cout << std::endl;
}

int main(void) {
    int taulukko[10];
    int i;

    for (i = 0; i < 10; i++) {
        taulukko[i] = i + 1;
    }

    printArray(taulukko);

    for (i = 0; i < 10; i = i + 2) {
        swap(*(taulukko + i), *(taulukko + (9 - i)));
    }

    printArray(taulukko);

    return 0;
}
