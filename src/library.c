#include "library.h"
#include <math.h>

double add(double x, double y) {
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}

double multiply(double x, double y) {
    return x * y;
}

double divide(double x, double y) {
    if (y != 0) {
        return x / y;
    } else {
        // Ak je to nulou
        return INFINITY;
    }
}

double square_root(double x) {
    if (x >= 0) {
        return sqrt(x);
    } else {
        // Ak je odmocnina nulou
        return NAN;
    }
}

double power(double x, double y) {
    return pow(x, y);
}

int factorial(int x) {
    if (x < 0) {
        // Ak je faktorial negativne cislo
        return -1;
    }
    int result = 1;
    while (x > 1) {
        result *= x;
        x--;
    }
    return result;
}

double sin_deg(double x) {
    // Konvertovanie stupnov na radiany
    double rad = x * PI / 180.0;
    return sin(rad);
}

double cos_deg(double x) {
    // Konvertovanie stupnov na radiany
    double rad = x * PI / 180.0;
    return cos(rad);
}

double tan_deg(double x) {
    // Konvertovanie stupnov na radiany
    double rad = x * PI / 180.0;
    return tan(rad);
}

double arcsin(double x) {
    return asin(x);
}

double arccos(double x) {
    return acos(x);
}

double arctan(double x) {
    return atan(x);
}

