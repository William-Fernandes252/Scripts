/* Return a array with a given number of elements of the fibonacci sequence */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE sizeof(fib_array)/sizeof(fib_array[0])

int main(int argc, char ** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: ./fibonacci_array n (nth element of the fibonacci sequence)");
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);

    long fib_array[n];
    fib_array[0] = 0;
    fib_array[1] = 1;
    fib_array[2] = 1;
    fib_array[3] = 2;

    int i = 4;
    for(; i != n; i++) {
        fib_array[i] = fib_array[i-1] + fib_array[i-2];
    }

    i = 0;
    for(; i != SIZE; i++) {
        printf("%d ", fib_array[i]);
    }

    return EXIT_SUCCESS;
}