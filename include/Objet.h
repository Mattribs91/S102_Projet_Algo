//
// Created by Matt on 18/12/2025.
//

#ifndef PROJET_ALGO_OBJET_H
#define PROJET_ALGO_OBJET_H

#include "Dictionnaire.h"
#include "Image.h"
#include "Tuile.h"

class Objet {
private:
    Image _image;
    int _position_x;
    int _position_y;
    Tuile _tuile;

public:
    Objet(const Image &image, const string &nomTuile, const Dictionnaire &dictionnaire, int position_x, int position_y);

    void dessiner() const;
    bool estSolide() const;
    bool estBonus() const;
    int getX() const;
    int getY() const;
    void cacher();
    bool estCache() const;
};

#endif //PROJET_ALGO_OBJET_H