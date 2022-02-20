/* Shows the greatest number of a sequence of entries */

#include<stdio.h>
#define FINISH 0

int main(void)
{
    float n, max = 0;

    printf("This program shows what is the greatest number of you entries (finish by entering %d and enter one by one).\n", FINISH);

    for(;;){
        printf("Enter a number: ");
        if((scanf(" %f", &n) == 1) && (n > max)){
            max = n;
        }
        if(n <= 0.0f)
            break;
    }

    printf("\nThe largest number entered is: %f.\n\n", max);

    return 0;
}
