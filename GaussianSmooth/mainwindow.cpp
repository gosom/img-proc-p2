#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imgloader.h"
#include <qfiledialog.h>
#include "qinputdialog.h"
#include "utils.h"
#include "imgwarp.h"
#include "warpsettingsdialog.h"
#include "cylinderanamorphosis.h"
#include "anamorphosisdialog.h"

#include <chrono>
#include <vector>
#include <utility>
#include <fstream>

#include <QDebug>
using namespace std::chrono;
using std::vector;
using std::tuple;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    imgLabel.setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    blurLabel.setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    settingsDialog = new WarpSettingsDialog(this);
    settingsAnamorphosis = new AnamorphosisDialog(this);

}

void MainWindow::on_actionLoad_Image_triggered(){
    QString fname = QFileDialog::getOpenFileName(this, "Select Image", "",
                                                 "*.png *.jpg");
    loader.load(fname);
    if(loader.isImgLoaded()){
        imgLabel.setPixmap(*loader.GetPixelMap());
        blurLabel.clear();
        ui->scrollAreaImage->setWidget(&imgLabel);
        ui->actionProcess_Image->setEnabled(true);
        ui->actionGather_stats->setEnabled(true);
    } else {
        ui->actionProcess_Image->setEnabled(false);
        ui->actionGather_stats->setEnabled(false);
    }
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_actionProcess_Image_triggered(){

    QImage img = gauss.blur(loader.GetImage());

    blurLabel.setPixmap(QPixmap::fromImage(img));

    ui->scrollAreaBlur->setWidget(&blurLabel);
}

void MainWindow::on_actionSet_kernel_size_triggered(){

    bool ok;
    int value;
    value = QInputDialog::getInt(this, "Kernel size",
                                 QString("Current value: %1")
                                 .arg(gauss.getKernelSize()),
                                 gauss.getKernelSize(), 1, 100, 1, &ok);
    if(ok){
        gauss.updateKsize(value, true);
        recGauss.calculate_coefficients(value);
    }

}

void MainWindow::on_actionGather_stats_triggered(){
    QImage in = loader.GetImage();
    vector<tuple<int, int>> results;
    for(int i=3; i<50 ; i+=2){
        gauss.updateKsize(i, true);
        int k = 0;
        int s = 0;
        while(k < 5){
            auto t0 = high_resolution_clock::now();
            gauss.blur(in);
            auto t1 = high_resolution_clock::now();
            s += duration_cast<milliseconds>(t1 - t0).count();
            ++k;
        }
        tuple<int, int> tmp(i, s / k);
        results.push_back(tmp);
    }
    QString fname = QFileDialog::getSaveFileName(this, "Save results", "", "");
    std::ofstream ofs(fname.toStdString());
    if(ofs){
        for(auto v:results){
            ofs << std::get<0>(v) << "\t" << std::get<1>(v) << "\n";
        }
    }
}

void MainWindow::on_actionWrite_Kernel_triggered(){
    QString fname = QFileDialog::getSaveFileName(this, "Save kernel", "", "");
    std::ofstream ofs(fname.toStdString());
    if(ofs){
        ofs << gauss.str_kernel() << "\n" << gauss.str_kernel1d() << "\n";
        //ofs << gauss.str_pkernel();
    }
}

void MainWindow::on_actionBlur_method_triggered(){
    bool ok;
    int value;
    value = QInputDialog::getInt(this, "Blur method",
                                 QString("select value:"),
                                 gauss.getType(), 0, 2, 1, &ok);
    if(ok)
        gauss.setType(value);

}

void MainWindow::on_actionWrap_triggered()
{
    settingsDialog->show();
}

void MainWindow::on_wrap_triggered(warpparams x, warpparams y){
    qDebug() << "Do some warping" << x.amplitude;
    QImage in = loader.GetImage();

    ImgWarp wrapper(&in, x, y);
    QImage out = wrapper.warp();

    blurLabel.setPixmap(QPixmap::fromImage(out));
    ui->scrollAreaBlur->setWidget(&blurLabel);

}


void MainWindow::on_actionRecursive_Blur_triggered()
{
    cv::Mat img = loader.GetOpenCvImage();
    recGauss.setImg(img);

    cv::Mat conv = recGauss.gaussian_conv();

    QImage out = mat2qimage(conv);

    blurLabel.setPixmap(QPixmap::fromImage(out));
    ui->scrollAreaBlur->setWidget(&blurLabel);
}

void MainWindow::on_actionBenchmarks_triggered()
{
    qDebug() << "Running benchmarks";
    QImage in = loader.GetImage();
    cv::Mat img = loader.GetOpenCvImage();
    recGauss.setImg(img);
    vector<tuple<double, double, double>> results;
    for(int i=3; i<50 ; i+=2){
        recGauss.calculate_coefficients(i);
        gauss.updateKsize(i, true);
        int k = 0;
        int sr = 0;
        int sf = 0;
        while(k < 100){
            // recursive
            auto t0 = high_resolution_clock::now();
            recGauss.gaussian_conv();
            auto t1 = high_resolution_clock::now();
            sr += duration_cast<milliseconds>(t1 - t0).count();
            //gauss
            t0 = high_resolution_clock::now();
            gauss.blur(in);
            t1 = high_resolution_clock::now();
            sf += duration_cast<milliseconds>(t1 - t0).count();
            ++k;
        }
        double sigma = gauss.get_sigma();
        tuple<double, double, double> tmp(sigma, sr / k, sf / k);
        results.push_back(tmp);
    }
    QString fname = QFileDialog::getSaveFileName(this, "Save results", "", "");
    std::ofstream ofs(fname.toStdString());
    if(ofs){
        for(auto v:results){
            ofs << std::get<0>(v) << "\t" << std::get<1>(v) << "\t";
            ofs << std::get<2>(v) << std::endl;
        }
    }


}

void MainWindow::on_actionAnamorphosis_triggered()
{
    settingsAnamorphosis->show();
}

void MainWindow::on_anamorphosis_triggered(int rmin){
    CylinderAnamorphosis ca(loader.GetImage(), rmin);

    QImage out = ca.get_anamorphosis();

    blurLabel.setPixmap(QPixmap::fromImage(out));
    ui->scrollAreaBlur->setWidget(&blurLabel);
}
