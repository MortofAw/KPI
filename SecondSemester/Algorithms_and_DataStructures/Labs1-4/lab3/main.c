#include <math.h>
#include <stdio.h>

double Recurs_Down(double prev, double indexF, int n) {

 	double item = (cos(indexF) + 2 * sqrtf(fabs(prev)));


	if (indexF < n) {
//		double s += Recurs_Down(item, indexF + 1, n);
//		return s;
	} else {
		return item;
	}
}

double Recurs_Up(int n,double* s) {
  	if (n == 1) {
		*s += 1.0;
		return 1.0;
	}

	double item = (cos(n) + 2 * sqrtf(fabs(Recurs_Up(n-1, s))));
	
	*s += item;

	return item;
}

double Recurs_Up_Down(double indexF, double prev, int n) {

	
	if (indexF > n) {
		return (cos(indexF) + 2 * sqrtf(fabs(prev)));
	} else {
	double item = (cos(indexF) + 2 * sqrtf(fabs(prev)));
		return item + Recurs_Up_Down(indexF + 1, item, n);
	}
}

int main(void) {
	int n = 0;
	
	while (n < 1) {
		printf("n >= 1 --> ");
		scanf("%d", &n);
	}
	
	double s;
	double F1;
	double res;
	
	//Спуск
	F1 = 1.0;
	//res = F1 + Recurs_Down();
	printf("Recurs_Down    --> %f\n", res);
	
	//Повернення
	s = 0.0;
	Recurs_Up(n, &s);//беремо адресу корміки суми і передаємо її параметром
	printf("Recurs_Up      --> %f\n", s);
	
	//Спукс + Повернення 
	F1 = 1.0;
	res = F1 + Recurs_Up_Down(2, F1, n);
	printf("Recurs_Up_Down --> %f\n", res);
	
	//Цикл
	s = 1.0;
	double item = 1.0;

	for (double indexF = 2; indexF <= n; indexF++) {
		item = cos(indexF) + 2 * sqrtf(fabs(item));
		s += item;
	}
	printf("FOR Cycle      --> %f", s);
	
	
	return 0;
}
