#include "Osoite.h"
#include <iostream>

using namespace std;

string Osoite::getKatuosoite() const { return katuosoite; }

string Osoite::getPostinumero() const { return postinumero; }

string Osoite::getKunta() const { return kunta; }

void Osoite::setKatuosoite(string katuosoite) { this->katuosoite = katuosoite; }

void Osoite::setPostinumero(string postinumero) {
    this->postinumero = postinumero;
}

void Osoite::setKunta(string kunta) { this->kunta = kunta; }

void Osoite::tulostaOsoite() const {
    cout << "Katuosoite: " << katuosoite << endl;
    cout << "Postinumero: " << postinumero << endl;
    cout << "Kunta: " << kunta << endl;
}

Osoite::Osoite(string katuosoite, string postinumero, string kunta) {
    this->katuosoite = katuosoite;
    this->postinumero = postinumero;
    this->kunta = kunta;
}

Osoite::Osoite()
    : katuosoite("Tuntematon"), postinumero("00000"), kunta("Tuntematon") {
    cout << "Osoite-luokan parametriton rakentaja" << endl;
}

void Osoite::kysyOsoite() {
    cin.ignore(10, '\n');
    cout << "\nAnna katuosoite: ";
    getline(cin, katuosoite);
    cout << "\nAnna postinumero: ";
    getline(cin, postinumero);
    cout << "\nAnna kunta: ";
    getline(cin, kunta);
}
