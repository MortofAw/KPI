#include <stdio.h>
#include<stdlib.h>

int main() {
    int n; 
    printf("Enter n: ");
    scanf("%d", &n);
    int* A = (int*)malloc(sizeof(int) * 4 * n),
        * A2 = (int*)malloc(sizeof(int) * 4 * n);//Array A2 for second algorithm 
/*    for (int i = 0; i < 4 * n; i++) {
        scanf("%d", &A[i]);
    }*/
    printf("Our array A:\n");
    for (int i = 0; i <= 4 * n - 1; i++) {
        A[i] = A2[i] = i + 1; //Filling array A and "copy" it in array A2
        printf("%d ", A[i]);
    }
    //With array B[]={}
    int* B = (int*)malloc(sizeof(int) * n), i, epart2 = 2 * n - 1, bpart3 = 2 * n, bpart4 = 3 * n, epart4 = 4 * n - 1;//e-end of,b-beginning of
    for (i = n; i <= epart2; i++) {// |2|->B; |~1~|->|2|
        B[i - n] = A[i];
        A[i] = A[epart2 - i];
    }
    for (i = bpart3; i <= bpart4 - 1; i++) {// |3|->|1|; B->|3|; |~4~|->B
        A[i - bpart3] = A[i];
        A[i] = B[i - bpart3];
        B[i - bpart3] = A[epart4 - i + bpart3];//4*n-1-i-2*n было 6*n-1-i
    }
    for (i = bpart4; i <= epart4; i++) {// B->|4|
        A[i] = B[i - bpart4];
    }
    printf("\n\nArray A created with additional array B:\n");
    for (i = 0; i <= 4 * n - 1; i++) {
        printf("%d ", A[i]);
    }

    //With variable int b
    int b, epart1 = n - 1;//e-end of,b-beginning of
    for (i = 0; i <= n / 2 - 1; i++) {// |2|->B; |~1~|->|2|
        b = A2[i];//|~1~|
        A2[i] = A2[epart1 - i];
        A2[epart1 - i] = b;
        b = A2[epart4 - i];//|~4~|
        A2[epart4 - i] = A2[bpart4 + i];
        A2[bpart4 + i] = b;
    }
    for (i = n; i <= 2 * n - 1; i++) {// |2|->B; |~1~|->|2|
        b = A2[i];//|3|->|2|; |2|->|3|
        A2[i] = A2[n + i];
        A2[i + n] = b;
        b = A2[i];//|2|->|1|
        A2[i] = A2[i - n];
        A2[i - n] = b;
    }
    printf("\n\nArray A created with additional variable b:\n");
    for (i = 0; i <= 4 * n - 1; i++) {
        printf("%d ", A2[i]);
    }
        free(A);
        free(B);
        return 0;
}
