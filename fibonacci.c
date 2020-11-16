/* Tutorial 6 Fibonacci numbers array*/

#include <stdio.h>
#include <stdlib.h>

long *make_long_array(long n)
{
    long *arr;
    arr = (long *)malloc(sizeof(long) * n);

    if (arr == NULL)
    {
        printf("Memory allocation failed");
        return NULL;
    }

    return arr;
}

long *make_fib_array(long n)
{
    long *fibs = make_long_array(n);

    if (fibs == NULL)
    {
        return NULL;
    }

    fibs[0] = 0;
    fibs[1] = 1;

    for (int i = 2; i < n; i++)
    {
        fibs[i] = fibs[i - 2] + fibs[i - 1];
    }

    return fibs;
}

void use_fib_array(long N)
{
    /* N is the maximum number for fibarray length */
    long n;         /* counter for fibarray length */
    long i;         /* counter for printing all elements of fibarray */
    long *fibarray; /* pointer to long -- pointer to the fibarray itself*/
    /* Print one line for each fibarray length n*/
    for (n = 2; n <= N; n++)
    {
        /* Obtain an array of longs with data */
        fibarray = make_fib_array(n);
        /* Print all elements in array */
        printf("fib(%2ld) : [", n);
        for (i = 0; i < n; i++)
        {
            printf(" %ld", fibarray[i]);
        }
        printf(" ]\n");
        /* free array memory */
        free(fibarray);
    }
}

int main(void)
{
    use_fib_array(10);
    return 0;
}