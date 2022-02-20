/* Uses a macro to display the image of the given parameters in a function. */

#include <stdio.h>
#include <stdlib.h>
#include <Math.h>
#define DISP(f, x, y) printf(#f"(%g, %g) = %g\n", (x), (y), f((x), (y)))

int main(void) {

    double x = 4, y = 2;

    DISP(pow, x, y);

    return 0;

}