#-------------------------------------------------
#
# Project created by QtCreator 2016-09-28T14:58:03
#
#-------------------------------------------------

QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageViewer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    aboutdialog.cpp

HEADERS  += mainwindow.h \
    aboutdialog.h

FORMS    += mainwindow.ui \
    aboutdialog.ui
