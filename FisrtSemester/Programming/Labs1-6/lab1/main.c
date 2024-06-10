#include <stdio.h>
#include <math.h>

int main() {
	float x, y, z, a, b;

	printf("----Function value calculation--------------|\n");
	printf("|\n------------------------------");
	printf("\nInput x: ");
	scanf("%f", &x);
	printf("\nInput y: ");
	scanf("%f", &y);
	printf("\nInput z: ");
	scanf("%f", &z);

	printf("\n------------------------------\n\n");
	
	//Calculating "a"------------------------------------------|
	if (x * x + y * y - 2 == 0) {
		printf("Error1: Expression (x^2+y^2-2) can't be = %d\n", x*x + y*y- 2);
	}
	else {
		a = ((cbrt(9 - ((fabs(x - y)) * (fabs(x - y))))) / (x * x + y * y - 2));
		printf("A == [%12.9f]\n", a);
	}

	printf("\n------------------------------\n\n");

	//Calculating "b"------------------------------------------|
	if (z == 0) {
		printf("Error2: (Z) can't be = %d\n\n", z);
	}
	else {
		b = cos(atan(1 / z)) * cos(atan(1 / z));
		printf("B == [%12.9f]\n\n", b);
	}

	return 0;
}