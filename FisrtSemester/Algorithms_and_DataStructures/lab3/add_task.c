#include <stdio.h>
#include<stdlib.h>

int main() {
    int n,b;
    printf("Enter n: ");
    scanf("%d", &n);
    int* A = (int*)malloc(sizeof(int) * 4 * n);
    printf("Our array A:\n");

    for (int i = 0; i <= 4 * n - 1; i++) {
        A[i] = i + 1;
        printf("%d ", A[i]);
    }
    for (int i = 0; i <= n - 1; i++) {
        b = A[n - 1 - i];
        A[n - 1 - i] = A[3 * n - 1 - i];
        A[3 * n - 1 - i] = A[4 * n - 1 - i];
        A[4 * n - 1 - i] = A[n + i];
        A[n + i] = b;
    }
    printf("\n\nArray A created with additional array B:\n");
    for (int i = 0; i <= 4 * n - 1; i++) {
        printf("%d ", A[i]);
    }
    free(A);
}