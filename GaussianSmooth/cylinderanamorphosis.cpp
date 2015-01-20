#include "cylinderanamorphosis.h"
#include <cmath>
#include <qcolor.h>
#include <utility>

struct PolarPoint{
    double r;
    double theta;
};

PolarPoint get_polar(int x, int y){
    double r = sqrt(x*x + y*y);
    double a;
    a = atan2(y, x);
    return PolarPoint{r, a};
}

CylinderAnamorphosis::CylinderAnamorphosis(){}

CylinderAnamorphosis::CylinderAnamorphosis(QImage img, int _rmin){
    _img = img;
    centerX = img.width() / 2.0;
    centerY = img.height() / 2.0;
    radius = img.width() / 2.0;
    rmin = _rmin;
}

CylinderAnamorphosis::~CylinderAnamorphosis(){}


QImage CylinderAnamorphosis::get_anamorphosis(){

    int width = _img.width();
    int height = _img.height();
    QImage out(width, height, _img.format());

    for(int x=0; x<height; ++x){
        for(int y=0; y<width; ++y){
            auto p = get_polar(x - centerX , y - centerY );
            double val = 0.0;
            if(p.r <= radius){
                int u = ((p.theta * width) / (2*M_PI)) + centerX ;
                int v = height*(radius - p.r) / (radius - rmin);
                QColor c(_img.pixel(u, v));
                val = c.red();
            }
            out.setPixel(x, y, qRgb(val, val, val));
        }
    }
    return out;
}
