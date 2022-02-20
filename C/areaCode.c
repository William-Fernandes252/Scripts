/* Prints the telephone area code of the major cities of Georgia */

#include <stdio.h>

int main(void)
{
    int area_code;

    printf("Enter the area code: ");
    scanf("%d", &area_code);

    switch(area_code)
    {
        case 229: printf("The city is Albany.\n"); break;
        case 404: printf("The city is Atlanta.\n"); break;
        case 470: printf("The city is Atlanta.\n"); break;
        case 478: printf("The city is Macon.\n"); break;
        case 678: printf("The city is Atlanta.\n"); break;
        case 706: printf("The city is Columbus.\n"); break;
        case 762: printf("The city is Columbs.\n"); break;
        case 770: printf("The city is Atlanta.\n"); break;
        case 912: printf("The city is Savannah.\n"); break;
        default: printf("Area code not reconized.\n"); break;
    }

    return 0;
}
