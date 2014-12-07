#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlabel.h>
#include "imgloader.h"
#include "fgaussian.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionLoad_Image_triggered();
    void on_actionProcess_Image_triggered();

    void on_actionSet_kernel_size_triggered();

    void on_actionGather_stats_triggered();

    void on_actionWrite_Kernel_triggered();

    void on_actionBlur_method_triggered();

private:
    Ui::MainWindow *ui;
    ImgLoader loader;
    QLabel imgLabel;
    QLabel blurLabel;
    FGaussian gauss;
};

#endif // MAINWINDOW_H
