#pragma once
#include "Paivays.h"
#include <string>

using namespace std;

class KalenteriMerkinta {
  private:
    Paivays paivays;
    string asia;
    bool muistutus;

  public:
    KalenteriMerkinta();
    KalenteriMerkinta(Paivays paivays, string asia, bool muistutus);
    KalenteriMerkinta(const KalenteriMerkinta& merkinta);
    void setPaivays(Paivays paivays);
    void setAsia(string asia);
    void setMuistutus(bool muistutus);
    Paivays getPaivays() const;
    string getAsia() const;
    bool getMuistutus() const;
    void tulostaMerkinta() const;
    void setPaivaysFromString(string paivaStr);
    void kysyTiedot();
};
