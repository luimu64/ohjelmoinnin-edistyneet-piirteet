#include "Koulu.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int running = 1;
    Koulu koulu("Koulu");

    while (running) {
        int valinta = 0;
        cout << "Valitse toiminto:\n1. Lisaa opettaja\n2. Lisaa opettajalle "
                "kurssi\n3. "
                "Lisaa opiskelija\n4. Lisaa opiskelijalle kurssi\n5. Tulosta "
                "opettajat\n6. "
                "Tulosta opiskelijat\n7. Tulosta kaikki tiedot\n8. Lopeta "
                "ohjelma\n";
        cin >> valinta;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (valinta) {
        case 1:
            koulu.lisaaOpettaja();
            break;
        case 2:
            koulu.lisaaOpettajalleKurssi();
            break;
        case 3:
            koulu.lisaaOpiskelija();
            break;
        case 4:
            koulu.lisaaOpiskelijalleKurssi();
            break;
        case 5:
            koulu.tulostaOpettajat();
            break;
        case 6:
            koulu.tulostaOpiskelijat();
            break;
        case 7:
            koulu.tulostaKaikkiTiedot();
            break;
        case 8:
            running = 0;
            break;
        default:
            cout << "Virheellinen valinta, yritä uudelleen.\n";
        }
    }
    return 0;
}
