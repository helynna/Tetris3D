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
    unsigned int points = 0;
    Piece *tetrimino=nullptr;
    Grille* board_;
    int Couleur_[8][3]={//Les couleurs de nos pièces et l'indice correspond à la valeur dans la grille
        {255, 0, 0},
        {0, 255, 0},
        {0, 0, 255},
        {255, 255, 0},
        {255, 0, 255},
        {0, 255, 255},
        {128, 128, 128},
        {0, 0, 0}
    };
    bool newTetrimino=true;//Booleen qui nous permet de savoir si l'on peut créer une nouvelle pièce ou pas

public:
    Jeu();
    ~Jeu();

    //Concernant le tetrimino
     void getActualShapeTetrimino(std::vector<std::vector<int>>& shape) { tetrimino->getActualShape(shape);}
     void getPosTetrimino(int Pos[2]);
     int getTypeShapeTetrimino(){return tetrimino->getTypeCouleur();}

     void tournerPieceGauche();
     void tournerPieceDroite();
     void allerAGauche();
     void allerADroite();
     void descenteRapide();
     bool peutDescendre(const std::vector<std::vector<int>>& shape,int pos[2]);
     bool peutBouger(const std::vector<std::vector<int>>& shape,int pos[2], int offx, int offy);
     void faireDescendre();

    //Concernant la grille
     void getCouleur(int couleur[3], int shape);
     int getIndiceInGrille(int x, int y);
     int doSumLine(int x);


    //Concernant le jeu en général
     void creationPieceAleatoire();//On va modifier la piece tetriminos que l'on stock vu qu'une nouvelle piece se fait seuelemnt quand l'autre est posée
     bool testerGameOver();//On teste si la grille est "complète" ou si ce n'est pas le cas
     unsigned int compterPoints() { return points; };
     int getPoints() {return points;}
     void placerTetrimino();//on fait en sorte que la piece soit fixée dans le tableau de la grille
     void faireTournerTour();

};

#endif // JEU_H
