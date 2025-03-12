#pragma once
#include <string>
#include <vector>

using namespace std;

class Noppa {
  public:
    Noppa();
    Noppa(int noppienLkm);
    void heitaNoppaa();
    int getViimeisinLukema();
    int getNoppienLkm();
    void setNoppienLkm(int noppienLkm);
    void kerroViimeisenHeitonLukema();

  private:
    int viimeisinLukema;
    int noppienLkm;
    vector<int> noppienArvot;
    int getNoppienSumma();
};
