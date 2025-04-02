#include "Henkilo.h"
#include "Opettaja.h"
#include "Opiskelija.h"
#include <vector>

using namespace std;

int main() {

    vector<Henkilo*> henkilot;

    henkilot.push_back(new Henkilo());
    henkilot.push_back(new Henkilo("Matti", 25));
    henkilot.push_back(new Henkilo(*henkilot.at(1)));

    // Create and add Opiskelija objects using different constructors
    henkilot.push_back(new Opiskelija());
    henkilot.push_back(
        new Opiskelija("Teppo", 30, Osoite("Katu 1", "00100", "Helsinki"),
                       "12345", vector<string>{"Kurssi1", "Kurssi2"}, 10));
    henkilot.push_back(
        new Opiskelija(*static_cast<Opiskelija*>(henkilot.back())));

    // Create and add Opettaja objects using different constructors
    henkilot.push_back(new Opettaja());
    henkilot.push_back(new Opettaja(
        "Matti", 35, Osoite("Katu 2", "00200", "Helsinki"), "Koulutusala"));
    henkilot.push_back(new Opettaja(*static_cast<Opettaja*>(henkilot.back())));

    // Print information about all objects in the vector
    for (Henkilo* henkilo : henkilot) {
        henkilo->tulostaTiedot();
    }

    return 0;
}
