#include <stdio.h>
#include <math.h>

int main() {
	double  mult, S;
	int i, j, n;
	printf("------------------------|Input your n: ");
	scanf("%d", &n);
	if (n > 0) {
		printf("------------------------|Math programming\n");
		S = 0;
		for (i = 1; i <= n; i++) {
			mult = 1;
			for (j = 1; j <= i; j++) {
				mult *= ((j + 1) * sin(j));
			}
			S += (mult / (i * (i + 1)));
		}
		printf("                                   Sum = [%9.7Lf]\n", S);
		printf("------------------------|Dynamic programming\n");
		S = 0; mult = 1;
		for (i = 1; i <= n; i++) {
			mult *= ((i + 1) * sin(i));
			S += (mult / (i * (i + 1)));
		}
		printf("                                   Sum = [%9.7Lf]\n\n\n", S);
	}
	else printf("Error, during devision by 0(no decision has been made)\n");
	return 0;
}
