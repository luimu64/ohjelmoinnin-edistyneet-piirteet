#pragma once
#include "Opettaja.h"
#include "Opiskelija.h"
#include <string>

using namespace std;

class Koulu {
  public:
    void lisaaOpettaja();
    void lisaaOpiskelija();
    void lisaaOpettajalleKurssi();
    void lisaaOpiskelijalleKurssi();
    void tulostaKaikkiTiedot() const;
    void tulostaOpiskelijat() const;
    void tulostaOpettajat() const;
    void poistaOpiskelija(string opNro);
    void poistaOpettaja(string opNro);
    void setKoulunNimi(string koulunNimi);
    string getKoulunNimi() const;
    Koulu();
    Koulu(const Koulu& koulu);
    Koulu(string koulunNimi);
    ~Koulu();

  private:
    vector<Opiskelija*> opiskelijat;
    vector<Opettaja*> opettajat;
    string koulunNimi;
};
