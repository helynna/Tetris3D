#ifndef JEU_H
#define JEU_H

#include "piece.h"

class Jeu
{  
private:
    unsigned int points;
    Piece tetriminos;

public:
    Jeu();
    void creationPieceAleatoire();//On va modifier la piece tetriminos que l'on stock vu qu'une nouvelle piece se fait seuelemnt quand l'autre est posée
    void placerPiece();//on fait en sorte que la piece soit fixée dans le tableau de la grille
    void testerGameOver();//On teste si la grille est complète ou si ce n'est pas le cas
    void compterPoints();


};

#endif // JEU_H
