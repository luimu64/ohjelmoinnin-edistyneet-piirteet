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
    cout << "Opiskelijanumero: " << opNro << "\nSuoritetut kurssit:\n";
    for (int i = 0; i < suoritetutKurssit.size() - 1; i++) {
        cout << suoritetutKurssit.at(i) << ", ";
    }
    cout << suoritetutKurssit.at(suoritetutKurssit.size() - 1) << "\n";
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

void Opiskelija::kysyOpiskelija() {
    cout << "Anna opiskelijanumero: ";
    getline(cin, opNro);
    cout << "Anna suoritetut kurssit (erottele pilkulla): ";
    string kurssit;
    getline(cin, kurssit);
    size_t pos = 0;
    while ((pos = kurssit.find(',')) != string::npos) {
        suoritetutKurssit.push_back(kurssit.substr(0, pos));
        kurssit.erase(0, pos + 1);
    }
    suoritetutKurssit.push_back(kurssit); // Add the last course
    cout << "Anna opintopisteet: ";
    string opintopisteetString;
    getline(cin, opintopisteetString);
    opintopisteet = stoi(opintopisteetString);
    this->kysyHenkilo();
}

Opiskelija::Opiskelija() : Henkilo(), opNro("00000"), opintopisteet(0) {}

Opiskelija::Opiskelija(const Opiskelija& opiskelija)
    : Henkilo(opiskelija), opNro(opiskelija.opNro),
      suoritetutKurssit(opiskelija.suoritetutKurssit),
      opintopisteet(opiskelija.opintopisteet) {}

Opiskelija::Opiskelija(string nimi, int ika, Osoite osoite, string opNro,
                       vector<string> suoritetutKurssit, int opintopisteet)
    : Henkilo(nimi, ika, osoite), opNro(opNro),
      suoritetutKurssit(suoritetutKurssit), opintopisteet(opintopisteet) {}

Opiskelija::~Opiskelija() {}
