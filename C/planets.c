#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_PLANETS 9

int main(int argc, char **argv) {
    char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};

    short i, j;

    for(i = 0; i < argc; i++) {
        for(j = 0; j < NUM_OF_PLANETS; j++) {
            if(strcmp(argv[i], planets[j]) == 0) {
                printf("%s is the planet %d.\n", argv[i], j + 1);
                break;
            }
        }
        if(j == NUM_OF_PLANETS) {
            printf("%s is not the planet.\n", argv[i]);
        }
    }

    return EXIT_SUCCESS;
}