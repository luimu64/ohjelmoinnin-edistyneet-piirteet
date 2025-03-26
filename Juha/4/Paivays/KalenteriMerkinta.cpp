#include "KalenteriMerkinta.h"
#include <iostream>
#include <string>

using namespace std;

void KalenteriMerkinta::tulostaMerkinta() const {
    this->paivays.tulostaPaivays();
    cout << "Asia: " << asia << endl;
    cout << "Muistutus: " << (muistutus ? "Kyllä" : "Ei") << endl;
}

void KalenteriMerkinta::setPaivaysFromString(string paivaStr) {
    int paiva, kuukausi, vuosi;
    sscanf(paivaStr.c_str(), "%d.%d.%d", &paiva, &kuukausi, &vuosi);
    this->paivays.setPaiva(paiva);
    this->paivays.setKuukausi(kuukausi);
    this->paivays.setVuosi(vuosi);
}

void KalenteriMerkinta::kysyTiedot() {
    cout << "Anna päiväys (pp.kk.vvvv): ";
    string paivaStr;
    getline(cin, paivaStr);
    setPaivaysFromString(paivaStr);
    cout << "Anna asia: ";
    getline(cin, asia);
    cout << "Anna muistutus (Kyllä/Ei): ";
    string muistutusStr;
    cin >> muistutusStr;
    muistutus = (muistutusStr == "Kyllä");
}

KalenteriMerkinta::KalenteriMerkinta() {
    paivays = Paivays();
    asia = "";
    muistutus = false;
}

KalenteriMerkinta::KalenteriMerkinta(Paivays paivays, string asia,
                                     bool muistutus)
    : paivays(paivays), asia(asia), muistutus(muistutus) {}

KalenteriMerkinta::KalenteriMerkinta(const KalenteriMerkinta& merkinta) {
    paivays = Paivays(26, 3, 2025);
    asia = merkinta.asia;
    muistutus = merkinta.muistutus;
}

void KalenteriMerkinta::setPaivays(Paivays paivays) { this->paivays = paivays; }

void KalenteriMerkinta::setAsia(string asia) { this->asia = asia; }

void KalenteriMerkinta::setMuistutus(bool muistutus) {
    this->muistutus = muistutus;
}

Paivays KalenteriMerkinta::getPaivays() const { return paivays; }

bool KalenteriMerkinta::getMuistutus() const { return muistutus; }

string KalenteriMerkinta::getAsia() const { return asia; }
