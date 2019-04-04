#include "grille.h"

Grille::Grille()
{
    /*
    //rouge
    Couleur_[0][0]=255;
    //vert
    Couleur_[1][1]=255;
    //bleu
    Couleur_[2][2]=255;
    //orange
    Couleur_[3][0]=255;
    Couleur_[3][1]=165;
    //Couleur_[3][0]=255;
    //jaune
    Couleur_[4][0]=255;
    Couleur_[4][1]=255;
    //cyan
    Couleur_[5][1]=255;
    Couleur_[5][2]=255;
    //violet
    Couleur_[6][0]=255;
    Couleur_[6][2]=255;

*/

}

bool Grille::isFull(int numLigne)
{
    bool res=true;
    for(int i=0;i<nbColonne;i++){
        if(grille[numLigne][i]==7){
            res=false;
            break;
        }

    }
    return res;
}

void Grille::supprimerLigne(int numLigne)
{   int i=numLigne;
    while(sommeLigne(i-1)!=70)
    {
        for(int j=0;j<nbColonne;j++){
            grille[i][j]=grille[i-1][j];
        }
        i--;

    }
        for(int j=0;j<nbColonne;j++){
            grille[i][j]=7;
        }



}

void Grille::supprimerLigneComplete()
{
    for(int i=0;i<nbLigne;i++){
        if(sommeLigne(i)!=70){
            if(isFull(i)){
                supprimerLigne(i);
            }
        }
    }


}

int Grille::sommeLigne(int numLigne)
{
    int somme =0;
    for(int i=0;i<nbColonne;i++){
        somme+=grille[numLigne][i];
    }

    return somme;

}

bool Grille::testDescente(Bloc type, int x, int y,int rotation)//{0,90,180,270};
{
    //int shape[][];

    switch(rotation){
    case 0:

        break;

    case 90:
        break;

    case 180:
        break;

    case 270:
        break;


    }
}

bool Grille::testGrille(int x, int y)
{
    if(grille[x-1][y]!=0){
        return false;
    }else{
        return true;
    }
}

void Grille::addTetrimino(int x, int y, int shape)
{
    if(x<nbLigne && y<nbColonne){
        grille[x][y] = shape;
    }


}

/*
void Grille::getCouleur(int couleur[3], int shape)
{
    couleur[0]=Couleur_[shape][0];
    couleur[1]=Couleur_[shape][1];
    couleur[2]=Couleur_[shape][2];

}*/
