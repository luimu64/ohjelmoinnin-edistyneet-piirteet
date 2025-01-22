#include <cmath>
#include <iostream>

int main() {
    double luku;
    std::cout << "Anna luku: ";
    std::cin >> luku;

    int alaraja = std::floor(luku);
    int ylaraja = std::ceil(luku);

    std::cout << "Luku " << luku << " sisaltyy välille " << "[ " << alaraja
              << ", " << ylaraja << " ]." << std::endl;

    return 0;
}
