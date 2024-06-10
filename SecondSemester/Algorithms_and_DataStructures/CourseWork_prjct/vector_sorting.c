#include "common.h"
#include <time.h>

clock_t select2()// Алгоритм сортування №2 методу прямого вибору
{
	int imin; 
    int tmp;

	clock_t time_start;
	clock_t time_stop;
	 
	time_start = clock();

	for(int s = 0; s < Vec_Length - 1; s++)
	{
		imin = s;
	 	
		for(int i = s + 1; i < Vec_Length; i++)
	 		if (Vector[i] < Vector[imin]) imin = i;
			
	 	tmp = Vector[imin];
	 	Vector[imin] = Vector[s];
	 	Vector[s] = tmp;
	}
	 
	time_stop = clock();

	return time_stop - time_start;
}

clock_t select7()// Алгоритм сортування №7 методу прямого вибору
{
	int Min;
	int Max;

	int L;
	int R;

	int imin;
	int imax;

	clock_t time_start;
	clock_t time_stop;

	time_start = clock();
	
	L = 0; R = Vec_Length - 1;
	
	while (L < R)
	{
		Min = Vector[L]; imin = L;
		Max = Vector[L]; imax = L;
		
		for(int i = L + 1; i < R + 1; i++)
		{
			if (Vector[i] < Min)
			{
				Min = Vector[i];
				imin = i;
			}
			else if(Vector[i] > Max)
			{
				Max = Vector[i];
				imax = i;
			}
		}
		if (imin != L) {
			Vector[imin] = Vector[L];
			Vector[L] = Min;
		}
		if (imax != R){
			if (imax == L) 
				Vector[imin] = Vector[R];
			else 
				Vector[imax] = Vector[R];
			Vector[R] = Max;
		}
		L = L + 1; R = R - 1;
	}

	time_stop = clock();

	return time_stop - time_start;
}

clock_t exchange2()// Алгоритм сортування №2 методу прямого обміну
{
	int R;
	int flag;
	int tmp;

	clock_t time_start; 
	clock_t time_stop;

	time_start = clock();
	
	R = Vec_Length - 1; flag = 1;

	while(flag == 1){
		flag = 0;
		for(int i = 0; i < R; i++)
			if (Vector[i] > Vector[i+1]) 
			{
				tmp = Vector[i];
				Vector[i] = Vector[i + 1];
				Vector[i + 1] = tmp;
				flag = 1;
			}
		R--;
	}

	time_stop = clock();
	
	return time_stop - time_start;
}
