#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlabel.h>
#include "imgloader.h"
#include "fgaussian.h"
#include "warpsettingsdialog.h"
#include "imgwarp.h"
#include "recursivegaussian.h"
#include "anamorphosisdialog.h"

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

    void on_actionWrap_triggered();
    void on_actionRecursive_Blur_triggered();

    void on_actionBenchmarks_triggered();

    void on_actionAnamorphosis_triggered();

public slots:
    void on_wrap_triggered(warpparams x, warpparams y);
    void on_anamorphosis_triggered(int rmin);

private:
    Ui::MainWindow *ui;
    ImgLoader loader;
    QLabel imgLabel;
    QLabel blurLabel;
    FGaussian gauss;
    RecursiveGaussian recGauss;
    WarpSettingsDialog* settingsDialog;
    AnamorphosisDialog* settingsAnamorphosis;
};

#endif // MAINWINDOW_H
