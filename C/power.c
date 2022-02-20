/* Calculates recursively the power of a given number*/

#include <stdio.h>
#include <stdlib.h>

long long power(long x, unsigned short n) {
    if(n % 2 == 0) {
        if(n == 0) {
            return 1;
        }
        return x * power(x, n/2);
    }
    else {
        if(n == 0) {
            return 1;
        }
        return x * power(x, n-1);
    }
}

int main(void) {
    long x;
    unsigned short n;

    printf("This program calculates the power of a number.\nEnter a value followed by the desired power: ");
    scanf("%ld%hd", &x, &n);

    printf("%ld^%hd = %lld", x, n, power(x, n));
}