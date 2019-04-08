#-------------------------------------------------
#
# Project created by QtCreator 2019-03-06T14:04:38
#
#-------------------------------------------------

QT       += core gui opengl widgets
QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tetris3D
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH +=$$(OPENCV_DIR)\..\..\include


CONFIG += c++11
CONFIG   += console
CONFIG   -= app_bundle

SOURCES += \
        main.cpp \
    piece.cpp \
    grille.cpp \
    piececarre.cpp \
    piecebaton.cpp \
    piecelambda.cpp \
    piecel_inverse.cpp \
    piecebiais.cpp \
    piecebiais_inverse.cpp \
    piecet_bloc.cpp \
    jeu.cpp \
    myglwidget.cpp \
    camerawidget.cpp \
    mainwindow.cpp

HEADERS += \
    piece.h \
    grille.h \
    piececarre.h \
    piecebaton.h \
    piecelambda.h \
    piecel_inverse.h \
    piecebiais.h \
    piecebiais_inverse.h \
    piecet_bloc.h \
    jeu.h \
    myglwidget.h \
    camerawidget.h \
    mainwindow.h

FORMS += \
    mainwindow.ui


LIBS += -L$$(OPENCV_DIR)\lib \
    -lopencv_core2413 \
    -lopencv_highgui2413 \
    -lopencv_imgproc2413 \
    -lopencv_features2d2413 \
    -lopencv_calib3d2413 \
    -lopencv_objdetect2413


win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
        DEFINES  += _WIN32
    } else {
        LIBS     += -lopengl32 -lglu32
    }
}
unix:!macx {
        LIBS     += -lGL -lGLU
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
