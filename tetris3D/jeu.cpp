#include "jeu.h"

Jeu::Jeu()
{




}

void Jeu::creationPieceAleatoire()
{
    srand (time(NULL));
    int nb=rand()%7;


    switch(nb){
    case 0:
        tetrimino=new PieceBiais();
        break;

    case 1:
        tetrimino=new PieceBiais_inverse();
        break;

    case 2:
        tetrimino=new PieceL_inverse();
        break;

    case 3:
        tetrimino=new PieceLambda();
        break;

    case 4:
        tetrimino=new PieceCarre();
        break;

    case 5:
        tetrimino=new PieceBaton();
        break;

    case 6:
        tetrimino=new PieceT_bloc();
        break;




    }
}

void Jeu::tournerPieceGauche()
{
    tetrimino->rotateLeft();
}

void Jeu::tournerPieceDroite()
{
    tetrimino->rotateRight();
}

void Jeu::allerAGauche()
{
    /*if(tetrimino->getX()>0){
        tetrimino->setX()
    }*/
}
