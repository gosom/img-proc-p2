#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imgloader.h"
#include <qfiledialog.h>
#include "qinputdialog.h"

#include <chrono>
#include <vector>
#include <utility>
#include <fstream>

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
    if(ok)
        gauss.updateKsize(value, true);

}

void MainWindow::on_actionGather_stats_triggered(){
    QImage in = loader.GetImage();
    vector<tuple<int, int>> results;
    for(int i=3; i<15 ; i+=2){
        gauss.updateKsize(i, true);
        int k = 0;
        int s = 0;
        while(k < 8){
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
                                 QString("select value:")
                                 .arg(gauss.getType()),
                                 gauss.getType(), 0, 2, 1, &ok);
    if(ok)
        gauss.setType(value);

}
