#include "recursivegaussian.h"

RecursiveGaussian::RecursiveGaussian()
{
}

RecursiveGaussian::~RecursiveGaussian(){

}

RecursiveGaussian::RecursiveGaussian(num sigma){
    coeff.sigma = sigma;
}

RecursiveGaussian::RecursiveGaussian(int ksize){

    coeff.sigma = calc_sigma(ksize);
}

void RecursiveGaussian::update_sigma(int ksize){
    coeff.sigma = calc_sigma(ksize);
}

num RecursiveGaussian::calc_sigma(int ksize){
    int radius = (ksize - 1) / 2;
    return (num) radius / 2.0;
}

void RecursiveGaussian::calculate_coefficients(int ksize){
    update_sigma(ksize);
    num sigma = coeff.sigma;

    coeff.a_pos[0] = alpha[0] + alpha[1];

    coeff.a_pos[1] = exp(-gamma[1]/sigma)*(beta[1]*sin(omega[1]/sigma) - \
            (alpha[1] + 2*alpha[0])*cos(omega[1]/sigma)) + \
            exp(-gamma[0]/sigma)*(beta[0]*sin(omega[0]/sigma) - \
            (2*alpha[1] + alpha[0])*cos(omega[0]/sigma));

    coeff.a_pos[2] = 2*exp(-gamma[0]/sigma - gamma[1]/sigma)* \
            ((alpha[0]+alpha[1])*cos(omega[1]/sigma)*cos(omega[0]/sigma) - \
            beta[0]*cos(omega[1]/sigma)*sin(omega[0]/sigma) - \
            cos(omega[0]/sigma)*beta[1]*sin(omega[1]/sigma)) +
            alpha[1]*exp(-2*gamma[0]/sigma) + alpha[0]*exp(-2*gamma[1]/sigma);

    coeff.a_pos[3] = exp(-gamma[1]/sigma - 2*gamma[0]/sigma)*(beta[1]* \
            sin(omega[1]/sigma) - alpha[1]*cos(omega[1]/sigma)) + \
            exp(-gamma[0]/sigma - 2*gamma[1]/sigma)* \
            (beta[0]*sin(omega[0]/sigma) - alpha[0]*cos(omega[0]/sigma));


    coeff.b_pos[1] = -2*exp(-gamma[1]/sigma)*cos(omega[1]/sigma) - \
            2*exp(-gamma[0]/sigma)*cos(omega[0]/sigma);

    coeff.b_pos[2] = 4*cos(omega[1]/sigma)* \
            cos(omega[0]/sigma)*exp(-gamma[0]/sigma - gamma[1]/sigma) + \
            exp(-2*gamma[1]/sigma) + exp(-2*gamma[0]/sigma);

    coeff.b_pos[3] = -2*cos(omega[0]/sigma)*exp(-gamma[0]/ \
            sigma-2*gamma[1]/sigma) - 2*cos(omega[1]/sigma)* \
            exp(-gamma[1]/sigma-2*gamma[0]/sigma);

    coeff.b_pos[4] = exp(-2*gamma[0]/sigma - 2*gamma[1]/sigma);

    coeff.a_pos[4] = 0;
    coeff.b_pos[0] = 1;

    for(int i=0; i < MaxK; ++i){
        coeff.b_neg[i] = coeff.b_pos[i];
        coeff.a_neg[i] = coeff.a_pos[i] - coeff.b_pos[i] * coeff.a_pos[0];
    }
    coeff.b_neg[4] = coeff.b_pos[4];
    coeff.a_neg[4] = - coeff.b_pos[4] * coeff.a_pos[0];

}

void RecursiveGaussian::get_causal(const std::vector<num> &tmp, std::vector<num> &causal){
    int width = tmp.size();
    causal.reserve(width);
    for(auto n=0; n<width; ++n){
        num val(0);
        for(auto m=0; m<=3; ++m){
            if(n >= m)
                val += coeff.a_pos[m] * tmp[n-m];
           else
                break;
        }
        for(auto m=1; m<=4; ++m){
            if(n >= m)
                val -= coeff.b_pos[m] * causal[n-m];
            else
                break;
        }
        causal.push_back(val);
    }
}

void RecursiveGaussian::get_acausal(const std::vector<num>& tmp, std::vector<num>& acausal){
    int width = tmp.size();
    for(auto n=width-1; n>=0; --n){
        num val(0);

        for(auto m=1; m<=4; ++m){
            if( (n + m) < width)
                val += coeff.a_neg[m] * tmp[n+m];
            else
                break;
        }
        for(auto m=1; m<=4; ++m){
            if( (n + m) < acausal.size())
                val -= coeff.b_neg[m] * acausal[n+m];
            else
                break;
        }
        acausal[n] = val;
    }
}

void RecursiveGaussian::apply_filter(cv::Mat &out){
    int width = out.cols;
    int height = out.rows;
    for(int i=0; i<height; ++i){
        std::vector<num> tmp;
        tmp.reserve(width);
        const num* p = out.ptr<num>(i);
        for(int j=0; j<width; ++j)
            tmp.push_back(p[j]);

        std::vector<num> causal;
        get_causal(tmp, causal);
        std::vector<num> acausal(width);
        get_acausal(tmp, acausal);

        num* pw = out.ptr<num>(i);
        for(int j=0; j<width; j++)
            pw[j] = (causal[j] + acausal[j]) / (coeff.sigma * Sqrt2pi);
    }
}

cv::Mat RecursiveGaussian::gaussian_conv(){
    int pad = (4 * coeff.sigma + 1)/2;
    cv::Mat bimg(img.rows + 2*pad, img.cols + 2*pad, CV_32FC1);
    cv::copyMakeBorder(img, bimg, pad, pad, pad, pad, cv::BORDER_REFLECT);
    cv::Mat out;
    bimg.convertTo(out, CV_32FC1);

    apply_filter(out);
    out = out.t();
    apply_filter(out);
    out = out.t();

    cv::Mat dst(out.rows, out.cols, CV_8UC1);
    cv::normalize(out, dst, 0, 255, cv::NORM_MINMAX, CV_8UC1);
    cv::Mat borderless(img.rows, img.cols, CV_8UC1);
    for(int x=pad; x<out.rows-pad; ++x)
        for(int y=pad; y<out.cols-pad; ++y)
            borderless.at<uchar>(x-pad, y-pad) = dst.at<uchar>(x, y);

    return borderless;
}
