#include <vector>

#include "Image.h"
#include "Moteur.h"
#include "Personnage.h"

using namespace std;

int main(int, char **) // Version speciale du main, ne pas modifier
{
  // Initialisation du jeu
  Moteur moteur("Jeu vidéo relou à faire");

  // TODO: charger images, creer personnages, etc.

  bool quitter = false;
  /*bool ouvert = false;
  double position_y = 0;*/

  // ---CREATION DES IMAGES----

  // Image coffre_ferme;
  // Image coffre_ouvert;
  Image personnage_simple, fond;

  try {
    // coffre_ferme = Image(moteur,"assets/coffre_ferme.png");
    // coffre_ouvert = Image(moteur,"assets/coffre_ouvert.png");
    fond = Image(moteur, "assets/fond.png");
    personnage_simple = Image(moteur, "assets/personnages.png");
  } catch (runtime_error) {
    cerr << "Impossible de charger l'image" << endl;
  }

  Avatar personnage(0, 0, personnage_simple, BAS, 0,
                    0); // Creation de l'objet personnage
  Ennemi ennemi1(5, 0, personnage_simple, BAS, 2, 1);
  Ennemi ennemi2(0, 5, personnage_simple, DROITE, 3, 0);

  // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
  // (en general, 60 fois par seconde)
  while (!quitter) {
    // I. Gestion des evenements
    Evenement evenement = moteur.evenementRecu();
    while (evenement != AUCUN) {
      switch (evenement) {
      // QUITTER = croix de la fenetre ou Echap
      case QUITTER_APPUYE:
        quitter = true;
        break;
      // TODO: gerer les autres evenements
      /*case ESPACE_APPUYE:
        ouvert = true;
        break;
      case ESPACE_RELACHE:
        ouvert = false;
        break;*/
      case HAUT_APPUYE:
        personnage.allerHaut();
        break;
      case DROITE_APPUYE:
        personnage.allerDroite();
        break;
      case BAS_APPUYE:
        personnage.allerBas();
        break;
      case GAUCHE_APPUYE:
        personnage.allerGauche();
        break;
      default:
        break;
      }

      evenement = moteur.evenementRecu();
    }
    // II. Mise à jour de l'état du jeu

    // TODO: faire bouger vos personnages, etc.

    // III. Generation de l'image à afficher
    moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment
                               // et reinitalise en ecran noir

    fond.dessiner(0, 0);   // Affiche l'image de fond
    personnage.dessiner(); // On dessine l'objet personnage
    ennemi1.avancer();
    ennemi2.avancer();
    ennemi1.dessiner();
    ennemi2.dessiner();

    /*if (ouvert) {
      coffre_ouvert.dessiner(0,position_y + 0.2); //Coffre ouvert si espace
    appuye } else { coffre_ferme.dessiner(0,position_y + 0.2); //Coffre ferme si
    espace relache
    }*/

    // TODO: afficher vos personnages, objets, etc.

    /*
      Affiche l'image en se cadencant sur la frequence de
      rafraichissement de l'ecran (donc va en general mettre le
      programme en pause jusqu'a ce que l'ecran soit rafraichi). En
      general, 60 images fois par seconde, mais ca peut dependre du
      materiel
    */
    moteur.finaliserRendu();
  }

  return 0;
}
