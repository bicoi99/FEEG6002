/* Tutorial 7 mixing strings */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int strlen(char *s1)
{
    for (int i = 0; i < MAXLINE; i++)
    {
        if (s1[i] == '\0')
        {
            return i + 1;
        }
    }
}

char *mix(char *s1, char *s2)
{
    char *r;
    int n = strlen(s1);
    r = (char *)malloc(2 * n * sizeof(char));
    if (r == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < 2 * n; i++)
    {
        if (i % 2 == 0)
        {
            r[i] = s1[i / 2];
        }
        else
        {
            r[i] = s2[(int)i / 2];
        }
    }
    return r;
}

int main(void)
{
    char s1[] = "HelloWorld";
    char s2[] = "123456789!";

    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);
    printf("r = %s\n", mix(s1, s2));

    return 0;
}