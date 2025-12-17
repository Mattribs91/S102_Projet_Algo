//
// Created by Matthéo Ribeiro on 12/3/25.
//

#include "Personnage.h"

using namespace std;

Personnage::Personnage() {
  _position_x = 0;
  _position_y = 0;
  _image = Image();
  _direction = BAS;
}

Personnage::Personnage(int x, int y, Image image, Direction direction,
                       int skin_x, int skin_y) {
  _position_x = x * TAILLE_CASE;
  _position_y = y * TAILLE_CASE;
  _image = image;
  _direction = direction;
  _skin_x = (skin_x * 3) + 1;
  _skin_y = skin_y * 4;
}

Avatar::Avatar(int x, int y, Image image, Direction direction, int skin_x,
               int skin_y) {
  _perso = Personnage(x, y, image, direction, skin_x, skin_y);
}

Ennemi::Ennemi(int x, int y, Image image, Direction direction, int skin_x,
               int skin_y) {
  _perso = Personnage(x, y, image, direction, skin_x, skin_y);
}

void Ennemi::dessiner() const { _perso.dessiner(); }

void Avatar::dessiner() const { _perso.dessiner(); }

void Personnage::dessiner() const {
  switch (_direction) {
  case HAUT:
    _image.dessiner(_position_x, _position_y, _skin_x * TAILLE_CASE,
                    (_skin_y + 3) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    break;
  case DROITE:
    _image.dessiner(_position_x, _position_y, _skin_x * TAILLE_CASE,
                    (_skin_y + 2) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    break;
  case BAS:
    _image.dessiner(_position_x, _position_y, _skin_x * TAILLE_CASE,
                    _skin_y * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    break;
  case GAUCHE:
    _image.dessiner(_position_x, _position_y, _skin_x * TAILLE_CASE,
                    (_skin_y + 1) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
    break;
  }
}

void Personnage::deplacer(int dx, int dy) {
  _position_x += dx;
  _position_y += dy;
}

void Avatar::allerDroite() {
  _perso.regarderDroite();
  if (_perso.peutBougerVers(DROITE)) {
    _perso.deplacer(TAILLE_CASE, 0);
  }
}

bool Personnage::peutBougerVers(Direction direction) const {
  if (direction == DROITE && _position_x < LARGEUR_FENETRE - TAILLE_CASE) {
    return true;
  }

  if (direction == GAUCHE && _position_x > 0) {
    return true;
  }

  if (direction == BAS && _position_y < HAUTEUR_FENETRE - TAILLE_CASE) {
    return true;
  }

  if (direction == HAUT && _position_y > 0) {
    return true;
  }

  return false;
}

void Ennemi::avancer() {
  if (_perso.peutBougerVers(_perso.getDirection())) {
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
  } else {
    _perso.inverserDirection();
  }
}

void Personnage::inverserDirection() {
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
}

Direction Personnage::getDirection() const {
  return _direction;
}

void Avatar::allerGauche() {
  _perso.regarderGauche();
  if (_perso.peutBougerVers(GAUCHE)) {
    _perso.deplacer(-TAILLE_CASE, 0);
  }
}

void Avatar::allerHaut() {
  _perso.regarderHaut();
  if (_perso.peutBougerVers(HAUT)) {
    _perso.deplacer(0, -TAILLE_CASE);
  }
}

void Avatar::allerBas() {
  _perso.regarderBas();
  if (_perso.peutBougerVers(BAS)) {
    _perso.deplacer(0, TAILLE_CASE);
  }
}

void Personnage::regarderHaut() { _direction = HAUT; }

void Personnage::regarderBas() { _direction = BAS; }

void Personnage::regarderDroite() { _direction = DROITE; }

void Personnage::regarderGauche() { _direction = GAUCHE; }
