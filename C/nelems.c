/* Uses a macro to determine the number of elements of any array. */

#include <stdio.h>
#include <stdlib.h>
#define SIZE(x) (sizeof(x)/sizeof(x[0]))

int main(void) {

    int array[10];

    printf("The size of the array is: %d", SIZE(array));

    return 0;

}