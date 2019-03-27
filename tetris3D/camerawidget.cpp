#include "camerawidget.h"
#include <cstdio>
#include <iostream>

using namespace cv;
using namespace std;

CameraWidget::CameraWidget(QWidget* parent):QGraphicsView(parent), capture{new VideoCapture(0)}
{
    if( !face_cascade.load( "C:/Users/Clement/Downloads/TestDetectMultiScale/TestDetectMultiScale/fist.xml" ) )
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
                        // Draw green rectangle
                        for (Rect r: fists)
                        {
                            scene.addRect(r.x,r.y,r.width,r.height);

                        }

                        if (fists.size()<2)
                        {
                           if (!pos_R.empty()&&compteur>5)
                           {
                               if( pos_R[0].x-fists[0].x<fist[0].width)
                               {
                                   compteur=0;
                                    pos_R[0]=fists[0];
                               }
                               if (pos_R[1].x-fists[0].x<fist[0].width)
                               {
                                    pos_R[1]=fists[0];
                                    compteur=0;
                               }
                           }
                        }
                        else
                        {
                            if (compteur>5)
                            {
                                pos_R=fists;
                                compteur=0;
                            }
                        }

                    }

                    compteur++;



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

