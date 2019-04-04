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
    std::vector<std::vector<int>> shape;
    int pos[2]={};
    getPosTetrimino(pos);
    getActualShapeTetrimino(shape);
    int color;
    color=tetrimino->getTypeCouleur();
    if(!peutDescendre(shape,pos)){
        for(int i=0;i<shape.front().size();i++){
            for(int j=0;j<shape.size();j++){
                board_->addTetrimino(pos[0]+i, pos[1]+j,color);
            }
        }
        newTetrimino=true;
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
                return false;
                //pos[0]+i,pos[1]+j)
            }


        }
    }
    else{//On est pas à la dernière ligne

            for(int j=0;j<shape.size();j++){
                if(shape[shape.front().size()-1][j]==1){//On essaye de savoir si la dernière ligne de la pièce contient un morceau de pièce
                    if((board_->getIndiceGrille(pos[0]+(shape.front().size()),pos[1]+j))!=7){//On voit si en dessous de notre morceau de pièce on a déjà un cube sur la grille
                       return false;
                    }
                    else{//Si le dessous de la pièce est libre, il faut vérifier une case au-dessus
                        res=true;
                        if(shape[shape.front().size()-2][j]==1){//On est à la ligne 1 si la pièce fait 2 de hauteur et 3 si elle en fait 4
                            if((board_->getIndiceGrille(pos[0]+(shape.front().size())-1,pos[1]+j))!=7){//On va regarder en dessous de la pièce
                               return false;
                            }
                            else{//Dans le cas où il n'y a rien sous la pièce
                                res=true;
                                if((shape.front().size())>2){//Si la taille de la pièce est supérieure à 2, on continue
                                    if(shape[shape.front().size()-3][j]==1){//On est à la ligne 2 si la pièce fait 4 de hauteur
                                        if((board_->getIndiceGrille(pos[0]+(shape.front().size())-2,pos[1]+j))!=7){//On va regarder en dessous de la pièce
                                           return false;
                                        }
                                        else{//On a rien en dessous du morceau de pièce
                                            res=true;
                                            if(shape[shape.front().size()-4][j]==1){//On est à la ligne 1 si la pièce fait 4 de hauteur
                                                if((board_->getIndiceGrille(pos[0]+(shape.front().size())-3,pos[1]+j))!=7){//On va regarder en dessous de la pièce
                                                   return false;
                                                }
                                                else{//On a rien en dessous du morceau de pièce
                                                    res=true;
                                                }
                                            }
                                        }

                                    }

                                }
                            }
                        }
                    }
                }else {//Si l'avant dernière ligne ne contient pas de morceau de pièce (ligne 1 ou ligne 3)
                    if(shape[shape.front().size()-2][j]==1){//On essaye de savoir si la dernière ligne de la pièce contient un morceau de pièce
                        if((board_->getIndiceGrille(pos[0]+(shape.front().size()),pos[1]+j))!=7){//On voit si en dessous de notre morceau de pièce on a déjà un cube sur la grille
                           return false;
                        }
                        else{//Si le dessous de la pièce est libre, il faut vérifier une case au-dessus
                            res=true;
                            if((shape.front().size())>2){//Si la taille de la pièce est supérieure à 2, on continue
                                if(shape[shape.front().size()-3][j]==1){//On est à la ligne 2 si la pièce fait 4 de hauteur
                                    if((board_->getIndiceGrille(pos[0]+(shape.front().size())-2,pos[1]+j))!=7){//On va regarder en dessous de la pièce
                                       return false;
                                    }
                                    else{//On a rien en dessous du morceau de pièce
                                        res=true;
                                        if(shape[shape.front().size()-4][j]==1){//On est à la ligne 1 si la pièce fait 4 de hauteur
                                            if((board_->getIndiceGrille(pos[0]+(shape.front().size())-3,pos[1]+j))!=7){//On va regarder en dessous de la pièce
                                               return false;
                                            }
                                            else{//On a rien en dessous du morceau de pièce
                                                res=true;
                                            }
                                        }
                                    }

                                }

                             }
                         }
                       }
                    else {//Si la dernière ligne ne contient pas de morceau de pièce (ligne 1 ou ligne 3)
                        if((shape.front().size())>2){//Si la taille de la pièce est supérieure à 2, on continue parce que sinon on va avoir un problème d'indice d'accès aux cases
                                        if(shape[shape.front().size()-3][j]==1){//On essaye de savoir si la ligne 2 de la pièce contient un morceau de pièce
                                            if((board_->getIndiceGrille(pos[0]+(shape.front().size()),pos[1]+j))!=7){//On voit si en dessous de notre morceau de pièce on a déjà un cube sur la grille
                                               return false;
                                            }
                                            else{//Si le dessous de la pièce est libre, il faut vérifier une case au-dessus
                                                res=true;
                                                    if(shape[shape.front().size()-4][j]==1){//On est à la ligne 1 si la pièce fait 4 de hauteur
                                                        if((board_->getIndiceGrille(pos[0]+(shape.front().size())-2,pos[1]+j))!=7){//On va regarder en dessous de la pièce
                                                           return false;
                                                        }
                                                        else{//On a rien en dessous du morceau de pièce
                                                            res=true;
                                                            }
                                                        }

                                                    }

                                                 }
                                        else {//Si la dernière ligne ne contient pas de morceau de pièce (ligne 1 pour une pièce de 4)
                                            if((shape.front().size())>2){//Si la taille de la pièce est supérieure à 2, on continue parce que sinon on va avoir un problème d'indice d'accès aux cases
                                                            if(shape[shape.front().size()-4][j]==1){//On essaye de savoir si la ligne 2 de la pièce contient un morceau de pièce
                                                                if((board_->getIndiceGrille(pos[0]+(shape.front().size()),pos[1]+j))!=7){//On voit si en dessous de notre morceau de pièce on a déjà un cube sur la grille
                                                                   return false;
                                                                }
                                                                else{//Si le dessous de la pièce est libre, il faut vérifier une case au-dessus
                                                                    res=true;
                                                                        if(shape[shape.front().size()-4][j]==1){//On est à la ligne 1 si la pièce fait 4 de hauteur
                                                                            if((board_->getIndiceGrille(pos[0]+(shape.front().size())-2,pos[1]+j))!=7){//On va regarder en dessous de la pièce
                                                                               return false;
                                                                            }
                                                                            else{//On a rien en dessous du morceau de pièce
                                                                                res=true;
                                                                                }
                                                                            }

                                                                        }

                                                                     }
                                                                 }
                                             }

                                           }
        }
    }

            }
    }
    return res;
}

void Jeu::faireDescendre()
{
    std::vector<std::vector<int>> shape;
    int pos[2]={};
    getPosTetrimino(pos);
    getActualShapeTetrimino(shape);
    if(peutDescendre(shape,pos)){
        tetrimino->moveDown();
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

