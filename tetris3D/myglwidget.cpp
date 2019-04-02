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
    //move(QApplication::desktop()->screen()->rect().center() - rect().center());

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


    //glEnable(GL_LIGHTING);
    //glEnable(GL_TEXTURE_2D);
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
    // Reinitialisation des tampons
    //
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);


    // Definition de la position de la camera
    // ...
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(70,double(width())/height(),1,150);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    /*float x,y,z;
    x=dist*sin(teta*M_PI/180)*cos(phi*M_PI/180);
    y=dist*cos(teta*M_PI/180);
    z=dist*sin(teta*M_PI/180)*sin(phi*M_PI/180);
    gluLookAt(x,y,z,0,0,0,0,1,0);*/

    //gluLookAt(-5,-3,-10,2.5f,1.5f,0,0,1,0);
    gluLookAt(5,-3,10,2.5f,1.5f,0,0,1,0);

    paintLinesGL();




}


void MyGLWidget::paintLinesGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5f,0.5f,0.5f);

    //Tracer les lignes
    for(int j=0;j<=20;j++){
        glBegin(GL_LINE_LOOP);
        glVertex3f(0,j*0.5,0);
        glVertex3f(5,j*0.5,0);
        glEnd();
    }

    //Tracer les colonnes
    for(int i=0;i<=10;i++){
        glBegin(GL_LINE_LOOP);
        glVertex3f(i*0.5,0,0);
        glVertex3f(i*0.5,10,0);
        glEnd();
    }

}

void MyGLWidget::paintCube(float x, float y,int style, int Couleur[8][3])
{
    glBegin(GL_QUADS);
    glColor3f(Couleur[style][0],Couleur[style][1],Couleur[style][2]);
    //Face du dessous
    glVertex3f(x,y,0);
    glVertex3f(x+0.5,y,0);
    glVertex3f(x+0.5,y+0.5,0);
    glVertex3f(x,y+0.5,0);

    //Face du haut
    glVertex3f(x,y,0);
    glVertex3f(x+0.5,y,0);
    glVertex3f(x+0.5,y,0.5);
    glVertex3f(x,y,0.5);

    //Face de droite
    glVertex3f(x+0.5,y,0);
    glVertex3f(x+0.5,+0.5,0);
    glVertex3f(x+0.5,y+0.5,0.5);
    glVertex3f(x+0.5,y,0.5);

    //Face du bas
    glVertex3f(x+0.5,y+0.5,0);
    glVertex3f(x,y+0.5,0);
    glVertex3f(x,y+0.5,0.5);
    glVertex3f(x+0.5,y+0.5,0.5);

    //Face de gauche
    glVertex3f(x,y,0);
    glVertex3f(x,y+0.5,0);
    glVertex3f(x,y+0.5,0.5);
    glVertex3f(x,y,0.5);

    //Face du dessus
    glVertex3f(x,y,0.5);
    glVertex3f(x+0.5,y,0.5);
    glVertex3f(x+0.5,y+0.5,0.5);
    glVertex3f(x,y+0.5,0.5);

    glEnd();

}


void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {
        // Activation/Arret de l'animation
        case Qt::Key_Space:
        {
            if(m_AnimationTimer.isActive())
                m_AnimationTimer.stop();
            else
                m_AnimationTimer.start();

            break;
        }

        // Sortie de l'application
        case Qt::Key_Up:
        case Qt::Key_Z:
            if(teta>1){
            teta--;
            }
            break;

       case Qt::Key_Right:

        break;
       case Qt::Key_D:
            phi++;
           break;

       case Qt::Key_Left:


        break;
       case Qt::Key_Q:
            phi--;
           break;

       case Qt::Key_Down:
       case Qt::Key_S:
           if(teta<179){
           teta++;
           }
           break;
        case Qt::Key_Plus:
            if(timeSlow<10){
            timeSlow=timeSlow+0.01;
            }
        break;

    case Qt::Key_Minus:
        if(timeSlow>0.01){
            timeSlow=timeSlow-0.01;
        }
        break;
        case Qt::Key_U:
             dist=dist+0.5;
            break;

        case Qt::Key_R:
             dist=dist-0.5;
            break;


        case Qt::Key_Escape:
        {
            exit(0);
        }

        // Cas par defaut
        default:
        {
            // Ignorer l'evenement
            event->ignore();
            return;
        }
    }

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
    updateGL();
}


void MyGLWidget::mousePressEvent(QMouseEvent *event)
{

}
