/* Uses a macro to print the name of file and the line. */

#include <stdio.h>
#include <stdlib.h>
#define STRINGIZE(x) #x
#define EXPAND(x) STRINGIZE(x)
#define LINE_FILE "Line "EXPAND(__LINE__)" of file "__FILE__"."

int main(void) {

    const char *str = LINE_FILE;
    printf("%s", str);

    return 0;

}