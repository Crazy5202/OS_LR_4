#include "lib.h"

float Square(float A, float B) {
    return 0.5*A*B;
}

float Pi(int K) {
    double pi = 2;
    for (int i = 1; i<=K; ++i) {
        float n = i;
        pi *= (4*n*n)/(4*n*n-1);
    }
    return pi;
}