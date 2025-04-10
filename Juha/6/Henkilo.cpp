#include "./Henkilo.h"
#include "./Osoite.h"
#include <iostream>

using namespace std;

void Henkilo::setNimi(string nimi) { this->nimi = nimi; }

void Henkilo::setIka(int ika) { this->ika = ika; }

void Henkilo::setOsoite(Osoite osoite) { this->osoite = osoite; }

string Henkilo::getNimi() const { return nimi; }

int Henkilo::getIka() const { return ika; }

Osoite Henkilo::getOsoite() const { return osoite; }

void Henkilo::kysyHenkilo() {
    string ikaString;

    cout << "Anna nimi: ";
    getline(cin, nimi);

    cout << "Anna ikä: ";
    getline(cin, ikaString);
    this->ika = stoi(ikaString);

    osoite.kysyOsoite();
}

void Henkilo::tulostaTiedot() const {
    cout << "Nimi: " << nimi << "\nIka: " << ika << "\n";
    osoite.tulostaOsoite();
}

Henkilo::Henkilo(const Henkilo& henkilo)
    : nimi(henkilo.nimi), ika(henkilo.ika), osoite(henkilo.osoite) {}

Henkilo::Henkilo(string nimi, int ika) : nimi(nimi), ika(ika) {}

Henkilo::Henkilo(string nimi, int ika, Osoite osoite)
    : nimi(nimi), ika(ika), osoite(osoite) {}

Henkilo::Henkilo() : nimi("Tuntematon"), ika(0), osoite(Osoite()) {}

Henkilo::~Henkilo() {}
