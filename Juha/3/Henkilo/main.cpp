#include "Henkilo.h"
#include "Osoite.h"

using namespace std;

void luoHenkilo() {
    Henkilo temp;
    temp.tulostaHenkilonTiedot();
}

int main() {
    Henkilo henkiloOsoitteella("Henkilo", 20,
                               Osoite("Jaakonkatu 55", "22357", "Pirkanmaa"));
    henkiloOsoitteella.tulostaHenkilonTiedot();

    Henkilo henkiloJolleOsoiteMyohemmin("Henkilo", 20);
    henkiloJolleOsoiteMyohemmin.setOsoite(
        Osoite("Karjalankatu 10", "55264", "Tampere"));
    henkiloJolleOsoiteMyohemmin.tulostaHenkilonTiedot();

    return 0;
}
