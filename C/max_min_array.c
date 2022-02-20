/* Finds and shows the biggest and smallest element of a given array of integers */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void find_elements (int a[], unsigned short N, int *max, int *min);

int main (int argc, char **argv) {

    char usage[] = "Usage: ./max_min_array followed by ten integers.";

    if(argc < (SIZE + 1)) {
        fprintf(stderr, "%s", usage);
        return EXIT_FAILURE;
    }

    int array[SIZE];

    for(int i = 0; i != SIZE; i++) {
        array[i] = atoi(argv[i+1]);
    }

    int max = array[0], min = array[0], N = SIZE;

    find_elements(array, N, &max, &min);

    printf("Biggest element: %d\nSmallest element: %d\n", max, min);

    return EXIT_SUCCESS;
}

void find_elements(int a[], unsigned short N, int *max, int *min) {
    
    for(int i = 0; i < N; i++) {
        
        if(a[i] >= *max) {
            *max = a[i];
        }

        if(a[i] <= *min) {
            *min = a[i];
        }

    }
}