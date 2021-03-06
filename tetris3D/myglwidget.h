#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QTimer>
#include <GL/glu.h>
#include <QColor>
#include <string.h>
#include <vector>
#include <QApplication>
#include <QImage>

#include "grille.h"
#include "jeu.h"


//Auteurs : Elodie Charitat et Clément Jarousse

// Classe dediee a l'affichage d'une scene OpenGL
class MyGLWidget : public QGLWidget
{
    Q_OBJECT

public:
    /*  Role : Construire l'objet et initialiser les attributs de la fenêtre 3D, initialiser les clocks
        Entrée : un pointeur sur le parent, qui est nul
        Sortie :vide */
    MyGLWidget(QWidget * parent = nullptr);

protected:
    /*  Role : Initialiser la fenêtre avec les activations des paramètres GL (comme la profondeur, les lumières)
        Entrée : vide
        Sortie :vide */
    void initializeGL();

    /*  Role : Redimensionne la fenêtre dans le cas d'un changement d'échelle
        Entrée : deux entiers qui correspondent aux dimensions de la fenêtre
        Sortie :vide */
    void resizeGL(int width, int height);

    /*  Role : Fonction qui permet l'affichage de la scène en 3D
        Entrée : vide
        Sortie :vide */
    void paintGL();

    /*  Role : Fonction qui permet de dessiner la grille de la scène en 3D
        Entrée : vide
        Sortie :vide */
    void paintLinesGL();

    //Dessiner les pieces
    /*  Role : Fonction qui permet de dessiner un cube en dessinant ses 6 faces par rapport à une position donnée
        Entrée : deux entiers qui correspondent à la position du coin en haut à gauche de la face du dessous et un tableau de
                 3 entiers qui correspond à la couleur RGB du cube
        Sortie :vide */
    void paintCube(float x, float y,int Couleur[3]);
    /*  Role : Fonction qui permet de dessiner le tétrimino qui n'est pas fixé dans la grille, celui que l'on peut déplacer
        Entrée : vide
        Sortie :vide */
    void paintTetrimino();
    /*  Role : Fonction qui permet de dessiner les tétriminos qui sont fixés dans la grille, donc le contenu de la grille
        Entrée : vide
        Sortie :vide */
    void paintBoard();

    // Fonction de gestion d'interactions clavier
    /*  Role : Fonction qui permet de capter une interaction de l'utilisateur et d'appeler des fonctions en conséquence
        Entrée : un pointeur sur un évenement, qui correspond à l'évenenemnt qui vient d'arriver
        Sortie :vide */
    void keyPressEvent(QKeyEvent * event);
    /*  Role : Fonction qui permet de mettre en pause l'affichage
        Entrée : vide
        Sortie :vide */
    void mettrePause();




public slots:
    void rotateLeft();
    void rotateRight();
    void goLeft();
    void goRight();
    void goDown();
    void regame();

private:
    // Timer d'animation
    Jeu* game;

    bool gameOver=false;

    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;


    int phi=90;
    int teta=45;
    float dist=45;

    float timeSlow=1.0f/12.0f;
};

#endif // MYGLWIDGET_H
