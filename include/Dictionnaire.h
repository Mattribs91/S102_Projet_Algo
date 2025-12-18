//
// Created by Matt on 18/12/2025.
//

#ifndef PROJET_ALGO_DICTIONNAIRE$_H
#define PROJET_ALGO_DICTIONNAIRE$_H

#include <vector>

#include "Tuile.h"

using namespace std;

class Dictionnaire {
private:
    vector<Tuile> tuile;

public:
    Dictionnaire(const string &nom);
    Dictionnaire();

    void afficher() const;

    //algorithme de recherche par dichotomie
    bool recherche(const string &nomTuile, Tuile& resulat) const;
};

#endif //PROJET_ALGO_DICTIONNAIRE$_H