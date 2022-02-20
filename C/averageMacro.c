/* Computes the average between the given values of x, y, and z using a parameterized macro. */

#include <stdio.h>
#include <stdlib.h>
#define AVERAGE(x, y, z) ((x)+(y)+(z))/3.0f

int main(int argc, char** argv) {

    if(argc < 3) {
        fprintf(stderr, "Usage ./averageMacro x y z.");
        return 1;
    }

    float x = atof(argv[1]);
    float y = atof(argv[2]);
    float z = atof(argv[3]);

    printf("The average of %.1f, %.1f and %.1f is %.1f", x, y, z, AVERAGE(x, y, z));

    return 0;

}