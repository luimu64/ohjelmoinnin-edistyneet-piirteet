#pragma once

#include "Henkilo.h"
#include <string>
#include <vector>

using namespace std;

class Opiskelija : public Henkilo {
  public:
    void setOpNro(string opNro);
    void setSuoritetutKurssit(vector<string> suoritetutKurssit);
    void setOpintopisteet(int opintopisteet);
    string getOpNro() const;
    vector<string> getSuoritetutKurssit() const;
    int getOpintopisteet() const;
    void tulostaTiedot() const;
    void lisaaKurssi(string kurssi);
    void poistaKurssi(string kurssi);
    void lisaaOpintopisteita(int opintopisteet);
    void poistaOpintopisteita(int opintopisteet);
    Opiskelija();
    Opiskelija(const Opiskelija& opiskelija);
    Opiskelija(string nimi, int ika, Osoite osoite, string opNro,
               vector<string> suoritetutKurssit, int opintopisteet);
    virtual ~Opiskelija();

  private:
    string opNro;
    vector<string> suoritetutKurssit;
    int opintopisteet;
};
