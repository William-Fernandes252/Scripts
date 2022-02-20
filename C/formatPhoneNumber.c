/* Formats and prints a entered phone number. */

#include<stdio.h>

int main(void)
{
    int pt_one, pt_two, pt_three;

    printf("Enter a phone number [(xxx) xxx-xxxx]: ");
    scanf("[(%d) %d-%d]", &pt_one, &pt_two, &pt_three);

    printf("You entered %d.%d.%d\n", pt_one, pt_two, pt_three);

    return 0;
}
