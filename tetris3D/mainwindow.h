#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//Auteurs :Clément Jarousse


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
