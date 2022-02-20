/* Prints a message in different languages depending on which macro is defined. */

#include <stdio.h>
#define FRENCH 1

int main(void) {

    #if defined(ENGLISH)
    printf("Insert Disk 1");
    #elif defined(FRENCH)
    printf("Inserez le Disque 1");
    #elif defined(SPANISH)
    printf("Inserte el Disco 1");
    #endif

    return 0;

}