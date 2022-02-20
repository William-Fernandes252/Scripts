/* Converts a 24-hour time to a 12-hour time */

#include<stdio.h>

int main(void)
{
    int hours, minutes;

    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%2d:%2d", &hours, &minutes);

    if(hours < 12){
    printf("Equivalent 12-hour time: %.2d:%.2d AM\n", hours, minutes);
    }
    else if(hours = 12){
    printf("Equivalent 12-hour time: 12:%.2d PM\n", minutes);
    }
    else if(hours > 12 && hours != 24){
    printf("Equivalent 12-hour time: %.2d:%.2d PM\n", hours - 12, minutes);
    }
    else if(hours = 24){
    printf("Equivalent 12-hour time: 00:%.2d AM\n", minutes);
    }

    return 0;
}
