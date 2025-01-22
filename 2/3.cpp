/*
3. Toteuta seuraavat 3 min()-funktiota, jotka kaikki palauttavat annettujen
kokonaislukuparametrien pienimmän arvon. 3- ja 4-parametrisissa versioissa on
hyödynnettävä 2-parametrista versiota, eli näistä min()-funktioista on
kutsuttava edellä tehtyjä min()-funktioita (= aliohjelmien uudelleenkäyttöä).
Tee lisäksi pääohjelma, jossa kutsutaan tehtyjä aliohjelmia niiden toimivuuden
varmistamiseksi.    int min(int x, int y);  int min(int x, int y, int z); 
int min(int x, int y, int z, int w); 

*/

#include <iostream>

int min(int x, int y) { return x < y ? x : y; }

int min(int x, int y, int z) { return min(min(x, y), z); }

int min(int x, int y, int z, int w) { return min(min(x, y, z), w); }

int main() {
    std::cout << min(1, 2) << std::endl;
    std::cout << min(1, 2, 3) << std::endl;
    std::cout << min(1, 2, 3, 4) << std::endl;

    return 0;
}
