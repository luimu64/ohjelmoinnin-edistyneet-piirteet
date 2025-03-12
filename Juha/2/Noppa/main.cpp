#include "Noppa.h"
#include <iostream>

int main() {
    Noppa noppa;
    noppa.heitaNoppaa();
    std::cout << "Viimeisin heitto: " << noppa.getViimeisinLukema()
              << std::endl;
    return 0;
}
