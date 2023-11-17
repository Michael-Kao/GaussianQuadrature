#include "GaussianQuadrature.h"

GaussianQuadrature::GaussianQuadrature() {
    //do nothing
}

// f(x, y) = 6sin^2(2x) + 9cos^2(3y)
double GaussianQuadrature::f(double x, double y) {
    return (6 * sin(2 * x) * sin(2 * x) + 9 * cos(3 * y) * cos(3 * y));
}

double GaussianQuadrature::comformal_mapping(double t, double a, double b) {
    return ((b - a) * t / 2.0 + (a + b) / 2.0);
}

double GaussianQuadrature::gaussian_quadrature(int n, double a_x, double b_x, double a_y, double b_y) {
    double sum = 0;
    for(int i = 0; i < n; i++) {
        //fix y axis first
        double ptn = p[n - 1][i];
        double y = comformal_mapping(ptn, a_y, b_y);
        double wgtY = wgt[n - 1][i];
        for(int j = 0; j < n; j++) {
            double ptn = p[n - 1][j];
            double x = comformal_mapping(ptn, a_x, b_x);
            double wgtX = wgt[n - 1][j];
            sum += wgtX * wgtY * f(x, y);
        }
    }
    sum *= (b_x - a_x) / 2.0;
    sum *= (b_y - a_y) / 2.0;

    return sum;
}

void GaussianQuadrature::run() {
    double  a = -2, b = 6;
    int InteV = 8;
    int N = 4;
    if(N > 4) {
        std::cout << "N cannot greater than 4\n";
        return;
    }
    std::cout << "num of sample points : " << N << std::endl;
    for(int interval = 1; interval <= InteV; interval *= 2) {
        for(int n = N; n <= N; n++) {
            double sum = 0;
            double h = 1.0 * (b - a) / interval;
            for (int i = 0; i < interval * interval; i++) {
                int xidx = i / interval;
                int yidx = i % interval;
                double curSum = gaussian_quadrature( n, 
                                                    a + xidx * h, 
                                                    a + (xidx + 1) * h,
                                                    a + yidx * h,
                                                    a + (yidx + 1) * h );
                sum += curSum;
            }
            // sum = gaussian_quadrature(4, -2, 6, -2, 6);
            std::cout << "num of interval : " << interval << "\n    ";
            std::cout << std::setprecision(15) << sum << std::endl;
            RelaError.push_back(fabs(470.327210063638 - sum) / 470.327210063638);
        }
    }
    std::cout << "Error : " << std::endl;
    for(auto err : RelaError) {
        std::cout << err << std::endl;
    }
}