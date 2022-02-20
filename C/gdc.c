/* Calculates the Greatest Commom Divisor between two integers */

#include<stdio.h>

int gdc(int n, int m) {

    int gdc;
    for(int i = 1; i <= n && i <= m; i++){
        if(n % i == 0 && m % i == 0){
            gdc = i;
        }
    }

    return gdc;

}

int main(void)
{
    int n, m;

    printf("Enter two integers: ");
    scanf("%d %d", &n, &m);

    printf("Greatest Commom Divisor: %d\n", gdc(n, m));

    return 0;
}
