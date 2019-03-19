#include "piece.h"

Piece::Piece()
{
    //switch



}

//int Piece::piece[7][4][2][4]={};

PieceCarre::PieceCarre()
{
    piece[0][0]=1;
    piece[0][1]=1;
    piece[1][0]=1;
    piece[1][1]=1;
}

PieceT_bloc::PieceT_bloc()
{
    piece[0][0]=1;
    piece[0][1]=1;
    piece[0][2]=1;
    piece[1][1]=1;
}

PieceBaton::PieceBaton()
{
    piece[0][0]=1;
    piece[0][1]=1;
    piece[0][2]=1;
    piece[0][3]=1;
}

PieceLambda::PieceLambda()
{
    piece[0][0]=1;
    piece[0][1]=1;
    piece[0][2]=1;
    piece[1][0]=1;
}

PieceL_inverse::PieceL_inverse()
{
    piece[0][0]=1;
    piece[0][1]=1;
    piece[0][2]=1;
    piece[1][2]=1;
}

PieceBiais::PieceBiais()
{
    piece[0][0]=1;
    piece[0][1]=1;
    piece[1][1]=1;
    piece[1][2]=1;
}

PieceBiais_inverse::PieceBiais_inverse()
{
    piece[0][2]=1;
    piece[0][1]=1;
    piece[1][1]=1;
    piece[1][0]=1;
}
