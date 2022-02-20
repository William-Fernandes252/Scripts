/* Calculates the closest flyght from a given hour of the day and provides the arrival time */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void closest_flyght(int dep_hour, int dep_min, char period) {

    int time;
    if(toupper(period) == 'A') {
        time = dep_hour * 60 + dep_min;
    }
    else {
        time = (dep_hour + 12) * 60 + dep_min;
    }

    if(time < 480) {
        printf("Closest departure time  is 08:00 a.m, arriving at 10:16 a.m.\n");
    }
    else if(time < 583) {
        printf("Closest departure time  is 09:43 a.m, arriving at 11:52 a.m.\n");
    }
    else if(time < 679) {
        printf("Closest departure time  is 11:19 a.m, arriving at 01:31 p.m.\n");
    }
    else if(time < 767) {
        printf("Closest departure time  is 12:47 a.m, arriving at 01:31 p.m.\n");
    }
    else if(time < 840) {
        printf("Closest departure time  is 02:00 p.m, arriving at 04:08 p.m.\n");
    }
    else if(time < 945) {
        printf("Closest departure time  is 03:45 p.m, arriving at 05:55 p.m.\n");
    }
    else if(time < 1140) {
        printf("Closest departure time  is 07:00 p.m, arriving at 09:20 p.m.\n");
    }
    else if(time < 1305) {
        printf("Closest departure time  is 09:45 p.m, arriving at 11:58 p.m.\n");
    }

}

int main(void) {

    int dep_hour, dep_min;
    char period;
    
    printf("Enter a 12-hour time (hh:mm A/P): ");

    do{
        scanf("%d:%d%c", &dep_hour, &dep_min, &period);
    }
    while(dep_hour >= 0 && dep_hour <= 12 && dep_min >= 0 && dep_min <= 59 && toupper(period) == 'A' || toupper(period) == 'P');
    
    closest_flyght(dep_hour, dep_min, period);

    return EXIT_SUCCESS;

}