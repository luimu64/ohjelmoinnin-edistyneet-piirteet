/*
Tee pääohjelma, josta löytyy seuraavat asiat / käsittelyt (tehtävä saattaa
vaikuttaa pitkältä mutta ratkaisu ei sitä ole koska jokaista kysyttyä asiaa
kohden tehdään suurinpiirtein yksi ohjelmalause! Pääasiana on treenata C++
-tietueiden käyttöä):
-
-
-
Ohjelman alussa luot tietuetyypin aika_ty, joka sisältää kentät ajankohdan
tunneille, minuuteille ja sekunneille.
Tee pääohjelman alussa aikatietuetyyppiä oleva muuttuja.
Lue sisältö aikamuuttujaasi päätteeltä. Syöte ohjelmalle voidaan antaa vaikkapa
seuraavasti:
Anna tunnit: 12
Anna minuutit: 33
Anna sekunnit: 44
, missä käyttäjän syötteet on merkitty harmaalla taustavärillä.
-
Jos luetussa syötteessä oli virhe (tunnit ei välillä 0 – 23 jne.) , tästä
annetaan virheilmoitus näytölle.-
-
-
Mikäli ajankohdan tunnit, minuutit ja sekunnit olivat kunnossa, ohjelma tulostaa
syötetyn ajankohdan päätteelle muodossa hh:mm:ss (hh = tunnit, mm = minuutit, ss
= sekunnit)
Tee vielä osoitinmuuttuja, joka osoittaa aiemmin tekemääsi aikatietuemuuttujaan.
Tulosta aikatietumuuttujan sisältö uudestaan näytölle käyttäen vain tätä
osoitinmuuttujaa.
Tee ohjelmaasi kaksi uutta aikatietuemuuttujaa joista toiseen asetat arvoksi
jonkin järkevän ajankohdan. Kopioi sitten tämän muuttujan arvo siihen toiseen
tässä vaiheessa luomaasi aikatietumuuttujaan. Tee tämän jälkeen vertailulause
jossa vertaat näiden kahden muuttujan sisältöä keskenään ja jos ne ovat samat
(pitäisi olla) tulosta näytölle ilmoitus: ”Sisällöt ovat samat.”
*/

#include <cmath>
#include <iostream>

using namespace std;

struct aika_ty {
    int h;
    int m;
    int s;
};

int main() {
    aika_ty aika;
    aika_ty* p_aika = &aika;

    cout << "Anna tunnit: ";
    cin >> aika.h;
    if (aika.h < 0 || aika.h > 23) {
        cout << "Virheellinen tuntimäärä.";
        return 1;
    }

    cout << "Anna minuutit: ";
    cin >> aika.m;
    if (aika.m < 0 || aika.m > 59) {
        cout << "Virheellinen minuuttimäärä.";
        return 1;
    }

    cout << "Anna sekunnit: ";
    cin >> aika.s;
    if (aika.s < 0 || aika.s > 59) {
        cout << "Virheellinen sekuntimäärä.";
        return 1;
    }

    cout << aika.h << ":" << aika.m << ":" << aika.s << endl;
    cout << p_aika->h << ":" << p_aika->m << ":" << p_aika->s << endl;

    aika_ty aika_1 = (aika_ty){.h = 2, .m = 46, .s = 40};
    aika_ty aika_2 = aika_1;

    if (aika_1.h == aika_2.h && aika_1.m == aika_2.m && aika_1.s == aika_2.s) {
        cout << "Sisällöt ovat samat.";
    }

    return 0;
}
