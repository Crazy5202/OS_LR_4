#include "lib.h"
#include "math.h"

float Square(float A, float B) {
    return A*B;
}

float Pi(int K) {
    double pi = 0.0;
    for(int i = 0; i < K; i++) {
        pi += 4*pow(-1,i)/(2*i+1);
    }
    return pi;
}