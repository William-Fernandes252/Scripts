/* Shows the earlier date */

#include<stdio.h>

int main(void)
{
    int day, month, year, earliest_day = 31, earliest_month = 12, earliest_year = 99 ;

    for(;;){
        printf("Enter a date (dd/mm/yy): ");
        scanf("%d/%d/%d", &day, &month, &year);

        if(year < earliest_year){
            earliest_year = year;
        }

        if(month < earliest_month){
            earliest_month = month;
        }

        if(month < earliest_month){
            earliest_day = day;
        }

        if(day == 0 && month == 0 && year == 0) break;
    }

    printf("The earliest date is %d/%d/%d", earliest_day, earliest_month, earliest_year);

    return 0;
}
