#include <stdio.h>

void print(int n) {
    int x = 0;
    while (x < n) {
        printf("%d ", x);
        x++;
    }
}

int main() {
    print(10);
    return 0;
}