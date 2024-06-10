#include <time.h>
#include <stdlib.h>
#include "common.h"

void orderedVecFill()
{
	for(int i = 0; i <= Vec_Length - 1; i++)
		Vector[i] = i;
}

void randomVecFill()
{
	srand(time(NULL));

	for(int i = 0; i <= Vec_Length - 1; i++)
		Vector[i]=rand () % (Vec_Length * 64);
}

void backOrderedVecFill()
{
	for(int i = 0; i <= Vec_Length - 1; i++)
		Vector[i] = Vec_Length - 1 - i;
}


