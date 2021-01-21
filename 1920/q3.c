#include <stdio.h>
#include <string.h>

int sum(int n) {
    if (n == 0)
        return 0;
    else
        return n + sum(n - 1);
}

int main(void) {
    char s[12];
    strcpy(s, "welcome home");
    struct person {
        char lastName[15];
        char firstName[15];
        int age;
    };
    return 0;
}