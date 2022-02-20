#include <stdio.h>
#include <stdlib.h>
#define SIZE 2

double innerProduct (double *a, double *b, short n);

int main (void) {
    
    double a[SIZE], b[SIZE], *p = a, *q = b;

    printf ("Enter %d elements for the first vector: ", SIZE);
    for (; p < a + SIZE;) {
        scanf ("%Lf", p++);
    }

    printf ("Enter %d elements for the second vector: ", SIZE);
    for (; q < b + SIZE;) {
        scanf ("%Lf", q++);
    }

    printf ("a * b = %f", innerProduct(a, b, SIZE));

    return EXIT_SUCCESS;
}

double innerProduct (double *a, double *b, short n) {

    double sum, *p = a, *q = b;

    while(p < a + SIZE && q < b + SIZE) {
        sum += (*p++) * (*q++);
    }

    return sum;

}
