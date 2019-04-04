#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <QGraphicsView>
#include "opencv2/opencv.hpp"
#include <QWidget>
#include <QTimer>

class CameraWidget : public QGraphicsView
{
public:
    CameraWidget(QWidget* parent=nullptr);

    ~CameraWidget();

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

};

#endif // CAMERAWIDGET_H