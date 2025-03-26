#include "Henkilo.h"
#include <vector>

using namespace std;

int main() {
    vector<Henkilo> henkilot;
    vector<Henkilo*> optimoidutHenkilot;

    for (int i = 0; i < 3; i++) {
        Henkilo henkilo = Henkilo();
        henkilo.kysyHenkilo();
        henkilot.push_back(henkilo);
    }

    for (int i = 0; i < 5; i++) {
        optimoidutHenkilot.push_back(new Henkilo(henkilot[i]));
    }

    for (int i = 0; i < henkilot.size(); i++) {
        henkilot[i].tulostaHenkilonTiedot();
    }

    for (int i = 0; i < optimoidutHenkilot.size(); i++) {
        optimoidutHenkilot[i]->tulostaHenkilonTiedot();
    }

    return 0;
}
