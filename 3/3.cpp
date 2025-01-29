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

struct aika_ty {
    int h;
    int m;
    int s;
};

int main() {
    aika_ty aika;
    aika_ty* p_aika = &aika;

    cout << "Anna tunnit: ";
    cin >> aika.h;
    if (aika.h < 0 || aika.h > 23) {
        cout << "Virheellinen tuntimäärä.";
        return 1;
    }

    cout << "Anna minuutit: ";
    cin >> aika.m;
    if (aika.m < 0 || aika.m > 59) {
        cout << "Virheellinen minuuttimäärä.";
        return 1;
    }

    cout << "Anna sekunnit: ";
    cin >> aika.s;
    if (aika.s < 0 || aika.s > 59) {
        cout << "Virheellinen sekuntimäärä.";
        return 1;
    }

    cout << aika.h << ":" << aika.m << ":" << aika.s << endl;
    cout << p_aika->h << ":" << p_aika->m << ":" << p_aika->s << endl;

    aika_ty aika_1 = (aika_ty){.h = 2, .m = 46, .s = 40};
    aika_ty aika_2 = aika_1;

    if (aika_1.h == aika_2.h && aika_1.m == aika_2.m && aika_1.s == aika_2.s) {
        cout << "Sisällöt ovat samat.";
    }

    return 0;
}
