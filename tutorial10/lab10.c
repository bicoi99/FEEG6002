#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double trapez(double (*f)(double), double a, double b, int n) {
    double A = 0;
    double h = (b - a) / n;
    int i;

    A += h / 2 * (f(a) + f(b));

    for (i = 1; i < n; i++) {
        A += h * (f(a + i * h));
    }

    return A;
}

double error_trapez(double (*f)(double), double (*fint_an)(double, double),
                    double a, double b, int n) {
    return trapez(f, a, b, n) - fint_an(a, b);
}

double qgaus(double (*func)(double), double a, double b) {
    int j;
    double xr, xm, dx, s;
    double x[] = {0.0,          0.1488743389, 0.4333953941,
                  0.6794095682, 0.8650633666, 0.9739065285};
    double w[] = {0.0,          0.2955242247, 0.2692667193,
                  0.2190863625, 0.1494513491, 0.0666713443};
    /* The first value of arrays x, w is not used. */

    xm = 0.5 * (b + a);
    xr = 0.5 * (b - a);
    s = 0;
    for (j = 1; j <= 5; j++) {
        dx = xr * x[j];
        s += w[j] * ((*func)(xm + dx) + (*func)(xm - dx));
    }
    return s *= xr;
}

double error_qgaus(double (*f)(double), double (*fint_an)(double, double),
                   double a, double b) {
    return qgaus(f, a, b) - fint_an(a, b);
}

double square(double x) { return x * x; }

double square_exact(double a, double b) { return (pow(b, 3) - pow(a, 3)) / 3; }

int main() {
    double a = -1;
    double b = 2;
    int n = 10;

    printf("%f\n", error_trapez(square, square_exact, a, b, n));
    printf("%f", error_qgaus(square, square_exact, a, b));
    return 0;
}