#ifndef CALC_H
#define CALC_H

#include <iostream>
#include <cmath>

namespace calc {
    class BasicCalc {
        public:
            double sqrt(double x);
            long long fact(int x);
            double log2(double x);
            double pow(double x, double y);
    };
}

#endif