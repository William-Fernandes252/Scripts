/*Calculating the Fibonacci*/

#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n) {
    if(n == 1 || n == 0) {
        return n;
    }
    else if(n < 0) {
        if(n % 2 == 1) {
            return fibonacci((-n) - 1) + fibonacci((-n) - 2);
        }
        else if(n % 2 == 0) {
            return -(fibonacci((-n) - 1) + fibonacci((-n) - 2));
        }
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(void) {
    int f;
    printf("Enter a number: ");
    scanf("%d", &f);
    printf("The Fibonacci of %d is %d.", f, fibonacci(f));

    return EXIT_SUCCESS;
}
