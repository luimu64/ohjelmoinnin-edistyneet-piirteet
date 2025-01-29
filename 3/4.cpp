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
