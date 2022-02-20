/* Convert a message for a "internet format" */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MESSAGE_SIZE 100

int main() {

    char message[] = gets(message);

    printf("Enter a message: ");

    int i = 0;
    for(; i != MESSAGE_SIZE; i++) {
        switch(toupper(message[i])) {
            case 'A': printf("4"); break;
            case 'B': printf("8"); break;
            case 'E': printf("3"); break;
            case 'I': printf("L"); break;
            case 'O': printf("0"); break;
            case 'S': printf("5"); break;
            default : printf("%c", toupper(message[i])); break;
        }
    }
    printf("!!!!!!!!!!!!!");

    return EXIT_SUCCESS;
}