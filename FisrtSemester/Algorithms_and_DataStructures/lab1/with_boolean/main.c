#include <stdio.h>

int main() {

	float x, y;
	printf("Input x: ");
	scanf("%f", &x);

	if ((x > -21) && (x <= 3) || (x > 12)) {
		y = -14 * x - 20;
		printf("y = %f\n", y);
	}
	else {
		if (x <= -41) {
			y = 13 * x * x / 11 - 6;
			printf("y = %f\n", y);
		}
		else {
			printf("Y doesn't exist\n");
		}
	}
	return 0;
}