#include <math.h>
#include <stdio.h>

#define N 3

void print_matrix(int n, double a[][N]) {
    int i, j;
    printf("\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void transpose(double a[][N]) {
    int i, j;
    double tmp;
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }
    }
}

double det2(double a[][2]) { return a[0][0] * a[1][1] - a[0][1] * a[1][0]; }

double cofactor(double a[][N], int i, int j) {
    int ii, jj, c = 0;
    double aa[2][2];
    /* Extract minor */
    for (ii = 0; ii < N; ii++) {
        if (ii == i) {
            continue;
        }
        for (jj = 0; jj < N; jj++) {
            if (jj == j) {
                continue;
            }
            *(*aa + c) = a[ii][jj];
            c++;
        }
    }
    return pow(-1, i + j) * det2(aa);
}

double det3(double a[][N]) {
    int i = 0, k;
    double det = 0;
    for (k = 0; k < N; k++) {
        det += a[k][i] * cofactor(a, k, i);
    }
    return det;
}

void inverse(double a[][N]) {
    double c[N][N], det;
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            c[i][j] = cofactor(a, i, j);
        }
    }
    det = det3(a);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = c[j][i] / det;
        }
    }
}

void multiply(double a[][N], double b[][N]) {
    double c[N][N];
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    print_matrix(3, c);
}

int main() {
    double a[N][N] = {{1., 0., 1.}, {0., 1., 1.}, {0., 0., 1.}}, ainv[N][N];
    int i, j;
    printf("\nOriginal matrix:\n");
    print_matrix(3, a);
    printf("Determinant of the matrix:\n");
    printf("%f\n", det3(a));
    printf("\nTranspose of the matrix:\n");
    transpose(a);
    print_matrix(3, a);
    printf("Inverse of the matrix:\n");
    transpose(a);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            ainv[i][j] = a[i][j];
        }
    }
    inverse(ainv);
    print_matrix(3, ainv);
    printf("Check that the product gives unit matrix.\n");
    multiply(a, ainv);
    return 0;
}