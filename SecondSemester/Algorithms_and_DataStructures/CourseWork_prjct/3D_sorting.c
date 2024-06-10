#include "common.h"
#include <time.h>

//сортування масиву матедом Select2
clock_t Select2()
{
	int imin;
	int jmin;

	int tmp;

	int istart;
	int jstart;

	clock_t time_start;
	clock_t time_stop;

	time_start = clock();// початок виміру часу

	for(int k = 0; k <= P - 1; k++)// зміна індексу перерізу
	{
	    imin = 0;
		jmin = 0;
		
		istart = 0;//
		jstart = 0;//визначення границі вже відсортованих елементів
	
		for(int s = 0; s < M * N - 1; s++)
		{
			imin = istart;
			jmin = jstart;

			for(int i = istart + 1; i <= M - 1; i++)//прохід по стовпцю лівої границі
			{
				if(Arr3D[k][imin][jmin] > Arr3D[k][i][jstart])
				{
					imin = i;
				}
			}
		
			for(int j = jstart + 1; j <= N - 1; j++)//прохід по області після стопця границі
			{
				for(int i = 0; i <= M - 1; i++)
				{
					if(Arr3D[k][imin][jmin] > Arr3D[k][i][j])
					{
						imin = i;
						jmin = j;
					}
				}
			}

			tmp = Arr3D[k][imin][jmin];
			Arr3D[k][imin][jmin] = Arr3D[k][istart][jstart];
			Arr3D[k][istart][jstart] = tmp;

			if(istart + 1 > M - 1){//для НЕ виходу за межі під час зміщення границі
				istart = 0;
				jstart++;
			}
			else istart++;

		}
	}

	time_stop = clock();//кінець виміру часу

	return time_stop - time_start;
}

//сортування масиву матедом Select7
clock_t Select7()
{
	int Min;
	int Max;

	int iL;
	int jL;
	int iR;
	int jR;

	int imin;
	int jmin;
	int imax;
	int jmax;

	clock_t time_start;
	clock_t time_stop;

	time_start = clock();// початок виміру часу

	for(int k = 0; k <= P - 1; k++)
	{
		iL = 0; 
		jL = 0;
		iR = M - 1; 
		jR = N - 1;
	
		while(jL < jR)//"Звуження" границь(L&&R) по стовпцям
		{
			Min = Arr3D[k][iL][jL]; imin = iL; jmin = jL;
			Max = Arr3D[k][iL][jL]; imax = iL; jmax = jL;

			for(int i = iL + 1; i <= M - 1; i++)//пошук по стовцю L границі
			{
				if(Arr3D[k][i][jL] < Min)
				{
					Min = Arr3D[k][i][jL];
					imin = i; jmin = jL;
				}
				if(Arr3D[k][i][jL] > Max)
				{
					Max = Arr3D[k][i][jL];
					imax = i; jmax = jL;
				}
				
			}

			for(int j = jL + 1; j <= jR - 1; j++)//пошук по блоку до границі R
			{
				for(int i = 0; i <= M - 1; i++)
				{
					if(Arr3D[k][i][j] < Min)
					{
						Min = Arr3D[k][i][j];
						imin = i; jmin = j;
					}
					if(Arr3D[k][i][j] > Max)
					{
						Max = Arr3D[k][i][j];
						imax = i; jmax = j;
					}
				}
			}
		
			//ітерація до стовця границі вже відбулась у попередньому циклі

			for(int i = 0; i <= iR; i++)//пошук по стовпцю границі R
			{
				if(Arr3D[k][i][jR] < Min)
				{
					Min = Arr3D[k][i][jR];
					imin = i; jmin = jR;
				}
				if(Arr3D[k][i][jR] > Max)
				{
					Max = Arr3D[k][i][jR];
					imax = i; jmax = jR;
				}
			}
			
			if (jmin != jL || imin != iL) {
				Arr3D[k][imin][jmin] = Arr3D[k][iL][jL];
				Arr3D[k][iL][jL] = Min;
			}
			if (jmax != jR || imax != iR){
				if (imax == iL && jmax == jL) 
					Arr3D[k][imin][jmin] = Arr3D[k][iR][jR];				
				else 
					Arr3D[k][imax][jmax] = Arr3D[k][iR][jR];				
				
				Arr3D[k][iR][jR] = Max;
			}

			//умови не виходу за межі масива 
			if(iL + 1 > M - 1)
			{
				iL = 0;
				jL = jL + 1;
			}
			else
				iL++;

			if(iR - 1 < 0)
			{
				iR = M - 1;
				jR--;
			}
			else
				iR--;
			
		}
		
		//Стовпці повинні бути рівними або jR або jL(індекси одного стовця)

		while(iL < iR && jL == jR)//"Звуження" границь(L&&R) по рядках
 		{
			Min = Arr3D[k][iL][jL]; imin = iL; jmin = jL;
			Max = Arr3D[k][iL][jL]; imax = iL; jmax = jL;

			for(int i = iL + 1; i < iR + 1; i++)
			{
				if (Arr3D[k][i][jR] < Min)
				{
					Min = Arr3D[k][i][jR];
					imin = i; jmin = jR;
				}
				else if(Arr3D[k][i][jR] > Max)
				{
					Max = Arr3D[k][i][jR];
					imax = i; jmax = jR;
				}
			}

			if (imin != iL) {
				Arr3D[k][imin][jmin] = Arr3D[k][iL][jL];
				Arr3D[k][iL][jL] = Min;
			}
			if (imax != iR){
				if (imax == iL) 
					Arr3D[k][imin][jmin] = Arr3D[k][iR][jR];				
				else 
					Arr3D[k][imax][jmax] = Arr3D[k][iR][jR];				
				
				Arr3D[k][iR][jR] = Max;
			}

			iL = iL + 1; iR = iR - 1;
		}
	}

	time_stop = clock();//кінець виміру часу

	return time_stop - time_start;
}

//сортування масиву матедом Exchange2
clock_t Exchange2()
{
	int iR;
	int jR;

	int iprev;
	int jprev;
	
	int flag;
	
	int tmp;

	clock_t time_start;
	clock_t time_stop;
	
	time_start = clock();// початок виміру часу

	for(int k = 0; k <= P - 1; k++){
	
		iR = M - 1; 
		jR = N - 1;
		
		flag = 1;

		while(flag == 1)
		{
			flag = 0;
			iprev = 0;// 
			jprev = 0;//для індксів останнього перевіренного на коректність розташування елемента

			for(int j = 0; j <= jR - 1; j++)//прохід по області до стопця границі
			{
				for(int i = 0; i <= M - 1; i++)
				{
					if(Arr3D[k][iprev][jprev] > Arr3D[k][i][j])
					{
						tmp = Arr3D[k][iprev][jprev];
						Arr3D[k][iprev][jprev] = Arr3D[k][i][j];
						Arr3D[k][i][j] = tmp;
						flag = 1;
					}
					iprev = i; jprev = j;
				}
			}

			//ітерація до стовця границі вже відбулась у 1-му циклі

			for(int i = 0; i <= iR; i++)//прохід по стовпцю границі
			{
				if(Arr3D[k][iprev][jprev] > Arr3D[k][i][jR])
				{
					tmp = Arr3D[k][iprev][jprev];
					Arr3D[k][iprev][jprev] = Arr3D[k][i][jR];
					Arr3D[k][i][jR] = tmp;
					flag = 1;
				}
				iprev = i; jprev = jR;
			}

			if(iR-1 < 0){//для НЕ виходу за межі під час зміщення границі
				iR = M-1;
				jR--;
			}
			else iR--;

		}

	}

	time_stop = clock();//кінець виміру часу

	return time_stop - time_start;
}
