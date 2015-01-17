#ifndef RECURSIVEGAUSSIAN_H
#define RECURSIVEGAUSSIAN_H
#include <qimage.h>
#include <opencv2/opencv.hpp>
#include <vector>

const int MaxK = 4;
typedef float num;
const num Sqrt2pi= sqrt(2 * M_PI);


typedef struct _coefficients{
    num sigma;
    num a_pos[MaxK+1];
    num a_neg[MaxK+1];
    num b_pos[MaxK+1];
    num b_neg[MaxK+1];
} coefficients;

class RecursiveGaussian
{
public:
    RecursiveGaussian();
    RecursiveGaussian(num sigma);
    RecursiveGaussian(int ksize);
    ~RecursiveGaussian();

    void setImg(cv::Mat _img) { img = _img; }

    void calculate_coefficients(int ksize);

    num get_sigma(){return coeff.sigma;}

    cv::Mat gaussian_conv();
private:
    coefficients coeff;
    cv::Mat img;
    num calc_sigma(int ksize);
    void get_causal(const std::vector<num>& tmp, std::vector<num>& causal);
    void get_acausal(const std::vector<num>& tmp, std::vector<num>& acausal);
    void apply_filter(cv::Mat& out);

    void update_sigma(int ksize);
    const num alpha[2] = {1.68, -0.6803};
    const num beta[2] = {3.7350, -0.2598};
    const num gamma[2] = {1.7830, 1.7230};
    const num omega[2] = {0.6318, 1.9970};
};

#endif // RECURSIVEGAUSSIAN_H
