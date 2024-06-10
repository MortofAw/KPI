#include <stdio.h>
#define n 4

int main() {
    int A[n][n];
    int i, j;
    int min, max, minn = -1, minm = -1, maxn = -1, maxm = -1;

    for (i = 0; i <= n - 1; i++) {
        for (j = 0; j <= n - 1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (i = 0; i <= n - 1; i++) {
        if (i == 0) {
            min = A[i][i];
            minn = minm = i;
        }
        if (A[i][i] < min) {
            minn = minm = i;
            min = A[i][i];
        }
    }
    for (i = 0; i <= n - 1; i++) {
        if (i == 0) {
            max = A[n - 1 - i][n - 1 - i];
            maxn = maxm = n - 1 - i;
        }
        if (A[n - 1 - i][n - 1 - i] > max) {
            maxn = maxm = n - 1 - i;
            max = A[n - 1 - i][n - 1 - i];
        }
    }

    printf("Matrix :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("[%6d] ", A[i][j]);
        }
        printf("\n");
    }

    if (minn == -1 || maxn == -1) printf("Error\n");
    else {
        printf("Min: %d; PosMin: %d-%d \n", min, minn, minm);
        printf("Max: %d; PosMax: %d-%d \n", max, maxn, maxm);
    }
    return 0;
}