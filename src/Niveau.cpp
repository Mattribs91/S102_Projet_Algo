//
// Created by Matt on 18/12/2025.
//

#include "Niveau.h"
#include <fstream>

Niveau::Niveau(const Image &image, const string &nomFichier, const Dictionnaire &dictionnaire) {
    _bonus = 0;

    ifstream fichier(nomFichier);
    int nbObjets, position_x, position_y;
    string nomObjet;

    fichier >> nbObjets;
    cout << nbObjets << endl;

    for (int i = 0; i < nbObjets; i++) {
        fichier >> nomObjet >> position_x >> position_y;
        cout << nomObjet << " " << position_x << " " << position_y << " " << endl;

        Objet objet(image, nomObjet, dictionnaire, position_x, position_y);
        if (objet.estBonus()) {
            _bonus++;
            cout << "nombre de bonus: " << _bonus << endl;
        }
        niveau.push_back(objet);
    }
}

void Niveau::dessiner() const {
    for (int i = 0; i < niveau.size(); i++) {
        if (!niveau[i].estCache()) {
            niveau[i].dessiner();
        }
    }
}

bool Niveau::caseEstLibre(const int x, const int y) const {
    for (int i = 0; i < niveau.size(); i++) {
        if (niveau[i].estSolide()) {
            if (niveau[i].getX() == x && niveau[i].getY() == y) {
                return false;
            }
        }
    }
    return true;
}

bool Niveau::testerBonusEtPrendre(const int x, const int y) {
    for (int i = 0; i < niveau.size(); i++) {
        if (niveau[i].estBonus()) {
            if (niveau[i].getX() == x && niveau[i].getY() == y) {
                _bonus--;
                niveau[i].cacher();
                return true;
            }
        }
    }
    return false;
}

bool Niveau::gagne() const {
    return (_bonus == 0);
}
