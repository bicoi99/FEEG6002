/* Tutorial 4 reverse string*/

#include <stdio.h>
#define MAXLINE 1000 /* maximum length of string */

/* function prototype */
void reverse(char source[], char target[]);
long string_length(char s[]);

int main(void)
{
    char original[] = "This is a test: can you print me in reverse character order?";
    char reversed[MAXLINE];
    printf("%s\n", original);
    reverse(original, reversed);
    printf("%s\n", reversed);
    return 0;
}

/* Function to compute string length */
long string_length(char s[])
{
    for (long i = 0; i < MAXLINE; i++)
    {
        if (s[i] == '\0')
        {
            return i;
        }
    }
}

/* Reverse the order of characters in 'source', write to 'target'. Assume 'target' is big enough. */
void reverse(char source[], char target[])
{
    long len = string_length(source);
    for (long i = 0; i < len; i++)
    {
        target[i] = source[len - 1 - i];
    }
    target[len] = '\0';
}