#ifndef FGAUSSIAN_H
#define FGAUSSIAN_H

#include <qimage.h>
#include "qcolor.h"
#include <string>

enum blurType { Gaussian, Separated, GaussFFT };

double gauss(int x, int y, double sigma);

void pad(double **src, double **dst, int src_size, int w, int h);

class FGaussian
{
public:
    FGaussian(unsigned int _ksize=15);
    ~FGaussian();
    QImage blur(const QImage& _in);
    void updateKsize(unsigned int _ksize, bool clean=true);
    int getKernelSize() const { return ksize; }
    std::string str_kernel() const;
    std::string str_kernel1d() const;
    void setType(int v){
        if(v == 0)
            type = Gaussian;
        else if(v == 1)
            type = Separated;
        else if(v == 2)
            type = GaussFFT;
    }
    int getType() const {return (int) type;}

private:
    blurType type;
    int ksize;
    int radius;
    double sigma;
    double **kernel;
    double *kernel1d;
    void kernel_generator();
    void clean_kernel();
    void kernel1d_generator();
    QImage gaussian_blur(const QImage& _in);
    QImage sep_blur(const QImage& _in);
    QImage gaussian_fft(const QImage& _in);
};

#endif // FGAUSSIAN_H
