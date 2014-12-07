#include "fgaussian.h"
#include <math.h>
#include <cmath>
//#include <string>
//#include <fstream>
#include <qimage.h>


double gauss(int x, int y, double sigma){
    double sigma_sqrt = sigma * sigma;
    double pow = exp(-( (x*x+y*y) / (2*sigma_sqrt) ));
    return (1.0/sqrt(2*M_PI*sigma_sqrt)) * pow;
}

FGaussian::FGaussian(unsigned int _ksize){
    updateKsize(_ksize, false);
}

FGaussian::~FGaussian(){
    clean_kernel();
}

void FGaussian::updateKsize(unsigned int _ksize, bool clean){
    if(clean)
        clean_kernel();

    ksize = _ksize;
    radius = (ksize - 1) / 2;
    sigma = radius / 2.0;

    kernel_generator();
}

void FGaussian::clean_kernel(){
    if(kernel != nullptr){
        for(int i=0; i<ksize; ++i)
            delete [] kernel[i];
        delete kernel;
    }
}

QImage FGaussian::blur(const QImage& _in){
    if(_in.isNull())
        return QImage();

    QImage img(_in.size(), _in.format());

    int w = _in.width();
    int h = _in.height();
    double d = 0.0;
    //QColor color;

    for(int x=0; x<w; ++x){
        for(int y=0; y<h; ++y){

            d = 0.0;
            for(int i=-radius; i<=radius; ++i){
                for(int j=-radius; j<=radius; ++j){
                    if( (i+x)>=0 && (j+y) >=0 && (i+x) < w-1 && (j+y)<h-1){
                        QColor color(_in.pixel(x+i, y+j));
                        double value = kernel[i+radius][j+radius];
                        d += color.red()*value;
                    }
                }
            }
            img.setPixel(x, y, qRgb(d, d, d));
        }
    }
    return img;

}

void FGaussian::kernel_generator(){
    kernel = new double*[ksize];
    for(int i=0; i<ksize; ++i)
        kernel[i] = new double[ksize];

    int midx = ksize / 2;
    int midy = ksize / 2;
    double sum = 0;

    for(int x=0; x<ksize; ++x){
        for(int y=0; y<ksize; ++y){
            double g;
            if (x > midx && y < midy)
                g = kernel[ksize-x-1][y];
            else if (x < midx && y > midy)
                g = kernel[x][ksize-y-1];
            else if (x > midx && y > midy)
                g = kernel[ksize-x-1][ksize-y-1];
            else
                g = gauss(x-midx, y-midy, sigma);
            kernel[x][y] = g;
            sum += g;
        }
    }

    //double vsum = 0;
    //std::string s = "{";
    for(int x=0; x<ksize; ++x){
        for(int y=0; y<ksize; ++y){
            double v = kernel[x][y] / sum;
            kernel[x][y] = v;
            //vsum += v;
            //s += std::to_string(v) + ",";
        }
        //s += "\n";
    }
    //s += "}";
    //std::ofstream ofs("test");
    //ofs << s;
}
