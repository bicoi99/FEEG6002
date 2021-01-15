#include <stdio.h>

int product(int a, int b, int c)
{
    return a * b * c;
}

int main(void)
{
    printf("Result = %d\n", product(1, 2, 3));
    return 0;
}