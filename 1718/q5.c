#include <stdio.h>
#define N 4

void maximum(double a[]) {
    double max = a[0];
    int i;
    for (i = 1; i < N; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    printf("Maximum of four numbers 10.5, 20.2, 19.9, 5.9 is: %.1f", max);
}

int main(void) {
    double a[4] = {10.5, 20.2, 19.9, 5.9};
    maximum(a);
    return 0;
}