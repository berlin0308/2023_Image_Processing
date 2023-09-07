//**************************************************************************
//
// A demonstration program to open *.64 image and show its histogram
//
// Date: 2016/09/28
//
// Author: Ta-Te Lin, Department of Bio-Industrial Mechatronics Engineering
//                    National Taiwan University
//
// Version: 1.0
//
//**************************************************************************

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//
// Close the window and exit the program
//
void MainWindow::on_actionExit_triggered()
{
    close();
}

//
// Open a *.64 image file and show it on the screen
//
void MainWindow::on_actionOpen_triggered()
{
    char a;
    int i,j;

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
          for(i=0; i<64; i++)
          {
              for(j=0; j<64; j++)
              {
                  // Get the character and convert it to integer ranging from 0 to 255
                  image[i][j] = imagefile.get();
                  // cout <<image[i][j]; // Use this line to check if the input is correct

                  if( (image[i][j] >= '0') && (image[i][j] <= '9') )
                  {
                    image[i][j] = (image[i][j]-'0');
                  }
                  else
                  {
                    image[i][j] = ((image[i][j]-'A') + 10);
                  }
              }
              a = imagefile.get();  // Discard the end of line character
              cout << a;  // Use this line to check if the input is correct
          }
          imagefile.close();
        }

        // Set up QImage for displaying it in the QLabel label

        QImage img(64, 64, QImage::Format_RGB32);
        for(i=0;i<64;i++)
        {
            for(j=0;j<64;j++)
            {
                // Set the pixel value of the QImage
                img.setPixel(j,i,qRgb(image[i][j]*8,image[i][j]*8,image[i][j]*8));
            }
        }

        // Display QImage on the label
        ui->label->setPixmap(QPixmap::fromImage(img));
        // Resize the QImage to fit the label display
        QImage imgResize = img.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio);
        ui->label->setPixmap(QPixmap::fromImage(imgResize));


        // Calculate the histogram of the 64x64 image;
        for( i=0; i<32; i++ ) histogram[i] = 0;	/* Initialize the array */
        for(i=0; i<64; i++)
        {
            for(j=0; j<64; j++)
            {
                histogram[ image[i][j] ]++;
            }
        }


        // Use QChart to display the image histogram

        QBarSet *set0 = new QBarSet("Histogram");

        for(i=0;i<32;i++)
            *set0 << histogram[i];

        QBarSeries *series = new QBarSeries();
        series->append(set0);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Histogram");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->legend()->setVisible(false);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        while(!ui->horizontalLayout->isEmpty())
        {
            // Clear the horizontal layout content if there is any
            ui->horizontalLayout->removeItem(ui->horizontalLayout->itemAt(0));
        }
        ui->horizontalLayout->addWidget(chartView);

   }
}

//
//  Message to show the basic information of this program
//
void MainWindow::on_actionAbout_triggered()
{
    AboutDialog aboutbox;
    aboutbox.setModal(true);
    aboutbox.exec();
}
