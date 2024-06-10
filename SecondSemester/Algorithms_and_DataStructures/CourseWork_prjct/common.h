#ifndef __COMMON_H__
#define __COMMON_H__

#define M 2//
#define N 50//
#define P 1// розміри масиву A[P,M,N]
#define Vec_Length M * N * P // розмір вектора

extern int*** Arr3D;
extern int Vector[Vec_Length];

void memory_alloc();//
void memory_free();// виділення та звільнення пам'яті для масиву

#endif// __COMMON_H_ 
