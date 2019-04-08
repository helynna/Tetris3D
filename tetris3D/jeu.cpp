#include "jeu.h"

Jeu::Jeu()
{
    board_ = new Grille();
    creationPieceAleatoire();

}

Jeu::~Jeu()
{
    delete board_;
    delete tetrimino;
}


void Jeu::creationPieceAleatoire()
{
    if(newTetrimino){
        srand (time(NULL));
        int nb=rand()%7;
        delete tetrimino;


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

void Jeu::initialiser()
{
    delete board_;
    delete tetrimino;
    points = 0;
    tetrimino=nullptr;
    newTetrimino=true;
    board_->initialiser();
    creationPieceAleatoire();


}

void Jeu::tournerPieceGauche()
{
    tetrimino->rotateLeft();
    std::vector<std::vector<int>> shape;//forme actuelle de la pièce avec sa rotation
    int pos[2]={};//tableau de la position du carré repère de la pièce
    getPosTetrimino(pos);
    getActualShapeTetrimino(shape);
    if(!peutBouger(shape,pos, 0, 0)){//Test des collisions avant de faire tourner la pièce
        tetrimino->rotateRight();
    }
}

void Jeu::tournerPieceDroite()
{
    tetrimino->rotateRight();
    std::vector<std::vector<int>> shape;//forme actuelle de la pièce avec sa rotation
    int pos[2]={};//tableau de la position du carré repère de la pièce
    getPosTetrimino(pos);
    getActualShapeTetrimino(shape);
    if(!peutBouger(shape,pos, 0, 0)){//Test des collisions avant de faire tourner la pièce
        tetrimino->rotateLeft();
    }
}

void Jeu::allerAGauche()
{
    std::vector<std::vector<int>> shape;//forme actuelle de la pièce avec sa rotation
    int pos[2]={};//tableau de la position du carré repère de la pièce
    getPosTetrimino(pos);
    getActualShapeTetrimino(shape);
    if(peutBouger(shape,pos, -1, 0)){//Test des collisions avant de faire bouger la pièce
        tetrimino->moveLeft();
    }
}

void Jeu::allerADroite()
{
    std::vector<std::vector<int>> shape;//forme actuelle de la pièce avec sa rotation
    int pos[2]={};//tableau de la position du carré repère de la pièce
    getPosTetrimino(pos);
    getActualShapeTetrimino(shape);
    if(peutBouger(shape,pos, 1, 0)){//Test des collisions avant de faire bouger la pièce
        tetrimino->moveRight();
    }
}

bool Jeu::peutBouger(const std::vector<std::vector<int>>& shape,int pos[2], int offx, int offy)
{//On applique un offset dans le cas ou notre carré qui représente la pièce est décalé à cause d'une rotation
 //Mais aussi quand on veut tester vers le bas car le carré représentatif est celui en haut à gauche de la pièce
 //Or pour tester le mouvement vers le bas on veut la 2nd ligne
    for(int i = 0; i < shape.size(); i++)
    {
        for(int j = 0; j < shape[i].size(); j++)
        {
            if(shape[i][j] == 1)//On teste si jamais il y a une valeur dans la pièce, donc qu'il s'agit d'un morceau de pièce
            {
                if(pos[0]+i+offx < 0 || pos[0]+i+offx >= nbColonne || pos[1]+j+offy < 0 || pos[1]+j+offy >= nbLigne)//Si ça sort des dimensions de la grille on ne peut pas bouger
                    return false;
                if(board_->getIndiceGrille(pos[0]+i+offx, pos[1]+j+offy) != 7)//S'il a déjà une pièce dans la grille on ne peut pas y aller
                    return false;
            }
        }
    }

    return true;
}

bool Jeu::peutDescendre(const std::vector<std::vector<int>>& shape,int pos[2])
{
    return peutBouger(shape, pos, 0, 1);//test si on peut bouger vers le bas, on applique un offset vers le bas pour tester directement la seconde ligne
}

void Jeu::faireDescendre()
{
    std::vector<std::vector<int>> shape;
    int pos[2]={};
    getPosTetrimino(pos);
    getActualShapeTetrimino(shape);
    if(peutDescendre(shape,pos)){//On regarde s'il peut descendre
        tetrimino->moveDown();//On le fait descendre
    } else {//il ne peut pas descendre
        placerTetrimino();//On fixe la valeur du tetrimino dans la grille
        int deletedLines = board_->supprimerLigneComplete();//On verifie s'il faut supprimer la ligne
        switch(deletedLines)//On applique les points en fonction du nombre de lignes supprimées
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
        if(!testerGameOver())//Si le joueur peut encore jouer
            creationPieceAleatoire();//On créer une nouvelle pièce
    }

}

void Jeu::getCouleur(int couleur[], int shape)
{//A partir de l'indice de la pièce on récupère ses valeurs rgb pour la dessiner de la bonne couleur
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

    if(doSumLine(0) != 70){//On teste s'il n'y a pas de pièce sur la dernière ligne
        newTetrimino=false;
        return true;
    }
    return false;
}
