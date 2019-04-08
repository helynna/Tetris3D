#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->graphicsView, SIGNAL(rot()),ui->openGLWidget,SLOT(rotateLeft()));
    connect(ui->graphicsView, SIGNAL(acceleration()),ui->openGLWidget,SLOT(goLeft()));
    connect(ui->graphicsView, SIGNAL(leftsig()),ui->openGLWidget,SLOT(goRight()));
    connect(ui->graphicsView, SIGNAL(rightsig()),ui->openGLWidget,SLOT(goDown()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
