//
// Created by Matt on 18/12/2025.
//

#ifndef PROJET_ALGO_NIVEAU_H
#define PROJET_ALGO_NIVEAU_H

#include "Objet.h"

class Niveau {
private:
    vector<Objet> niveau;
    int _bonus;

public:
    Niveau(const Image &image, const string &nomFichier, const Dictionnaire &dictionnaire);

    void dessiner() const;
    bool caseEstLibre(int x, int y) const;

    bool testerBonusEtPrendre(int x, int y);

    bool gagne() const;
};

#endif //PROJET_ALGO_NIVEAU_H