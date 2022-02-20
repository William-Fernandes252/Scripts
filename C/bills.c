/*Shows how to pay a amount of dollars using the smallest number of  $20, $10, $5, and $1 bills*/

#include<stdio.h>

int main(void) {

    int dollar;

    printf("Enter a amount of dollars: ");
    scanf("%d", &dollar);

    printf("\n$20 dollar bills: %d\n", dollar / 20);
    printf("$10 dollar bills: %d\n", dollar % 20 / 10);
    printf("$5 dollar bills: %d\n", dollar % 10 / 5 );
    printf("$1 dollar bills: %d\n\n", dollar % 5 / 1);

    return 0;

}
