#include <stdio.h>

#define SIZE 10

void printArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void copyarrays(int a[], int b[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        b[i] = a[i];
    }
}

int main() {
    int a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[SIZE];
    printf("Values before copy: ");
    printArray(b, SIZE);
    printf("\nValues after copy: ");
    copyarrays(a, b, SIZE);
    printArray(b, SIZE);
    return 0;
}