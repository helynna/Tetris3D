#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <QGraphicsView>
#include "opencv2/opencv.hpp"
#include <QWidget>
#include <QTimer>

//Auteurs : Clément Jarousse


class CameraWidget : public QGraphicsView
{

    Q_OBJECT
public:
    CameraWidget(QWidget* parent=nullptr);

    ~CameraWidget();
signals:
    void rot();
    void acceleration();
    void leftsig();
    void rightsig();

private:
    cv::VideoCapture * capture;
    QTimer timer;
    QGraphicsScene scene;
    cv::CascadeClassifier face_cascade;
    std::vector<cv::Rect> pos_R;
    int compteur=0;
    bool L_H=false;
    bool R_H=false;
    bool accel=false;
    bool rotate=false;

    bool previousL=false;
    bool previousR=false;
    bool previousA=false;
    bool previousRo=false;


};

#endif // CAMERAWIDGET_H
