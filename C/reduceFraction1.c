/* Reduces a fraction */

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

    int n, d, i, divisor;

    printf("Enter a fraction (n/d): ");
    scanf("%d/%d", &n, &d);
    divisor = gdc(n, d);

    printf("In lowest terms: %d/%d\n", n / divisor, d / divisor);

    return 0;
    
}
