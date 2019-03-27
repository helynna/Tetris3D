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
    while(sommeLigne(i-1)!=0)
    {
        for(int j=0;j<nbColonne;j++){
            grille[i][j]=grille[i-1][j];
        }
        i--;

    }
        for(int j=0;j<nbColonne;j++){
            grille[i][j]=0;
        }



}

void Grille::supprimerLigneComplete()
{
    for(int i=0;i<nbLigne;i++){
        if(sommeLigne(i)!=0){
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

/*bool Grille::testDescente(Bloc type, int x, int y,int rotation)//{0,90,180,270};
{
    //enum Bloc{Carre, T_bloc, Baton, Lambda, L_inverse, Biais, Biais_inverse};
    switch(type){
    case Carre:
        
        break;

    case T_bloc:
        break;

    case Baton:
        break;

    case Lambda:
        break;

    case L_inverse:
        break;

    case Biais:
        break;

    case Biais_inverse:
        break;


    }
}
*/
