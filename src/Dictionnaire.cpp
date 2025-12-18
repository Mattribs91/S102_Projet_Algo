//
// Created by Matt on 18/12/2025.
//

#include "Dictionnaire.h"
#include <fstream>

Dictionnaire::Dictionnaire(const string &nom) {
    ifstream fichier(nom);

    int nb_tuiles;
    string nomTuile, propriete;
    int x, y;

    fichier >> nb_tuiles;

    for (int i = 0; i < nb_tuiles; i++) {
        fichier >> nomTuile >> x >> y >> propriete;
        tuile.push_back(Tuile(nomTuile, x, y, propriete));
    }
}

Dictionnaire::Dictionnaire() {
    tuile = {};
}

void Dictionnaire::afficher() const {
    for (int i = 0; i < tuile.size(); i++) {
        tuile[i].afficher();
    }
}

bool Dictionnaire::recherche(const string &nomTuile, Tuile &resulat) const {
    int debut = 0;
    int milieu;
    int fin = tuile.size() - 1;

    while (debut <= fin) {
        milieu = (debut + fin) / 2;
        if (tuile[milieu].getNom() == nomTuile) {
            resulat = tuile[milieu];
            return true;
        } else if (nomTuile < tuile[milieu].getNom()) {
            fin = milieu - 1;
        } else {
            debut = milieu + 1;
        }
    }
    return false;
}
