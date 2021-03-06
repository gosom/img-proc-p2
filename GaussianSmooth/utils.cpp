#include "utils.h"
#include "math.h"
#include <qimage.h>
#include <qcolor.h>
#include <complex>
#include <fftw3.h>
#include <utility>
#include <opencv2/opencv.hpp>
#include <qdebug.h>

//credits http://stackoverflow.com/questions/11543298/qt-opencv-displaying-images-on-qlabel
QImage mat2qimage(cv::Mat const &mat)
{
    if(mat.type()==CV_8UC1)
    {
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    if(mat.type()==CV_8UC3)
    {
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}

void fftshift(std::complex<double> *a, int w, int h){
    int m = h/2;
    std::complex<double> tmp1;
    for(int row=0; row!= w/2; ++row){
        for(int column=0; column != h/2; ++column){
            tmp1 = a[(row+m)*h+column + m];
            a[(row+m)*h+column + m] = a[row*h + column];
            a[row*h + column] = tmp1;

            tmp1 = a[(row)*h+column + m];
            a[(row)*h+column + m] = a[(row+m)*h + column];
            a[(row+m)*h + column] = tmp1;
        }
    }
}


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


void pad(double **src, double **dst, int sw, int sh, int w, int h){
    if(w == sw && h == sh){
        for(int i=0; i<sw; ++i){
            for(int j=0; j<sh; ++j)
                dst[i][j] = src[i][j];
        }
    }else{
        int top_bottom = h - sh, right_left = w - sw;
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


QImage padded(const QImage& in, int ksize){
    int padsize = ksize/2;
    int w = in.width() + ksize -1;
    int h = in.height() + ksize -1;
    QImage img(w, h, in.format());
    img.fill(0);
    QColor c;
    double v;
    for(int x=0; x!=w; ++x){
        for(int y=0; y!=h; ++y){
            if(x >= padsize && x < (in.width() + padsize)
               && y >= padsize && y < (in.height() + padsize)){
                c = in.pixel(x-padsize, y-padsize);
            }else{
                if(x<padsize && y >= padsize && y < (in.height() + padsize)){
                     c = in.pixel(0, y-padsize);
                }else if(x>padsize && y >= padsize && y < (in.height() + padsize)){
                    c = in.pixel(in.width()-1, y-padsize);
                }
                else if(y<padsize && x >= padsize && x < (in.width() + padsize)){
                    c = in.pixel(x-padsize, 0);
                }else if(y>padsize && x >= padsize && x < (in.width() + padsize)){
                    c = in.pixel(x-padsize, in.height()-1);
                }else if(x<padsize && y<padsize){
                    c = in.pixel(0, 0);
                }else if(x<padsize && y>padsize){
                    c = in.pixel(0, in.height()-1);
                }else if(x>padsize && y<padsize){
                    c = in.pixel(in.width()-1, 0);
                }else
                    c = in.pixel(in.width()-1, in.height()-1);
            }
            v = c.red();
            img.setPixel(x, y, qRgb(v, v, v));
        }
    }
    return img;
}

QImage unpad(const QImage& in, int ksize){
    int padsize = ksize/2;
    int nw = in.width() - ksize + 1;
    int nh = in.height() - ksize + 1;
    double** ndata = new double*[nw];
    for(int i=0; i<nw; ++i)
        ndata[i] = new double[nh];
    QImage img(nw, nh, in.format());
    QColor c;
    double v;
    int coordx, coordy;
    for(int x=0; x<in.width(); ++x){
        for(int y=0; y<in.height(); ++y){
            if(x>=padsize && x< (nw + padsize)
               && y>=padsize && y < (nh+padsize)){
                c = in.pixel(x, y);
                v = c.red();
                coordx = x - padsize;
                coordy = y - padsize;
                img.setPixel(coordx, coordy, qRgb(v, v, v));
            }
        }
    }
    return img;
}

int reflect(int dim, int x){
    if(x < 0)
        return -x - 1;
    if(x >= dim)
        return 2 * dim - x - 1;
    return x;
}


