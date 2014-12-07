#include "imgloader.h"

#include <qmessagebox.h>


ImgLoader::ImgLoader(){
    pixelMap = new QPixmap;
    loaded = false;
}

ImgLoader::~ImgLoader(){
    if(pixelMap != nullptr)
        delete pixelMap;
}

void ImgLoader::load(const QString& path){
    if(pixelMap->load(path))
        loaded = true;
    else{
        QMessageBox::critical(0, "Failed to load image", path);
        loaded = false;
    }
}

