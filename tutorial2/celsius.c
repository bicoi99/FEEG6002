/* Tutorial 2 degreeC/degreeF table */

#include <stdio.h>

int main(void)
{
    double tempF;
    for (int tempC = -30; tempC <= 30; tempC += 2)
    {
        tempF = tempC * (9.0 / 5.0) + 32.0;
        printf("%3d = %5.1f\n", tempC, tempF);
    }

    return 0;
}