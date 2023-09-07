#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <fstream>
#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QString>
#include <math.h>
#include <QtWidgets/QApplication>
//#include <QtCharts/QBarSet>
//#include <QtCharts/QBarSeries>
//#include <QtCharts/QChart>
//#include <QtCharts/QChartView>
//#include <QtWidgets/QMainWindow>
//#include <QtWidgets/QHBoxLayout>
using namespace std;


int image[64][64]; // the first image
int image_processed[64][64]; // processed first image
int image_g[64][64];
int image_second[64][64]; // the second image
int image_avg[64][64]; // averaged image

QString image_primacy = "default"; // image currently updated and histogram shown

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_avg->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_upload_1_clicked()
{
    // Open file dialog to get the file name
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), ".",
                                                   tr("Image Files (*.64)"));

    // Read the .64 text file and convert the characters into image array
    if(fileName != NULL)
    {
        ifstream imagefile;
        imagefile.open(fileName.toStdString());


        if (imagefile.is_open())
        {
            for(int i=0; i<64; i++)
            {
                for(int j=0; j<64; j++)
                {
                    // Get the character and convert it to integer ranging from 0 to 31
                    image[i][j] = imagefile.get();

                    if( (image[i][j] >= '0') && (image[i][j] <= '9') )
                    {
                        image[i][j] = (image[i][j]-'0');
                    }
                    else
                    {
                        image[i][j] = ((image[i][j]-'A') + 10);
                    }
                }
                int a = imagefile.get();  // Discard the end of line character
                //cout << a;  // Use this line to check if the input is correct
            }
            imagefile.close();
        }
    }

    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            image_processed[i][j] = image[i][j];
        }
    }



    QImage img(64, 64, QImage::Format_RGB32);
    for(int i=0;i<64;i++)
    {
        for(int j=0;j<64;j++)
        {
            // Set the pixel value of the QImage
            img.setPixel(j,i,qRgb(image[i][j]*8,image[i][j]*8,image[i][j]*8));
        }
    }


    QGraphicsView &view = *ui->graphicsView_1;
    QGraphicsScene &scene = *new QGraphicsScene(&view);

    QImage imgResize = img.scaled(ui->graphicsView_1->width(),ui->graphicsView_1->height(),Qt::KeepAspectRatio);
    QPixmap pix = QPixmap::fromImage(imgResize);
    scene.addItem(new QGraphicsPixmapItem(pix));

    view.setScene(&scene);
    view.setSceneRect(pix.rect());
    view.show();

    image_primacy = "first";
    generate_histogram(image);
}


void MainWindow::on_upload_2_clicked()
{
    // Open file dialog to get the file name
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), ".",
                                                    tr("Image Files (*.64)"));

    // Read the .64 text file and convert the characters into image array
    if(fileName != NULL)
    {
        ifstream imagefile;
        imagefile.open(fileName.toStdString());


        if (imagefile.is_open())
        {
            for(int i=0; i<64; i++)
            {
                for(int j=0; j<64; j++)
                {
                    // Get the character and convert it to integer ranging from 0 to 31
                    image_second[i][j] = imagefile.get();

                    if( (image_second[i][j] >= '0') && (image_second[i][j] <= '9') )
                    {
                        image_second[i][j] = (image_second[i][j]-'0');
                    }
                    else
                    {
                        image_second[i][j] = ((image_second[i][j]-'A') + 10);
                    }
                }
                int a = imagefile.get();  // Discard the end of line character
                //cout << a;  // Use this line to check if the input is correct
            }
            imagefile.close();
        }
    }


    QImage img(64, 64, QImage::Format_RGB32);
    for(int i=0;i<64;i++)
    {
        for(int j=0;j<64;j++)
        {
            // Set the pixel value of the QImage
            img.setPixel(j,i,qRgb(image_second[i][j]*8,image_second[i][j]*8,image_second[i][j]*8));
        }
    }

    QGraphicsView &view = *ui->graphicsView_2;
    QGraphicsScene &scene = *new QGraphicsScene(&view);

    QImage imgResize = img.scaled(ui->graphicsView_2->width(),ui->graphicsView_2->height(),Qt::KeepAspectRatio);
    QPixmap pix = QPixmap::fromImage(imgResize);
    scene.addItem(new QGraphicsPixmapItem(pix));

    view.setScene(&scene);
    view.setSceneRect(pix.rect());
    view.show();

    image_primacy = "second";
    ui->pushButton_avg->setEnabled(true);

}


void MainWindow::on_horizontalSlider_add_sub_valueChanged(int value)
{
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            image_processed[i][j] = max(min(image[i][j] + value, 31),0);
        }
    }

    QImage img(64, 64, QImage::Format_RGB32);
    for(int i=0;i<64;i++)
    {
        for(int j=0;j<64;j++)
        {
            img.setPixel(j,i,qRgb(image_processed[i][j]*8,image_processed[i][j]*8,image_processed[i][j]*8));
        }
    }

    QGraphicsView &view = *ui->graphicsView_1;
    QGraphicsScene &scene = *new QGraphicsScene(&view);

    QImage imgResize = img.scaled(ui->graphicsView_1->width(),ui->graphicsView_1->height(),Qt::KeepAspectRatio);
    QPixmap pix = QPixmap::fromImage(imgResize);
    scene.addItem(new QGraphicsPixmapItem(pix));

    view.setScene(&scene);
    view.setSceneRect(pix.rect());
    view.show();

    image_primacy = "first";
}


void MainWindow::on_horizontalSlider_multiply_valueChanged(int value)
{
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            image_processed[i][j] = min((image[i][j]*(value/10.0)), 31.0);
        }
    }

    QImage img(64, 64, QImage::Format_RGB32);
    for(int i=0;i<64;i++)
    {
        for(int j=0;j<64;j++)
        {
            img.setPixel(j,i,qRgb(image_processed[i][j]*8,image_processed[i][j]*8,image_processed[i][j]*8));
        }
    }

    QGraphicsView &view = *ui->graphicsView_1;
    QGraphicsScene &scene = *new QGraphicsScene(&view);

    QImage imgResize = img.scaled(ui->graphicsView_1->width(),ui->graphicsView_1->height(),Qt::KeepAspectRatio);
    QPixmap pix = QPixmap::fromImage(imgResize);
    scene.addItem(new QGraphicsPixmapItem(pix));

    view.setScene(&scene);
    view.setSceneRect(pix.rect());
    view.show();

    image_primacy = "first";
}


void MainWindow::on_pushButton_g_func_clicked()
{

    for (int i = 1; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            image_g[i][j] = abs(image[i][j] - image[i-1][j]);
        }
    }

    QImage img(64, 64, QImage::Format_RGB32);
    for(int i=0;i<64;i++)
    {
        for(int j=0;j<64;j++)
        {
            img.setPixel(j,i,qRgb(image_g[i][j]*8,image_g[i][j]*8,image_g[i][j]*8));
        }
    }

    QGraphicsView &view = *ui->graphicsView_1;
    QGraphicsScene &scene = *new QGraphicsScene(&view);

    QImage imgResize = img.scaled(ui->graphicsView_1->width(),ui->graphicsView_1->height(),Qt::KeepAspectRatio);
    QPixmap pix = QPixmap::fromImage(imgResize);
    scene.addItem(new QGraphicsPixmapItem(pix));

    view.setScene(&scene);
    view.setSceneRect(pix.rect());
    view.show();

    image_primacy = "first";
}


void MainWindow::on_pushButton_avg_clicked()
{
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            image_avg[i][j] = (image[i][j] + image_second[i][j]) / 2 ;
        }
    }

    QImage img(64, 64, QImage::Format_RGB32);
    for(int i=0;i<64;i++)
    {
        for(int j=0;j<64;j++)
        {
            img.setPixel(j,i,qRgb(image_avg[i][j]*8,image_avg[i][j]*8,image_avg[i][j]*8));
        }
    }

    QGraphicsView &view = *ui->graphicsView_avg;
    QGraphicsScene &scene = *new QGraphicsScene(&view);

    QImage imgResize = img.scaled(ui->graphicsView_1->width(),ui->graphicsView_1->height(),Qt::KeepAspectRatio);
    QPixmap pix = QPixmap::fromImage(imgResize);
    scene.addItem(new QGraphicsPixmapItem(pix));

    view.setScene(&scene);
    view.setSceneRect(pix.rect());
    view.show();

    image_primacy = "avg";
}

void MainWindow::generate_histogram(int image[64][64]){

    cout << "generating histogram" << endl;

    int occurrence[32] = {0};
    for(int i=0;i<64;i++)
    {
        for(int j=0;j<64;j++)
        {
//            cout <<image[i][j]<<" ";
            occurrence[image[i][j]]++;
        }
    }

    for (const int& element : occurrence) {
        std::cout << element << " ";
    }

//    QBarSet *set0 = new QBarSet("Histogram");

//    for(i=0;i<32;i++)
//        *set0 << histogram[i];

//    QBarSeries *series = new QBarSeries();
//    series->append(set0);

//    QChart *chart = new QChart();
//    chart->addSeries(series);
//    chart->setTitle("Histogram");
//    chart->setAnimationOptions(QChart::SeriesAnimations);
//    chart->legend()->setVisible(false);
//    chart->legend()->setAlignment(Qt::AlignBottom);

//    QChartView *chartView = new QChartView(chart);
//    chartView->setRenderHint(QPainter::Antialiasing);

//    while(!ui->horizontalLayout->isEmpty())
//    {
//        // Clear the horizontal layout content if there is any
//        ui->horizontalLayout->removeItem(ui->horizontalLayout->itemAt(0));
//    }
//    ui->horizontalLayout->addWidget(chartView);



}
