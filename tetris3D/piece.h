#ifndef PIECE_H
#define PIECE_H


class Piece
{
protected:
    enum Bloc{Carre, T_bloc, Baton, Lambda, L_inverse, Biais, Biais_inverse};
    //static int piece[7][4][2][4];//possibilite d'opti en 2,4
    int piece[2][4]={};
    int angle=0;
    Bloc type_;

public:
    Piece();
};


class PieceCarre: public Piece
{
private:


public:
    PieceCarre();
};


class PieceT_bloc: public Piece
{
private:


public:
    PieceT_bloc();
};


class PieceBaton: public Piece
{
private:


public:
    PieceBaton();


};


class PieceLambda: public Piece
{
private:


public:
    PieceLambda();

};


class PieceL_inverse: public Piece
{
private:


public:
    PieceL_inverse();

};


class PieceBiais: public Piece
{
private:


public:
    PieceBiais();

};


class PieceBiais_inverse: public Piece
{
private:

public:
    PieceBiais_inverse();
};






#endif // PIECE_H
