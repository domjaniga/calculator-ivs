#include "library.h"
#include <math.h>


const double PI = 3.14159265358979323846;


double lib_add(double x, double y) {
    return x + y;
}

double lib_subtract(double x, double y) {
    return x - y;
}

double lib_multiply(double x, double y) {
    return x * y;
}

double lib_divide(double x, double y) {
    if (y != 0) {
        return x / y;
    } else {
        return INFINITY;
    }
}

double lib_square_root(double x) {
    if (x >= 0) {
        return sqrt(x);
    } else {
        return NAN;
    }
}

double lib_power(double x, double y) {
    return pow(x, y);
}

int lib_factorial(int x) {
    if (x < 0) {
        return -1;
    }
    int result = 1;
    for (int i = 2; i <= x; i++) {
        result *= i;
    }
    return result;
}

double lib_sin_deg(double x) {
    double rad = x * PI / 180.0;
    return sin(rad);
}

double lib_cos_deg(double x) {
    double rad = x * PI / 180.0;
    return cos(rad);
}

double lib_tan_deg(double x) {
    double rad = x * PI / 180.0;
    return tan(rad);
}

double lib_arcsin(double x) {
    return asin(x);
}

double lib_arccos(double x) {
    return acos(x);
}

double lib_arctan(double x) {
    return atan(x);
}
