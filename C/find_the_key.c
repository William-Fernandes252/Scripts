#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define SIZE 100
#define CHANCES 3

bool search(short *a, int n, short key);

int main (int argc, char **argv) {

    srand (time(NULL));

    if(argc != 4) {
        fprintf(stderr, "This program consists in a very simple game where you have to find the number between 0 and 100 choose by the computer. Enter ./find_the_key followed by %d numbers you think might be correct.", CHANCES);
        return EXIT_FAILURE;
    }

    short sequence[SIZE], *p;

    p = sequence;

    for(;p < sequence + SIZE;) {
        *p++ = rand() % 100;
    }

    unsigned short i = 1;
    while(i <= CHANCES) {
        if(search(sequence, SIZE, atoi(argv[i]))) {
            printf("You won! The number %d was a key :D", atoi(argv[i]));
            goto exit;
        }
    }

    printf("None of yours bets matches a key. You lose :(");

    exit:
        return EXIT_SUCCESS;
}

bool search(short *a, int n, short key) {

    short *p = a;
    for(; p < a + n; p++) {
        if(*p == key) return true;
    }

    return false;
}