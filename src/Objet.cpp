//
// Created by Matt on 18/12/2025.
//

#include "Objet.h"

Objet::Objet(const Image &image, const string &nomTuile, const Dictionnaire &dictionnaire, int position_x, int position_y) {
    Tuile temp;

    _image = image;
    _position_x = position_x * TAILLE_CASE;
    _position_y = position_y * TAILLE_CASE;

    if (dictionnaire.recherche(nomTuile, temp)) {
        _tuile = temp;
        cout << "\nObjet trouve" << endl;
    } else {
        cout << "\nObjet non trouve" << endl;
    }
}

void Objet::dessiner() const {
    _image.dessiner(_position_x, _position_y, _tuile.getX() * TAILLE_CASE, _tuile.getY() * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
}

bool Objet::estSolide() const {
    return (_tuile.getPropriete() == "solide");
}

bool Objet::estBonus() const {
    return (_tuile.getPropriete() == "bonus");
}

int Objet::getY() const {
    return _position_y;
}

int Objet::getX() const {
    return _position_x;
}

void Objet::cacher() {
    _tuile.setPropriete("cache");
}

bool Objet::estCache() const {
    return (_tuile.getPropriete() == "cache");
}