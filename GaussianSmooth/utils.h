#ifndef UTILS_H
#define UTILS_H
#include <complex>
#include <qimage.h>

void array2_complex_array(double** src, std::complex<double>* dst, int w,
                          int h);

void img2_array1d(const QImage& input,std::complex<double>* dst);

void array2_complex_array(double** src, std::complex<double>* dst, int w,
                          int h);

QImage array1d_2img(std::complex<double>* in, int w, int h,
                    QImage::Format format);

void fft(std::complex<double>* in, std::complex<double>* out, int w, int h,
         bool reverse=false);

double gauss(int x, int y, double sigma);

void pad(double **src, double **dst, int ksize, int w, int h);

int reflect(int dim, int x);

#endif // UTILS_H
