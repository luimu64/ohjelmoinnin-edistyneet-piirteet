#include "Henkilo.h"

using namespace std;

void luoHenkilo() {
    Henkilo temp;
    temp.tulostaHenkilonTiedot();
}

int main() {
    Henkilo tuntematon;
    tuntematon.tulostaHenkilonTiedot();

    Henkilo pekka("Pekka", 30);
    pekka.tulostaHenkilonTiedot();

    Henkilo* johannes = new Henkilo("Johannes", 25);
    johannes->tulostaHenkilonTiedot();
    delete johannes;

    if (true) {
        Henkilo temp;
        temp.tulostaHenkilonTiedot();
    }

    Henkilo henkilot[3]; // käyttää oletusrakentajaa

    for (int i = 0; i < 3; i++) {
        Henkilo temp;
        temp.tulostaHenkilonTiedot();
    }

    luoHenkilo();

    return 0;
}
