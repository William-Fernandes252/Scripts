/* Shows all the even squares between 0 and a number */

#include<stdio.h>

int main(void)
{
    int n, i = 2;

    printf("Enter a  number: ");
    scanf(" %d", &n);

    do{
        if((i * i) % 2 == 0){
            printf("%d\n", i * i);
        }
        i++;
    }
    while(n >= i * i);

    return 0;
}
