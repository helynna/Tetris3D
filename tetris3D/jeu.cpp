#include "jeu.h"

Jeu::Jeu()
{
    board_ = new Grille();
    creationPieceAleatoire();

}

Jeu::~Jeu()
{
    delete board_;
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
        for(int i=0;i<shape.size();i++){
            for(int j=0;j<shape.front().size();j++){
                if(shape[i][j])
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
    std::vector<std::vector<int>> shape;
    int pos[2]={};
    getPosTetrimino(pos);
    getActualShapeTetrimino(shape);
    if(peutBouger(shape,pos, -1, 0)){
        tetrimino->moveLeft();
    }
}

void Jeu::allerADroite()
{
    std::vector<std::vector<int>> shape;
    int pos[2]={};
    getPosTetrimino(pos);
    getActualShapeTetrimino(shape);
    if(peutBouger(shape,pos, 1, 0)){
        tetrimino->moveRight();
    }
}

bool Jeu::peutBouger(const std::vector<std::vector<int>>& shape,int pos[2], int offx, int offy)
{
    for(int i = 0; i < shape.size(); i++)
    {
        for(int j = 0; j < shape[i].size(); j++)
        {
            if(shape[i][j] == 1)
            {
                if(pos[0]+i+offx < 0 || pos[0]+i+offx >= nbColonne || pos[1]+j+offy < 0 || pos[1]+j+offy >= nbLigne)
                    return false;
                if(board_->getIndiceGrille(pos[0]+i+offx, pos[1]+j+offy) != 7)
                    return false;
            }
        }
    }

    return true;
}

bool Jeu::peutDescendre(const std::vector<std::vector<int>>& shape,int pos[2])
{
    return peutBouger(shape, pos, 0, 1);
}

void Jeu::faireDescendre()
{
    std::vector<std::vector<int>> shape;
    int pos[2]={};
    getPosTetrimino(pos);
    getActualShapeTetrimino(shape);
    if(peutDescendre(shape,pos)){
        tetrimino->moveDown();
    } else {
        placerTetrimino();
        int deletedLines = board_->supprimerLigneComplete();
        switch(deletedLines)
        {
            case 1:
                points += 100;
                break;
            case 2:
                points += 250;
                break;
            case 3:
                points += 500;
                break;
            case 4:
                points += 1000;
                break;
        }
        if(!testerGameOver())
            creationPieceAleatoire();
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
    return board_->sommeLigne(x);
}

void Jeu::getPosTetrimino(int Pos[2])
{
    Pos[0]=tetrimino->getX();
    Pos[1]=tetrimino->getY();
}

bool Jeu::testerGameOver() {
    return doSumLine(0) != 70;
}
