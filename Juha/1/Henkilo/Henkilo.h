#pragma once
#include <string>

using namespace std;

class Henkilo {
  public:
    void setNimi(string nimi);
    void setIka(int ika);
    string getNimi() const;
    int getIka() const;
    void tulostaHenkilonTiedot() const;

  private:
    string nimi;
    int ika;
};
