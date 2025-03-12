#include "Paivays.h"

void luoPaivays() {
    Paivays temp;
    temp.tulostaPaivays();
}

int main() {
    Paivays constructoriPaiva(28, 2, 2023);
    constructoriPaiva.tulostaPaivays();

    Paivays defaultConstructoriPaiva;
    defaultConstructoriPaiva.tulostaPaivays();

    Paivays* paivays = new Paivays(15, 4, 2023);
    paivays->tulostaPaivays();
    delete paivays;

    if (true) {
        Paivays temp;
        temp.tulostaPaivays();
    }

    Paivays paivaykset[3]; // käyttää oletusrakentajaa

    for (int i = 0; i < 3; i++) {
        Paivays temp;
        temp.tulostaPaivays();
    }

    luoPaivays();

    return 0;
}
