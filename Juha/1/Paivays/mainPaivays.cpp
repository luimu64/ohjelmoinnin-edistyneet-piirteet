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

    return 0;
}
