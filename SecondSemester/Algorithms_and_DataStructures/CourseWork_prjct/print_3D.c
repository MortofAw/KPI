#include "common.h"
#include <stdio.h>

// функція виводу масива
void print3D(){
	for(int k = 0; k <= P - 1; k++)
	{
		printf("P = %d\n", k);
		for(int j = 0; j <= M - 1; j++)
		{
			for(int i = 0; i <= N - 1; i++)
				printf("%d ", Arr3D[k][j][i]);
			printf("\n");
		}	
		printf("\n");
	}		
}
