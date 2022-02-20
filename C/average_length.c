/* Return the average word size of a given period */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char phrase;
    float letters = 0;
    float phrase_length = 1;

    printf("Enter a phrase: ");

    while((phrase = getchar()) != '\n') {
        if(phrase != ' ') {
            letters += 1;
        }
        else {
            phrase_length += 1;
        }
    }

    printf("Average word length: %.1f", letters/phrase_length);

    return EXIT_SUCCESS;
}