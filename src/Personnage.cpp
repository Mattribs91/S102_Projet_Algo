//
// Created by Matthéo Ribeiro on 12/3/25.
//

#include "Personnage.h"

using namespace std;

Personnage::Personnage() {
    _position_x = 0;
    _position_y = 0;
    _image = Image();
    _direction = 1;
}

Personnage::Personnage(int x, int y, Image image, int direction, int skin_x, int skin_y) {
    _position_x = x;
    _position_y = y;
    _image =  image;
    _direction = direction;
    _skin_x = (skin_x * 3) + 1;
    _skin_y = skin_y * 4;
}

void Personnage::dessiner() const {
    switch (_direction) {
        case HAUT: _image.dessiner(_position_x, _position_y, _skin_x * TAILLE_CASE, (_skin_y + 3) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
        case DROITE: _image.dessiner(_position_x, _position_y, _skin_x * TAILLE_CASE, (_skin_y + 2) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
        case BAS: _image.dessiner(_position_x, _position_y, _skin_x * TAILLE_CASE, _skin_y * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
        case GAUCHE: _image.dessiner(_position_x, _position_y, _skin_x * TAILLE_CASE, (_skin_y + 1) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
    }
}

void Personnage::regarderHaut() {
    _direction = HAUT;
}

void Personnage::regarderBas() {
    _direction = BAS;
}

void Personnage::regarderDroite() {
    _direction = DROITE;
}

void Personnage::regarderGauche() {
    _direction = GAUCHE;
}