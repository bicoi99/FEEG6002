#include <stdio.h>
#include <stdlib.h>

int *zero_array(int n) {
    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Out of memory");
    }
    return a;
}

void print(int *a, int n) {
    int i = 0;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void delete_array(int *a) { free((void *)a); }

int main() {
    int n = 5;
    int *a = zero_array(n);
    print(a, n);
    delete_array(a);
    return 0;
}