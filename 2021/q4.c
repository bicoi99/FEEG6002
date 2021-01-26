#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Votes {
    char state[100];
    long dempv;
    long demev;
    long reppv;
    long repev;
} votes;

int count_lines(char *fileName) {
    FILE *fp;
    char c;
    int cnt = 0;
    if ((fp = fopen(fileName, "r")) == NULL) {
        printf("Cannot open file for reading.");
        return -1;
    }
    for (c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n') {
            cnt++;
        }
    }
    if (fclose(fp) != 0) {
        printf("Cannot close file.");
        return -1;
    }
    return cnt + 1;
}

void initialise_votes(char *fileName, votes *arr, int n) {
    FILE *fp;
    int i;
    if ((fp = fopen(fileName, "r")) == NULL) {
        printf("Cannot open file for reading.");
    }
    for (i = 0; i < n; i++) {
        fscanf(fp, "%s\t%ld\t%ld\t%ld\t%ld", arr[i].state, &arr[i].dempv,
               &arr[i].demev, &arr[i].reppv, &arr[i].repev);
    }
    if (fclose(fp) != 0) {
        printf("Cannot close file.");
    }
}

void print_list(votes *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%-14s\t%-8ld\t%-3ld\t%-8ld\t%-3ld\n", arr[i].state,
               arr[i].dempv, arr[i].demev, arr[i].reppv, arr[i].repev);
    }
}

votes print_vote_state(votes *arr, int n) {
    votes maxstate;
    int i;
    maxstate = arr[0];
    for (i = 1; i < n; i++) {
        if ((arr[i].dempv + arr[i].reppv) > (maxstate.dempv + maxstate.reppv)) {
            maxstate = arr[i];
        }
    }
    return maxstate;
}

const char *print_vote_total(votes *arr, int n) {
    /* Store votes total with sum array {dempv, demev, reppv, repev} */
    long sum[4] = {0, 0, 0, 0};
    int i;
    for (i = 0; i < n; i++) {
        sum[0] += arr[i].dempv;
        sum[1] += arr[i].demev;
        sum[2] += arr[i].reppv;
        sum[3] += arr[i].repev;
    }
    printf("Dem. pop. vote total: %ld\n", sum[0]);
    printf("Dem. el. vote total: %ld\n", sum[1]);
    printf("Rep. pop. vote total: %ld\n", sum[2]);
    printf("Rep. el. vote total: %ld\n", sum[3]);
    if (sum[1] - sum[3] > 0) {
        return "Dem. wins";
    } else {
        return "Rep. wins";
    }
}

int main() {
    char fileName[] = "uselection2012.txt";
    int nlines;
    votes *arr, maxstate;

    nlines = count_lines(fileName);
    arr = (votes *)malloc(nlines * sizeof(votes));

    initialise_votes("uselection2012.txt", arr, nlines);
    print_list(arr, nlines);
    printf("\n");
    maxstate = print_vote_state(arr, nlines);
    printf("%s wins with %ld (dem) and %ld (rep) popular votes.\n",
           maxstate.state, maxstate.dempv, maxstate.reppv);
    printf("\n");
    printf("%s\n", print_vote_total(arr, nlines));

    return 0;
}