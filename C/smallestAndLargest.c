/* Finds the largest and smallest integer in a sequence of 4 integers.*/

#include<stdio.h>

int main(void)
{
    int a, b, c, d;

    puts("Enter four integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if(a > b && b > c && c > d){
        printf("Largest: %d\nSmallest: %d\n", a, d);
    }
    else if(b > a && a > c && c > d){
        printf("Largest: %d\nSmallest: %d\n", b, d);
    }
    else if(c > a && a > b && b > d){
        printf("Largest: %d\nSmallest: %d\n", c, d);
    }
    else if(d > c && c > b && b > a){
        printf("Largest: %d\nSmallest: %d\n", d, a);
    }
    else if(d > c && c > a && a > b){
        printf("Largest: %d\nSmallest: %d\n", d, b);
    }
    else if(d > b && b > a && a > c){
        printf("Largest: %d\nSmallest: %d\n", d, c);
    }

    return 0;
}
