/* Swap the value of two variables. */

#include <stdio.h>
#include <stdlib.h>

void swap(double *a, double *b);

int main(int argc, char **argv) {

    char usage[] = "Usage: ./swap a b where a and b are real number for swap.";

    if(argc != 3) {
        fprintf(stderr, "%s", usage);
        return EXIT_FAILURE;
    }

    double a = atof(argv[1]), b = atof(argv[2]);

    swap(&a, &b);

    printf("a = %f\nb = %f\n", a, b);
}

void swap(double *a, double *b) {

    double helper = *a;
    *a = *b;
    *b = helper;

}