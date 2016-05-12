#-------------------------------------------------
#
# Project created by QtCreator 2016-05-11T16:48:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CG3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    convexhull.cpp \
    segment.cpp \
    point.cpp

HEADERS  += mainwindow.h \
    convexhull.h \
    segment.h \
    point.h

FORMS    += mainwindow.ui
