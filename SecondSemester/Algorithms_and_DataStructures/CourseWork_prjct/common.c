#include "common.h"
#include <stdlib.h>

int*** Arr3D;
int Vector[Vec_Length];

void memory_alloc()
{
	 Arr3D = (int***) malloc(P*sizeof(int**));
	 for (int k=0; k<P; k++)
	 { 
		 Arr3D[k] = (int**) malloc(M*sizeof(int*));
		 for (int i=0; i<M; i++)
		 	Arr3D[k][i] = (int*) malloc(N*sizeof(int));
	 }
}

void memory_free()
{
	for (int k=0; k<P; k++)
	{ 
		for (int i=0; i<M; i++)
			free(Arr3D[k][i]);
	
		free(Arr3D[k]);
	}
	free(Arr3D);
}

