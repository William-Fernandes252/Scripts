/* Decompose a number */

#include <stdio.h>
#include <stdlib.h>

void decompose(double x, long *i, double *f);

int main(int argc, char ** argv) {
    
    char usage[] = "Usage: ./decompose followed by the number to decompose in its int part and fractional part.";

    if(argc != 2) {
        fprintf(stderr, "%s", usage);
        return EXIT_FAILURE;
    }

    double number = atof(argv[1]);

    long int_part = 0;
    double frac_part = 0;

    decompose(number, &int_part, &frac_part);

    printf("Integer part: %d\nFractional part: %f", int_part, frac_part);

    return EXIT_SUCCESS;

}

void decompose(double x, long *i, double *f) {
    *i = (long)x;
    *f = x - *i;
}