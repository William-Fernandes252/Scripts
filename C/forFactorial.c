/* Factorial of a given number */

#include <stdio.h>

void main() {
    int answer = 5;
    for(int i = 1; i < 5; i++) {
        answer = answer * (5-i);
    }
    printf("%d", answer);
}
