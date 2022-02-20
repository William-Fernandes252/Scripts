/* Shows the departure an arrival time of the closest flight of time entered */

#include <stdio.h>

int main(void)
{
    int hours, minutes, time;

    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%d:%d", &hours, &minutes);

    time = hours * 60 + minutes;

    if(time < 480){
        printf("Closest departure time  is 08:00 a.m, arriving at 10:16 a.m.\n");
    }
    else if(time < 583){
        printf("Closest departure time  is 09:43 a.m, arriving at 11:52 a.m.\n");
    }
    else if(time < 679){
        printf("Closest departure time  is 11:19 a.m, arriving at 01:31 p.m.\n");
    }
    else if(time < 767){
        printf("Closest departure time  is 12:47 a.m, arriving at 01:31 p.m.\n");
    }
    else if(time < 840){
        printf("Closest departure time  is 02:00 p.m, arriving at 04:08 p.m.\n");
    }
    else if(time < 945){
        printf("Closest departure time  is 03:45 p.m, arriving at 05:55 p.m.\n");
    }
    else if(time < 1140){
        printf("Closest departure time  is 07:00 p.m, arriving at 09:20 p.m.\n");
    }
    else if(time < 1305){
        printf("Closest departure time  is 09:45 p.m, arriving at 11:58 p.m.\n");
    }

    return 0;
}
