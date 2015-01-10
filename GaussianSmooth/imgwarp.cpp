#include "imgwarp.h"
#include <qimage.h>
#include <qcolor.h>
#include <utility>
#include "math.h"

ImgWarp::ImgWarp()
{
}

ImgWarp::ImgWarp(const QImage* _img, warpparams _x, warpparams _y):
 img(_img), xparams(_x), yparams(_y){

}


ImgWarp::~ImgWarp(){}

std::pair<int, int> ImgWarp::get_coords(int x, int y, int w, int h){

    int xold = x;
    int yold;

    double yr;
    yr = yparams.amplitude * h * sin(x+y);
    yold = round(y + yr);
    return std::make_pair(xold, yold);
}

QImage ImgWarp::warp(){
    int inw = img->width();
    int inh = img->height();

    double offsetx = xparams.amplitude * inw;
    double offsety = yparams.amplitude * inh;

    int outw = round(inw + offsetx);
    int outh = round(inh + offsety);
    if(yparams.freq!=0 && yparams.freq < 2)
        outh += offsety;
    if(xparams.freq != 0 && xparams.freq < 2)
        outw += offsetx;
    QImage out(outw, outh, img->format());

    double freqy = yparams.freq*inh;
    double phasey = yparams.phase * inh * M_PI / 180;

    double freqx = xparams.freq*inw;
    double phasex = xparams.phase * inw * M_PI / 180;
    for(int y=0; y<outh; ++y){
        for(int x=0; x<outw; ++x){

            int ox = round(x - offsetx + offsetx*sin(2 * M_PI * y/freqx + phasex));
            int oy = round(y - offsety + offsety*sin(2 * M_PI * x/freqy + phasey));

            QColor c(0, 0, 0);
            if(ox >= 0 && ox < inw && oy >=0 && oy < inh)
                c = img->pixel(ox, oy);

            int v = c.red();
            out.setPixel(x, y, qRgb(v, v, v));
        }
    }
    return out;
}
