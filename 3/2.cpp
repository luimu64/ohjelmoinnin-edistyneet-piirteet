/*
Tee 1 tehtävän aliohjelmalle käänteinen aliohjelma aika_sekunneiksi, joka saa
parametreina tunnit, minuutit ja sekunnit vuorokauden alusta lukien ja palautaa
paluuarvonaan parametreja vastaavan sekuntimäärän vuorokauden alusta lukien.
Testaa aliohjelmasi toimintaa sopivalla pääohjelmalla; esimerkiksi voit kutsua
pääohjelmassasi ensin aika_sekunneiksi –aliohjelmaa ja sen jälkeen aliohjelmaa
sekunnit_ajaksi (= harjoituksen 2 ratkaisu), jolle annat sekuntimääränä 1.
aliohjelmakutsun palauttaman arvon. 2. aliohjelmakutsun palauttaman ajankohdan
pitäisi olla sama kuin 1. aliohjelmakutsulle annettiin parametrina.
Ajoesimerkki:
2 tuntia 46 minuuttia 40 sekuntia on 10000 sekuntia joka on
puolestaan 2 tuntia 46 minuuttia 40 sekuntia.
*/

#include <cmath>
#include <iostream>

using namespace std;

void sekunnit_ajaksi(int s_tot, int& h, int& m, int& s) {
    h = floor((s_tot / 60) / 60);
    m = floor((s_tot / 60) - (h * 60));
    s = floor(s_tot - ((h * 60 * 60) + (m * 60)));
}

void aika_sekunneiksi(int h, int m, int s, int& s_tot) {
    s_tot = (h * 60 * 60) + (m * 60) + s;
}

int main() {
    int s_tot = 10000;
    int h, m, s;
    sekunnit_ajaksi(s_tot, h, m, s);
    cout << s_tot << " sekuntia on " << h << " tuntia " << m << " minuuttia "
         << s << " sekuntia,";
    aika_sekunneiksi(h, m, s, s_tot);
    cout << " joka on " << s_tot << " sekunteina.";
    return 0;
}
