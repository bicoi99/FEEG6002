/* Tutorial 3 user defined function */

#include <stdio.h>

/* define the user-defined function checkPrimeNumber here */
int checkPrimeNumber(int n);
int fastPrime(int n);

int main()
{
    int n1, n2, i, flag;
    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);
    printf("Prime numbers between %d and %d are: ", n1, n2);
    for (i = n1; i <= n2; i++)
    {
        if (fastPrime(i) == 1)
        {
            printf("\n%d", i);
        }
    }

    return 0;
}

/* add user-defined function checkPrimeNumber to check prime number here */
/* this function should check whether a number is prime or not */
int checkPrimeNumber(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

/* Optimized implementation of checking prime number */
/* Use input 1000000000 and 1000000030 to check speed difference */
int fastPrime(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    if (n <= 3)
    {
        return 1;
    }

    if (n % 2 == 0 || n % 3 == 0)
    {
        return 0;
    }

    for (int i = 5; i * i < n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return 0;
        }
    }

    return 1;
}