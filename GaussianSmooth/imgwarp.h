#ifndef IMGWARP_H
#define IMGWARP_H
#include <qimage.h>
#include <utility>

struct warpparams{
    double amplitude;
    double freq;
    double phase;
};

class ImgWarp
{
public:
    ImgWarp();
    ImgWarp(const QImage* _img, warpparams _x, warpparams _y);
    QImage warp();
    ~ImgWarp();
private:
    const QImage* img;
    warpparams xparams;
    warpparams yparams;
    std::pair<int, int> get_coords(int x, int y, int w, int h);
};

#endif // IMGWARP_H
