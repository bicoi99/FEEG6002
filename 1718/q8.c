#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 4

int main(void) {
    float values[] = {10.7, 13.4, 15.8, 19.2};
    float *valPtr[NUM];
    int i;
    float val, sum = 0., product = 1.;
    srand((unsigned)time(NULL));
    for (i = 0; i < NUM; i++) {
        valPtr[i] = &values[rand() % NUM];
    }
    printf("Data in valPtr:");
    for (i = 0; i < NUM; i++) {
        val = *valPtr[i];
        printf(" %.1f", val);
        sum += val;
        product *= val;
    }
    printf("\nSum: %.1f", sum);
    printf("\nProduct: %.1f", product);
    return 0;
}