/* Shows the earlier date */

#include<stdio.h>

int main(void)
{
    int day1, month1, year1, day2, month2, year2;

    printf("Enter one date (dd/mm/yy): ");
    scanf("%d/%d/%d", &day1, &month1, &year1);
    printf("Enter one more date (dd/mm/yy): ");
    scanf("%d/%d/%d", &day2, &month2, &year2);

    if(year1 > year2){
        printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d.\n", day2, month2, year2, day1, month1, year1);
    }
    else if(month1 > month2){
        printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d.\n", day2, month2, year2, day1, month1, year1);
    }
    else if(day1 > day2){
        printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d.\n", day2, month2, year2, day1, month1, year1);
    }
    else{
        printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d.\n", day1, month1, year1, day2, month2, year2);
    }

    system("pause");

    return 0;
}
