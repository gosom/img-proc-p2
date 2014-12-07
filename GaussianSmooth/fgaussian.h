#ifndef FGAUSSIAN_H
#define FGAUSSIAN_H

#include <qimage.h>
#include "qcolor.h"

double gauss(int x, int y, double sigma);

class FGaussian
{
public:
    FGaussian(unsigned int _ksize=15);
    ~FGaussian();
    QImage blur(const QImage& _in);
    void updateKsize(unsigned int _ksize, bool clean=true);
    int getKernelSize() const { return ksize; }

private:
    int ksize;
    int radius;
    double sigma;
    double **kernel;
    void kernel_generator();
    void clean_kernel();
};

#endif // FGAUSSIAN_H
