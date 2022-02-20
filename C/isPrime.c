/* Verifies if a number is prime */

#include <stdio.h>

int main(void) {
    int n, d;

    printf("Enter a number: ");
    scanf("%d", &n);

    for(d = 2; d < n; d++){
    if(n % d * d == 0)
    break;
    }
    if(d < n){
        printf("%d is divisible by %d\n", n, d);
    }
    else{
        printf("%d is prime\n", n);
    }

    return 0;
}
