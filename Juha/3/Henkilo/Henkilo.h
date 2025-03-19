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
    void tulostaHenkilonTiedot() const;
    Henkilo();
    Henkilo(string nimi, int ika);
    Henkilo(string nimi, int ika, Osoite osoite);
    ~Henkilo();

  private:
    string nimi;
    int ika;
    Osoite osoite;
};
