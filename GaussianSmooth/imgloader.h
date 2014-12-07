#ifndef IMGLOADER_H
#define IMGLOADER_H

#include <qimage.h>
#include <qpixmap.h>

class ImgLoader{
public:
    ImgLoader();
    ~ImgLoader();

    void load(const QString& path);
    bool isImgLoaded() const { return loaded; }
    QImage GetImage() const { return pixelMap->toImage(); }
    QPixmap* GetPixelMap() const {return pixelMap;}

private:
    QPixmap *pixelMap;
    bool loaded;
};
#endif // IMGLOADER_H
