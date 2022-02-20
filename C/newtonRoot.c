/* Calculates the square root of a given number with the newtom-raphson method */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double absolute(float num)
{
    if(num < 0){
        num = -num;
    }
    return num;
}

int main(void) {
    double x, y;
    y = 1.0;

    printf("Enter a positive number: ");
    scanf("%lf", &x);
    
    while((absolute((y * y) - x)) >= 0.00001) {
        y = (y + (x/y))/2.0;
    }

    printf("Newton Root: %f", y);
}