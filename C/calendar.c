/* Prints a formatted calendar of a month with a given number of days, and starting in a given day of the week. */

#include<stdio.h>

int main(void)
{
    int days, week_day, i;

    printf("*** This program generates a one month calendar ***\n");

    printf("Enter the number of days of the month: ");
    scanf("%d", &days);
    printf("Enter the starting day of the month (1 = sun, 7 = sat): ");
    scanf("%d", &week_day);
    week_day -= 1;

    for(i = 0; i < week_day; i++){
        printf("   ");
    }
    for(i = 1; i <= days; i++){
        printf("%3d", i);
        week_day = (week_day + 1) % 7;
        if(week_day == 0){
            printf("\n");
        }
    }

    return 0;
}
