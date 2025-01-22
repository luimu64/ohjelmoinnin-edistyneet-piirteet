/*
4. Kokonaisluvun sanotaan olevan alkuluku (engl. prime number), jos se on
jaollinen ainoastaan 1:llä ja itsellään. Esimerkiksi 2, 3, 5 ja 7 ovat
alkulukuja. Sitä vastoin luvut 4, 6, 8 ja 9 eivät ole alkulukuja.    a) Kirjoita
aliohjelma isPrime, joka päättelee, onko sille parametrina annettu luku alkuluku
ja palauttaa arvon true jos on; muutoin false:n.    b) Käytä edellä tekemääsi
aliohjelmaa hyväksi pääohjelmassa, joka päättelee sen, mitkä luvut väliltä
1-10000 ovat alkulukuja. Pääohjelma tulostaa nämä alkuluvut, niiden lukumäärän
sekä niiden prosenttiosuuden kaikista tutkituista luvuista.    c) Tutkiessasi
mielivaltaisen luvun X alkulukuominaisuutta voit käyttää seuraavia
strategioita:  (i) tutkit, onko luku X jaollinen luvuilla 2, 3, …, X - 1  (ii)
tutkit, onko luku X jaollinen luvuilla 2, 3, …, X / 2  (iii) tutkit, onko luku X
jaollinen luvuilla 2, 3, …, neliöjuuri( X )    Mikä edellisistä ratkaisuista
on tehokkain ? Miksi 2 viimeistä strategiaa ovat toimivia ? Tee a) –kohdan
aliohjelmasta versiot prime_all, prime_half sekä prime_square_root, jotka
hyödyntävät edellisiä strategioita nimiensä mukaisesti. Varmista, että niillä
kaikilla löytyvät samat alkuluvut, kun suoritat etsinnän luvuista 1, 2, …
, 10000 b) –kohdan mukaisesti (esim. tulostamalla kaikki löytyvät alkuluvut tai
laskemalla niiden määrät tai niiden prosenttiosuuden kaikista tutkituista
luvuista jne.). 
*/

#include <cmath>
#include <iostream>

bool isPrime(int x) {
    if (x < 2) {
        return false;
    }

    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

int prime_all() {
    int count = 0;
    for (int i = 1; i <= 10000; i++) {
        if (isPrime(i)) {
            count++;
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return count;
}

int prime_half() {
    int count = 0;
    for (int i = 1; i <= 10000; i++) {
        if (isPrime(i)) {
            count++;
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return count;
}

int prime_square_root() {
    int count = 0;
    for (int i = 1; i <= 10000; i++) {
        if (isPrime(i)) {
            count++;
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return count;
}

int main() {
    int count_all = prime_all();
    int count_half = prime_half();
    int count_square_root = prime_square_root();

    std::cout << "Alkulukuja yhteensä: " << count_all << std::endl;
    std::cout << "Alkulukuja yhteensä: " << count_half << std::endl;
    std::cout << "Alkulukuja yhteensä: " << count_square_root << std::endl;

    std::cout << "Alkulukujen osuus: " << count_all / 10000.0 * 100 << "%"
              << std::endl;

    return 0;
}
