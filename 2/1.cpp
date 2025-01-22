#include <iostream>

enum KolmioTyyppi {
    epasaannollinen,
    tasakylkinen,
    tasasivuinen,
    suorakulmainen
};

bool onKolmiollinen(double a, double b, double c, KolmioTyyppi& tyyppi) {
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            tyyppi = tasasivuinen;
        } else if (a == b || a == c || b == c) {
            tyyppi = tasakylkinen;
        } else {
            tyyppi = epasaannollinen;
        }

        if (a * a + b * b == c * c || a * a + c * c == b * b ||
            b * b + c * c == a * a) {
            tyyppi = suorakulmainen;
        }

        return true;
    }

    return false;
}

int main() {
    double a, b, c;
    KolmioTyyppi tyyppi;

    std::cout << "Anna kolmion sivujen pituudet: ";
    std::cin >> a >> b >> c;

    if (onKolmiollinen(a, b, c, tyyppi)) {
        std::string tyyppiNimi;
        switch (tyyppi) {
        case epasaannollinen:
            tyyppiNimi = "epäsäännöllinen";
            break;
        case tasakylkinen:
            tyyppiNimi = "tasakylkinen";
            break;
        case tasasivuinen:
            tyyppiNimi = "tasasivuinen";
            break;
        case suorakulmainen:
            tyyppiNimi = "suorakulmainen";
            break;
        }
        std::cout << "Annetuista sivuista voidaan muodostaa " << tyyppiNimi
                  << " kolmio." << std::endl;
    } else {
        std::cout << "Kolmiota ei voi muodostaa." << std::endl;
    }

    return 0;
}
