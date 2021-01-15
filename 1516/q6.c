#include <stdio.h>

double compute_mean(double data[], int n) {
    double sum;
    int i;
    for (i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum;
}

int main(void) {
    double data1[6] = {23.2, 31.5, 16.9, 27.5, 25.4, 28.6};
    double data2[6] = {10.0, 20.0};
    printf("The mean is %f.\n", compute_mean(data1, 6));
    printf("The mean is %f.\n", compute_mean(data2, 2));
    return 0;
}