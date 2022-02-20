#include <stdio.h>
#define ABS(x) ((x) < 0 ? (-x) : (x))

int main(void)
{
    double x;

    printf("Enter a value: ");
    scanf("%lf", &x);

    printf("The absolute value of %f is %f.\n", x, ABS(x));

    return 0;
}
