#include <cmath>
#include <iostream>

bool isPrime(int x) {
    if (x < 2) {
        return false;
    }

    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

int prime_all() {
    int count = 0;
    for (int i = 1; i <= 10000; i++) {
        if (isPrime(i)) {
            count++;
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return count;
}

int prime_half() {
    int count = 0;
    for (int i = 1; i <= 10000; i++) {
        if (isPrime(i)) {
            count++;
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return count;
}

int prime_square_root() {
    int count = 0;
    for (int i = 1; i <= 10000; i++) {
        if (isPrime(i)) {
            count++;
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return count;
}

int main() {
    int count_all = prime_all();
    int count_half = prime_half();
    int count_square_root = prime_square_root();

    std::cout << "Alkulukuja yhteensä: " << count_all << std::endl;
    std::cout << "Alkulukuja yhteensä: " << count_half << std::endl;
    std::cout << "Alkulukuja yhteensä: " << count_square_root << std::endl;

    std::cout << "Alkulukujen osuus: " << count_all / 10000.0 * 100 << "%"
              << std::endl;

    return 0;
}
