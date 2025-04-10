#include "Opettaja.h"
#include <iostream>
#include <vector>

using namespace std;

void Opettaja::setKurssi(string vanhaKurssi, string uusiKurssi) {
    for (int i = 0; i < kurssit.size(); i++) {
        if (kurssit.at(i) == vanhaKurssi) {
            kurssit.at(i) = uusiKurssi;
        }
    }
}

void Opettaja::tulostaTiedot() const {
    Henkilo::tulostaTiedot();
    cout << "Koulutusala: " << koulutusala << "\nKurssit:\n";
    for (int i = 0; i < kurssit.size() - 1; i++) {
        cout << kurssit.at(i) << ", ";
    }
    cout << kurssit.at(kurssit.size() - 1) << "\n";
}

void Opettaja::lisaaKurssi(string kurssi) { kurssit.push_back(kurssi); }

void Opettaja::poistaKurssi(string kurssi) {
    for (int i = 0; i < kurssit.size(); i++) {
        if (kurssit.at(i) == kurssi) {
            kurssit.erase(kurssit.begin() + i);
        }
    }
}

void Opettaja::setKoulutusala(string koulutusala) {
    this->koulutusala = koulutusala;
}

string Opettaja::getKoulutusala() const { return koulutusala; }

void Opettaja::kysyOpettaja() {
    cout << "Anna koulutusala: ";
    getline(cin, koulutusala);
    cout << "Anna kurssit (erottele pilkulla): ";
    string kurssitString;
    getline(cin, kurssitString);
    size_t pos = 0;
    while ((pos = kurssitString.find(',')) != string::npos) {
        kurssit.push_back(kurssitString.substr(0, pos));
        kurssitString.erase(0, pos + 1);
    }
    kurssit.push_back(kurssitString); // Add the last course
    this->kysyHenkilo();
}

Opettaja::Opettaja() : Henkilo(), koulutusala("Tuntematon") {}

Opettaja::Opettaja(const Opettaja& opettaja)
    : Henkilo(opettaja), kurssit(opettaja.kurssit),
      koulutusala(opettaja.koulutusala) {}

Opettaja::Opettaja(string nimi, int ika, Osoite osoite, string koulutusala)
    : Henkilo(nimi, ika, osoite), koulutusala(koulutusala) {}

Opettaja::~Opettaja() {}
