#include <iostream>

void swapDeference(int& c, int& d) {
    int temp = c;
    c = d;
    d = temp;
}

void swapPoint(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int a = 5;
    int b = 1;
    int c = 3;
    int d = 7;

    std::cout << "alkuperäinen" << std::endl;
    std::cout << "a  b  c  d" << std::endl;
    std::cout << a << "  " << b << "  " << c << "  " << d << "\n\n";

    swapPoint(&a, &b);
    swapDeference(c, d);

    std::cout << "vaihdettuna" << std::endl;
    std::cout << "a  b  c  d" << std::endl;
    std::cout << a << "  " << b << "  " << c << "  " << d << std::endl;

    return 0;
}
