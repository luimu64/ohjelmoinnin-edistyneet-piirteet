#include "Henkilo.h"

using namespace std;

int main() {
    Henkilo henkilo1;
    Henkilo henkilo2;

    henkilo1.setNimi("Juha");
    henkilo1.setIka(25);
    henkilo2.setNimi("Matti");
    henkilo2.setIka(30);

    henkilo1.tulostaHenkilonTiedot();
    henkilo2.tulostaHenkilonTiedot();

    Henkilo pekka;
    pekka.tulostaHenkilonTiedot();

    Henkilo henkilot[3];

    for (int i = 0; i < 3; i++) {
        henkilot[i].tulostaHenkilonTiedot();
    }

    return 0;
}
