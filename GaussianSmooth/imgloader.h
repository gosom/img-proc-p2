#ifndef IMGLOADER_H
#define IMGLOADER_H

#include <qimage.h>
#include <qpixmap.h>
#include <opencv2/opencv.hpp>

class ImgLoader{
public:
    ImgLoader();
    ~ImgLoader();

    void load(const QString& path);
    bool isImgLoaded() const { return loaded; }
    QImage GetImage() const { return pixelMap->toImage(); }
    QPixmap* GetPixelMap() const {return pixelMap;}
    cv::Mat GetOpenCvImage() const { return matInput; }

private:
    QPixmap *pixelMap;
    cv::Mat matInput;
    bool loaded;


};
#endif // IMGLOADER_H
