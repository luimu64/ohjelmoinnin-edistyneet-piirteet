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
    : katuosoite("Tuntematon"), postinumero("00000"), kunta("Tuntematon") {}

void Osoite::kysyOsoite() {
    cout << "Anna katuosoite: ";
    getline(cin, katuosoite);
    cout << "Anna postinumero: ";
    getline(cin, postinumero);
    cout << "Anna kunta: ";
    getline(cin, kunta);
}
