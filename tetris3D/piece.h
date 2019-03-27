#ifndef PIECE_H
#define PIECE_H

enum Bloc{Carre, T_bloc, Baton, Lambda, L_inverse, Biais, Biais_inverse};

class Piece
{  

protected:

    //static int piece[7][4][2][4];//possibilite d'opti en 2,4
    int piece[2][4]={};
    int angle=0;
    Bloc type_;

public :
        Piece();

};





#endif // PIECE_H
