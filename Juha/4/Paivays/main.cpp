#include "KalenteriMerkinta.h"

void arvoParametri(KalenteriMerkinta merkinta) {
    KalenteriMerkinta kopio(merkinta);
    kopio.tulostaMerkinta();
}

void viiteParametri(const KalenteriMerkinta& merkinta) {
    KalenteriMerkinta kopio(merkinta);
    kopio.tulostaMerkinta();
}

int main() {
    KalenteriMerkinta merkinta(Paivays(2, 2, 2023), "Testi2", false);
    arvoParametri(merkinta);
    merkinta.tulostaMerkinta();
    viiteParametri(merkinta);
    merkinta.tulostaMerkinta();

    return 0;
}
