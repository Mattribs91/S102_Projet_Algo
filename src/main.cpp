#include <vector>

#include "Moteur.h"
#include "Image.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
  // Initialisation du jeu
  Moteur moteur("Mon super jeu vidéo");

  // TODO: charger images, creer personnages, etc.

  bool quitter = false;
  bool ouvert = false;
  int position_y = 0;

  // ---CREATION DES IMAGES----

  Image fond; //Creation image de fond
  try {
    fond = Image(moteur,"../assets/fond.png");
  } catch (runtime_error) {
    cerr << "Impossible de charger l'image" << endl;
  }

  Image coffre_ferme; //Image coffre ferme
  try {
    coffre_ferme = Image(moteur,"../assets/coffre_ferme.png");
  } catch (runtime_error) {
    cerr << "Impossible de charger l'image" << endl;
  }

  Image coffre_ouvert; //Image coffre ouvert
  try {
    coffre_ouvert = Image(moteur,"../assets/coffre_ouvert.png");
  } catch (runtime_error) {
    cerr << "Impossible de charger l'image" << endl;
  }

  // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
  // (en general, 60 fois par seconde)
  while (!quitter)
  {
    // I. Gestion des evenements
    Evenement evenement = moteur.evenementRecu();
    while (evenement != AUCUN)
    {
      switch (evenement)
      {
        // QUITTER = croix de la fenetre ou Echap
        case QUITTER_APPUYE:
          quitter = true;
          break;
        // TODO: gerer les autres evenements
        case ESPACE_APPUYE:
          ouvert = true;
          break;
        case ESPACE_RELACHE:
          ouvert = false;
          break;
        default:
          break;
      }

      evenement = moteur.evenementRecu();
    }
    // II. Mise à jour de l'état du jeu

    // TODO: faire bouger vos personnages, etc.

    // III. Generation de l'image à afficher
    moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

    fond.dessiner(0, 0); //Affiche l'image de fond

    if (ouvert) {
      coffre_ouvert.dessiner(0,position_y++); //Coffre ouvert si espace appuye
    } else {
      coffre_ferme.dessiner(0,position_y++); //Coffre ferme si espace relache
    }

    if (coffre_ferme > HAUTEUR_FENETRE) {
      position_y = 0;
    }

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