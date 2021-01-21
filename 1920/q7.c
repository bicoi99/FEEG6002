#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define Ti 0.0
#define Tf 2.0
#define dT 0.1
#define Y0 0.0

void euler(double *t, double *y, double y0, double (*f)(double, double),
           int n) {
    int i;
    y[0] = y0;
    /* Only go to n-1 because y[n+1] does not exist */
    for (i = 0; i < n; i++) {
        y[i + 1] = y[i] + dT * f(t[i], y[i]);
    }
}

void rk(double *t, double *y, double y0, double (*f)(double, double), int n) {
    int i;
    double k1, k2, k3, k4;
    y[0] = y0;
    /* Only go to n-1 because y[n+1] does not exist */
    for (i = 0; i < n; i++) {
        k1 = dT * f(t[i], y[i]);
        k2 = dT * f(t[i] + dT / 2., y[i] + k1 / 2.);
        k3 = dT * f(t[i] + dT / 2., y[i] + k2 / 2.);
        k4 = dT * f(t[i] + dT, y[i] + k3);
        y[i + 1] = y[i] + (k1 + 2. * k2 + 2. * k3 + k4) / 6.;
    }
}

double error(double *t, double *y, double (*g)(double), int n) {
    double err;
    int i;
    for (i = 0; i <= n; i++) {
        err += pow(y[i] - g(t[i]), 2);
    }
    return err;
}

double fode(double t, double y) { return -t * (1.0 + y); }

double fode_analytic(double x) { return -1 + exp(-x * x / 2); }

int main() {
    int N, i;
    double *t, *y_e, *y_rk;
    FILE *fw;

    N = (Tf - Ti) / dT;
    t = (double *)malloc((N + 1) * sizeof(double));
    y_e = (double *)malloc((N + 1) * sizeof(double));
    y_rk = (double *)malloc((N + 1) * sizeof(double));

    for (i = 0; i <= N; i++) {
        t[i] = Ti + dT * i;
        y_e[i] = 0.0;
        y_rk[i] = 0.0;
    }

    euler(t, y_e, Y0, fode, N);
    rk(t, y_rk, Y0, fode, N);

    if ((fw = fopen("data.txt", "w")) == NULL) {
        printf("Cannot open file for writing.");
        return -1;
    }
    for (i = 0; i <= N; i++) {
        fprintf(fw, "%f\t%f\t%f\t%f\n", t[i], y_e[i], y_rk[i],
                fode_analytic(t[i]));
    }
    if (fclose(fw) != 0) {
        printf("Cannot close file.");
        return -1;
    }
    printf("\nMean square error achieved by Euler method\n");
    printf("assuming step %f is %f\n", dT, error(t, y_e, fode_analytic, N));
    printf("\nMean square error achieved by Runge-Kutta method\n");
    printf("assuming step %f is %f\n", dT, error(t, y_rk, fode_analytic, N));
    return 0;
}
