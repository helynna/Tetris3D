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

};

#endif // CAMERAWIDGET_H
