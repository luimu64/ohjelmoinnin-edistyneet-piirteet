#include "Noppa.h"
#include <iostream>

void Noppa::kerroViimeisenHeitonLukema() {
    std::cout << "Viimeisin heitto on " << viimeisinLukema << std::endl;
}

Noppa::Noppa() : viimeisinLukema(1) {}

void Noppa::heitaNoppaa() {
    srand(time(NULL));
    viimeisinLukema = rand() % 6 + 1;
}

int Noppa::getViimeisinLukema() { return viimeisinLukema; }
