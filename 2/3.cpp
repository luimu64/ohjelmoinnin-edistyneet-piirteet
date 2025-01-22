#include <iostream>

int min(int x, int y) { return x < y ? x : y; }

int min(int x, int y, int z) { return min(min(x, y), z); }

int min(int x, int y, int z, int w) { return min(min(x, y, z), w); }

int main() {
    std::cout << min(1, 2) << std::endl;
    std::cout << min(1, 2, 3) << std::endl;
    std::cout << min(1, 2, 3, 4) << std::endl;

    return 0;
}
