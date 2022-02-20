/* Uses a macro to evaluate the reminder of a given number when divided by DIV. */

#include <stdio.h>
#include <stdlib.h>
#define DIV 4
#define REMINDER(x) ((x)%DIV)

int main(int argc, char ** argv) {

    if(argc < 2) {
        fprintf(stderr, "Usage: %s int", argv[0]);
        exit(1);
    }

    int x = atoi(argv[1]);

    printf("%d %% %d = %d\n", x, DIV, REMINDER(x));

    return 0;

}