#include <stdio.h>

int main() {
	float x, y = 0;
	printf("Input x: ");
	scanf("%f", &x);

	printf("With Boolean Operation-------------------------------------\n");
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

	printf("Without Boolean Operation-------------------------------------\n");
	if (x <= -41) {
		y = 13 * x * x / 11 - 6;
	}
	else if (x <= -21) {
		printf("Y doesn't exist\n");
		return 0;
	}
	else if (x <= 3) {
		y = -14 * x - 20;
	}
	else if (x <= 12) {
		printf("Y doesn't exist\n");
		return 0;
	}
	else {
		y = -14 * x - 20;
	}
	printf("y = %f\n", y);

	return 0;
}
