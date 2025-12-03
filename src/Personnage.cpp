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

Personnage::Personnage(int x, int y, Image image, int direction) {
    _position_x = x;
    _position_y = y;
    _image =  image;
    _direction = direction;
}

void Personnage::dessiner() const {
    switch (_direction) {
        case 1: _image.dessiner(0, 0, 4 * TAILLE_CASE, 3 * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
        case 2: _image.dessiner(0, 0, 4 * TAILLE_CASE, 2 * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
        case 3: _image.dessiner(0, 0, 4 * TAILLE_CASE, 0 * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
        case 4: _image.dessiner(0, 0, 4 * TAILLE_CASE, 1 * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
    }
}

void Personnage::regarderHaut() {
    _direction = 1;
}

void Personnage::regarderBas() {
    _direction = 3;
}

void Personnage::regarderDroite() {
    _direction = 2;
}

void Personnage::regarderGauche() {
    _direction = 4;
}