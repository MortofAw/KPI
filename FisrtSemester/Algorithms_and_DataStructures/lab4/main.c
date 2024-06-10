#include <stdio.h>
#define n 8

int main() {
    int A[n][n], i, j, negn = -1, negm = -1, posn = -1, posm = -1;

    for (i = 0; i <= n - 1; i++) {
        for (j = 0; j <= n - 1; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (i = 0; i <= n - 1; i++) {
        if (A[i][n - 1 - i] < 0) {
            negn = i; negm = n - 1 - i; break;
        }
    }
    for (j = 0; j <= n - 1; j++) {
        if (A[n - 1 - j][j] > 0) {
            posn = n - 1 - j; posm = j; break;
        }
    }

    printf("Matrix before transposition:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("[%6d] ", A[i][j]);
        }
        printf("\n");
    }

    if (negn == -1 || posn == -1) printf("Error\n");
    else {
        i = A[posn][posm];
        A[posn][posm] = A[negn][negm];
        A[negn][negm] = i;
    }

    printf("Matrix after transposition:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("[%6d] ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}