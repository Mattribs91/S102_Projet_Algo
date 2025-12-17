//
// Created by Matthéo Ribeiro on 12/3/25.
//

#ifndef PROJET_ALGO_PERSONNAGE_H
#define PROJET_ALGO_PERSONNAGE_H
#include "Image.h"

enum Direction {HAUT, BAS, DROITE, GAUCHE};

class Personnage {
private:
    int _position_x;
    int _position_y;
    Image _image;
    int _direction;
    int _skin_x;
    int _skin_y;

public:
    Personnage();
    Personnage(int position_X, int position_y, Image image, int direction, int skin_x, int skin_y);

    void dessiner() const;
    void regarderHaut();
    void regarderBas();
    void regarderDroite();
    void regarderGauche();
};

#endif //PROJET_ALGO_PERSONNAGE_H