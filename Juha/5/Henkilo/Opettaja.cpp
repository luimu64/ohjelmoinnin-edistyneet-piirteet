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

string Opettaja::getKurssi() const {
    string kurssitString = "";
    for (int i = 0; i < kurssit.size(); i++) {
        kurssitString += kurssit.at(i) + "\n";
    }
    return kurssitString;
}

void Opettaja::tulostaTiedot() const {
    Henkilo::tulostaTiedot();
    cout << "Koulutusala: " << koulutusala << "\n\nKurssit:\n" << getKurssi();
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

Opettaja::Opettaja() : Henkilo(), koulutusala("Tuntematon") {
    cout << "Opettaja-luokan parametriton rakentaja" << endl;
}

Opettaja::Opettaja(const Opettaja& opettaja)
    : Henkilo(opettaja), kurssit(opettaja.kurssit),
      koulutusala(opettaja.koulutusala) {
    cout << "Opettaja-luokan kopiorakentaja" << endl;
}

Opettaja::Opettaja(string nimi, int ika, Osoite osoite, string koulutusala)
    : Henkilo(nimi, ika, osoite), koulutusala(koulutusala) {
    cout << "Opettaja-luokan 4 parametrinen rakentaja" << endl;
}

Opettaja::~Opettaja() { cout << "Opettaja-luokan purkaja kutsuttu" << endl; }
