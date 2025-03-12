#include "Noppa.h"
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(NULL));

    Noppa noppa;
    noppa.heitaNoppaa();
    noppa.kerroViimeisenHeitonLukema();
    noppa.setNoppienLkm(4);
    noppa.heitaNoppaa();
    noppa.kerroViimeisenHeitonLukema();

    Noppa monopoli(2);
    monopoli.heitaNoppaa();
    monopoli.kerroViimeisenHeitonLukema();

    Noppa yatzy(6);
    yatzy.heitaNoppaa();
    yatzy.kerroViimeisenHeitonLukema();
    return 0;
}
