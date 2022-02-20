#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LENGTH 60

int read_line(char str[], unsigned short n) {

    int ch = 0, i = 0;
    
    while((ch = getchar()) == ' ')
        ;
    str[i++] = ch; /* Stores the first charater after the spaces. */
    while((ch = getchar()) != '\n') {
        if(i < n) str[i++] = ch;
    }

    str[i] = '\0';

    return i;

}

int read_word(char *str, int n) {

    int ch; 
    int i = 0;
    
    while((ch = getchar()) != '\n') {
        if((ch = getchar()) != ' ') continue;
        if(i < n) str[i++] = ch;
        if(isspace(ch)) break;
    }

    str[i] = '\n';
    str[i + 1] = '\0';

    return i;

}

int main(void) {

    char message[LENGTH];
    printf("Enter a message: ");
    read_line(message, LENGTH);
    printf("Your message is: %s\n", message);

}