

#include <stdio.h>
#include <stdlib.h>

double polynomial(double x) {
    double answer;
    answer = 3*(x*x*x*x*x) + 2*(x*x*x*x) - 5*(x*x*x) - (x*x) + 7*x + 6;
    return answer;
}

int main(void) {
    
    double x;
    
    printf("This program solves the polynomial p(x) = 3x^5 + 2x^4 - 5x^3 - x^2 + 7x + 6.\nEnter a value for the x: ");
    scanf("%lf", &x);

    printf("p(%.3f) = %.3f", x, polynomial(x));
}