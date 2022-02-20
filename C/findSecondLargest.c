/* Finds and shows the largest and the second largest element of a array of 10 elements. */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int *find_second_largest(int a[], unsigned short N, int *largest, int *second_largest);

int main (int argc, char **argv) {

    char usage[] = "Usage: ./find_second_largest followed by ten integers.";

    if(argc < (SIZE + 1)) {
        fprintf(stderr, "%s", usage);
        return EXIT_FAILURE;
    }

    int array[SIZE];

    for(int i = 0; i != SIZE; i++) {
        array[i] = atoi(argv[i+1]);
    }

    int largest = array[0], second_largest = array[0], N = SIZE, *s;

    s = find_second_largest(array, N, &largest, &second_largest);

    printf("Largest element: %d\nSecond largest element: %d\n", largest, *s);

    return EXIT_SUCCESS;
}

int *find_second_largest(int a[], unsigned short N, int *largest, int *second_largest) {
    
    unsigned int i = 0, largest_index, second_largest_index;

    for(; i < N; i++) {
        
        if(a[i] >= *largest) {
            *largest = a[i];
            largest_index = i;
        }

    }

    i = 0;

    for(; i < N; i++) {
        if(a[i] > *second_largest && i != largest_index) {
            *second_largest = a[i];
            second_largest_index = i;
        }
    }

    return &a[second_largest_index];
}