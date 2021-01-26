#include <stdio.h>
#include <stdlib.h>

#define Ti 0.0
#define Tf 30.0
#define dT 0.001

#define Y01 70.0
#define Y02 50.0

#define A 0.7
#define B 1
#define C 0.007

void fode2(double *p, double *f) {
    f[0] = A * p[0] - C * p[0] * p[1];
    f[1] = C * p[0] * p[1] - B * p[1];
}

void euler(double *y1, double *y2, void (*fode)(double *, double *), int n) {
    int i;
    double p[2], f[2];
    y1[0] = Y01;
    y2[0] = Y02;
    for (i = 0; i < n; i++) {
        p[0] = y1[i];
        p[1] = y2[i];
        fode(p, f);
        y1[i + 1] = y1[i] + dT * f[0];
        y2[i + 1] = y2[i] + dT * f[1];
    }
}

int main() {
    int i, N;
    double *t, *y1, *y2;
    FILE *fw;

    N = (Tf - Ti) / dT;
    t = (double *)malloc(sizeof(double) * (N + 1));
    y1 = (double *)malloc(sizeof(double) * (N + 1));
    y2 = (double *)malloc(sizeof(double) * (N + 1));

    for (i = 0; i <= N; i++) {
        t[i] = Ti + dT * i;
    }

    euler(y1, y2, fode2, N);

    if ((fw = fopen("data.txt", "w")) == NULL) {
        printf("Cannot open file for reading.");
        return -1;
    }
    for (i = 0; i <= N; i++) {
        fprintf(fw, "%f\t%f\t%f\n", t[i], y1[i], y2[i]);
    }
    if (fclose(fw) != 0) {
        printf("Cannot close file.");
        return -1;
    }

    free((void *)t);
    free((void *)y1);
    free((void *)y2);

    return 0;
}