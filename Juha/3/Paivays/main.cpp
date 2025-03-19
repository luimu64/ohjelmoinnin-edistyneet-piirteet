#include "KalenteriMerkinta.h"

int main() {
    KalenteriMerkinta merkinta;
    merkinta.tulostaMerkinta();

    KalenteriMerkinta merkinta2(Paivays(2, 2, 2023), "Testi2", false);
    merkinta2.tulostaMerkinta();

    KalenteriMerkinta kysytty;
    kysytty.kysyTiedot();
    kysytty.tulostaMerkinta();
    return 0;
}
