//
// Created by Matt on 18/12/2025.
//

#ifndef PROJET_ALGO_TUILE_H
#define PROJET_ALGO_TUILE_H
#include <string>
#include <iostream>

using namespace std;

class Tuile {
private:
    string _nom;
    int _x;
    int _y;
    string _propriete;

public:
    Tuile(const string &nom, int x, int y, const string &propriete);
    Tuile();

    void afficher() const;
    string getNom() const;
    int getX() const;
    int getY() const;
    string getPropriete() const;
    void setPropriete(const string &propriete);
};

#endif //PROJET_ALGO_TUILE_H