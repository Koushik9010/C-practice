#include <stdio.h>

void find_replace(char STR[], char PTR[], char REP[]) {
    int i, j, k, l, m, n;

    // PTR length = l
    // REP length = m
    // STR length = n

    l = 0;
    while (PTR[l]) {
        l++;
    }
    m = 0;
    while (REP[m]) {
        m++;
    }
    n = 0;
    while (STR[n]) {
        n++;
    }

    for (i = 0; i <= n - l; i++) {
        k = i;
        for (j = 0; j < l; j++) {
            if (STR[k] != PTR[j]) {
                break;
            }
            k++;
        }
        if (j == l) {
            for (j = 0; j < m; j++) {
                STR[i + j] = REP[j];
            }
            for (j = i + m; j <= n; j++) {
                STR[j] = STR[j + l - m];
            }
            n = n - l + m;
        }
    }
}

int main() {
    char STR[100], PAT[100], REP[100];

    printf("\n\nEnter the main string: ");
    scanf("%s", STR);

    printf("\n\nEnter the pattern string: ");
    scanf("%s", PTR);

    printf("\n\nEnter the replace string: ");
    scanf("%s", REP);

    find_replace(STR, PTR, REP);

    printf("Modified string: %s\n", STR);

    return 0;
}
