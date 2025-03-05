#include <iostream>

int main(void) {
    int a = 5;
    int* b = &a;
    int* c;

    *b = 8;

    std::cout << "a: " << std::endl;
    std::cout << "arvo: " << a << std::endl;
    std::cout << "osoite: " << &a << std::endl;
    std::cout << "koko: " << sizeof(a) << " tavua" << std::endl;
    std::cout << "b: " << std::endl;
    std::cout << "arvo: " << b << std::endl;
    std::cout << "osoite: " << &b << std::endl;
    std::cout << "koko: " << sizeof(b) << " tavua" << std::endl;

    std::cout << ((a == *b) ? "operaattorit kumoaa toisensa"
                            : "operaattorit ei kumoa toisiaan")
              << std::endl;

    // std::cout << c << std::endl;
    // error: ‘c’ is used uninitialized [-Werror=uninitialized]

    c = nullptr;
    std::cout << "c arvo: " << c << std::endl;

    return 0;
}
