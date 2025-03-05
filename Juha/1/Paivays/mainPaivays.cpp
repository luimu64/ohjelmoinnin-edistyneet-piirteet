#include "Paivays.h"

int main() {
    Paivays tanaan, huomenna;
    tanaan.setPaiva(5);
    tanaan.setKuukausi(3);
    tanaan.setVuosi(2024);

    huomenna.setPaiva(6);
    huomenna.setKuukausi(3);
    huomenna.setVuosi(2024);

    tanaan.tulostaPaivays();
    huomenna.tulostaPaivays();

    Paivays uusiPaiva;
    uusiPaiva.setPaiva(28);
    uusiPaiva.setKuukausi(2);
    uusiPaiva.setVuosi(2023);

    uusiPaiva.tulostaPaivays();
    uusiPaiva.addPaiva();
    uusiPaiva.tulostaPaivays();
    uusiPaiva.addPaiva();
    uusiPaiva.tulostaPaivays();

    return 0;
}
