#include "Paivays.h"
#include <iostream>

using namespace std;

void Paivays::setPaiva(int paiva_) {
    if (paiva_ >= 1 && paiva_ <= 31) {
        paiva = paiva_;
    }
}

void Paivays::setKuukausi(int kuukausi_) {
    if (kuukausi_ >= 1 && kuukausi_ <= 12) {
        kuukausi = kuukausi_;
    }
}

void Paivays::setVuosi(int vuosi_) { vuosi = vuosi_; }

int Paivays::getPaiva() const { return paiva; }

int Paivays::getKuukausi() const { return kuukausi; }

int Paivays::getVuosi() const { return vuosi; }

void Paivays::tulostaPaivays() const {
    cout << paiva << "." << kuukausi << "." << vuosi << endl;
}
