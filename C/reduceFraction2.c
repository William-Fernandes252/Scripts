/* Simplifies a given fraction */

#include <stdio.h>
#include <stdlib.h>

int compute_gcd (int a, int b) {

    int gcd = 1;

    for(int i = 0; i <= a && i <= b; i++) {
        if(a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    return gcd;
}

int main(void) {

    int num, denm;

    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &denm);

    int gcd = compute_gcd(num, denm);

    printf("Reduced form is: %d/%d", num/gcd, denm/gcd);

    return EXIT_SUCCESS;
}
