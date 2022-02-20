/* Shows a float variable in different formats */

#include<stdio.h>

int main(void)
{
    float f;

    scanf("%f", &f);

    printf("\n|%-8.1e|\n", f);
    printf("|10.6e|\n", f);
    printf("|%-8.3f|\n", f);
    printf("|%6.0f|\n\n", f);


    return 0;
}
