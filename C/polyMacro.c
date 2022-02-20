/* Computes the value of a polynomial using a parameterized macro. */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define POLYNOMIAL(x) 3.0f*(pow((x), 5)) + 2.0f*(pow((x), 4)) - 5.0f*(pow((x), 3)) - (pow((x), 2)) + 7.0f*(x) - 6.0f

int main(int argc, char** argv) {

    if(argc < 2) {
        fprintf(stderr, "Usage ./polyMacro x\nx: a real number.");
        return 1;
    }

    float x = atof(argv[1]);

    printf("The image of %.1f in the polynomial is %.1f.\n", x, POLYNOMIAL(x));

    return 0;

}