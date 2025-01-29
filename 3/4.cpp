/*
Tee aliohjelma aikojen_erotus, jolle välitetään parametreina kaksi ajankohtaa
(tyyppiä aika_ty, ks. edellinen tehtävä). Aliohjelma laskee näiden kahden
välitetyn ajankohdan erotuksen ja palauttaa sen paluuarvonaan (paluuarvo on myös
tyyppiä aika_ty). Oletetaan parametrien arvojen olevan järkevät ja 2. parametrin
ajankohta on suurempi tai yhtäsuuri kuin 1. parametrin; molemmat ajankohdat ovat
saman vuorokauden sisällä. Tee myös pääohjelma, jolla testaat aliohjelman
toiminnan. Pääohjelma kysyy käyttäjältä kahta ajankohtaa, joiden erotuksen
aliohjelma laskee. Pääohjelma tulostaa sitten aliohjelman palauttaman erotuksen
näytölle. Jälleen oletetaan käyttäjän syötteiden olevan järkevät. Vinkki: eräs
vaihtoehto on muuntaa molemmat ajankohdat sekunneiksi, laskea erotus sekunteina
ja muuntaa tämä erotus (sekunteina) jälleen tunneiksi, minuuteiksi ja
sekunneiksi. Tässä kannattaa hyödyntää edellisen viikon aika_sekunneiksi()- ja
sekunnit_ajaksi() –aliohjelmia.
*/

#include <cmath>
#include <iostream>

using namespace std;

struct aika_ty {
    int h;
    int m;
    int s;
};

int aika_sekunneiksi(int h, int m, int s) {
    return (h * 60 * 60) + (m * 60) + s;
}

aika_ty sekunnit_ajaksi(int s_tot) {
    aika_ty tulos;
    tulos.h = floor((s_tot / 60) / 60);
    tulos.m = floor((s_tot / 60) - (tulos.h * 60));
    tulos.s = floor(s_tot - ((tulos.h * 60 * 60) + (tulos.m * 60)));
    return tulos;
}

int main() {
    aika_ty ajat[2];

    for (int i = 0; i < 2; i++) {
        cout << "Anna " << i + 1 << ". aika." << endl << "Anna tunnit: ";
        cin >> ajat[i].h;
        cout << "Anna minuutit: ";
        cin >> ajat[i].m;
        cout << "Anna sekunnit: ";
        cin >> ajat[i].s;
    }

    aika_ty erotus =
        sekunnit_ajaksi(aika_sekunneiksi(ajat[1].h, ajat[1].m, ajat[1].s) -
                        aika_sekunneiksi(ajat[0].h, ajat[0].m, ajat[0].s));

    cout << "Aikojen ero on " << erotus.h << " tuntia " << erotus.m
         << " minuuttia ja " << erotus.s << " sekuntia.";

    return 0;
}
