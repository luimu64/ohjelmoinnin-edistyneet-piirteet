/*
Kirjoita aliohjelma s_ajaksi, joka saa 1. parametrina sekunttien määrän
vuorokauden alusta alkaen (kellonlyömästä 00:00:00 alkaen) ja palauttaa saman
ajan tunteina, minuutteina ja sekunteina. Tee myös pääohjelma, jolla testaat em.
aliohjelmaa. Esimerkiksi jos sekuntimäärä = 10000, niin vastaava aika tunteina,
minuutteina ja sekunteina on 2 tuntia 46 minuuttia 40 sekuntia. Huomaa, että
aliohjelmasta pitää palauttaa useampia tietoja; sovella tässä
viittausparametreja. Ajoesimerkki: 10000 sekuntia on 2 tuntia 46 minuuttia 40
sekuntia.
*/

#include <cmath>
#include <iostream>

using namespace std;

void s_ajaksi(int s_tot, int& h, int& m, int& s) {
    h = floor((s_tot / 60) / 60);
    m = floor((s_tot / 60) - (h * 60));
    s = floor(s_tot - ((h * 60 * 60) + (m * 60)));
}

int main() {
    int s_tot = 10000;
    int h, m, s;
    s_ajaksi(s_tot, h, m, s);
    cout << s_tot << " sekuntia on " << h << " tuntia " << m << " minuuttia "
         << s << " sekuntia.";
    return 0;
}
