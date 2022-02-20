/* Test a macro to create a generic max function. */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long u_long;

#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
    return x > y ? x : y;       \
}

GENERIC_MAX(u_long)

int main(void) {

    u_long x = 9, y = 0;
    printf("%d\n", u_long_max(x, y));

    return 0;

}