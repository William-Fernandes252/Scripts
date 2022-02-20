/* Scrabble game */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {

    char input;
    short val = 0; 

    printf("Enter a word: ");
    while((input = getchar()) != '\n') {
        
        switch (toupper(input)) {
        case 'A': case 'E': case 'I': case 'L': case 'N': case 'O': case 'R': case 'S': case 'T': case 'U':
            val += 1;
            break;
        case 'D': case 'G':
            val += 2;
            break;
        case 'B': case 'C': case 'M': case 'P':
            val += 3;
            break;
        case 'F': case 'H': case 'V': case 'W': case 'Y':
            val += 4;
            break;
        case 'K':
            val += 5;
            break;
        case 'J': case 'X':
            val += 8;
            break;
        case 'Q': case 'Z':
            val += 10;
            break;
        default:
            break;
        }
    }

    printf("Scrabble value: %d", val);

    return EXIT_SUCCESS;
}