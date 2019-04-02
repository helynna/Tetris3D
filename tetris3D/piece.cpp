#include "piece.h"
#include "piecebaton.h"
#include "piecebiais.h"
#include "piecebiais_inverse.h"
#include "piececarre.h"
#include "piecel_inverse.h"
#include "piecelambda.h"
#include "piecet_bloc.h"


Piece::Piece()
{


}

void Piece::rotateRight()
{    

    if(angle+=90>270){
        angle = 0;
    }

}

void Piece::rotateLeft()
{

    if(angle-=90<0){
        angle = 360;
    }
}

void Piece::getActualShape(std::vector<std::vector<int> > shape)
{
    switch (angle){

        case 0:
            for(int i=0;i<2;i++){
                for(int j=0;j<4;j++){
                   shape[i][j]=piece[i][j];
                }

            }

            break;

        case 90:
            for(int i=0;i<2;i++){
                for(int j=0;j<4;j++){
                   //shape[i][j]=piece[j][1-i];
                   shape[j][1-i]=piece[i][j];
                }

            }
            break;

        case 180:
            for(int i=0;i<2;i++){
                for(int j=0;j<4;j++){
                   //shape[i][j]=piece[1-i][3-j];
                   shape[1-i][3-j]=piece[i][j];
                }

            }
            break;

        case 270:
        for(int i=0;i<2;i++){
            for(int j=0;j<4;j++){
               //shape[i][j]=piece[3-j][i];
               shape[3-j][i]==piece[i][j];
            }

        }
            break;
    }

}

void Piece::moveRight(int abs)
{


}






