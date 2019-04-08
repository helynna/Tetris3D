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



// Classe dediee a l'affichage d'une scene OpenGL
class MyGLWidget : public QGLWidget
{
    Q_OBJECT

public:
    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);

protected:
    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    //Dessiner la grille de fond
    void paintLinesGL();

    //Dessiner les pieces
    void paintCube(float x, float y,int Couleur[3]);
    //void paintCube(float x, float y,int style, int Couleur[8][3]);
    void paintTetrimino();
    void paintBoard();

    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent * event);
    void mettrePause();




public slots:
    void rotateLeft();
    void rotateRight();
    void goLeft();
    void goRight();
    void goDown();

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
