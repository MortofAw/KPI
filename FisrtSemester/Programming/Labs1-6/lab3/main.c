#include <stdio.h>
#include <math.h>
#define size 6 //Compiler doesn't initialize the matrix with 'const', so...

void CreatMatrix(double Matrix[size][size], int n);
void TrnsposeMatrix(double Matrix[size][size], int n);
void PrintMatrix(double Matrix[size][size], int n);
void PrintVector(double Matrix[size], int n);
void FormatMatrix(double Matrix[size][size], double Vector[size], int n);
void DevisionFunc(double Vector[size], double* FunctionG, int n);

int main() {
    double m[size][size], x[size],g=1.0;

    CreatMatrix(&m, size);
    printf("-----|Filling matrix A:\n");
    PrintMatrix(&m, size);

    TrnsposeMatrix(&m, size);
    printf("-----|Transpose matrix A:\n");
    PrintMatrix(&m, size);

    FormatMatrix(&m, &x, size);
    printf("-----|Vector X:\n");
    PrintVector(&x, size);

    DevisionFunc(&x, &g, size);
    printf("-----|Function U :\n [%11f]\n\n", g);

    return 0;
}

void PrintVector(double Vector[size], int n) {
    for (int i = 0; i <= n - 1; i++) { // Print vector
            printf(" [%11f]", Vector[i]);
    }
        printf("\n\n");
}

void PrintMatrix(double Matrix[size][size], int n) {
    for (int i = 0; i <= n - 1; i++) { // Print matrix
        for (int j = 0; j <= n - 1; j++) {
            printf(" [%11f]", Matrix[i][j]);
        }
        printf("\n\n");
    }
}

void CreatMatrix(double Matrix[size][size], int n) {
    for (int i = 0; i <= n-1; i++) { //Filling array
        for (int j = 0; j <= n-1; j++) {
            Matrix[i][j] = 2 * exp(j) - 0.879 * i * i + 13.2 * j;
        }
    }
}

void TrnsposeMatrix(double Matrix[size][size], int n) {
    for (int i = 0; i <= n - 1; i++) { //Transposition array
        for (int j = 0; j <= n - 1; j++) {
            if (Matrix[i][j] == Matrix[i][n - 1 - i]) { // If [i][j] - on the diagonal
                break;
            }
            else {
                double temp = Matrix[i][j];
                Matrix[i][j] = Matrix[n-1-j][n-1-i];
                Matrix[n - 1 - j][n - 1 - i] = temp;
            }
        }
    }
}

void FormatMatrix(double Matrix[size][size], double Vector [size], int n){
    for (int i = 2;;) { //Vector X is:
        for (int j = 0; j <= n - 1; j++) {
                Vector[j] = Matrix[i][j];
        }
        break;
    }
}

void DevisionFunc(double Vector[size], double* FunctionG, int n) {
    for (int i = 0; i < n -1 ; i++) { // Product of series
        *FunctionG *= 1 / (fabs(Vector[i]) + 1) + Vector[i + 1];
    }
}