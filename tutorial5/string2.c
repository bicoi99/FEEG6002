/* Tutorial 5 left strip string */

#include <stdio.h>

/* Function void lstrip(char s[])
modifies the string s: if at the end of the string s there are one or more spaces,
then remove these from the string.
The name lstrip stands for left STRIP, trying to indicate that spaces at the 'left'
end of the string should be removed.
*/
void lstrip(char s[])
{
    int start = 0, i = 0;
    while (s[start] == ' ')
    {
        start++;
    }
    for (i = 0; i < 1000; i++)
    {
        s[i] = s[i + start];
        if (s[i + start] == '\0')
        {
            break;
        }
    }
}

int main(void)
{
    char test1[] = "     Hello World";
    printf("Original string reads : |%s|\n", test1);
    lstrip(test1);
    printf("l-stripped string reads: |%s|\n", test1);
    return 0;
}