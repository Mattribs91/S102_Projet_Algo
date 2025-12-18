//
// Created by Matt on 18/12/2025.
//

#include "Tuile.h"

Tuile::Tuile(const string &nom, const int x, const int y, const string &propriete) {
    _nom = nom;
    _x = x;
    _y = y;
    _propriete = propriete;
}

Tuile::Tuile() {
    _nom = "Défaut";
    _x = -999;
    _y = -999;
    _propriete = "Tuile défaut";
}

void Tuile::afficher() const {
    cout << _nom << ": " << "x = " << _x << ", " << "y = " << _y << ", " << _propriete << endl;
}

string Tuile::getNom() const {
    return _nom;
}

int Tuile::getX() const {
    return _x;
}

int Tuile::getY() const {
    return _y;
}

string Tuile::getPropriete() const {
    return _propriete;
}

void Tuile::setPropriete(const string &propriete) {
    _propriete = propriete;
}
