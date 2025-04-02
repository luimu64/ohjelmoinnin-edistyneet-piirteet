#pragma once

#include "Henkilo.h"
#include <string>
#include <vector>

using namespace std;

class Opettaja : public Henkilo {
  public:
    void setKurssi(string vanhaKurssi, string uusiKurssi);
    string getKurssi() const;
    void tulostaTiedot() const;
    void lisaaKurssi(string kurssi);
    void poistaKurssi(string kurssi);
    void setKoulutusala(string koulutusala);
    string getKoulutusala() const;
    Opettaja();
    Opettaja(const Opettaja& opettaja);
    Opettaja(string nimi, int ika, Osoite osoite, string koulutusala);
    ~Opettaja();

  private:
    vector<string> kurssit;
    string koulutusala;
};
