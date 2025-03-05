#include "./Henkilo.h"
#include <iostream>

using namespace std;

void Henkilo::setNimi(string nimi) { this->nimi = nimi; }

void Henkilo::setIka(int ika) { this->ika = ika; }

string Henkilo::getNimi() const { return nimi; }

int Henkilo::getIka() const { return ika; }

void Henkilo::tulostaHenkilonTiedot() const {
    cout << "Nimi: " << nimi << "\n\nIka: " << ika << "\n\n";
}
