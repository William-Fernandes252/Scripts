/* Displays the description of the speed of the wind according to the Beaufort Scale */

#include<stdio.h>

void main()
{
    int speed;

    printf("Enter the speed of the wind in knots: ");
    scanf("%d", &speed);

    if(speed < 1){
        printf("According to the Beaufort Scale: Calm.\n");
    }
    else if(speed <= 3){
        printf("According to the Beaufort Scale: Light air.\n");
    }
    else if(speed <= 27){
        printf("According to the Beaufort Scale: Breeze.\n");
    }
    else if(speed <= 47){
        printf("According to the Beaufort Scale: Gale.\n");
    }
    else if(speed <= 63){
        printf("According to the Beaufort Scale: Storm.\n");
    }
    else if(speed > 63){
        printf("According to the Beaufort Scale: Hurricane.\n");
    }

    system("pause");
}
