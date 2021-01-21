#include <math.h>
#include <stdio.h>

#define N 20
#define XMIN 1.
#define XMAX 20.

int main() {
    float x;
    printf("%10s %10s %10s %10s\n", "x", "sin(x)", "cos(x)", "tan(x)");
    for (x = XMIN; x <= XMAX; x += ((XMAX - XMIN) / (N - 1))) {
        printf("%10.2f %10.2f %10.2f %10.2f\n", x, sin(x), cos(x), tan(x));
    }
    return 0;
}