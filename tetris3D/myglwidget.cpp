#define _USE_MATH_DEFINES

#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <cmath>
#include <random>




// Declarations des constantes
const unsigned int WIN_WIDTH  = 1600;
const unsigned int WIN_HEIGHT = 900;
const float MAX_DIMENSION     = 50.0f;


// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    // Connexion du timer
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += timeSlow;
        updateGL();
    });

    m_AnimationTimer.setInterval(10);
    m_AnimationTimer.start();

}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

    // Activation du zbuffer
    //
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
}

void MyGLWidget::resizeGL(int widthW, int heightW)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, widthW, heightW);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(widthW != 0)
         gluPerspective(70,double(width())/height(),1,150);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void MyGLWidget::paintGL()
{

}


void MyGLWidget::keyPressEvent(QKeyEvent * event)
{

}


void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
