/* Tutorial 2 computing interest */

#include <stdio.h>

int main(void)
{
    int s = 1000;
    float debt = s;
    float rate = 0.03;
    float interest, total_interest, frac;

    for (int month = 1; month < 25; month++)
    {
        interest = debt * rate;
        total_interest += interest;
        frac = total_interest / s * 100;
        debt += interest;
        printf("month %2d: debt=%7.2f, interest=%5.2f, total_interest=%.2f, frac=%.2f%%\n", month, debt, interest, total_interest, frac);
    }

    return 0;
}