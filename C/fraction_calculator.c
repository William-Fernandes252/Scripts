/* Operations with fractions */

#include <stdio.h>
#include <stdlib.h>

struct fraction_tag {
    int num;
    int denm;
}; 
typedef struct fraction_tag fraction_t;

int compute_gcd (int a, int b) {

    int gcd = 1;

    for(int i = 0; i <= a && i <= b; i++) {
        if(a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    return gcd;
}

void subtract_fraction(fraction_t operand1, fraction_t operand2) {
    int result_denm = operand1.denm * operand2.denm;
    int result_num = ((result_denm/operand1.denm) * operand1.num) - ((result_denm/operand2.denm) * operand2.num);
    int gcd = compute_gcd(result_num, result_denm);

    printf("The resultant fraction is: %d/%d", result_num/gcd, result_denm/gcd);
}

void sum_fraction(fraction_t operand1, fraction_t operand2) {
    int result_denm = operand1.denm * operand2.denm;
    int result_num = ((result_denm/operand1.denm) * operand1.num) + ((result_denm/operand2.denm) * operand2.num);
    int gcd = compute_gcd(result_num, result_denm);

    printf("The resultant fraction is: %d/%d", result_num/gcd, result_denm/gcd);
}

void divide_fraction(fraction_t operand1, fraction_t operand2) {
    printf("The resultant fraction is: %d/%d", operand1.num * operand2.denm, operand1.denm * operand2.num);
}

void multiply_fraction(fraction_t operand1, fraction_t operand2) {
    printf("The resultant fraction is: %d/%d", operand1.num * operand2.num, operand1.denm * operand2.denm);
}

int main(void) {
    
    fraction_t fraction1, fraction2;
    char operator;

    printf("Enter the first fraction: ");
    scanf("%d/%d", &fraction1.num, &fraction1.denm);

    printf("Enter the second fraction: ");
    scanf("%d/%d", &fraction2.num, &fraction2.denm);

    printf("Now enter the operation (sum(+), multiplication(*), subtraction(-), division(:)): ");

    operator = getchar();

    while(operator != '+' && operator != '-' && operator != '*' && operator != ':') {
        printf("Enter a valid operation: ");
        operator = getchar();
    }

    switch(operator) {
        case '+': sum_fraction(fraction1, fraction2); break;
        case '*': multiply_fraction(fraction1, fraction2); break;
        case '-': subtract_fraction(fraction1, fraction2); break;
        case ':': divide_fraction(fraction1, fraction2); break;
    }

    return EXIT_SUCCESS;
}