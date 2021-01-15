#include <stdio.h>

int sum_integers()
{
    int sum = 0;
    int i;
    for (i = 1; i <= 10; i++)
        sum += i;
    return sum;
}

int main(void)
{
    printf("Sum = %d\n", sum_integers());
    return 0;
}