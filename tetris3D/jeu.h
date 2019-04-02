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
    Grille board_;

public:
    Jeu();
    void creationPieceAleatoire();//On va modifier la piece tetriminos que l'on stock vu qu'une nouvelle piece se fait seuelemnt quand l'autre est posée
    void placerPiece();//on fait en sorte que la piece soit fixée dans le tableau de la grille
    void testerGameOver();//On teste si la grille est complète ou si ce n'est pas le cas
    void compterPoints();
    void ajouterPiece();
    void tournerPieceGauche();
    void tournerPieceDroite();
    void allerAGauche();
    void allerADroite();
    void descenteRapide();
    void fixerPiece();


};

#endif // JEU_H
