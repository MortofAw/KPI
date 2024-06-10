#include <stdio.h>
#include <math.h>

float f(float x)
{
	return (sin(x)/cos(x) * sqrt(0.378*log2(4.56 + x) + x));
}

float trapecio(float (*func)(float), float a, float b, float n)
{
	float res;
	float h;
	float x;

	int index = 1;
	
	res = 0.0;
	h = (b-a)/n;
	for(x = a + h; x < b; x += h)
	{
		if(index == 1 || index == n)
			res += 1.0/2.0 * (*func)(x);
		else
			res += (*func)(x);

		index++;
	}
	return res * h;
}

int main(void)
{
	float epsilon = 0.0001;
	float i1;
	float i2;
	float delta;

	int step = 10;
	int i = 1;

	do
	{
		i1 = trapecio(f, 0.3, 1.0, i * step);
		i *= 2;
		i2 = trapecio(f, 0.3, 1.0, i * step);
		delta = 1.0 / 3.0 * fabs(i1 - i2);
	}
	while(delta >= epsilon);

	printf("Integer is = %.4f", i2);
}
