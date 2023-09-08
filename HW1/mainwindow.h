#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_upload_1_clicked();

    void on_upload_2_clicked();

    void on_horizontalSlider_add_sub_valueChanged(int value);

    void on_horizontalSlider_multiply_valueChanged(int value);

    void on_pushButton_g_func_clicked();

    void on_pushButton_avg_clicked();

    void generate_histogram(int image[64][64]);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
