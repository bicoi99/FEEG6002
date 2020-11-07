/* Tutorial 5 right strip string */

#include <stdio.h>

/* Function void rstrip(char s[])
modifies the string s: if at the end of the string s there are one or more spaces,
then remove these from the string.
The name rstrip stands for Right STRIP, trying to indicate that spaces at the 'right'
end of the string should be removed.
*/
void rstrip(char s[])
{
    int len;
    for (len = 0; len < 1000; len++)
    {
        if (s[len] == '\0')
        {
            break;
        }
    }
    while (s[len - 1] == ' ')
    {
        s[len - 1] = '\0';
        len--;
    }
}

int main(void)
{
    char test1[] = "Hello World     ";
    printf("Original string reads : |%s|\n", test1);
    rstrip(test1);
    printf("r-stripped string reads: |%s|\n", test1);
    return 0;
}