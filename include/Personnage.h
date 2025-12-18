//
// Created by Matthéo Ribeiro on 12/3/25.
//

#ifndef PROJET_ALGO_PERSONNAGE_H
#define PROJET_ALGO_PERSONNAGE_H
#include "Image.h"
#include "Niveau.h"

using namespace std;

enum Direction { HAUT, BAS, DROITE, GAUCHE };
enum Skin { NU, BAMBI, BAMBINETTE, SKELETTE, BLOB, BATMAN, GHOST, LARAIGNEE};

class Personnage {
private:
  int _position_x;
  int _position_y;
  Image _image;
  Direction _direction;
  Skin _skin;
  int _skin_x;
  int _skin_y;

public:
  Personnage();
  Personnage(int position_x, int position_y, const Image &image, Direction direction, Skin skin);

  void dessiner() const;
  void regarderHaut();
  void regarderBas();
  void regarderDroite();
  void regarderGauche();
  void deplacer(int dx, int dy);
  bool peutBougerVers(Direction direction, const Niveau &niveau) const;
  Direction getDirection() const;
  //void inverserDirection(); plus besoin car mouvements randoms

  int getPositionX() const;
  int getPositionY() const;

  // pour changer la direction en random
  void setDirection(Direction direction);
};

class Ennemi {
private:
  Personnage _perso;

public:
  Ennemi(int position_x, int position_y, const Image &image, Direction direction, Skin skin);

  void dessiner() const;
  void avancer(const Niveau &niveau);

  int getPositionX() const;
  int getPositionY() const;
};

class Avatar {
private:
  Personnage _perso;

public:
  Avatar(int position_x, int position_y, const Image &image, Direction direction, Skin skin);

  void dessiner() const;
  void allerDroite(Niveau &niveau);
  void allerGauche(Niveau &niveau);
  void allerHaut(Niveau &niveau);
  void allerBas(Niveau &niveau);
  bool touche(const Ennemi &ennemi) const;
};

#endif // PROJET_ALGO_PERSONNAGE_H
