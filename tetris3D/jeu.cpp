#include "jeu.h"

Jeu::Jeu()
{




}

void Jeu::creationPieceAleatoire()
{
    if(newTetrimino){
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
        newTetrimino=false;
    }
}

void Jeu::placerTetrimino()
{




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

bool Jeu::peutDescendre(std::vector<std::vector<int>> shape,int pos[2])
{
    bool res=true;
    /*
    std::vector<std::vector<int>> shape;
    int pos[2]={};
    getPosTetrimino(pos);
    getActualShapeTetrimino(shape);*/
    if(pos[0]==18){
        for(int j=0;j<shape.size();j++){
            if(shape[shape.front().size()-1][j]==1){
                res=false;
                //pos[0]+i,pos[1]+j)
            }


        }
    }
    else{//On est pas à la dernière ligne
        for(int j=0;j<shape.size();j++){
            if(shape[shape.front().size()-1][j]==1){
                if((board_->getIndiceGrille(pos[0]+1,pos[1]+j))!=7){
                   res=false;
                }
                else{
                    res=true;
                }

                //Ici il faut prendre la dernière case du shape
                //qu'on ajoute à la pos actuelle, on verifie s'il y a des 1
                //si oui on verifie que dessous c'est libre
                //puis on verifie que les cases au dessus sont libres
                //surtout si la derniere est vide
                //pos[0]+i,pos[1]+j)
            }
            else{//Notre dernière case de la pièce ne contient pas de 1, donc pas de pièce
                if(shape.front().size()){

                }//blbl

            }
        }
    }
}

void Jeu::getCouleur(int couleur[], int shape)
{
        couleur[0]=Couleur_[shape][0];
        couleur[1]=Couleur_[shape][1];
        couleur[2]=Couleur_[shape][2];
}

int Jeu::getIndiceInGrille(int x, int y)
{
    return board_->getIndiceGrille(x,y);
}

int Jeu::doSumLine(int x)
{
    board_->sommeLigne(x);
}

void Jeu::getPosTetrimino(int Pos[2])
{
    Pos[0]=tetrimino->getX();
    Pos[1]=tetrimino->getY();
}

