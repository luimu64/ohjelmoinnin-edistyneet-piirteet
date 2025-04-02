#include "Opiskelija.h"
#include <iostream>
#include <vector>

using namespace std;

void Opiskelija::setOpNro(string opNro) { this->opNro = opNro; }

void Opiskelija::setSuoritetutKurssit(vector<string> suoritetutKurssit) {
    this->suoritetutKurssit = suoritetutKurssit;
}

void Opiskelija::setOpintopisteet(int opintopisteet) {
    this->opintopisteet = opintopisteet;
}

string Opiskelija::getOpNro() const { return opNro; }

vector<string> Opiskelija::getSuoritetutKurssit() const {
    return suoritetutKurssit;
}

int Opiskelija::getOpintopisteet() const { return opintopisteet; }

void Opiskelija::tulostaTiedot() const {
    Henkilo::tulostaTiedot();
    cout << "Opiskelijanumero: " << opNro << "\n\nSuoritetut kurssit:\n";
    for (int i = 0; i < suoritetutKurssit.size(); i++) {
        cout << suoritetutKurssit.at(i) << "\n";
    }
    cout << "Opintopisteet: " << opintopisteet << "\n\n";
}

void Opiskelija::lisaaKurssi(string kurssi) {
    suoritetutKurssit.push_back(kurssi);
}

void Opiskelija::poistaKurssi(string kurssi) {
    for (int i = 0; i < suoritetutKurssit.size(); i++) {
        if (suoritetutKurssit.at(i) == kurssi) {
            suoritetutKurssit.erase(suoritetutKurssit.begin() + i);
        }
    }
}

void Opiskelija::lisaaOpintopisteita(int opintopisteet) {
    this->opintopisteet += opintopisteet;
}

void Opiskelija::poistaOpintopisteita(int opintopisteet) {
    this->opintopisteet -= opintopisteet;
}

Opiskelija::Opiskelija() : Henkilo(), opNro("00000"), opintopisteet(0) {
    cout << "Opiskelija-luokan parametriton rakentaja" << endl;
}

Opiskelija::Opiskelija(const Opiskelija& opiskelija)
    : Henkilo(opiskelija), opNro(opiskelija.opNro),
      suoritetutKurssit(opiskelija.suoritetutKurssit),
      opintopisteet(opiskelija.opintopisteet) {
    cout << "Opiskelija-luokan kopiorakentaja" << endl;
}

Opiskelija::Opiskelija(string nimi, int ika, Osoite osoite, string opNro,
                       vector<string> suoritetutKurssit, int opintopisteet)
    : Henkilo(nimi, ika, osoite), opNro(opNro),
      suoritetutKurssit(suoritetutKurssit), opintopisteet(opintopisteet) {
    cout << "Opiskelija-luokan 6 parametrinen rakentaja" << endl;
}

Opiskelija::~Opiskelija() {
    cout << "Opiskelija-luokan purkaja kutsuttu" << endl;
}
