/* Formats and prints a entered date. */

#include<stdio.h>

int main(void)
{
    int mm, dd, yyyy;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &mm, &dd, &yyyy);

    printf("\nYou entered the date: %d%d%d\n", mm, dd, yyyy);

    return 0;
}
