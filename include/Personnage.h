//
// Created by Matthéo Ribeiro on 12/3/25.
//

#ifndef PROJET_ALGO_PERSONNAGE_H
#define PROJET_ALGO_PERSONNAGE_H
#include "Image.h"
#include <vector>
#include <string>

using namespace std;

enum Direction { HAUT, BAS, DROITE, GAUCHE };

class Personnage {
private:
  int _position_x;
  int _position_y;
  Image _image;
  Direction _direction;
  int _skin_x;
  int _skin_y;

public:
  Personnage();
  Personnage(int position_X, int position_y, Image image, Direction direction,
             int skin_x, int skin_y);

  void dessiner() const;
  void regarderHaut();
  void regarderBas();
  void regarderDroite();
  void regarderGauche();
  void deplacer(int dx, int dy);
  bool peutBougerVers(Direction direction) const;
  Direction getDirection() const;
  void inverserDirection();

  int getPositionX() const;
  int getPositionY() const;
};

class Ennemi {
private:
  Personnage _perso;

public:
  Ennemi(int position_X, int position_y, Image image, Direction direction,
         int skin_x, int skin_y);

  void dessiner() const;
  void avancer();

  int getPositionX() const;
  int getPositionY() const;
};

class Avatar {
private:
  Personnage _perso;

public:
  Avatar(int position_X, int position_y, Image image, Direction direction,
         int skin_x, int skin_y);

  void dessiner() const;
  void allerDroite();
  void allerGauche();
  void allerHaut();
  void allerBas();
  bool touche(Ennemi ennemi) const;
};



//SEANCE 4 TUILE

class Tuile {
private:
  string _nom;
  int _x;
  int _y;
  string _propriete;

public:
  Tuile(string nom, int x, int y, string propriete);

  void afficher() const;
};

class Dictionnaire {
private:
  vector<Tuile> Tuile;

public:
  Dictionnaire(string nom);
};

#endif // PROJET_ALGO_PERSONNAGE_H
