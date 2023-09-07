/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *upload_1;
    QGraphicsView *graphicsView_2;
    QPushButton *upload_2;
    QSlider *horizontalSlider_add_sub;
    QSlider *horizontalSlider_mult;
    QPushButton *pushButton_g_func;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QGraphicsView *graphicsView_avg;
    QLabel *label_4;
    QGraphicsView *graphicsView_hist;
    QGraphicsView *graphicsView_1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        upload_1 = new QPushButton(centralwidget);
        upload_1->setObjectName(QString::fromUtf8("upload_1"));
        upload_1->setGeometry(QRect(60, 40, 121, 31));
        graphicsView_2 = new QGraphicsView(centralwidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(220, 80, 121, 121));
        graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        upload_2 = new QPushButton(centralwidget);
        upload_2->setObjectName(QString::fromUtf8("upload_2"));
        upload_2->setGeometry(QRect(220, 40, 121, 31));
        horizontalSlider_add_sub = new QSlider(centralwidget);
        horizontalSlider_add_sub->setObjectName(QString::fromUtf8("horizontalSlider_add_sub"));
        horizontalSlider_add_sub->setGeometry(QRect(60, 230, 121, 16));
        horizontalSlider_add_sub->setOrientation(Qt::Horizontal);
        horizontalSlider_mult = new QSlider(centralwidget);
        horizontalSlider_mult->setObjectName(QString::fromUtf8("horizontalSlider_mult"));
        horizontalSlider_mult->setGeometry(QRect(60, 260, 121, 16));
        horizontalSlider_mult->setOrientation(Qt::Horizontal);
        pushButton_g_func = new QPushButton(centralwidget);
        pushButton_g_func->setObjectName(QString::fromUtf8("pushButton_g_func"));
        pushButton_g_func->setGeometry(QRect(30, 290, 181, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 410, 53, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 220, 31, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 250, 31, 31));
        graphicsView_avg = new QGraphicsView(centralwidget);
        graphicsView_avg->setObjectName(QString::fromUtf8("graphicsView_avg"));
        graphicsView_avg->setGeometry(QRect(420, 80, 121, 121));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(420, 50, 121, 21));
        label_4->setAlignment(Qt::AlignCenter);
        graphicsView_hist = new QGraphicsView(centralwidget);
        graphicsView_hist->setObjectName(QString::fromUtf8("graphicsView_hist"));
        graphicsView_hist->setGeometry(QRect(280, 230, 191, 111));
        graphicsView_1 = new QGraphicsView(centralwidget);
        graphicsView_1->setObjectName(QString::fromUtf8("graphicsView_1"));
        graphicsView_1->setGeometry(QRect(60, 80, 121, 121));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView_1->sizePolicy().hasHeightForWidth());
        graphicsView_1->setSizePolicy(sizePolicy);
        graphicsView_1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        upload_1->setText(QCoreApplication::translate("MainWindow", "Upload (.64)", nullptr));
        upload_2->setText(QCoreApplication::translate("MainWindow", "Upload (.64)", nullptr));
        pushButton_g_func->setText(QCoreApplication::translate("MainWindow", "g(x,y) = f(x,y) - f(x-1,y) ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "- / +", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "   x", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Averaged", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
