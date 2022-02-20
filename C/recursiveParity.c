/*Test if a number is odd (or even) with a mutual recursion algorithm*/

#include<stdio.h>
#include<stdlib.h>

isOdd(int x) {
    if(x == 0 || x == 1) {
        return x;
    }
    return isEven(x - 1);
}

isEven(int x) {
    if(x == 0) {
        return 1;
    }
    else if(x == 1) {
        return 0;
    }
    return isOdd(x - 1);
}

int main(void) {
    int test;

    printf("Enter a number: ");
    scanf("%d", &test);

    if(!isOdd(test)) {
        printf("%d is even.", test);
    }
    else {
        printf("%d is odd.", test);
    }

    return 0;
}
