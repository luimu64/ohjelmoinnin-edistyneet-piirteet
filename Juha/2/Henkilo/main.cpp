#include "Henkilo.h"

using namespace std;

int main() {
    Henkilo pekka;
    pekka.tulostaHenkilonTiedot();

    Henkilo henkilot[3];

    for (int i = 0; i < 3; i++) {
        henkilot[i].tulostaHenkilonTiedot();
    }

    return 0;
}
