#include <math.h>
#include <stdio.h>
#define N 3

/* structure declaration */
typedef struct Vector {
    double x;
    double y;
    double z;
} vector;

/* definition of function init */
vector init(double xi, double yi, double zi) {
    vector v;
    v.x = xi;
    v.y = yi;
    v.z = zi;
    return v;
}

/* definition of function add */
vector add(vector a, vector b) {
    vector v;
    v.x = a.x + b.x;
    v.y = a.y + b.y;
    v.z = a.z + b.z;
    return v;
}

/* definition of function scale */
vector scale(vector a, double c) {
    vector v;
    v.x = a.x * c;
    v.y = a.y * c;
    v.z = a.z * c;
    return v;
}

/* definition of a function norm*/
double norm(vector a) { return sqrt(a.x * a.x + a.y * a.y + a.z * a.z); }

/* definition of function dot_product */
double dot_product(vector a, vector b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

/* definition of function cross_product */
vector cross_product(vector a, vector b) {
    vector v;
    v.x = a.y * b.z - a.z * b.y;
    v.y = a.z * b.x - a.x * b.z;
    v.z = a.x * b.y - a.y * b.x;
    return v;
}

int main() {
    vector basis[N];
    vector a, a_unit;
    int i;

    basis[0] = init(1., 0., 0.);
    basis[1] = init(0., 1., 0.);
    basis[2] = init(0., 0., 1.);

    printf("\n");
    printf("Normalise a to a unit vector:\n");
    a = init(2., 3., 4.);
    printf("Vector a = (%.2f, %.2f, %.2f)\n", a.x, a.y, a.z);
    a_unit = scale(a, 1 / norm(a));
    printf("Unit vector a = (%.2f, %.2f, %.2f)\n", a_unit.x, a_unit.y,
           a_unit.z);
    printf("Check the norm of a normalised to unit vector: %.2f\n",
           norm(a_unit));

    printf("\nCalculate projections of vector a onto the basis vectors:\n");
    for (i = 0; i < N; i++) {
        printf("Projection of vector a on (%.2f, %.2f, %.2f) ", basis[i].x,
               basis[i].y, basis[i].z);
        printf("is %.2f\n", dot_product(basis[i], a_unit));
    }

    printf("\n");
    printf("Cross product of vector a with the basis vectors:\n");
    for (i = 0; i < N; i++) {
        printf("Cross product of vector a with (%.2f, %.2f, %.2f) ", basis[i].x,
               basis[i].y, basis[i].z);
        printf("is (%.2f, %.2f, %.2f)\n", cross_product(a_unit, basis[i]).x,
               cross_product(a_unit, basis[i]).y,
               cross_product(a_unit, basis[i]).z);
    }

    return 0;
}