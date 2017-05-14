#-------------------------------------------------
#
# Project created by QtCreator 2017-04-27T21:30:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = imgtool
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filtromedianas.cpp \
    medianfilter.cpp

HEADERS  += mainwindow.h \
    filtromedianas.h \
    medianfilter.h

FORMS    += mainwindow.ui \
    medianfilter.ui

INCLUDEPATH += /usr/include/opencv2/
LIBS += -L/usr/lib64/ -lopencv_core  -lopencv_highgui -lopencv_imgproc
