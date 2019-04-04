#ifndef PIECE_H
#define PIECE_H

#include <GL/glu.h>
#include <QColor>
#include <string.h>
#include <vector>
#include <QApplication>
#include <QImage>
#include <math.h>

enum Bloc{Carre, T_bloc, Baton, Lambda, L_inverse, Biais, Biais_inverse};

class Piece
{  

protected:

    //static int piece[7][4][2][4];//possibilite d'opti en 2,4
    int piece[2][4]={};
    //int piece[2][2][4]={};
    int angle=0;
    Bloc type_;
    int x=3;
    int y=0;
   // std::vector<float> Couleur_;
    int typeCouleur_;
    void setX(int abs) {x=abs;}
    void setY(int ord) {y=ord;}

public :
        Piece();
        void rotateRight();
        void rotateLeft();
        void getActualShape(std::vector<std::vector<int>>& shape);
        int getAngle(){return angle;}

        //template<size_t rows, size_t cols>
        //void f(int (&shape)[rows][cols]);
        int getTypeCouleur() {return typeCouleur_;}
        int getX() {return x;}
        int getY() {return y;}
        void moveRight();
        void moveLeft();
        void moveDown() {y+=1;}
        void moveUp() {y-=1;}; // A delete à la fin des tests




};




#endif // PIECE_H
