#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *center(char *s, int n) {
    char *ret = (char *)malloc(n * sizeof(char));
    int i, j;
    int slen = strlen(s);
    if (ret == NULL) {
        printf("Out of memory");
    }
    for (i = 0; i < n; i++) {
        ret[i] = '-';
    }
    for (j = 0; j < slen; j++) {
        ret[(n - slen) / 2 + j] = s[j];
    }
    return ret;
}

int main(void) {
    char s[] = "cat";
    char *ret;
    ret = center(s, 5);
    printf("%s\n", ret);
    free(ret);
    ret = center(s, 6);
    printf("%s\n", ret);
    free(ret);
    ret = center(s, 7);
    printf("%s\n", ret);
    free(ret);
    return 0;
}