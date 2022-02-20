#include <stdio.h>
#include <stdlib.h>
#define CUBE(x) ((x)*(x)*(x))

int main(int argc, char ** argv) {

    if(argc < 2) {
        fprintf(stderr, "Usage: ./cube x (real number)\nOutput: x^3");
        exit(1);
    }

    double x = atof(argv[1]);

    printf("%f^3 = %.1f\n", x, CUBE(x));

    return 0;

}