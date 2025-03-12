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

void Paivays::setAllFromUser() {
    int paiva_, kuukausi_, vuosi_;
    cout << "Anna päivä: ";
    cin >> paiva_;
    cout << "Anna kuukausi: ";
    cin >> kuukausi_;
    cout << "Anna vuosi: ";
    cin >> vuosi_;
    setPaiva(paiva_);
    setKuukausi(kuukausi_);
    setVuosi(vuosi_);
}

bool isKarkausvuosi(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void Paivays::addPaiva() {
    int paiviaVuodessa[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (kuukausi == 2 && isKarkausvuosi(vuosi)) {
        paiviaVuodessa[1] = 29;
    }

    paiva++;

    if (paiva > paiviaVuodessa[kuukausi - 1]) {
        paiva = 1;
        kuukausi++;
        if (kuukausi > 12) {
            kuukausi = 1;
            vuosi++;
        }
    }
}

Paivays::Paivays() : paiva(1), kuukausi(1), vuosi(1970) {
    std::cout << "Paivays-luokan parametriton rakentaja" << std::endl;
}

Paivays::Paivays(int paiva_, int kuukausi_, int vuosi_)
    : paiva(paiva_), kuukausi(kuukausi_), vuosi(vuosi_) {
    std::cout << "Paivays-luokan 2 parametrinen rakentaja" << std::endl;
}
