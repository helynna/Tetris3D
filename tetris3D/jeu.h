#ifndef JEU_H
#define JEU_H

#include "piece.h"
#include "grille.h"
#include "piecebaton.h"
#include "piecebiais.h"
#include "piecebiais_inverse.h"
#include "piececarre.h"
#include "piecel_inverse.h"
#include "piecelambda.h"
#include "piecet_bloc.h"

class Jeu
{  
private:
    unsigned int points;
    Piece *tetrimino;
    Grille* board_;
    int Couleur_[8][3]={};
    bool newTetrimino=true;

public:
    Jeu();

    //void ajouterPiece();
    //void fixerPiece();

    //Concernant le tetrimino
     void getActualShapeTetrimino(std::vector<std::vector<int>> shape) { tetrimino->getActualShape(shape);}
     void getPosTetrimino(int Pos[2]);
     int getTypeShapeTetrimino(){return tetrimino->getTypeCouleur();}

     void tournerPieceGauche();
     void tournerPieceDroite();
     void allerAGauche();
     void allerADroite();
     void descenteRapide();
     bool peutDescendre(std::vector<std::vector<int>> shape,int pos[2]);

    //Concernant la grille
     void getCouleur(int couleur[3], int shape);
     int getIndiceInGrille(int x, int y);
     int doSumLine(int x);


    //Concernant le jeu en général
     void creationPieceAleatoire();//On va modifier la piece tetriminos que l'on stock vu qu'une nouvelle piece se fait seuelemnt quand l'autre est posée
     void testerGameOver();//On teste si la grille est complète ou si ce n'est pas le cas
     void compterPoints();
     void placerTetrimino();//on fait en sorte que la piece soit fixée dans le tableau de la grille

};

#endif // JEU_H
