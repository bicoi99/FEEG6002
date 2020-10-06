/* Tutorial 1 printfwhat */

#include <stdio.h>

int main(void)
{
    int i;

    i = printf("What am I doing?\n");

    printf("%d", i); // i is the length of the string inside the printf

    return 0;
}