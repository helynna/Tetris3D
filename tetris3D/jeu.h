#ifndef JEU_H
#define JEU_H

#include "piece.h"
#include "grille.h"
#include "piecebaton.h"
#include "piecebiais.h"
#include "piecebiais_inverse.h"
#include "piececarre.h"
#include "piecel_inverse.h"
#include "piecelambda.h"
#include "piecet_bloc.h"



//Auteurs : Elodie Charitat et Clément Jarousse

class Jeu
{  
private:
    unsigned int points = 0;//compteur de points
    Piece *tetrimino=nullptr;
    Grille* board_;
    int Couleur_[8][3]={//Les couleurs de nos pièces et l'indice correspond à la valeur dans la grille
        {255, 0, 0},//rouge
        {0, 255, 0},//Vert
        {0, 0, 255},//bleu
        {255, 255, 0},//jaune
        {255, 0, 255},//violet
        {0, 255, 255},//cyan
        {255,180,100},//Orange mais Gris : 180 partout
        {0, 0, 0}//vide
    };
    bool newTetrimino=true;//Booleen qui nous permet de savoir si l'on peut créer une nouvelle pièce ou pas

public:
    /*  Role : Construire l'objet et initialiser la grille avec la valeur vide, le 7
        Entrée : vide
        Sortie :vide */
    Jeu();

    /*  Role : Détruire l'objet et supprimer les pointeurs
        Entrée : vide
        Sortie :vide */
    ~Jeu();

    //Concernant le tetrimino

    /*  Role : Récupérer la forme actuelle de la pièce en prenbant en compte sa rotation actuelle
        Entrée : un vecteur de vecteur dans lequel on va charger la pièce avec sa rotation actuelle
        Sortie :vide */
     void getActualShapeTetrimino(std::vector<std::vector<int>>& shape) { tetrimino->getActualShape(shape);}

     /*  Role : Récupérer les positions du tetrimino dans la grille
         Entrée : un tableau d'entier qui correspondent à la position de la pièce dans la grille
         Sortie :vide */
     void getPosTetrimino(int Pos[2]);

     /*  Role : Récupérer la valeur de la pièce dans la grille
         Entrée : vide
         Sortie : un entier qui correspond à la valeur de la pièce dans la grille */
     int getTypeShapeTetrimino(){return tetrimino->getTypeCouleur();}

     /*  Role : Appeler la fonction pour faire tourner(rotation) le tétrimino à gauche s'il en a la possibilité
         Entrée : vide
         Sortie :vide */
     void tournerPieceGauche();

     /*  Role : Appeler la fonction pour faire tourner(rotation) le tétrimino à droite s'il en a la possibilité
         Entrée : vide
         Sortie :vide */
     void tournerPieceDroite();

     /*  Role : Appeler la fonction pour faire bouger/déplacer le tétrimino à gauche s'il en a la possibilité
         Entrée : vide
         Sortie :vide */
     void allerAGauche();

     /*  Role : Appeler la fonction pour faire bouger/déplacer le tétrimino à gauche s'il en a la possibilité
         Entrée : vide
         Sortie :vide */
     void allerADroite();

     /*  Role : Tester si la pièce peut bouger dans la direction du bas
         Entrée : un vecteur de vecteur qui correspond à la pièce actuelle avec sa rotation actuelle, un tableau d'entiers qui correspondent à la position de la pièce dans la grille
         Sortie :un booléen qui correspond à true s'il peut descendre et false s'il ne peut pas */
     bool peutDescendre(const std::vector<std::vector<int>>& shape,int pos[2]);

     /*  Role : Vérifier si la pièce peut bouger dans une direction indiquée
         Entrée : un vecteur de vecteur qui correspond à la pièce actuelle avec sa rotation actuelle, un tableau d'entiers qui correspondent à la position de la pièce dans la grille
         un offset en x qui permet de savoir si la pièce peut se déplacer dans la direction en x indiqué par l'offset (exemple : aller à gauche = offset négatif de -1)
         un offset en y qui permet de savoir si la pièce peut se déplacer dans la direction en y indiqué par l'offset
         Sortie :vide */
     bool peutBouger(const std::vector<std::vector<int>>& shape,int pos[2], int offx, int offy);

     /*  Role : Vérifier que la pièce peut descendre, puis la faire descendre si c'est le cas et la fixer dans la grille si ce n'est pas le cas.
      *  Vérification des lignes complètes et compter les points s'il y a suppression des lignes
         Entrée : vide
         Sortie :vide */
     void faireDescendre();



    //Concernant la grille
     /*  Role : Récupérer la couleur de la pièce dans le format RGB, pour pouvoir la dessiner correctement
      *  Vérification des lignes complètes et compter les points s'il y a suppression des lignes
         Entrée : un tableau d'entiers qui correspond aux couleurs de la pièce actuell, un entier qui correspond à la piece que l'on a actuellement
         Sortie :vide */
     void getCouleur(int couleur[3], int shape);

     /*  Role : Récupérer l'indice qui est contenu dans la grille pour une case précise en apellant la fonction de la classe Grille
         Entrée : deux entiers qui correspondent à la position de l'indice dans la grille
         Sortie : un entier qui correspond à l'indice contenu dans la grille  */
     int getIndiceInGrille(int x, int y);

     /*  Role : Faire la somme des valeurs contenues dans la grille sur une même ligne en apellant la fonction de la classe Grille
         Entrée : un entier qui correspond au  numéro de la ligne
         Sortie : un entier qui correspond à la somme des valeurs sur la ligne */
     int doSumLine(int x);




    //Concernant le jeu en général
     /*  Role : On vérifie si l'on peut créer un nouveau tétrimino c'est à dire si celui d'avant est fixé (indiquer par le booléen)
      *  Puis si c'est possible on en créer un de façon aléatoire parmi les 7 possibles
         Entrée : vide
         Sortie : vide */
     void creationPieceAleatoire();

     /*  Role : On teste si la grille est "complète" ou si ce n'est pas le cas
         Entrée : vide
         Sortie : sortie qui correspond à la fin du jeu ou pas. True = gameOver et False= on peut continuer*/
     bool testerGameOver();

     /*  Role : Retourner le nombre de points que le joueur a actuellement
         Entrée : vide
         Sortie : Un entier qui correspond au nombre de points*/
     int getPoints() {return points;}

     /*  Role : Placer la valeur du tétrimino dans la grille à la position où il est actuellement
         Entrée : vide
         Sortie : vide  */
     void placerTetrimino();

     /*  Role : Initilaiser la grille avec la valeur vide, le 7
         Entrée : vide
         Sortie :vide */
     void initialiser();


};

#endif // JEU_H
