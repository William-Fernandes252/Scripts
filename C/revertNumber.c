/* Prints the reversal of a three digit number. */

#include<stdio.h>

int main(void)
{
    int n;

    printf("Enter a three digits number: ");
    scanf("%3d", &n);

    printf("The reversal is: %d\n", (n % 100) * 10 + (n / 100));

    return 0;
}
