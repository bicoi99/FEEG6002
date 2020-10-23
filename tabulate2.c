/* Tutorial 3 tabulate sin and cos functions */

#include <stdio.h>
#include <math.h>

/* Define symbolic constants */
#define N 10
#define XMIN 1
#define XMAX 10

int main(void)
{
    double x;
    for (int i = 0; i < N; i++)
    {
        x = XMIN + (XMAX - XMIN) / (N - 1) * i;
        printf("%f %f %f\n", x, sin(x), cos(x));
    }

    return 0;
}