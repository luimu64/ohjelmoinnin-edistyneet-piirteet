#pragma once
#include "Osoite.h"
#include <string>

using namespace std;

class Henkilo {
  public:
    void setNimi(string nimi);
    void setIka(int ika);
    void setOsoite(Osoite osoite);
    string getNimi() const;
    int getIka() const;
    Osoite getOsoite() const;
    void tulostaTiedot() const;
    void kysyHenkilo();
    Henkilo();
    Henkilo(const Henkilo& henkilo);
    Henkilo(string nimi, int ika);
    Henkilo(string nimi, int ika, Osoite osoite);
    virtual ~Henkilo();

  private:
    string nimi;
    int ika;
    Osoite osoite;
};
