#include <stdio.h>
#include "common.h"

// функція виводу вектору
void printV(){
	for (int i = 0; i < Vec_Length; i++)
	{
		printf ("%d ", Vector[i]);
	}
}
