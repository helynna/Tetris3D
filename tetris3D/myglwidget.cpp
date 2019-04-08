#define _USE_MATH_DEFINES

#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <cmath>
#include <random>
#include "camerawidget.h"



// Declarations des constantes
const unsigned int WIN_WIDTH  = 400;
const unsigned int WIN_HEIGHT = 400;
const float MAX_DIMENSION     = 50.0f;


// Constructeur
MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Reglage de la taille/position
   // setFixedSize(WIN_WIDTH, WIN_HEIGHT);
    //move(QApplication::desktop()->screen()->rect().center() - rect().center());

    // Connexion du timer
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1;
        game->faireDescendre();
        updateGL();
    });



    m_AnimationTimer.setInterval(1000);
    m_AnimationTimer.start();
    game = new Jeu();

}


// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

    // Activation du zbuffer
    //
    glEnable(GL_DEPTH_TEST);


    // Reglage de la lampe
    //
    /*glEnable(GL_LIGHT0);

    GLfloat CouleurLumiere[]={0.5,0.5,0.5,1.0};
    //glMaterialfv(GL_FRONT, GL_EMISSION, CouleurLumiere);

    GLfloat light_tab[] = {5,-3,10,1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_tab);

    GLfloat colorAmbiante_tab[]={1.0,1.0,0.5,1.0};
    glLightfv(GL_LIGHT0,GL_AMBIENT, colorAmbiante_tab);



    //Activation de la lumière
    glEnable(GL_LIGHTING);*/

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
    //gluLookAt(-2,-3,2,2.5f,1.5f,0,0,1,0);
    //gluLookAt(-3,-3,1,2.5f,1.5f,0,0,1,0);
    gluLookAt(5,-3,10,2.5f,1.5f,0,0,1,0);

    paintLinesGL();
    paintBoard();

    paintTetrimino();

    glColor3f(1,1,1);

    renderText(30, 60, QString::number(game->compterPoints()),QFont ("Arial", 60));

    if(game->testerGameOver()){
        QString score;
        score.append("You scored ");
        score.append(QString::number(game->compterPoints()));
        score.append(" points.");

        renderText(width()/2-width()/10,height()/2-50,"Game Over !",QFont ("Arial", 50));
        renderText(width()/2-width()/5,height()/2+25,score,QFont ("Arial", 50));
        renderText(width()/2-width()/3,height()/2+100,"You can replay using N on the keyboard. ",QFont ("Arial", 30));

    }

}


void MyGLWidget::paintLinesGL()
{
    //glDisable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5f,0.5f,0.5f);

    //Tracer les lignes
    for(int j=0;j<=20;j++){
        glBegin(GL_LINE_LOOP);
        glVertex3f(0,j*0.5f,0);
        glVertex3f(5,j*0.5f,0);
        glEnd();
    }

    //Tracer les colonnes
    for(int i=0;i<=10;i++){
        glBegin(GL_LINE_LOOP);
        glVertex3f(i*0.5f,0,0);
        glVertex3f(i*0.5f,10,0);
        glEnd();
    }

}

void MyGLWidget::paintCube(float x, float y,int Couleur[3])
//void MyGLWidget::paintCube(float x, float y,int style, int Couleur[8][3])
{
    std::vector<float> Color;
    std::vector<float> ColorOmbre;
    std::vector<float> ColorOmbreTotale;
    Color.push_back(Couleur[0]/255);
    Color.push_back(Couleur[1]/255);
    Color.push_back(Couleur[2]/255);

/*
    ColorOmbre.push_back(Couleur[0]-50/255);
    ColorOmbre.push_back(Couleur[1]-50/255);
    ColorOmbre.push_back(Couleur[2]-50/255);


    ColorOmbreTotale.push_back(Couleur[0]-100/255);
    ColorOmbreTotale.push_back(Couleur[1]-100/255);
    ColorOmbreTotale.push_back(Couleur[2]-100/255);*/

    //glEnable(GL_LIGHTING);
    x /= 2;
    y /= 2;

    //glColor3ub(Couleur[0],Couleur[1],Couleur[2]);
    glBegin(GL_QUADS);
    //glMaterialfv(GL_FRONT, GL_AMBIENT, Color.data());
    //glMaterialfv(GL_FRONT, GL_DIFFUSE, Color.data());
    //Face du dessous
    glColor3ub(Couleur[0]-100*(Couleur[0]/255),Couleur[1]-100*(Couleur[1]/255),Couleur[2]-100*(Couleur[2]/255));
    glNormal3f(x+0.25f,y+0.25f,-0.5);

    glVertex3f(x,y,0);
    glVertex3f(x+0.5f,y,0);
    glVertex3f(x+0.5f,y+0.5f,0);
    glVertex3f(x,y+0.5f,0);

    //Face du haut
    glColor3ub(Couleur[0]-50*(Couleur[0]/255),Couleur[1]-50*(Couleur[1]/255),Couleur[2]-50*(Couleur[2]/255));
    glNormal3f(x+0.25f,y-0.5f,0.25);

    glVertex3f(x,y,0);
    glVertex3f(x+0.5f,y,0);
    glVertex3f(x+0.5f,y,0.5);
    glVertex3f(x,y,0.5);

    //Face de droite
    glColor3ub(Couleur[0]-50*(Couleur[0]/255),Couleur[1]-50*(Couleur[1]/255),Couleur[2]-50*(Couleur[2]/255));
    glNormal3f(x+0.75f,y+0.25f,0.25);

    glVertex3f(x+0.5f,y,0);
    glVertex3f(x+0.5f,y+0.5f,0);
    glVertex3f(x+0.5f,y+0.5f,0.5);
    glVertex3f(x+0.5f,y,0.5);

    //Face du bas
    glColor3ub(Couleur[0]-50*(Couleur[0]/255),Couleur[1]-50*(Couleur[1]/255),Couleur[2]-50*(Couleur[2]/255));
    glNormal3f(x+0.25f,y+0.75f,0.25);

    glVertex3f(x+0.5f,y+0.5f,0);
    glVertex3f(x,y+0.5f,0);
    glVertex3f(x,y+0.5f,0.5);
    glVertex3f(x+0.5f,y+0.5f,0.5);

    //Face de gauche
   glColor3ub(Couleur[0]-50*(Couleur[0]/255),Couleur[1]-50*(Couleur[1]/255),Couleur[2]-50*(Couleur[2]/255));
    glNormal3f(x-0.5f,y+0.25f,0.25);

    glVertex3f(x,y,0);
    glVertex3f(x,y+0.5f,0);
    glVertex3f(x,y+0.5f,0.5);
    glVertex3f(x,y,0.5);

    //Face du dessus
    glColor3ub(Couleur[0],Couleur[1],Couleur[2]);
    glNormal3f(x+0.25f,y+0.25f,1);

    glVertex3f(x,y,0.5);
    glVertex3f(x+0.5f,y,0.5);
    glVertex3f(x+0.5f,y+0.5f,0.5);
    glVertex3f(x,y+0.5f,0.5);

    glEnd();

}

void MyGLWidget::paintTetrimino()
{
    //glEnable(GL_LIGHTING);
    int Couleur[3]={};
    std::vector<std::vector<int>> shape;
    int pos[2]={};
    game->getCouleur(Couleur,game->getTypeShapeTetrimino());
    game->getActualShapeTetrimino(shape);
    game->getPosTetrimino(pos);

    for(int i=0;i<shape.size();i++){
        for(int j=0;j<shape.front().size();j++){
            if(shape[i][j]==1){
                paintCube(pos[0]+i,20 -pos[1]-j,Couleur);//Si j'ai une erreur d'affichage, c'est ici qu'elle va être à cause du double vector
            }

        }
    }


}

void MyGLWidget::paintBoard()
{
    //glEnable(GL_LIGHTING);
    int indice=-1;
    int Couleur[3]={};
    for(int i=19;i>=0;i--){
        for(int j=9;j>=0;j--){

            if(game->doSumLine(i)!=70){
                indice=game->getIndiceInGrille(j,i);
                if(indice!=7){
                    game->getCouleur(Couleur,indice);
                    paintCube(j,19- i,Couleur);

                }
            }
        }
    }

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

        case Qt::Key_Z:
            if(teta>1){
            teta--;
            }
            break;

        case Qt::Key_Q:
              phi--;
             break;


        case Qt::Key_S:
            if(teta<179){
            teta++;
            }
            break;

        case Qt::Key_D:
            phi++;
         break;


       case Qt::Key_Right:
            goRight();
        break;

        case Qt::Key_Down:
            goDown();
         break;

        case Qt::Key_Left:
             goLeft();
         break;

        case Qt::Key_A:
             rotateLeft();
         break;

        case Qt::Key_P:
             rotateRight();
         break;



    case Qt::Key_N:

        if(game->testerGameOver()){
            delete(game);
            game = new Jeu();
        }
        break;



        case Qt::Key_Plus:
            if(timeSlow<10){
            timeSlow=timeSlow+0.01f;
            }
        break;

    case Qt::Key_Minus:
        if(timeSlow>0.01f){
            timeSlow=timeSlow-0.01f;
        }
        break;
        case Qt::Key_U:
             dist=dist+0.5f;
            break;

        case Qt::Key_R:
             dist=dist-0.5f;
            break;


        case Qt::Key_Escape:
        {
            mettrePause();
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

void MyGLWidget::mettrePause()
{
    exit(0);
}


void MyGLWidget::rotateLeft()
{
    game->tournerPieceGauche();
}

void MyGLWidget::rotateRight()
{
    game->tournerPieceDroite();
}

void MyGLWidget::goLeft()
{
    game->allerAGauche();
}

void MyGLWidget::goRight()
{
    game->allerADroite();
}

void MyGLWidget::goDown()
{
    game->faireDescendre();
}
