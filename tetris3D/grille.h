#ifndef GRILLE_H
#define GRILLE_H

#include "piece.h"

#define nbColonne 10
#define nbLigne 20

class Grille
{
private :
    //const unsigned int nbColonne=10;
    //const unsigned int nbLigne=20;
    unsigned int grille[nbLigne][nbColonne]={7};
    //int Couleur_[8][3]={};
    //unsigned int indiceActuel=1;
    //unsigned int grille[20][10]={};
public:
    Grille();
    bool isFull(int numLigne);
    void supprimerLigne(int numLigne);
    void supprimerLigneComplete();
    int sommeLigne(int numLigne);

    bool testDescente(Bloc type,int x, int y, int rotation);//{0,90,180,270};
    bool testGrille(int x, int y);
    //void getCouleur(int couleur[3], int shape);
    int getIndiceGrille(int x, int y) {return grille[x][y];}







};

#endif // GRILLE_H
