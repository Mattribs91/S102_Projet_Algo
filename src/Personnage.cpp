//
// Created by Matthéo Ribeiro on 12/3/25.
//

#include "Personnage.h"
#include <fstream>

using namespace std;

// constructeur vide de personnage
Personnage::Personnage() {
  _position_x = 0;
  _position_y = 0;
  _image = Image();
  _direction = BAS;
  _skin = BAMBI;
  _skin_x = 0;
  _skin_y = 0;
}

// constructeur de personnage
Personnage::Personnage(const int position_x, const int position_y, const Image &image, const Direction direction, Skin skin) {
  _position_x = position_x * TAILLE_CASE;
  _position_y = position_y * TAILLE_CASE;
  _image = image;
  _direction = direction;
  _skin = skin;

  int skin_x = 0;
  int skin_y = 0;
  switch (_skin) {
    case NU:
      skin_x = 0;
      skin_y = 0;
      break;
    case BAMBI:
      skin_x = 1;
      skin_y = 0;
      break;
    case BAMBINETTE:
      skin_x = 2;
      skin_y = 0;
      break;
    case SKELETTE:
      skin_x = 3;
      skin_y = 0;
      break;
    case BLOB:
      skin_x = 0;
      skin_y = 1;
      break;
    case BATMAN:
      skin_x = 1;
      skin_y = 1;
      break;
    case GHOST:
      skin_x = 2;
      skin_y = 1;
      break;
    case LARAIGNEE:
      skin_x = 3;
      skin_y = 1;
      break;
    default:
      skin_x = 0;
      skin_y = 0;
      break;
  }

  _skin_x = (skin_x * 3) + 1;
  _skin_y = skin_y * 4;
}

//constructeur d'avatar
Avatar::Avatar(const int position_x, const int position_y, const Image &image, const Direction direction, Skin skin) {
  _perso = Personnage(position_x, position_y, image, direction, skin);
}

//constructeur d'ennemi
Ennemi::Ennemi(const int position_x, const int position_y, const Image &image, const Direction direction, Skin skin) {
  _perso = Personnage(position_x, position_y, image, direction, skin);
}

//methode pour dessiner les ennemis en utilisant la methode de personnage
void Ennemi::dessiner() const {
  _perso.dessiner();
}

//methode pour dessiner les avatars en utilisant la methode de personnage
void Avatar::dessiner() const {
  _perso.dessiner();
}

//Methode pour dessiner le personnage en fonction de sa direction
void Personnage::dessiner() const {
  switch (_direction) {
  case HAUT:
    _image.dessiner(_position_x, _position_y, _skin_x * TAILLE_CASE,(_skin_y + 3) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    break;
  case DROITE:
    _image.dessiner(_position_x, _position_y, _skin_x * TAILLE_CASE,(_skin_y + 2) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    break;
  case BAS:
    _image.dessiner(_position_x, _position_y, _skin_x * TAILLE_CASE,_skin_y * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    break;
  case GAUCHE:
    _image.dessiner(_position_x, _position_y, _skin_x * TAILLE_CASE,(_skin_y + 1) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    break;
  }
}

// methode pour deplacer le personnage
void Personnage::deplacer(const int dx, const int dy) {
  _position_x += dx;
  _position_y += dy;
}

// Méthode pour vérifier si le perso peut bouger dans la direction actuelle
bool Personnage::peutBougerVers(const Direction direction, const Niveau &niveau) const {
  if (direction == DROITE && _position_x < LARGEUR_FENETRE - TAILLE_CASE && niveau.caseEstLibre(_position_x + TAILLE_CASE, _position_y)) {
    return true;
  }

  if (direction == GAUCHE && _position_x > 0 && niveau.caseEstLibre(_position_x - TAILLE_CASE, _position_y)) {
    return true;
  }

  if (direction == BAS && _position_y < HAUTEUR_FENETRE - TAILLE_CASE && niveau.caseEstLibre(_position_x, _position_y + TAILLE_CASE)) {
    return true;
  }

  if (direction == HAUT && _position_y > 0 && niveau.caseEstLibre(_position_x, _position_y - TAILLE_CASE)) {
    return true;
  }

  return false;
}

void Personnage::setDirection(Direction direction) {
  _direction = direction;
}

//méthode pour faire avancer les ennemis s'ils peuvent aller dans la direction actuelle sinon on inverse
void Ennemi::avancer(const Niveau &niveau) {
  _perso.setDirection((Direction)(rand() % 4)); // change la direction random

  if (_perso.peutBougerVers(_perso.getDirection(), niveau)) {
    switch (_perso.getDirection()) {
      case DROITE:
        _perso.deplacer(TAILLE_CASE, 0);
        break;
      case GAUCHE:
        _perso.deplacer(-TAILLE_CASE, 0);
        break;
      case HAUT:
        _perso.deplacer(0, -TAILLE_CASE);
        break;
      case BAS:
        _perso.deplacer(0, TAILLE_CASE);
      default:
        break;
    }
  }
}

//méthode pour inverser la direction du perso s'il ne peut pas avancer
/*void Personnage::inverserDirection() {
  switch (_direction) {
    case HAUT:
      _direction = BAS;
      break;
    case BAS:
      _direction = HAUT;
      break;
    case DROITE:
      _direction = GAUCHE;
      break;
    case GAUCHE:
      _direction = DROITE;
      break;
    default:
      break;
  }
} PLUS BESOIN CAR MOUVEMENTS RANDOMS */

// getter pour la direction du perso
Direction Personnage::getDirection() const {
  return _direction;
}

// ------------------------------------------------- //
// getters pour les positions x et y du perso
int Personnage::getPositionX() const {
  return _position_x;
}

int Personnage::getPositionY() const {
  return _position_y;
}

// getters pour les positions x et y des ennemis
int Ennemi::getPositionX() const {
  return _perso.getPositionX();
}

int Ennemi::getPositionY() const {
  return _perso.getPositionY();
}
// ------------------------------------------------- //

// ------------------------------------------------- //
// Méthode pour se mettre dans la bonne direction et avancer si c possible
void Avatar::allerGauche(Niveau &niveau) {
  _perso.regarderGauche();
  if (_perso.peutBougerVers(GAUCHE, niveau)) {
    _perso.deplacer(-TAILLE_CASE, 0);
    niveau.testerBonusEtPrendre(_perso.getPositionX(), _perso.getPositionY());
  }
}

void Avatar::allerDroite(Niveau &niveau) {
  _perso.regarderDroite();
  if (_perso.peutBougerVers(DROITE, niveau)) {
    _perso.deplacer(TAILLE_CASE, 0);
    niveau.testerBonusEtPrendre(_perso.getPositionX(), _perso.getPositionY());
  }
}

void Avatar::allerHaut(Niveau &niveau) {
  _perso.regarderHaut();
  if (_perso.peutBougerVers(HAUT, niveau)) {
    _perso.deplacer(0, -TAILLE_CASE);
    niveau.testerBonusEtPrendre(_perso.getPositionX(), _perso.getPositionY());
  }
}

void Avatar::allerBas(Niveau &niveau) {
  _perso.regarderBas();
  if (_perso.peutBougerVers(BAS, niveau)) {
    _perso.deplacer(0, TAILLE_CASE);
    niveau.testerBonusEtPrendre(_perso.getPositionX(), _perso.getPositionY());
  }
}
// ------------------------------------------------- //

// ------------------------------------------------- //
// Méthode pour changer la direction du perso
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
// ------------------------------------------------- //

//méthode pour vérifier si un ennemi est en contact avec un avatar
bool Avatar::touche(const Ennemi &ennemi) const {
  if ((_perso.getPositionX() == ennemi.getPositionX()) && (_perso.getPositionY() == ennemi.getPositionY())) {
    return true;
  }
  return false;
}