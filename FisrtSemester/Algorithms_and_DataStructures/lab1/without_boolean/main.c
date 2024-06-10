#include <stdio.h>

int main()
{
    float x, y = 0;
    printf("Input x: ");
    scanf("%f", &x);

    if (x <= -41) {
        y = 13 * x * x / 11 - 6;
    }
    else if (x <= -21) {
        printf("Y doesn't exist");
        return 0;
    }
    else if (x <= 3) {
        y = -14 * x - 20;
    }
    else if (x <= 12) {
        printf("Y doesn't exist");
        return 0;
    }
    else {
        y = -14 * x - 20;
    }
    printf("y = %f\n", y);
    return 0;
}
