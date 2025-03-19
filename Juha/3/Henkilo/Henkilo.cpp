#include "./Henkilo.h"
#include <iostream>

using namespace std;

void Henkilo::setNimi(string nimi) { this->nimi = nimi; }

void Henkilo::setIka(int ika) { this->ika = ika; }

void Henkilo::setOsoite(Osoite osoite) { this->osoite = osoite; }

string Henkilo::getNimi() const { return nimi; }

int Henkilo::getIka() const { return ika; }

Osoite Henkilo::getOsoite() const { return osoite; }

void Henkilo::tulostaHenkilonTiedot() const {
    cout << "Nimi: " << nimi << "\n\nIka: " << ika << "\n\n";
    osoite.tulostaOsoite();
}

Henkilo::Henkilo(string nimi, int ika) : nimi(nimi), ika(ika) {
    cout << "Henkilo-luokan 2 parametrinen rakentaja" << endl;
}

Henkilo::Henkilo(string nimi, int ika, Osoite osoite)
    : nimi(nimi), ika(ika), osoite(osoite) {
    cout << "Henkilo-luokan 3 parametrinen rakentaja" << endl;
}

Henkilo::Henkilo() : nimi("Tuntematon"), ika(0), osoite(Osoite()) {
    cout << "Henkilo–luokan parametriton rakentaja" << endl;
}

Henkilo::~Henkilo() { cout << "Henkilo-luokan purkaja kutsuttu" << endl; }
