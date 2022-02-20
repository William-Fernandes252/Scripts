/*Rises the value in 5%*/

#include<stdio.h>
#define RATE_OF_INCREASE 1.05f

int main(void)
{
    float value;

    printf("Enter a amount: ");
    scanf("%f", &value);

    printf("With tax added: U$%.2f\n", value * RATE_OF_INCREASE);

    return 0;
}
