/* Looks for a especific temperature in a matrix of the measurements in a week */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define COLLUMNS 24
#define ROWS 7

bool search(const float a[], int n, float key);

int main(int argc, char** argv) {

    char usage[] = "usage: temperatures T where T is the wanted temperature in °F.";

    if(argc != 2) {
        fprintf(stderr, usage);
        exit(1);
    }

    float temperatures[ROWS][COLLUMNS], *p;

    float temperature = atof(argv[1]);

    for(p = &temperatures[0][0]; p < &temperatures[ROWS][COLLUMNS]; p++) {
        *p = 31.0f;
    }

    if(search(&temperatures[0][0], ROWS * COLLUMNS, temperature)) {
        printf("Temperature of %.1f degrees was found.", temperature);
        return EXIT_SUCCESS;
    }

    printf("Temperature of %.1f degrees was not found.", temperature);

    return EXIT_SUCCESS;
}

bool search(const float *a, int n, float key) {

    const float *q = a;
    for(; q < a + n; q++) {
        if(*q == key) return true;
    }

    return false;

}