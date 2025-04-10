#include "Koulu.h"
#include <iostream>

void Koulu::lisaaOpiskelija() {
    Opiskelija* opiskelija = new Opiskelija();
    opiskelija->kysyOpiskelija();
    opiskelijat.push_back(opiskelija);
}

void Koulu::lisaaOpettaja() {
    Opettaja* opettaja = new Opettaja();
    opettaja->kysyOpettaja();
    opettajat.push_back(opettaja);
}

void Koulu::tulostaKaikkiTiedot() const {
    cout << "Koulun nimi: " << koulunNimi << "\n";
    cout << "Opiskelijoiden lukumäärä: " << opiskelijat.size() << "\n";
    cout << "Opettajien lukumäärä: " << opettajat.size() << "\n\n";
    tulostaOpiskelijat();
    tulostaOpettajat();
}

void Koulu::tulostaOpiskelijat() const {
    cout << "Opiskelijat:\n";
    for (const Opiskelija* opiskelija : opiskelijat) {
        opiskelija->tulostaTiedot();
    }
    cout << endl;
}

void Koulu::tulostaOpettajat() const {
    cout << "Opettajat:\n";
    for (const Opettaja* opettaja : opettajat) {
        opettaja->tulostaTiedot();
    }
    cout << endl;
}

void Koulu::poistaOpiskelija(string opNro) {
    for (int i = 0; i < opiskelijat.size(); i++) {
        if (opiskelijat.at(i)->getOpNro() == opNro) {
            delete opiskelijat.at(i);
            opiskelijat.erase(opiskelijat.begin() + i);
            break;
        }
    }
}

void Koulu::poistaOpettaja(string opNro) {
    for (int i = 0; i < opettajat.size(); i++) {
        if (opettajat.at(i)->getNimi() == opNro) {
            delete opettajat.at(i);
            opettajat.erase(opettajat.begin() + i);
            break;
        }
    }
}

void Koulu::setKoulunNimi(string koulunNimi) { this->koulunNimi = koulunNimi; }

string Koulu::getKoulunNimi() const { return koulunNimi; }

void Koulu::lisaaOpettajalleKurssi() {
    string kurssi, nimi;
    cout << "Anna muokattavan opettajan nimi: ";
    getline(cin, nimi);
    cout << "Anna lisättävä kurssi: ";
    getline(cin, kurssi);
    for (Opettaja* opettaja : opettajat) {
        if (opettaja->getNimi() == nimi) {
            opettaja->lisaaKurssi(kurssi);
            break;
        }
    }
}

void Koulu::lisaaOpiskelijalleKurssi() {
    string kurssi, opNro;
    cout << "Anna muokattavan opiskelijan opiskelijanumero: ";
    getline(cin, opNro);
    cout << "Anna lisättävä kurssi: ";
    getline(cin, kurssi);
    for (Opiskelija* opiskelija : opiskelijat) {
        if (opiskelija->getOpNro() == opNro) {
            opiskelija->lisaaKurssi(kurssi);
            break;
        }
    }
}

Koulu::Koulu() : koulunNimi("Tuntematon") {}

Koulu::Koulu(const Koulu& koulu)
    : opiskelijat(koulu.opiskelijat), opettajat(koulu.opettajat),
      koulunNimi(koulu.koulunNimi) {}

Koulu::Koulu(string koulunNimi) : koulunNimi(koulunNimi) {}

Koulu::~Koulu() {
    for (Opiskelija* opiskelija : opiskelijat) {
        delete opiskelija;
    }
    for (Opettaja* opettaja : opettajat) {
        delete opettaja;
    }
}
