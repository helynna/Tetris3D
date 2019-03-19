#ifndef GRILLE_H
#define GRILLE_H

#define nbColonne 10
#define nbLigne 20

class Grille
{
private :
    //const unsigned int nbColonne=10;
    //const unsigned int nbLigne=20;
    unsigned int grille[nbLigne][nbColonne]={};
    unsigned int indiceActuel=1;
    //unsigned int grille[20][10]={};
public:
    Grille();
    bool isFull(int numLigne);
    void supprimerLigne(int numLigne);
    int sommeLigne(int numLigne);





};

#endif // GRILLE_H
