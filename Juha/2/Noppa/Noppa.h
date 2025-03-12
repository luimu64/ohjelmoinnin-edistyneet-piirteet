#pragma once
#include <string>

using namespace std;

class Noppa {
  public:
    Noppa();
    void heitaNoppaa();
    int getViimeisinLukema();
    void kerroViimeisenHeitonLukema();

  private:
    int viimeisinLukema;
};
