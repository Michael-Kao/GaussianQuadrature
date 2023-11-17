#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>


class GaussianQuadrature {
public:
    GaussianQuadrature();
    void run();
    std::vector<float> getError() { return RelaError; }
private:
    // Sample points in [-1, 1], 1-, 2-, 3-, and 4-points. Ignore extra points (the 0s).
    double p[4][4] = {
        {0.0, 0.0, 0.0, 0.0}, 
        {0.5773502691896257, -0.5773502691896257, 0.0, 0.0}, 
        {0.0, 0.7745966692414834, -0.7745966692414834, 0.0}, 
        {0.3399810435848563, -0.3399810435848563, 0.8611363115940526, -0.8611363115940526}
    };
    // weights, for 1-, 2-, 3-, and 4-points. Extra weights = 0s.
    double wgt[4][4] = {
        {2.0, 0.0, 0.0, 0.0}, 
        {1.0, 1.0, 0.0, 0.0}, 
        {0.888888888888888888888, 0.555555555555555556, 0.555555555555555556, 0.0}, 
        {0.6521451548625461, 0.6521451548625461, 0.3478548451374538, 0.3478548451374538}
    };
    // N sample points, CURRENT range for both x and y
    double gaussian_quadrature(int n, double a_x, double b_x, double a_y, double b_y);
    double comformal_mapping(double t, double a, double b);
    double f(double x, double y);

    std::vector<float> RelaError;
};