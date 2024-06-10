#include "common.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

//заповнення масиву впорядкованними значеннями
void ordered3DFill()
{
	int num = 0;
	for(int k = 0; k <= P - 1; k++)
	{
		for(int j = 0; j <= N - 1; j++)
		{
			for(int i = 0; i <= M - 1; i++)
				Arr3D[k][i][j] = num++;
		}	
	}		
}

//заповнення масиву довільними значеннями значеннями
void random3DFill()
{
	for(int k = 0; k <= P - 1; k++)
	{
		for(int j = 0; j <= N - 1; j++)
		{
			for(int i = 0; i <= M - 1; i++)
				Arr3D[k][i][j] = rand () % (P * M * N * 64);
		}	
	}		
} 

//заповнення масиву обернено впорядкованними значеннями
void backOrdered3DFill()
{
	srand(time(NULL));

	int num = 0;

	for(int k = 0; k <= P - 1; k++)
	{
		for(int j = 0; j <= N - 1; j++)
		{
			for(int i = 0; i <= M - 1; i++)
				Arr3D[k][i][j] = (P * M * N) - 1 - num++;
		}	
	}		
}
