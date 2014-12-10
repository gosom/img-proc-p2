#include "utils.h"
#include "math.h"
#include <qimage.h>
#include <qcolor.h>
#include <complex>
#include <fftw3.h>

void array2_complex_array(double** src, std::complex<double>* dst, int w,
                          int h){
    for(int x = 0; x < w; x++){
            for(int y = 0; y < h; y++)
                dst[y * w + x] = src[x][y];
        }
}

void img2_array1d(const QImage& input,
                  std::complex<double>* dst){
    int w = input.width();
    int h = input.height();
    for(int x = 0; x < w; x++){
        for(int y = 0; y < h; y++){
            QColor color(input.pixel(x, y));
            dst[y * w + x] = (double)color.red();
        }
    }
}

QImage array1d_2img(std::complex<double>* in, int w, int h,
                    QImage::Format format){
    QImage output = QImage(w, h, format);
    int N = w * h;
    for(int x=0; x<w; ++x){
        for(int y=0; y<h; ++y){
            double v = (in[y*w + x].real())/N;
            output.setPixel(x, y, qRgb(v, v, v));
        }
    }
    return output;
}

void fft(std::complex<double>* in, std::complex<double>* out, int w, int h,
         bool reverse){
    fftw_plan plan;
    if(reverse){
        plan = fftw_plan_dft_2d(w, h,
                                reinterpret_cast<fftw_complex*>(in),
                                reinterpret_cast<fftw_complex*>(out),
                                FFTW_BACKWARD, FFTW_ESTIMATE);
    }else{
        plan = fftw_plan_dft_2d(w, h,
                                reinterpret_cast<fftw_complex*>(in),
                                reinterpret_cast<fftw_complex*>(out),
                                FFTW_FORWARD, FFTW_ESTIMATE);
    }
    fftw_execute(plan);
    fftw_destroy_plan(plan);
}


double gauss(int x, int y, double sigma){
    double sigma_sqrt = sigma * sigma;
    double pow = exp(-( (x*x+y*y) / (2*sigma_sqrt) ));
    return (1.0/sqrt(2*M_PI*sigma_sqrt)) * pow;
}


void pad(double **src, double **dst, int ksize, int w, int h){
    if(w == ksize && h == ksize){
        for(int i=0; i<ksize; ++i){
            for(int j=0; j<ksize; ++j)
                dst[i][j] = src[i][j];
        }
    }else{
        int top_bottom = h - ksize, right_left = w - ksize;
        int top, bottom, left, right;
        top = bottom = top_bottom / 2;
        if(top_bottom % 2 != 0)
            bottom += 1;
        left = right = right_left/2;
        if(right_left % 2 != 0)
            right += 1;

        int ki = 0;
        for(int i=0; i<w; ++i){
            int kj = 0;
            for(int j=0; j<h; ++j){
                if(j >= top && (h-j) > bottom && i >= left && (w-i) > right)
                    dst[i][j] = src[ki][kj];
                else
                    dst[i][j] = 0.0;
                if(j >= top)
                    kj += 1;
            }
            if(i >= left && (w-i) >= right)
                ki += 1;
            }
        }
}


int reflect(int dim, int x){
    if(x < 0)
        return -x - 1;
    if(x >= dim)
        return 2 * dim - x - 1;
    return x;
}
