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

    int piece[2][4]={};//Tableau contenant la forme de la pièce
    int angle=0;//rotation actuelle de la pièce
    Bloc type_;
    int x=3;//Position du carré de repère de la piece
    int y=0;
    int typeCouleur_;
    void setX(int abs) {x=abs;}
    void setY(int ord) {y=ord;}

public :
        Piece();
        void rotateRight();
        void rotateLeft();
        void getActualShape(std::vector<std::vector<int>>& shape);//Lis le tableau contenant la forme de base, en fonction de la rotation
        int getAngle(){return angle;}


        int getTypeCouleur() {return typeCouleur_;}
        int getX() {return x;}
        int getY() {return y;}
        void moveRight();
        void moveLeft();
        void moveDown() {y+=1;}
        void moveUp() {y-=1;}; // A delete à la fin des tests




};




#endif // PIECE_H
