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


int reflect(int dim, int x)
{
    if(x < 0)
        return -x - 1;
    if(x >= dim)
        return 2 * dim - x - 1;
    return x;
}

FGaussian::FGaussian(unsigned int _ksize){
    updateKsize(_ksize, false);
    type = Gaussian;
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
    if(kernel1d != nullptr)
        delete kernel1d;

}

QImage FGaussian::blur(const QImage& _in){
    QImage out;
    if(type == Gaussian)
        out = gaussian_blur(_in);
    else if(type == Separated)
        out = sep_blur(_in);
    return out;
}

QImage FGaussian::gaussian_blur(const QImage& _in){
    if(_in.isNull())
        return QImage();

    QImage img(_in.size(), _in.format());

    int w = _in.width();
    int h = _in.height();
    double d = 0.0;

    for(int x=0; x<w; ++x){
        for(int y=0; y<h; ++y){

            d = 0.0;
            for(int i=-radius; i<=radius; ++i){
                for(int j=-radius; j<=radius; ++j){

                    int x1 = reflect(_in.width(), x-i);
                    int y1 = reflect(_in.height(), y-j);
                    QColor color(_in.pixel(x1, y1));
                    double value = kernel[i+radius][j+radius];
                    d += color.red()*value;
                    /* now using reflection since it is easier to understand
                    if( (i+x)>=0 && (j+y) >=0 && (i+x) < w-1 && (j+y)<h-1){
                        QColor color(_in.pixel(x+i, y+j));
                        double value = kernel[i+radius][j+radius];
                        d += color.red()*value;
                    }*/
                }
            }
            img.setPixel(x, y, qRgb(d, d, d));
        }
    }
    return img;

}

QImage FGaussian::sep_blur(const QImage& _in){
    QImage dst(_in.size(), _in.format());
    QImage tmp(_in.size(), _in.format());
    int w = _in.width();
    int h = _in.height();
    double sum;

    for(int y=0; y < h; y++){
        for(int x=0; x < w; x++){
            sum = 0.0;
            for(int i=-radius; i<=radius; ++i){
                int y1 = reflect(h, y-i);
                QColor color(_in.pixel(y1, x));
                double value = kernel1d[i+radius];
                sum += color.red()*value;

            }
            tmp.setPixel(y, x, qRgb(sum, sum, sum));
        }
    }

    for(int y=0; y < h; y++){
        for(int x=0; x < w; x++){
            sum = 0.0;
            for(int i=-radius; i<=radius; ++i){
                int x1 = reflect(w, x-i);
                QColor color(tmp.pixel(y, x1));
                double value = kernel1d[i+radius];
                sum += color.red()*value;

            }
            dst.setPixel(y, x, qRgb(sum, sum, sum));
        }
    }

    return dst;
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

    for(int x=0; x<ksize; ++x){
        for(int y=0; y<ksize; ++y)
            kernel[x][y] /= sum;
    }

    kernel1d_generator();
}

void FGaussian::kernel1d_generator(){
    kernel1d = new double[ksize];
    for(int i=0; i<ksize; ++i)
        kernel1d[i] = 0.0;

    for(int i=0; i<ksize; ++i){
        for(int j=0; j<ksize; ++j){
            kernel1d[j] += kernel[i][j];
        }
    }
}

std::string FGaussian::str_kernel() const{
    std::string s = "{";
    for(int x=0; x<ksize; ++x){
        for(int y=0; y<ksize; ++y){
            s += std::to_string(kernel[x][y]) + ",";
        }
        s += "\n";
    }
    s += "}";
    return s;
}

std::string FGaussian::str_kernel1d() const{
    std::string s = "{";
    for(int x=0; x<ksize; ++x)
        s += std::to_string(kernel1d[x]) + ",";
    s += "}";
    return s;
}

