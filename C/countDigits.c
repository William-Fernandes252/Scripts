/* Show how many digits has a given number. */

#include <stdio.h>

int main(void) {

    int number, aux, count = 1;

        printf("Enter a number: ");
        scanf("%d", &number);

        aux = number;

        while(aux > 0) {
            aux /= 10;
            count++;
        }

    printf("The number %d have %d digits.", number, count);

    return 0;

}
