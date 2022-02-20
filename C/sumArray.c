#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

double sum_array(double *a, unsigned int n);

int main (int argc, char **argv) {

    char usage[] = "Usage: ./sum_array followed by ten real numbers.";

    if(argc < (SIZE + 1)) {
        fprintf(stderr, "%s", usage);
        return EXIT_FAILURE;
    }

    double array[SIZE];

    double *p = array;

    short int i = 0;
    for(; p < array + SIZE; p++) {
        *p = atoi(argv[(i++)+1]);
    }

    double sum = sum_array(array, SIZE); 

    printf("Sum of the elements: %Lf\n", sum);
    return EXIT_SUCCESS;

}

double sum_array(double *a, unsigned int n) {

    double sum = 0.0;
    double *p = a;

    for(;p < a + n;) {
        sum += *p++;
    }

    return sum;
}