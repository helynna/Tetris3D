#ifndef PIECE_H
#define PIECE_H

#include <GL/glu.h>
#include <QColor>
#include <string.h>
#include <vector>
#include <QApplication>
#include <QImage>
#include <math.h>



//Auteurs : Elodie Charitat

enum Bloc{Carre, T_bloc, Baton, Lambda, L_inverse, Biais, Biais_inverse};

class Piece
{  

protected:

    int piece[2][4]={};//Tableau contenant la forme de la pièce
    int angle=0;//rotation actuelle de la pièce
    Bloc type_;
    int x=3;//Position en x du carré de repère de la piece
    int y=0;//Position en y du carré de repère de la piece
    int typeCouleur_;//entier qui corredpond à la valeur que la pièce aura dans la grille
    void setX(int abs) {x=abs;}
    void setY(int ord) {y=ord;}

public :
    /*  Role : Construire l'objet et initialiser la forme de la pièce
        Entrée : vide
        Sortie :vide */
        Piece();

        /*  Role : Appeler la fonction pour faire tourner(rotation) le tétrimino à droite (dans le sens horaire)
            Entrée : vide
            Sortie :vide */
        void rotateRight();

        /*  Role : Appeler la fonction pour faire tourner(rotation) le tétrimino à gauche (dans le sens anti-horaire)
            Entrée : vide
            Sortie :vide */
        void rotateLeft();

        /*  Role : Récupérer la forme actuelle de la pièce en prenbant en compte sa rotation actuelle
            Entrée : un vecteur de vecteur dans lequel on va charger la pièce avec sa rotation actuelle
            Sortie :vide */
        void getActualShape(std::vector<std::vector<int>>& shape);

        /*  Role : Appeler la fonction pour faire tourner(rotation) le tétrimino à gauche (dans le sens anti-horaire)
            Entrée : vide
            Sortie :vide */
        int getAngle(){return angle;}

        /*  Role : Récupérer la valeur de la pièce, son indice utilisé dans la grille
            Entrée : vide
            Sortie : un entier qui correspond à la valeur de la pièce dans la grille */
        int getTypeCouleur() {return typeCouleur_;}

        /*  Role : Récupérer la position x de la pièce
            Entrée : vide
            Sortie : un entier qui correspond à la position de la pièce dans la grille en x */
        int getX() {return x;}

        /*  Role : Récupérer la position y de la pièce
            Entrée : vide
            Sortie : un entier qui correspond à la position de la pièce dans la grille en y */
        int getY() {return y;}

        /*  Role : Appeler la fonction pour faire déplacerle tétrimino à droite
            Entrée : vide
            Sortie :vide */
        void moveRight();

        /*  Role : Appeler la fonction pour faire déplacerle tétrimino à gauche
            Entrée : vide
            Sortie :vide */
        void moveLeft();

        /*  Role : Appeler la fonction pour faire déplacerle tétrimino vers le bas
            Entrée : vide
            Sortie :vide */
        void moveDown() {y+=1;}





};




#endif // PIECE_H
