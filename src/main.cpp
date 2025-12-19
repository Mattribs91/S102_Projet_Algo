#include <vector>

#include "Image.h"
#include "Moteur.h"
#include "Personnage.h"
#include "Tuile.h"
#include "Dictionnaire.h"
#include "Niveau.h"

#include <cstdlib>
#include <ctime>

using namespace std;

int main(int, char **) // Version speciale du main, ne pas modifier
{
  srand(time(NULL)); // sert a changer le pattern des ennemis a chaque lancement

  // Initialisation du jeu
  Moteur moteur("Jeu vidéo relou à faire");

  // TODO: charger images, creer personnages, etc.

  bool quitter = false;
  /*bool ouvert = false;
  double position_y = 0;*/

  // ---CREATION DES OBJETS----

  // Image coffre_fermé ;
  // Image coffre_ouvert ;
  Image objets, fond, personnage_simple, gagne, perdu;
  Dictionnaire dictionnaire;

  //on essaye de charger les images
  try {
    // coffre_ferme = Image (moteur,"assets/coffre_ferme.png") ;
    // coffre_ouvert = Image (moteur,"assets/coffre_ouvert.png") ;
    objets = Image (moteur, "assets/objets.png");
    //fond = Image(moteur, "assets/fond.png");
    personnage_simple = Image(moteur, "assets/personnages.png");
    dictionnaire = Dictionnaire("assets/dictionnaire.txt"); //chargement du dictionnaire
    gagne = Image(moteur, "assets/bravo.png");
    perdu = Image(moteur, "assets/papel.png");
  } catch (const runtime_error&) {
    cerr << "Impossible de charger l'image" << endl;
  }

  dictionnaire.afficher(); //affichage du dictionnaire

  Tuile resultat;
  if (dictionnaire.recherche("Arbre_1", resultat)) {
    cout << "\ntrue" << endl;
    resultat.afficher();
  } else {
    cout << "\nfalse" << endl;
  }

  //Objet bloc(objets, "Puits", dictionnaire, 1, 0);

  Niveau niveau(objets, "assets/niveau.txt", dictionnaire);

  Avatar personnage(1, 2, personnage_simple, BAS, NU); // Creation de l'objet personnage
  Ennemi ennemi1(1 + rand() % (NB_CASE_LARGEUR - 2), 1 + rand() % (NB_CASE_HAUTEUR - 2), personnage_simple, BAS, GHOST);
  Ennemi ennemi2(1 + rand() % (NB_CASE_LARGEUR - 2), 1 + rand() % (NB_CASE_HAUTEUR - 2), personnage_simple, DROITE, LARAIGNEE);

  // Boucle de jeu, appelee à chaque fois que l'écran doit etre mis à jour
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
        personnage.allerHaut(niveau);
        break;
      case DROITE_APPUYE:
        personnage.allerDroite(niveau);
        break;
      case BAS_APPUYE:
        personnage.allerBas(niveau);
        break;
      case GAUCHE_APPUYE:
        personnage.allerGauche(niveau);
        break;
      default:
        break;
      }

      evenement = moteur.evenementRecu();
    }
    // II. Mise à jour de l'état du jeu

    if (moteur.animationsAmettreAjour()) {
      ennemi1.avancer(niveau);
      ennemi2.avancer(niveau);
    }

    if (personnage.touche(ennemi1) || personnage.touche(ennemi2)) {
      cout << "\ntrop nul t mort" << endl;
      perdu.dessiner(2 * TAILLE_CASE, 3 * TAILLE_CASE);
      moteur.attendre(3);
      quitter = true;
    }

    // III. Generation de l'image à afficher
    moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment
                               // et initialise en ecran noir

    /*if (ouvert) {
      coffre_ouvert.dessiner(0,position_y + 0.2); //Coffre ouvert si espace
    appuye } else { coffre_ferme.dessiner(0,position_y + 0.2); //Coffre ferme si
    espace relache
    }*/

    // TODO: afficher vos personnages, objets, etc.
    //fond.dessiner(0, 0);   // Affiche l'image de fond
    niveau.dessiner();
    personnage.dessiner(); // On dessine l'objet personnage
    ennemi1.dessiner();
    ennemi2.dessiner();

    //bloc.dessiner();

    if (niveau.gagne()) {
      gagne.dessiner(2 * TAILLE_CASE, 3 * TAILLE_CASE);
    }

    /*
      Affiche l'image en se cadencant sur la frequence de
      rafraichissement de l'écran (donc va en general mettre le
      programme en pause jusqu'a ce que l'écran soit rafraichi). En
      general, 60 images fois par seconde, mais ca peut dependre du
      materiel
    */
    moteur.finaliserRendu();

    if (niveau.gagne()) {
      cout << "t'as gagne bro" << endl;
      moteur.attendre(3);
      quitter = true;
    }
  }

  return 0;
}
