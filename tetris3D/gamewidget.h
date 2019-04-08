#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QOpenGLWidget>
#include <QTimer>
//#include "grille.h"

class GameWidget : public QOpenGLWidget
{
public:
    GameWidget(QWidget* parent=nullptr);
};

#endif // GAMEWIDGET_H
