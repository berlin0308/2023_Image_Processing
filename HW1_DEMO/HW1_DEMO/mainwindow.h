#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

using namespace QtCharts;
using namespace std;

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QDialog aboutbox;

    unsigned char image[64][64];  // Array to store a 64x64 image
    int histogram[32];            // Array to store the histogram of the 64x64 image (32 gray scales)

private slots:
    void on_actionExit_triggered();

    void on_actionOpen_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
