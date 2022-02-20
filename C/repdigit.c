/* Verifies if there are digits that appear more than once in a given number */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char ** argv) {
    
    bool digit_seen[10] = {false};
    int digit;
    long n;

    if(argc != 2) {
        fprintf(stderr, "Usage: program number");
        return EXIT_FAILURE;
    }

    n = atol(argv[1]);

    while(n > 0) {
        digit = n % 10;
        if(digit_seen[digit]) {
            break;
        digit_seen[digit] = true;
        n = n/10;
        }
    }

    if(n > 0) {
        puts("Repeated digit.");
    }
    else {
        puts("No repeated digit.");
    }

    return EXIT_SUCCESS;
}