#include "grille.h"

Grille::Grille()
{

}

bool Grille::isFull(int numLigne)
{
    bool res=true;
    for(int i=0;i<nbColonne;i++){
        if(grille[numLigne][i]!=0){
            res=false;
        }

    }
    return res;
}

void Grille::supprimerLigne(int numLigne)
{   int i=numLigne;
    /*while(sommeLigne(i-1)!=0)
    {
        for(int j=0;i<nbColonne;j++){
            grille[i][j]=grille[i-1][j];
        }
        i--;

    }
        for(int j=0;i<nbColonne;j++){
            grille[i][j]=grille[i-1][j];
        }
*/


}

int Grille::sommeLigne(int numLigne)
{
    int somme =0;
    for(int i=0;i<nbColonne;i++){
        somme+=grille[numLigne][i];
    }

    return somme;

}
