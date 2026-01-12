Projet Jeu Vidéo - S102

Groupe : 1E - Matthéo Ribeiro, Khadija Boufeneche

Lien du repo GitHub : https://github.com/Mattribs91/S102_Projet_Algo

--------------------------------------------------------------------------------

Voici notre rapport pour le projet Création Jeu Vidéo (S102) en C++.

--- FONCTIONNALITES IMPLEMENTEES ---

Toutes les fonctionnalités principales demandées dans le sujet sont fonctionnelles.
On peut déplacer notre personnage, les niveaux se chargent bien depuis les fichiers texte, et les collisions avec les murs, les objets et les ennemis fonctionnent.

Nous avons aussi fait plusieurs questions optionnelles.

--- Fonctionnalités optionnelles : ---

*   Les bonus : On doit ramasser toutes les pièces pour gagner la partie.
*   Fin du jeu : Le jeu s'arrête si on récupère toutes les pièces ou si on perd en rentrant en contact avec un ennemi.
*   Écran de fin : Nous avons bien implémenté l'affichage des images 'Bravo' et 'Game Over' en fonction de l'issue de la partie.
*   Ennemis aléatoires : Les ennemis ne font pas juste des aller-retours, ils se déplacent aléatoirement avec des patterns tous différents.

--- DETAILS TECHNIQUES DU JEU ---

1. Structure du code
Pour rendre le code plus lisible et plus facile à utiliser, nous avons ajouté des enums (Énumération) dans le fichier Personnage.h :
*   enum Direction { HAUT, BAS, DROITE, GAUCHE } : pour gérer les différents sens possibles du personnage pour simplifier les mouvements.
*   enum Skin { NU, BAMBI, BAMBINETTE, SKELETTE... } : permet de sélectionner un skin de personnage plus facilement que de devoir utiliser les coordonnées du sprite.

2. Algorithme de recherche
Comme le dictionnaire est trié par ordre alphabétique, nous avons utilisé la recherche dichotomique. C'était la méthode la plus efficace pour trouver les informations d'une tuile à partir de son nom.

3. Mouvements aléatoires
Pour que les ennemis n'utilisent pas toujours le même pattern à chaque lancement du jeu pour leurs mouvements, on utilise la fonction rand(). Nous l'avons initialisée avec srand(time(nullptr)) au début du programme pour utiliser l'heure comme pattern, qui change tout le temps donc tous les mouvements seront différents à chaque lancement du jeu.

4. Gestion de la vitesse du jeu
Nous avons modifié le nombre de FPS par défaut dans le fichier Moteur.h. Nous avons décidé de changer cette valeur, pour que les mouvements des ennemis soient plus lent et que le joueur perde moins rapidement.
