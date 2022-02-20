/* Prints the reversal of a given sentence. */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void reversal(char *sentence, short n);

int main(void) {
    
    char sentence[SIZE];
    
    printf("This program prints the reversal of a given sentence.\nWrite the sentence: ");

    reversal(sentence, SIZE);

    return EXIT_SUCCESS;

}

void reversal(char *sentence, short n) {

    char *p = sentence;

    for (; p < sentence + (SIZE); p++) {
        scanf("%c", p);
        if(*p == '\n') break;
    }

    for(p -= 1; p >= sentence; p--) {
        printf("%c", *p);
    }

}