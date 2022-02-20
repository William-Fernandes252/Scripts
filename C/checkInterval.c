/* Uses a parameterized macro to determine if the given x and y is between a given n-1. */

#include <stdio.h>
#include <stdlib.h>
#define CHECK(x, y, n) 0 <= (x) && (x) <= (n)-1 && 0 <= (y) && (y) <= (n)-1 ? 1 : 0

int main(int argc, char** argv) {

    if(argc < 3) {
        fprintf(stderr, "Usage ./checkInterval x y n.");
        return 1;
    }

    float x = atof(argv[1]);
    float y = atof(argv[2]);
    float n = atof(argv[3]);

    if(CHECK(x, y, n) == 1) {
        printf("%.1f and %.1f are between 0 and %.1f.\n", x, y, (n-1));
    }
    else {
        printf("%.1f and %.1f aren't between 0 and %.1f.\n", x, y, (n-1));
    }

    return 0;

}