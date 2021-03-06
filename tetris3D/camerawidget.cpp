#include "camerawidget.h"
#include <cstdio>
#include <iostream>
#include <QDebug>
#include "myglwidget.h"
using namespace cv;
using namespace std;

CameraWidget::CameraWidget(QWidget* parent):QGraphicsView(parent), capture{new VideoCapture(0)}
{
    if( !face_cascade.load( "C:/Users/Clement/Tetris3D/tetris3D/fistCascade.xml" ) )
    {
        cerr<<"Error loading haarcascade"<<endl;
        throw -1;
    }

    setScene(&scene);

    connect(&timer, &QTimer::timeout, [this]{
        if (capture->isOpened()) {
            Mat image;
            if (capture->read(image)) {   // Capture a frame
                // Flip to get a mirror effect
                flip(image,image,1);
                // Invert Blue and Red color channels
                cvtColor(image,image,CV_BGR2RGB);
                // Convert to Qt image
                QImage img= QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
                scene.clear();
                scene.addPixmap(QPixmap::fromImage(img));


                    Mat frame_gray;
                    std::vector<Rect> fists;
                    // Convert to gray
                    cv::cvtColor(image,frame_gray,COLOR_BGR2GRAY);
                    // Equalize graylevels
            //        equalizeHist( frame_gray, frame_gray );
                    //-- Detect fists
                    face_cascade.detectMultiScale( frame_gray, fists, 1.1, 4, 0|CV_HAAR_SCALE_IMAGE, Size(60, 60) );
                    if (fists.size()>0)
                    {
                        float min=5000;
                        float max=0;
                        Rect left;
                        Rect Right;
                        // Draw green rectangle
                        for (Rect r: fists)
                        {
                            scene.addRect(r.x,r.y,r.width,r.height);
                            if (r.x<min && r.x<width()/2)
                            {
                                min=r.x;
                                left=r;
                            }
                            if(r.x>max && r.x>width()/2)
                            {
                                Right=r;
                                max=r.x;
                            }
                        }
                        if (pos_R.empty())
                        {
                            pos_R.push_back(left);
                            pos_R.push_back(Right);

                        }

                       else
                        {
                            if (fists.size()<2)
                             {
                                if (compteur>5)
                                {
                                    if(  abs(pos_R[0].x-fists[0].x)<abs(pos_R[1].x-fists[0].x))
                                    {
                                        compteur=0;
                                         pos_R[0]=left;
                                    }
                                    else
                                    {
                                         pos_R[1]=Right;
                                         compteur=0;
                                    }
                                }
                             }

                             else
                            {
                                if (compteur>3)
                                 {

                                         pos_R[0]=left;
                                         pos_R[1]=Right;
                                         compteur=0;
                                        // qDebug()<<pos_R[0].x;
                                        // qDebug()<<pos_R[0].y;
                                        // qDebug()<<pos_R[1].x;
                                         //qDebug()<<pos_R[1].y;

                                 }
                             }

                            if (pos_R[0].y>pos_R[1].y+pos_R[0].height/2)
                                L_H=true;
                            else
                                L_H=false;
                            if (pos_R[1].y>pos_R[0].y+pos_R[1].height/2)
                                R_H=true;
                            else
                                R_H=false;
                            if (pos_R[1].y>270 && pos_R[0].y>270)
                                accel=true;
                            else
                                accel=false;
                            if (abs(pos_R[0].x-pos_R[1].x)<pos_R[0].width+pos_R[1].width)
                                rotate=true;
                            else
                                rotate=false;

                            if (previousL)
                            {
                                previousL=L_H;
                            }
                            else
                            {
                                if (L_H)
                                {
                                    emit leftsig();
                                    previousL=L_H;
                                }
                            }

                            if (previousR)
                            {
                                previousR=R_H;
                            }
                            else
                            {
                                if (R_H)
                                {
                                    emit rightsig();
                                    previousR=R_H;
                                }
                            }

                            if (previousA)
                            {
                                previousA=accel;
                            }
                            else
                            {
                                if (accel)
                                {
                                    emit acceleration();
                                    previousA=accel;
                                }
                            }
                            if (previousRo)
                            {
                                previousRo=rotate;
                            }
                            else
                            {
                                if (rotate)
                                {
                                    emit rot();
                                    previousRo=rotate;
                                }
                            }


                        }


                    }


                    compteur++;
                  //  qdebug<<left.x;

                update();


            }
        }
    });

    if(capture->isOpened())
    {
        timer.setInterval(1000 / 60);
        timer.start();
    }
}

CameraWidget::~CameraWidget()
{
    delete capture;
}


void CameraWidget::keyPressEvent(QKeyEvent * event)
{
     switch(event->key())
     { case Qt::Key_N:
        emit newgame();
         break;}
}
