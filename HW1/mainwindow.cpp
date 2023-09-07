#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <fstream>
#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>

using namespace std;

int image[64][64]; // the first image
int image_second[64][64]; // the second image

int image_primacy[64][64]; // image currently updated and histogram shown

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
            image_primacy[i][j] = image[i][j];
        }
    }
    cout << "primacy image updated";

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

    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            image_primacy[i][j] = image_second[i][j];
        }
    }
    cout << "primacy image updated";

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
}

