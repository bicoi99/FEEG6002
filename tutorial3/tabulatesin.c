/* Tutorial 3 tabulate sin function */

#include <stdio.h>
#include <math.h>

/* Define symbolic constants */
#define N 10
#define XMIN 1
#define XMAX 10

int main(void)
{
    double x, f;
    for (int i = 0; i < N; i++)
    {
        x = XMIN + (XMAX - XMIN) / (N - 1) * i;
        f = sin(x);
        printf("%f %f\n", x, f);
    }

    return 0;
}