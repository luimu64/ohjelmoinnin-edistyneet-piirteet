#include "Noppa.h"
#include <iostream>

void Noppa::kerroViimeisenHeitonLukema() {
    if (noppienLkm == 1) {
        std::cout << "Viimeisin heitto on " << viimeisinLukema << "!"
                  << std::endl;
    } else {
        for (int i = 0; i < noppienLkm; i++) {
            std::cout << "Noppa" << i + 1 << ": " << noppienArvot[i] << ", ";
        }
        std::cout << "yhteensä " << getNoppienSumma() << std::endl;
    }
}

int Noppa::getNoppienSumma() {
    int summa = 0;
    for (int i = 0; i < noppienLkm; i++) {
        summa += noppienArvot[i];
    }
    return summa;
}

Noppa::Noppa()
    : viimeisinLukema(1), noppienLkm(1), noppienArvot(noppienLkm, 1) {}

Noppa::Noppa(int noppienLkm)
    : viimeisinLukema(1), noppienLkm(noppienLkm), noppienArvot(noppienLkm, 1) {}

void Noppa::heitaNoppaa() {
    for (int i = 0; i < noppienLkm; i++) {
        viimeisinLukema = rand() % 6 + 1;
        noppienArvot[i] = viimeisinLukema;
    }
}

int Noppa::getViimeisinLukema() { return viimeisinLukema; }
