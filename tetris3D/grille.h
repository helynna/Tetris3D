#ifndef GRILLE_H
#define GRILLE_H

#include "piece.h"

#define nbColonne 10//Nombre de colonne pour la grille
#define nbLigne 20//Nombre de ligne pour la grille

class Grille
{
private :
    unsigned int grille[nbLigne][nbColonne]={};

public:
    /*  Role : Construire l'objet et initilaiser la grille avec la valeur vide, le 7
        Entrée : vide
        Sortie :vide */
    Grille();

    /*  Role : Tester si une ligne est pleine ou s'il reste un emplacement vide
        Entrée : un entier qui correspond au numéro de la ligne
        Sortie : un booléen qui indique si oui (true) la ligne est pleine ou false si elle est non pleine */
    bool isFull(int numLigne);

    /*  Role : Supprimer une ligne, donc ligne actuelle qui prend la valeur des lignes dessus et on fait descendre les lignes suivantes
        Entrée : un entier qui correspond au  numéro de la ligne
        Sortie :vide */
    void supprimerLigne(int numLigne);

    /*  Role : Tester si une ligne est pleine qui la supprimer si c'est le cas
        Entrée : vide
        Sortie : un entier qui correspond au nombre de ligne(s) supprimée(s) en une pièce ajouté */
    int supprimerLigneComplete();

    /*  Role : Faire la somme des valeurs contenues dans la grille sur une même ligne
        Entrée : un entier qui correspond au  numéro de la ligne
        Sortie : un entier qui correspond à la somme des valeurs sur la ligne */
    int sommeLigne(int numLigne);


    /*  Role : Récupérer l'indice qui est contenu dans la grille pour une case précise
        Entrée : deux entiers qui correspondent à la position de l'indice dans la grille
        Sortie : un entier qui correspond à l'indice contenu dans la grille  */
    int getIndiceGrille(int x, int y) {return grille[y][x];}

    /*  Role : Ajout d'un tetrimino dans la grille à la position indiquer
        Entrée : 2 entiers qui correspondent à la position dans la grille et le 3e indice qui correspond à la valeur de l'indice à ajouter dans la grille
        Sortie :vide */
    void addTetrimino(int x, int y, int shape);

    /*  Role : Initilaiser la grille avec la valeur vide, le 7
        Entrée : vide
        Sortie :vide */
    void initialiser();







};

#endif // GRILLE_H
