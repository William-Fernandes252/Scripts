/* Couns the amount of digits of a number. */

#include<stdio.h>

int main(void)
{
    int n, i = 0;

    printf("Enter a number: ");
    scanf(" %d", &n);

    do{
       n = n / 10; i++;
    }
    while(n != 0);

    printf("The number has %d digits.\n", i);

    return 0;
}
