/* This program sort a array in crescent order */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void selection_sort(int n, int a[n]) {

    int temp = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] > temp) {
            temp = a[i];
        }
    }

    for(int i = 0; i < n; i++) {
        if(a[i] == temp) {
            temp = a[n-1];
            a[n-1] = a[i];
            a[i] = temp;
        }
    }

    if(n != 1) {
        selection_sort(n-1, a);
    }
}

int main(void) {
    
    int sequence[SIZE];
    
    printf("Enter a sequence of %d integers: ", SIZE);
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &sequence[i]);
    }

    selection_sort(SIZE, sequence);

    puts("Sequence sorted: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", sequence[i]);
    }

    return EXIT_SUCCESS;
}