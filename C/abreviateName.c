/* Return the given full name in a abreviated form */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char ** argv) {
    
    if(argc != 3) {
        fprintf(stderr, "Usage: program firstname lastname");
        return EXIT_FAILURE;
    }
    
    printf("%s, %c.", argv[2], toupper(argv[1][0]));
}