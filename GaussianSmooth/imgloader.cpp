#include "imgloader.h"
#include <qmessagebox.h>
#include <opencv2/opencv.hpp>

ImgLoader::ImgLoader(){
    pixelMap = new QPixmap;
    loaded = false;
}

ImgLoader::~ImgLoader(){
    if(pixelMap != nullptr)
        delete pixelMap;
}

void ImgLoader::load(const QString& path){

    matInput = cv::imread(path.toStdString(), CV_LOAD_IMAGE_GRAYSCALE);

    if(pixelMap->load(path))
        loaded = true;
    else{
        QMessageBox::critical(0, "Failed to load image", path);
        loaded = false;
    }
}

