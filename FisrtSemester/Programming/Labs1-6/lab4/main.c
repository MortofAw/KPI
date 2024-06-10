#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define nmA 6 
#define nB 3
#define mB 54
#define mult nmA * nmA + nB * mB

void scanM(const int* M, int row, int col);
void printM(int* M, int row, int col);
int copy(int* M1, int* M2, int index);

int main() {
	int A[nmA][nmA], B[nB][mB];

	printf("Fill first matrix A: \n");
	scanM(&A[0][0], nmA, nmA);
	printf("Fill second matrix  B: \n");
	scanM(&B[0][0], nB, mB);

	printf("Matrix A: \n");
	printM(&A[0][0], nmA, nmA);
	printf("Matrix B: \n");
	printM(&B[0][0], nB, mB);

	printf("Array from matrix A & B: \n");
	for (int i = 0; i < mult; i++)
	{
	printf("[%3d] ", copy(&A[0][0], &B[0][0], i));
	}

	return 0;
}
void scanM(int* M, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
		scanf("%d", &M[i * col + j]);
		}
	}
}
void printM(int* M, int row, int col) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("[%3d] ", M[i* col +j]);
		}
		printf("\n");
	}
}
int copy(int* M1, int* M2, int index) {
	int temp[mult],b=0;

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < nmA * nmA; j++, b++) {
			temp[b] = M1[i * nmA* nmA + j];
		}
		for (int j = 0; j < nB * mB; j++, b++) {
			temp[b] = M2[i * nB * mB + j];
		}
	}
	return temp[index];
}