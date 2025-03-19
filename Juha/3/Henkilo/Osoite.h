#pragma once
#include <string>

using namespace std;

class Osoite {
  private:
    string katuosoite;
    string postinumero;
    string kunta;

  public:
    void tulostaOsoite() const;
    void setKatuosoite(string katuosoite);
    void setPostinumero(string postinumero);
    void setKunta(string kunta);
    string getKatuosoite() const;
    string getPostinumero() const;
    string getKunta() const;
    Osoite(string katuosoite, string postinumero, string kunta);
    Osoite();
};
