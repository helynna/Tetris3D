#ifndef GRILLE_H
#define GRILLE_H

#include "piece.h"

#define nbColonne 10
#define nbLigne 20

class Grille
{
private :
    unsigned int grille[nbLigne][nbColonne]={};

public:
    Grille();
    bool isFull(int numLigne);//tester si une ligne est pleine
    void supprimerLigne(int numLigne);//fonction pour supprimer une ligne
    int supprimerLigneComplete();//Fonction qui teste si la ligne est complète puis la supprime
    int sommeLigne(int numLigne);//Faire une somme des valeurs sur la ligne pour savoir si elle est vide

    int getIndiceGrille(int x, int y) {return grille[y][x];}
    void addTetrimino(int x, int y, int shape);//Ajout d'un tetrimino dans la grille
    void initialiser();







};

#endif // GRILLE_H
