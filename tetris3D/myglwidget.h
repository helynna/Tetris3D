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

    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent * event);

    //Fonction de gestion d'interactions souris
    void mousePressEvent(QMouseEvent * event);

private:
    // Timer d'animation
    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;

    float timeSlow=1.0f/12.0f;
};

#endif // MYGLWIDGET_H
