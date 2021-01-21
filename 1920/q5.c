#include <stdio.h>

#define SIZE 10

void printArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void swapElements(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int a[], int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swapElements(&a[min], &a[i]);
    }
}

int main() {
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    printf("Data items in original order\n");
    printArray(a, SIZE);
    printf("\nData items in ascending order\n");
    selectionSort(a, SIZE);
    printArray(a, SIZE);
    return 0;
}