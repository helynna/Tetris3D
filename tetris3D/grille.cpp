#include "grille.h"

Grille::Grille()
{//On rempli notre grille de 7, car la valeur vide est la valeur 7
    initialiser();

}

bool Grille::isFull(int numLigne)
{
    bool res=true;
    for(int i=0;i<nbColonne;i++){
        if(grille[numLigne][i]==7){//Si on a un 7, ça veut dire qu'il y a une case vide, on s'arrête
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
        for(int j=0;j<nbColonne;j++){//On fait descendre les lignes au-dessus jusqu'à avoir une ligne vide au dessus de la ligne actuelle
            grille[i][j]=grille[i-1][j];
        }
        i--;

    }
        for(int j=0;j<nbColonne;j++){//Si on a une ligne vide au-dessus on remplace notre ligne actuelle par la valeur 7 (vide)
            grille[i][j]=7;
        }

}


int Grille::supprimerLigneComplete()
{
    int t = 0;
    for(int i=0;i<nbLigne;i++){
        if(sommeLigne(i)!=70){
            if(isFull(i)){
                supprimerLigne(i);
                t++;
            }
        }
    }
    return t;

}

int Grille::sommeLigne(int numLigne)
{
    int somme =0;
    for(int i=0;i<nbColonne;i++){
        somme+=grille[numLigne][i];
    }

    return somme;

}


void Grille::addTetrimino(int x, int y, int shape)
{
    if(y<nbLigne && x<nbColonne){
        grille[y][x] = shape;//on ajoute sa valeur dans la grille
    }


}

void Grille::initialiser()
{//On rempli notre grille de 7, car la valeur vide est la valeur 7
    for(int i = 0; i < nbLigne; i++)
    {
        for(int j = 0; j < nbColonne; j++)
        {
            grille[i][j] = 7;
        }
    }

}

